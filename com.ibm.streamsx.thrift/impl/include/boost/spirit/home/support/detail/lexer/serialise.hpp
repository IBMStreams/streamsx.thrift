// examples/serialise.hpp
// Copyright (c) 2007-2009 Ben Hanson (http://www.benhanson.net/)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file licence_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_LEXER_SERIALISE_HPP
#define STREAMS_BOOST_LEXER_SERIALISE_HPP

#include "internals.hpp"
#include "state_machine.hpp"
#include <streams_boost/serialization/vector.hpp>

namespace streams_boost
{
namespace lexer
{
// IMPORTANT! This won't work if you don't enable RTTI!
template<typename CharT, class Archive>
void serialise (basic_state_machine<CharT> &sm_, Archive &ar_,
    unsigned int version_ = 1)
{
    detail::internals &internals_ = const_cast<detail::internals &>
        (sm_.data ());

    ar_ & version_;
    ar_ & *internals_._lookup;
    ar_ & internals_._dfa_alphabet;
    ar_ & *internals_._dfa;
    ar_ & internals_._seen_BOL_assertion;
    ar_ & internals_._seen_EOL_assertion;
}
}
}

#endif
