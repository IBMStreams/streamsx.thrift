//  Copyright (c) 2006 Xiaogang Zhang
//  Copyright (c) 2006 John Maddock
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  History:
//  XZ wrote the original of this file as part of the Google
//  Summer of Code 2006.  JM modified it to fit into the
//  Boost.Math conceptual framework better, and to ensure
//  that the code continues to work no matter how many digits
//  type T has.

#ifndef STREAMS_BOOST_MATH_ELLINT_1_HPP
#define STREAMS_BOOST_MATH_ELLINT_1_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/math/special_functions/ellint_rf.hpp>
#include <streams_boost/math/constants/constants.hpp>
#include <streams_boost/math/policies/error_handling.hpp>
#include <streams_boost/math/tools/workaround.hpp>

// Elliptic integrals (complete and incomplete) of the first kind
// Carlson, Numerische Mathematik, vol 33, 1 (1979)

namespace streams_boost { namespace math {

template <class T1, class T2, class Policy>
typename tools::promote_args<T1, T2>::type ellint_1(T1 k, T2 phi, const Policy& pol);

namespace detail{

template <typename T, typename Policy>
T ellint_k_imp(T k, const Policy& pol);

// Elliptic integral (Legendre form) of the first kind
template <typename T, typename Policy>
T ellint_f_imp(T phi, T k, const Policy& pol)
{
    STREAMS_BOOST_MATH_STD_USING
    using namespace streams_boost::math::tools;
    using namespace streams_boost::math::constants;

    static const char* function = "streams_boost::math::ellint_f<%1%>(%1%,%1%)";
    STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(phi);
    STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(k);
    STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(function);

    if (abs(k) > 1)
    {
       return policies::raise_domain_error<T>(function,
            "Got k = %1%, function requires |k| <= 1", k, pol);
    }

    bool invert = false;
    if(phi < 0)
    {
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(phi);
       phi = fabs(phi);
       invert = true;
    }

    T result;

    if(phi >= tools::max_value<T>())
    {
       // Need to handle infinity as a special case:
       result = policies::raise_overflow_error<T>(function, 0, pol);
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
    }
    else if(phi > 1 / tools::epsilon<T>())
    {
       // Phi is so large that phi%pi is necessarily zero (or garbage),
       // just return the second part of the duplication formula:
       result = 2 * phi * ellint_k_imp(k, pol) / constants::pi<T>();
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
    }
    else
    {
       // Carlson's algorithm works only for |phi| <= pi/2,
       // use the integrand's periodicity to normalize phi
       //
       // Xiaogang's original code used a cast to long long here
       // but that fails if T has more digits than a long long,
       // so rewritten to use fmod instead:
       //
       STREAMS_BOOST_MATH_INSTRUMENT_CODE("pi/2 = " << constants::pi<T>() / 2);
       T rphi = streams_boost::math::tools::fmod_workaround(phi, T(constants::pi<T>() / 2));
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(rphi);
       T m = floor((2 * phi) / constants::pi<T>());
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(m);
       int s = 1;
       if(streams_boost::math::tools::fmod_workaround(m, T(2)) > 0.5)
       {
          m += 1;
          s = -1;
          rphi = constants::pi<T>() / 2 - rphi;
          STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(rphi);
       }
       T sinp = sin(rphi);
       T cosp = cos(rphi);
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(sinp);
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(cosp);
       result = s * sinp * ellint_rf_imp(T(cosp * cosp), T(1 - k * k * sinp * sinp), T(1), pol);
       STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
       if(m != 0)
       {
          result += m * ellint_k_imp(k, pol);
          STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
       }
    }
    return invert ? T(-result) : result;
}

// Complete elliptic integral (Legendre form) of the first kind
template <typename T, typename Policy>
T ellint_k_imp(T k, const Policy& pol)
{
    STREAMS_BOOST_MATH_STD_USING
    using namespace streams_boost::math::tools;

    static const char* function = "streams_boost::math::ellint_k<%1%>(%1%)";

    if (abs(k) > 1)
    {
       return policies::raise_domain_error<T>(function,
            "Got k = %1%, function requires |k| <= 1", k, pol);
    }
    if (abs(k) == 1)
    {
       return policies::raise_overflow_error<T>(function, 0, pol);
    }

    T x = 0;
    T y = 1 - k * k;
    T z = 1;
    T value = ellint_rf_imp(x, y, z, pol);

    return value;
}

template <typename T, typename Policy>
inline typename tools::promote_args<T>::type ellint_1(T k, const Policy& pol, const mpl::true_&)
{
   typedef typename tools::promote_args<T>::type result_type;
   typedef typename policies::evaluation<result_type, Policy>::type value_type;
   return policies::checked_narrowing_cast<result_type, Policy>(detail::ellint_k_imp(static_cast<value_type>(k), pol), "streams_boost::math::ellint_1<%1%>(%1%)");
}

template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type ellint_1(T1 k, T2 phi, const mpl::false_&)
{
   return streams_boost::math::ellint_1(k, phi, policies::policy<>());
}

}

// Complete elliptic integral (Legendre form) of the first kind
template <typename T>
inline typename tools::promote_args<T>::type ellint_1(T k)
{
   return ellint_1(k, policies::policy<>());
}

// Elliptic integral (Legendre form) of the first kind
template <class T1, class T2, class Policy>
inline typename tools::promote_args<T1, T2>::type ellint_1(T1 k, T2 phi, const Policy& pol)
{
   typedef typename tools::promote_args<T1, T2>::type result_type;
   typedef typename policies::evaluation<result_type, Policy>::type value_type;
   return policies::checked_narrowing_cast<result_type, Policy>(detail::ellint_f_imp(static_cast<value_type>(phi), static_cast<value_type>(k), pol), "streams_boost::math::ellint_1<%1%>(%1%,%1%)");
}

template <class T1, class T2>
inline typename tools::promote_args<T1, T2>::type ellint_1(T1 k, T2 phi)
{
   typedef typename policies::is_policy<T2>::type tag_type;
   return detail::ellint_1(k, phi, tag_type());
}

}} // namespaces

#endif // STREAMS_BOOST_MATH_ELLINT_1_HPP

