
#ifndef STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: nested_type_wknd.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/config/gcc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MPL_CFG_GCC, STREAMS_BOOST_TESTED_AT(0x0302)) \
    || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x561)) \
    || STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x530)) \
    || STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))

namespace streams_boost { namespace mpl { namespace aux {
template< typename T > struct nested_type_wknd
    : T::type
{
};
}}}

#if STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))
#   define STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T) \
    aux::nested_type_wknd<T> \
/**/
#else
#   define STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T) \
    ::streams_boost::mpl::aux::nested_type_wknd<T> \
/**/
#endif

#else // !STREAMS_BOOST_MPL_CFG_GCC et al.

#   define STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(T) T::type

#endif 

#endif // STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED
