// Copyright (C) 2005 Arkadiy Vertleyb, Peder Holt.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_STD_iterator_hpp_INCLUDED
#define STREAMS_BOOST_TYPEOF_STD_iterator_hpp_INCLUDED

#include <iterator>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/string.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator_traits, 1)
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_DINKUMWARE_STDLIB, == 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator, 3)
#else
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator, 4)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::iterator, 5)
#endif//STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_DINKUMWARE_STDLIB, == 1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::input_iterator_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::output_iterator_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::forward_iterator_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::bidirectional_iterator_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(std::random_access_iterator_tag)
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_DINKUMWARE_STDLIB, == 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::reverse_iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::reverse_iterator, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::reverse_iterator, 4)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::reverse_iterator, 5)
#else
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::reverse_iterator, 1)
#endif//STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_DINKUMWARE_STDLIB, == 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::back_insert_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::front_insert_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::insert_iterator, 1)
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_DINKUMWARE_STDLIB, == 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 3)
#else
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istream_iterator, 4)
#endif//STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_DINKUMWARE_STDLIB, == 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::ostream_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::ostream_iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::ostream_iterator, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istreambuf_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::istreambuf_iterator, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::ostreambuf_iterator, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(std::ostreambuf_iterator, 2)

#endif//STREAMS_BOOST_TYPEOF_STD_iterator_hpp_INCLUDED
