//  A thread-safe version of Boost.Signals.

// Copyright Frank Mori Hess 2007-2009
//
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_SIGNAL_HPP
#define STREAMS_BOOST_SIGNALS2_SIGNAL_HPP

#include <algorithm>
#include <streams_boost/assert.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/function.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/signals2/connection.hpp>
#include <streams_boost/signals2/detail/unique_lock.hpp>
#include <streams_boost/signals2/detail/replace_slot_function.hpp>
#include <streams_boost/signals2/detail/result_type_wrapper.hpp>
#include <streams_boost/signals2/detail/signals_common.hpp>
#include <streams_boost/signals2/detail/signals_common_macros.hpp>
#include <streams_boost/signals2/detail/slot_groups.hpp>
#include <streams_boost/signals2/detail/slot_call_iterator.hpp>
#include <streams_boost/signals2/optional_last_value.hpp>
#include <streams_boost/signals2/mutex.hpp>
#include <streams_boost/signals2/slot.hpp>
#include <streams_boost/throw_exception.hpp>
#include <functional>

#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES
#include <streams_boost/signals2/preprocessed_signal.hpp>
#else
#include <streams_boost/signals2/variadic_signal.hpp>
#endif

#endif // STREAMS_BOOST_SIGNALS2_SIGNAL_HPP
