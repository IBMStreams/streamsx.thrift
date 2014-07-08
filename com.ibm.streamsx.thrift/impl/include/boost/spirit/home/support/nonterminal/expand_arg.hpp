/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_EXPAND_ARG_FEB_19_2007_1107AM)
#define STREAMS_BOOST_SPIRIT_EXPAND_ARG_FEB_19_2007_1107AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/utility/result_of.hpp>
#include <streams_boost/type_traits/is_scalar.hpp>
#include <streams_boost/spirit/home/support/string_traits.hpp>

namespace streams_boost { namespace spirit { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Context>
    struct expand_arg
    {
        template <typename T>
        struct result_type
        {
            // This is a temporary hack. The better way is to detect if T
            // can be called given unused context.
            typedef typename
                mpl::eval_if<
                    mpl::or_<is_scalar<T>, traits::is_string<T> >
                  , mpl::identity<T const &>
                  , streams_boost::result_of<T(unused_type, Context)>
                >::type
            type;
        };

        template <typename T>
        struct result;

        template <typename F, typename A0>
        struct result<F(A0)>
          : result_type<A0> {};

        template <typename F, typename A0>
        struct result<F(A0&)>
          : result_type<A0> {};

        expand_arg(Context& context)
          : context(context)
        {
        }

        template <typename T>
        typename result_type<T>::type
        call(T const& f, mpl::false_) const
        {
            return f(unused, context);
        }

        template <typename T>
        typename result_type<T>::type
        call(T const& val, mpl::true_) const
        {
            return val;
        }

        template <typename T>
        typename result_type<T>::type
        operator()(T const& x) const
        {
            return call(x, mpl::or_<is_scalar<T>, traits::is_string<T> >());
        }

        Context& context;

    private:
        // silence MSVC warning C4512: assignment operator could not be generated
        expand_arg& operator= (expand_arg const&);
    };

}}}

#endif
