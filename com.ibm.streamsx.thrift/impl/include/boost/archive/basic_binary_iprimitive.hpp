#ifndef STREAMS_BOOST_ARCHIVE_BINARY_IPRIMITIVE_HPP
#define STREAMS_BOOST_ARCHIVE_BINARY_IPRIMITIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#if defined(_MSC_VER)
#pragma warning( disable : 4800 )
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_binary_iprimitive.hpp
//
// archives stored as native binary - this should be the fastest way
// to archive the state of a group of obects.  It makes no attempt to
// convert to any canonical form.

// IN GENERAL, ARCHIVES CREATED WITH THIS CLASS WILL NOT BE READABLE
// ON PLATFORM APART FROM THE ONE THEY ARE CREATED ON

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <iosfwd>
#include <cassert>
#include <locale>
#include <cstring> // std::memcpy
#include <cstddef> // std::size_t
#include <streambuf> // basic_streambuf
#include <string>

#include <streams_boost/config.hpp>
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::memcpy; 
    using ::size_t;
} // namespace std
#endif

#include <streams_boost/cstdint.hpp>
#include <streams_boost/scoped_ptr.hpp>
#include <streams_boost/serialization/throw_exception.hpp>
#include <streams_boost/integer.hpp>
#include <streams_boost/integer_traits.hpp>

#include <streams_boost/archive/basic_streambuf_locale_saver.hpp>
#include <streams_boost/archive/archive_exception.hpp>
#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/mpl/placeholders.hpp>
#include <streams_boost/serialization/is_bitwise_serializable.hpp>
#include <streams_boost/serialization/array.hpp>
#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

namespace streams_boost { 
namespace archive {

/////////////////////////////////////////////////////////////////////////////
// class binary_iarchive - read serialized objects from a input binary stream
template<class Archive, class Elem, class Tr>
class basic_binary_iprimitive
{
#ifndef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
    friend class load_access;
protected:
#else
public:
#endif
    std::basic_streambuf<Elem, Tr> & m_sb;
    // return a pointer to the most derived class
    Archive * This(){
        return static_cast<Archive *>(this);
    }

    #ifndef STREAMS_BOOST_NO_STD_LOCALE
    streams_boost::scoped_ptr<std::locale> archive_locale;
    basic_streambuf_locale_saver<Elem, Tr> locale_saver;
    #endif

    // main template for serilization of primitive types
    template<class T>
    void load(T & t){
        load_binary(& t, sizeof(T));
    }

    /////////////////////////////////////////////////////////
    // fundamental types that need special treatment
    
    // trap usage of invalid uninitialized boolean 
    void load(bool & t){
        load_binary(& t, sizeof(t));
        int i = t;
        assert(0 == i || 1 == i);
        (void)i; // warning suppression for release builds.
    }
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load(std::string &s);
    #ifndef STREAMS_BOOST_NO_STD_WSTRING
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load(std::wstring &ws);
    #endif
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load(char * t);
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    load(wchar_t * t);

    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
    init();
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    basic_binary_iprimitive(
        std::basic_streambuf<Elem, Tr> & sb, 
        bool no_codecvt
    );
    STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    ~basic_binary_iprimitive();
public:
    // we provide an optimized load for all fundamental types
    // typedef serialization::is_bitwise_serializable<mpl::_1> 
    // use_array_optimization;
    struct use_array_optimization {  
        template <class T>  
        #if defined(STREAMS_BOOST_NO_DEPENDENT_NESTED_DERIVATIONS)  
            struct apply {  
                typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::serialization::is_bitwise_serializable<T>::type type;  
            };
        #else
            struct apply : public streams_boost::serialization::is_bitwise_serializable<T> {};  
        #endif
    };

    // the optimized load_array dispatches to load_binary 
    template <class ValueType>
    void load_array(serialization::array<ValueType>& a, unsigned int)
    {
      load_binary(a.address(),a.count()*sizeof(ValueType));
    }

    void
    load_binary(void *address, std::size_t count);
};

template<class Archive, class Elem, class Tr>
inline void
basic_binary_iprimitive<Archive, Elem, Tr>::load_binary(
    void *address, 
    std::size_t count
){
    // note: an optimizer should eliminate the following for char files
    assert(
        static_cast<std::streamsize>(count / sizeof(Elem)) 
        <= streams_boost::integer_traits<std::streamsize>::const_max
    );
    std::streamsize s = static_cast<std::streamsize>(count / sizeof(Elem));
    std::streamsize scount = m_sb.sgetn(
        static_cast<Elem *>(address), 
        s
    );
    if(scount != s)
        streams_boost::serialization::throw_exception(
            archive_exception(archive_exception::stream_error)
        );
    // note: an optimizer should eliminate the following for char files
    assert(count % sizeof(Elem) <= streams_boost::integer_traits<std::streamsize>::const_max);
    s = static_cast<std::streamsize>(count % sizeof(Elem));
    if(0 < s){
//        if(is.fail())
//            streams_boost::serialization::throw_exception(
//                archive_exception(archive_exception::stream_error)
//        );
        Elem t;
        scount = m_sb.sgetn(& t, 1);
        if(scount != 1)
            streams_boost::serialization::throw_exception(
                archive_exception(archive_exception::stream_error)
            );
        std::memcpy(static_cast<char*>(address) + (count - s), &t, s);
    }
}

} // namespace archive
} // namespace streams_boost

#include <streams_boost/archive/detail/abi_suffix.hpp> // pop pragmas

#endif // STREAMS_BOOST_ARCHIVE_BINARY_IPRIMITIVE_HPP
