//  (C) Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_CMATH_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_CMATH_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_CMATH

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(cmath)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_HEADER(cmath)
#  endif

#else

#include <streams_boost/math/tr1.hpp>

namespace std{ namespace tr1{

using streams_boost::math::tr1::assoc_laguerre;
using streams_boost::math::tr1::assoc_laguerref;
using streams_boost::math::tr1::assoc_laguerrel;
// [5.2.1.2] associated Legendre functions:
using streams_boost::math::tr1::assoc_legendre;
using streams_boost::math::tr1::assoc_legendref;
using streams_boost::math::tr1::assoc_legendrel;
// [5.2.1.3] beta function:
using streams_boost::math::tr1::beta;
using streams_boost::math::tr1::betaf;
using streams_boost::math::tr1::betal;
// [5.2.1.4] (complete) elliptic integral of the first kind:
using streams_boost::math::tr1::comp_ellint_1;
using streams_boost::math::tr1::comp_ellint_1f;
using streams_boost::math::tr1::comp_ellint_1l;
// [5.2.1.5] (complete) elliptic integral of the second kind:
using streams_boost::math::tr1::comp_ellint_2;
using streams_boost::math::tr1::comp_ellint_2f;
using streams_boost::math::tr1::comp_ellint_2l;
// [5.2.1.6] (complete) elliptic integral of the third kind:
using streams_boost::math::tr1::comp_ellint_3;
using streams_boost::math::tr1::comp_ellint_3f;
using streams_boost::math::tr1::comp_ellint_3l;
#if 0
// [5.2.1.7] confluent hypergeometric functions:
using streams_boost::math::tr1::conf_hyperg;
using streams_boost::math::tr1::conf_hypergf;
using streams_boost::math::tr1::conf_hypergl;
#endif
// [5.2.1.8] regular modified cylindrical Bessel functions:
using streams_boost::math::tr1::cyl_bessel_i;
using streams_boost::math::tr1::cyl_bessel_if;
using streams_boost::math::tr1::cyl_bessel_il;
// [5.2.1.9] cylindrical Bessel functions (of the first kind):
using streams_boost::math::tr1::cyl_bessel_j;
using streams_boost::math::tr1::cyl_bessel_jf;
using streams_boost::math::tr1::cyl_bessel_jl;
// [5.2.1.10] irregular modified cylindrical Bessel functions:
using streams_boost::math::tr1::cyl_bessel_k;
using streams_boost::math::tr1::cyl_bessel_kf;
using streams_boost::math::tr1::cyl_bessel_kl;
// [5.2.1.11] cylindrical Neumann functions;
// cylindrical Bessel functions (of the second kind):
using streams_boost::math::tr1::cyl_neumann;
using streams_boost::math::tr1::cyl_neumannf;
using streams_boost::math::tr1::cyl_neumannl;
// [5.2.1.12] (incomplete) elliptic integral of the first kind:
using streams_boost::math::tr1::ellint_1;
using streams_boost::math::tr1::ellint_1f;
using streams_boost::math::tr1::ellint_1l;
// [5.2.1.13] (incomplete) elliptic integral of the second kind:
using streams_boost::math::tr1::ellint_2;
using streams_boost::math::tr1::ellint_2f;
using streams_boost::math::tr1::ellint_2l;
// [5.2.1.14] (incomplete) elliptic integral of the third kind:
using streams_boost::math::tr1::ellint_3;
using streams_boost::math::tr1::ellint_3f;
using streams_boost::math::tr1::ellint_3l;
// [5.2.1.15] exponential integral:
using streams_boost::math::tr1::expint;
using streams_boost::math::tr1::expintf;
using streams_boost::math::tr1::expintl;
// [5.2.1.16] Hermite polynomials:
using streams_boost::math::tr1::hermite;
using streams_boost::math::tr1::hermitef;
using streams_boost::math::tr1::hermitel;
#if 0
// [5.2.1.17] hypergeometric functions:
using streams_boost::math::tr1::hyperg;
using streams_boost::math::tr1::hypergf;
using streams_boost::math::tr1::hypergl;
#endif
// [5.2.1.18] Laguerre polynomials:
using streams_boost::math::tr1::laguerre;
using streams_boost::math::tr1::laguerref;
using streams_boost::math::tr1::laguerrel;
// [5.2.1.19] Legendre polynomials:
using streams_boost::math::tr1::legendre;
using streams_boost::math::tr1::legendref;
using streams_boost::math::tr1::legendrel;
// [5.2.1.20] Riemann zeta function:
using streams_boost::math::tr1::riemann_zeta;
using streams_boost::math::tr1::riemann_zetaf;
using streams_boost::math::tr1::riemann_zetal;
// [5.2.1.21] spherical Bessel functions (of the first kind):
using streams_boost::math::tr1::sph_bessel;
using streams_boost::math::tr1::sph_besself;
using streams_boost::math::tr1::sph_bessell;
// [5.2.1.22] spherical associated Legendre functions:
using streams_boost::math::tr1::sph_legendre;
using streams_boost::math::tr1::sph_legendref;
using streams_boost::math::tr1::sph_legendrel;
// [5.2.1.23] spherical Neumann functions;
// spherical Bessel functions (of the second kind):
using streams_boost::math::tr1::sph_neumann;
using streams_boost::math::tr1::sph_neumannf;
using streams_boost::math::tr1::sph_neumannl;

// types
using streams_boost::math::tr1::double_t;
using streams_boost::math::tr1::float_t;
// functions
using streams_boost::math::tr1::acosh;
using streams_boost::math::tr1::acoshf;
using streams_boost::math::tr1::acoshl;
using streams_boost::math::tr1::asinh;
using streams_boost::math::tr1::asinhf;
using streams_boost::math::tr1::asinhl;
using streams_boost::math::tr1::atanh;
using streams_boost::math::tr1::atanhf;
using streams_boost::math::tr1::atanhl;
using streams_boost::math::tr1::cbrt;
using streams_boost::math::tr1::cbrtf;
using streams_boost::math::tr1::cbrtl;
using streams_boost::math::tr1::copysign;
using streams_boost::math::tr1::copysignf;
using streams_boost::math::tr1::copysignl;
using streams_boost::math::tr1::erf;
using streams_boost::math::tr1::erff;
using streams_boost::math::tr1::erfl;
using streams_boost::math::tr1::erfc;
using streams_boost::math::tr1::erfcf;
using streams_boost::math::tr1::erfcl;
#if 0
using streams_boost::math::tr1::exp2;
using streams_boost::math::tr1::exp2f;
using streams_boost::math::tr1::exp2l;
#endif
using streams_boost::math::tr1::expm1;
using streams_boost::math::tr1::expm1f;
using streams_boost::math::tr1::expm1l;
#if 0
using streams_boost::math::tr1::fdim;
using streams_boost::math::tr1::fdimf;
using streams_boost::math::tr1::fdiml;
using streams_boost::math::tr1::fma;
using streams_boost::math::tr1::fmaf;
using streams_boost::math::tr1::fmal;
#endif
using streams_boost::math::tr1::fmax;
using streams_boost::math::tr1::fmaxf;
using streams_boost::math::tr1::fmaxl;
using streams_boost::math::tr1::fmin;
using streams_boost::math::tr1::fminf;
using streams_boost::math::tr1::fminl;
using streams_boost::math::tr1::hypot;
using streams_boost::math::tr1::hypotf;
using streams_boost::math::tr1::hypotl;
#if 0
using streams_boost::math::tr1::ilogb;
using streams_boost::math::tr1::ilogbf;
using streams_boost::math::tr1::ilogbl;
#endif
using streams_boost::math::tr1::lgamma;
using streams_boost::math::tr1::lgammaf;
using streams_boost::math::tr1::lgammal;
#if 0
using streams_boost::math::tr1::llrint;
using streams_boost::math::tr1::llrintf;
using streams_boost::math::tr1::llrintl;
#endif
using streams_boost::math::tr1::llround;
using streams_boost::math::tr1::llroundf;
using streams_boost::math::tr1::llroundl;
using streams_boost::math::tr1::log1p;
using streams_boost::math::tr1::log1pf;
using streams_boost::math::tr1::log1pl;
#if 0
using streams_boost::math::tr1::log2;
using streams_boost::math::tr1::log2f;
using streams_boost::math::tr1::log2l;
using streams_boost::math::tr1::logb;
using streams_boost::math::tr1::logbf;
using streams_boost::math::tr1::logbl;
using streams_boost::math::tr1::lrint;
using streams_boost::math::tr1::lrintf;
using streams_boost::math::tr1::lrintl;
#endif
using streams_boost::math::tr1::lround;
using streams_boost::math::tr1::lroundf;
using streams_boost::math::tr1::lroundl;
#if 0
using streams_boost::math::tr1::nan;
using streams_boost::math::tr1::nanf;
using streams_boost::math::tr1::nanl;
using streams_boost::math::tr1::nearbyint;
using streams_boost::math::tr1::nearbyintf;
using streams_boost::math::tr1::nearbyintl;
#endif
using streams_boost::math::tr1::nextafter;
using streams_boost::math::tr1::nextafterf;
using streams_boost::math::tr1::nextafterl;
using streams_boost::math::tr1::nexttoward;
using streams_boost::math::tr1::nexttowardf;
using streams_boost::math::tr1::nexttowardl;
#if 0
using streams_boost::math::tr1::remainder;
using streams_boost::math::tr1::remainderf;
using streams_boost::math::tr1::remainderl;
using streams_boost::math::tr1::remquo;
using streams_boost::math::tr1::remquof;
using streams_boost::math::tr1::remquol;
using streams_boost::math::tr1::rint;
using streams_boost::math::tr1::rintf;
using streams_boost::math::tr1::rintl;
#endif
using streams_boost::math::tr1::round;
using streams_boost::math::tr1::roundf;
using streams_boost::math::tr1::roundl;
#if 0
using streams_boost::math::tr1::scalbln;
using streams_boost::math::tr1::scalblnf;
using streams_boost::math::tr1::scalblnl;
using streams_boost::math::tr1::scalbn;
using streams_boost::math::tr1::scalbnf;
using streams_boost::math::tr1::scalbnl;
#endif
using streams_boost::math::tr1::tgamma;
using streams_boost::math::tr1::tgammaf;
using streams_boost::math::tr1::tgammal;
using streams_boost::math::tr1::trunc;
using streams_boost::math::tr1::truncf;
using streams_boost::math::tr1::truncl;
// C99 macros defined as C++ templates
using streams_boost::math::tr1::signbit;
using streams_boost::math::tr1::fpclassify;
using streams_boost::math::tr1::isfinite;
using streams_boost::math::tr1::isinf;
using streams_boost::math::tr1::isnan;
using streams_boost::math::tr1::isnormal;
#if 0
using streams_boost::math::tr1::isgreater;
using streams_boost::math::tr1::isgreaterequal;
using streams_boost::math::tr1::isless;
using streams_boost::math::tr1::islessequal;
using streams_boost::math::tr1::islessgreater;
using streams_boost::math::tr1::isunordered;
#endif
} } // namespaces

#endif // STREAMS_BOOST_HAS_TR1_CMATH

#endif // STREAMS_BOOST_TR1_CMATH_HPP_INCLUDED
