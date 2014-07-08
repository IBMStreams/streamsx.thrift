// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IS_AUTO_PTR_DWA2003224_STREAMS_HPP
# define IS_AUTO_PTR_DWA2003224_STREAMS_HPP

# ifndef STREAMS_BOOST_NO_AUTO_PTR
#  include <streams_boost/python/detail/is_xxx.hpp>
#  include <memory>
# endif

namespace streams_boost { namespace python { namespace detail { 

# if !defined(STREAMS_BOOST_NO_AUTO_PTR)

STREAMS_BOOST_PYTHON_IS_XXX_DEF(auto_ptr, std::auto_ptr, 1)

# else

template <class T>
struct is_auto_ptr : mpl::false_
{
};

# endif
    
}}} // namespace streams_boost::python::detail

#endif // IS_AUTO_PTR_DWA2003224_STREAMS_HPP
