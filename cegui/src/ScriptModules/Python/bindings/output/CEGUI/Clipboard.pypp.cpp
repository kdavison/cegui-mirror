// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "Clipboard.pypp.hpp"

namespace bp = boost::python;

void register_Clipboard_class(){

    { //::CEGUI::Clipboard
        typedef bp::class_< CEGUI::Clipboard > Clipboard_exposer_t;
        Clipboard_exposer_t Clipboard_exposer = Clipboard_exposer_t( "Clipboard", "*!\n\
        \n\
            Defines a clipboard handling class\n\
        \n\
        \n\
            Usually, there is just one instance of this class, owned by CEGUI.System,\n\
            it contains internal CEGUI clipboard that may be (optionally) synchronised\n\
            with native clipboard if user sets NativeClipboardProvider with:\n\
            .\n\
            CEGUI.System.getSingleton().getClipboard().setNativeProvider(customProvider)\n\
            \n\n\
            Where customProvider is of course user implemented clipboard provider.\n\
            \n\
         internal\n\
            We may provide native clipboard providers automatically for some platforms\n\
            in the future, however for X11 this is really hard and would introduce\n\
            dependency -lX11 to CEGUIBase which is something we would really hate.\n\
        *\n", bp::init< >("*!\n\
         constructor\n\
        *\n") );
        bp::scope Clipboard_scope( Clipboard_exposer );
        { //::CEGUI::Clipboard::getText
        
            typedef ::CEGUI::String ( ::CEGUI::Clipboard::*getText_function_type )(  ) ;
            
            Clipboard_exposer.def( 
                "getText"
                , getText_function_type( &::CEGUI::Clipboard::getText )
                , "*!\n\
             convenience method that retrieves contents as a string\n\
            *\n" );
        
        }
        { //::CEGUI::Clipboard::setText
        
            typedef void ( ::CEGUI::Clipboard::*setText_function_type )( ::CEGUI::String const & ) ;
            
            Clipboard_exposer.def( 
                "setText"
                , setText_function_type( &::CEGUI::Clipboard::setText )
                , ( bp::arg("text") )
                , "*!\n\
             convenience method that sets contents to given string\n\
            *\n" );
        
        }
    }

}
