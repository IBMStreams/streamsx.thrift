// (C) Copyright Thorsten Ottosen 2005
// (C) Copyright Howard Hinnant 2004
// (C) Copyright Jonathan Turkanis 2004
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

//
// Contains type traits machinery for incomplete arrays. MPL compatibility
// is included for completeness, but is not necessary for the current 
// application.
// 

#ifndef STREAMS_BOOST_MOVE_PTR_ARRAYS_HPP_INCLUDED
#define STREAMS_BOOST_MOVE_PTR_ARRAYS_HPP_INCLUDED

#include <streams_boost/config.hpp> // STREAMS_BOOST_STATIC_CONSTANT.
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/type_traits/is_array.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/type_traits/remove_bounds.hpp>
#include <streams_boost/type_traits/remove_cv.hpp>
#include <streams_boost/utility/enable_if.hpp>

namespace streams_boost { namespace ptr_container_detail { namespace move_ptrs {

// From Howard Hinnant.
template<typename T, typename U>
struct is_array_convertible {
    typedef typename remove_bounds<T>::type      t_element; 
    typedef typename remove_bounds<U>::type      u_element; 
    typedef typename remove_cv<t_element>::type  t_base; 
    typedef typename remove_cv<u_element>::type  u_base; 
    typedef typename 
            mpl::and_<
                is_array<T>,
                is_array<U>,
                is_same<t_base, u_base>,
                is_convertible<t_element*, u_element*>
            >::type                                     type;
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = type::value);
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2, is_array_convertible, (T, U))
};

template<typename T, typename U>
struct is_smart_ptr_convertible 
    : mpl::if_<
          is_array<T>,
          is_array_convertible<T, U>,
          is_convertible<T*, U*> 
      >::type
    { };

#ifndef STREAMS_BOOST_NO_SFINAE
    template<typename Src, typename Tgt, typename T = void>
    struct enable_if_convertible 
        : enable_if< 
              is_smart_ptr_convertible<Src, Tgt>,
              T
          >
        { };
#else
    template<typename Src, typename Tgt, class T >
    struct enable_if_convertible : mpl::identity<T> { };
#endif

} } }         // End namespaces ptr_container_detail, move_ptrs, streams_boost.

#endif      // #ifndef STREAMS_BOOST_MOVE_PTR_ARRAYS_HPP_INCLUDED
