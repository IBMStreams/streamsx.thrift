#ifndef STREAMS_BOOST_SERIALIZATION_SHARED_PTR_132_HPP
#define STREAMS_BOOST_SERIALIZATION_SHARED_PTR_132_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// shared_ptr.hpp: serialization for streams_boost shared pointer

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

// note: totally unadvised hack to gain access to private variables
// in shared_ptr and shared_count. Unfortunately its the only way to
// do this without changing shared_ptr and shared_count
// the best we can do is to detect a conflict here
#include <streams_boost/config.hpp>

#include <list>
#include <cstddef> // NULL

#include <streams_boost/serialization/assume_abstract.hpp>
#include <streams_boost/serialization/split_free.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/tracking.hpp>
#include <streams_boost/serialization/void_cast.hpp>

// mark base class as an (uncreatable) base class
#include <streams_boost/serialization/detail/shared_ptr_132.hpp>

/////////////////////////////////////////////////////////////
// Maintain a couple of lists of loaded shared pointers of the old previous
// version (1.32)

namespace streams_boost_132 { 
namespace serialization {
namespace detail {

struct null_deleter {
    void operator()(void const *) const {}
};

} // namespace detail
} // namespace serialization
} // namespace streams_boost_132

/////////////////////////////////////////////////////////////
// sp_counted_base_impl serialization

namespace streams_boost { 
namespace serialization {

template<class Archive, class P, class D>
inline void serialize(
    Archive & /* ar */,
    streams_boost_132::detail::sp_counted_base_impl<P, D> & /* t */,
    const unsigned int /*file_version*/
){
    // register the relationship between each derived class
    // its polymorphic base
    streams_boost::serialization::void_cast_register<
        streams_boost_132::detail::sp_counted_base_impl<P, D>,
        streams_boost_132::detail::sp_counted_base 
    >(
        static_cast<streams_boost_132::detail::sp_counted_base_impl<P, D> *>(NULL),
        static_cast<streams_boost_132::detail::sp_counted_base *>(NULL)
    );
}

template<class Archive, class P, class D>
inline void save_construct_data(
    Archive & ar,
    const 
    streams_boost_132::detail::sp_counted_base_impl<P, D> *t, 
    const STREAMS_BOOST_PFTO unsigned int /* file_version */
){
    // variables used for construction
    ar << streams_boost::serialization::make_nvp("ptr", t->ptr);
}

template<class Archive, class P, class D>
inline void load_construct_data(
    Archive & ar,
    streams_boost_132::detail::sp_counted_base_impl<P, D> * t, 
    const unsigned int /* file_version */
){
    P ptr_;
    ar >> streams_boost::serialization::make_nvp("ptr", ptr_);
    // ::new(t)streams_boost_132::detail::sp_counted_base_impl<P, D>(ptr_,  D()); 
    // placement
    // note: the original ::new... above is replaced by the one here.  This one
    // creates all new objects with a null_deleter so that after the archive
    // is finished loading and the shared_ptrs are destroyed - the underlying
    // raw pointers are NOT deleted.  This is necessary as they are used by the 
    // new system as well.
    ::new(t)streams_boost_132::detail::sp_counted_base_impl<
        P, 
        streams_boost_132::serialization::detail::null_deleter
    >(
        ptr_,  streams_boost_132::serialization::detail::null_deleter()
    ); // placement new
    // compensate for that fact that a new shared count always is 
    // initialized with one. the add_ref_copy below will increment it
    // every time its serialized so without this adjustment
    // the use and weak counts will be off by one.
    t->use_count_ = 0;
}

} // serialization
} // namespace streams_boost

/////////////////////////////////////////////////////////////
// shared_count serialization

namespace streams_boost { 
namespace serialization {

template<class Archive>
inline void save(
    Archive & ar,
    const streams_boost_132::detail::shared_count &t,
    const unsigned int /* file_version */
){
    ar << streams_boost::serialization::make_nvp("pi", t.pi_);
}

template<class Archive>
inline void load(
    Archive & ar,
    streams_boost_132::detail::shared_count &t,
    const unsigned int /* file_version */
){
    ar >> streams_boost::serialization::make_nvp("pi", t.pi_);
    if(NULL != t.pi_)
        t.pi_->add_ref_copy();
}

} // serialization
} // namespace streams_boost

STREAMS_BOOST_SERIALIZATION_SPLIT_FREE(streams_boost_132::detail::shared_count)

/////////////////////////////////////////////////////////////
// implement serialization for shared_ptr<T>

namespace streams_boost { 
namespace serialization {

template<class Archive, class T>
inline void save(
    Archive & ar,
    const streams_boost_132::shared_ptr<T> &t,
    const unsigned int /* file_version */
){
    // only the raw pointer has to be saved
    // the ref count is maintained automatically as shared pointers are loaded
    ar.register_type(static_cast<
        streams_boost_132::detail::sp_counted_base_impl<T *, streams_boost::checked_deleter<T> > *
    >(NULL));
    ar << streams_boost::serialization::make_nvp("px", t.px);
    ar << streams_boost::serialization::make_nvp("pn", t.pn);
}

template<class Archive, class T>
inline void load(
    Archive & ar,
    streams_boost_132::shared_ptr<T> &t,
    const unsigned int /* file_version */
){
    // only the raw pointer has to be saved
    // the ref count is maintained automatically as shared pointers are loaded
    ar.register_type(static_cast<
        streams_boost_132::detail::sp_counted_base_impl<T *, streams_boost::checked_deleter<T> > *
    >(NULL));
    ar >> streams_boost::serialization::make_nvp("px", t.px);
    ar >> streams_boost::serialization::make_nvp("pn", t.pn);
}

template<class Archive, class T>
inline void serialize(
    Archive & ar,
    streams_boost_132::shared_ptr<T> &t,
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

} // serialization
} // namespace streams_boost

// note: change below uses null_deleter 
// This macro is used to export GUIDS for shared pointers to allow
// the serialization system to export them properly. David Tonge
#define STREAMS_BOOST_SHARED_POINTER_EXPORT_GUID(T, K)                     \
    typedef streams_boost_132::detail::sp_counted_base_impl<               \
        T *,                                                       \
        streams_boost::checked_deleter< T >                                \
    > __shared_ptr_ ## T;                                          \
    STREAMS_BOOST_CLASS_EXPORT_GUID(__shared_ptr_ ## T, "__shared_ptr_" K) \
    STREAMS_BOOST_CLASS_EXPORT_GUID(T, K)                                  \
    /**/

#define STREAMS_BOOST_SHARED_POINTER_EXPORT(T)                             \
    STREAMS_BOOST_SHARED_POINTER_EXPORT_GUID(                              \
        T,                                                         \
        STREAMS_BOOST_PP_STRINGIZE(T)                                      \
    )                                                              \
    /**/

#endif // STREAMS_BOOST_SERIALIZATION_SHARED_PTR_132_HPP
