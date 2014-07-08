/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(SPIRIT_WHAT_FUNCTION_APRIL_22_2007_0236PM)
#define SPIRIT_WHAT_FUNCTION_APRIL_22_2007_0236PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <string>
#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/detail/workaround.hpp>

namespace streams_boost { namespace spirit { namespace detail
{
    template <typename Context>
    struct what_function
    {
        what_function(info& what, Context& context)
          : what(what), context(context)
        {
            what.value = std::list<info>();
        }

        template <typename Component>
        void operator()(Component const& component) const
        {
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1600))
            component; // suppresses warning: C4100: 'component' : unreferenced formal parameter
#endif
            get<std::list<info> >(what.value).push_back(component.what(context));
        }

        info& what;
        Context& context;

    private:
        // silence MSVC warning C4512: assignment operator could not be generated
        what_function& operator= (what_function const&);
    };
}}}

#endif
