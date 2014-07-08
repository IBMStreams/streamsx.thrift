// Copyright Daniel Wallin 2005. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_FLATTEN_051217_HPP
# define STREAMS_BOOST_PARAMETER_FLATTEN_051217_HPP

# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/preprocessor/tuple/rem.hpp>
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/seq/for_each.hpp>
# include <streams_boost/preprocessor/seq/for_each_i.hpp>
# include <streams_boost/preprocessor/identity.hpp>
# include <streams_boost/preprocessor/selection/max.hpp>
# include <streams_boost/preprocessor/arithmetic/sub.hpp>
# include <streams_boost/preprocessor/repetition/enum_trailing.hpp>
# include <streams_boost/parameter/aux_/preprocessor/for_each.hpp>

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT_required required,
# define STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT_optional optional,
# define STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT_deduced deduced,

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT(sub) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT_, sub)

# define STREAMS_BOOST_PARAMETER_FLATTEN_QUALIFIER(sub) \
    STREAMS_BOOST_PP_SPLIT(0, STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT(sub))

# define STREAMS_BOOST_PARAMETER_FLATTEN_ARGS(sub) \
    STREAMS_BOOST_PP_SPLIT(1, STREAMS_BOOST_PARAMETER_FLATTEN_SPLIT(sub))

# define STREAMS_BOOST_PARAMETER_FLATTEN_ARITY_optional(arities) \
    STREAMS_BOOST_PP_TUPLE_ELEM(3,0,arities)

# define STREAMS_BOOST_PARAMETER_FLATTEN_ARITY_required(arities) \
    STREAMS_BOOST_PP_TUPLE_ELEM(3,1,arities)

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC0_DUMMY_ELEM(z, n, data) ~
# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC0(r, n, elem, data) \
    (( \
        STREAMS_BOOST_PP_TUPLE_ELEM(3,2,data) \
      , STREAMS_BOOST_PP_TUPLE_REM(STREAMS_BOOST_PP_TUPLE_ELEM(3,0,data)) elem \
        STREAMS_BOOST_PP_ENUM_TRAILING( \
            STREAMS_BOOST_PP_SUB( \
                STREAMS_BOOST_PP_TUPLE_ELEM(3,1,data) \
              , STREAMS_BOOST_PP_TUPLE_ELEM(3,0,data) \
            ) \
          , STREAMS_BOOST_PARAMETER_FLATTEN_SPEC0_DUMMY_ELEM \
          , ~ \
        ) \
    ))

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_AUX(r, arity, max_arity, spec, transform) \
    STREAMS_BOOST_PARAMETER_FOR_EACH_R( \
        r \
      , arity \
      , STREAMS_BOOST_PARAMETER_FLATTEN_ARGS(spec) \
      , (arity, max_arity, transform(STREAMS_BOOST_PARAMETER_FLATTEN_QUALIFIER(spec))) \
      , STREAMS_BOOST_PARAMETER_FLATTEN_SPEC0 \
    )

# define STREAMS_BOOST_PARAMETER_FLATTEN_IDENTITY(x) x

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_optional(r, arities, spec) \
    STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_AUX( \
        r \
      , STREAMS_BOOST_PP_CAT( \
            STREAMS_BOOST_PARAMETER_FLATTEN_ARITY_, STREAMS_BOOST_PARAMETER_FLATTEN_QUALIFIER(spec) \
        )(arities) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(3,2,arities) \
      , spec \
      , STREAMS_BOOST_PARAMETER_FLATTEN_IDENTITY \
    )

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_required(r, arities, spec) \
    STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_optional(r, arities, spec)

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_AS_DEDUCED(x) STREAMS_BOOST_PP_CAT(deduced_,x)

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_deduced_M(r, arities, n, spec) \
    STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_AUX( \
        r \
      , STREAMS_BOOST_PP_CAT( \
            STREAMS_BOOST_PARAMETER_FLATTEN_ARITY_, STREAMS_BOOST_PARAMETER_FLATTEN_QUALIFIER(spec) \
        )(arities) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(3,2,arities) \
      , spec \
      , STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_AS_DEDUCED \
    )

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_deduced(r, arities, spec) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R( \
        r \
      , STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_deduced_M \
      , arities \
      , STREAMS_BOOST_PARAMETER_FLATTEN_ARGS(spec) \
    )

# define STREAMS_BOOST_PARAMETER_FLATTEN_SPEC(r, arities, spec) \
    STREAMS_BOOST_PP_CAT( \
        STREAMS_BOOST_PARAMETER_FLATTEN_SPEC_, STREAMS_BOOST_PARAMETER_FLATTEN_QUALIFIER(spec) \
    )(r, arities, spec)

# define STREAMS_BOOST_PARAMETER_FLATTEN(optional_arity, required_arity, wanted_arity, specs) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH( \
        STREAMS_BOOST_PARAMETER_FLATTEN_SPEC \
      , ( \
            optional_arity, required_arity \
          , wanted_arity \
        ) \
      , specs \
    )

#endif // STREAMS_BOOST_PARAMETER_FLATTEN_051217_HPP

