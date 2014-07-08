// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IMPLICIT_DWA2002325_STREAMS_HPP
# define IMPLICIT_DWA2002325_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/type.hpp>
# include <streams_boost/python/converter/implicit.hpp>
# include <streams_boost/python/converter/registry.hpp>
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
# include <streams_boost/python/converter/pytype_function.hpp>
#endif
# include <streams_boost/python/type_id.hpp>

namespace streams_boost { namespace python { 

template <class Source, class Target>
void implicitly_convertible(streams_boost::type<Source>* = 0, streams_boost::type<Target>* = 0)
{
    typedef converter::implicit<Source,Target> functions;
    
    converter::registry::push_back(
          &functions::convertible
        , &functions::construct
        , type_id<Target>()
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
        , &converter::expected_from_python_type_direct<Source>::get_pytype
#endif
        );
}

}} // namespace streams_boost::python

#endif // IMPLICIT_DWA2002325_STREAMS_HPP
