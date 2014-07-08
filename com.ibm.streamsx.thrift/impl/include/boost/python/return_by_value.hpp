// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef BY_VALUE_DWA20021015_STREAMS_HPP
# define BY_VALUE_DWA20021015_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/to_python_value.hpp>
# include <streams_boost/type_traits/add_reference.hpp>
# include <streams_boost/type_traits/add_const.hpp>

# include <streams_boost/python/detail/value_arg.hpp>

namespace streams_boost { namespace python { 

struct return_by_value
{
    template <class R>
    struct apply
    {
       typedef to_python_value<
           typename detail::value_arg<R>::type
       > type;
    };
};

}} // namespace streams_boost::python

#endif // BY_VALUE_DWA20021015_STREAMS_HPP
