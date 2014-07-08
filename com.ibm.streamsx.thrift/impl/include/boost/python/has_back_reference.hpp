// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef HAS_BACK_REFERENCE_DWA2002323_STREAMS_HPP
# define HAS_BACK_REFERENCE_DWA2002323_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace python { 

// traits class which users can specialize to indicate that a class
// contains a back-reference to its owning PyObject*
template <class T>
struct has_back_reference
  : mpl::false_
{
};


}} // namespace streams_boost::python

#endif // HAS_BACK_REFERENCE_DWA2002323_STREAMS_HPP
