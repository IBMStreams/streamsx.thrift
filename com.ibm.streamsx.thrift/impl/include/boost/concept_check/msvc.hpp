// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_CHECK_MSVC_DWA2006429_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_CHECK_MSVC_DWA2006429_STREAMS_HPP

# ifdef STREAMS_BOOST_OLD_CONCEPT_SUPPORT
#  include <streams_boost/concept_check/has_constraints.hpp>
#  include <streams_boost/mpl/if.hpp>
# endif


namespace streams_boost
{
  namespace concept_checking
  {
    template <class Model>
    struct concept_check_
    {
        virtual void failed(Model* x)
        {
            x->~Model();
        }
    };
  }
  
# ifdef STREAMS_BOOST_OLD_CONCEPT_SUPPORT
  
  namespace concept_checking
  {
    template <class Model>
    struct constraint_check
    {
        virtual void failed(Model* x)
        {
            x->constraints();
        }
    };
  }

  template <class Model>
  struct concept_check
    : mpl::if_c<
          concept_checking::has_constraints<Model>::value
        , concept_checking::constraint_check<Model>
        , concept_checking::concept_check_<Model>
      >::type
  {};
      
# else
  
  template <class Model>
  struct concept_check
    : concept_checking::concept_check_<Model>
  {};
  
# endif

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1310)

  //
  // The iterator library sees some really strange errors unless we
  // use partial specialization to extract the model type with
  // msvc-7.1
  // 
  template <class Model>
  struct concept_check<void(*)(Model)>
    : concept_check<Model>
  { };

# define STREAMS_BOOST_CONCEPT_ASSERT( ModelInParens )                          \
  enum { STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__) =                   \
         sizeof(::streams_boost::concept_check<void(*) ModelInParens>)          \
  }
  
# else
  
  template <class Model>
  concept_check<Model>
  concept_check_(void(*)(Model));
  
# define STREAMS_BOOST_CONCEPT_ASSERT( ModelInParens )                          \
  enum { STREAMS_BOOST_PP_CAT(streams_boost_concept_check,__LINE__) =                   \
         sizeof(::streams_boost::concept_check_((void(*) ModelInParens)0))      \
  }
  
# endif 
}

#endif // STREAMS_BOOST_CONCEPT_CHECK_MSVC_DWA2006429_STREAMS_HPP
