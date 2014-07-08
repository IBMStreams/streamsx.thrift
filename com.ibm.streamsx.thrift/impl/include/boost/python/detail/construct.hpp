// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef CONSTRUCT_REFERENCE_DWA2002716_STREAMS_HPP
# define CONSTRUCT_REFERENCE_DWA2002716_STREAMS_HPP

namespace streams_boost { namespace python { namespace detail { 

template <class T, class Arg>
void construct_pointee(void* storage, Arg& x
# if !defined(STREAMS_BOOST_MSVC) || STREAMS_BOOST_MSVC > 1300
                       , T const volatile*
# else 
                       , T const*
# endif 
    )
{
    new (storage) T(x);
}

template <class T, class Arg>
void construct_referent_impl(void* storage, Arg& x, T&(*)())
{
    construct_pointee(storage, x, (T*)0);
}

template <class T, class Arg>
void construct_referent(void* storage, Arg const& x, T(*tag)() = 0)
{
    construct_referent_impl(storage, x, tag);
}

template <class T, class Arg>
void construct_referent(void* storage, Arg& x, T(*tag)() = 0)
{
    construct_referent_impl(storage, x, tag);
}

}}} // namespace streams_boost::python::detail

#endif // CONSTRUCT_REFERENCE_DWA2002716_STREAMS_HPP
