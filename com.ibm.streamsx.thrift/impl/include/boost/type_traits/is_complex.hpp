//  (C) Copyright John Maddock 2007. 
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_COMPLEX_HPP
#define STREAMS_BOOST_TT_IS_COMPLEX_HPP

#include <streams_boost/type_traits/is_convertible.hpp>
#include <complex>
// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>


namespace streams_boost {
namespace detail{

struct is_convertible_from_tester
{
   template <class T>
   is_convertible_from_tester(const std::complex<T>&);
};

}

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_complex,T,(::streams_boost::is_convertible<T, detail::is_convertible_from_tester>::value))

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif //STREAMS_BOOST_TT_IS_COMPLEX_HPP
