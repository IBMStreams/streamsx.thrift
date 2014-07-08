//  Copyright John Maddock 2007.

//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

/*
This header defines two traits classes, both in namespace streams_boost::math::tools.

is_distribution<D>::value is true iff D has overloaded "cdf" and
"quantile" functions, plus member typedefs value_type and policy_type.  
It's not much of a definitive test frankly,
but if it looks like a distribution and quacks like a distribution
then it must be a distribution.

is_scaled_distribution<D>::value is true iff D is a distribution
as defined above, and has member functions "scale" and "location".

*/

#ifndef STREAMS_BOOST_STATS_IS_DISTRIBUTION_HPP
#define STREAMS_BOOST_STATS_IS_DISTRIBUTION_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/mpl/has_xxx.hpp>
// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost{ namespace math{ namespace tools{

namespace detail{

STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_value_type, value_type, true)
STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_policy_type, policy_type, true)

template<class D>
char cdf(const D& ...);
template<class D>
char quantile(const D& ...);

template <class D>
struct has_cdf
{
   static D d;
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = sizeof(cdf(d, 0.0f)) != 1);
};

template <class D>
struct has_quantile
{
   static D d;
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = sizeof(quantile(d, 0.0f)) != 1);
};

template <class D>
struct is_distribution_imp
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
      has_quantile<D>::value 
      && has_cdf<D>::value
      && has_value_type<D>::value
      && has_policy_type<D>::value);
};

template <class sig, sig val>
struct result_tag{};

template <class D>
double test_has_location(const volatile result_tag<typename D::value_type (D::*)()const, &D::location>*);
template <class D>
char test_has_location(...);

template <class D>
double test_has_scale(const volatile result_tag<typename D::value_type (D::*)()const, &D::scale>*);
template <class D>
char test_has_scale(...);

template <class D, bool b>
struct is_scaled_distribution_helper
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template <class D>
struct is_scaled_distribution_helper<D, true>
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
      (sizeof(test_has_location<D>(0)) != 1) 
      && 
      (sizeof(test_has_scale<D>(0)) != 1));
};

template <class D>
struct is_scaled_distribution_imp
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = (::streams_boost::math::tools::detail::is_scaled_distribution_helper<D, ::streams_boost::math::tools::detail::is_distribution_imp<D>::value>::value));
};

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_distribution,T,::streams_boost::math::tools::detail::is_distribution_imp<T>::value)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_scaled_distribution,T,::streams_boost::math::tools::detail::is_scaled_distribution_imp<T>::value)

}}}

#endif


