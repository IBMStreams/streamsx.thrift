/*=============================================================================
    Copyright (c) 2005 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_LIST_07172005_1153)
#define FUSION_LIST_07172005_1153

#include <streams_boost/fusion/container/list/list_fwd.hpp>
#include <streams_boost/fusion/container/list/detail/list_to_cons.hpp>

namespace streams_boost { namespace fusion
{
    struct nil;
    struct void_;

    template <STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, typename T)>
    struct list 
        : detail::list_to_cons<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, T)>::type
    {
    private:
        typedef 
            detail::list_to_cons<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, T)>
        list_to_cons;

    public:
        typedef typename list_to_cons::type inherited_type;

        list()
            : inherited_type() {}

        template <STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, typename U)>
        list(list<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, U)> const& rhs)
            : inherited_type(rhs) {}

        template <typename Sequence>
        list(Sequence const& rhs)
            : inherited_type(rhs) {}

        //  Expand a couple of forwarding constructors for arguments
        //  of type (T0), (T0, T1), (T0, T1, T2) etc. Exanple:
        //
        //  list(
        //      typename detail::call_param<T0>::type _0
        //    , typename detail::call_param<T1>::type _1)
        //    : inherited_type(list_to_cons::call(_0, _1)) {}
        #include <streams_boost/fusion/container/list/detail/list_forward_ctor.hpp>

        template <STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, typename U)>
        list&
        operator=(list<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_LIST_SIZE, U)> const& rhs)
        {
            inherited_type::operator=(rhs);
            return *this;
        }

        template <typename T>
        list&
        operator=(T const& rhs)
        {
            inherited_type::operator=(rhs);
            return *this;
        }
    };
}}

#endif
