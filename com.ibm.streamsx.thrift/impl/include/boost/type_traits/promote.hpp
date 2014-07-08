// Copyright 2005 Alexander Nasonov.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef FILE_streams_boost_type_traits_promote_hpp_INCLUDED
#define FILE_streams_boost_type_traits_promote_hpp_INCLUDED

#include <streams_boost/config.hpp>
#include <streams_boost/type_traits/integral_promotion.hpp>
#include <streams_boost/type_traits/floating_point_promotion.hpp>

// Should be the last #include
#include <streams_boost/type_traits/detail/type_trait_def.hpp>

namespace streams_boost {

namespace detail {

template<class T>
struct promote_impl
  : integral_promotion<
        STREAMS_BOOST_DEDUCED_TYPENAME floating_point_promotion<T>::type
      >
{
};

}

STREAMS_BOOST_TT_AUX_TYPE_TRAIT_DEF1(
      promote
    , T
    , STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::detail::promote_impl<T>::type
    )
}

#include <streams_boost/type_traits/detail/type_trait_undef.hpp>

#endif // #ifndef FILE_streams_boost_type_traits_promote_hpp_INCLUDED

