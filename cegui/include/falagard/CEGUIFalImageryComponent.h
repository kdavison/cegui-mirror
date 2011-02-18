/***********************************************************************
    filename:   CEGUIFalImageryComponent.h
    created:    Mon Jun 13 2005
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
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
#ifndef _CEGUIFalImageryComponent_h_
#define _CEGUIFalImageryComponent_h_

#include "CEGUIFalComponentBase.h"
#include "../CEGUIXMLSerializer.h"

// Start of CEGUI namespace section
namespace CEGUI
{
    /*!
    \brief
        Class that encapsulates information for a single image component.
    */
    class CEGUIEXPORT ImageryComponent : public FalagardComponentBase
    {
    public:
        /*!
        \brief
            Constructor
        */
        ImageryComponent();

        /*!
        \brief
            Return the Image object that will be drawn by this ImageryComponent.

        \return
            Image object.
        */
        const Image* getImage() const;

        /*!
        \brief
            Set the Image that will be drawn by this ImageryComponent.

        \param
            Pointer to the Image object to be drawn by this ImageryComponent.

        \return
            Nothing.
        */
        void setImage(const Image* image);

        /*!
        \brief
            Set the Image that will be drawn by this ImageryComponent.

        \param name
            String holding the name of the Image to be rendered.

        \return
            Nothing.
        */
        void setImage(const String& name);

        /*!
        \brief
            Return the current vertical formatting setting for this ImageryComponent.

        \return
            One of the VerticalFormatting enumerated values.
        */
        VerticalFormatting getVerticalFormatting() const;

        /*!
        \brief
            Set the vertical formatting setting for this ImageryComponent.

        \param fmt
            One of the VerticalFormatting enumerated values.

        \return
            Nothing.
        */
        void setVerticalFormatting(VerticalFormatting fmt);

        /*!
        \brief
            Return the current horizontal formatting setting for this ImageryComponent.

        \return
            One of the HorizontalFormatting enumerated values.
        */
        HorizontalFormatting getHorizontalFormatting() const;

        /*!
        \brief
            Set the horizontal formatting setting for this ImageryComponent.

        \param fmt
            One of the HorizontalFormatting enumerated values.

        \return
            Nothing.
        */
        void setHorizontalFormatting(HorizontalFormatting fmt);

        /*!
        \brief
            Writes an xml representation of this ImageryComponent to \a out_stream.

        \param xml_stream
            Stream where xml data should be output.


        \return
            Nothing.
        */
        void writeXMLToStream(XMLSerializer& xml_stream) const;

        /*!
        \brief
            Return whether this ImageryComponent fetches it's image via a property on the target window.

        \return
            - true if the image comes via a Propery.
            - false if the image is defined explicitly.
        */
        bool isImageFetchedFromProperty() const;

        /*!
        \brief
            Return the name of the property that will be used to determine the image for this ImageryComponent.

        \return
            String object holding the name of a Propery.
        */
        const String& getImagePropertySource() const;

        /*!
        \brief
            Set the name of the property that will be used to determine the image for this ImageryComponent.

        \param property
            String object holding the name of a Propery.  The property should access a imageset & image specification.

        \return
            Nothing.
        */
        void setImagePropertySource(const String& property);

    protected:
        // implemets abstract from base
        void render_impl(Window& srcWindow, Rect& destRect, const CEGUI::ColourRect* modColours, const Rect* clipper, bool clipToDisplay) const;

        const Image*         d_image;           //!< CEGUI::Image to be drawn by this image component.
        VerticalFormatting   d_vertFormatting;  //!< Vertical formatting to be applied when rendering the image component.
        HorizontalFormatting d_horzFormatting;  //!< Horizontal formatting to be applied when rendering the image component.
        String  d_imagePropertyName;            //!< Name of the property to access to obtain the image to be used.
    };

} // End of  CEGUI namespace section


#endif  // end of guard _CEGUIFalImageryComponent_h_
