// Boost.Assign library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/assign/
//  
 

#ifndef STREAMS_BOOST_ASSIGN_ASSIGNMENT_EXCEPTION_HPP
#define STREAMS_BOOST_ASSIGN_ASSIGNMENT_EXCEPTION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <exception>

namespace streams_boost
{    
    namespace assign
    {
        class assignment_exception : public std::exception
        {
        public:
            assignment_exception( const char* _what ) 
            : what_( _what )
            { }
        
            virtual const char* what() const throw()
            {
                return what_;
            }
        
        private:
                const char* what_;
        };
    }
}

#endif
