/* streams_boost random/uniform_01.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: uniform_01.hpp 58649 2010-01-02 21:23:17Z steven_watanabe $
 *
 * Revision history
 *  2001-02-18  moved to individual header files
 */

#ifndef STREAMS_BOOST_RANDOM_UNIFORM_01_HPP
#define STREAMS_BOOST_RANDOM_UNIFORM_01_HPP

#include <iostream>
#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/random/detail/config.hpp>
#include <streams_boost/random/detail/pass_through_engine.hpp>

#include <streams_boost/random/detail/disable_warnings.hpp>

namespace streams_boost {

namespace detail {

template<class RealType>
class new_uniform_01
{
public:
  typedef RealType input_type;
  typedef RealType result_type;
  // compiler-generated copy ctor and copy assignment are fine
  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return result_type(0); }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return result_type(1); }
  void reset() { }

  template<class Engine>
  result_type operator()(Engine& eng) {
    for (;;) {
      typedef typename Engine::result_type base_result;
      result_type factor = result_type(1) /
              (result_type((eng.max)()-(eng.min)()) +
               result_type(std::numeric_limits<base_result>::is_integer ? 1 : 0));
      result_type result = result_type(eng() - (eng.min)()) * factor;
      if (result < result_type(1))
        return result;
    }
  }

#ifndef STREAMS_BOOST_RANDOM_NO_STREAM_OPERATORS
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const new_uniform_01&)
  {
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, new_uniform_01&)
  {
    return is;
  }
#endif
};

template<class UniformRandomNumberGenerator, class RealType>
class backward_compatible_uniform_01
{
  typedef streams_boost::random::detail::ptr_helper<UniformRandomNumberGenerator> traits;
  typedef streams_boost::random::detail::pass_through_engine<UniformRandomNumberGenerator> internal_engine_type;
public:
  typedef UniformRandomNumberGenerator base_type;
  typedef RealType result_type;

  STREAMS_BOOST_STATIC_CONSTANT(bool, has_fixed_range = false);

#if !defined(STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS) && !(defined(STREAMS_BOOST_MSVC) && STREAMS_BOOST_MSVC <= 1300)
  STREAMS_BOOST_STATIC_ASSERT(!std::numeric_limits<RealType>::is_integer);
#endif

  explicit backward_compatible_uniform_01(typename traits::rvalue_type rng)
    : _rng(rng),
      _factor(result_type(1) /
              (result_type((_rng.max)()-(_rng.min)()) +
               result_type(std::numeric_limits<base_result>::is_integer ? 1 : 0)))
  {
  }
  // compiler-generated copy ctor and copy assignment are fine

  result_type min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return result_type(0); }
  result_type max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION () const { return result_type(1); }
  typename traits::value_type& base() { return _rng.base(); }
  const typename traits::value_type& base() const { return _rng.base(); }
  void reset() { }

  result_type operator()() {
    for (;;) {
      result_type result = result_type(_rng() - (_rng.min)()) * _factor;
      if (result < result_type(1))
        return result;
    }
  }

#if !defined(STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE) && !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const backward_compatible_uniform_01& u)
  {
    os << u._rng;
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, backward_compatible_uniform_01& u)
  {
    is >> u._rng;
    return is;
  }
#endif

private:
  typedef typename internal_engine_type::result_type base_result;
  internal_engine_type _rng;
  result_type _factor;
};

#ifndef STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
//  A definition is required even for integral static constants
template<class UniformRandomNumberGenerator, class RealType>
const bool backward_compatible_uniform_01<UniformRandomNumberGenerator, RealType>::has_fixed_range;
#endif

template<class UniformRandomNumberGenerator>
struct select_uniform_01
{
  template<class RealType>
  struct apply
  {
    typedef backward_compatible_uniform_01<UniformRandomNumberGenerator, RealType> type;
  };
};

template<>
struct select_uniform_01<float>
{
  template<class RealType>
  struct apply
  {
    typedef new_uniform_01<float> type;
  };
};

template<>
struct select_uniform_01<double>
{
  template<class RealType>
  struct apply
  {
    typedef new_uniform_01<double> type;
  };
};

template<>
struct select_uniform_01<long double>
{
  template<class RealType>
  struct apply
  {
    typedef new_uniform_01<long double> type;
  };
};

}

// Because it is so commonly used: uniform distribution on the real [0..1)
// range.  This allows for specializations to avoid a costly int -> float
// conversion plus float multiplication
template<class UniformRandomNumberGenerator = double, class RealType = double>
class uniform_01
  : public detail::select_uniform_01<UniformRandomNumberGenerator>::STREAMS_BOOST_NESTED_TEMPLATE apply<RealType>::type
{
  typedef typename detail::select_uniform_01<UniformRandomNumberGenerator>::STREAMS_BOOST_NESTED_TEMPLATE apply<RealType>::type impl_type;
  typedef streams_boost::random::detail::ptr_helper<UniformRandomNumberGenerator> traits;
public:

  uniform_01() {}

  explicit uniform_01(typename traits::rvalue_type rng)
    : impl_type(rng)
  {
  }

#if !defined(STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE) && !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
  template<class CharT, class Traits>
  friend std::basic_ostream<CharT,Traits>&
  operator<<(std::basic_ostream<CharT,Traits>& os, const uniform_01& u)
  {
    os << static_cast<const impl_type&>(u);
    return os;
  }

  template<class CharT, class Traits>
  friend std::basic_istream<CharT,Traits>&
  operator>>(std::basic_istream<CharT,Traits>& is, uniform_01& u)
  {
    is >> static_cast<impl_type&>(u);
    return is;
  }
#endif
};

} // namespace streams_boost

#include <streams_boost/random/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_RANDOM_UNIFORM_01_HPP
