#ifndef STREAMS_BOOST_SERIALIZATION_STATE_SAVER_HPP
#define STREAMS_BOOST_SERIALIZATION_STATE_SAVER_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// state_saver.hpp:

// (C) Copyright 2003-4 Pavel Vozenilek and Robert Ramey - http://www.rrsd.com.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/serialization for updates, documentation, and revision history.

// Inspired by Daryle Walker's iostate_saver concept.  This saves the original
// value of a variable when a state_saver is constructed and restores
// upon destruction.  Useful for being sure that state is restored to
// variables upon exit from scope.


#include <streams_boost/config.hpp>
#ifndef STREAMS_BOOST_NO_EXCEPTIONS
    #include <exception>
#endif

#include <streams_boost/call_traits.hpp>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/type_traits/has_nothrow_copy.hpp>
#include <streams_boost/detail/no_exceptions_support.hpp>

#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>

namespace streams_boost {
namespace serialization {

template<class T>
// T requirements:
//  - POD or object semantic (cannot be reference, function, ...)
//  - copy constructor
//  - operator = (no-throw one preferred)
class state_saver : private streams_boost::noncopyable
{
private:
    const T previous_value;
    T & previous_ref;

    struct restore {
        static void invoke(T & previous_ref, const T & previous_value){
            previous_ref = previous_value; // won't throw
        }
    };

    struct restore_with_exception {
        static void invoke(T & previous_ref, const T & previous_value){
            STREAMS_BOOST_TRY{
                previous_ref = previous_value;
            } 
            STREAMS_BOOST_CATCH(::std::exception &) { 
                // we must ignore it - we are in destructor
            }
            STREAMS_BOOST_CATCH_END
        }
    };

public:
    state_saver(
        T & object
    ) : 
        previous_value(object),
        previous_ref(object) 
    {}
    
    ~state_saver() {
        #ifndef STREAMS_BOOST_NO_EXCEPTIONS
            typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
                has_nothrow_copy<T>,
                mpl::identity<restore>,
                mpl::identity<restore_with_exception>
            >::type typex;
            typex::invoke(previous_ref, previous_value);
        #else
            previous_ref = previous_value;
        #endif
    }

}; // state_saver<>

} // serialization
} // streams_boost

#endif //STREAMS_BOOST_SERIALIZATION_STATE_SAVER_HPP