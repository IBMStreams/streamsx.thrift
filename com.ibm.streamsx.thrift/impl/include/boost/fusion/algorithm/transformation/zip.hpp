/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef STREAMS_BOOST_PP_IS_ITERATING
#if !defined(FUSION_ZIP_HPP_20060125_2058)
#define FUSION_ZIP_HPP_20060125_2058

#include <streams_boost/fusion/view/zip_view.hpp>
#include <streams_boost/fusion/adapted/mpl.hpp>
#include <streams_boost/fusion/container/vector.hpp>
#include <streams_boost/fusion/container/vector/convert.hpp>
#include <streams_boost/type_traits/add_reference.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/arithmetic/inc.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/mpl/vector.hpp>
#include <streams_boost/mpl/transform.hpp>
#include <streams_boost/mpl/placeholders.hpp>

#if !defined(FUSION_MAX_ZIP_SEQUENCES)
#define FUSION_MAX_ZIP_SEQUENCES 10
#endif

namespace streams_boost { namespace fusion {

    struct void_;
    
    namespace result_of
    {
        template<STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_PP_INC(FUSION_MAX_ZIP_SEQUENCES), typename T, fusion::void_)>
        struct zip;
    }

#define STREAMS_BOOST_PP_FILENAME_1 \
    <streams_boost/fusion/algorithm/transformation/zip.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (2, FUSION_MAX_ZIP_SEQUENCES)
#include STREAMS_BOOST_PP_ITERATE()

}}

#endif

#else

#define ZIP_ITERATION STREAMS_BOOST_PP_ITERATION()

    namespace result_of
    {
        template< STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, typename T) >
#if defined(STREAMS_BOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS)
        #define TEXT(z, n, text) , text
        struct zip< STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, T) STREAMS_BOOST_PP_REPEAT_FROM_TO(STREAMS_BOOST_PP_DEC(ZIP_ITERATION), FUSION_MAX_ZIP_SEQUENCES, TEXT, void_) >
        #undef TEXT
#else
        struct zip< STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, T) >
#endif
        {
            typedef mpl::vector< STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, T) > sequences;
            typedef typename mpl::transform<sequences, add_reference<mpl::_> >::type ref_params;
            typedef zip_view<typename result_of::as_vector<ref_params>::type> type;
        };
    }

#define FUSION_REF_PARAM(z, n, data) const T ## n&

    template<STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, typename T)>
    inline typename result_of::zip<STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, const T)>::type
    zip(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(ZIP_ITERATION, T, const& t))
    {
        fusion::vector<STREAMS_BOOST_PP_ENUM(ZIP_ITERATION, FUSION_REF_PARAM, _)> seqs(
            STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, t));
        return typename result_of::zip<STREAMS_BOOST_PP_ENUM_PARAMS(ZIP_ITERATION, const T)>::type(
            seqs);
    }

#undef FUSION_REF_PARAM
#undef ZIP_ITERATION

#endif
