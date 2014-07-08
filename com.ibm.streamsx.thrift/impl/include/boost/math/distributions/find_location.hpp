//  Copyright John Maddock 2007.
//  Copyright Paul A. Bristow 2007.

//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_STATS_FIND_LOCATION_HPP
#define STREAMS_BOOST_STATS_FIND_LOCATION_HPP

#include <streams_boost/math/distributions/fwd.hpp> // for all distribution signatures.
#include <streams_boost/math/distributions/complement.hpp>
#include <streams_boost/math/policies/policy.hpp>
#include <streams_boost/math/tools/traits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/math/special_functions/fpclassify.hpp>
#include <streams_boost/math/policies/error_handling.hpp>
// using streams_boost::math::policies::policy;
// using streams_boost::math::complement; // will be needed by users who want complement,
// but NOT placed here to avoid putting it in global scope.

namespace streams_boost
{
  namespace math
  {
  // Function to find location of random variable z
  // to give probability p (given scale)
  // Applies to normal, lognormal, extreme value, Cauchy, (and symmetrical triangular),
  // enforced by STREAMS_BOOST_STATIC_ASSERT below.

    template <class Dist, class Policy>
    inline
      typename Dist::value_type find_location( // For example, normal mean.
      typename Dist::value_type z, // location of random variable z to give probability, P(X > z) == p.
      // For example, a nominal minimum acceptable z, so that p * 100 % are > z
      typename Dist::value_type p, // probability value desired at x, say 0.95 for 95% > z.
      typename Dist::value_type scale, // scale parameter, for example, normal standard deviation.
      const Policy& pol 
      )
    {
#if !defined(STREAMS_BOOST_NO_SFINAE) && !STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x590))
      // Will fail to compile here if try to use with a distribution without scale & location,
      // for example pareto, and many others.  These tests are disabled by the pp-logic
      // above if the compiler doesn't support the SFINAE tricks used in the traits class.
      STREAMS_BOOST_STATIC_ASSERT(::streams_boost::math::tools::is_distribution<Dist>::value); 
      STREAMS_BOOST_STATIC_ASSERT(::streams_boost::math::tools::is_scaled_distribution<Dist>::value);
#endif
      static const char* function = "streams_boost::math::find_location<Dist, Policy>&, %1%)";

      if(!(streams_boost::math::isfinite)(p) || (p < 0) || (p > 1))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "Probability parameter was %1%, but must be >= 0 and <= 1!", p, pol);
      }
      if(!(streams_boost::math::isfinite)(z))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "z parameter was %1%, but must be finite!", z, pol);
      }
      if(!(streams_boost::math::isfinite)(scale))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "scale parameter was %1%, but must be finite!", scale, pol);
      }
        
      //cout << "z " << z << ", p " << p << ",  quantile(Dist(), p) "
      //  << quantile(Dist(), p) << ", quan * scale " << quantile(Dist(), p) * scale << endl;
      return z - (quantile(Dist(), p) * scale);
    } // find_location

    template <class Dist>
    inline // with default policy.
      typename Dist::value_type find_location( // For example, normal mean.
      typename Dist::value_type z, // location of random variable z to give probability, P(X > z) == p.
      // For example, a nominal minimum acceptable z, so that p * 100 % are > z
      typename Dist::value_type p, // probability value desired at x, say 0.95 for 95% > z.
      typename Dist::value_type scale) // scale parameter, for example, normal standard deviation.
    { // Forward to find_location with default policy.
       return (find_location<Dist>(z, p, scale, policies::policy<>()));
    } // find_location

    // So the user can start from the complement q = (1 - p) of the probability p,
    // for example, l = find_location<normal>(complement(z, q, sd));

    template <class Dist, class Real1, class Real2, class Real3>
    inline typename Dist::value_type find_location( // Default policy.
      complemented3_type<Real1, Real2, Real3> const& c)
    {
      static const char* function = "streams_boost::math::find_location<Dist, Policy>&, %1%)";

      typename Dist::value_type p = c.param1;
      if(!(streams_boost::math::isfinite)(p) || (p < 0) || (p > 1))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "Probability parameter was %1%, but must be >= 0 and <= 1!", p, policies::policy<>());
      }
      typename Dist::value_type z = c.dist;
      if(!(streams_boost::math::isfinite)(z))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "z parameter was %1%, but must be finite!", z, policies::policy<>());
      }
      typename Dist::value_type scale = c.param2;
      if(!(streams_boost::math::isfinite)(scale))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "scale parameter was %1%, but must be finite!", scale, policies::policy<>());
      }
       // cout << "z " << c.dist << ", quantile (Dist(), " << c.param1 << ") * scale " << c.param2 << endl;
       return z - quantile(Dist(), p) * scale;
    } // find_location complement


    template <class Dist, class Real1, class Real2, class Real3, class Real4>
    inline typename Dist::value_type find_location( // Explicit policy.
      complemented4_type<Real1, Real2, Real3, Real4> const& c)
    {
      static const char* function = "streams_boost::math::find_location<Dist, Policy>&, %1%)";

      typename Dist::value_type p = c.param1;
      if(!(streams_boost::math::isfinite)(p) || (p < 0) || (p > 1))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "Probability parameter was %1%, but must be >= 0 and <= 1!", p, c.param3);
      }
      typename Dist::value_type z = c.dist;
      if(!(streams_boost::math::isfinite)(z))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "z parameter was %1%, but must be finite!", z, c.param3);
      }
      typename Dist::value_type scale = c.param2;
      if(!(streams_boost::math::isfinite)(scale))
      {
       return policies::raise_domain_error<typename Dist::value_type>(
           function, "scale parameter was %1%, but must be finite!", scale, c.param3);
      }
       // cout << "z " << c.dist << ", quantile (Dist(), " << c.param1 << ") * scale " << c.param2 << endl;
       return z - quantile(Dist(), p) * scale;
    } // find_location complement

  } // namespace streams_boost
} // namespace math

#endif // STREAMS_BOOST_STATS_FIND_LOCATION_HPP

