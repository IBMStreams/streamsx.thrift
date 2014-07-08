/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// basic_xml_oarchive.ipp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com .
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <algorithm>
#include <cstddef> // NULL
#include <cstring>
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE) && ! defined(__LIBCOMO__)
namespace std{
    using ::strlen;
} // namespace std
#endif

#include <streams_boost/archive/basic_xml_archive.hpp>
#include <streams_boost/archive/basic_xml_oarchive.hpp>
#include <streams_boost/archive/xml_archive_exception.hpp>
#include <streams_boost/detail/no_exceptions_support.hpp>

namespace streams_boost {
namespace archive {

namespace detail {
template<class CharType>
struct XML_name {
    void operator()(CharType t) const{
        const unsigned char lookup_table[] = {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0, // -.
            1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0, // 0-9
            0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, // A-
            1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1, // -Z _
            0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, // a-
            1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0, // -z
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        };
        if((unsigned)t > 127)
            return;
        if(0 == lookup_table[(unsigned)t])
            streams_boost::serialization::throw_exception(
                xml_archive_exception(
                    xml_archive_exception::xml_archive_tag_name_error
                )
            );
    }
};

} // namespace detail

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// implemenations of functions common to both types of xml output

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::write_attribute(
    const char *attribute_name,
    int t,
    const char *conjunction
){
    this->This()->put(' ');
    this->This()->put(attribute_name);
    this->This()->put(conjunction);
    this->This()->save(t);
    this->This()->put('"');
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::write_attribute(
    const char *attribute_name,
    const char *key
){
    this->This()->put(' ');
    this->This()->put(attribute_name);
    this->This()->put("=\"");
    this->This()->save(key);
    this->This()->put('"');
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::indent(){
    int i;
    for(i = depth; i-- > 0;)
        this->This()->put('\t');
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_start(const char *name)
{
    if(NULL == name)
        return;

    // be sure name has no invalid characters
    std::for_each(name, name + std::strlen(name), detail::XML_name<const char>());

    end_preamble();
    if(depth > 0){
        this->This()->put('\n');
        indent();
    }
    ++depth;
    this->This()->put('<');
    this->This()->save(name);
    pending_preamble = true;
    indent_next = false;
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_end(const char *name)
{
    if(NULL == name)
        return;

    // be sure name has no invalid characters
    std::for_each(name, name + std::strlen(name), detail::XML_name<const char>());

    end_preamble();
    --depth;
    if(indent_next){
        this->This()->put('\n');
        indent();
    }
    indent_next = true;
    this->This()->put("</");
    this->This()->save(name);
    this->This()->put('>');
    if(0 == depth)
        this->This()->put('\n');
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::end_preamble(){
    if(pending_preamble){
        this->This()->put('>');
        pending_preamble = false;
    }
}
#if 0
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const object_id_type & t, int)
{
    int i = t.t; // extra .t is for borland
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_OBJECT_ID(), i, "=\"_");
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(
    const object_reference_type & t,
    int
){
    int i = t.t; // extra .t is for borland
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_OBJECT_REFERENCE(), i, "=\"_");
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const version_type & t, int)
{
    int i = t.t; // extra .t is for borland
    write_attribute(VSTREAMS_BOOST_ARCHIVE_XML_ERSION(), i);
}
#endif

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const object_id_type & t, int)
{
    // borland doesn't do conversion of STRONG_TYPEDEFs very well
    const unsigned int i = t;
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_OBJECT_ID(), i, "=\"_");
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(
    const object_reference_type & t,
    int
){
    const unsigned int i = t;
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_OBJECT_REFERENCE(), i, "=\"_");
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const version_type & t, int)
{
    const unsigned int i = t;
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_VERSION(), i);
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const class_id_type & t, int)
{
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_CLASS_ID(), t);
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(
    const class_id_reference_type & t,
    int
){
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_CLASS_ID_REFERENCE(), t);
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(
    const class_id_optional_type & t,
    int
){
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_CLASS_ID(), t);
}
template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const class_name_type & t, int)
{
    const char * key = t;
    if(NULL == key)
        return;
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_CLASS_NAME(), key);
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::save_override(const tracking_type & t, int)
{
    write_attribute(STREAMS_BOOST_ARCHIVE_XML_TRACKING(), t.t);
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(void)
basic_xml_oarchive<Archive>::init(){
    // xml header
    this->This()->put("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\n");
    this->This()->put("<!DOCTYPE streams_boost_serialization>\n");
    // xml document wrapper - outer root
    this->This()->put("<streams_boost_serialization");
    write_attribute("signature", STREAMS_BOOST_ARCHIVE_SIGNATURE());
    write_attribute("version", STREAMS_BOOST_ARCHIVE_VERSION());
    this->This()->put(">\n");
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY())
basic_xml_oarchive<Archive>::basic_xml_oarchive(unsigned int flags) :
    detail::common_oarchive<Archive>(flags),
    depth(0),
    indent_next(false),
    pending_preamble(false)
{
}

template<class Archive>
STREAMS_BOOST_ARCHIVE_OR_WARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY())
basic_xml_oarchive<Archive>::~basic_xml_oarchive(){
    if(0 == (this->get_flags() & no_header)){
        STREAMS_BOOST_TRY{
                this->This()->put("</streams_boost_serialization>\n");
        }
        STREAMS_BOOST_CATCH(...){}
        STREAMS_BOOST_CATCH_END
    }
}

} // namespace archive
} // namespace streams_boost
