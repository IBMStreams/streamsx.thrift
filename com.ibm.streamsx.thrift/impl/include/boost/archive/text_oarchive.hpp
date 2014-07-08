#ifndef STREAMS_BOOST_ARCHIVE_TEXT_OARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_TEXT_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// text_oarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <ostream>
#include <cstddef> // std::size_t

#include <streams_boost/config.hpp>
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::size_t; 
} // namespace std
#endif

#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/basic_text_oprimitive.hpp>
#include <streams_boost/archive/basic_text_oarchive.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost { 
namespace archive {

template<class Archive>
class text_oarchive_impl : 
     /* protected ? */ public basic_text_oprimitive<std::ostream>,
     public basic_text_oarchive<Archive>
{
#ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class detail::interface_oarchive<Archive>;
    friend class basic_text_oarchive<Archive>;
    friend class save_access;
protected:
#endif
    template<class T>
    void save(const T & t){
        this->newtoken();
        basic_text_oprimitive<std::ostream>::save(t);
    }
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    save(const char * t);
    #ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    save(const wchar_t * t);
    #endif
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    save(const std::string &s);
    #ifndef STREAMS_BOOST_NO_STD_WSTRING
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    save(const std::wstring &ws);
    #endif
    STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    text_oarchive_impl(std::ostream & os, unsigned int flags);
    STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    ~text_oarchive_impl(){};
public:
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    save_binary(const void *address, std::size_t count);
};

// do not derive from this class.  If you want to extend this functionality
// via inhertance, derived from text_oarchive_impl instead.  This will
// preserve correct static polymorphism.
class text_oarchive : 
    public text_oarchive_impl<text_oarchive>
{
public:
    text_oarchive(std::ostream & os_, unsigned int flags = 0) :
        // note: added _ to suppress useless gcc warning
        text_oarchive_impl<text_oarchive>(os_, flags)
    {}
    ~text_oarchive(){}
};

typedef text_oarchive naked_text_oarchive;

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::archive::text_oarchive)

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_ARCHIVE_TEXT_OARCHIVE_HPP
