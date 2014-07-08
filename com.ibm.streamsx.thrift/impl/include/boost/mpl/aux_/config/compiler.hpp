
#ifndef STREAMS_BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: compiler.hpp 53189 2009-05-22 20:07:55Z hkaiser $
// $Date: 2009-05-22 16:07:55 -0400 (Fri, 22 May 2009) $
// $Revision: 53189 $

#if !defined(STREAMS_BOOST_MPL_CFG_COMPILER_DIR)

#   include <streams_boost/mpl/aux_/config/dtp.hpp>
#   include <streams_boost/mpl/aux_/config/ttp.hpp>
#   include <streams_boost/mpl/aux_/config/ctps.hpp>
#   include <streams_boost/mpl/aux_/config/msvc.hpp>
#   include <streams_boost/mpl/aux_/config/gcc.hpp>
#   include <streams_boost/mpl/aux_/config/workaround.hpp>

#   if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR msvc60

#   elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR msvc70

#   elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, STREAMS_BOOST_TESTED_AT(0x0304))
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR gcc

#   elif STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610))
#       if !defined(STREAMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#           define STREAMS_BOOST_MPL_CFG_COMPILER_DIR bcc551
#       elif STREAMS_BOOST_WORKAROUND(__BORLANDC__, >= 0x590)
#           define STREAMS_BOOST_MPL_CFG_COMPILER_DIR bcc
#       else
#           define STREAMS_BOOST_MPL_CFG_COMPILER_DIR bcc_pre590
#       endif

#   elif STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR dmc

#   elif defined(__MWERKS__)
#       if defined(STREAMS_BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#           define STREAMS_BOOST_MPL_CFG_COMPILER_DIR mwcw
#       else
#           define STREAMS_BOOST_MPL_CFG_COMPILER_DIR plain
#       endif

#   elif defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR no_ctps

#   elif defined(STREAMS_BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS)
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR no_ttp

#   else
#       define STREAMS_BOOST_MPL_CFG_COMPILER_DIR plain
#   endif

#endif // STREAMS_BOOST_MPL_CFG_COMPILER_DIR

#endif // STREAMS_BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED
