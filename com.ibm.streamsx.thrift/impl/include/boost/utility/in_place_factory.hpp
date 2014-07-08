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
#ifndef STREAMS_BOOST_UTILITY_INPLACE_FACTORY_04APR2007_HPP
#ifndef STREAMS_BOOST_PP_IS_ITERATING

#include <streams_boost/utility/detail/in_place_factory_prefix.hpp>

namespace streams_boost {

class in_place_factory_base {} ;

#define  STREAMS_BOOST_PP_ITERATION_LIMITS (0, STREAMS_BOOST_MAX_INPLACE_FACTORY_ARITY)
#define  STREAMS_BOOST_PP_FILENAME_1 <streams_boost/utility/in_place_factory.hpp>
#include STREAMS_BOOST_PP_ITERATE()

} // namespace streams_boost

#include <streams_boost/utility/detail/in_place_factory_suffix.hpp>

#define STREAMS_BOOST_UTILITY_INPLACE_FACTORY_04APR2007_HPP
#else
#define N STREAMS_BOOST_PP_ITERATION()

#if N
template< STREAMS_BOOST_PP_ENUM_PARAMS(N, class A) >
#endif
class STREAMS_BOOST_PP_CAT(in_place_factory,N)
  : 
  public in_place_factory_base
{
public:

  explicit STREAMS_BOOST_PP_CAT(in_place_factory,N)
      ( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N,A,const& a) )
#if N > 0
    : STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_DEFINE_INPLACE_FACTORY_CLASS_MEMBER_INIT, _)
#endif
  {}

  template<class T>
  void* apply(void* address
      STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(T)) const
  {
    return new(address) T( STREAMS_BOOST_PP_ENUM_PARAMS(N, m_a) );
  }

  template<class T>
  void* apply(void* address, std::size_t n
      STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(T)) const
  {
    for(char* next = address = this->STREAMS_BOOST_NESTED_TEMPLATE apply<T>(address);
        !! --n;)
      this->STREAMS_BOOST_NESTED_TEMPLATE apply<T>(next = next+sizeof(T));
    return address; 
  }

  STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_DEFINE_INPLACE_FACTORY_CLASS_MEMBER_DECL, _)
};

#if N > 0
template< STREAMS_BOOST_PP_ENUM_PARAMS(N, class A) >
inline STREAMS_BOOST_PP_CAT(in_place_factory,N)< STREAMS_BOOST_PP_ENUM_PARAMS(N, A) >
in_place( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& a) )
{
  return STREAMS_BOOST_PP_CAT(in_place_factory,N)< STREAMS_BOOST_PP_ENUM_PARAMS(N, A) >
      ( STREAMS_BOOST_PP_ENUM_PARAMS(N, a) );
}
#else
inline in_place_factory0 in_place()
{
  return in_place_factory0();
}
#endif

#undef N
#endif
#endif

