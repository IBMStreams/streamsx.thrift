// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_DETAIL_GENERAL_DWA2006429_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_DETAIL_GENERAL_DWA2006429_STREAMS_HPP

# include <streams_boost/preprocessor/cat.hpp>

# ifdef STREAMS_BOOST_OLD_CONCEPT_SUPPORT
#  include <streams_boost/concept/detail/has_constraints.hpp>
#  include <streams_boost/mpl/if.hpp>
# endif

// This implementation works on Comeau and GCC, all the way back to
// 2.95
namespace streams_boost { namespace concept {

template <class ModelFn>
struct requirement_;

namespace detail
{
  template <void(*)()> struct instantiate {};
}

template <class Model>
struct requirement
{
    static void failed() { ((Model*)0)->~Model(); }
};

# ifdef STREAMS_BOOST_OLD_CONCEPT_SUPPORT

template <class Model>
struct constraint
{
    static void failed() { ((Model*)0)->constraints(); }
};
  
template <class Model>
struct requirement_<void(*)(Model)>
  : mpl::if_<
        concept::not_satisfied<Model>
      , constraint<Model>
      , requirement<Model>
    >::type
{};
  
# else

// For GCC-2.x, these can't have exactly the same name
template <class Model>
struct requirement_<void(*)(Model)>
  : requirement<Model>
{};
  
# endif

#  define STREAMS_BOOST_CONCEPT_ASSERT_FN( ModelFnPtr )             \
    typedef ::streams_boost::concept::detail::instantiate<          \
    &::streams_boost::concept::requirement_<ModelFnPtr>::failed>    \
      STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__)

}}

#endif // STREAMS_BOOST_CONCEPT_DETAIL_GENERAL_DWA2006429_STREAMS_HPP
