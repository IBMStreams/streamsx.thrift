
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_EXTENT_HPP_INCLUDED
#define STREAMS_BOOST_TT_EXTENT_HPP_INCLUDED

// should be the last #include
#include <streams_boost/type_traits/detail/size_t_trait_def.hpp>

namespace streams_boost {

namespace detail{

#if defined( __CODEGEARC__ )
    // wrap the impl as main trait provides additional MPL lambda support
    template < typename T, std::size_t N >
    struct extent_imp {
        static const std::size_t value = __array_extent(T, N);
    };

#else

template <class T, std::size_t N>
struct extent_imp
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 0);
};
#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(STREAMS_BOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
template <class T, std::size_t R, std::size_t N>
struct extent_imp<T[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};

template <class T, std::size_t R, std::size_t N>
struct extent_imp<T const[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};

template <class T, std::size_t R, std::size_t N>
struct extent_imp<T volatile[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};

template <class T, std::size_t R, std::size_t N>
struct extent_imp<T const volatile[R], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};

template <class T, std::size_t R>
struct extent_imp<T[R],0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = R);
};

template <class T, std::size_t R>
struct extent_imp<T const[R], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = R);
};

template <class T, std::size_t R>
struct extent_imp<T volatile[R], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = R);
};

template <class T, std::size_t R>
struct extent_imp<T const volatile[R], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = R);
};

#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x600) && !defined(__IBMCPP__) &&  !STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840)) && !defined(__MWERKS__)
template <class T, std::size_t N>
struct extent_imp<T[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};
template <class T, std::size_t N>
struct extent_imp<T const[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};
template <class T, std::size_t N>
struct extent_imp<T volatile[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};
template <class T, std::size_t N>
struct extent_imp<T const volatile[], N>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (::streams_boost::detail::extent_imp<T, N-1>::value));
};
template <class T>
struct extent_imp<T[], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 0);
};
template <class T>
struct extent_imp<T const[], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 0);
};
template <class T>
struct extent_imp<T volatile[], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 0);
};
template <class T>
struct extent_imp<T const volatile[], 0>
{
   STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 0);
};
#endif
#endif

#endif  // non-CodeGear implementation
}   // ::streams_boost::detail

template <class T, std::size_t N = 0>
struct extent
   : public ::streams_boost::integral_constant<std::size_t, ::streams_boost::detail::extent_imp<T,N>::value>
{
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) 
   typedef ::streams_boost::integral_constant<std::size_t, ::streams_boost::detail::extent_imp<T,N>::value> base_; 
   using base_::value;
#endif
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,extent,(T))
};

} // namespace streams_boost

#include <streams_boost/type_traits/detail/size_t_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
