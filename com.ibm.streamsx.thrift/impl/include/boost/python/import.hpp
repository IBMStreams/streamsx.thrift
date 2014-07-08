// Copyright Stefan Seefeld 2005.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IMPORT_SS20050624_HPP
# define IMPORT_SS20050624_HPP

# include <streams_boost/python/object.hpp>
# include <streams_boost/python/str.hpp>

namespace streams_boost 
{ 
namespace python 
{

// Import the named module and return a reference to it.
object STREAMS_BOOST_PYTHON_DECL import(str name);

}
}

#endif
