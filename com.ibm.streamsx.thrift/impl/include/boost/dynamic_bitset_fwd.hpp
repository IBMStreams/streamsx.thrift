// -----------------------------------------------------------
//
//   Copyright (c) 2001-2002 Chuck Allison and Jeremy Siek
//            Copyright (c) 2003-2004 Gennaro Prota
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// -----------------------------------------------------------

#ifndef STREAMS_BOOST_DYNAMIC_BITSET_FWD_HPP
#define STREAMS_BOOST_DYNAMIC_BITSET_FWD_HPP

#include <memory>

namespace streams_boost {

template <typename Block = unsigned long,
          typename Allocator = std::allocator<Block> >
class dynamic_bitset;

}

#endif // include guard
