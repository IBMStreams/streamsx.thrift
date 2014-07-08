// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_TEMPLATE_PARAMS_HPP_INCLUDED

#include <streams_boost/preprocessor/control/expr_if.hpp>
#include <streams_boost/preprocessor/control/if.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>

#define STREAMS_BOOST_IOSTREAMS_TEMPLATE_PARAMS(arity, param) \
    STREAMS_BOOST_PP_EXPR_IF(arity, template<) \
    STREAMS_BOOST_PP_ENUM_PARAMS(arity, typename param) \
    STREAMS_BOOST_PP_EXPR_IF(arity, >) \
    /**/

#define STREAMS_BOOST_IOSTREAMS_TEMPLATE_ARGS(arity, param) \
    STREAMS_BOOST_PP_EXPR_IF(arity, <) \
    STREAMS_BOOST_PP_ENUM_PARAMS(arity, param) \
    STREAMS_BOOST_PP_EXPR_IF(arity, >) \
    /**/

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_BUFFERS_HPP_INCLUDED
