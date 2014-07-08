// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_CHECK_BORLAND_DWA2006429_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_CHECK_BORLAND_DWA2006429_STREAMS_HPP

namespace streams_boost {

template <class ModelFn>
struct concept_check;

template <class Model>
struct concept_check<void(*)(Model)>
{
    enum { instantiate = sizeof((((Model*)0)->~Model()), 3) };
};

#  define STREAMS_BOOST_CONCEPT_ASSERT( ModelInParens )                     \
  enum { STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__) =               \
         streams_boost::concept_check<void(*)ModelInParens>::instantiate    \
  }

} // namespace streams_boost::concept_checking

#endif // STREAMS_BOOST_CONCEPT_CHECK_BORLAND_DWA2006429_STREAMS_HPP
