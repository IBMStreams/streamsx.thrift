// Boost.Signals2 library

// Copyright Frank Mori Hess 2007-2009.
// Copyright Timmo Stange 2007.
// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_PREPROCESSED_SLOT_HPP
#define STREAMS_BOOST_SIGNALS2_PREPROCESSED_SLOT_HPP

#include <streams_boost/preprocessor/repetition.hpp>
#include <streams_boost/signals2/detail/preprocessed_arg_type.hpp>
#include <streams_boost/type_traits/function_traits.hpp>

#ifndef STREAMS_BOOST_SIGNALS2_SLOT_MAX_BINDING_ARGS
#define STREAMS_BOOST_SIGNALS2_SLOT_MAX_BINDING_ARGS 10
#endif


// template<typename Func, typename BindArgT0, typename BindArgT1, ..., typename BindArgTN-1> slotN(...
#define STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTOR(z, n, data) \
  template<typename Func, STREAMS_BOOST_SIGNALS2_PREFIXED_ARGS_TEMPLATE_DECL(n, BindArg)> \
  STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)( \
    const Func &func, STREAMS_BOOST_SIGNALS2_PREFIXED_FULL_REF_ARGS(n, const BindArg)) \
  { \
    init_slot_function(streams_boost::bind(func, STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(n))); \
  }
#define STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTORS \
  STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_SIGNALS2_SLOT_MAX_BINDING_ARGS, STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTOR, ~)


#define STREAMS_BOOST_PP_ITERATION_LIMITS (0, STREAMS_BOOST_PP_INC(STREAMS_BOOST_SIGNALS2_MAX_ARGS))
#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/signals2/detail/slot_template.hpp>
#include STREAMS_BOOST_PP_ITERATE()

#undef STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTOR
#undef STREAMS_BOOST_SIGNALS2_SLOT_N_BINDING_CONSTRUCTORS

namespace streams_boost
{
  namespace signals2
  {
    template<typename Signature,
      typename SlotFunction = streams_boost::function<Signature> >
    class slot: public detail::slotN<function_traits<Signature>::arity,
      Signature, SlotFunction>::type
    {
    private:
      typedef typename detail::slotN<streams_boost::function_traits<Signature>::arity,
        Signature, SlotFunction>::type base_type;
    public:
      template<typename F>
      slot(const F& f): base_type(f)
      {}
      // bind syntactic sugar
// template<typename F, typename BindArgT0, typename BindArgT1, ..., typename BindArgTn-1> slot(...
#define STREAMS_BOOST_SIGNALS2_SLOT_BINDING_CONSTRUCTOR(z, n, data) \
  template<typename Func, STREAMS_BOOST_SIGNALS2_PREFIXED_ARGS_TEMPLATE_DECL(n, BindArg)> \
    slot(const Func &func, STREAMS_BOOST_SIGNALS2_PREFIXED_FULL_REF_ARGS(n, const BindArg)): \
    base_type(func, STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(n)) \
  {}
      STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_SIGNALS2_SLOT_MAX_BINDING_ARGS, STREAMS_BOOST_SIGNALS2_SLOT_BINDING_CONSTRUCTOR, ~)
#undef STREAMS_BOOST_SIGNALS2_SLOT_BINDING_CONSTRUCTOR
    };
  } // namespace signals2
}

#endif // STREAMS_BOOST_SIGNALS2_PREPROCESSED_SLOT_HPP
