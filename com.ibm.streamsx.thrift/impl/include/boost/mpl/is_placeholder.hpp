
#ifndef STREAMS_BOOST_MPL_IS_PLACEHOLDER_HPP_INCLUDED
#define STREAMS_BOOST_MPL_IS_PLACEHOLDER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: is_placeholder.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/arg_fwd.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/aux_/yes_no.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/nttp_decl.hpp>
#include <streams_boost/mpl/aux_/config/ctps.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>

namespace streams_boost { namespace mpl {

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename T >
struct is_placeholder
    : bool_<false>
{
};

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N) >
struct is_placeholder< arg<N> >
    : bool_<true>
{
};

#else

namespace aux {

aux::no_tag is_placeholder_helper(...);

template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(int, N) >
aux::yes_tag is_placeholder_helper(aux::type_wrapper< arg<N> >*);

} // namespace aux

template< typename T >
struct is_placeholder
{
    static aux::type_wrapper<T>* get();
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(aux::is_placeholder_helper(get())) == sizeof(aux::yes_tag)
        );
    
    typedef bool_<value> type;
};

#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}}

#endif // STREAMS_BOOST_MPL_IS_PLACEHOLDER_HPP_INCLUDED
