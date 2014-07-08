#ifndef STREAMS_BOOST_SERIALIZATION_WRAPPER_HPP
#define STREAMS_BOOST_SERIALIZATION_WRAPPER_HPP

// (C) Copyright 2005-2006 Matthias Troyer
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/serialization/traits.hpp>
#include <streams_boost/type_traits/is_base_and_derived.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace serialization {

/// the base class for serialization wrappers
///
/// wrappers need to be treated differently at various places in the serialization library,
/// e.g. saving of non-const wrappers has to be possible. Since partial specialization
// is not supported by all compilers, we derive all wrappers from wrapper_traits. 

template<
    class T, 
    int Level = object_serializable, 
    int Tracking = track_never,
    unsigned int Version = 0,
    class ETII = extended_type_info_impl< T >
>
struct wrapper_traits : 
    public traits<T,Level,Tracking,Version,ETII,mpl::true_> 
{};

template<class T>
struct is_wrapper_impl :
    streams_boost::mpl::eval_if<
      streams_boost::is_base_and_derived<basic_traits,T>,
      streams_boost::mpl::true_,
      streams_boost::mpl::false_
    >::type
{};

template<class T>
struct is_wrapper {
    typedef STREAMS_BOOST_DEDUCED_TYPENAME is_wrapper_impl<const T>::type type;
};

} // serialization
} // streams_boost

// A macro to define that a class is a wrapper
#define STREAMS_BOOST_CLASS_IS_WRAPPER(T)                       \
namespace streams_boost {                                       \
namespace serialization {                               \
template<>                                              \
struct is_wrapper_impl<const T> : streams_boost::mpl::true_ {}; \
}                                                       \
}                                                       \
/**/

#endif //STREAMS_BOOST_SERIALIZATION_WRAPPER_HPP
