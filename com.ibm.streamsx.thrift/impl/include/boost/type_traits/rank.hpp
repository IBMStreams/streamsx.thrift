
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_RANK_HPP_INCLUDED
#define STREAMS_BOOST_TT_RANK_HPP_INCLUDED

// should be the last #include
#include <streams_boost/type_traits/detail/size_t_trait_def.hpp>

namespace streams_boost {

#if !defined( __CODEGEARC__ )

namespace detail{

template <class T, std::size_t N>
struct rank_imp
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = N);
};
#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(STREAMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
template <class T, std::size_t R, std::size_t N>
struct rank_imp<T[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};

template <class T, std::size_t R, std::size_t N>
struct rank_imp<T const[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};

template <class T, std::size_t R, std::size_t N>
struct rank_imp<T volatile[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};

template <class T, std::size_t R, std::size_t N>
struct rank_imp<T const volatile[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) && !defined(__IBMCPP__) &&  !STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))
template <class T, std::size_t N>
struct rank_imp<T[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};
template <class T, std::size_t N>
struct rank_imp<T const[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};
template <class T, std::size_t N>
struct rank_imp<T volatile[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};
template <class T, std::size_t N>
struct rank_imp<T const volatile[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::rank_imp<T, N+1>::value));
};
#endif
#endif
}

#endif // !defined( __CODEGEARC__ )

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_SIZE_T_TRAIT_DEF1(rank,T,__array_rank(T))
#else
STREAMS_BOOST_TT_AUX_SIZE_T_TRAIT_DEF1(rank,T,(::streams_boost::detail::rank_imp<T,0>::value))
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/size_t_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
