/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 1999-2003 Jeremiah Willcock
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_IN_05042005_0120)
#define STREAMS_BOOST_IN_05042005_0120

#include <istream>
#include <streams_boost/fusion/sequence/io/detail/in.hpp>
#include <streams_boost/fusion/support/is_sequence.hpp>

namespace streams_boost { namespace fusion
{
    template <typename Sequence>
    inline std::istream&
    in(std::istream& is, Sequence& seq)
    {
        detail::read_sequence(is, seq);
        return is;
    }

    namespace operators
    {
        template <typename Sequence>
        inline typename
            enable_if<
               fusion::traits::is_sequence<Sequence>
              , std::istream&
            >::type
        operator>>(std::istream& is, Sequence& seq)
        {
            return fusion::in(is, seq);
        }
    }
    using operators::operator>>;
}}

#endif
