// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "StateImagery.pypp.hpp"

namespace bp = boost::python;

void register_StateImagery_class(){

    { //::CEGUI::StateImagery
        typedef bp::class_< CEGUI::StateImagery > StateImagery_exposer_t;
        StateImagery_exposer_t StateImagery_exposer = StateImagery_exposer_t( "StateImagery", bp::init< >("*!\n\
        \n\
            Constructor\n\
        *\n") );
        bp::scope StateImagery_scope( StateImagery_exposer );
        StateImagery_exposer.def( bp::init< CEGUI::String const & >(( bp::arg("name") ), "*!\n\
                \n\
                    Constructor\n\
        \n\
                @param name\n\
                    Name of the state\n\
                *\n") );
        bp::implicitly_convertible< CEGUI::String const &, CEGUI::StateImagery >();
        { //::CEGUI::StateImagery::addLayer
        
            typedef void ( ::CEGUI::StateImagery::*addLayer_function_type )( ::CEGUI::LayerSpecification const & ) ;
            
            StateImagery_exposer.def( 
                "addLayer"
                , addLayer_function_type( &::CEGUI::StateImagery::addLayer )
                , ( bp::arg("layer") )
                , "*!\n\
                    \n\
                        Add an imagery LayerSpecification to this state.\n\
            \n\
                    @param layer\n\
                        LayerSpecification to be added to this state (will be copied)\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::clearLayers
        
            typedef void ( ::CEGUI::StateImagery::*clearLayers_function_type )(  ) ;
            
            StateImagery_exposer.def( 
                "clearLayers"
                , clearLayers_function_type( &::CEGUI::StateImagery::clearLayers )
                , "*!\n\
                    \n\
                        Removed all LayerSpecifications from this state.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::getName
        
            typedef ::CEGUI::String const & ( ::CEGUI::StateImagery::*getName_function_type )(  ) const;
            
            StateImagery_exposer.def( 
                "getName"
                , getName_function_type( &::CEGUI::StateImagery::getName )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
                    \n\
                        Return the name of this state.\n\
            \n\
                    @return\n\
                        String object holding the name of the StateImagery object.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::isClippedToDisplay
        
            typedef bool ( ::CEGUI::StateImagery::*isClippedToDisplay_function_type )(  ) const;
            
            StateImagery_exposer.def( 
                "isClippedToDisplay"
                , isClippedToDisplay_function_type( &::CEGUI::StateImagery::isClippedToDisplay )
                , "*!\n\
                    \n\
                        Return whether this state imagery should be clipped to the display rather than the\
                        target window.\n\
            \n\
                        Clipping to the display effectively implies that the imagery should be rendered\
                        unclipped.\n\
            \n\
                    return\n\
                        - true if the imagery will be clipped to the display area.\n\
                        - false if the imagery will be clipped to the target window area.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::render
        
            typedef void ( ::CEGUI::StateImagery::*render_function_type )( ::CEGUI::Window &,::CEGUI::ColourRect const *,::CEGUI::Rectf const * ) const;
            
            StateImagery_exposer.def( 
                "render"
                , render_function_type( &::CEGUI::StateImagery::render )
                , ( bp::arg("srcWindow"), bp::arg("modcols")=bp::object(), bp::arg("clipper")=bp::object() )
                , "*!\n\
                    \n\
                        Render imagery for this state.\n\
            \n\
                    @param srcWindow\n\
                        Window to use when convering BaseDim values to pixels.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::render
        
            typedef void ( ::CEGUI::StateImagery::*render_function_type )( ::CEGUI::Window &,::CEGUI::Rectf const &,::CEGUI::ColourRect const *,::CEGUI::Rectf const * ) const;
            
            StateImagery_exposer.def( 
                "render"
                , render_function_type( &::CEGUI::StateImagery::render )
                , ( bp::arg("srcWindow"), bp::arg("baseRect"), bp::arg("modcols")=bp::object(), bp::arg("clipper")=bp::object() )
                , "*!\n\
                    \n\
                        Render imagery for this state.\n\
            \n\
                    @param srcWindow\n\
                        Window to use when convering BaseDim values to pixels.\n\
            \n\
                    @param baseRect\n\
                        Rect to use when convering BaseDim values to pixels.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::setClippedToDisplay
        
            typedef void ( ::CEGUI::StateImagery::*setClippedToDisplay_function_type )( bool ) ;
            
            StateImagery_exposer.def( 
                "setClippedToDisplay"
                , setClippedToDisplay_function_type( &::CEGUI::StateImagery::setClippedToDisplay )
                , ( bp::arg("setting") )
                , "*!\n\
                    \n\
                        Set whether this state imagery should be clipped to the display rather than the target\
                        window.\n\
            \n\
                        Clipping to the display effectively implies that the imagery should be rendered\
                        unclipped.\n\
            \n\
                    @param setting\n\
                        - true if the imagery should be clipped to the display area.\n\
                        - false if the imagery should be clipped to the target window area.\n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
        { //::CEGUI::StateImagery::writeXMLToStream
        
            typedef void ( ::CEGUI::StateImagery::*writeXMLToStream_function_type )( ::CEGUI::XMLSerializer & ) const;
            
            StateImagery_exposer.def( 
                "writeXMLToStream"
                , writeXMLToStream_function_type( &::CEGUI::StateImagery::writeXMLToStream )
                , ( bp::arg("xml_stream") )
                , "*!\n\
                    \n\
                        Writes an xml representation of this StateImagery to  out_stream.\n\
            \n\
                    @param xml_stream\n\
                        Stream where xml data should be output.\n\
            \n\
            \n\
                    @return\n\
                        Nothing.\n\
                    *\n" );
        
        }
    }

}
