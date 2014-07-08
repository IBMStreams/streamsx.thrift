
#ifndef STREAMS_BOOST_MPL_MULTISET_AUX_ITEM_HPP_INCLUDED
#define STREAMS_BOOST_MPL_MULTISET_AUX_ITEM_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: item.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/multiset/aux_/tag.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/yes_no.hpp>
#include <streams_boost/mpl/aux_/value_wknd.hpp>
#include <streams_boost/mpl/aux_/static_cast.hpp>
#include <streams_boost/mpl/aux_/config/arrays.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
#   include <streams_boost/mpl/eval_if.hpp>
#   include <streams_boost/mpl/next.hpp>
#   include <streams_boost/type_traits/is_same.hpp>
#endif


namespace streams_boost { namespace mpl {

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

template< typename T, typename Base >
struct ms_item
{
    typedef aux::multiset_tag tag;

    template< typename U > struct prior_count
    {
        enum { msvc70_wknd_ = sizeof(Base::key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(U*,0))) };
        typedef int_< msvc70_wknd_ > count_;
        typedef typename eval_if< is_same<T,U>, next<count_>, count_ >::type c_;
#if defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
        typedef typename aux::weighted_tag<STREAMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(c_)::value>::type type;
#else
        typedef char (&type)[STREAMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(c_)::value];
#endif
    };

    template< typename U > struct prior_ref_count
    {
        typedef U (* u_)();
        enum { msvc70_wknd_ = sizeof(Base::ref_key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(u_,0))) }; 
        typedef int_< msvc70_wknd_ > count_;
        typedef typename eval_if< is_same<T,U>, next<count_>, count_ >::type c_;
#if defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
        typedef typename aux::weighted_tag<STREAMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(c_)::value>::type type;
#else
        typedef char (&type)[STREAMS_BOOST_MPL_AUX_MSVC_VALUE_WKND(c_)::value];
#endif
    };

    template< typename U >
    static typename prior_count<U>::type key_count(U*);

    template< typename U >
    static typename prior_ref_count<U>::type ref_key_count(U (*)());
};

#else // STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

namespace aux {
template< typename U, typename Base >
struct prior_key_count
{
    enum { msvc71_wknd_ = sizeof(Base::key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<U>*,0))) }; 
    typedef int_< msvc71_wknd_ > count_;
#if defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
    typedef typename aux::weighted_tag< STREAMS_BOOST_MPL_AUX_VALUE_WKND(count_)::value >::type type;
#else
    typedef char (&type)[count_::value];
#endif
};
}

template< typename T, typename Base >
struct ms_item
{
    typedef aux::multiset_tag tag;

    enum { msvc71_wknd_ = sizeof(Base::key_count(STREAMS_BOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<T>*,0))) + 1 };
    typedef int_< msvc71_wknd_ > count_;
#if defined(STREAMS_BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
    static 
    typename aux::weighted_tag< STREAMS_BOOST_MPL_AUX_VALUE_WKND(count_)::value >::type
        key_count(aux::type_wrapper<T>*);
#else
    static char (& key_count(aux::type_wrapper<T>*) )[count_::value];
#endif

    template< typename U >
    static typename aux::prior_key_count<U,Base>::type key_count(aux::type_wrapper<U>*);
};

#endif // STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

}}

#endif // STREAMS_BOOST_MPL_MULTISET_AUX_ITEM_HPP_INCLUDED
