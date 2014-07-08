// Copyright (c) 2001 Ronald Garcia, Indiana University (garcia@osl.iu.edu)
// Andrew Lumsdaine, Indiana University (lums@osl.iu.edu). Permission to copy, 
// use, modify, sell and distribute this software is granted provided this
// copyright notice appears in all copies. This software is provided "as is"
// without express or implied warranty, and with no claim as to its suitability
// for any purpose.

#ifndef STREAMS_BOOST_PROGRAM_OPTIONS_UTF8_CODECVT_FACET_HPP
#define STREAMS_BOOST_PROGRAM_OPTIONS_UTF8_CODECVT_FACET_HPP

#include <streams_boost/program_options/config.hpp>

#define STREAMS_BOOST_UTF8_BEGIN_NAMESPACE \
     namespace streams_boost { namespace program_options { namespace detail {

#define STREAMS_BOOST_UTF8_END_NAMESPACE }}}
#define STREAMS_BOOST_UTF8_DECL STREAMS_BOOST_PROGRAM_OPTIONS_DECL

#include <streams_boost/detail/utf8_codecvt_facet.hpp>

#undef STREAMS_BOOST_UTF8_BEGIN_NAMESPACE
#undef STREAMS_BOOST_UTF8_END_NAMESPACE
#undef STREAMS_BOOST_UTF8_DECL

#endif
