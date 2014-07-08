/* Boost interval/limits.hpp template implementation file
 *
 * Copyright 2000 Jens Maurer
 * Copyright 2002-2003 Hervé Brönnimann, Guillaume Melquiond, Sylvain Pion
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or
 * copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 */

#ifndef STREAMS_BOOST_NUMERIC_INTERVAL_LIMITS_HPP
#define STREAMS_BOOST_NUMERIC_INTERVAL_LIMITS_HPP

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/numeric/interval/detail/interval_prototype.hpp>

namespace std {

template<class T, class Policies>
class numeric_limits<streams_boost::numeric::interval<T, Policies> >
  : public numeric_limits<T>
{
private:
  typedef streams_boost::numeric::interval<T, Policies> I;
  typedef numeric_limits<T> bl;
public:
  static I min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () throw() { return I((bl::min)(), (bl::min)()); }
  static I max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () throw() { return I((bl::max)(), (bl::max)()); }
  static I epsilon() throw() { return I(bl::epsilon(), bl::epsilon()); }

  STREAMS_BOOST_STATIC_CONSTANT(float_round_style, round_style = round_indeterminate);
  STREAMS_BOOST_STATIC_CONSTANT(bool, is_iec559 = false);

  static I infinity () throw() { return I::whole(); }
  static I quiet_NaN() throw() { return I::empty(); }
  static I signaling_NaN() throw()
  { return I(bl::signaling_NaN(), bl::signaling_Nan()); }
  static I denorm_min() throw()
  { return I(bl::denorm_min(), bl::denorm_min()); }
private:
  static I round_error();    // hide this on purpose, not yet implemented
};

} // namespace std

#endif

#endif // STREAMS_BOOST_NUMERIC_INTERVAL_LIMITS_HPP
