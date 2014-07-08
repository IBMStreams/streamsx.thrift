//-----------------------------------------------------------------------------
// streams_boost variant/detail/variant_io.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman, Itay Maman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_VARIANT_IO_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_VARIANT_IO_HPP

#include <iosfwd> // for std::basic_ostream forward declare

#include "streams_boost/variant/variant_fwd.hpp"

#include "streams_boost/detail/templated_streams.hpp"
#include "streams_boost/variant/static_visitor.hpp"

namespace streams_boost {

///////////////////////////////////////////////////////////////////////////////
// function template operator<<
//
// Outputs the content of the given variant to the given ostream.
//

// forward declare (allows output of embedded variant< variant< ... >, ... >)
template <
      STREAMS_BOOST_TEMPLATED_STREAM_ARGS(E,T)
    STREAMS_BOOST_TEMPLATED_STREAM_COMMA
      STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename U)
    >
inline STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const variant< STREAMS_BOOST_VARIANT_ENUM_PARAMS(U) >& rhs
    );

namespace detail { namespace variant {

template <typename OStream>
class printer
    : public streams_boost::static_visitor<>
{
private: // representation

    OStream& out_;

public: // structors

    explicit printer(OStream& out)
        : out_( out )
    {
    }

public: // visitor interface

    template <typename T>
    void operator()(const T& operand) const
    {
        out_ << operand;
    }

};

}} // namespace detail::variant

template <
      STREAMS_BOOST_TEMPLATED_STREAM_ARGS(E,T)
    STREAMS_BOOST_TEMPLATED_STREAM_COMMA
      STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename U)
    >
inline STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const variant< STREAMS_BOOST_VARIANT_ENUM_PARAMS(U) >& rhs
    )
{
    detail::variant::printer<
          STREAMS_BOOST_TEMPLATED_STREAM(ostream, E,T)
        > visitor(out);

    rhs.apply_visitor(visitor);

    return out;
}

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_DETAIL_VARIANT_IO_HPP
