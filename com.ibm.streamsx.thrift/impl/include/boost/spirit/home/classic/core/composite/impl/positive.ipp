/*=============================================================================
    Copyright (c) 1998-2003 Joel de Guzman
    Copyright (c) 2001 Daniel Nuffer
    Copyright (c) 2002 Hartmut Kaiser
    http://spirit.sourceforge.net/

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_POSITIVE_IPP)
#define STREAMS_BOOST_SPIRIT_POSITIVE_IPP

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    ///////////////////////////////////////////////////////////////////////////
    //
    //  positive class implementation
    //
    ///////////////////////////////////////////////////////////////////////////
    template <typename S>
    inline positive<S>
    operator+(parser<S> const& a)
    {
        return positive<S>(a.derived());
    }

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace streams_boost::spirit

#endif
