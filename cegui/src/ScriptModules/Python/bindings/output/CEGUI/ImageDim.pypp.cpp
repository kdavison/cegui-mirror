// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "ImageDim.pypp.hpp"

namespace bp = boost::python;

struct ImageDim_wrapper : CEGUI::ImageDim, bp::wrapper< CEGUI::ImageDim > {

    ImageDim_wrapper(CEGUI::ImageDim const & arg )
    : CEGUI::ImageDim( arg )
      , bp::wrapper< CEGUI::ImageDim >(){
        // copy constructor
        
    }

    ImageDim_wrapper( )
    : CEGUI::ImageDim( )
      , bp::wrapper< CEGUI::ImageDim >(){
        // null constructor
    
    }

    ImageDim_wrapper(::CEGUI::String const & image_name, ::CEGUI::DimensionType dim )
    : CEGUI::ImageDim( boost::ref(image_name), dim )
      , bp::wrapper< CEGUI::ImageDim >(){
        // constructor
    
    }

    virtual ::CEGUI::BaseDim * clone_impl(  ) const {
        if( bp::override func_clone_impl = this->get_override( "clone_impl" ) )
            return func_clone_impl(  );
        else{
            return this->CEGUI::ImageDim::clone_impl(  );
        }
    }
    
    virtual ::CEGUI::BaseDim * default_clone_impl(  ) const {
        return CEGUI::ImageDim::clone_impl( );
    }

    virtual ::CEGUI::Image const * getSourceImage( ::CEGUI::Window const & wnd ) const {
        if( bp::override func_getSourceImage = this->get_override( "getSourceImage" ) )
            return func_getSourceImage( boost::ref(wnd) );
        else{
            return this->CEGUI::ImageDim::getSourceImage( boost::ref(wnd) );
        }
    }
    
    virtual ::CEGUI::Image const * default_getSourceImage( ::CEGUI::Window const & wnd ) const {
        return CEGUI::ImageDim::getSourceImage( boost::ref(wnd) );
    }

    virtual void writeXMLElementAttributes_impl( ::CEGUI::XMLSerializer & xml_stream ) const {
        if( bp::override func_writeXMLElementAttributes_impl = this->get_override( "writeXMLElementAttributes_impl" ) )
            func_writeXMLElementAttributes_impl( boost::ref(xml_stream) );
        else{
            this->CEGUI::ImageDim::writeXMLElementAttributes_impl( boost::ref(xml_stream) );
        }
    }
    
    virtual void default_writeXMLElementAttributes_impl( ::CEGUI::XMLSerializer & xml_stream ) const {
        CEGUI::ImageDim::writeXMLElementAttributes_impl( boost::ref(xml_stream) );
    }

    virtual void writeXMLElementName_impl( ::CEGUI::XMLSerializer & xml_stream ) const {
        if( bp::override func_writeXMLElementName_impl = this->get_override( "writeXMLElementName_impl" ) )
            func_writeXMLElementName_impl( boost::ref(xml_stream) );
        else{
            this->CEGUI::ImageDim::writeXMLElementName_impl( boost::ref(xml_stream) );
        }
    }
    
    virtual void default_writeXMLElementName_impl( ::CEGUI::XMLSerializer & xml_stream ) const {
        CEGUI::ImageDim::writeXMLElementName_impl( boost::ref(xml_stream) );
    }

    virtual bool handleFontRenderSizeChange( ::CEGUI::Window & window, ::CEGUI::Font const * font ) const  {
        if( bp::override func_handleFontRenderSizeChange = this->get_override( "handleFontRenderSizeChange" ) )
            return func_handleFontRenderSizeChange( boost::ref(window), boost::python::ptr(font) );
        else{
            return this->CEGUI::BaseDim::handleFontRenderSizeChange( boost::ref(window), boost::python::ptr(font) );
        }
    }
    
    bool default_handleFontRenderSizeChange( ::CEGUI::Window & window, ::CEGUI::Font const * font ) const  {
        return CEGUI::BaseDim::handleFontRenderSizeChange( boost::ref(window), boost::python::ptr(font) );
    }

};

void register_ImageDim_class(){

    { //::CEGUI::ImageDim
        typedef bp::class_< ImageDim_wrapper > ImageDim_exposer_t;
        ImageDim_exposer_t ImageDim_exposer = ImageDim_exposer_t( "ImageDim", "! ImageDimBase subclass that accesses an image by its name.\n", bp::init< >() );
        bp::scope ImageDim_scope( ImageDim_exposer );
        ImageDim_exposer.def( bp::init< CEGUI::String const &, CEGUI::DimensionType >(( bp::arg("image_name"), bp::arg("dim") ), "*!\n\
                \n\
                    Constructor.\n\
        \n\
                @param image_name\n\
                    String holding the name of the image to be accessed by the ImageDim\n\
        \n\
                @param dim\n\
                    DimensionType value indicating which dimension of an Image that\n\
                    this ImageDim is to represent.\n\
                *\n") );
        { //::CEGUI::ImageDim::clone_impl
        
            typedef ::CEGUI::BaseDim * ( ImageDim_wrapper::*clone_impl_function_type )(  ) const;
            
            ImageDim_exposer.def( 
                "clone_impl"
                , clone_impl_function_type( &ImageDim_wrapper::default_clone_impl )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::CEGUI::ImageDim::getSourceImage
        
            typedef ::CEGUI::String const & ( ::CEGUI::ImageDim::*getSourceImage_function_type )(  ) const;
            
            ImageDim_exposer.def( 
                "getSourceImage"
                , getSourceImage_function_type( &::CEGUI::ImageDim::getSourceImage )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "! return the name of the image accessed by this ImageDim.\n" );
        
        }
        { //::CEGUI::ImageDim::getSourceImage
        
            typedef ::CEGUI::Image const * ( ImageDim_wrapper::*getSourceImage_function_type )( ::CEGUI::Window const & ) const;
            
            ImageDim_exposer.def( 
                "getSourceImage"
                , getSourceImage_function_type( &ImageDim_wrapper::default_getSourceImage )
                , ( bp::arg("wnd") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Implementation of the base class interface\n" );
        
        }
        { //::CEGUI::ImageDim::setSourceImage
        
            typedef void ( ::CEGUI::ImageDim::*setSourceImage_function_type )( ::CEGUI::String const & ) ;
            
            ImageDim_exposer.def( 
                "setSourceImage"
                , setSourceImage_function_type( &::CEGUI::ImageDim::setSourceImage )
                , ( bp::arg("image_name") )
                , "! return the name of the image accessed by this ImageDim.\n\
            ! set the name of the image accessed by this ImageDim.\n" );
        
        }
        { //::CEGUI::ImageDim::writeXMLElementAttributes_impl
        
            typedef void ( ImageDim_wrapper::*writeXMLElementAttributes_impl_function_type )( ::CEGUI::XMLSerializer & ) const;
            
            ImageDim_exposer.def( 
                "writeXMLElementAttributes_impl"
                , writeXMLElementAttributes_impl_function_type( &ImageDim_wrapper::default_writeXMLElementAttributes_impl )
                , ( bp::arg("xml_stream") ) );
        
        }
        { //::CEGUI::ImageDim::writeXMLElementName_impl
        
            typedef void ( ImageDim_wrapper::*writeXMLElementName_impl_function_type )( ::CEGUI::XMLSerializer & ) const;
            
            ImageDim_exposer.def( 
                "writeXMLElementName_impl"
                , writeXMLElementName_impl_function_type( &ImageDim_wrapper::default_writeXMLElementName_impl )
                , ( bp::arg("xml_stream") )
                , "Implementation of the base class interface\n" );
        
        }
        { //::CEGUI::BaseDim::handleFontRenderSizeChange
        
            typedef bool ( ::CEGUI::BaseDim::*handleFontRenderSizeChange_function_type )( ::CEGUI::Window &,::CEGUI::Font const * ) const;
            typedef bool ( ImageDim_wrapper::*default_handleFontRenderSizeChange_function_type )( ::CEGUI::Window &,::CEGUI::Font const * ) const;
            
            ImageDim_exposer.def( 
                "handleFontRenderSizeChange"
                , handleFontRenderSizeChange_function_type(&::CEGUI::BaseDim::handleFontRenderSizeChange)
                , default_handleFontRenderSizeChange_function_type(&ImageDim_wrapper::default_handleFontRenderSizeChange)
                , ( bp::arg("window"), bp::arg("font") ) );
        
        }
    }

}
