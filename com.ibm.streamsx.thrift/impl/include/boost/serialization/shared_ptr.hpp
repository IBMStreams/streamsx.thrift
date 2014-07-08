#ifndef STREAMS_BOOST_SERIALIZATION_SHARED_PTR_HPP
#define STREAMS_BOOST_SERIALIZATION_SHARED_PTR_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// shared_ptr.hpp: serialization for streams_boost shared pointer

// (C) Copyright 2004 Robert Ramey and Martin Ecker
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <map>
#include <cstddef> // NULL

#include <streams_boost/config.hpp>
#include <streams_boost/mpl/integral_c.hpp>
#include <streams_boost/mpl/integral_c_tag.hpp>

#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/shared_ptr.hpp>

#include <streams_boost/serialization/split_free.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/version.hpp>
#include <streams_boost/serialization/tracking.hpp>

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// shared_ptr serialization traits
// version 1 to distinguish from streams_boost 1.32 version. Note: we can only do this
// for a template when the compiler supports partial template specialization

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    namespace streams_boost {
    namespace serialization{
        template<class T>
        struct version< ::streams_boost::shared_ptr<T> > {
            typedef mpl::integral_c_tag tag;
            #if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3206))
            typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::int_<1> type;
            #else
            typedef mpl::int_<1> type;
            #endif
            #if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x570))
            STREAMS_BOOST_STATIC_CONSTANT(unsigned int, value = 1);
            #else
            STREAMS_BOOST_STATIC_CONSTANT(unsigned int, value = type::value);
            #endif
        };
        // don't track shared pointers
        template<class T>
        struct tracking_level< ::streams_boost::shared_ptr<T> > { 
            typedef mpl::integral_c_tag tag;
            #if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3206))
            typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::int_< ::streams_boost::serialization::track_never> type;
            #else
            typedef mpl::int_< ::streams_boost::serialization::track_never> type;
            #endif
            #if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x570))
            STREAMS_BOOST_STATIC_CONSTANT(int, value = ::streams_boost::serialization::track_never);
            #else
            STREAMS_BOOST_STATIC_CONSTANT(int, value = type::value);
            #endif
        };
    }}
    #define STREAMS_BOOST_SERIALIZATION_SHARED_PTR(T)
#else
    // define macro to let users of these compilers do this
    #define STREAMS_BOOST_SERIALIZATION_SHARED_PTR(T)                         \
    STREAMS_BOOST_CLASS_VERSION(                                              \
        ::streams_boost::shared_ptr< T >,                                     \
        1                                                             \
    )                                                                 \
    STREAMS_BOOST_CLASS_TRACKING(                                             \
        ::streams_boost::shared_ptr< T >,                                     \
        ::streams_boost::serialization::track_never                           \
    )                                                                 \
    /**/
#endif

namespace streams_boost {
namespace serialization{

struct null_deleter {
    void operator()(void const *) const {}
};

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// serialization for shared_ptr

template<class Archive, class T>
inline void save(
    Archive & ar,
    const streams_boost::shared_ptr<T> &t,
    const unsigned int /* file_version */
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    STREAMS_BOOST_STATIC_ASSERT((tracking_level<T>::value != track_never));
    const T * t_ptr = t.get();
    ar << streams_boost::serialization::make_nvp("px", t_ptr);
}

#ifdef STREAMS_BOOST_SERIALIZATION_SHARED_PTR_132_HPP
template<class Archive, class T>
inline void load(
    Archive & ar,
    streams_boost::shared_ptr<T> &t,
    const unsigned int file_version
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    STREAMS_BOOST_STATIC_ASSERT((tracking_level<T>::value != track_never));
    T* r;
    if(file_version < 1){
        //ar.register_type(static_cast<
        //    streams_boost_132::detail::sp_counted_base_impl<T *, streams_boost::checked_deleter<T> > *
        //>(NULL));
        ar.register_type(static_cast<
            streams_boost_132::detail::sp_counted_base_impl<T *, null_deleter > *
        >(NULL));
        streams_boost_132::shared_ptr<T> sp;
        ar >> streams_boost::serialization::make_nvp("px", sp.px);
        ar >> streams_boost::serialization::make_nvp("pn", sp.pn);
        // got to keep the sps around so the sp.pns don't disappear
        ar.append(sp);
        r = sp.get();
    }
    else{
        ar >> streams_boost::serialization::make_nvp("px", r);
    }
    ar.reset(t,r);
}

#else
template<class Archive, class T>
inline void load(
    Archive & ar,
    streams_boost::shared_ptr<T> &t,
    const unsigned int /*file_version*/
){
    // The most common cause of trapping here would be serializing
    // something like shared_ptr<int>.  This occurs because int
    // is never tracked by default.  Wrap int in a trackable type
    STREAMS_BOOST_STATIC_ASSERT((tracking_level<T>::value != track_never));
    T* r;
    ar >> streams_boost::serialization::make_nvp("px", r);
    ar.reset(t,r);
}
#endif

template<class Archive, class T>
inline void serialize(
    Archive & ar,
    streams_boost::shared_ptr<T> &t,
    const unsigned int file_version
){
    // correct shared_ptr serialization depends upon object tracking
    // being used.
    STREAMS_BOOST_STATIC_ASSERT(
        streams_boost::serialization::tracking_level<T>::value
        != streams_boost::serialization::track_never
    );
    streams_boost::serialization::split_free(ar, t, file_version);
}

} // namespace serialization
} // namespace streams_boost

#endif // STREAMS_BOOST_SERIALIZATION_SHARED_PTR_HPP
