//  Copyright (c) 2001-2010 Hartmut Kaiser
//  Copyright (c) 2001-2010 Joel de Guzman
//  Copyright (c) 2009 Carl Barron
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#if !defined(STREAMS_BOOST_SPIRIT_PARSE_ATTR_APRIL_24_2009_1043AM)
#define STREAMS_BOOST_SPIRIT_PARSE_ATTR_APRIL_24_2009_1043AM

#include <streams_boost/spirit/home/qi/parse.hpp>

#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/spirit/home/qi/parse_attr.hpp>
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
#define STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE(z, n, A) STREAMS_BOOST_PP_CAT(A, n)&

namespace streams_boost { namespace spirit { namespace qi
{
    template <typename Iterator, typename Expr
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    parse(
        Iterator& first
      , Iterator last
      , Expr const& expr
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        // Make sure the iterator is at least a forward_iterator. If you got an 
        // compilation error here, then you are using an input_iterator while
        // calling this function, you need to supply at least a 
        // forward_iterator instead.
        STREAMS_BOOST_CONCEPT_ASSERT((ForwardIterator<Iterator>));

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        return compile<qi::domain>(expr).parse(first, last, unused, unused, attr);
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Iterator, typename Expr, typename Skipper
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    phrase_parse(
        Iterator& first
      , Iterator last
      , Expr const& expr
      , Skipper const& skipper
      , STREAMS_BOOST_SCOPED_ENUM(skip_flag) post_skip
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        // Make sure the iterator is at least a forward_iterator. If you got an 
        // compilation error here, then you are using an input_iterator while
        // calling this function, you need to supply at least a 
        // forward_iterator instead.
        STREAMS_BOOST_CONCEPT_ASSERT((ForwardIterator<Iterator>));

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then either the expression (expr) or skipper is not a valid
        // spirit qi expression.
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
        STREAMS_BOOST_SPIRIT_ASSERT_MATCH(qi::domain, Skipper);

        typedef
            typename result_of::compile<qi::domain, Skipper>::type
        skipper_type;
        skipper_type const skipper_ = compile<qi::domain>(skipper);

        typedef fusion::vector<
            STREAMS_BOOST_PP_ENUM(N, STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type attr (STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
        if (!compile<qi::domain>(expr).parse(
                first, last, unused, skipper_, attr))
            return false;

        if (post_skip == skip_flag::postskip)
            qi::skip_over(first, last, skipper_);
        return true;
    }

    template <typename Iterator, typename Expr, typename Skipper
      , STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    phrase_parse(
        Iterator& first
      , Iterator last
      , Expr const& expr
      , Skipper const& skipper
      , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        return phrase_parse(first, last, expr, skipper, skip_flag::postskip
          , STREAMS_BOOST_PP_ENUM_PARAMS(N, attr));
    }

}}}

#undef STREAMS_BOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE
#undef N

#endif

