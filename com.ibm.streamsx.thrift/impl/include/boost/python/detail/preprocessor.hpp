// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef PREPROCESSOR_DWA200247_STREAMS_HPP
# define PREPROCESSOR_DWA200247_STREAMS_HPP

# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/comma_if.hpp>
# include <streams_boost/preprocessor/repeat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>

// stuff that should be in the preprocessor library

# define STREAMS_BOOST_PYTHON_APPLY(x) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PYTHON_APPLY_, x)

# define STREAMS_BOOST_PYTHON_APPLY_STREAMS_BOOST_PYTHON_ITEM(v) v
# define STREAMS_BOOST_PYTHON_APPLY_STREAMS_BOOST_PYTHON_NIL

// cv-qualifiers

# if !defined(__MWERKS__) || __MWERKS__ > 0x2407
#  define STREAMS_BOOST_PYTHON_CV_COUNT 4
# else
#  define STREAMS_BOOST_PYTHON_CV_COUNT 1
# endif

# ifndef STREAMS_BOOST_PYTHON_MAX_ARITY
#  define STREAMS_BOOST_PYTHON_MAX_ARITY 15
# endif

# ifndef STREAMS_BOOST_PYTHON_MAX_BASES
#  define STREAMS_BOOST_PYTHON_MAX_BASES 10
# endif 

# define STREAMS_BOOST_PYTHON_CV_QUALIFIER(i)                          \
    STREAMS_BOOST_PYTHON_APPLY(                                        \
        STREAMS_BOOST_PP_TUPLE_ELEM(4, i, STREAMS_BOOST_PYTHON_CV_QUALIFIER_I) \
    )

# define STREAMS_BOOST_PYTHON_CV_QUALIFIER_I      \
    (                                     \
        STREAMS_BOOST_PYTHON_NIL,                 \
        STREAMS_BOOST_PYTHON_ITEM(const),         \
        STREAMS_BOOST_PYTHON_ITEM(volatile),      \
        STREAMS_BOOST_PYTHON_ITEM(const volatile) \
    )

// enumerators
# define STREAMS_BOOST_PYTHON_UNARY_ENUM(c, text) STREAMS_BOOST_PP_REPEAT(c, STREAMS_BOOST_PYTHON_UNARY_ENUM_I, text)
# define STREAMS_BOOST_PYTHON_UNARY_ENUM_I(z, n, text) STREAMS_BOOST_PP_COMMA_IF(n) text ## n

# define STREAMS_BOOST_PYTHON_BINARY_ENUM(c, a, b) STREAMS_BOOST_PP_REPEAT(c, STREAMS_BOOST_PYTHON_BINARY_ENUM_I, (a, b))
# define STREAMS_BOOST_PYTHON_BINARY_ENUM_I(z, n, _) STREAMS_BOOST_PP_COMMA_IF(n) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, _), n) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, _), n)

# define STREAMS_BOOST_PYTHON_ENUM_WITH_DEFAULT(c, text, def) STREAMS_BOOST_PP_REPEAT(c, STREAMS_BOOST_PYTHON_ENUM_WITH_DEFAULT_I, (text, def))
# define STREAMS_BOOST_PYTHON_ENUM_WITH_DEFAULT_I(z, n, _) STREAMS_BOOST_PP_COMMA_IF(n) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, _), n) = STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, _)

// fixed text (no commas)
# define STREAMS_BOOST_PYTHON_FIXED(z, n, text) text

// flags
# define STREAMS_BOOST_PYTHON_FUNCTION_POINTER 0x0001
# define STREAMS_BOOST_PYTHON_POINTER_TO_MEMBER 0x0002

#endif // PREPROCESSOR_DWA200247_STREAMS_HPP
