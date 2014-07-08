// Copyright John Maddock 2008.
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_TR1_HPP
#define STREAMS_BOOST_MATH_TR1_HPP

#ifdef _MSC_VER
#pragma once
#endif

#ifdef __cplusplus

#include <streams_boost/config.hpp>
#include <streams_boost/static_assert.hpp>

namespace streams_boost{ namespace math{ namespace tr1{ extern "C"{

#endif // __cplusplus

#ifdef STREAMS_BOOST_HAS_DECLSPEC // defined in config system
// we need to import/export our code only if the user has specifically
// asked for it by defining either STREAMS_BOOST_ALL_DYN_LINK if they want all streams_boost
// libraries to be dynamically linked, or STREAMS_BOOST_MATH_TR1_DYN_LINK
// if they want just this one to be dynamically liked:
#if defined(STREAMS_BOOST_ALL_DYN_LINK) || defined(STREAMS_BOOST_MATH_TR1_DYN_LINK)
// export if this is our own source, otherwise import:
#ifdef STREAMS_BOOST_MATH_TR1_SOURCE
# define STREAMS_BOOST_MATH_TR1_DECL __declspec(dllexport)
#else
# define STREAMS_BOOST_MATH_TR1_DECL __declspec(dllimport)
#endif  // STREAMS_BOOST_MATH_TR1_SOURCE
#endif  // DYN_LINK
#endif  // STREAMS_BOOST_HAS_DECLSPEC
//
// if STREAMS_BOOST_MATH_TR1_DECL isn't defined yet define it now:
#ifndef STREAMS_BOOST_MATH_TR1_DECL
#define STREAMS_BOOST_MATH_TR1_DECL
#endif

//
// Now set up the libraries to link against:
//
#if !defined(STREAMS_BOOST_MATH_TR1_NO_LIB) && !defined(STREAMS_BOOST_MATH_TR1_SOURCE) \
   && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus)
#  define STREAMS_BOOST_LIB_NAME streams_boost_math_c99
#  if defined(STREAMS_BOOST_MATH_TR1_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif
#if !defined(STREAMS_BOOST_MATH_TR1_NO_LIB) && !defined(STREAMS_BOOST_MATH_TR1_SOURCE) \
   && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus)
#  define STREAMS_BOOST_LIB_NAME streams_boost_math_c99f
#  if defined(STREAMS_BOOST_MATH_TR1_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif
#if !defined(STREAMS_BOOST_MATH_TR1_NO_LIB) && !defined(STREAMS_BOOST_MATH_TR1_SOURCE) \
   && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus) \
   && !defined(STREAMS_BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
#  define STREAMS_BOOST_LIB_NAME streams_boost_math_c99l
#  if defined(STREAMS_BOOST_MATH_TR1_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif
#if !defined(STREAMS_BOOST_MATH_TR1_NO_LIB) && !defined(STREAMS_BOOST_MATH_TR1_SOURCE) \
   && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus)
#  define STREAMS_BOOST_LIB_NAME streams_boost_math_tr1
#  if defined(STREAMS_BOOST_MATH_TR1_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif
#if !defined(STREAMS_BOOST_MATH_TR1_NO_LIB) && !defined(STREAMS_BOOST_MATH_TR1_SOURCE) \
   && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus)
#  define STREAMS_BOOST_LIB_NAME streams_boost_math_tr1f
#  if defined(STREAMS_BOOST_MATH_TR1_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif
#if !defined(STREAMS_BOOST_MATH_TR1_NO_LIB) && !defined(STREAMS_BOOST_MATH_TR1_SOURCE) \
   && !defined(STREAMS_BOOST_ALL_NO_LIB) && defined(__cplusplus) \
   && !defined(STREAMS_BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
#  define STREAMS_BOOST_LIB_NAME streams_boost_math_tr1l
#  if defined(STREAMS_BOOST_MATH_TR1_DYN_LINK) || defined(STREAMS_BOOST_ALL_DYN_LINK)
#     define STREAMS_BOOST_DYN_LINK
#  endif
#  include <streams_boost/config/auto_link.hpp>
#endif

#ifndef FLT_EVAL_METHOD
typedef float float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 0
typedef float float_t;
typedef double double_t;
#elif FLT_EVAL_METHOD == 1
typedef double float_t;
typedef double double_t;
#else
typedef long double float_t;
typedef long double double_t;
#endif

// C99 Functions:
double STREAMS_BOOST_MATH_TR1_DECL acosh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL acoshf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL acoshl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL asinh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL asinhf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL asinhl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL atanh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL atanhf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL atanhl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL cbrt STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL cbrtf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL cbrtl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL copysignf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL copysignl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);

double STREAMS_BOOST_MATH_TR1_DECL erf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL erff STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL erfl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL erfc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL erfcf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL erfcl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#if 0
double STREAMS_BOOST_MATH_TR1_DECL exp2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL exp2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL exp2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
double STREAMS_BOOST_MATH_TR1_DECL streams_boost_expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL streams_boost_expm1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL streams_boost_expm1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#if 0
double STREAMS_BOOST_MATH_TR1_DECL fdim STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL fdimf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL fdiml STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);
double STREAMS_BOOST_MATH_TR1_DECL fma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y, double z);
float STREAMS_BOOST_MATH_TR1_DECL fmaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y, float z);
long double STREAMS_BOOST_MATH_TR1_DECL fmal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y, long double z);
#endif
double STREAMS_BOOST_MATH_TR1_DECL fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL fmaxf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL fmaxl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);

double STREAMS_BOOST_MATH_TR1_DECL fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL fminf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL fminl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);

double STREAMS_BOOST_MATH_TR1_DECL hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL hypotf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL hypotl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);
#if 0
int STREAMS_BOOST_MATH_TR1_DECL ilogb STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
int STREAMS_BOOST_MATH_TR1_DECL ilogbf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
int STREAMS_BOOST_MATH_TR1_DECL ilogbl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
double STREAMS_BOOST_MATH_TR1_DECL lgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL lgammaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL lgammal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#ifdef STREAMS_BOOST_HAS_LONG_LONG
#if 0
::streams_boost::long_long_type STREAMS_BOOST_MATH_TR1_DECL llrint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
::streams_boost::long_long_type STREAMS_BOOST_MATH_TR1_DECL llrintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
::streams_boost::long_long_type STREAMS_BOOST_MATH_TR1_DECL llrintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
::streams_boost::long_long_type STREAMS_BOOST_MATH_TR1_DECL llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
::streams_boost::long_long_type STREAMS_BOOST_MATH_TR1_DECL llroundf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
::streams_boost::long_long_type STREAMS_BOOST_MATH_TR1_DECL llroundl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
double STREAMS_BOOST_MATH_TR1_DECL streams_boost_log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL streams_boost_log1pf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL streams_boost_log1pl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#if 0
double STREAMS_BOOST_MATH_TR1_DECL log2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL log2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL log2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL logb STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL logbf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL logbl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
long STREAMS_BOOST_MATH_TR1_DECL lrint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
long STREAMS_BOOST_MATH_TR1_DECL lrintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long STREAMS_BOOST_MATH_TR1_DECL lrintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
long STREAMS_BOOST_MATH_TR1_DECL lround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
long STREAMS_BOOST_MATH_TR1_DECL lroundf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long STREAMS_BOOST_MATH_TR1_DECL lroundl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#if 0
double STREAMS_BOOST_MATH_TR1_DECL nan STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(const char *str);
float STREAMS_BOOST_MATH_TR1_DECL nanf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(const char *str);
long double STREAMS_BOOST_MATH_TR1_DECL nanl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(const char *str);
double STREAMS_BOOST_MATH_TR1_DECL nearbyint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL nearbyintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL nearbyintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
double STREAMS_BOOST_MATH_TR1_DECL streams_boost_nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL streams_boost_nextafterf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL streams_boost_nextafterl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);

double STREAMS_BOOST_MATH_TR1_DECL nexttoward STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, long double y);
float STREAMS_BOOST_MATH_TR1_DECL nexttowardf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, long double y);
long double STREAMS_BOOST_MATH_TR1_DECL nexttowardl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);
#if 0
double STREAMS_BOOST_MATH_TR1_DECL remainder STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL remainderf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL remainderl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);
double STREAMS_BOOST_MATH_TR1_DECL remquo STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y, int *pquo);
float STREAMS_BOOST_MATH_TR1_DECL remquof STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y, int *pquo);
long double STREAMS_BOOST_MATH_TR1_DECL remquol STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y, int *pquo);
double STREAMS_BOOST_MATH_TR1_DECL rint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL rintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL rintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
double STREAMS_BOOST_MATH_TR1_DECL round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL roundf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL roundl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#if 0
double STREAMS_BOOST_MATH_TR1_DECL scalbln STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, long ex);
float STREAMS_BOOST_MATH_TR1_DECL scalblnf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, long ex);
long double STREAMS_BOOST_MATH_TR1_DECL scalblnl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long ex);
double STREAMS_BOOST_MATH_TR1_DECL scalbn STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, int ex);
float STREAMS_BOOST_MATH_TR1_DECL scalbnf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, int ex);
long double STREAMS_BOOST_MATH_TR1_DECL scalbnl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, int ex);
#endif
double STREAMS_BOOST_MATH_TR1_DECL tgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL tgammaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL tgammal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double STREAMS_BOOST_MATH_TR1_DECL trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL truncf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL truncl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

// [5.2.1.1] associated Laguerre polynomials:
double STREAMS_BOOST_MATH_TR1_DECL assoc_laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, unsigned m, double x);
float STREAMS_BOOST_MATH_TR1_DECL assoc_laguerref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, unsigned m, float x);
long double STREAMS_BOOST_MATH_TR1_DECL assoc_laguerrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, unsigned m, long double x);

// [5.2.1.2] associated Legendre functions:
double STREAMS_BOOST_MATH_TR1_DECL assoc_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, double x);
float STREAMS_BOOST_MATH_TR1_DECL assoc_legendref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, float x);
long double STREAMS_BOOST_MATH_TR1_DECL assoc_legendrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, long double x);

// [5.2.1.3] beta function:
double STREAMS_BOOST_MATH_TR1_DECL beta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float STREAMS_BOOST_MATH_TR1_DECL betaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double STREAMS_BOOST_MATH_TR1_DECL betal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);

// [5.2.1.4] (complete) elliptic integral of the first kind:
double STREAMS_BOOST_MATH_TR1_DECL comp_ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double k);
float STREAMS_BOOST_MATH_TR1_DECL comp_ellint_1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k);
long double STREAMS_BOOST_MATH_TR1_DECL comp_ellint_1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k);

// [5.2.1.5] (complete) elliptic integral of the second kind:
double STREAMS_BOOST_MATH_TR1_DECL comp_ellint_2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double k);
float STREAMS_BOOST_MATH_TR1_DECL comp_ellint_2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k);
long double STREAMS_BOOST_MATH_TR1_DECL comp_ellint_2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k);

// [5.2.1.6] (complete) elliptic integral of the third kind:
double STREAMS_BOOST_MATH_TR1_DECL comp_ellint_3 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double k, double nu);
float STREAMS_BOOST_MATH_TR1_DECL comp_ellint_3f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float nu);
long double STREAMS_BOOST_MATH_TR1_DECL comp_ellint_3l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double nu);
#if 0
// [5.2.1.7] confluent hypergeometric functions:
double STREAMS_BOOST_MATH_TR1_DECL conf_hyperg STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double a, double c, double x);
float STREAMS_BOOST_MATH_TR1_DECL conf_hypergf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float a, float c, float x);
long double STREAMS_BOOST_MATH_TR1_DECL conf_hypergl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double a, long double c, long double x);
#endif
// [5.2.1.8] regular modified cylindrical Bessel functions:
double STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_i STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double nu, double x);
float STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_if STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x);
long double STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_il STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x);

// [5.2.1.9] cylindrical Bessel functions (of the first kind):
double STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_j STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double nu, double x);
float STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_jf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x);
long double STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_jl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x);

// [5.2.1.10] irregular modified cylindrical Bessel functions:
double STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_k STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double nu, double x);
float STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_kf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x);
long double STREAMS_BOOST_MATH_TR1_DECL cyl_bessel_kl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x);

// [5.2.1.11] cylindrical Neumann functions;
// cylindrical Bessel functions (of the second kind):
double STREAMS_BOOST_MATH_TR1_DECL cyl_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double nu, double x);
float STREAMS_BOOST_MATH_TR1_DECL cyl_neumannf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x);
long double STREAMS_BOOST_MATH_TR1_DECL cyl_neumannl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x);

// [5.2.1.12] (incomplete) elliptic integral of the first kind:
double STREAMS_BOOST_MATH_TR1_DECL ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double k, double phi);
float STREAMS_BOOST_MATH_TR1_DECL ellint_1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float phi);
long double STREAMS_BOOST_MATH_TR1_DECL ellint_1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double phi);

// [5.2.1.13] (incomplete) elliptic integral of the second kind:
double STREAMS_BOOST_MATH_TR1_DECL ellint_2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double k, double phi);
float STREAMS_BOOST_MATH_TR1_DECL ellint_2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float phi);
long double STREAMS_BOOST_MATH_TR1_DECL ellint_2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double phi);

// [5.2.1.14] (incomplete) elliptic integral of the third kind:
double STREAMS_BOOST_MATH_TR1_DECL ellint_3 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double k, double nu, double phi);
float STREAMS_BOOST_MATH_TR1_DECL ellint_3f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float nu, float phi);
long double STREAMS_BOOST_MATH_TR1_DECL ellint_3l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double nu, long double phi);

// [5.2.1.15] exponential integral:
double STREAMS_BOOST_MATH_TR1_DECL expint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float STREAMS_BOOST_MATH_TR1_DECL expintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double STREAMS_BOOST_MATH_TR1_DECL expintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

// [5.2.1.16] Hermite polynomials:
double STREAMS_BOOST_MATH_TR1_DECL hermite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, double x);
float STREAMS_BOOST_MATH_TR1_DECL hermitef STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x);
long double STREAMS_BOOST_MATH_TR1_DECL hermitel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x);

#if 0
// [5.2.1.17] hypergeometric functions:
double STREAMS_BOOST_MATH_TR1_DECL hyperg STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double a, double b, double c, double x);
float STREAMS_BOOST_MATH_TR1_DECL hypergf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float a, float b, float c, float x);
long double STREAMS_BOOST_MATH_TR1_DECL hypergl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double a, long double b, long double c,
long double x);
#endif

// [5.2.1.18] Laguerre polynomials:
double STREAMS_BOOST_MATH_TR1_DECL laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, double x);
float STREAMS_BOOST_MATH_TR1_DECL laguerref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x);
long double STREAMS_BOOST_MATH_TR1_DECL laguerrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x);

// [5.2.1.19] Legendre polynomials:
double STREAMS_BOOST_MATH_TR1_DECL legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, double x);
float STREAMS_BOOST_MATH_TR1_DECL legendref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, float x);
long double STREAMS_BOOST_MATH_TR1_DECL legendrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, long double x);

// [5.2.1.20] Riemann zeta function:
double STREAMS_BOOST_MATH_TR1_DECL riemann_zeta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double);
float STREAMS_BOOST_MATH_TR1_DECL riemann_zetaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float);
long double STREAMS_BOOST_MATH_TR1_DECL riemann_zetal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double);

// [5.2.1.21] spherical Bessel functions (of the first kind):
double STREAMS_BOOST_MATH_TR1_DECL sph_bessel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, double x);
float STREAMS_BOOST_MATH_TR1_DECL sph_besself STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x);
long double STREAMS_BOOST_MATH_TR1_DECL sph_bessell STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x);

// [5.2.1.22] spherical associated Legendre functions:
double STREAMS_BOOST_MATH_TR1_DECL sph_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, double theta);
float STREAMS_BOOST_MATH_TR1_DECL sph_legendref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, float theta);
long double STREAMS_BOOST_MATH_TR1_DECL sph_legendrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, long double theta);

// [5.2.1.23] spherical Neumann functions;
// spherical Bessel functions (of the second kind):
double STREAMS_BOOST_MATH_TR1_DECL sph_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, double x);
float STREAMS_BOOST_MATH_TR1_DECL sph_neumannf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x);
long double STREAMS_BOOST_MATH_TR1_DECL sph_neumannl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x);

#ifdef __cplusplus

}}}}  // namespaces

#include <streams_boost/math/tools/promotion.hpp>

namespace streams_boost{ namespace math{ namespace tr1{
//
// Declare overload of the functions which forward to the
// C interfaces:
//
// C99 Functions:
inline float acosh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::acoshf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double acosh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::acoshl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type acosh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::acosh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

inline float asinh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x){ return streams_boost::math::tr1::asinhf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double asinh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x){ return streams_boost::math::tr1::asinhl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type asinh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::asinh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

inline float atanh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x){ return streams_boost::math::tr1::atanhf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double atanh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x){ return streams_boost::math::tr1::atanhl(x); }
template <class T>
inline typename tools::promote_args<T>::type atanh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::atanh STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

inline float cbrt STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::cbrtf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double cbrt STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::cbrtl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type cbrt STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::cbrt STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

inline float copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::copysignf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::copysignl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 x, T2 y)
{ return streams_boost::math::tr1::copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<typename tools::promote_args<T1, T2>::type>(y)); }

inline float erf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::erff STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double erf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::erfl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type erf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::erf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

inline float erfc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::erfcf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double erfc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::erfcl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type erfc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::erfc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }
#if 0
double exp2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float exp2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double exp2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
inline float expm1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::streams_boost_expm1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline double expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x)
{ return streams_boost::math::tr1::streams_boost_expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double expm1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::streams_boost_expm1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline float expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::expm1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::expm1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::expm1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }
#if 0
double fdim STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float fdimf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double fdiml STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);
double fma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y, double z);
float fmaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y, float z);
long double fmal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y, long double z);
#endif
inline float fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::fmaxf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::fmaxl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 x, T2 y)
{ return streams_boost::math::tr1::fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<typename tools::promote_args<T1, T2>::type>(y)); }

inline float fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::fminf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::fminl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 x, T2 y)
{ return streams_boost::math::tr1::fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<typename tools::promote_args<T1, T2>::type>(y)); }

inline float hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::hypotf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::hypotl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 x, T2 y)
{ return streams_boost::math::tr1::hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<typename tools::promote_args<T1, T2>::type>(y)); }
#if 0
int ilogb STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
int ilogbf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
int ilogbl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
inline float lgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::lgammaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double lgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::lgammal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type lgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::lgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }
#ifdef STREAMS_BOOST_HAS_LONG_LONG
#if 0
::streams_boost::long_long_type llrint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
::streams_boost::long_long_type llrintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
::streams_boost::long_long_type llrintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
inline ::streams_boost::long_long_type llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::llroundf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline ::streams_boost::long_long_type llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::llroundl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline ::streams_boost::long_long_type llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<double>(x)); }
#endif
inline float log1pf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::streams_boost_log1pf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline double log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x)
{ return streams_boost::math::tr1::streams_boost_log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double log1pl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::streams_boost_log1pl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline float log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::log1pf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::log1pl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::log1p STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }
#if 0
double log2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float log2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double log2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);

double logb STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float logbf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double logbl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
long lrint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
long lrintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long lrintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
inline long lround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::lroundf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long lround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::lroundl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
long lround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::lround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<double>(x)); }
#if 0
double nan STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(const char *str);
float nanf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(const char *str);
long double nanl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(const char *str);
double nearbyint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float nearbyintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double nearbyintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
inline float nextafterf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::streams_boost_nextafterf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline double nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y)
{ return streams_boost::math::tr1::streams_boost_nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double nextafterl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::streams_boost_nextafterl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline float nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::nextafterf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::nextafterl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 x, T2 y)
{ return streams_boost::math::tr1::nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<typename tools::promote_args<T1, T2>::type>(y)); }

inline float nexttoward STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, long double y)
{ return streams_boost::math::tr1::nexttowardf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double nexttoward STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::nexttowardl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type nexttoward STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 x, T2 y)
{ return streams_boost::math::tr1::nexttoward STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<long double>(y)); }
#if 0
double remainder STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y);
float remainderf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y);
long double remainderl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y);
double remquo STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, double y, int *pquo);
float remquof STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y, int *pquo);
long double remquol STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y, int *pquo);
double rint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x);
float rintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x);
long double rintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x);
#endif
inline float round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::roundf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::roundl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }
#if 0
double scalbln STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, long ex);
float scalblnf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, long ex);
long double scalblnl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long ex);
double scalbn STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double x, int ex);
float scalbnf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, int ex);
long double scalbnl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, int ex);
#endif
inline float tgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::tgammaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double tgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::tgammal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type tgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::tgamma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

inline float trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::truncf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::truncl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

# define NO_MACRO_EXPAND /**/
// C99 macros defined as C++ templates
template<class T> bool signbit NO_MACRO_EXPAND(T x)
{ STREAMS_BOOST_STATIC_ASSERT(sizeof(T) == 0); return false; } // must not be instantiated
template<> bool STREAMS_BOOST_MATH_TR1_DECL signbit<float> NO_MACRO_EXPAND(float x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL signbit<double> NO_MACRO_EXPAND(double x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL signbit<long double> NO_MACRO_EXPAND(long double x);

template<class T> int fpclassify NO_MACRO_EXPAND(T x)
{ STREAMS_BOOST_STATIC_ASSERT(sizeof(T) == 0); return false; } // must not be instantiated
template<> int STREAMS_BOOST_MATH_TR1_DECL fpclassify<float> NO_MACRO_EXPAND(float x);
template<> int STREAMS_BOOST_MATH_TR1_DECL fpclassify<double> NO_MACRO_EXPAND(double x);
template<> int STREAMS_BOOST_MATH_TR1_DECL fpclassify<long double> NO_MACRO_EXPAND(long double x);

template<class T> bool isfinite NO_MACRO_EXPAND(T x)
{ STREAMS_BOOST_STATIC_ASSERT(sizeof(T) == 0); return false; } // must not be instantiated
template<> bool STREAMS_BOOST_MATH_TR1_DECL isfinite<float> NO_MACRO_EXPAND(float x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isfinite<double> NO_MACRO_EXPAND(double x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isfinite<long double> NO_MACRO_EXPAND(long double x);

template<class T> bool isinf NO_MACRO_EXPAND(T x)
{ STREAMS_BOOST_STATIC_ASSERT(sizeof(T) == 0); return false; } // must not be instantiated
template<> bool STREAMS_BOOST_MATH_TR1_DECL isinf<float> NO_MACRO_EXPAND(float x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isinf<double> NO_MACRO_EXPAND(double x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isinf<long double> NO_MACRO_EXPAND(long double x);

template<class T> bool isnan NO_MACRO_EXPAND(T x)
{ STREAMS_BOOST_STATIC_ASSERT(sizeof(T) == 0); return false; } // must not be instantiated
template<> bool STREAMS_BOOST_MATH_TR1_DECL isnan<float> NO_MACRO_EXPAND(float x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isnan<double> NO_MACRO_EXPAND(double x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isnan<long double> NO_MACRO_EXPAND(long double x);

template<class T> bool isnormal NO_MACRO_EXPAND(T x)
{ STREAMS_BOOST_STATIC_ASSERT(sizeof(T) == 0); return false; } // must not be instantiated
template<> bool STREAMS_BOOST_MATH_TR1_DECL isnormal<float> NO_MACRO_EXPAND(float x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isnormal<double> NO_MACRO_EXPAND(double x);
template<> bool STREAMS_BOOST_MATH_TR1_DECL isnormal<long double> NO_MACRO_EXPAND(long double x);

#undef NO_MACRO_EXPAND   
   
// [5.2.1.1] associated Laguerre polynomials:
inline float assoc_laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, unsigned m, float x)
{ return streams_boost::math::tr1::assoc_laguerref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, m, x); }
inline long double assoc_laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, unsigned m, long double x)
{ return streams_boost::math::tr1::assoc_laguerrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, m, x); }
template <class T> 
inline typename tools::promote_args<T>::type assoc_laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, unsigned m, T x)
{ return streams_boost::math::tr1::assoc_laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, m, static_cast<typename tools::promote_args<T>::type>(x)); }

// [5.2.1.2] associated Legendre functions:
inline float assoc_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, float x)
{ return streams_boost::math::tr1::assoc_legendref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, m, x); }
inline long double assoc_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, long double x)
{ return streams_boost::math::tr1::assoc_legendrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, m, x); }
template <class T>
inline typename tools::promote_args<T>::type assoc_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, T x)
{ return streams_boost::math::tr1::assoc_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, m, static_cast<typename tools::promote_args<T>::type>(x)); }

// [5.2.1.3] beta function:
inline float beta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x, float y)
{ return streams_boost::math::tr1::betaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
inline long double beta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x, long double y)
{ return streams_boost::math::tr1::betal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x, y); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type beta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T2 x, T1 y)
{ return streams_boost::math::tr1::beta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(x), static_cast<typename tools::promote_args<T1, T2>::type>(y)); }

// [5.2.1.4] (complete) elliptic integral of the first kind:
inline float comp_ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k)
{ return streams_boost::math::tr1::comp_ellint_1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k); }
inline long double comp_ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k)
{ return streams_boost::math::tr1::comp_ellint_1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k); }
template <class T>
inline typename tools::promote_args<T>::type comp_ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T k)
{ return streams_boost::math::tr1::comp_ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(k)); }

// [5.2.1.5]  STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(complete) elliptic integral of the second kind:
inline float comp_ellint_2(float k)
{ return streams_boost::math::tr1::comp_ellint_2f(k); }
inline long double comp_ellint_2(long double k)
{ return streams_boost::math::tr1::comp_ellint_2l(k); }
template <class T>
inline typename tools::promote_args<T>::type comp_ellint_2(T k)
{ return streams_boost::math::tr1::comp_ellint_2(static_cast<typename tools::promote_args<T>::type> STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k)); }

// [5.2.1.6]  STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(complete) elliptic integral of the third kind:
inline float comp_ellint_3(float k, float nu)
{ return streams_boost::math::tr1::comp_ellint_3f(k, nu); }
inline long double comp_ellint_3(long double k, long double nu)
{ return streams_boost::math::tr1::comp_ellint_3l(k, nu); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type comp_ellint_3(T1 k, T2 nu)
{ return streams_boost::math::tr1::comp_ellint_3(static_cast<typename tools::promote_args<T1, T2>::type> STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k), static_cast<typename tools::promote_args<T1, T2>::type> STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu)); }

#if 0
// [5.2.1.7] confluent hypergeometric functions:
double conf_hyperg STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double a, double c, double x);
float conf_hypergf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float a, float c, float x);
long double conf_hypergl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double a, long double c, long double x);
#endif

// [5.2.1.8] regular modified cylindrical Bessel functions:
inline float cyl_bessel_i STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x)
{ return streams_boost::math::tr1::cyl_bessel_if STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
inline long double cyl_bessel_i STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x)
{ return streams_boost::math::tr1::cyl_bessel_il STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type cyl_bessel_i STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 nu, T2 x)
{ return streams_boost::math::tr1::cyl_bessel_i STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(nu), static_cast<typename tools::promote_args<T1, T2>::type>(x)); }

// [5.2.1.9] cylindrical Bessel functions (of the first kind):
inline float cyl_bessel_j STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x)
{ return streams_boost::math::tr1::cyl_bessel_jf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
inline long double cyl_bessel_j STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x)
{ return streams_boost::math::tr1::cyl_bessel_jl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type cyl_bessel_j STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 nu, T2 x)
{ return streams_boost::math::tr1::cyl_bessel_j STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(nu), static_cast<typename tools::promote_args<T1, T2>::type>(x)); }

// [5.2.1.10] irregular modified cylindrical Bessel functions:
inline float cyl_bessel_k STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x)
{ return streams_boost::math::tr1::cyl_bessel_kf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
inline long double cyl_bessel_k STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x)
{ return streams_boost::math::tr1::cyl_bessel_kl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type cyl_bessel_k STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 nu, T2 x)
{ return streams_boost::math::tr1::cyl_bessel_k STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type> STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu), static_cast<typename tools::promote_args<T1, T2>::type>(x)); }

// [5.2.1.11] cylindrical Neumann functions;
// cylindrical Bessel functions (of the second kind):
inline float cyl_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float nu, float x)
{ return streams_boost::math::tr1::cyl_neumannf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
inline long double cyl_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double nu, long double x)
{ return streams_boost::math::tr1::cyl_neumannl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type cyl_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 nu, T2 x)
{ return streams_boost::math::tr1::cyl_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(nu), static_cast<typename tools::promote_args<T1, T2>::type>(x)); }

// [5.2.1.12] (incomplete) elliptic integral of the first kind:
inline float ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float phi)
{ return streams_boost::math::tr1::ellint_1f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k, phi); }
inline long double ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double phi)
{ return streams_boost::math::tr1::ellint_1l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k, phi); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 k, T2 phi)
{ return streams_boost::math::tr1::ellint_1 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(k), static_cast<typename tools::promote_args<T1, T2>::type>(phi)); }

// [5.2.1.13] (incomplete) elliptic integral of the second kind:
inline float ellint_2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float phi)
{ return streams_boost::math::tr1::ellint_2f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k, phi); }
inline long double ellint_2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double phi)
{ return streams_boost::math::tr1::ellint_2l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k, phi); }
template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type ellint_2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 k, T2 phi)
{ return streams_boost::math::tr1::ellint_2 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2>::type>(k), static_cast<typename tools::promote_args<T1, T2>::type>(phi)); }

// [5.2.1.14] (incomplete) elliptic integral of the third kind:
inline float ellint_3 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float k, float nu, float phi)
{ return streams_boost::math::tr1::ellint_3f STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k, nu, phi); }
inline long double ellint_3 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double k, long double nu, long double phi)
{ return streams_boost::math::tr1::ellint_3l STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(k, nu, phi); }
template <class T1, class T2, class T3>
inline typename tools::promote_args<T1, T2, T3>::type ellint_3 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T1 k, T2 nu, T3 phi)
{ return streams_boost::math::tr1::ellint_3 STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T1, T2, T3>::type>(k), static_cast<typename tools::promote_args<T1, T2, T3>::type>(nu), static_cast<typename tools::promote_args<T1, T2, T3>::type>(phi)); }

// [5.2.1.15] exponential integral:
inline float expint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float x)
{ return streams_boost::math::tr1::expintf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
inline long double expint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double x)
{ return streams_boost::math::tr1::expintl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(x); }
template <class T>
inline typename tools::promote_args<T>::type expint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T x)
{ return streams_boost::math::tr1::expint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(x)); }

// [5.2.1.16] Hermite polynomials:
inline float hermite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x)
{ return streams_boost::math::tr1::hermitef STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
inline long double hermite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x)
{ return streams_boost::math::tr1::hermitel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
template <class T>
inline typename tools::promote_args<T>::type hermite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, T x)
{ return streams_boost::math::tr1::hermite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, static_cast<typename tools::promote_args<T>::type>(x)); }

#if 0
// [5.2.1.17] hypergeometric functions:
double hyperg STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(double a, double b, double c, double x);
float hypergf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float a, float b, float c, float x);
long double hypergl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double a, long double b, long double c,
long double x);
#endif

// [5.2.1.18] Laguerre polynomials:
inline float laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x)
{ return streams_boost::math::tr1::laguerref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
inline long double laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x)
{ return streams_boost::math::tr1::laguerrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
template <class T>
inline typename tools::promote_args<T>::type laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, T x)
{ return streams_boost::math::tr1::laguerre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, static_cast<typename tools::promote_args<T>::type>(x)); }

// [5.2.1.19] Legendre polynomials:
inline float legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, float x)
{ return streams_boost::math::tr1::legendref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, x); }
inline long double legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, long double x)
{ return streams_boost::math::tr1::legendrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, x); }
template <class T>
inline typename tools::promote_args<T>::type legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, T x)
{ return streams_boost::math::tr1::legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, static_cast<typename tools::promote_args<T>::type>(x)); }

// [5.2.1.20] Riemann zeta function:
inline float riemann_zeta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(float z)
{ return streams_boost::math::tr1::riemann_zetaf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(z); }
inline long double riemann_zeta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(long double z)
{ return streams_boost::math::tr1::riemann_zetal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(z); }
template <class T>
inline typename tools::promote_args<T>::type riemann_zeta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T z)
{ return streams_boost::math::tr1::riemann_zeta STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(static_cast<typename tools::promote_args<T>::type>(z)); }

// [5.2.1.21] spherical Bessel functions (of the first kind):
inline float sph_bessel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x)
{ return streams_boost::math::tr1::sph_besself STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
inline long double sph_bessel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x)
{ return streams_boost::math::tr1::sph_bessell STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
template <class T>
inline typename tools::promote_args<T>::type sph_bessel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, T x)
{ return streams_boost::math::tr1::sph_bessel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, static_cast<typename tools::promote_args<T>::type>(x)); }

// [5.2.1.22] spherical associated Legendre functions:
inline float sph_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, float theta)
{ return streams_boost::math::tr1::sph_legendref STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, m, theta); }
inline long double sph_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, long double theta)
{ return streams_boost::math::tr1::sph_legendrel STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, m, theta); }
template <class T>
inline typename tools::promote_args<T>::type sph_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned l, unsigned m, T theta)
{ return streams_boost::math::tr1::sph_legendre STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(l, m, static_cast<typename tools::promote_args<T>::type>(theta)); }

// [5.2.1.23] spherical Neumann functions;
// spherical Bessel functions (of the second kind):
inline float sph_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, float x)
{ return streams_boost::math::tr1::sph_neumannf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
inline long double sph_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, long double x)
{ return streams_boost::math::tr1::sph_neumannl STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, x); }
template <class T>
inline typename tools::promote_args<T>::type sph_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(unsigned n, T x)
{ return streams_boost::math::tr1::sph_neumann STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(n, static_cast<typename tools::promote_args<T>::type>(x)); }

}}} // namespaces

#endif // __cplusplus

#endif // STREAMS_BOOST_MATH_TR1_HPP

