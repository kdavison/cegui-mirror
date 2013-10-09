/***********************************************************************
    filename:   BitmapImage.cpp
    created:    Wed Feb 16 2011
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2011 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#include "CEGUI/BitmapImage.h"
#include "CEGUI/GeometryBuffer.h"
#include "CEGUI/Texture.h"
#include "CEGUI/Vertex.h"
#include "CEGUI/ColourRect.h"
#include "CEGUI/XMLAttributes.h"
#include "CEGUI/System.h" // this being here is a bit nasty IMO
#include "CEGUI/CoordConverter.h"

#include <glm/glm.hpp>

// Start of CEGUI namespace section
namespace CEGUI
{
const String ImageTypeAttribute( "type" );
const String ImageNameAttribute( "name" );
const String ImageTextureAttribute( "texture" );
const String ImageXPosAttribute( "xPos" );
const String ImageYPosAttribute( "yPos" );
const String ImageWidthAttribute( "width" );
const String ImageHeightAttribute( "height" );
const String ImageXOffsetAttribute( "xOffset" );
const String ImageYOffsetAttribute( "yOffset" );
const String ImageAutoScaledAttribute( "autoScaled" );
const String ImageNativeHorzResAttribute( "nativeHorzRes" );
const String ImageNativeVertResAttribute( "nativeVertRes" );

//----------------------------------------------------------------------------//
BitmapImage::BitmapImage(const String& name) :
    Image(name),
    d_texture(0)
{
}

//----------------------------------------------------------------------------//
BitmapImage::BitmapImage(const XMLAttributes& attributes) :
    Image(attributes.getValueAsString(ImageNameAttribute),
          Vector2f(static_cast<float>(attributes.getValueAsInteger(ImageXOffsetAttribute, 0)),
                   static_cast<float>(attributes.getValueAsInteger(ImageYOffsetAttribute, 0))),
          Rectf(Vector2f(static_cast<float>(attributes.getValueAsInteger(ImageXPosAttribute, 0)),
                         static_cast<float>(attributes.getValueAsInteger(ImageYPosAttribute, 0))),
                Sizef(static_cast<float>(attributes.getValueAsInteger(ImageWidthAttribute, 0)),
                      static_cast<float>(attributes.getValueAsInteger(ImageHeightAttribute, 0)))),
          PropertyHelper<AutoScaledMode>::fromString(attributes.getValueAsString(ImageAutoScaledAttribute)),
          Sizef(static_cast<float>(attributes.getValueAsInteger(ImageNativeHorzResAttribute, 640)),
                static_cast<float>(attributes.getValueAsInteger(ImageNativeVertResAttribute, 480)))),
    d_texture(&System::getSingleton().getRenderer()->getTexture(
              attributes.getValueAsString(ImageTextureAttribute)))
{
}

//----------------------------------------------------------------------------//
BitmapImage::BitmapImage(const String& name, Texture* texture,
                       const Rectf& pixel_area, const Vector2f& pixel_offset,
                       const AutoScaledMode autoscaled, const Sizef& native_res) :
    Image(name,
          pixel_offset,
          pixel_area,
          autoscaled,
          native_res),
    d_texture(texture)
{
}

//----------------------------------------------------------------------------//
void BitmapImage::setTexture(Texture* texture)
{
    d_texture = texture;
}

//----------------------------------------------------------------------------//
void BitmapImage::render(std::vector<GeometryBuffer*>& geometry_buffers,
                         const ImageRenderSettings& render_settings) const
{
    const QuadSplitMode quad_split_mode(TopLeftToBottomRight);

    Rectf dest(render_settings.d_destArea);
    // apply rendering offset to the destination Rect
    dest.offset(d_scaledOffset);

    const CEGUI::Rectf*const&  clip_area = render_settings.d_clipArea;
    // get the rect area that we will actually draw to (i.e. perform clipping)
    Rectf final_rect(clip_area ? dest.getIntersection(*clip_area) : dest );

    // check if rect was totally clipped
    if ((final_rect.getWidth() == 0) || (final_rect.getHeight() == 0))
        return;

    // Obtain correct scale values from the texture
    const Vector2f& texel_scale = d_texture->getTexelScaling();
    const Vector2f tex_per_pix(d_imageArea.getWidth() / dest.getWidth(), d_imageArea.getHeight() / dest.getHeight());

    // calculate final, clipped, texture co-ordinates
    const Rectf tex_rect((d_imageArea + ((final_rect - dest) * tex_per_pix)) * texel_scale);

    // URGENT FIXME: Shouldn't this be in the hands of the user?
    final_rect.d_min.d_x = CoordConverter::alignToPixels(final_rect.d_min.d_x);
    final_rect.d_min.d_y = CoordConverter::alignToPixels(final_rect.d_min.d_y);
    final_rect.d_max.d_x = CoordConverter::alignToPixels(final_rect.d_max.d_x);
    final_rect.d_max.d_y = CoordConverter::alignToPixels(final_rect.d_max.d_y);

    TexturedColouredVertex vbuffer[6];
    const CEGUI::ColourRect&  colours = render_settings.d_multiplyColours;

    // vertex 0
    vbuffer[0].d_position   = glm::vec3(final_rect.left(), final_rect.top(), 0.0f);
    vbuffer[0].d_colour = colours.d_top_left;
    vbuffer[0].d_texCoords = glm::vec2(tex_rect.left(), tex_rect.top());

    // vertex 1
    vbuffer[1].d_position   = glm::vec3(final_rect.left(), final_rect.bottom(), 0.0f);
    vbuffer[1].d_colour = colours.d_bottom_left;
    vbuffer[1].d_texCoords = glm::vec2(tex_rect.left(), tex_rect.bottom());

    // vertex 2
    vbuffer[2].d_position.x   = final_rect.right();
    vbuffer[2].d_position.z   = 0.0f;
    vbuffer[2].d_colour   = colours.d_bottom_right;
    vbuffer[2].d_texCoords.x = tex_rect.right();

    // top-left to bottom-right diagonal
    if (quad_split_mode == TopLeftToBottomRight)
    {
        vbuffer[2].d_position.y   = final_rect.bottom();
        vbuffer[2].d_texCoords.y = tex_rect.bottom();
    }
    // bottom-left to top-right diagonal
    else
    {
        vbuffer[2].d_position.y   = final_rect.top();
        vbuffer[2].d_texCoords.y = tex_rect.top();
    }

    // vertex 3
    vbuffer[3].d_position   = glm::vec3(final_rect.right(), final_rect.top(), 0.0f);
    vbuffer[3].d_colour = colours.d_top_right;
    vbuffer[3].d_texCoords = glm::vec2(tex_rect.right(), tex_rect.top());

    // vertex 4
    vbuffer[4].d_position.x   = final_rect.left();
    vbuffer[4].d_position.z   = 0.0f;
    vbuffer[4].d_colour   = colours.d_top_left;
    vbuffer[4].d_texCoords.x = tex_rect.left();

    // top-left to bottom-right diagonal
    if (quad_split_mode == TopLeftToBottomRight)
    {
        vbuffer[4].d_position.y   = final_rect.top();
        vbuffer[4].d_texCoords.y = tex_rect.top();
    }
    // bottom-left to top-right diagonal
    else
    {
        vbuffer[4].d_position.y   = final_rect.bottom();
        vbuffer[4].d_texCoords.y = tex_rect.bottom();
    }

    // vertex 5
    vbuffer[5].d_position     = glm::vec3(final_rect.right(), final_rect.bottom(), 0.0f);
    vbuffer[5].d_colour   = colours.d_bottom_right;
    vbuffer[5].d_texCoords   = glm::vec2(tex_rect.right(), tex_rect.bottom());

    CEGUI::GeometryBuffer& buffer = System::getSingleton().getRenderer()->createGeometryBufferTextured();
    geometry_buffers.push_back(&buffer);

    buffer.setClippingActive(render_settings.d_clippingEnabled);
    if(render_settings.d_clippingEnabled)
        buffer.setClippingRegion(*render_settings.d_clipArea);
    buffer.setTexture(d_texture);
    buffer.appendGeometry(vbuffer, 6);
}




//----------------------------------------------------------------------------//
const Texture* BitmapImage::getTexture() const
{
    return d_texture;
}

} // End of  CEGUI namespace section
