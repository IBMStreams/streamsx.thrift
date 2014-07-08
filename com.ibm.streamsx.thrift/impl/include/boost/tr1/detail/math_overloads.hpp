//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_MATH_OVERLOADS_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_MATH_OVERLOADS_HPP_INCLUDED
#  include <streams_boost/config.hpp>

#  ifndef STREAMS_BOOST_NO_SFINAE
#     include <streams_boost/utility/enable_if.hpp>
#     include <streams_boost/type_traits/is_convertible.hpp>
#     define STREAMS_BOOST_TR1_MATH_RETURN(RET) typename ::streams_boost::enable_if< ::streams_boost::is_convertible<T,double>, RET >::type
#  else
#     define STREAMS_BOOST_TR1_MATH_RETURN(RET) RET
#  endif

#  include <streams_boost/type_traits/is_floating_point.hpp>
#  include <streams_boost/type_traits/is_same.hpp>
#  include <streams_boost/mpl/if.hpp>

namespace streams_boost{ namespace tr1_detail{

template <class T, class U>
struct largest_real
{
   typedef typename streams_boost::mpl::if_<
      streams_boost::is_same<long double, T>,
      long double,
      typename streams_boost::mpl::if_<
         streams_boost::is_same<long double, U>,
         long double,
         typename streams_boost::mpl::if_<
            streams_boost::is_same<double, T>,
            double,
            typename streams_boost::mpl::if_<
               streams_boost::is_same<double, U>,
               double,
               float
            >::type
         >::type
      >::type
   >::type type;
};

template <class T, class U>
struct promote_to_real
{
   typedef typename largest_real<
      typename streams_boost::mpl::if_< streams_boost::is_floating_point<T>, T, double>::type,
      typename streams_boost::mpl::if_< streams_boost::is_floating_point<U>, U, double>::type
   >::type type;
};

} }

#endif

