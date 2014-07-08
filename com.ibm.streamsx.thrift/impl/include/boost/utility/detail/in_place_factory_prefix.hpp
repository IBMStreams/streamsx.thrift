// Copyright (C) 2003, Fernando Luis Cacciola Carballal.
// Copyright (C) 2007, Tobias Schwinger.
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/lib/optional for documentation.
//
// You are welcome to contact the author at:
//  fernando_cacciola@hotmail.com
//
#ifndef STREAMS_BOOST_UTILITY_DETAIL_INPLACE_FACTORY_PREFIX_04APR2007_HPP
#define STREAMS_BOOST_UTILITY_DETAIL_INPLACE_FACTORY_PREFIX_04APR2007_HPP

#include <new>
#include <cstddef>
#include <streams_boost/config.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/punctuation/paren.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

#define STREAMS_BOOST_DEFINE_INPLACE_FACTORY_CLASS_MEMBER_INIT(z,n,_) STREAMS_BOOST_PP_CAT(m_a,n) STREAMS_BOOST_PP_LPAREN() STREAMS_BOOST_PP_CAT(a,n) STREAMS_BOOST_PP_RPAREN()
#define STREAMS_BOOST_DEFINE_INPLACE_FACTORY_CLASS_MEMBER_DECL(z,n,_) STREAMS_BOOST_PP_CAT(A,n) const& STREAMS_BOOST_PP_CAT(m_a,n);

#define STREAMS_BOOST_MAX_INPLACE_FACTORY_ARITY 10

#undef STREAMS_BOOST_UTILITY_DETAIL_INPLACE_FACTORY_SUFFIX_04APR2007_HPP

#endif

