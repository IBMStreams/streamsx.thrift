/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_VECTOR10_05042005_0257)
#define FUSION_VECTOR10_05042005_0257

#include <streams_boost/fusion/support/sequence_base.hpp>
#include <streams_boost/fusion/support/detail/access.hpp>
#include <streams_boost/fusion/iterator/next.hpp>
#include <streams_boost/fusion/iterator/deref.hpp>
#include <streams_boost/fusion/sequence/intrinsic/begin.hpp>
#include <streams_boost/fusion/container/vector/detail/at_impl.hpp>
#include <streams_boost/fusion/container/vector/detail/value_at_impl.hpp>
#include <streams_boost/fusion/container/vector/detail/begin_impl.hpp>
#include <streams_boost/fusion/container/vector/detail/end_impl.hpp>

#include <streams_boost/mpl/void.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/at.hpp>
#include <streams_boost/mpl/vector/vector10.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/utility/enable_if.hpp>

#include <streams_boost/preprocessor/dec.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>

namespace streams_boost { namespace fusion
{
    struct vector_tag;
    struct fusion_sequence_tag;
    struct random_access_traversal_tag;

    template <typename Dummy = void>
    struct vector0 : sequence_base<vector0<Dummy> >
    {
        typedef mpl::vector0<> types;
        typedef vector_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef mpl::false_ is_view;
        typedef random_access_traversal_tag category;
        typedef mpl::int_<0> size;

        vector0() {}

        template<typename Sequence>
        vector0(Sequence const& seq)
        {}
    };

// expand vector1 to vector10
#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/fusion/container/vector/detail/vector_n.hpp>
#define STREAMS_BOOST_PP_ITERATION_LIMITS (1, 10)
#include STREAMS_BOOST_PP_ITERATE()

}}

#endif

