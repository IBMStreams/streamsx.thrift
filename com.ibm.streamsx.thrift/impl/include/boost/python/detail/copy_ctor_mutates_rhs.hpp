// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef COPY_CTOR_MUTATES_RHS_DWA2003219_STREAMS_HPP
# define COPY_CTOR_MUTATES_RHS_DWA2003219_STREAMS_HPP

#include <streams_boost/python/detail/is_auto_ptr.hpp>
#include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace python { namespace detail { 

template <class T>
struct copy_ctor_mutates_rhs
    : is_auto_ptr<T>
{
};

}}} // namespace streams_boost::python::detail

#endif // COPY_CTOR_MUTATES_RHS_DWA2003219_STREAMS_HPP
