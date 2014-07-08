/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_NO_LOCKING_HPP
#define STREAMS_BOOST_FLYWEIGHT_NO_LOCKING_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/flyweight/no_locking_fwd.hpp>
#include <streams_boost/flyweight/locking_tag.hpp>

/* null locking policy */

namespace streams_boost{

namespace flyweights{

struct no_locking:locking_marker
{
  struct             mutex_type{};
  typedef mutex_type lock_type;
};

} /* namespace flyweights */

} /* namespace streams_boost */

#endif
