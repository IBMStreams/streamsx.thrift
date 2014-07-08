// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_CHECK_MSVC_DWA2006429_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_CHECK_MSVC_DWA2006429_STREAMS_HPP

# include <streams_boost/preprocessor/cat.hpp>

# ifdef STREAMS_BOOST_OLD_CONCEPT_SUPPORT
#  include <streams_boost/concept/detail/has_constraints.hpp>
#  include <streams_boost/mpl/if.hpp>
# endif


namespace streams_boost { namespace concept {

template <class Model>
struct check
{
    virtual void failed(Model* x)
    {
        x->~Model();
    }
};
  
# ifdef STREAMS_BOOST_OLD_CONCEPT_SUPPORT
  
namespace detail
{
  // No need for a virtual function here, since evaluating
  // not_satisfied below will have already instantiated the
  // constraints() member.
  struct constraint {};
}

template <class Model>
struct require
  : mpl::if_c<
        not_satisfied<Model>::value
      , detail::constraint
      , check<Model>
        >::type
{};
      
# else
  
template <class Model>
struct require
  : check<Model>
{};
  
# endif
    
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1310)

//
// The iterator library sees some really strange errors unless we
// do things this way.
//
template <class Model>
struct require<void(*)(Model)>
{
    virtual void failed(Model*)
    {
        require<Model>();
    }
};

# define STREAMS_BOOST_CONCEPT_ASSERT_FN( ModelFnPtr )      \
enum                                                \
{                                                   \
    STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__) =    \
    sizeof(::streams_boost::concept::require<ModelFnPtr>)    \
}
  
# else // Not vc-7.1
  
template <class Model>
require<Model>
require_(void(*)(Model));
  
# define STREAMS_BOOST_CONCEPT_ASSERT_FN( ModelFnPtr )          \
enum                                                    \
{                                                       \
    STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__) =        \
      sizeof(::streams_boost::concept::require_((ModelFnPtr)0)) \
}
  
# endif
}}

#endif // STREAMS_BOOST_CONCEPT_CHECK_MSVC_DWA2006429_STREAMS_HPP
