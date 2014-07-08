// Boost.Signals2 library

// Copyright Frank Mori Hess 2009.
//
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_SLOT_HPP
#define STREAMS_BOOST_SIGNALS2_SLOT_HPP

#include <streams_boost/bind.hpp>
#include <streams_boost/config.hpp>
#include <streams_boost/function.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/ref.hpp>
#include <streams_boost/signals2/detail/signals_common.hpp>
#include <streams_boost/signals2/detail/signals_common_macros.hpp>
#include <streams_boost/signals2/detail/tracked_objects_visitor.hpp>
#include <streams_boost/signals2/slot_base.hpp>
#include <streams_boost/visit_each.hpp>
#include <streams_boost/weak_ptr.hpp>

#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES
#include <streams_boost/signals2/preprocessed_slot.hpp>
#else
#include <streams_boost/signals2/variadic_slot.hpp>
#endif

#endif // STREAMS_BOOST_SIGNALS2_SLOT_HPP
