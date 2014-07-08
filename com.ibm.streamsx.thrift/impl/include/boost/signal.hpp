// Boost.Signals library

// Copyright Douglas Gregor 2001-2006. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org/libs/signals

#ifndef STREAMS_BOOST_SIGNAL_HPP
#define STREAMS_BOOST_SIGNAL_HPP

#ifndef STREAMS_BOOST_SIGNALS_MAX_ARGS
#  define STREAMS_BOOST_SIGNALS_MAX_ARGS 10
#endif

#include <streams_boost/config.hpp>
#include <streams_boost/type_traits/function_traits.hpp>
#include <streams_boost/signals/signal0.hpp>
#include <streams_boost/signals/signal1.hpp>
#include <streams_boost/signals/signal2.hpp>
#include <streams_boost/signals/signal3.hpp>
#include <streams_boost/signals/signal4.hpp>
#include <streams_boost/signals/signal5.hpp>
#include <streams_boost/signals/signal6.hpp>
#include <streams_boost/signals/signal7.hpp>
#include <streams_boost/signals/signal8.hpp>
#include <streams_boost/signals/signal9.hpp>
#include <streams_boost/signals/signal10.hpp>
#include <streams_boost/function.hpp>

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_PREFIX
#endif

namespace streams_boost {
#ifndef STREAMS_BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX
  namespace STREAMS_BOOST_SIGNALS_NAMESPACE {
    namespace detail {
      template<int Arity,
               typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl;

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<0, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal0<typename traits::result_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<1, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal1<typename traits::result_type,
                        typename traits::arg1_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<2, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal2<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<3, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal3<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<4, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal4<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        typename traits::arg4_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<5, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal5<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        typename traits::arg4_type,
                        typename traits::arg5_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<6, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal6<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        typename traits::arg4_type,
                        typename traits::arg5_type,
                        typename traits::arg6_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<7, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal7<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        typename traits::arg4_type,
                        typename traits::arg5_type,
                        typename traits::arg6_type,
                        typename traits::arg7_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<8, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal8<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        typename traits::arg4_type,
                        typename traits::arg5_type,
                        typename traits::arg6_type,
                        typename traits::arg7_type,
                        typename traits::arg8_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<9, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal9<typename traits::result_type,
                        typename traits::arg1_type,
                        typename traits::arg2_type,
                        typename traits::arg3_type,
                        typename traits::arg4_type,
                        typename traits::arg5_type,
                        typename traits::arg6_type,
                        typename traits::arg7_type,
                        typename traits::arg8_type,
                        typename traits::arg9_type,
                        Combiner,
                        Group,
                        GroupCompare,
                        SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      class real_get_signal_impl<10, Signature, Combiner, Group, GroupCompare,
                                 SlotFunction>
      {
        typedef function_traits<Signature> traits;

      public:
        typedef signal10<typename traits::result_type,
                         typename traits::arg1_type,
                         typename traits::arg2_type,
                         typename traits::arg3_type,
                         typename traits::arg4_type,
                         typename traits::arg5_type,
                         typename traits::arg6_type,
                         typename traits::arg7_type,
                         typename traits::arg8_type,
                         typename traits::arg9_type,
                         typename traits::arg10_type,
                         Combiner,
                         Group,
                         GroupCompare,
                         SlotFunction> type;
      };

      template<typename Signature,
               typename Combiner,
               typename Group,
               typename GroupCompare,
               typename SlotFunction>
      struct get_signal_impl :
        public real_get_signal_impl<(function_traits<Signature>::arity),
                                    Signature,
                                    Combiner,
                                    Group,
                                    GroupCompare,
                                    SlotFunction>
      {
      };

    } // end namespace detail
  } // end namespace STREAMS_BOOST_SIGNALS_NAMESPACE

  // Very lightweight wrapper around the signalN classes that allows signals to
  // be created where the number of arguments does not need to be part of the
  // class name.
  template<
    typename Signature, // function type R (T1, T2, ..., TN)
    typename Combiner = last_value<typename function_traits<Signature>::result_type>,
    typename Group = int,
    typename GroupCompare = std::less<Group>,
    typename SlotFunction = function<Signature>
  >
  class signal :
    public STREAMS_BOOST_SIGNALS_NAMESPACE::detail::get_signal_impl<Signature,
                                                            Combiner,
                                                            Group,
                                                            GroupCompare,
                                                            SlotFunction>::type
  {
    typedef typename STREAMS_BOOST_SIGNALS_NAMESPACE::detail::get_signal_impl<
                       Signature,
                       Combiner,
                       Group,
                       GroupCompare,
                       SlotFunction>::type base_type;

  public:
    explicit signal(const Combiner& combiner = Combiner(),
                    const GroupCompare& group_compare = GroupCompare()) :
      base_type(combiner, group_compare)
    {
    }
  };
#endif // ndef STREAMS_BOOST_FUNCTION_NO_FUNCTION_TYPE_SYNTAX

} // end namespace streams_boost

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif

#endif // STREAMS_BOOST_SIGNAL_HPP
