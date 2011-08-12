// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b.pypp.hpp"

namespace bp = boost::python;

struct ConstBaseIterator_less__std_scope_vector_less__CEGUI_scope_Window_ptr___greater__comma__CEGUI_scope_Window_ptr___greater__wrapper : CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >, bp::wrapper< CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > > {

    ConstBaseIterator_less__std_scope_vector_less__CEGUI_scope_Window_ptr___greater__comma__CEGUI_scope_Window_ptr___greater__wrapper( )
    : CEGUI::ConstBaseIterator<std::vector<CEGUI::Window*, std::allocator<CEGUI::Window*> >, CEGUI::Window*>( )
      , bp::wrapper< CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > >(){
        // null constructor
    
    }

    virtual ::CEGUI::Window * getCurrentValue(  ) const {
        bp::override func_getCurrentValue = this->get_override( "getCurrentValue" );
        return func_getCurrentValue(  );
    }

};

void register_ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_class(){

    { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >
        typedef bp::class_< ConstBaseIterator_less__std_scope_vector_less__CEGUI_scope_Window_ptr___greater__comma__CEGUI_scope_Window_ptr___greater__wrapper, boost::noncopyable > ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer_t;
        ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer_t ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer = ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer_t( "ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b", bp::no_init );
        bp::scope ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_scope( ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer );
        ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( bp::init< >("*************************************************************************\n\
           No default construction available\n\
        *************************************************************************\n") );
        { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::getCurrentValue
        
            typedef CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > exported_class_t;
            typedef ::CEGUI::Window * ( exported_class_t::*getCurrentValue_function_type )(  ) const;
            
            ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( 
                "getCurrentValue"
                , bp::pure_virtual( getCurrentValue_function_type(&::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::getCurrentValue) )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "*!\n\
            \n\
               Return the value for the item at the current iterator position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::isAtEnd
        
            typedef CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > exported_class_t;
            typedef bool ( exported_class_t::*isAtEnd_function_type )(  ) const;
            
            ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( 
                "isAtEnd"
                , isAtEnd_function_type( &::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::isAtEnd )
                , "*!\n\
            \n\
               Return whether the current iterator position is at the end of the iterators range.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::isAtStart
        
            typedef CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > exported_class_t;
            typedef bool ( exported_class_t::*isAtStart_function_type )(  ) const;
            
            ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( 
                "isAtStart"
                , isAtStart_function_type( &::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::isAtStart )
                , "*!\n\
            \n\
               Return whether the current iterator position is at the start of the iterators range.\n\
            *\n" );
        
        }
        ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( bp::self != bp::self );
        { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::operator=
        
            typedef CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > exported_class_t;
            typedef ::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > & ( exported_class_t::*assign_function_type )( ::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > const & ) ;
            
            ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >()
                , "*!\n\
            \n\
               ConstBaseIterator assignment operator\n\
            *\n" );
        
        }
        ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( bp::self == bp::self );
        { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::toEnd
        
            typedef CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > exported_class_t;
            typedef void ( exported_class_t::*toEnd_function_type )(  ) ;
            
            ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( 
                "toEnd"
                , toEnd_function_type( &::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::toEnd )
                , "*!\n\
            \n\
               Set the iterator current position to the end position.\n\
            *\n" );
        
        }
        { //::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::toStart
        
            typedef CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* > exported_class_t;
            typedef void ( exported_class_t::*toStart_function_type )(  ) ;
            
            ConstBaseIterator_9dce73c5f5e3a55d1a66a6e740fbf48b_exposer.def( 
                "toStart"
                , toStart_function_type( &::CEGUI::ConstBaseIterator< std::vector< CEGUI::Window* >, CEGUI::Window* >::toStart )
                , "*!\n\
            \n\
               Set the iterator current position to the start position.\n\
            *\n" );
        
        }
    }

}
