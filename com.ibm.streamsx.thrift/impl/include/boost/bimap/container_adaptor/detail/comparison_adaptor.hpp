// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file container_adaptor/detail/comparison_adaptor.hpp
/// \brief Comparison adaptor.

#ifndef STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_DETAIL_COMPARISON_ADAPTOR_HPP
#define STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_DETAIL_COMPARISON_ADAPTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/call_traits.hpp>
#include <functional>

namespace streams_boost {
namespace bimaps {
namespace container_adaptor {
namespace detail {

/// \brief Comparison adaptor
/**

A simple comparison adaptor.
                                                                                    **/

template < class Compare, class NewType, class Converter >
struct comparison_adaptor : std::binary_function<NewType,NewType,bool>
{
    comparison_adaptor( const Compare & comp, const Converter & conv)
        : compare(comp), converter(conv) {}

    bool operator()( STREAMS_BOOST_DEDUCED_TYPENAME call_traits<NewType>::param_type x,
                     STREAMS_BOOST_DEDUCED_TYPENAME call_traits<NewType>::param_type y) const
    {
        return compare( converter(x), converter(y) );
    }

    private:
    Compare     compare;
    Converter   converter;
};

template < class Compare, class NewType, class Converter >
struct compatible_comparison_adaptor : std::binary_function<NewType,NewType,bool>
{
    compatible_comparison_adaptor( const Compare & comp, const Converter & conv)
        : compare(comp), converter(conv) {}

    template< class CompatibleTypeLeft, class CompatibleTypeRight >
    bool operator()( const CompatibleTypeLeft  & x,
                     const CompatibleTypeRight & y) const
    {
        return compare( converter(x), converter(y) );
    }

    private:
    Compare     compare;
    Converter   converter;
};


/// \brief Unary Check adaptor
/**

A simple unary check adaptor.
                                                                                    **/

template < class Compare, class NewType, class Converter >
struct unary_check_adaptor : std::unary_function<NewType,bool>
{
    unary_check_adaptor( const Compare & comp, const Converter & conv ) :
        compare(comp), converter(conv) {}

    bool operator()( STREAMS_BOOST_DEDUCED_TYPENAME call_traits<NewType>::param_type x) const
    {
        return compare( converter(x) );
    }

    private:
    Compare   compare;
    Converter converter;
};

} // namespace detail
} // namespace container_adaptor
} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_CONTAINER_ADAPTOR_DETAIL_COMPARISON_ADAPTOR_HPP


