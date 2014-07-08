/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

// No include guard - this file is included multiple times intentionally.

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>

#if !defined(STREAMS_BOOST_FUSION_CLASS_TPL_NAME)
#   error "STREAMS_BOOST_FUSION_CLASS_TPL_NAME undefined"
#endif

#define STREAMS_BOOST_FUSION_FUNC_NAME STREAMS_BOOST_PP_CAT(make_,STREAMS_BOOST_FUSION_CLASS_TPL_NAME)

namespace streams_boost { namespace fusion
{

    namespace result_of
    {
        template <typename F>
        struct STREAMS_BOOST_FUSION_FUNC_NAME
        {
            typedef fusion::STREAMS_BOOST_FUSION_CLASS_TPL_NAME< 
                typename fusion::detail::as_fusion_element<F>::type > type;
        };
    }

    template <typename F>
    inline typename result_of::STREAMS_BOOST_FUSION_FUNC_NAME<F>::type
    STREAMS_BOOST_FUSION_FUNC_NAME(F const & f)
    {
        return typename result_of::STREAMS_BOOST_FUSION_FUNC_NAME<F>::type(f);
    }

}}

#undef STREAMS_BOOST_FUSION_CLASS_TPL_NAME
#undef STREAMS_BOOST_FUSION_FUNC_NAME

