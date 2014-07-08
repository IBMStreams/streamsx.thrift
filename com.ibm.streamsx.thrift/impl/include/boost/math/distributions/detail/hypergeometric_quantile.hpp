// Copyright 2008 John Maddock
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_DISTRIBUTIONS_DETAIL_HG_QUANTILE_HPP
#define STREAMS_BOOST_MATH_DISTRIBUTIONS_DETAIL_HG_QUANTILE_HPP

#include <streams_boost/math/policies/error_handling.hpp>
#include <streams_boost/math/distributions/detail/hypergeometric_pdf.hpp>

namespace streams_boost{ namespace math{ namespace detail{

template <class T>
inline unsigned round_x_from_p(unsigned x, T p, T cum, T fudge_factor, unsigned lbound, unsigned /*ubound*/, const policies::discrete_quantile<policies::integer_round_down>&)
{
   if((p < cum * fudge_factor) && (x != lbound))
   {
      STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x-1);
      return --x;
   }
   return x;
}

template <class T>
inline unsigned round_x_from_p(unsigned x, T p, T cum, T fudge_factor, unsigned /*lbound*/, unsigned ubound, const policies::discrete_quantile<policies::integer_round_up>&)
{
   if((cum < p * fudge_factor) && (x != ubound))
   {
      STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x+1);
      return ++x;
   }
   return x;
}

template <class T>
inline unsigned round_x_from_p(unsigned x, T p, T cum, T fudge_factor, unsigned lbound, unsigned ubound, const policies::discrete_quantile<policies::integer_round_inwards>&)
{
   if(p >= 0.5)
      return round_x_from_p(x, p, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_down>());
   return round_x_from_p(x, p, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_up>());
}

template <class T>
inline unsigned round_x_from_p(unsigned x, T p, T cum, T fudge_factor, unsigned lbound, unsigned ubound, const policies::discrete_quantile<policies::integer_round_outwards>&)
{
   if(p >= 0.5)
      return round_x_from_p(x, p, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_up>());
   return round_x_from_p(x, p, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_down>());
}

template <class T>
inline unsigned round_x_from_p(unsigned x, T /*p*/, T /*cum*/, T /*fudge_factor*/, unsigned /*lbound*/, unsigned /*ubound*/, const policies::discrete_quantile<policies::integer_round_nearest>&)
{
   return x;
}

template <class T>
inline unsigned round_x_from_q(unsigned x, T q, T cum, T fudge_factor, unsigned lbound, unsigned /*ubound*/, const policies::discrete_quantile<policies::integer_round_down>&)
{
   if((q * fudge_factor > cum) && (x != lbound))
   {
      STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x-1);
      return --x;
   }
   return x;
}

template <class T>
inline unsigned round_x_from_q(unsigned x, T q, T cum, T fudge_factor, unsigned /*lbound*/, unsigned ubound, const policies::discrete_quantile<policies::integer_round_up>&)
{
   if((q < cum * fudge_factor) && (x != ubound))
   {
      STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x+1);
      return ++x;
   }
   return x;
}

template <class T>
inline unsigned round_x_from_q(unsigned x, T q, T cum, T fudge_factor, unsigned lbound, unsigned ubound, const policies::discrete_quantile<policies::integer_round_inwards>&)
{
   if(q < 0.5)
      return round_x_from_q(x, q, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_down>());
   return round_x_from_q(x, q, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_up>());
}

template <class T>
inline unsigned round_x_from_q(unsigned x, T q, T cum, T fudge_factor, unsigned lbound, unsigned ubound, const policies::discrete_quantile<policies::integer_round_outwards>&)
{
   if(q >= 0.5)
      return round_x_from_q(x, q, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_down>());
   return round_x_from_q(x, q, cum, fudge_factor, lbound, ubound, policies::discrete_quantile<policies::integer_round_up>());
}

template <class T>
inline unsigned round_x_from_q(unsigned x, T /*q*/, T /*cum*/, T /*fudge_factor*/, unsigned /*lbound*/, unsigned /*ubound*/, const policies::discrete_quantile<policies::integer_round_nearest>&)
{
   return x;
}

template <class T, class Policy>
unsigned hypergeometric_quantile_imp(T p, T q, unsigned r, unsigned n, unsigned N, const Policy& pol)
{
#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable:4267)
#endif
   typedef typename Policy::discrete_quantile_type discrete_quantile_type;
   STREAMS_BOOST_MATH_STD_USING
   STREAMS_BOOST_FPU_EXCEPTION_GUARD
   T result;
   T fudge_factor = 1 + tools::epsilon<T>() * ((N <= streams_boost::math::prime(streams_boost::math::max_prime - 1)) ? 50 : 2 * N);
   unsigned base = static_cast<unsigned>((std::max)(0, (int)(n + r) - (int)(N)));
   unsigned lim = (std::min)(r, n);

   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(p);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(q);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(r);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(n);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(N);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(fudge_factor);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(base);
   STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(lim);

   if(p <= 0.5)
   {
      unsigned x = base;
      result = hypergeometric_pdf<T>(x, r, n, N, pol);
      T diff = result;
      while(result < p)
      {
         diff = (diff > tools::min_value<T>() * 8) 
            ? T(n - x) * T(r - x) * diff / (T(x + 1) * T(N + x + 1 - n - r))
            : hypergeometric_pdf<T>(x + 1, r, n, N, pol);
         if(result + diff / 2 > p)
            break;
         ++x;
         result += diff;
#ifdef STREAMS_BOOST_MATH_INSTRUMENT
         if(diff != 0)
         {
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x);
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(diff);
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
         }
#endif
      }
      return round_x_from_p(x, p, result, fudge_factor, base, lim, discrete_quantile_type());
   }
   else
   {
      unsigned x = lim;
      result = 0;
      T diff = hypergeometric_pdf<T>(x, r, n, N, pol);
      while(result + diff / 2 < q)
      {
         result += diff;
         diff = (diff > tools::min_value<T>() * 8)
            ? x * T(N + x - n - r) * diff / (T(1 + n - x) * T(1 + r - x))
            : hypergeometric_pdf<T>(x - 1, r, n, N, pol);
         --x;
#ifdef STREAMS_BOOST_MATH_INSTRUMENT
         if(diff != 0)
         {
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x);
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(diff);
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
         }
#endif
      }
      return round_x_from_q(x, q, result, fudge_factor, base, lim, discrete_quantile_type());
   }
#ifdef STREAMS_BOOST_MSVC
#  pragma warning(pop)
#endif
}

template <class T, class Policy>
inline unsigned hypergeometric_quantile(T p, T q, unsigned r, unsigned n, unsigned N, const Policy&)
{
   STREAMS_BOOST_FPU_EXCEPTION_GUARD
   typedef typename tools::promote_args<T>::type result_type;
   typedef typename policies::evaluation<result_type, Policy>::type value_type;
   typedef typename policies::normalise<
      Policy, 
      policies::promote_float<false>, 
      policies::promote_double<false>, 
      policies::assert_undefined<> >::type forwarding_policy;

   return detail::hypergeometric_quantile_imp<value_type>(p, q, r, n, N, forwarding_policy());
}

}}} // namespaces

#endif

