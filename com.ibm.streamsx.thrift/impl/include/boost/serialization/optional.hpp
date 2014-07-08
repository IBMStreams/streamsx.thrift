/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8

// (C) Copyright 2002-4 Pavel Vozenilek . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// Provides non-intrusive serialization for streams_boost::optional.

#ifndef STREAMS_BOOST_SERIALIZATION_OPTIONAL_HPP_
#define STREAMS_BOOST_SERIALIZATION_OPTIONAL_HPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/optional.hpp>
#include <streams_boost/serialization/split_free.hpp>
#include <streams_boost/serialization/level.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/version.hpp>
#include <streams_boost/serialization/detail/stack_constructor.hpp>

// function specializations must be defined in the appropriate
// namespace - streams_boost::serialization
namespace streams_boost { 
namespace serialization {

template<class Archive, class T>
void save(
    Archive & ar, 
    const streams_boost::optional<T> & t, 
    const unsigned int /*version*/
){
    const bool tflag = t.is_initialized();
    ar << streams_boost::serialization::make_nvp("initialized", tflag);
    if (tflag){
        if(3 < ar.get_library_version()){
            const int v = version<T>::value;
            ar << streams_boost::serialization::make_nvp("item_version", v);
        }
        ar << streams_boost::serialization::make_nvp("value", *t);
    }
}

template<class Archive, class T>
void load(
    Archive & ar, 
    streams_boost::optional<T> & t, 
    const unsigned int /*version*/
){
    bool tflag;
    ar >> streams_boost::serialization::make_nvp("initialized", tflag);
    if (tflag){
        unsigned int v = 0;
        if(3 < ar.get_library_version()){
            ar >> streams_boost::serialization::make_nvp("item_version", v);
        }
        detail::stack_construct<Archive, T> aux(ar, v);
        ar >> streams_boost::serialization::make_nvp("value", aux.reference());
        t.reset(aux.reference());
    }
    else {
        t.reset();
    }
}

template<class Archive, class T>
void serialize(
    Archive & ar, 
    streams_boost::optional<T> & t, 
    const unsigned int version
){
    streams_boost::serialization::split_free(ar, t, version);
}

// the following would be slightly more efficient.  But it
// would mean that archives created with programs that support
// TPS wouldn't be readable by programs that don't support TPS.
// Hence we decline to support this otherwise convenient optimization.
//#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#if 0

template <class T>
struct implementation_level<optional<T> >
{
    typedef mpl::integral_c_tag tag;
    typedef mpl::int_<streams_boost::serialization::object_serializable> type;
    STREAMS_BOOST_STATIC_CONSTANT(
        int , 
        value = streams_boost::serialization::implementation_level::type::value
    );
};

template<class T>
struct tracking_level<optional<T> >
{
    typedef mpl::integral_c_tag tag;
    typedef mpl::int_<streams_boost::serialization::track_never> type;
    STREAMS_BOOST_STATIC_CONSTANT(
        int , 
        value = streams_boost::serialization::tracking_level::type::value
    );
};

#endif

} // serialization
} // namespace streams_boost

#endif // STREAMS_BOOST_SERIALIZATION_OPTIONAL_HPP_
