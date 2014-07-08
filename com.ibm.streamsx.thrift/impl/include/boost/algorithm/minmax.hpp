//  (C) Copyright Herve Bronnimann 2004.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

/*
 Revision history:
   1 July 2004
      Split the code into two headers to lessen dependence on
      Boost.tuple. (Herve)
   26 June 2004
      Added the code for the streams_boost minmax library. (Herve)
*/

#ifndef STREAMS_BOOST_ALGORITHM_MINMAX_HPP
#define STREAMS_BOOST_ALGORITHM_MINMAX_HPP

/* PROPOSED STANDARD EXTENSIONS:
 *
 * minmax(a, b)
 * Effect: (b<a) ? std::make_pair(b,a) : std::make_pair(a,b);
 *
 * minmax(a, b, comp)
 * Effect: comp(b,a) ? std::make_pair(b,a) : std::make_pair(a,b);
 *
 */

#include <streams_boost/tuple/tuple.hpp> // for using pairs with streams_boost::cref
#include <streams_boost/ref.hpp>

namespace streams_boost {

  template <typename T>
  tuple< T const&, T const& >
  minmax(T const& a, T const& b) {
    return (b<a) ? make_tuple(cref(b),cref(a)) : make_tuple(cref(a),cref(b));
  }

  template <typename T, class BinaryPredicate>
  tuple< T const&, T const& >
  minmax(T const& a, T const& b, BinaryPredicate comp) {
    return comp(b,a) ? make_tuple(cref(b),cref(a)) : make_tuple(cref(a),cref(b));
  }

} // namespace streams_boost

#endif // STREAMS_BOOST_ALGORITHM_MINMAX_HPP
