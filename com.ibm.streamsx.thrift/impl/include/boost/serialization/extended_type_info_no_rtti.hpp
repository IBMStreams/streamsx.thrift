#ifndef STREAMS_BOOST_EXTENDED_TYPE_INFO_NO_RTTI_HPP
#define STREAMS_BOOST_EXTENDED_TYPE_INFO_NO_RTTI_HPP

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

// extended_type_info_no_rtti.hpp: implementation for version that depends
// on runtime typing (rtti - typeid) but uses a user specified string
// as the portable class identifier.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.
#include <cassert>

#include <streams_boost/config.hpp>
#include <streams_boost/static_assert.hpp>

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/type_traits/is_polymorphic.hpp>

#include <streams_boost/serialization/static_warning.hpp>
#include <streams_boost/serialization/singleton.hpp>
#include <streams_boost/serialization/extended_type_info.hpp>
#include <streams_boost/serialization/factory.hpp>
#include <streams_boost/serialization/throw_exception.hpp>

// hijack serialization access
#include <streams_boost/serialization/access.hpp>

#include <streams_boost/config/abi_prefix.hpp> // must be the last header
#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4251 4231 4660 4275 4511 4512)
#endif

namespace streams_boost {
namespace serialization {
///////////////////////////////////////////////////////////////////////
// define a special type_info that doesn't depend on rtti which is not
// available in all situations.

namespace no_rtti_system {

// common base class to share type_info_key.  This is used to 
// identify the method used to keep track of the extended type
class STREAMS_BOOST_SERIALIZATION_DECL(STREAMS_BOOST_PP_EMPTY()) extended_type_info_no_rtti_0 : 
    public extended_type_info
{
protected:
    extended_type_info_no_rtti_0(const char * key);
    ~extended_type_info_no_rtti_0();
public:
    virtual bool
    is_less_than(const streams_boost::serialization::extended_type_info &rhs) const ;
    virtual bool
    is_equal(const streams_boost::serialization::extended_type_info &rhs) const ;
};

} // no_rtti_system

template<class T>
class extended_type_info_no_rtti : 
    public no_rtti_system::extended_type_info_no_rtti_0,
    public singleton<extended_type_info_no_rtti<T> >
{
    template<bool tf>
    struct action {
        struct defined {
            static const char * invoke(){
                return guid<T>();
            }
        };
        struct undefined {
            // if your program traps here - you failed to 
            // export a guid for this type.  the no_rtti
            // system requires export for types serialized
            // as pointers.
            STREAMS_BOOST_STATIC_ASSERT(0 == sizeof(T));
            static const char * invoke();
        };
        static const char * invoke(){
            typedef 
                STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::mpl::if_c<
                    tf,
                    defined,
                    undefined
                >::type type;
            return type::invoke();
        }
    };
public:
    extended_type_info_no_rtti() :
        no_rtti_system::extended_type_info_no_rtti_0(get_key())
    {
        key_register();
    }
    ~extended_type_info_no_rtti(){
        key_unregister();
    }
    const extended_type_info *
    get_derived_extended_type_info(const T & t) const {
        // find the type that corresponds to the most derived type.
        // this implementation doesn't depend on typeid() but assumes
        // that the specified type has a function of the following signature.
        // A common implemention of such a function is to define as a virtual
        // function. So if the is not a polymporphic type it's likely an error
        STREAMS_BOOST_STATIC_WARNING(streams_boost::is_polymorphic<T>::value);
        const char * derived_key = t.get_key();
        assert(NULL != derived_key);
        return streams_boost::serialization::extended_type_info::find(derived_key);
    }
    const char * get_key() const{
        return action<guid_defined<T>::value >::invoke();
    }
    virtual const char * get_debug_info() const{
        return action<guid_defined<T>::value >::invoke();
    }
    virtual void * construct(unsigned int count, ...) const{
        // count up the arguments
        std::va_list ap;
        va_start(ap, count);
        switch(count){
        case 0:
            return factory<T, 0>(ap);
        case 1:
            return factory<T, 1>(ap);
        case 2:
            return factory<T, 2>(ap);
        case 3:
            return factory<T, 3>(ap);
        case 4:
            return factory<T, 4>(ap);
        default:
            assert(false); // too many arguments
            // throw exception here?
            return NULL;
        }
    }
    virtual void destroy(void const * const p) const{
        streams_boost::serialization::access::destroy(
            static_cast<T const * const>(p)
        );
        //delete static_cast<T const * const>(p) ;
    }
};

} // namespace serialization
} // namespace streams_boost

///////////////////////////////////////////////////////////////////////////////
// If no other implementation has been designated as default, 
// use this one.  To use this implementation as the default, specify it
// before any of the other headers.

#ifndef STREAMS_BOOST_SERIALIZATION_DEFAULT_TYPE_INFO
    #define STREAMS_BOOST_SERIALIZATION_DEFAULT_TYPE_INFO
    namespace streams_boost {
    namespace serialization {
    template<class T>
    struct extended_type_info_impl {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME 
            streams_boost::serialization::extended_type_info_no_rtti<T> type;
    };
    } // namespace serialization
    } // namespace streams_boost
#endif

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(pop)
#endif
#include <streams_boost/config/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_EXTENDED_TYPE_INFO_NO_RTTI_HPP
