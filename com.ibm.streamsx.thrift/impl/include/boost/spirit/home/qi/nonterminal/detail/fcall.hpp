/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING

#include <streams_boost/preprocessor/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#define STREAMS_BOOST_PP_FILENAME_1 \
    <streams_boost/spirit/home/qi/nonterminal/detail/fcall.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, SPIRIT_ARGUMENTS_LIMIT)
#include STREAMS_BOOST_PP_ITERATE()

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)

#define N STREAMS_BOOST_PP_ITERATION()

    template <STREAMS_BOOST_PP_ENUM_PARAMS(N, typename A)>
    typename lazy_enable_if_c<
        (params_size == N)
      , proto::terminal<
            spirit::qi::parameterized_nonterminal<
                parameterized_subject_type
              , fusion::vector<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)> >
        >
    >::type
    operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& f)) const
    {
        typedef fusion::vector<STREAMS_BOOST_PP_ENUM_PARAMS(N, A)> vector_type;
        typedef spirit::qi::parameterized_nonterminal<
            parameterized_subject_type, vector_type> parameterized_type;
        typedef typename proto::terminal<parameterized_type>::type result_type;

        return result_type::make(
            parameterized_type(
                this->get_parameterized_subject()
              , fusion::make_vector(STREAMS_BOOST_PP_ENUM_PARAMS(N, f)))
        );
    }

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)


