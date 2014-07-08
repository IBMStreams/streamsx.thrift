// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef SHARED_PTR_TO_PYTHON_DWA2003224_STREAMS_HPP
# define SHARED_PTR_TO_PYTHON_DWA2003224_STREAMS_HPP

# include <streams_boost/python/refcount.hpp>
# include <streams_boost/python/converter/shared_ptr_deleter.hpp>
# include <streams_boost/shared_ptr.hpp>
# include <streams_boost/get_pointer.hpp>

namespace streams_boost { namespace python { namespace converter { 

template <class T>
PyObject* shared_ptr_to_python(shared_ptr<T> const& x)
{
    if (!x)
        return python::detail::none();
    else if (shared_ptr_deleter* d = streams_boost::get_deleter<shared_ptr_deleter>(x))
        return incref( get_pointer( d->owner ) );
    else
        return converter::registered<shared_ptr<T> const&>::converters.to_python(&x);
}

}}} // namespace streams_boost::python::converter

#endif // SHARED_PTR_TO_PYTHON_DWA2003224_STREAMS_HPP
