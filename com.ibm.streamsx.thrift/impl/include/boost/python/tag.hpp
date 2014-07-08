// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef TAG_DWA2002720_STREAMS_HPP
# define TAG_DWA2002720_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

namespace streams_boost { namespace python { 

// used only to prevent argument-dependent lookup from finding the
// wrong function in some cases. Cheaper than qualification.
enum tag_t { tag };

}} // namespace streams_boost::python

#endif // TAG_DWA2002720_STREAMS_HPP
