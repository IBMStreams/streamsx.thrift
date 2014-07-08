#ifndef STREAMS_BOOST_SERIALIZATION_EXTENDED_TYPE_INFO_HPP
#define STREAMS_BOOST_SERIALIZATION_EXTENDED_TYPE_INFO_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// extended_type_info.hpp: interface for portable version of type_info

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

// for now, extended type info is part of the serialization libraries
// this could change in the future.
#include <cstdarg>
#include <cassert>
#include <cstddef> // NULL
#include <streams_boost/config.hpp>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/serialization/config.hpp>
#include <streams_boost/mpl/bool.hpp>

#include <streams_boost/config/abi_prefix.hpp> // must be the last header
#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4251 4231 4660 4275)
#endif

#define STREAMS_BOOST_SERIALIZATION_MAX_KEY_SIZE 128

namespace streams_boost { 
namespace serialization {

namespace void_cast_detail{
    class void_caster;
}

class STREAMS_BOOST_SERIALIZATION_DECL(STREAMS_BOOST_PP_EMPTY()) extended_type_info :
    private streams_boost::noncopyable
{
private:
    friend class streams_boost::serialization::void_cast_detail::void_caster;

    // used to uniquely identify the type of class derived from this one
    // so that different derivations of this class can be simultaneously
    // included in implementation of sets and maps.
    const unsigned int m_type_info_key;
    virtual bool is_less_than(const extended_type_info & /*rhs*/) const = 0;
    virtual bool is_equal(const extended_type_info & /*rhs*/) const = 0;
    const char * m_key;

protected:
    void key_unregister() const;
    void key_register() const;
    // this class can't be used as is. It's just the 
    // common functionality for all type_info replacement
    // systems.  Hence, make these protected
    extended_type_info(
    	const unsigned int type_info_key,
    	const char * key
    );
    // account for bogus gcc warning
    #if defined(__GNUC__)
    virtual
    #endif
    ~extended_type_info();
public:
    const char * get_key() const {
        return m_key;
    }
    virtual const char * get_debug_info() const = 0;
    bool operator<(const extended_type_info &rhs) const;
    bool operator==(const extended_type_info &rhs) const;
    bool operator!=(const extended_type_info &rhs) const {
        return !(operator==(rhs));
    }
    static const extended_type_info * find(const char *key);
    // for plugins
    virtual void * construct(unsigned int /*count*/ = 0, ...) const = 0;
    virtual void destroy(void const * const /*p*/) const = 0;
};

template<class T>
struct guid_defined : streams_boost::mpl::false_ {};
template<class T>
inline const char * guid(){
    return NULL;
}

} // namespace serialization 
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#include <streams_boost/config/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_SERIALIZATION_EXTENDED_TYPE_INFO_HPP
