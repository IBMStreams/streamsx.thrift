// Copyright (C) 2003, Fernando Luis Cacciola Carballal.
// Copyright (C) 2007, Tobias Schwinger.
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/lib/optional for documentation.
//
// You are welcome to contact the author at:
//  fernando_cacciola@hotmail.com
//
#ifndef STREAMS_BOOST_UTILITY_TYPED_INPLACE_FACTORY_04APR2007_HPP
#ifndef STREAMS_BOOST_PP_IS_ITERATING

#include <streams_boost/utility/detail/in_place_factory_prefix.hpp>

namespace streams_boost {

class typed_in_place_factory_base {} ;

#define  STREAMS_BOOST_PP_ITERATION_LIMITS (0, STREAMS_BOOST_MAX_INPLACE_FACTORY_ARITY)
#define  STREAMS_BOOST_PP_FILENAME_1 <streams_boost/utility/typed_in_place_factory.hpp>
#include STREAMS_BOOST_PP_ITERATE()

} // namespace streams_boost

#include <streams_boost/utility/detail/in_place_factory_suffix.hpp>

#define STREAMS_BOOST_UTILITY_TYPED_INPLACE_FACTORY_04APR2007_HPP
#else 
#define N STREAMS_BOOST_PP_ITERATION()

template< class T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N,class A) >
class STREAMS_BOOST_PP_CAT(typed_in_place_factory,N) 
  : 
  public typed_in_place_factory_base
{
public:

  typedef T value_type;

  explicit STREAMS_BOOST_PP_CAT(typed_in_place_factory,N) 
      ( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& a) )
#if N > 0
    : STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_DEFINE_INPLACE_FACTORY_CLASS_MEMBER_INIT, _)
#endif
  {}

  void* apply (void* address) const
  {
    return new(address) T( STREAMS_BOOST_PP_ENUM_PARAMS(N, m_a) );
  }

  void* apply (void* address, std::size_t n) const
  {
    for(void* next = address = this->apply(address); !! --n;)
      this->apply(next = static_cast<char *>(next) + sizeof(T));
    return address; 
  }

  STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_DEFINE_INPLACE_FACTORY_CLASS_MEMBER_DECL, _)
};

template< class T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, class A) >
inline STREAMS_BOOST_PP_CAT(typed_in_place_factory,N)<
    T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, A) >
in_place( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& a) )
{
  return STREAMS_BOOST_PP_CAT(typed_in_place_factory,N)< 
      T STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, A) >( STREAMS_BOOST_PP_ENUM_PARAMS(N, a) );
}

#undef N
#endif
#endif

