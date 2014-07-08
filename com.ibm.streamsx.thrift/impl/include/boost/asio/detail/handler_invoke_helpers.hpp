//
// handler_invoke_helpers.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_ASIO_DETAIL_HANDLER_INVOKE_HELPERS_HPP
#define STREAMS_BOOST_ASIO_DETAIL_HANDLER_INVOKE_HELPERS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <streams_boost/asio/detail/push_options.hpp>

#include <streams_boost/asio/detail/push_options.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/utility/addressof.hpp>
#include <streams_boost/asio/detail/pop_options.hpp>

#include <streams_boost/asio/handler_invoke_hook.hpp>

// Calls to asio_handler_invoke must be made from a namespace that does not
// contain overloads of this function. The streams_boost_asio_handler_invoke_helpers
// namespace is defined here for that purpose.
namespace streams_boost_asio_handler_invoke_helpers {

template <typename Function, typename Context>
inline void invoke(const Function& function, Context& context)
{
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) \
  || STREAMS_BOOST_WORKAROUND(__GNUC__, < 3)
  Function tmp(function);
  tmp();
#else
  using namespace streams_boost::asio;
  asio_handler_invoke(function, streams_boost::addressof(context));
#endif
}

} // namespace streams_boost_asio_handler_invoke_helpers

#include <streams_boost/asio/detail/pop_options.hpp>

#endif // STREAMS_BOOST_ASIO_DETAIL_HANDLER_INVOKE_HELPERS_HPP
