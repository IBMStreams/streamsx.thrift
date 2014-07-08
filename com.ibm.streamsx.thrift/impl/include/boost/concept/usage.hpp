// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_USAGE_DWA2006919_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_USAGE_DWA2006919_STREAMS_HPP

# include <streams_boost/concept/assert.hpp>
# include <streams_boost/detail/workaround.hpp>

namespace streams_boost { namespace concept { 

# if STREAMS_BOOST_WORKAROUND(__GNUC__, == 2)

#  define STREAMS_BOOST_CONCEPT_USAGE(model) ~model()

# else 

template <class Model>
struct usage_requirements
{
    ~usage_requirements() { ((Model*)0)->~Model(); }
};

#  if STREAMS_BOOST_WORKAROUND(__GNUC__, <= 3)

#   define STREAMS_BOOST_CONCEPT_USAGE(model)                                    \
      model(); /* at least 2.96 and 3.4.3 both need this :( */           \
      STREAMS_BOOST_CONCEPT_ASSERT((streams_boost::concept::usage_requirements<model>)); \
      ~model()

#  else

#   define STREAMS_BOOST_CONCEPT_USAGE(model)                                    \
      STREAMS_BOOST_CONCEPT_ASSERT((streams_boost::concept::usage_requirements<model>)); \
      ~model()

#  endif

# endif 

}} // namespace streams_boost::concept

#endif // STREAMS_BOOST_CONCEPT_USAGE_DWA2006919_STREAMS_HPP