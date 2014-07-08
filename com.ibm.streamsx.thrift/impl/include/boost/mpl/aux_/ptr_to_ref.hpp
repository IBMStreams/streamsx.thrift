
#ifndef STREAMS_BOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED
#define STREAMS_BOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: ptr_to_ref.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/aux_/static_cast.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>


#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) \
    ||  ( STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 245) \
        && !(defined(__STD_STRICT_ANSI) \
            || defined(__STD_STRICT_ANSI_ERRORS)) )

#   define STREAMS_BOOST_MPL_AUX_PTR_TO_REF(X) \
    *STREAMS_BOOST_MPL_AUX_STATIC_CAST(X*, 0) \
/**/

#else

#   define STREAMS_BOOST_MPL_AUX_PTR_TO_REF(X) \
    aux::ptr_to_ref(STREAMS_BOOST_MPL_AUX_STATIC_CAST(X*, 0)) \
/**/

#endif


namespace streams_boost { namespace mpl { namespace aux {

template< typename T > static T const& ptr_to_ref(T*);

}}}

#endif // STREAMS_BOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED
