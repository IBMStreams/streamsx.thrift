#ifndef STREAMS_BOOST_ARCHIVE_XML_WOARCHIVE_HPP
#define STREAMS_BOOST_ARCHIVE_XML_WOARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// xml_woarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#ifdef STREAMS_BOOST_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else

#include <cstddef> // size_t
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::size_t; 
} // namespace std
#endif

#include <ostream>

#include <streams_boost/archive/detail/auto_link_warchive.hpp>
#include <streams_boost/archive/basic_text_oprimitive.hpp>
#include <streams_boost/archive/basic_xml_oarchive.hpp>
#include <streams_boost/archive/detail/register_archive.hpp>

#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace streams_boost {
namespace archive {

#if 0
STREAMS_BOOST_WARCHIVE_DECL(std::wostream &)
operator<<(std::wostream &os, const char *t);

STREAMS_BOOST_WARCHIVE_DECL(std::wostream &)
operator<<(std::wostream &os, const char t);
#endif

template<class Archive>
class xml_woarchive_impl : 
    public basic_text_oprimitive<std::wostream>,
    public basic_xml_oarchive<Archive>
{
#ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class detail::interface_oarchive<Archive>;
    friend class basic_xml_oarchive<Archive>;
    friend class save_access;
protected:
#endif
    //void end_preamble(){
    //    basic_xml_oarchive<Archive>::end_preamble();
    //}
    template<class T>
    void 
    save(const T & t){
        basic_text_oprimitive<std::wostream>::save(t);
    }
    STREAMS_BOOST_WARCHIVE_DECL(void)
    save(const char * t);
    #ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
    STREAMS_BOOST_WARCHIVE_DECL(void) 
    save(const wchar_t * t);
    #endif
    STREAMS_BOOST_WARCHIVE_DECL(void) 
    save(const std::string &s);
    #ifndef STREAMS_BOOST_NO_STD_WSTRING
    STREAMS_BOOST_WARCHIVE_DECL(void)
    save(const std::wstring &ws);
    #endif
    STREAMS_BOOST_WARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY()) 
    xml_woarchive_impl(std::wostream & os, unsigned int flags);
    ~xml_woarchive_impl(){}
public:
    void 
    save_binary(const void *address, std::size_t count){
        this->end_preamble();
        #if ! defined(__MWERKS__)
        this->basic_text_oprimitive<std::wostream>::save_binary(
        #else
        this->basic_text_oprimitive::save_binary(
        #endif
            address, 
            count
        );
        this->indent_next = true;
    }
};

// we use the following because we can't use
// typedef xml_woarchive_impl<xml_woarchive_impl<...> > xml_woarchive;

// do not derive from this class.  If you want to extend this functionality
// via inhertance, derived from xml_woarchive_impl instead.  This will
// preserve correct static polymorphism.
class xml_woarchive : 
    public xml_woarchive_impl<xml_woarchive>
{
public:
    xml_woarchive(std::wostream & os, unsigned int flags = 0) :
        xml_woarchive_impl<xml_woarchive>(os, flags)
    {}
    ~xml_woarchive(){}
};

typedef xml_woarchive naked_xml_woarchive;

} // namespace archive
} // namespace streams_boost

// required by export
STREAMS_BOOST_SERIALIZATION_REGISTER_ARCHIVE(streams_boost::archive::xml_woarchive)

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_NO_STD_WSTREAMBUF
#endif // STREAMS_BOOST_ARCHIVE_XML_OARCHIVE_HPP
