/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_HOLDER_TAG_HPP
#define STREAMS_BOOST_FLYWEIGHT_HOLDER_TAG_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <streams_boost/parameter/parameters.hpp>
#include <streams_boost/type_traits/is_base_and_derived.hpp>

namespace streams_boost{

namespace flyweights{

/* Three ways to indicate that a given class T is a holder specifier:
 *   1. Make it derived from holder_marker.
 *   2. Specialize is_holder to evaluate to streams_boost::mpl::true_.
 *   3. Pass it as holder<T> when defining a flyweight type.
 */

struct holder_marker{};

template<typename T>
struct is_holder:is_base_and_derived<holder_marker,T>
{};

template<typename T=parameter::void_>
struct holder:parameter::template_keyword<holder<>,T>
{};

} /* namespace flyweights */

} /* namespace streams_boost */

#endif