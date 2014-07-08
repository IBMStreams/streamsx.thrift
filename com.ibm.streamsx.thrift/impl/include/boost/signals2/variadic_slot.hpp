// Boost.Signals2 library

// Copyright Frank Mori Hess 2009.
//
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_VARIADIC_SLOT_HPP
#define STREAMS_BOOST_SIGNALS2_VARIADIC_SLOT_HPP

#include <streams_boost/signals2/detail/variadic_arg_type.hpp>

#define STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTORS \
  template<typename ... BindArgs> slot(const BindArgs & ... args) \
  { \
    init_slot_function(streams_boost::bind(args...)); \
  }


#include <streams_boost/signals2/detail/slot_template.hpp>
#endif // STREAMS_BOOST_SIGNALS2_VARIADIC_SLOT_HPP
