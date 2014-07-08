/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_DEQUE_26112006_1649)
#define STREAMS_BOOST_FUSION_DEQUE_26112006_1649

#include <streams_boost/fusion/container/deque/limits.hpp>
#include <streams_boost/fusion/container/deque/front_extended_deque.hpp>
#include <streams_boost/fusion/container/deque/back_extended_deque.hpp>
#include <streams_boost/fusion/container/deque/detail/deque_keyed_values.hpp>
#include <streams_boost/fusion/container/deque/detail/deque_initial_size.hpp>
#include <streams_boost/fusion/support/sequence_base.hpp>
#include <streams_boost/fusion/container/deque/detail/keyed_element.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/type_traits/add_reference.hpp>
#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>

#include <streams_boost/fusion/container/deque/deque_fwd.hpp>
#include <streams_boost/fusion/container/deque/detail/value_at_impl.hpp>
#include <streams_boost/fusion/container/deque/detail/at_impl.hpp>
#include <streams_boost/fusion/container/deque/detail/begin_impl.hpp>
#include <streams_boost/fusion/container/deque/detail/end_impl.hpp>
#include <streams_boost/fusion/sequence/intrinsic/begin.hpp>
#include <streams_boost/mpl/bool.hpp>

#include <streams_boost/fusion/support/sequence_base.hpp>
#include <streams_boost/fusion/support/void.hpp>
#include <streams_boost/utility/enable_if.hpp>

namespace streams_boost { namespace fusion {

    struct deque_tag;

    template<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, typename T)>
    struct deque
        :
        detail::deque_keyed_values<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, T)>::type,
        sequence_base<deque<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, T)> >
    {
        typedef deque_tag fusion_tag;
        typedef bidirectional_traversal_tag category;
        typedef typename detail::deque_keyed_values<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, T)>::type base;
        typedef typename detail::deque_initial_size<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, T)>::type size;
        typedef mpl::int_<size::value> next_up;
        typedef mpl::int_<
            mpl::if_<mpl::equal_to<size, mpl::int_<0> >, mpl::int_<0>, mpl::int_<-1> >::type::value> next_down;
        typedef mpl::false_ is_view;

#include <streams_boost/fusion/container/deque/detail/deque_forward_ctor.hpp>

        deque()
            {}

        explicit deque(typename add_reference<typename add_const<T0>::type>::type t0)
            : base(t0, detail::nil_keyed_element())
            {}

        template<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, typename U)>
            deque(deque<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, U)> const& seq)
            : base(seq)
            {}

        template<typename Sequence>
            deque(Sequence const& seq, typename disable_if<is_convertible<Sequence, T0> >::type* dummy = 0)
            : base(base::from_iterator(fusion::begin(seq)))
            {}

        template <STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, typename U)>
        deque&
        operator=(deque<STREAMS_BOOST_PP_ENUM_PARAMS(FUSION_MAX_DEQUE_SIZE, U)> const& rhs)
        {
            base::operator=(rhs);
            return *this;
        }

        template <typename T>
        deque&
        operator=(T const& rhs)
        {
            base::operator=(rhs);
            return *this;
        }

    };
}}

#endif
