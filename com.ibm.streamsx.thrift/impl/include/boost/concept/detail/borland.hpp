// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_STREAMS_HPP

# include <streams_boost/preprocessor/cat.hpp>

namespace streams_boost { namespace concept {

template <class ModelFnPtr>
struct require;

template <class Model>
struct require<void(*)(Model)>
{
    enum { instantiate = sizeof((((Model*)0)->~Model()), 3) };
};

#  define STREAMS_BOOST_CONCEPT_ASSERT_FN( ModelFnPtr )         \
  enum                                                  \
  {                                                     \
      STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__) =      \
      streams_boost::concept::require<ModelFnPtr>::instantiate  \
  }

}} // namespace streams_boost::concept

#endif // STREAMS_BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_STREAMS_HPP
