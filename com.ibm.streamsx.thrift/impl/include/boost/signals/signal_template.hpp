// Boost.Signals library

// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

// This file intentionally does not have include guards, because it is meant
// to be included multiple times (one for each signalN class). The
// STREAMS_BOOST_SIGNALS_SIGNAL_TEMPLATE_HEADER_INCLUDED macro merely serves to
// suppress reinclusion of the files that this header depends on.

#ifndef STREAMS_BOOST_SIGNALS_SIGNAL_TEMPLATE_HEADER_INCLUDED
#define STREAMS_BOOST_SIGNALS_SIGNAL_TEMPLATE_HEADER_INCLUDED
#  include <streams_boost/config.hpp>
#  include <streams_boost/signals/connection.hpp>
#  include <streams_boost/utility.hpp>
#  include <streams_boost/ref.hpp>
#  include <streams_boost/signals/slot.hpp>
#  include <streams_boost/last_value.hpp>
#  include <streams_boost/signals/detail/signal_base.hpp>
#  include <streams_boost/signals/detail/slot_call_iterator.hpp>
#  include <streams_boost/mpl/bool.hpp>
#  include <streams_boost/type_traits/is_convertible.hpp>
#  include <cassert>
#  include <functional>
#  include <memory>
#endif // !STREAMS_BOOST_SIGNALS_SIGNAL_TEMPLATE_HEADER_INCLUDED

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_PREFIX
#endif

// Include the appropriate functionN header
#define STREAMS_BOOST_SIGNAL_FUNCTION_N_HEADER STREAMS_BOOST_JOIN(<streams_boost/function/function,STREAMS_BOOST_SIGNALS_NUM_ARGS.hpp>)
#include STREAMS_BOOST_SIGNAL_FUNCTION_N_HEADER

// Determine if a comma should follow a listing of the arguments/parameters
#if STREAMS_BOOST_SIGNALS_NUM_ARGS == 0
#  define STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
#else
#  define STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS ,
#endif // STREAMS_BOOST_SIGNALS_NUM_ARGS > 0

// Define class names used
#define STREAMS_BOOST_SIGNALS_SIGNAL STREAMS_BOOST_JOIN(signal,STREAMS_BOOST_SIGNALS_NUM_ARGS)
#define STREAMS_BOOST_SIGNALS_FUNCTION STREAMS_BOOST_JOIN(function,STREAMS_BOOST_SIGNALS_NUM_ARGS)
#define STREAMS_BOOST_SIGNALS_ARGS_STRUCT STREAMS_BOOST_JOIN(args,STREAMS_BOOST_SIGNALS_NUM_ARGS)
#define STREAMS_BOOST_SIGNALS_CALL_BOUND STREAMS_BOOST_JOIN(call_bound,STREAMS_BOOST_SIGNALS_NUM_ARGS)

// Define commonly-used instantiations
#define STREAMS_BOOST_SIGNALS_ARGS_STRUCT_INST \
  STREAMS_BOOST_SIGNALS_NAMESPACE::detail::STREAMS_BOOST_SIGNALS_ARGS_STRUCT<STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS>

namespace streams_boost {
  namespace STREAMS_BOOST_SIGNALS_NAMESPACE {
    namespace detail {
      // Holds the arguments for a bound slot call in a single place
      template<STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
               STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
               typename Dummy = int>
      struct STREAMS_BOOST_SIGNALS_ARGS_STRUCT {
        STREAMS_BOOST_SIGNALS_ARGS_STRUCT(STREAMS_BOOST_SIGNALS_COPY_PARMS)
          STREAMS_BOOST_SIGNALS_INIT_ARGS
        {
        }

        STREAMS_BOOST_SIGNALS_ARGS_AS_MEMBERS
      };

      // Function object that calls the function object given to it, passing
      // the bound arguments along to that underlying function object
      template<typename R>
      struct STREAMS_BOOST_SIGNALS_CALL_BOUND {
        template<STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
                 STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
                 typename F>
        struct caller {
          typedef STREAMS_BOOST_SIGNALS_ARGS_STRUCT<STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS>*
            args_type;

          args_type args;

          typedef R result_type;

          caller() {}
          caller(args_type a) : args(a) {}

          template<typename Pair>
          R operator()(const Pair& slot) const
          {
            F* target = const_cast<F*>(unsafe_any_cast<F>(&slot.second));
            return (*target)(STREAMS_BOOST_SIGNALS_BOUND_ARGS);
          }
        };
      };

      template<>
      struct STREAMS_BOOST_SIGNALS_CALL_BOUND<void> {
        template<STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
                 STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
                 typename F>
        struct caller {
          typedef STREAMS_BOOST_SIGNALS_ARGS_STRUCT<STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS>*
            args_type;

          args_type args;

          typedef unusable result_type;

          caller(args_type a) : args(a) {}

          template<typename Pair>
          unusable operator()(const Pair& slot) const
          {
            F* target = const_cast<F*>(unsafe_any_cast<F>(&slot.second));
            (*target)(STREAMS_BOOST_SIGNALS_BOUND_ARGS);
            return unusable();
          }
        };
      };
    } // namespace detail
  } // namespace STREAMS_BOOST_SIGNALS_NAMESPACE

  // The actual signalN class
  template<
    typename R,
    STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    typename Combiner = last_value<R>,
    typename Group = int,
    typename GroupCompare = std::less<Group>,
    typename SlotFunction = STREAMS_BOOST_SIGNALS_FUNCTION<
                              R STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
                              STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS>
  >
  class STREAMS_BOOST_SIGNALS_SIGNAL :
    public STREAMS_BOOST_SIGNALS_NAMESPACE::detail::signal_base, // management of slot list
    public STREAMS_BOOST_SIGNALS_NAMESPACE::trackable // signals are trackable
  {
  public:
    // The slot function type
    typedef SlotFunction slot_function_type;

    // Result type of a slot
    typedef typename STREAMS_BOOST_SIGNALS_NAMESPACE::detail::slot_result_type<R>::type
      slot_result_type;

    // Argument types
    STREAMS_BOOST_SIGNALS_ARG_TYPES

#if STREAMS_BOOST_SIGNALS_NUM_ARGS == 1
    typedef T1 argument_type;
#elif STREAMS_BOOST_SIGNALS_NUM_ARGS == 2
    typedef T1 first_argument_type;
    typedef T2 second_argument_type;
#endif

  private:
    // The real slot name comparison object type
    typedef STREAMS_BOOST_SIGNALS_NAMESPACE::detail::group_bridge_compare<GroupCompare, Group>
      real_group_compare_type;

    // The function object passed to the slot call iterator that will call
    // the underlying slot function with its arguments bound
    typedef STREAMS_BOOST_SIGNALS_NAMESPACE::detail::STREAMS_BOOST_SIGNALS_CALL_BOUND<R>
      outer_bound_slot_caller;
    typedef typename outer_bound_slot_caller::template
              caller<STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
                     STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
                     slot_function_type>
      call_bound_slot;

  public:
    // Combiner's result type
    typedef typename Combiner::result_type result_type;

    // Combiner type
    typedef Combiner combiner_type;

    // Slot type
    typedef slot<slot_function_type> slot_type;

    // Slot name type and comparison
    typedef Group group_type;
    typedef GroupCompare group_compare_type;

    typedef STREAMS_BOOST_SIGNALS_NAMESPACE::detail::slot_call_iterator<
              call_bound_slot, iterator> slot_call_iterator;

    explicit
    STREAMS_BOOST_SIGNALS_SIGNAL(const Combiner& c = Combiner(),
                         const GroupCompare& comp = GroupCompare()) :
      STREAMS_BOOST_SIGNALS_NAMESPACE::detail::signal_base(real_group_compare_type(comp),
                                                   c)
    {
    }

    // Connect a slot to this signal
    STREAMS_BOOST_SIGNALS_NAMESPACE::connection
    connect(const slot_type&,
            STREAMS_BOOST_SIGNALS_NAMESPACE::connect_position at
              = STREAMS_BOOST_SIGNALS_NAMESPACE::at_back);


    STREAMS_BOOST_SIGNALS_NAMESPACE::connection
    connect(const group_type&, const slot_type&,
            STREAMS_BOOST_SIGNALS_NAMESPACE::connect_position at
              = STREAMS_BOOST_SIGNALS_NAMESPACE::at_back);

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
    // MSVC 6.0 and 7.0 don't handle the is_convertible test well
    void disconnect(const group_type& group)
    {
      impl->disconnect(group);
    }
#else
    template<typename T>
    void disconnect(const T& t)
    {
      typedef mpl::bool_<(is_convertible<T, group_type>::value)> is_group;
      this->do_disconnect(t, is_group());
    }

  private:
    // Disconnect a named slot
    void do_disconnect(const group_type& group, mpl::bool_<true>)
    {
      impl->disconnect(group);
    }

    template<typename Function>
    void do_disconnect(const Function& f, mpl::bool_<false>)
    {
      // Notify the slot handling code that we are iterating through the slots
      STREAMS_BOOST_SIGNALS_NAMESPACE::detail::call_notification notification(this->impl);

      for (iterator i = impl->slots_.begin(); i != impl->slots_.end(); ++i) {
        slot_function_type& s = *unsafe_any_cast<slot_function_type>(&i->second);
        if (s == f) i->first.disconnect();
      }
    }
#endif

  public:

    // Emit the signal
    result_type operator()(STREAMS_BOOST_SIGNALS_PARMS);
    result_type operator()(STREAMS_BOOST_SIGNALS_PARMS) const;

    Combiner& combiner()
    { return *unsafe_any_cast<Combiner>(&impl->combiner_); }

    const Combiner& combiner() const
    { return *unsafe_any_cast<const Combiner>(&impl->combiner_); }
  };

  template<
    typename R,
    STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    typename Combiner,
    typename Group,
    typename GroupCompare,
    typename SlotFunction
  >
  STREAMS_BOOST_SIGNALS_NAMESPACE::connection
  STREAMS_BOOST_SIGNALS_SIGNAL<
    R, STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    Combiner, Group, GroupCompare, SlotFunction
  >::connect(const slot_type& in_slot,
             STREAMS_BOOST_SIGNALS_NAMESPACE::connect_position at)
  {
    using streams_boost::STREAMS_BOOST_SIGNALS_NAMESPACE::detail::stored_group;

    // If the slot has been disconnected, just return a disconnected
    // connection
    if (!in_slot.is_active()) {
      return STREAMS_BOOST_SIGNALS_NAMESPACE::connection();
    }

    return impl->connect_slot(in_slot.get_slot_function(), stored_group(),
                              in_slot.get_data(), at);
  }

  template<
    typename R,
    STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    typename Combiner,
    typename Group,
    typename GroupCompare,
    typename SlotFunction
  >
  STREAMS_BOOST_SIGNALS_NAMESPACE::connection
  STREAMS_BOOST_SIGNALS_SIGNAL<
    R, STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    Combiner, Group, GroupCompare, SlotFunction
  >::connect(const group_type& group,
             const slot_type& in_slot,
             STREAMS_BOOST_SIGNALS_NAMESPACE::connect_position at)
  {
    // If the slot has been disconnected, just return a disconnected
    // connection
    if (!in_slot.is_active()) {
      return STREAMS_BOOST_SIGNALS_NAMESPACE::connection();
    }

    return impl->connect_slot(in_slot.get_slot_function(), group,
                              in_slot.get_data(), at);
  }

  template<
    typename R,
    STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    typename Combiner,
    typename Group,
    typename GroupCompare,
    typename SlotFunction
  >
  typename STREAMS_BOOST_SIGNALS_SIGNAL<
             R, STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
             STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
             Combiner, Group, GroupCompare, SlotFunction>::result_type
  STREAMS_BOOST_SIGNALS_SIGNAL<
    R, STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    Combiner, Group, GroupCompare, SlotFunction
  >::operator()(STREAMS_BOOST_SIGNALS_PARMS)
  {
    // Notify the slot handling code that we are making a call
    STREAMS_BOOST_SIGNALS_NAMESPACE::detail::call_notification notification(this->impl);

    // Construct a function object that will call the underlying slots
    // with the given arguments.
#if STREAMS_BOOST_SIGNALS_NUM_ARGS == 0
    STREAMS_BOOST_SIGNALS_ARGS_STRUCT_INST args;
#else
    STREAMS_BOOST_SIGNALS_ARGS_STRUCT_INST args(STREAMS_BOOST_SIGNALS_ARGS);
#endif // STREAMS_BOOST_SIGNALS_NUM_ARGS > 0
    call_bound_slot f(&args);

    typedef typename call_bound_slot::result_type result_type;
    optional<result_type> cache;
    // Let the combiner call the slots via a pair of input iterators
    return combiner()(slot_call_iterator(notification.impl->slots_.begin(),
                                         impl->slots_.end(), f, cache),
                      slot_call_iterator(notification.impl->slots_.end(),
                                         impl->slots_.end(), f, cache));
  }

  template<
    typename R,
    STREAMS_BOOST_SIGNALS_TEMPLATE_PARMS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    typename Combiner,
    typename Group,
    typename GroupCompare,
    typename SlotFunction
  >
  typename STREAMS_BOOST_SIGNALS_SIGNAL<
             R, STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
             STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
             Combiner, Group, GroupCompare, SlotFunction>::result_type
  STREAMS_BOOST_SIGNALS_SIGNAL<
    R, STREAMS_BOOST_SIGNALS_TEMPLATE_ARGS
    STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS
    Combiner, Group, GroupCompare, SlotFunction
  >::operator()(STREAMS_BOOST_SIGNALS_PARMS) const
  {
    // Notify the slot handling code that we are making a call
    STREAMS_BOOST_SIGNALS_NAMESPACE::detail::call_notification notification(this->impl);

    // Construct a function object that will call the underlying slots
    // with the given arguments.
#if STREAMS_BOOST_SIGNALS_NUM_ARGS == 0
    STREAMS_BOOST_SIGNALS_ARGS_STRUCT_INST args;
#else
    STREAMS_BOOST_SIGNALS_ARGS_STRUCT_INST args(STREAMS_BOOST_SIGNALS_ARGS);
#endif // STREAMS_BOOST_SIGNALS_NUM_ARGS > 0

    call_bound_slot f(&args);

    typedef typename call_bound_slot::result_type result_type;
    optional<result_type> cache;

    // Let the combiner call the slots via a pair of input iterators
    return combiner()(slot_call_iterator(notification.impl->slots_.begin(),
                                         impl->slots_.end(), f, cache),
                      slot_call_iterator(notification.impl->slots_.end(),
                                         impl->slots_.end(), f, cache));
  }
} // namespace streams_boost

#undef STREAMS_BOOST_SIGNAL_FUNCTION_N_HEADER
#undef STREAMS_BOOST_SIGNALS_ARGS_STRUCT_INST
#undef STREAMS_BOOST_SIGNALS_CALL_BOUND
#undef STREAMS_BOOST_SIGNALS_ARGS_STRUCT
#undef STREAMS_BOOST_SIGNALS_FUNCTION
#undef STREAMS_BOOST_SIGNALS_SIGNAL
#undef STREAMS_BOOST_SIGNALS_COMMA_IF_NONZERO_ARGS

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif
