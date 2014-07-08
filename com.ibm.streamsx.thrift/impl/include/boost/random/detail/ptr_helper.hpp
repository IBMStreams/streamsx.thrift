/* streams_boost random/detail/ptr_helper.hpp header file
 *
 * Copyright Jens Maurer 2002
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: ptr_helper.hpp 24096 2004-07-27 03:43:34Z dgregor $
 *
 */

#ifndef STREAMS_BOOST_RANDOM_DETAIL_PTR_HELPER_HPP
#define STREAMS_BOOST_RANDOM_DETAIL_PTR_HELPER_HPP

#include <streams_boost/config.hpp>


namespace streams_boost {
namespace random {
namespace detail {

// type_traits could help here, but I don't want to depend on type_traits.
template<class T>
struct ptr_helper
{
  typedef T value_type;
  typedef T& reference_type;
  typedef const T& rvalue_type;
  static reference_type ref(T& r) { return r; }
  static const T& ref(const T& r) { return r; }
};

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template<class T>
struct ptr_helper<T&>
{
  typedef T value_type;
  typedef T& reference_type;
  typedef T& rvalue_type;
  static reference_type ref(T& r) { return r; }
  static const T& ref(const T& r) { return r; }
};

template<class T>
struct ptr_helper<T*>
{
  typedef T value_type;
  typedef T& reference_type;
  typedef T* rvalue_type;
  static reference_type ref(T * p) { return *p; }
  static const T& ref(const T * p) { return *p; }
};
#endif

} // namespace detail
} // namespace random
} // namespace streams_boost

//
// STREAMS_BOOST_RANDOM_PTR_HELPER_SPEC --
//
//  Helper macro for broken compilers defines specializations of
//  ptr_helper.
//
#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
# define STREAMS_BOOST_RANDOM_PTR_HELPER_SPEC(T)                \
namespace streams_boost { namespace random { namespace detail { \
template<>                                              \
struct ptr_helper<T&>                                   \
{                                                       \
  typedef T value_type;                                 \
  typedef T& reference_type;                            \
  typedef T& rvalue_type;                               \
  static reference_type ref(T& r) { return r; }         \
  static const T& ref(const T& r) { return r; }         \
};                                                      \
                                                        \
template<>                                              \
struct ptr_helper<T*>                                   \
{                                                       \
  typedef T value_type;                                 \
  typedef T& reference_type;                            \
  typedef T* rvalue_type;                               \
  static reference_type ref(T * p) { return *p; }       \
  static const T& ref(const T * p) { return *p; }       \
};                                                      \
}}}
#else
# define STREAMS_BOOST_RANDOM_PTR_HELPER_SPEC(T)
#endif 

#endif // STREAMS_BOOST_RANDOM_DETAIL_PTR_HELPER_HPP
