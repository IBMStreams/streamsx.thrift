// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef VALUE_IS_SHARED_PTR_DWA2003224_STREAMS_HPP
# define VALUE_IS_SHARED_PTR_DWA2003224_STREAMS_HPP

# include <streams_boost/python/detail/value_is_xxx.hpp>
# include <streams_boost/shared_ptr.hpp>

namespace streams_boost { namespace python { namespace detail { 

STREAMS_BOOST_PYTHON_VALUE_IS_XXX_DEF(shared_ptr, shared_ptr, 1)
    
}}} // namespace streams_boost::python::detail

#endif // VALUE_IS_SHARED_PTR_DWA2003224_STREAMS_HPP
