// Copyright Stefan Seefeld 2005.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef EXEC_SS20050616_HPP
# define EXEC_SS20050616_HPP

# include <streams_boost/python/object.hpp>
# include <streams_boost/python/str.hpp>

namespace streams_boost 
{ 
namespace python 
{

// Evaluate python expression from str.
// global and local are the global and local scopes respectively,
// used during evaluation.
object 
STREAMS_BOOST_PYTHON_DECL
eval(str string, object global = object(), object local = object());

// Execute an individual python statement from str.
// global and local are the global and local scopes respectively,
// used during execution.
object 
STREAMS_BOOST_PYTHON_DECL
exec_statement(str string, object global = object(), object local = object());

// Execute python source code from str.
// global and local are the global and local scopes respectively,
// used during execution.
object 
STREAMS_BOOST_PYTHON_DECL
exec(str string, object global = object(), object local = object());

// Execute python source code from file filename.
// global and local are the global and local scopes respectively,
// used during execution.
object 
STREAMS_BOOST_PYTHON_DECL
exec_file(str filename, object global = object(), object local = object());

}
}

#endif
