#ifndef STREAMS_BOOST_SERIALIZATION_VERSION_HPP
#define STREAMS_BOOST_SERIALIZATION_VERSION_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// version.hpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/config.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/integral_c_tag.hpp>

#include <streams_boost/type_traits/is_base_and_derived.hpp>
//#include <streams_boost/serialization/traits.hpp>

namespace streams_boost { 
namespace serialization {

struct basic_traits;

// default version number is 0. Override with higher version
// when class definition changes.
template<class T>
struct version
{
    template<class U>
    struct traits_class_version {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME U::version type;
    };

    typedef mpl::integral_c_tag tag;
    // note: at least one compiler complained w/o the full qualification
    // on basic traits below
    typedef
        STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
            is_base_and_derived<streams_boost::serialization::basic_traits,T>,
            traits_class_version<T>,
            mpl::int_<0>
        >::type type;
    STREAMS_BOOST_STATIC_CONSTANT(int, value = version::type::value);
};

} // namespace serialization
} // namespace streams_boost

/* note: at first it seemed that this would be a good place to trap
 * as an error an attempt to set a version # for a class which doesn't
 * save its class information (including version #) in the archive.
 * However, this imposes a requirement that the version be set after
 * the implemention level which would be pretty confusing.  If this
 * is to be done, do this check in the input or output operators when
 * ALL the serialization traits are available.  Included the implementation
 * here with this comment as a reminder not to do this!
 */
//#include <streams_boost/serialization/level.hpp>
//#include <streams_boost/mpl/equal_to.hpp>

// specify the current version number for the class
#define STREAMS_BOOST_CLASS_VERSION(T, N)                                      \
namespace streams_boost {                                                      \
namespace serialization {                                              \
template<>                                                             \
struct version<T >                                                     \
{                                                                      \
    typedef mpl::int_<N> type;                                         \
    typedef mpl::integral_c_tag tag;                                   \
    STREAMS_BOOST_STATIC_CONSTANT(unsigned int, value = version::type::value); \
    /*                                                                 \
    STREAMS_BOOST_STATIC_ASSERT((                                              \
        mpl::equal_to<                                                 \
            :implementation_level<T >,                                 \
            mpl::int_<object_class_info>                               \
        >::value                                                       \
    ));                                                                \
    */                                                                 \
};                                                                     \
}                                                                      \
}

#endif // STREAMS_BOOST_SERIALIZATION_VERSION_HPP
