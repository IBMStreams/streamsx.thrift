#ifndef STREAMS_BOOST_ARCHIVE_ITERATORS_XML_UNESCAPE_HPP
#define STREAMS_BOOST_ARCHIVE_ITERATORS_XML_UNESCAPE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// xml_unescape.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <cassert>

#include <streams_boost/config.hpp> // for STREAMS_BOOST_DEDUCED_TYPENAME

#include <streams_boost/serialization/throw_exception.hpp>
#include <streams_boost/serialization/pfto.hpp>

#include <streams_boost/archive/iterators/unescape.hpp>
#include <streams_boost/archive/iterators/dataflow_exception.hpp>

namespace streams_boost { 
namespace archive {
namespace iterators {

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// replace &??? xml escape sequences with the corresponding characters
template<class Base>
class xml_unescape 
    : public unescape<xml_unescape<Base>, Base>
{
    friend class streams_boost::iterator_core_access;
    typedef xml_unescape<Base> this_t;
    typedef unescape<this_t, Base> super_t;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::iterator_reference<this_t> reference_type;

    reference_type dereference() const {
        return unescape<xml_unescape<Base>, Base>::dereference();
    }
public:
    // workaround msvc 7.1 ICU crash
    #if defined(STREAMS_BOOST_MSVC)
        typedef int value_type;
    #else
        typedef STREAMS_BOOST_DEDUCED_TYPENAME this_t::value_type value_type;
    #endif

    void drain_residue(const char *literal);
    value_type drain();

    template<class T>
    xml_unescape(STREAMS_BOOST_PFTO_WRAPPER(T) start) : 
        super_t(Base(STREAMS_BOOST_MAKE_PFTO_WRAPPER(static_cast<T>(start))))
    {}
    // intel 7.1 doesn't like default copy constructor
    xml_unescape(const xml_unescape & rhs) : 
        super_t(rhs.base_reference())
    {}
};

template<class Base>
void xml_unescape<Base>::drain_residue(const char * literal){
    do{
        if(* literal != * ++(this->base_reference()))
            streams_boost::serialization::throw_exception(
                dataflow_exception(
                    dataflow_exception::invalid_xml_escape_sequence
                )
            );
    }
    while('\0' != * ++literal);
}

// note key constraint on this function is that can't "look ahead" any
// more than necessary into base iterator.  Doing so would alter the base
// iterator refenence which would make subsequent iterator comparisons
// incorrect and thereby break the composiblity of iterators.
template<class Base>
STREAMS_BOOST_DEDUCED_TYPENAME xml_unescape<Base>::value_type 
//int 
xml_unescape<Base>::drain(){
    value_type retval = * this->base_reference();
    if('&' != retval){
        return retval;
    }
    retval = * ++(this->base_reference());
    switch(retval){
    case 'l': // &lt;
        drain_residue("t;");
        retval = '<';
        break;
    case 'g': // &gt;
        drain_residue("t;");
        retval = '>';
        break;
    case 'a':
        retval = * ++(this->base_reference());
        switch(retval){
        case 'p': // &apos;
            drain_residue("os;");
            retval = '\'';
            break;
        case 'm': // &amp;
            drain_residue("p;");
            retval = '&';
            break;
        }
        break;
    case 'q':
        drain_residue("uot;");
        retval = '"';
        break;
    }
    return retval;
}

} // namespace iterators
} // namespace archive
} // namespace streams_boost

#endif // STREAMS_BOOST_ARCHIVE_ITERATORS_XML_UNESCAPE_HPP
