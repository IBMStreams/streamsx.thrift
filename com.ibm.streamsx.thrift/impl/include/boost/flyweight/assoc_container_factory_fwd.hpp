/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/flyweight for library home page.
 */

#ifndef STREAMS_BOOST_FLYWEIGHT_ASSOC_CONTAINER_FACTORY_FWD_HPP
#define STREAMS_BOOST_FLYWEIGHT_ASSOC_CONTAINER_FACTORY_FWD_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/flyweight/detail/not_placeholder_expr.hpp>

namespace streams_boost{

namespace flyweights{

template<typename Container>
class assoc_container_factory_class;

template<
  typename ContainerSpecifier
  STREAMS_BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION
>
struct assoc_container_factory;

}  /* namespace flyweights */

} /* namespace streams_boost */

#endif
