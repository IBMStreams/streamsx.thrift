// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef OVERLOADS_FWD_DWA2002101_STREAMS_HPP
# define OVERLOADS_FWD_DWA2002101_STREAMS_HPP

namespace streams_boost { namespace python { namespace detail { 

// forward declarations
struct overloads_base;
  
template <class OverloadsT, class NameSpaceT, class SigT>
inline void define_with_defaults(char const* name, OverloadsT const&, NameSpaceT&, SigT const&);

}}} // namespace streams_boost::python::detail

#endif // OVERLOADS_FWD_DWA2002101_STREAMS_HPP
