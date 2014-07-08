/*
  A thread-safe version of Boost.Signals.

  Author: Frank Mori Hess <fmhess@users.sourceforge.net>
  Begin: 2007-01-23
*/
// Copyright Frank Mori Hess 2007-2008
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_PREPROCESSED_SIGNAL_HPP
#define STREAMS_BOOST_SIGNALS2_PREPROCESSED_SIGNAL_HPP

#include <streams_boost/preprocessor/arithmetic.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iteration.hpp>
#include <streams_boost/preprocessor/repetition.hpp>
#include <streams_boost/signals2/detail/preprocessed_arg_type.hpp>
#include <streams_boost/type_traits/add_reference.hpp>

#define STREAMS_BOOST_PP_ITERATION_LIMITS (0, STREAMS_BOOST_SIGNALS2_MAX_ARGS)
#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/signals2/detail/signal_template.hpp>
#include STREAMS_BOOST_PP_ITERATE()

namespace streams_boost
{
  namespace signals2
  {
    template<typename Signature,
      typename Combiner = optional_last_value<typename streams_boost::function_traits<Signature>::result_type>,
      typename Group = int,
      typename GroupCompare = std::less<Group>,
      typename SlotFunction = function<Signature>,
      typename ExtendedSlotFunction = typename detail::extended_signature<function_traits<Signature>::arity, Signature>::function_type,
      typename Mutex = mutex >
    class signal: public detail::signalN<function_traits<Signature>::arity,
      Signature, Combiner, Group, GroupCompare, SlotFunction, ExtendedSlotFunction, Mutex>::type
    {
    private:
      typedef typename detail::signalN<streams_boost::function_traits<Signature>::arity,
        Signature, Combiner, Group, GroupCompare, SlotFunction, ExtendedSlotFunction, Mutex>::type base_type;
    public:
      signal(const Combiner &combiner = Combiner(), const GroupCompare &group_compare = GroupCompare()):
        base_type(combiner, group_compare)
      {}
    };
  }
}

#endif // STREAMS_BOOST_SIGNALS2_PREPROCESSED_SIGNAL_HPP
