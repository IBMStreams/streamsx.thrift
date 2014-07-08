// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef CLASS_FWD_DWA200222_STREAMS_HPP
# define CLASS_FWD_DWA200222_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/detail/not_specified.hpp>

namespace streams_boost { namespace python { 

template <
    class T // class being wrapped
    // arbitrarily-ordered optional arguments. Full qualification needed for MSVC6
    , class X1 = ::streams_boost::python::detail::not_specified
    , class X2 = ::streams_boost::python::detail::not_specified
    , class X3 = ::streams_boost::python::detail::not_specified
    >
class class_;

}} // namespace streams_boost::python

#endif // CLASS_FWD_DWA200222_STREAMS_HPP
