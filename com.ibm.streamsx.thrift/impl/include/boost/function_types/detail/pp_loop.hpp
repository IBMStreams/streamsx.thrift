
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusions

#ifndef STREAMS_BOOST_FT_DETAIL_PP_LOOP_HPP_INCLUDED
#define STREAMS_BOOST_FT_DETAIL_PP_LOOP_HPP_INCLUDED
#   include <streams_boost/preprocessor/facilities/expand.hpp>
#   include <streams_boost/preprocessor/facilities/empty.hpp>
#   include <streams_boost/preprocessor/punctuation/paren.hpp>
#endif

#include <streams_boost/function_types/detail/encoding/def.hpp>
#include <streams_boost/function_types/detail/encoding/aliases_def.hpp>

#if defined(STREAMS_BOOST_FT_PREPROCESSING_MODE)
#   define STREAMS_BOOST_FT_loop <streams_boost/function_types/detail/pp_cc_loop/master.hpp>
#else
#   define STREAMS_BOOST_FT_loop \
        <streams_boost/function_types/detail/pp_cc_loop/preprocessed.hpp>
#endif

#if defined(STREAMS_BOOST_FT_al_path)

#   define STREAMS_BOOST_FT_cc_file \
        <streams_boost/function_types/detail/pp_variate_loop/preprocessed.hpp>
#   define STREAMS_BOOST_FT_variate_file \
        <streams_boost/function_types/detail/pp_arity_loop.hpp>

#   ifndef STREAMS_BOOST_FT_type_function
#   define STREAMS_BOOST_FT_type_function(cc,name) STREAMS_BOOST_FT_SYNTAX( \
      R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_EMPTY,cc,STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_EMPTY)
#   endif
#   ifndef STREAMS_BOOST_FT_type_function_pointer
#   define STREAMS_BOOST_FT_type_function_pointer(cc,name) STREAMS_BOOST_FT_SYNTAX( \
      R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_LPAREN,cc,* STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_RPAREN)
#   endif
#   ifndef STREAMS_BOOST_FT_type_function_reference
#   define STREAMS_BOOST_FT_type_function_reference(cc,name) STREAMS_BOOST_FT_SYNTAX( \
      R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_LPAREN,cc,& STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_RPAREN)
#   endif
#   ifndef STREAMS_BOOST_FT_type_member_function_pointer
#   define STREAMS_BOOST_FT_type_member_function_pointer(cc,name) STREAMS_BOOST_FT_SYNTAX( \
      R STREAMS_BOOST_PP_EMPTY,STREAMS_BOOST_PP_LPAREN,cc,T0::* STREAMS_BOOST_PP_EMPTY,name,STREAMS_BOOST_PP_RPAREN)
#   endif

#   include STREAMS_BOOST_FT_loop

#   undef STREAMS_BOOST_FT_type_function
#   undef STREAMS_BOOST_FT_type_function_pointer
#   undef STREAMS_BOOST_FT_type_function_reference
#   undef STREAMS_BOOST_FT_type_member_function_pointer

#   undef STREAMS_BOOST_FT_variations
#   undef STREAMS_BOOST_FT_variate_file
#   undef STREAMS_BOOST_FT_cc_file
#   undef STREAMS_BOOST_FT_al_path

#elif defined(STREAMS_BOOST_FT_cc_file)

#   include STREAMS_BOOST_FT_loop
#   undef STREAMS_BOOST_FT_cc_file

#else

#   error "argument missing"

#endif

#undef STREAMS_BOOST_FT_loop

#include <streams_boost/function_types/detail/encoding/aliases_undef.hpp>
#include <streams_boost/function_types/detail/encoding/undef.hpp>


