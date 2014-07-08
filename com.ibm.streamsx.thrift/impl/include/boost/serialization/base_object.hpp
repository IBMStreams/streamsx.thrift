#ifndef STREAMS_BOOST_SERIALIZATION_BASE_OBJECT_HPP
#define STREAMS_BOOST_SERIALIZATION_BASE_OBJECT_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// base_object.hpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

// if no archive headers have been included this is a no op
// this is to permit STREAMS_BOOST_EXPORT etc to be included in a 
// file declaration header

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/identity.hpp>

#include <streams_boost/type_traits/is_base_and_derived.hpp>
#include <streams_boost/type_traits/is_pointer.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/is_polymorphic.hpp>

#include <streams_boost/static_assert.hpp>
#include <streams_boost/serialization/access.hpp>
#include <streams_boost/serialization/force_include.hpp>
#include <streams_boost/serialization/void_cast_fwd.hpp>

namespace streams_boost {
namespace serialization {

namespace detail
{
    // get the base type for a given derived type
    // preserving the const-ness
    template<class B, class D>
    struct base_cast
    {
        typedef STREAMS_BOOST_DEDUCED_TYPENAME
        mpl::if_<
            is_const<D>,
            const B,
            B
        >::type type;
        STREAMS_BOOST_STATIC_ASSERT(is_const<type>::value == is_const<D>::value);
    };

    // only register void casts if the types are polymorphic
    template<class Base, class Derived>
    struct base_register
    {
        struct polymorphic {
            static void const * invoke(){
                Base const * const b = 0;
                Derived const * const d = 0;
                return & void_cast_register(d, b);
            }
        };
        struct non_polymorphic {
            static void const * invoke(){
                return 0;
            }
        };
        static void const * invoke(){
            typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
                is_polymorphic<Base>,
                mpl::identity<polymorphic>,
                mpl::identity<non_polymorphic>
            >::type type;
            return type::invoke();
        }
    };

} // namespace detail
#if defined(__BORLANDC__) && __BORLANDC__ < 0x610
template<class Base, class Derived>
const Base & 
base_object(const Derived & d)
{
    STREAMS_BOOST_STATIC_ASSERT(! is_pointer<Derived>::value);
    detail::base_register<Base, Derived>::invoke();
    return access::cast_reference<const Base, Derived>(d);
}
#else
template<class Base, class Derived>
STREAMS_BOOST_DEDUCED_TYPENAME detail::base_cast<Base, Derived>::type & 
base_object(Derived &d)
{
    STREAMS_BOOST_STATIC_ASSERT(( is_base_and_derived<Base,Derived>::value));
    STREAMS_BOOST_STATIC_ASSERT(! is_pointer<Derived>::value);
    typedef STREAMS_BOOST_DEDUCED_TYPENAME detail::base_cast<Base, Derived>::type type;
    detail::base_register<type, Derived>::invoke();
    return access::cast_reference<type, Derived>(d);
}
#endif

} // namespace serialization
} // namespace streams_boost

#endif // STREAMS_BOOST_SERIALIZATION_BASE_OBJECT_HPP
