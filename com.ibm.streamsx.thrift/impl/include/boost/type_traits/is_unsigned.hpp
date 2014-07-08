
//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.


#ifndef STREAMS_BOOST_TT_IS_UNSIGNED_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_UNSIGNED_HPP_INCLUDED

#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/type_traits/is_enum.hpp>
#include <streams_boost/type_traits/remove_cv.hpp>
#include <streams_boost/type_traits/detail/ice_or.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

#if !defined( __CODEGEARC__ )

namespace detail{

#if !(defined(__EDG_VERSION__) && __EDG_VERSION__ <= 238)

template <class T>
struct is_unsigned_values
{
   typedef typename remove_cv<T>::type no_cv_t;
   STREAMS_BOOST_STATIC_CONSTANT(no_cv_t, minus_one = (static_cast<no_cv_t>(-1)));
   STREAMS_BOOST_STATIC_CONSTANT(no_cv_t, zero = (static_cast<no_cv_t>(0)));
};

template <class T>
struct is_ununsigned_helper
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = (::streams_boost::detail::is_unsigned_values<T>::minus_one > ::streams_boost::detail::is_unsigned_values<T>::zero));
};

template <bool integral_type>
struct is_ununsigned_select_helper
{
   template <class T>
   struct rebind
   {
      typedef is_ununsigned_helper<T> type;
   };
};

template <>
struct is_ununsigned_select_helper<false>
{
   template <class T>
   struct rebind
   {
      typedef false_type type;
   };
};

template <class T>
struct is_unsigned_imp
{
   typedef is_ununsigned_select_helper< 
      ::streams_boost::type_traits::ice_or<
         ::streams_boost::is_integral<T>::value,
         ::streams_boost::is_enum<T>::value>::value 
   > selector;
   typedef typename selector::template rebind<T> binder;
   typedef typename binder::type type;
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = type::value);
};

#else

template <class T> struct is_unsigned_imp : public false_type{};
template <> struct is_unsigned_imp<unsigned char> : public true_type{};
template <> struct is_unsigned_imp<const unsigned char> : public true_type{};
template <> struct is_unsigned_imp<volatile unsigned char> : public true_type{};
template <> struct is_unsigned_imp<const volatile unsigned char> : public true_type{};
template <> struct is_unsigned_imp<unsigned short> : public true_type{};
template <> struct is_unsigned_imp<const unsigned short> : public true_type{};
template <> struct is_unsigned_imp<volatile unsigned short> : public true_type{};
template <> struct is_unsigned_imp<const volatile unsigned short> : public true_type{};
template <> struct is_unsigned_imp<unsigned int> : public true_type{};
template <> struct is_unsigned_imp<const unsigned int> : public true_type{};
template <> struct is_unsigned_imp<volatile unsigned int> : public true_type{};
template <> struct is_unsigned_imp<const volatile unsigned int> : public true_type{};
template <> struct is_unsigned_imp<unsigned long> : public true_type{};
template <> struct is_unsigned_imp<const unsigned long> : public true_type{};
template <> struct is_unsigned_imp<volatile unsigned long> : public true_type{};
template <> struct is_unsigned_imp<const volatile unsigned long> : public true_type{};
#ifdef STREAMS_BOOST_HAS_LONG_LONG
template <> struct is_unsigned_imp<unsigned long long> : public true_type{};
template <> struct is_unsigned_imp<const unsigned long long> : public true_type{};
template <> struct is_unsigned_imp<volatile unsigned long long> : public true_type{};
template <> struct is_unsigned_imp<const volatile unsigned long long> : public true_type{};
#endif
#if defined(CHAR_MIN) && (CHAR_MIN == 0)
template <> struct is_unsigned_imp<char> : public true_type{};
template <> struct is_unsigned_imp<const char> : public true_type{};
template <> struct is_unsigned_imp<volatile char> : public true_type{};
template <> struct is_unsigned_imp<const volatile char> : public true_type{};
#endif
#if defined(WCHAR_MIN) && (WCHAR_MIN == 0)
template <> struct is_unsigned_imp<wchar_t> : public true_type{};
template <> struct is_unsigned_imp<const wchar_t> : public true_type{};
template <> struct is_unsigned_imp<volatile wchar_t> : public true_type{};
template <> struct is_unsigned_imp<const volatile wchar_t> : public true_type{};
#endif

#endif

}

#endif // !defined( __CODEGEARC__ )

#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_unsigned,T,__is_unsigned(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_unsigned,T,::streams_boost::detail::is_unsigned_imp<T>::value)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
