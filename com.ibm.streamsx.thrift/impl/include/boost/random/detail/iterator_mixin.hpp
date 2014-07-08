/* streams_boost random/detail/iterator_mixin.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * Revision history
 */

#ifndef STREAMS_BOOST_ITERATOR_MIXIN_HPP
#define STREAMS_BOOST_ITERATOR_MIXIN_HPP

#include <streams_boost/operators.hpp>

namespace streams_boost {

// must be in streams_boost namespace, otherwise the inline friend trick fails
template<class Generator, class ResultType>
class generator_iterator_mixin_adapter
  : incrementable<Generator>, equality_comparable<Generator>
{
public:
  typedef std::input_iterator_tag iterator_category;
  typedef ResultType value_type;
  typedef std::ptrdiff_t difference_type;
  typedef const value_type * pointer;
  typedef const value_type & reference;
  Generator& operator++() { v = cast()(); return cast(); }
  const value_type& operator*() const { return v; }

protected:
  // instantiate from derived classes only
  generator_iterator_mixin_adapter() { }
  void iterator_init() { operator++(); }
private:
  Generator & cast() { return static_cast<Generator&>(*this); }
  value_type v;
};

} // namespace streams_boost

#endif // STREAMS_BOOST_ITERATOR_MIXIN_HPP
