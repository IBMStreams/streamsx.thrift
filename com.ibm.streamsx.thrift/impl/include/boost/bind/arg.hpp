#ifndef STREAMS_BOOST_BIND_ARG_HPP_INCLUDED
#define STREAMS_BOOST_BIND_ARG_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/arg.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  See http://www.streams_boost.org/libs/bind/bind.html for documentation.
//

#include <streams_boost/config.hpp>
#include <streams_boost/is_placeholder.hpp>

namespace streams_boost
{

template< int I > struct arg
{
    arg()
    {
    }

    template< class T > arg( T const & /* t */ )
    {
        // static assert I == is_placeholder<T>::value
        typedef char T_must_be_placeholder[ I == is_placeholder<T>::value? 1: -1 ];
    }
};

template< int I > bool operator==( arg<I> const &, arg<I> const & )
{
    return true;
}

#if !defined( STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION )

template< int I > struct is_placeholder< arg<I> >
{
    enum _vt { value = I };
};

template< int I > struct is_placeholder< arg<I> (*) () >
{
    enum _vt { value = I };
};

#endif

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_BIND_ARG_HPP_INCLUDED
