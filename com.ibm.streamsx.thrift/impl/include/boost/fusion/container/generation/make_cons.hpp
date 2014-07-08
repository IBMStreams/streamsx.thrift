/*=============================================================================
    Copyright (c) 2005 Joel de Guzman
    Copyright (c) 2005 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_MAKE_CONS_07172005_0918)
#define FUSION_MAKE_CONS_07172005_0918

#include <streams_boost/fusion/support/detail/as_fusion_element.hpp>
#include <streams_boost/fusion/container/list/cons.hpp>

namespace streams_boost { namespace fusion
{
    struct nil;

    namespace result_of
    {
        template <typename Car, typename Cdr = nil>
        struct make_cons
        {
            typedef cons<typename detail::as_fusion_element<Car>::type, Cdr> type;
        };
    }

    template <typename Car>
    inline cons<typename detail::as_fusion_element<Car>::type>
    make_cons(Car const& car)
    {
        return cons<typename detail::as_fusion_element<Car>::type>(car);
    }

    template <typename Car, typename Cdr>
    inline cons<typename detail::as_fusion_element<Car>::type, Cdr>
    make_cons(Car const& car, Cdr const& cdr)
    {
        return cons<typename detail::as_fusion_element<Car>::type, Cdr>(car, cdr);
    }
}}

#endif

