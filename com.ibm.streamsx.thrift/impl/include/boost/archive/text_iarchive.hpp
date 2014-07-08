#ifndef STREAMS_BOOST_ARCHIVE_TEXT_IARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_TEXT_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// text_iarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <istream>

#include <streams_boost/config.hpp>
#include <streams_boost/archive/detail/auto_link_archive.hpp>
#include <streams_boost/archive/basic_text_iprimitive.hpp>
#include <streams_boost/archive/basic_text_iarchive.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost { 
namespace archive {

template<class Archive>
class text_iarchive_impl : 
    public basic_text_iprimitive<std::istream>,
    public basic_text_iarchive<Archive>
{
#ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class detail::interface_iarchive<Archive>;
    friend class basic_text_iarchive<Archive>;
    friend class load_access;
protected:
#endif
    template<class T>
    void load(T & t){
        basic_text_iprimitive<std::istream>::load(t);
    }
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    load(char * t);
    #ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    load(wchar_t * t);
    #endif
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    load(std::string &s);
    #ifndef STREAMS_BOOST_NO_STD_WSTRING
    STREAMS_BOOST_ARCHIVE_DECL(void) 
    load(std::wstring &ws);
    #endif
    // note: the following should not needed - but one compiler (vc 7.1)
    // fails to compile one test (test_shared_ptr) without it !!!
    // make this protected so it can be called from a derived archive
    template<class T>
    void load_override(T & t, STREAMS_BOOST_PFTO int){
        basic_text_iarchive<Archive>::load_override(t, 0);
    }
    STREAMS_BOOST_ARCHIVE_DECL(void)
    load_override(class_name_type & t, int);
    STREAMS_BOOST_ARCHIVE_DECL(void)
    init();
    STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    text_iarchive_impl(std::istream & is, unsigned int flags);
    STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    ~text_iarchive_impl(){};
};

// do not derive from the classes below.  If you want to extend this functionality
// via inhertance, derived from text_iarchive_impl instead.  This will
// preserve correct static polymorphism.

// same as text_iarchive below - without the shared_ptr_helper
class naked_text_iarchive : 
    public text_iarchive_impl<naked_text_iarchive>
{
public:
    naked_text_iarchive(std::istream & is_, unsigned int flags = 0) :
        // note: added _ to suppress useless gcc warning
        text_iarchive_impl<naked_text_iarchive>(is_, flags)
    {}
    ~naked_text_iarchive(){}
};

} // namespace archive
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

// note special treatment of shared_ptr. This type needs a special
// structure associated with every archive.  We created a "mix-in"
// class to provide this functionality.  Since shared_ptr holds a
// special esteem in the streams_boost library - we included it here by default.
#include <streams_boost/archive/shared_ptr_helper.hpp>

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost { 
namespace archive {

class text_iarchive : 
    public text_iarchive_impl<text_iarchive>,
    public detail::shared_ptr_helper
{
public:
    text_iarchive(std::istream & is_, unsigned int flags = 0) :
        // note: added _ to suppress useless gcc warning
        text_iarchive_impl<text_iarchive>(is_, flags)
    {}
    ~text_iarchive(){}
};

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::archive::text_iarchive)

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#endif // STREAMS_BOOST_ARCHIVE_TEXT_IARCHIVE_HPP
