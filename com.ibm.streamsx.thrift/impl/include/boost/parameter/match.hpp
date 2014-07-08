// Copyright David Abrahams 2005. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_PARAMETER_MATCH_DWA2005714_STREAMS_HPP
# define STREAMS_BOOST_PARAMETER_MATCH_DWA2005714_STREAMS_HPP

# include <streams_boost/detail/workaround.hpp>
# include <streams_boost/preprocessor/seq/enum.hpp>

# if STREAMS_BOOST_WORKAROUND(__MWERKS__, <= 0x3003)
// Temporary version of STREAMS_BOOST_PP_SEQ_ENUM until Paul M. integrates the workaround.
#  define STREAMS_BOOST_PARAMETER_SEQ_ENUM_I(size,seq) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_SEQ_ENUM_, size) seq
#  define STREAMS_BOOST_PARAMETER_SEQ_ENUM(seq) STREAMS_BOOST_PARAMETER_SEQ_ENUM_I(STREAMS_BOOST_PP_SEQ_SIZE(seq), seq)
# else
#  define STREAMS_BOOST_PARAMETER_SEQ_ENUM(seq) STREAMS_BOOST_PP_SEQ_ENUM(seq)
# endif 

# if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))

#  include <streams_boost/parameter/config.hpp>
#  include <streams_boost/parameter/aux_/void.hpp>
#  include <streams_boost/preprocessor/arithmetic/sub.hpp>
#  include <streams_boost/preprocessor/facilities/intercept.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

#  define STREAMS_BOOST_PARAMETER_MATCH_DEFAULTS(ArgTypes)              \
        STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(                          \
            STREAMS_BOOST_PP_SUB(                                       \
                STREAMS_BOOST_PARAMETER_MAX_ARITY                       \
              , STREAMS_BOOST_PP_SEQ_SIZE(ArgTypes)                     \
            )                                                   \
          , ::streams_boost::parameter::void_ STREAMS_BOOST_PP_INTERCEPT   \
        )

# else

#  define STREAMS_BOOST_PARAMETER_MATCH_DEFAULTS(ArgTypes)

# endif 

//
// Generates, e.g.
//
//    typename dfs_params::match<A1,A2>::type name = dfs_params()
//
// with workarounds for Borland compatibility.
//

# define STREAMS_BOOST_PARAMETER_MATCH(ParameterSpec, ArgTypes, name)   \
    typename ParameterSpec ::match<                             \
        STREAMS_BOOST_PARAMETER_SEQ_ENUM(ArgTypes)                      \
        STREAMS_BOOST_PARAMETER_MATCH_DEFAULTS(ArgTypes)                \
    >::type name = ParameterSpec ()

#endif // STREAMS_BOOST_PARAMETER_MATCH_DWA2005714_STREAMS_HPP
