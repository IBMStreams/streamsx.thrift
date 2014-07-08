//  Copyright (c) 2001-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#if !defined(STREAMS_BOOST_SPIRIT_KARMA_GENERATE_ATTR_APR_23_2009_0541PM)
#define STREAMS_BOOST_SPIRIT_KARMA_GENERATE_ATTR_APR_23_2009_0541PM

#include <streams_boost/spirit/home/karma/generate.hpp>

#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/spirit/home/karma/generate_attr.hpp>
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

namespace streams_boost { namespace spirit { namespace karma
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename OutputIterator, typename Properties, typename Expr
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    generate(
        detail::output_iterator<OutputIterator, Properties>& sink
      , Expr const& expr
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit karma expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Expr);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return compile<karma::domain>(expr).generate(sink, unused, unused, attr);
    }

    template <typename OutputIterator, typename Expr
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    generate(
        OutputIterator& target_sink
      , Expr const& expr
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        typedef traits::properties_of<
            typename result_of::compile<karma::domain, Expr>::type
        > properties;

        // wrap user supplied iterator into our own output iterator
        detail::output_iterator<OutputIterator
          , mpl::int_<properties::value> > sink(target_sink);
        return karma::generate(sink, expr, STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename OutputIterator, typename Properties, typename Expr
      , typename Delimiter, STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    generate_delimited(
        detail::output_iterator<OutputIterator, Properties>& sink
      , Expr const& expr
      , Delimiter const& delimiter
      , STREAMS_BOOST_SCOPED_ENUM(delimit_flag) pre_delimit
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then either the expression (expr) or skipper is not a valid
        // spirit karma expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Expr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(karma::domain, Delimiter);

        typename result_of::compile<karma::domain, Delimiter>::type const 
            delimiter_ = compile<karma::domain>(delimiter);

        if (pre_delimit == delimit_flag::predelimit &&
            !karma::delimit_out(sink, delimiter_))
        {
            return false;
        }

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return compile<karma::domain>(expr).
            generate(sink, unused, delimiter_, attr);
    }

    template <typename OutputIterator, typename Expr, typename Delimiter
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    generate_delimited(
        OutputIterator& target_sink
      , Expr const& expr
      , Delimiter const& delimiter
      , STREAMS_BOOST_SCOPED_ENUM(delimit_flag) pre_delimit
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        typedef traits::properties_of<
            typename result_of::compile<karma::domain, Expr>::type
        > properties;
        typedef traits::properties_of<
            typename result_of::compile<karma::domain, Delimiter>::type
        > delimiter_properties;

        // wrap user supplied iterator into our own output iterator
        detail::output_iterator<OutputIterator
          , mpl::int_<properties::value | delimiter_properties::value>
        > sink(target_sink);
        return karma::generate_delimited(sink, expr, delimiter, pre_delimit
          , STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
    }

    template <typename OutputIterator, typename Expr, typename Delimiter
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    generate_delimited(
        OutputIterator& target_sink
      , Expr const& expr
      , Delimiter const& delimiter
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& attr))
    {
        typedef traits::properties_of<
            typename result_of::compile<karma::domain, Expr>::type
        > properties;
        typedef traits::properties_of<
            typename result_of::compile<karma::domain, Delimiter>::type
        > delimiter_properties;

        // wrap user supplied iterator into our own output iterator
        detail::output_iterator<OutputIterator
          , mpl::int_<properties::value | delimiter_properties::value>
        > sink(target_sink);
        return karma::generate_delimited(sink, expr, delimiter
          , delimit_flag::dont_predelimit, STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
    }

}}}

#undef STREAMS_BOOST_SPIRIT_KARMA_ATTRIBUTE_REFERENCE
#undef N

#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)

