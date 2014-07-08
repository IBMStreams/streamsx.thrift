// Copyright Eric Niebler 2005.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STL_ITERATOR_CORE_EAN20051028_HPP
# define STL_ITERATOR_CORE_EAN20051028_HPP

# include <streams_boost/python/object_fwd.hpp>
# include <streams_boost/python/handle_fwd.hpp>

namespace streams_boost { namespace python { namespace objects {

struct STREAMS_BOOST_PYTHON_DECL stl_input_iterator_impl
{
    stl_input_iterator_impl();
    stl_input_iterator_impl(streams_boost::python::object const &ob);
    void increment();
    bool equal(stl_input_iterator_impl const &that) const;
    streams_boost::python::handle<> const &current() const;
private:
    streams_boost::python::object it_;
    streams_boost::python::handle<> ob_;
};

}}} // namespace streams_boost::python::object

#endif // STL_ITERATOR_CORE_EAN20051028_HPP
