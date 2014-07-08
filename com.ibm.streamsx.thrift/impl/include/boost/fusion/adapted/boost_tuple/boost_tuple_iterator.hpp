/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_STREAMS_BOOST_TUPLE_ITERATOR_09262006_1851)
#define FUSION_STREAMS_BOOST_TUPLE_ITERATOR_09262006_1851

#include <streams_boost/fusion/iterator/iterator_facade.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/mpl/plus.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/tuple/tuple.hpp>

namespace streams_boost { namespace fusion
{
    struct forward_traversal_tag;

    namespace detail
    {
        template <typename T>
        struct streams_boost_tuple_is_empty : mpl::false_ {};

        template <>
        struct streams_boost_tuple_is_empty<tuples::null_type> : mpl::true_ {};

        template <>
        struct streams_boost_tuple_is_empty<tuples::null_type const> : mpl::true_ {};

        template <>
        struct streams_boost_tuple_is_empty<tuples::tuple<> > : mpl::true_ {};

        template <>
        struct streams_boost_tuple_is_empty<tuples::tuple<> const> : mpl::true_ {};
    }

    template <typename Cons = tuples::null_type>
    struct streams_boost_tuple_iterator
        : iterator_facade<streams_boost_tuple_iterator<Cons>, forward_traversal_tag>
    {
        typedef Cons cons_type;

        explicit streams_boost_tuple_iterator(Cons& cons)
            : cons(cons) {}
        Cons& cons;

        template <typename Iterator>
        struct value_of : mpl::identity<typename Iterator::cons_type::head_type> {};

        template <typename Iterator>
        struct deref
        {
            typedef typename value_of<Iterator>::type element;

            typedef typename
                mpl::if_<
                    is_const<typename Iterator::cons_type>
                  , typename tuples::access_traits<element>::const_type
                  , typename tuples::access_traits<element>::non_const_type
                >::type
            type;

            static type
            call(Iterator const& iter)
            {
                return iter.cons.get_head();
            }
        };

        template <typename Iterator>
        struct next
        {
            typedef typename Iterator::cons_type cons_type;
            typedef typename cons_type::tail_type tail_type;

            typedef streams_boost_tuple_iterator<
                typename mpl::eval_if<
                    is_const<cons_type>
                  , add_const<tail_type>
                  , mpl::identity<tail_type>
                >::type>
            type;

            static type
            call(Iterator const& iter)
            {
                return type(iter.cons.get_tail());
            }
        };
        
        template <typename I1, typename I2>
        struct distance;

        // detail
        template <typename I1, typename I2>
        struct lazy_next_distance
        {
            typedef
                typename mpl::plus<
                    mpl::int_<1>,
                    typename distance<
                        typename next<I1>::type,
                        I2
                    >::type
                >::type type;
        };
        
        template <typename I1, typename I2>
        struct distance
        {
            typedef typename mpl::eval_if<
                streams_boost::is_same<I1, I2>,
                mpl::int_<0>,
                lazy_next_distance<I1, I2>
            >::type type;
            
            static type
            call(I1 const&, I2 const&)
            {
                return type();
            }
        };
    };

    template <typename Null>
    struct streams_boost_tuple_null_iterator
        : iterator_facade<streams_boost_tuple_iterator<Null>, forward_traversal_tag>
    {
        typedef Null cons_type;

        template <typename I1, typename I2>
        struct equal_to
            : mpl::or_<
                is_same<I1, I2>
              , mpl::and_<
                    detail::streams_boost_tuple_is_empty<typename I1::cons_type>
                  , detail::streams_boost_tuple_is_empty<typename I2::cons_type>
                >
            >
        {};
    };

    template <>
    struct streams_boost_tuple_iterator<tuples::null_type>
        : streams_boost_tuple_null_iterator<tuples::null_type>
    {
        template <typename Cons>
        explicit streams_boost_tuple_iterator(Cons const&) {}
    };

    template <>
    struct streams_boost_tuple_iterator<tuples::null_type const>
        : streams_boost_tuple_null_iterator<tuples::null_type const>
    {
        template <typename Cons>
        explicit streams_boost_tuple_iterator(Cons const&) {}
    };

    template <>
    struct streams_boost_tuple_iterator<tuples::tuple<> >
        : streams_boost_tuple_null_iterator<tuples::tuple<> >
    {
        template <typename Cons>
        explicit streams_boost_tuple_iterator(Cons const&) {}
    };

    template <>
    struct streams_boost_tuple_iterator<tuples::tuple<> const>
        : streams_boost_tuple_null_iterator<tuples::tuple<> const>
    {
        template <typename Cons>
        explicit streams_boost_tuple_iterator(Cons const&) {}
    };
}}

#endif


