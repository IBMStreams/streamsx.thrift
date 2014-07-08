//  (C) Copyright Jeremy Siek 1999.
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_INT_ITERATOR_H
#define STREAMS_BOOST_INT_ITERATOR_H

#include <streams_boost/iterator.hpp>
#if !defined STREAMS_BOOST_MSVC
#include <streams_boost/operators.hpp>
#endif
#include <iostream>
//using namespace std;

#ifndef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE
namespace streams_boost {
#endif

// this should use random_access_iterator_helper but I've had
// VC++ portablility problems with that. -JGS
template <class IntT>
class int_iterator
{
  typedef int_iterator self;
public:
  typedef std::random_access_iterator_tag iterator_category;
  typedef IntT value_type;
  typedef IntT& reference;
  typedef IntT* pointer;
  typedef std::ptrdiff_t difference_type;

  inline int_iterator() : _i(0) { }
  inline int_iterator(IntT i) : _i(i) { }
  inline int_iterator(const self& x) : _i(x._i) { }
  inline self& operator=(const self& x) { _i = x._i; return *this; }
  inline IntT operator*() { return _i; }
  inline IntT operator[](IntT n) { return _i + n; }
  inline self& operator++() { ++_i; return *this; }
  inline self operator++(int) { self t = *this; ++_i; return t; }
  inline self& operator+=(IntT n) { _i += n; return *this; }
  inline self operator+(IntT n) { self t = *this; t += n; return t; }
  inline self& operator--() { --_i; return *this; }
  inline self operator--(int) { self t = *this; --_i; return t; }
  inline self& operator-=(IntT n) { _i -= n; return *this; }
  inline IntT operator-(const self& x) const { return _i - x._i; }
  inline bool operator==(const self& x) const { return _i == x._i; }
  // vc++ had a problem finding != in random_access_iterator_helper
  // need to look into this... for now implementing everything here -JGS
  inline bool operator!=(const self& x) const { return _i != x._i; }
  inline bool operator<(const self& x) const { return _i < x._i; }
  inline bool operator<=(const self& x) const { return _i <= x._i; }
  inline bool operator>(const self& x) const { return _i > x._i; }
  inline bool operator>=(const self& x) const { return _i >= x._i; }
protected:
  IntT _i;
};

template <class IntT>
inline int_iterator<IntT>
operator+(IntT n, int_iterator<IntT> t) { t += n; return t; }

#ifndef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE
} /* namespace streams_boost */
#endif

#ifdef STREAMS_BOOST_NO_OPERATORS_IN_NAMESPACE
namespace streams_boost {
  using ::int_iterator;
}
#endif


#endif /* STREAMS_BOOST_INT_ITERATOR_H */
