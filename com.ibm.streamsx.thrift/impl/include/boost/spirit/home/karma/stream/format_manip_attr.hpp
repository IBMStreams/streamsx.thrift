//  Copyright (c) 2001-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#if !defined(STREAMS_BOOST_SPIRIT_KARMA_FORMAT_MANIP_ATTR_APR_24_2009_0734AM)
#define STREAMS_BOOST_SPIRIT_KARMA_FORMAT_MANIP_ATTR_APR_24_2009_0734AM

#include <streams_boost/spirit/home/karma/stream/format_manip.hpp>

#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1                                                   \
    <streams_boost/spirit/home/karma/stream/format_manip_attr.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (2, SPIRIT_ARGUMENTS_LIMIT)
#include STREAMS_BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()
#define STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE(z, n, A)                       \
    STREAMS_BOOST_PP_CAT(A, n) const&

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit { namespace karma 
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline detail::format_manip<Expr, mpl::false_, mpl::true_, unused_type
      , fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > > 
    format(Expr const& xpr, STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        using karma::detail::format_manip;

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit karma expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Expr);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return format_manip<Expr, mpl::false_, mpl::true_, unused_type, vector_type>(
            xpr, unused, attr);
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Expr, typename Delimiter
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline detail::format_manip<Expr, mpl::false_, mpl::true_, Delimiter
      , fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > > 
    format_delimited(Expr const& xpr, Delimiter const& d
      , STREAMS_BOOST_SCOPED_ENUM(delimit_flag) pre_delimit
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        using karma::detail::format_manip;

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit karma expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Expr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Delimiter);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return format_manip<Expr, mpl::false_, mpl::true_, Delimiter, vector_type>(
            xpr, d, pre_delimit, attr);
    }

    template <typename Expr, typename Delimiter
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline detail::format_manip<Expr, mpl::false_, mpl::true_, Delimiter
      , fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > > 
    format_delimited(Expr const& xpr, Delimiter const& d
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        using karma::detail::format_manip;

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit karma expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Expr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Delimiter);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return format_manip<Expr, mpl::false_, mpl::true_, Delimiter, vector_type>(
            xpr, d, delimit_flag::dont_predelimit, attr);
    }

}}}

#undef STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE
#undef N

#endif 

