// Boost.Signals2 library

// Copyright Frank Mori Hess 2007-2008.
// Copyright Timmo Stange 2007.
// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

// This file is included iteratively, and should not be protected from multiple inclusion

#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES
#define STREAMS_BOOST_SIGNALS2_NUM_ARGS STREAMS_BOOST_PP_ITERATION()
#else
#define STREAMS_BOOST_SIGNALS2_NUM_ARGS 1
#endif


namespace streams_boost
{
  namespace signals2
  {
    template<typename Signature, typename SlotFunction> class slot;

    // slot class template.
    template<STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS),
      typename SlotFunction = STREAMS_BOOST_SIGNALS2_FUNCTION_N_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS)>
      class STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS);

    template<STREAMS_BOOST_SIGNALS2_SLOT_TEMPLATE_SPECIALIZATION_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS)>
      class STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS) STREAMS_BOOST_SIGNALS2_SLOT_TEMPLATE_SPECIALIZATION
      : public slot_base, public detail::STREAMS_BOOST_SIGNALS2_STD_FUNCTIONAL_BASE(R)

    {
    public:
      template<STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS, Other), typename OtherSlotFunction>
      friend class STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS);

      typedef SlotFunction slot_function_type;
      typedef R result_type;
      typedef typename mpl::identity<STREAMS_BOOST_SIGNALS2_SIGNATURE_FUNCTION_TYPE(STREAMS_BOOST_SIGNALS2_NUM_ARGS)>::type signature_type;

#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES

// typedef Tn argn_type;
#define STREAMS_BOOST_SIGNALS2_MISC_STATEMENT(z, n, data) \
    typedef STREAMS_BOOST_PP_CAT(T, STREAMS_BOOST_PP_INC(n)) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(arg, STREAMS_BOOST_PP_INC(n)), _type);
          STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_SIGNALS2_NUM_ARGS, STREAMS_BOOST_SIGNALS2_MISC_STATEMENT, ~)
#undef STREAMS_BOOST_SIGNALS2_MISC_STATEMENT
#if STREAMS_BOOST_SIGNALS2_NUM_ARGS == 1
      typedef arg1_type argument_type;
#elif STREAMS_BOOST_SIGNALS2_NUM_ARGS == 2
      typedef arg1_type first_argument_type;
      typedef arg2_type second_argument_type;
#endif

      template<unsigned n> class arg : public
        detail::STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_N_TYPE_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)
        <n STREAMS_BOOST_SIGNALS2_PP_COMMA_IF(STREAMS_BOOST_SIGNALS2_NUM_ARGS)
        STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_INSTANTIATION(STREAMS_BOOST_SIGNALS2_NUM_ARGS)>
      {};

      STREAMS_BOOST_STATIC_CONSTANT(int, arity = STREAMS_BOOST_SIGNALS2_NUM_ARGS);

#else // STREAMS_BOOST_NO_VARIADIC_TEMPLATES

      template<unsigned n> class arg
      {
      public:
        typedef typename detail::variadic_arg_type<n, Args...>::type type;
      };
      STREAMS_BOOST_STATIC_CONSTANT(int, arity = sizeof...(Args));

#endif // STREAMS_BOOST_NO_VARIADIC_TEMPLATES

      template<typename F>
      STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)(const F& f)
      {
        init_slot_function(f);
      }
      // copy constructors
#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES
      template<STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS, Other), typename OtherSlotFunction>
      STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)(const STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)
        <STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_INSTANTIATION(STREAMS_BOOST_SIGNALS2_NUM_ARGS, Other), OtherSlotFunction> &other_slot):
        slot_base(other_slot), _slot_function(other_slot._slot_function)
      {
      }
#endif
      template<typename Signature, typename OtherSlotFunction>
      STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)(const slot<Signature, OtherSlotFunction> &other_slot):
        slot_base(other_slot), _slot_function(other_slot._slot_function)
      {
      }
      // bind syntactic sugar
      STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTORS
      // invocation
      R operator()(STREAMS_BOOST_SIGNALS2_SIGNATURE_FULL_ARGS(STREAMS_BOOST_SIGNALS2_NUM_ARGS))
      {
        locked_container_type locked_objects = lock();
        return _slot_function(STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(STREAMS_BOOST_SIGNALS2_NUM_ARGS));
      }
      R operator()(STREAMS_BOOST_SIGNALS2_SIGNATURE_FULL_ARGS(STREAMS_BOOST_SIGNALS2_NUM_ARGS)) const
      {
        locked_container_type locked_objects = lock();
        return _slot_function(STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(STREAMS_BOOST_SIGNALS2_NUM_ARGS));
      }
      // tracking
      STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)& track(const weak_ptr<void> &tracked)
      {
        _tracked_objects.push_back(tracked);
        return *this;
      }
      STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)& track(const signal_base &signal)
      {
        track_signal(signal);
        return *this;
      }
      STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)& track(const slot_base &slot)
      {
        tracked_container_type::const_iterator it;
        for(it = slot.tracked_objects().begin(); it != slot.tracked_objects().end(); ++it)
        {
          track(*it);
        }
        return *this;
      }

      const slot_function_type& slot_function() const {return _slot_function;}
      slot_function_type& slot_function() {return _slot_function;}
    private:
      template<typename F>
      void init_slot_function(const F& f)
      {
        _slot_function = detail::get_invocable_slot(f, detail::tag_type(f));
        signals2::detail::tracked_objects_visitor visitor(this);
        streams_boost::visit_each(visitor, f);
      }

      SlotFunction _slot_function;
    };

#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES
    namespace detail
    {
      template<unsigned arity, typename Signature, typename SlotFunction>
      class slotN;
      // partial template specialization
      template<typename Signature, typename SlotFunction>
      class slotN<STREAMS_BOOST_SIGNALS2_NUM_ARGS, Signature, SlotFunction>
      {
      public:
        typedef STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)<
          STREAMS_BOOST_SIGNALS2_PORTABLE_SIGNATURE(STREAMS_BOOST_SIGNALS2_NUM_ARGS, Signature),
          SlotFunction> type;
      };
    }
#endif
  } // end namespace signals2
} // end namespace streams_boost

#undef STREAMS_BOOST_SIGNALS2_NUM_ARGS
