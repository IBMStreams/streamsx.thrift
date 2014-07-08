
#ifndef STREAMS_BOOST_MPL_AUX_PREPROCESSOR_IS_SEQ_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PREPROCESSOR_IS_SEQ_HPP_INCLUDED

// Copyright Paul Mensonides 2003
// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: is_seq.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/preprocessor/seq/size.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/punctuation/paren.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/config/config.hpp>

// returns 1 if 'seq' is a PP-sequence, 0 otherwise:
//
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_PP_NOT( STREAMS_BOOST_MPL_PP_IS_SEQ( int ) ) )
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_MPL_PP_IS_SEQ( (int) ) )
//   STREAMS_BOOST_PP_ASSERT( STREAMS_BOOST_MPL_PP_IS_SEQ( (1)(2) ) )

#if (STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_BCC()) || defined(_MSC_VER) && defined(__INTEL_COMPILER) && __INTEL_COMPILER == 1010

#   define STREAMS_BOOST_MPL_PP_IS_SEQ(seq) STREAMS_BOOST_PP_DEC( STREAMS_BOOST_PP_SEQ_SIZE( STREAMS_BOOST_MPL_PP_IS_SEQ_(seq) ) )
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_(seq) STREAMS_BOOST_MPL_PP_IS_SEQ_SEQ_( STREAMS_BOOST_MPL_PP_IS_SEQ_SPLIT_ seq )
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_SEQ_(x) (x)
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_SPLIT_(unused) unused)((unused)

#else

#   if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#       define STREAMS_BOOST_MPL_PP_IS_SEQ(seq) STREAMS_BOOST_MPL_PP_IS_SEQ_MWCC_((seq))
#       define STREAMS_BOOST_MPL_PP_IS_SEQ_MWCC_(args) STREAMS_BOOST_MPL_PP_IS_SEQ_ ## args
#   else
#       define STREAMS_BOOST_MPL_PP_IS_SEQ(seq) STREAMS_BOOST_MPL_PP_IS_SEQ_(seq)
#   endif

#   define STREAMS_BOOST_MPL_PP_IS_SEQ_(seq) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_MPL_PP_IS_SEQ_, STREAMS_BOOST_MPL_PP_IS_SEQ_0 seq STREAMS_BOOST_PP_RPAREN())
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_0(x) STREAMS_BOOST_MPL_PP_IS_SEQ_1(x
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_ALWAYS_0(unused) 0
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_STREAMS_BOOST_MPL_PP_IS_SEQ_0 STREAMS_BOOST_MPL_PP_IS_SEQ_ALWAYS_0(
#   define STREAMS_BOOST_MPL_PP_IS_SEQ_STREAMS_BOOST_MPL_PP_IS_SEQ_1(unused) 1

#endif

#endif // STREAMS_BOOST_MPL_AUX_PREPROCESSOR_IS_SEQ_HPP_INCLUDED
