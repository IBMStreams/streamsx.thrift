/*=============================================================================
    Copyright (c) 1998-2003 Joel de Guzman
    http://spirit.sourceforge.net/

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_MATCH_ATTR_TRAITS_IPP)
#define STREAMS_BOOST_SPIRIT_MATCH_ATTR_TRAITS_IPP

#include <streams_boost/optional.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace spirit { 

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

namespace impl
{
    template <typename T>
    struct match_attr_traits
    {
        typedef typename
            streams_boost::optional<T>::reference_const_type
        const_reference;

        //  case where src *IS* convertible to T (dest)
        template <typename T2>
        static void
        convert(streams_boost::optional<T>& dest, T2 const& src, mpl::true_)
        { 
            dest.reset(src); 
        }

        //  case where src *IS NOT* convertible to T (dest)
        template <typename T2>
        static void
        convert(streams_boost::optional<T>& dest, T2 const& /*src*/, mpl::false_)
        { 
            dest.reset(); 
        }

        static void
        convert(streams_boost::optional<T>& dest, nil_t/*src*/)
        { 
            dest.reset(); 
        }
        
        template <typename T2>
        static void
        convert(streams_boost::optional<T>& dest, T2 const& src)
        { 
            convert(dest, src, is_convertible<T2, T>());
        }

        template <typename OtherMatchT>
        static void
        copy(streams_boost::optional<T>& dest, OtherMatchT const& src)
        {
            if (src.has_valid_attribute())
                convert(dest, src.value());
        }

        template <typename OtherMatchT>
        static void
        assign(streams_boost::optional<T>& dest, OtherMatchT const& src)
        {
            if (src.has_valid_attribute())
                convert(dest, src.value());
            else
                dest.reset();
        }

        // T is not reference
        template <typename ValueT>
        static void
        set_value(streams_boost::optional<T>& dest, ValueT const& val, mpl::false_)
        {
            dest.reset(val);
        }

        // T is a reference
        template <typename ValueT>
        static void
        set_value(streams_boost::optional<T>& dest, ValueT const& val, mpl::true_)
        {
            dest.get() = val;
        }
    };

}

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace streams_boost::spirit::impl

#endif

