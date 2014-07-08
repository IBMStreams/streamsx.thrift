///////////////////////////////////////////////////////////////////////////////
// traits_utils.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_UTILITY_TRAITS_UTILS_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_UTILITY_TRAITS_UTILS_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
# pragma warning(push)
# pragma warning(disable : 4100) // unreferenced formal parameter
#endif

#include <string>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/iterator/transform_iterator.hpp>
#include <streams_boost/xpressive/detail/utility/algorithm.hpp>

namespace streams_boost { namespace xpressive { namespace detail
{

    ///////////////////////////////////////////////////////////////////////////////
    // char_cast
    //
    template<typename ToChar, typename FromChar, typename Traits>
    inline ToChar
    char_cast(FromChar from, Traits const &, typename enable_if<is_same<ToChar, FromChar> >::type * = 0)
    {
        return from;
    }

    template<typename ToChar, typename FromChar, typename Traits>
    inline ToChar
    char_cast(FromChar from, Traits const &tr, typename disable_if<is_same<ToChar, FromChar> >::type * = 0)
    {
        STREAMS_BOOST_MPL_ASSERT((is_same<FromChar, char>));
        return tr.widen(from);
    }

    ///////////////////////////////////////////////////////////////////////////////
    // widen_fun
    //
    template<typename Traits>
    struct widen_fun
    {
        typedef typename Traits::char_type result_type;
        explicit widen_fun(Traits const &tr)
          : traits_(tr)
        {}

        result_type operator()(char ch) const
        {
            return this->traits_.widen(ch);
        }

        Traits const &traits_;
    };

    ///////////////////////////////////////////////////////////////////////////////
    // string_cast_
    //
    template<
        typename To
      , typename From
      , typename ToChar = typename detail::range_data<To>::type
      , typename FromChar = typename detail::range_data<From>::type
    >
    struct string_cast_
    {
        STREAMS_BOOST_MPL_ASSERT((is_same<FromChar, char>));
        typedef To const result_type;
        template<typename Traits>
        result_type operator()(From const &from, Traits const &tr) const
        {
            widen_fun<Traits> widen(tr);
            To to(
                streams_boost::make_transform_iterator(detail::data_begin(from), widen)
              , streams_boost::make_transform_iterator(detail::data_end(from), widen)
            );
            return to;
        }
    };

    template<typename To, typename From, typename Char>
    struct string_cast_<To, From, Char, Char>
    {
        typedef To const result_type;
        template<typename Traits>
        result_type operator()(From const &from, Traits const &) const
        {
            To to(detail::data_begin(from), detail::data_end(from));
            return to;
        }
    };

    template<typename From, typename Char>
    struct string_cast_<From, From, Char, Char>
    {
        typedef From const &result_type;
        template<typename Traits>
        result_type operator()(From const &from, Traits const &) const
        {
            return from;
        }
    };

    ///////////////////////////////////////////////////////////////////////////////
    // string_cast
    //
    template<typename To, typename From, typename Traits>
    typename string_cast_<To, From>::result_type
    string_cast(From const &from, Traits const &tr)
    {
        return string_cast_<To, From>()(from, tr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    // translate
    //
    template<typename Char, typename Traits>
    inline Char translate(Char ch, Traits const &tr, mpl::false_) // case-sensitive
    {
        return tr.translate(ch);
    }

    template<typename Char, typename Traits>
    inline Char translate(Char ch, Traits const &tr, mpl::true_) // case-insensitive
    {
        return tr.translate_nocase(ch);
    }

}}} // namespace streams_boost::xpressive::detail

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma warning(pop)
#endif

#endif