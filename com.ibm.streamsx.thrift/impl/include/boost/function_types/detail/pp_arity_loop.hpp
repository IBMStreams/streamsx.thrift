
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#ifndef STREAMS_BOOST_FT_PREPROCESSING_MODE
// input:  STREAMS_BOOST_FT_mfp        0 or 1 <=> member function pointer?
// input:  STREAMS_BOOST_FT_type_name  STREAMS_BOOST_FT_type --> "R (* ..._type_name)()" (pass2)
#endif
// input:  STREAMS_BOOST_FT_syntax     type macro to use
// input:  STREAMS_BOOST_FT_cc         empty or cc specifier 
// input:  STREAMS_BOOST_FT_ell        empty or "..."
// input:  STREAMS_BOOST_FT_cv         empty or cv qualifiers
// input:  STREAMS_BOOST_FT_flags      single decimal integer encoding the flags
// output: STREAMS_BOOST_FT_n          number of component types (arity+1)
// output: STREAMS_BOOST_FT_arity      current arity
// output: STREAMS_BOOST_FT_type       macro that expands to the type
// output: STREAMS_BOOST_FT_tplargs(p) template arguments with given prefix
// output: STREAMS_BOOST_FT_params(p)  parameters with given prefix

#ifdef __WAVE__
#   pragma wave option(preserve: 0)
#endif

#ifndef STREAMS_BOOST_FT_ARITY_LOOP_IS_ITERATING

#   define STREAMS_BOOST_FT_AL_PREPROCESSED \
        STREAMS_BOOST_FT_AL_FILE(STREAMS_BOOST_FT_al_path,STREAMS_BOOST_FT_FROM_ARITY,STREAMS_BOOST_FT_mfp)

#   define STREAMS_BOOST_FT_AL_FILE(base_path,max_arity,mfp) \
        STREAMS_BOOST_FT_AL_FILE_I(base_path,max_arity,mfp)
#   define STREAMS_BOOST_FT_AL_FILE_I(base_path,max_arity,mfp) \
        <base_path/arity ## max_arity ## _ ## mfp.hpp>

#   if !defined(STREAMS_BOOST_FT_PREPROCESSING_MODE)

#     if STREAMS_BOOST_FT_MAX_ARITY < 10
#       define STREAMS_BOOST_FT_FROM_ARITY 0 
#     elif STREAMS_BOOST_FT_MAX_ARITY < 20
#       define STREAMS_BOOST_FT_FROM_ARITY 10
#     elif STREAMS_BOOST_FT_MAX_ARITY < 30
#       define STREAMS_BOOST_FT_FROM_ARITY 20
#     elif STREAMS_BOOST_FT_MAX_ARITY < 40
#       define STREAMS_BOOST_FT_FROM_ARITY 30
#     endif

#     if STREAMS_BOOST_FT_FROM_ARITY
#       include STREAMS_BOOST_FT_AL_PREPROCESSED
#     endif

#   elif !defined(STREAMS_BOOST_FT_FROM_ARITY) // single pass preprocessing
#     define STREAMS_BOOST_FT_FROM_ARITY 0

#   elif STREAMS_BOOST_FT_FROM_ARITY > 0       // arity20 includes arity10
STREAMS_BOOST_PP_EXPAND(#) include STREAMS_BOOST_FT_AL_PREPROCESSED
#   endif

#   undef STREAMS_BOOST_FT_AL_PREPROCESSED

#   undef STREAMS_BOOST_FT_AL_FILE
#   undef STREAMS_BOOST_FT_AL_FILE_I

#   if STREAMS_BOOST_FT_MAX_ARITY > STREAMS_BOOST_FT_FROM_ARITY

#     ifndef STREAMS_BOOST_FT_DETAIL_ARITY_LOOP_HPP_INCLUDED
#     define STREAMS_BOOST_FT_DETAIL_ARITY_LOOP_HPP_INCLUDED
#         include <streams_boost/preprocessor/cat.hpp>
#         include <streams_boost/preprocessor/tuple/eat.hpp>
#         include <streams_boost/preprocessor/control/if.hpp>
#         include <streams_boost/preprocessor/arithmetic/inc.hpp>
#         include <streams_boost/preprocessor/facilities/empty.hpp>
#         include <streams_boost/preprocessor/facilities/expand.hpp>
#         include <streams_boost/preprocessor/iteration/iterate.hpp>
#         include <streams_boost/preprocessor/repetition/enum_params.hpp>
#         include <streams_boost/preprocessor/repetition/enum_shifted_params.hpp>
#         include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#     endif

#     define STREAMS_BOOST_FT_AL_INCLUDE_FILE <STREAMS_BOOST_FT_al_path/master.hpp>

#     define STREAMS_BOOST_FT_ARITY_LOOP_PREFIX 1
#     include STREAMS_BOOST_FT_AL_INCLUDE_FILE
#     undef  STREAMS_BOOST_FT_ARITY_LOOP_PREFIX

#     if !STREAMS_BOOST_PP_IS_ITERATING
#       define STREAMS_BOOST_PP_FILENAME_1 STREAMS_BOOST_FT_AL_INCLUDE_FILE
#     elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 1
#       define STREAMS_BOOST_PP_FILENAME_2 STREAMS_BOOST_FT_AL_INCLUDE_FILE
#     else
#       error "loops nested too deeply"
#     endif

#     define STREAMS_BOOST_FT_arity STREAMS_BOOST_PP_ITERATION()
#     define STREAMS_BOOST_FT_n     STREAMS_BOOST_PP_INC(STREAMS_BOOST_FT_arity)

#     define STREAMS_BOOST_FT_type \
          STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc,STREAMS_BOOST_FT_type_name STREAMS_BOOST_PP_EMPTY)\
               (STREAMS_BOOST_FT_params(STREAMS_BOOST_PP_EMPTY) STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv

#     define STREAMS_BOOST_FT_tplargs(prefx) \
          prefx() R STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(STREAMS_BOOST_FT_arity,prefx() T)

#     if !STREAMS_BOOST_FT_mfp

#       define STREAMS_BOOST_FT_params(prefx) \
            STREAMS_BOOST_PP_IF(STREAMS_BOOST_FT_arity,STREAMS_BOOST_PP_ENUM_PARAMS, \
                STREAMS_BOOST_FT_nullary_param STREAMS_BOOST_PP_TUPLE_EAT(2))( \
                    STREAMS_BOOST_FT_arity,prefx() T) 
#     else

#       define STREAMS_BOOST_FT_params(prefx) \
            STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_FT_arity,prefx() T)

#     endif

#     if !STREAMS_BOOST_FT_FROM_ARITY 
#       define STREAMS_BOOST_PP_ITERATION_LIMITS (STREAMS_BOOST_FT_mfp, STREAMS_BOOST_FT_MAX_ARITY)
#     else
#       define STREAMS_BOOST_PP_ITERATION_LIMITS \
            (STREAMS_BOOST_FT_FROM_ARITY+1, STREAMS_BOOST_FT_MAX_ARITY)
#     endif

#     define STREAMS_BOOST_FT_ARITY_LOOP_IS_ITERATING 1
#     include STREAMS_BOOST_PP_ITERATE()
#     undef  STREAMS_BOOST_FT_ARITY_LOOP_IS_ITERATING

#     undef STREAMS_BOOST_FT_arity
#     undef STREAMS_BOOST_FT_params
#     undef STREAMS_BOOST_FT_tplargs
#     undef STREAMS_BOOST_FT_type

#     define STREAMS_BOOST_FT_ARITY_LOOP_SUFFIX 1
#     include STREAMS_BOOST_FT_AL_INCLUDE_FILE
#     undef  STREAMS_BOOST_FT_ARITY_LOOP_SUFFIX

#     undef STREAMS_BOOST_FT_AL_INCLUDE_FILE
#   endif

#   undef STREAMS_BOOST_FT_FROM_ARITY

#else
#   error "attempt to nest arity loops"
#endif

