// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef IMPLICIT_CAST_DWA200356_STREAMS_HPP
# define IMPLICIT_CAST_DWA200356_STREAMS_HPP

# include <streams_boost/mpl/identity.hpp>

namespace streams_boost {

// implementation originally suggested by C. Green in
// http://lists.streams_boost.org/MailArchives/streams_boost/msg00886.php

// The use of identity creates a non-deduced form, so that the
// explicit template argument must be supplied
template <typename T>
inline T implicit_cast (typename mpl::identity<T>::type x) {
    return x;
}

// incomplete return type now is here
//template <typename T>
//void implicit_cast (...);

} // namespace streams_boost


#endif // IMPLICIT_CAST_DWA200356_STREAMS_HPP
