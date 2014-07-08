//-----------------------------------------------------------------------------
// streams_boost variant/bad_visit.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_BAD_VISIT_HPP
#define STREAMS_BOOST_VARIANT_BAD_VISIT_HPP

#include <exception>

namespace streams_boost {

//////////////////////////////////////////////////////////////////////////
// class bad_visit
//
// Exception thrown when a visitation attempt via apply_visitor fails due
// to invalid visited subtype or contents.
//
struct bad_visit
    : std::exception
{
public: // std::exception interface

    virtual const char * what() const throw()
    {
        return "streams_boost::bad_visit: "
               "failed visitation using streams_boost::apply_visitor";
    }

};

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_BAD_VISIT_HPP
