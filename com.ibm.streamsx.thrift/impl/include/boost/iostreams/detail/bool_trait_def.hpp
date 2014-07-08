// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED     

#include <streams_boost/config.hpp> // STREAMS_BOOST_STATIC_CONSTANT.
#include <streams_boost/iostreams/detail/template_params.hpp>
#include <streams_boost/mpl/aux_/lambda_support.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/type_traits/detail/yes_no_type.hpp>
 
// 
// Macro name: STREAMS_BOOST_IOSTREAMS_BOOL_TRAIT_DEF
// Description: Used to generate the traits classes is_istream, is_ostream,
//      etc.
//
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x582))
# define STREAMS_BOOST_IOSTREAMS_TRAIT_NAMESPACE(trait)
#else
# define STREAMS_BOOST_IOSTREAMS_TRAIT_NAMESPACE(trait) STREAMS_BOOST_PP_CAT(trait, _impl_):: 
#endif
#define STREAMS_BOOST_IOSTREAMS_BOOL_TRAIT_DEF(trait, type, arity) \
    namespace STREAMS_BOOST_PP_CAT(trait, _impl_) { \
      STREAMS_BOOST_IOSTREAMS_TEMPLATE_PARAMS(arity, T) \
      type_traits::yes_type helper \
          (const volatile type STREAMS_BOOST_IOSTREAMS_TEMPLATE_ARGS(arity, T)*); \
      type_traits::no_type helper(...); \
      template<typename T> \
      struct impl { \
           STREAMS_BOOST_STATIC_CONSTANT(bool, value = \
           (sizeof(STREAMS_BOOST_IOSTREAMS_TRAIT_NAMESPACE(trait) \
              helper(static_cast<T*>(0))) == \
                sizeof(type_traits::yes_type))); \
      }; \
    } \
    template<typename T> \
    struct trait \
        : mpl::bool_<STREAMS_BOOST_PP_CAT(trait, _impl_)::impl<T>::value> \
    { STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1, trait, (T)) }; \
    /**/

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED
