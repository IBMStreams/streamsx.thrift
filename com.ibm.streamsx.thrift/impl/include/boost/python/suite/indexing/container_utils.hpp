
//  (C) Copyright Joel de Guzman 2003.
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef PY_CONTAINER_UTILS_JDG20038_HPP
# define PY_CONTAINER_UTILS_JDG20038_HPP

# include <utility>
# include <streams_boost/foreach.hpp>
# include <streams_boost/python/object.hpp>
# include <streams_boost/python/handle.hpp>
# include <streams_boost/python/extract.hpp>
# include <streams_boost/python/stl_iterator.hpp>

namespace streams_boost { namespace python { namespace container_utils {
        
    template <typename Container>
    void
    extend_container(Container& container, object l)
    {
        typedef typename Container::value_type data_type;
        
        //  l must be iterable
        STREAMS_BOOST_FOREACH(object elem,
            std::make_pair(
              streams_boost::python::stl_input_iterator<object>(l),
              streams_boost::python::stl_input_iterator<object>()
              ))
        {
            extract<data_type const&> x(elem);
            //  try if elem is an exact data_type type
            if (x.check())
            {
                container.push_back(x());
            }
            else
            {
                //  try to convert elem to data_type type
                extract<data_type> x(elem);
                if (x.check())
                {
                    container.push_back(x());
                }
                else
                {
                    PyErr_SetString(PyExc_TypeError, "Incompatible Data Type");
                    throw_error_already_set();
                }
            }
        }          
    }

}}} // namespace streams_boost::python::container_utils

#endif
