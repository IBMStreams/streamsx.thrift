/*=============================================================================
    Copyright (c) 2009 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_NVIEW_SEP_23_2009_0948PM)
#define STREAMS_BOOST_FUSION_NVIEW_SEP_23_2009_0948PM

#include <streams_boost/mpl/size.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/vector_c.hpp>
#include <streams_boost/utility/result_of.hpp>

#include <streams_boost/type_traits/remove_reference.hpp>

#include <streams_boost/fusion/support/is_view.hpp>
#include <streams_boost/fusion/support/category_of.hpp>
#include <streams_boost/fusion/support/sequence_base.hpp>
#include <streams_boost/fusion/container/vector.hpp>
#include <streams_boost/fusion/view/transform_view.hpp>

namespace streams_boost { namespace fusion
{
    namespace detail
    {
        struct addref
        {
            template<typename Sig>
            struct result;

            template<typename U>
            struct result<addref(U)> : add_reference<U> {};

            template <typename T>
            typename streams_boost::result_of<addref(T)>::type 
            operator()(T& x) const
            {
                return x;
            }
        };

        struct addconstref
        {
            template<typename Sig>
            struct result;

            template<typename U>
            struct result<addconstref(U)> 
              : add_reference<typename add_const<U>::type> 
            {};

            template <typename T>
            typename streams_boost::result_of<addconstref(T)>::type 
            operator()(T& x) const
            {
                return x;
            }
        };
    }

    struct nview_tag;
    struct random_access_traversal_tag;
    struct fusion_sequence_tag;

    template<typename Sequence, typename Indicies>
    struct nview
      : sequence_base<nview<Sequence, Indicies> >
    {
        typedef nview_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef random_access_traversal_tag category;

        typedef mpl::true_ is_view;
        typedef Indicies index_type;
        typedef typename mpl::size<Indicies>::type size;

        typedef typename mpl::if_<
            is_const<Sequence>, detail::addconstref, detail::addref
        >::type transform_type;
        typedef transform_view<Sequence, transform_type> transform_view_type;
        typedef typename result_of::as_vector<transform_view_type>::type 
            sequence_type;

        explicit nview(Sequence& val)
          : seq(sequence_type(transform_view_type(val, transform_type()))) 
        {}

        sequence_type seq;
    };

}}

// define the nview() generator functions
#include <streams_boost/fusion/view/nview/detail/nview_impl.hpp>

#endif


