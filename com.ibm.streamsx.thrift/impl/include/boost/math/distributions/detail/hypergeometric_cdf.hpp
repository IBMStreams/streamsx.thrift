// Copyright 2008 John Maddock
//
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_DISTRIBUTIONS_DETAIL_HG_CDF_HPP
#define STREAMS_BOOST_MATH_DISTRIBUTIONS_DETAIL_HG_CDF_HPP

#include <streams_boost/math/policies/error_handling.hpp>
#include <streams_boost/math/distributions/detail/hypergeometric_pdf.hpp>

namespace streams_boost{ namespace math{ namespace detail{

   template <class T, class Policy>
   T hypergeometric_cdf_imp(unsigned x, unsigned r, unsigned n, unsigned N, bool invert, const Policy& pol)
   {
#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable:4267)
#endif
      STREAMS_BOOST_MATH_STD_USING
      T result = 0;
      T mode = floor(T(r + 1) * T(n + 1) / (N + 2));
      if(x < mode)
      {
         result = hypergeometric_pdf<T>(x, r, n, N, pol);
         T diff = result;
         unsigned lower_limit = static_cast<unsigned>((std::max)(0, (int)(n + r) - (int)(N)));
         while(diff > (invert ? T(1) : result) * tools::epsilon<T>())
         {
            diff = T(x) * T((N + x) - n - r) * diff / (T(1 + n - x) * T(1 + r - x));
            result += diff;
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x);
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(diff);
            STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
            if(x == lower_limit)
               break;
            --x;
         }
      }
      else
      {
         invert = !invert;
         unsigned upper_limit = (std::min)(r, n);
         if(x != upper_limit)
         {
            ++x;
            result = hypergeometric_pdf<T>(x, r, n, N, pol);
            T diff = result;
            while((x <= upper_limit) && (diff > (invert ? T(1) : result) * tools::epsilon<T>()))
            {
               diff = T(n - x) * T(r - x) * diff / (T(x + 1) * T((N + x + 1) - n - r));
               result += diff;
               ++x;
               STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(x);
               STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(diff);
               STREAMS_BOOST_MATH_INSTRUMENT_VARIABLE(result);
            }
         }
      }
      if(invert)
         result = 1 - result;
      return result;
#ifdef STREAMS_BOOST_MSVC
#  pragma warning(pop)
#endif
   }

   template <class T, class Policy>
   inline T hypergeometric_cdf(unsigned x, unsigned r, unsigned n, unsigned N, bool invert, const Policy&)
   {
      STREAMS_BOOST_FPU_EXCEPTION_GUARD
      typedef typename tools::promote_args<T>::type result_type;
      typedef typename policies::evaluation<result_type, Policy>::type value_type;
      typedef typename policies::normalise<
         Policy, 
         policies::promote_float<false>, 
         policies::promote_double<false>, 
         policies::discrete_quantile<>,
         policies::assert_undefined<> >::type forwarding_policy;

      value_type result;
      result = detail::hypergeometric_cdf_imp<value_type>(x, r, n, N, invert, forwarding_policy());
      if(result > 1)
      {
         result  = 1;
      }
      if(result < 0)
      {
         result = 0;
      }
      return policies::checked_narrowing_cast<result_type, forwarding_policy>(result, "streams_boost::math::hypergeometric_cdf<%1%>(%1%,%1%,%1%,%1%)");
   }

}}} // namespaces

#endif

