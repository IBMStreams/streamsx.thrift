
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

#ifndef STREAMS_BOOST_TT_IS_INTEGRAL_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_INTEGRAL_HPP_INCLUDED

#include <streams_boost/config.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {

//* is a type T an [cv-qualified-] integral type described in the standard (3.9.1p3)
// as an extention we include long long, as this is likely to be added to the
// standard at a later date
#if defined( __CODEGEARC__ )
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_integral,T,__is_integral(T))
#else
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF1(is_integral,T,false)

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned char,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned short,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned int,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned long,true)

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed char,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed short,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed int,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,signed long,true)

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,bool,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,char,true)

#ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
// If the following line fails to compile and you're using the Intel
// compiler, see http://lists.streams_boost.org/MailArchives/streams_boost-users/msg06567.php,
// and define STREAMS_BOOST_NO_INTRINSIC_WCHAR_T on the command line.
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,wchar_t,true)
#endif

// Same set of integral types as in streams_boost/type_traits/integral_promotion.hpp.
// Please, keep in sync. -- Alexander Nasonov
#if (defined(STREAMS_BOOST_MSVC) && (STREAMS_BOOST_MSVC < 1300)) \
    || (defined(STREAMS_BOOST_INTEL_CXX_VERSION) && defined(_MSC_VER) && (STREAMS_BOOST_INTEL_CXX_VERSION <= 600)) \
    || (defined(__BORLANDC__) && (__BORLANDC__ == 0x600) && (_MSC_VER < 1300))
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int8,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int8,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int16,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int16,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int32,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int32,true)
#ifdef __BORLANDC__
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int64,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int64,true)
#endif
#endif

# if defined(STREAMS_BOOST_HAS_LONG_LONG)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral, ::streams_boost::ulong_long_type,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral, ::streams_boost::long_long_type,true)
#elif defined(STREAMS_BOOST_HAS_MS_INT64)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,unsigned __int64,true)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(is_integral,__int64,true)
#endif

#endif  // non-CodeGear implementation

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif // STREAMS_BOOST_TT_IS_INTEGRAL_HPP_INCLUDED
