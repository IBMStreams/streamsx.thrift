//  (C) Copyright John Maddock 2005-2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_TOOLS_FRACTION_INCLUDED
#define STREAMS_BOOST_MATH_TOOLS_FRACTION_INCLUDED

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/config/no_tr1/cmath.hpp>
#include <streams_boost/cstdint.hpp>
#include <streams_boost/type_traits/integral_constant.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/math/tools/precision.hpp>

namespace streams_boost{ namespace math{ namespace tools{

namespace detail
{

   template <class T>
   struct is_pair : public streams_boost::false_type{};

   template <class T, class U>
   struct is_pair<std::pair<T,U> > : public streams_boost::true_type{};

   template <class Gen>
   struct fraction_traits_simple
   {
       typedef typename Gen::result_type result_type;
       typedef typename Gen::result_type value_type;

       static result_type a(const value_type& v)
       {
          return 1;
       }
       static result_type b(const value_type& v)
       {
          return v;
       }
   };

   template <class Gen>
   struct fraction_traits_pair
   {
       typedef typename Gen::result_type value_type;
       typedef typename value_type::first_type result_type;

       static result_type a(const value_type& v)
       {
          return v.first;
       }
       static result_type b(const value_type& v)
       {
          return v.second;
       }
   };

   template <class Gen>
   struct fraction_traits
       : public streams_boost::mpl::if_c<
         is_pair<typename Gen::result_type>::value,
         fraction_traits_pair<Gen>,
         fraction_traits_simple<Gen> >::type
   {
   };

} // namespace detail

//
// continued_fraction_b
// Evaluates:
//
// b0 +       a1
//      ---------------
//      b1 +     a2
//           ----------
//           b2 +   a3
//                -----
//                b3 + ...
//
// Note that the first a0 returned by generator Gen is disarded.
//
template <class Gen, class U>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_b(Gen& g, const U& factor, streams_boost::uintmax_t& max_terms)
{
   STREAMS_BOOST_MATH_STD_USING // ADL of std names

   typedef detail::fraction_traits<Gen> traits;
   typedef typename traits::result_type result_type;
   typedef typename traits::value_type value_type;

   result_type tiny = tools::min_value<result_type>();

   value_type v = g();

   result_type f, C, D, delta;
   f = traits::b(v);
   if(f == 0)
      f = tiny;
   C = f;
   D = 0;

   streams_boost::uintmax_t counter(max_terms);

   do{
      v = g();
      D = traits::b(v) + traits::a(v) * D;
      if(D == 0)
         D = tiny;
      C = traits::b(v) + traits::a(v) / C;
      if(C == 0)
         C = tiny;
      D = 1/D;
      delta = C*D;
      f = f * delta;
   }while((fabs(delta - 1) > factor) && --counter);

   max_terms = max_terms - counter;

   return f;
}

template <class Gen, class U>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_b(Gen& g, const U& factor)
{
   streams_boost::uintmax_t max_terms = (std::numeric_limits<streams_boost::uintmax_t>::max)();
   return continued_fraction_b(g, factor, max_terms);
}

template <class Gen>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_b(Gen& g, int bits)
{
   STREAMS_BOOST_MATH_STD_USING // ADL of std names

   typedef detail::fraction_traits<Gen> traits;
   typedef typename traits::result_type result_type;

   result_type factor = ldexp(1.0f, 1 - bits); // 1 / pow(result_type(2), bits);
   streams_boost::uintmax_t max_terms = (std::numeric_limits<streams_boost::uintmax_t>::max)();
   return continued_fraction_b(g, factor, max_terms);
}

template <class Gen>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_b(Gen& g, int bits, streams_boost::uintmax_t& max_terms)
{
   STREAMS_BOOST_MATH_STD_USING // ADL of std names

   typedef detail::fraction_traits<Gen> traits;
   typedef typename traits::result_type result_type;

   result_type factor = ldexp(1.0f, 1 - bits); // 1 / pow(result_type(2), bits);
   return continued_fraction_b(g, factor, max_terms);
}

//
// continued_fraction_a
// Evaluates:
//
//            a1
//      ---------------
//      b1 +     a2
//           ----------
//           b2 +   a3
//                -----
//                b3 + ...
//
// Note that the first a1 and b1 returned by generator Gen are both used.
//
template <class Gen, class U>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_a(Gen& g, const U& factor, streams_boost::uintmax_t& max_terms)
{
   STREAMS_BOOST_MATH_STD_USING // ADL of std names

   typedef detail::fraction_traits<Gen> traits;
   typedef typename traits::result_type result_type;
   typedef typename traits::value_type value_type;

   result_type tiny = tools::min_value<result_type>();

   value_type v = g();

   result_type f, C, D, delta, a0;
   f = traits::b(v);
   a0 = traits::a(v);
   if(f == 0)
      f = tiny;
   C = f;
   D = 0;

   streams_boost::uintmax_t counter(max_terms);

   do{
      v = g();
      D = traits::b(v) + traits::a(v) * D;
      if(D == 0)
         D = tiny;
      C = traits::b(v) + traits::a(v) / C;
      if(C == 0)
         C = tiny;
      D = 1/D;
      delta = C*D;
      f = f * delta;
   }while((fabs(delta - 1) > factor) && --counter);

   max_terms = max_terms - counter;

   return a0/f;
}

template <class Gen, class U>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_a(Gen& g, const U& factor)
{
   streams_boost::uintmax_t max_iter = (std::numeric_limits<streams_boost::uintmax_t>::max)();
   return continued_fraction_a(g, factor, max_iter);
}

template <class Gen>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_a(Gen& g, int bits)
{
   STREAMS_BOOST_MATH_STD_USING // ADL of std names

   typedef detail::fraction_traits<Gen> traits;
   typedef typename traits::result_type result_type;

   result_type factor = ldexp(1.0f, 1-bits); // 1 / pow(result_type(2), bits);
   streams_boost::uintmax_t max_iter = (std::numeric_limits<streams_boost::uintmax_t>::max)();

   return continued_fraction_a(g, factor, max_iter);
}

template <class Gen>
inline typename detail::fraction_traits<Gen>::result_type continued_fraction_a(Gen& g, int bits, streams_boost::uintmax_t& max_terms)
{
   STREAMS_BOOST_MATH_STD_USING // ADL of std names

   typedef detail::fraction_traits<Gen> traits;
   typedef typename traits::result_type result_type;

   result_type factor = ldexp(1.0f, 1-bits); // 1 / pow(result_type(2), bits);
   return continued_fraction_a(g, factor, max_terms);
}

} // namespace tools
} // namespace math
} // namespace streams_boost

#endif // STREAMS_BOOST_MATH_TOOLS_FRACTION_INCLUDED
