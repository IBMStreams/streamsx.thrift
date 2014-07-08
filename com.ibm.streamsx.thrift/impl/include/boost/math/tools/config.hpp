//  Copyright (c) 2006-7 John Maddock
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_TOOLS_CONFIG_HPP
#define STREAMS_BOOST_MATH_TOOLS_CONFIG_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/cstdint.hpp> // for streams_boost::uintmax_t
#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <algorithm>  // for min and max
#include <streams_boost/config/no_tr1/cmath.hpp>
#include <climits>
#if (defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__))
#  include <math.h>
#endif

#include <streams_boost/math/tools/user.hpp>
#include <streams_boost/math/special_functions/detail/round_fwd.hpp>

#if defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
   || defined(__hppa) || defined(__NO_LONG_DOUBLE_MATH)
#  define STREAMS_BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x582))
//
// Borland post 5.8.2 uses Dinkumware's std C lib which
// doesn't have true long double precision.  Earlier
// versions are problematic too:
//
#  define STREAMS_BOOST_MATH_NO_REAL_CONCEPT_TESTS
#  define STREAMS_BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#  define STREAMS_BOOST_MATH_CONTROL_FP _control87(MCW_EM,MCW_EM)
#  include <float.h>
#endif
#if (defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)) && ((LDBL_MANT_DIG == 106) || (__LDBL_MANT_DIG__ == 106))
//
// Darwin's rather strange "double double" is rather hard to
// support, it should be possible given enough effort though...
//
#  define STREAMS_BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if defined(unix) && defined(__INTEL_COMPILER) && (__INTEL_COMPILER <= 1000)
//
// Intel compiler prior to version 10 has sporadic problems
// calling the long double overloads of the std lib math functions:
// calling ::powl is OK, but std::pow(long double, long double) 
// may segfault depending upon the value of the arguments passed 
// and the specific Linux distribution.
//
// We'll be conservative and disable long double support for this compiler.
//
// Comment out this #define and try building the tests to determine whether
// your Intel compiler version has this issue or not.
//
#  define STREAMS_BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if defined(unix) && defined(__INTEL_COMPILER)
//
// Intel compiler has sporadic issues compiling std::fpclassify depending on
// the exact OS version used.  Use our own code for this as we know it works
// well on Intel processors:
//
#define STREAMS_BOOST_MATH_DISABLE_STD_FPCLASSIFY
#endif

#if defined(STREAMS_BOOST_MSVC) && !defined(_WIN32_WCE)
   // Better safe than sorry, our tests don't support hardware exceptions:
#  define STREAMS_BOOST_MATH_CONTROL_FP _control87(MCW_EM,MCW_EM)
#endif

#ifdef __IBMCPP__
#  define STREAMS_BOOST_MATH_NO_DEDUCED_FUNCTION_POINTERS
#endif

#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901))
#  define STREAMS_BOOST_MATH_USE_C99
#endif

#if (defined(__hpux) && !defined(__hppa))
#  define STREAMS_BOOST_MATH_USE_C99
#endif

#if defined(__GNUC__) && defined(_GLIBCXX_USE_C99)
#  define STREAMS_BOOST_MATH_USE_C99
#endif

#if defined(__CYGWIN__) || defined(__HP_aCC) || defined(STREAMS_BOOST_INTEL) \
  || defined(STREAMS_BOOST_NO_NATIVE_LONG_DOUBLE_FP_CLASSIFY) \
  || (defined(__GNUC__) && !defined(STREAMS_BOOST_MATH_USE_C99))
#  define STREAMS_BOOST_MATH_NO_NATIVE_LONG_DOUBLE_FP_CLASSIFY
#endif

#if defined(STREAMS_BOOST_NO_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS) || STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, <= 0x590)

#  include "streams_boost/type.hpp"
#  include "streams_boost/non_type.hpp"

#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_TYPE(t)         streams_boost::type<t>* = 0
#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_TYPE_SPEC(t)    streams_boost::type<t>*
#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE(t, v)  streams_boost::non_type<t, v>* = 0
#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)  streams_boost::non_type<t, v>*

#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE(t)         \
             , STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_TYPE(t)
#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE_SPEC(t)    \
             , STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(t, v)  \
             , STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)  \
             , STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)

#else

// no workaround needed: expand to nothing

#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_TYPE(t)
#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define STREAMS_BOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)

#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE(t)
#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define STREAMS_BOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)


#endif // defined STREAMS_BOOST_NO_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS

#if defined(__SUNPRO_CC) || defined(__hppa) || defined(__GNUC__)
// Sun's compiler emits a hard error if a constant underflows,
// as does aCC on PA-RISC, while gcc issues a large number of warnings:
#  define STREAMS_BOOST_MATH_SMALL_CONSTANT(x) 0
#else
#  define STREAMS_BOOST_MATH_SMALL_CONSTANT(x) x
#endif


#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1400)
//
// Define if constants too large for a float cause "bad"
// values to be stored in the data, rather than infinity
// or a suitably large value.
//
#  define STREAMS_BOOST_MATH_BUGGY_LARGE_FLOAT_CONSTANTS
#endif
//
// Tune performance options for specific compilers:
//
#ifdef STREAMS_BOOST_MSVC
#  define STREAMS_BOOST_MATH_POLY_METHOD 3
#elif defined(STREAMS_BOOST_INTEL)
#  define STREAMS_BOOST_MATH_POLY_METHOD 2
#  define STREAMS_BOOST_MATH_RATIONAL_METHOD 2
#elif defined(__GNUC__)
#  define STREAMS_BOOST_MATH_POLY_METHOD 3
#  define STREAMS_BOOST_MATH_RATIONAL_METHOD 3
#  define STREAMS_BOOST_MATH_INT_TABLE_TYPE(RT, IT) RT
#  define STREAMS_BOOST_MATH_INT_VALUE_SUFFIX(RV, SUF) RV##.0L
#endif

#if defined(STREAMS_BOOST_NO_LONG_LONG) && !defined(STREAMS_BOOST_MATH_INT_TABLE_TYPE)
#  define STREAMS_BOOST_MATH_INT_TABLE_TYPE(RT, IT) RT
#  define STREAMS_BOOST_MATH_INT_VALUE_SUFFIX(RV, SUF) RV##.0L
#endif

//
// The maximum order of polynomial that will be evaluated 
// via an unrolled specialisation:
//
#ifndef STREAMS_BOOST_MATH_MAX_POLY_ORDER
#  define STREAMS_BOOST_MATH_MAX_POLY_ORDER 17
#endif 
//
// Set the method used to evaluate polynomials and rationals:
//
#ifndef STREAMS_BOOST_MATH_POLY_METHOD
#  define STREAMS_BOOST_MATH_POLY_METHOD 1
#endif 
#ifndef STREAMS_BOOST_MATH_RATIONAL_METHOD
#  define STREAMS_BOOST_MATH_RATIONAL_METHOD 0
#endif 
//
// decide whether to store constants as integers or reals:
//
#ifndef STREAMS_BOOST_MATH_INT_TABLE_TYPE
#  define STREAMS_BOOST_MATH_INT_TABLE_TYPE(RT, IT) IT
#endif
#ifndef STREAMS_BOOST_MATH_INT_VALUE_SUFFIX
#  define STREAMS_BOOST_MATH_INT_VALUE_SUFFIX(RV, SUF) RV##SUF
#endif

//
// Helper macro for controlling the FP behaviour:
//
#ifndef STREAMS_BOOST_MATH_CONTROL_FP
#  define STREAMS_BOOST_MATH_CONTROL_FP
#endif
//
// Helper macro for using statements:
//
#define STREAMS_BOOST_MATH_STD_USING \
   using std::abs;\
   using std::acos;\
   using std::cos;\
   using std::fmod;\
   using std::modf;\
   using std::tan;\
   using std::asin;\
   using std::cosh;\
   using std::frexp;\
   using std::pow;\
   using std::tanh;\
   using std::atan;\
   using std::exp;\
   using std::ldexp;\
   using std::sin;\
   using std::atan2;\
   using std::fabs;\
   using std::log;\
   using std::sinh;\
   using std::ceil;\
   using std::floor;\
   using std::log10;\
   using std::sqrt;\
   using streams_boost::math::round;\
   using streams_boost::math::iround;\
   using streams_boost::math::lround;\
   using streams_boost::math::trunc;\
   using streams_boost::math::itrunc;\
   using streams_boost::math::ltrunc;\
   using streams_boost::math::modf;


namespace streams_boost{ namespace math{
namespace tools
{

template <class T>
inline T max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T a, T b, T c)
{
   return (std::max)((std::max)(a, b), c);
}

template <class T>
inline T max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T a, T b, T c, T d)
{
   return (std::max)((std::max)(a, b), (std::max)(c, d));
}
} // namespace tools
}} // namespace streams_boost namespace math

#if (defined(__linux__) && !defined(__UCLIBC__)) || defined(__QNX__) || defined(__IBMCPP__)

   #include <fenv.h>

   namespace streams_boost{ namespace math{
   namespace detail
   {
   struct fpu_guard
   {
      fpu_guard()
      {
         fegetexceptflag(&m_flags, FE_ALL_EXCEPT);
         feclearexcept(FE_ALL_EXCEPT);
      }
      ~fpu_guard()
      {
         fesetexceptflag(&m_flags, FE_ALL_EXCEPT);
      }
   private:
      fexcept_t m_flags;
   };

   } // namespace detail
   }} // namespaces

#  define STREAMS_BOOST_FPU_EXCEPTION_GUARD streams_boost::math::detail::fpu_guard local_guard_object;
#  define STREAMS_BOOST_MATH_INSTRUMENT_FPU do{ fexcept_t cpu_flags; fegetexceptflag(&cpu_flags, FE_ALL_EXCEPT); STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(cpu_flags); } while(0); 
#else // All other platforms.
#  define STREAMS_BOOST_FPU_EXCEPTION_GUARD
#  define STREAMS_BOOST_MATH_INSTRUMENT_FPU
#endif

#ifdef STREAMS_BOOST_MATH_INSTRUMENT
#define STREAMS_BOOST_MATH_INSTRUMENT_CODE(x) \
   std::cout << std::setprecision(35) << __FILE__ << ":" << __LINE__ << " " << x << std::endl;
#define STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(name) STREAMS_BOOST_MATH_INSTRUMENT_CODE(STREAMS_BOOST_STRINGIZE(name) << " = " << name)
#else
#define STREAMS_BOOST_MATH_INSTRUMENT_CODE(x)
#define STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(name)
#endif

#endif // STREAMS_BOOST_MATH_TOOLS_CONFIG_HPP





