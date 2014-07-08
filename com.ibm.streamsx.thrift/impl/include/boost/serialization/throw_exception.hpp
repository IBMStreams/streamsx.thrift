#ifndef STREAMS_BOOST_SERIALIZATION_THROW_EXCEPTION_HPP_INCLUDED
#define STREAMS_BOOST_SERIALIZATION_THROW_EXCEPTION_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//  streams_boost/throw_exception.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#include <streams_boost/config.hpp>

#ifndef STREAMS_BOOST_NO_EXCEPTIONS
#include <exception>
#endif

namespace streams_boost {
namespace serialization {

#ifdef STREAMS_BOOST_NO_EXCEPTIONS

void inline throw_exception(std::exception const & e) {
    ::streams_boost::throw_exception(e);
}

#else

template<class E> inline void throw_exception(E const & e){
    throw e;
}

#endif

} // namespace serialization
} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_SERIALIZATION_THROW_EXCEPTION_HPP_INCLUDED
