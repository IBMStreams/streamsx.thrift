#ifndef STREAMS_BOOST_ARCHIVE_POLYMORPHIC_OARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_POLYMORPHIC_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// polymorphic_oarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <cstddef> // size_t
#include <climits> // ULONG_MAX 
#include <string>

#include <streams_boost/config.hpp>
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{
    using ::size_t;
} // namespace std
#endif

#include <streams_boost/cstdint.hpp>
#include <streams_boost/serialization/pfto.hpp>
#include <streams_boost/archive/detail/oserializer.hpp>
#include <streams_boost/archive/detail/interface_oarchive.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

#include <streams_boost/archive/detail/decl.hpp>
#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

// determine if its necessary to handle (u)int64_t specifically
// i.e. that its not a synonym for (unsigned) long
// if there is no 64 bit int or if its the same as a long
// we shouldn't define separate functions for int64 data types.
#if defined(STREAMS_BOOST_NO_INT64_T)
    #define STREAMS_BOOST_NO_INTRINSIC_INT64_T
#else 
    #if defined(ULLONG_MAX)  
        #if(ULONG_MAX == 18446744073709551615ul) // 2**64 - 1  
            #define STREAMS_BOOST_NO_INTRINSIC_INT64_T  
        #endif  
    #elif defined(ULONG_MAX)  
        #if(ULONG_MAX != 0xffffffff && ULONG_MAX == 18446744073709551615ul) // 2**64 - 1  
            #define STREAMS_BOOST_NO_INTRINSIC_INT64_T  
        #endif  
    #else   
        #define STREAMS_BOOST_NO_INTRINSIC_INT64_T  
    #endif  
#endif

namespace streams_boost {
template<class T>
class shared_ptr;
namespace serialization {
    class extended_type_info;
} // namespace serialization
namespace archive {
namespace detail {
    class STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) basic_oarchive;
    class STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) basic_oserializer;
}

class polymorphic_oarchive;

class polymorphic_oarchive_impl :
    public detail::interface_oarchive<polymorphic_oarchive>
{
#ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class detail::interface_oarchive<polymorphic_oarchive>;
    friend class save_access;
#endif
    // primitive types the only ones permitted by polymorphic archives
    virtual void save(const bool t) = 0;

    virtual void save(const char t) = 0;
    virtual void save(const signed char t) = 0;
    virtual void save(const unsigned char t) = 0;
    #ifndef STREAMS_BOOST_NO_CWCHAR
    #ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
    virtual void save(const wchar_t t) = 0;
    #endif
    #endif
    virtual void save(const short t) = 0;
    virtual void save(const unsigned short t) = 0;
    virtual void save(const int t) = 0;
    virtual void save(const unsigned int t) = 0;
    virtual void save(const long t) = 0;
    virtual void save(const unsigned long t) = 0;
    #if !defined(STREAMS_BOOST_NO_INTRINSIC_INT64_T)
    virtual void save(const streams_boost::int64_t t) = 0;
    virtual void save(const streams_boost::uint64_t t) = 0;
    #endif
    virtual void save(const float t) = 0;
    virtual void save(const double t) = 0;

    // string types are treated as primitives
    virtual void save(const std::string & t) = 0;
    #ifndef STREAMS_BOOST_NO_STD_WSTRING
    virtual void save(const std::wstring & t) = 0;
    #endif

    virtual void save_null_pointer() = 0;
    // used for xml and other tagged formats
    virtual void save_start(const char * name) = 0;
    virtual void save_end(const char * name) = 0;
    virtual void register_basic_serializer(const detail::basic_oserializer & bos) = 0;

    virtual void end_preamble() = 0;

    // msvc and borland won't automatically pass these to the base class so
    // make it explicit here
    template<class T>
    void save_override(T & t, STREAMS_BOOST_PFTO int)
    {
        archive::save(* this->This(), t);
    }
    // special treatment for name-value pairs.
    template<class T>
    void save_override(
                #ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
                const
                #endif
                ::streams_boost::serialization::nvp<T> & t, int
        ){
        save_start(t.name());
        archive::save(* this->This(), t.const_value());
        save_end(t.name());
    }
protected:
    virtual ~polymorphic_oarchive_impl(){};
public:
    // utility functions implemented by all legal archives
    virtual unsigned int get_flags() const = 0;
    virtual unsigned int get_library_version() const = 0;
    virtual void save_binary(const void * t, std::size_t size) = 0;

    virtual void save_object(
        const void *x,
        const detail::basic_oserializer & bos
    ) = 0;
    virtual void save_pointer(
        const void * t,
        const detail::basic_pointer_oserializer * bpos_ptr
    ) = 0;
};

// note: preserve naming symmetry
class polymorphic_oarchive : 
    public polymorphic_oarchive_impl
{
public:
    virtual ~polymorphic_oarchive(){};
};

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::archive::polymorphic_oarchive)

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_ARCHIVE_POLYMORPHIC_OARCHIVE_HPP
