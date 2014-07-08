/*
  Author: Frank Mori Hess <fmhess@users.sourceforge.net>
  Begin: 2007-01-23
*/
// Copyright Frank Mori Hess 2007-2008
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_SIGNALS2_SIGNALS_COMMON_MACROS_HPP
#define STREAMS_BOOST_SIGNALS2_SIGNALS_COMMON_MACROS_HPP

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_NO_VARIADIC_TEMPLATES

#ifndef STREAMS_BOOST_SIGNALS2_MAX_ARGS
#define STREAMS_BOOST_SIGNALS2_MAX_ARGS 9
#endif

// signaln
#define STREAMS_BOOST_SIGNALS2_SIGNAL_CLASS_NAME(arity) STREAMS_BOOST_PP_CAT(signal, arity)
// weak_signaln
#define STREAMS_BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(arity) STREAMS_BOOST_PP_CAT(weak_, STREAMS_BOOST_SIGNALS2_SIGNAL_CLASS_NAME(arity))
// signaln_impl
#define STREAMS_BOOST_SIGNALS2_SIGNAL_IMPL_CLASS_NAME(arity) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_SIGNALS2_SIGNAL_CLASS_NAME(arity), _impl)
// argn
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAME(z, n, data) STREAMS_BOOST_PP_CAT(arg, STREAMS_BOOST_PP_INC(n))
// Tn argn
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_FULL_ARG(z, n, data) \
  STREAMS_BOOST_PP_CAT(T, STREAMS_BOOST_PP_INC(n)) STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAME(~, n, ~)
// T1 arg1, T2 arg2, ..., Tn argn
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_FULL_ARGS(arity) \
  STREAMS_BOOST_PP_ENUM(arity, STREAMS_BOOST_SIGNALS2_SIGNATURE_FULL_ARG, ~)
// arg1, arg2, ..., argn
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(arity) STREAMS_BOOST_PP_ENUM(arity, STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAME, ~)
// T1, T2, ..., TN
#define STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_INSTANTIATION(arity) \
  STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_INC(arity), T)
// R (T1, T2, ..., TN)
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_FUNCTION_TYPE(arity) \
  R ( STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_INSTANTIATION(arity) )
// typename prefixR, typename prefixT1, typename prefixT2, ..., typename prefixTN
#define STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_DECL(arity, prefix) \
  typename STREAMS_BOOST_PP_CAT(prefix, R) STREAMS_BOOST_PP_COMMA_IF(arity) \
  STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_INC(arity), typename STREAMS_BOOST_PP_CAT(prefix, T))
// typename R, typename T1, typename T2, ..., typename TN
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_DECL(arity) STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_DECL(arity,)
// typename prefixT1, typename prefixT2, ..., typename prefixTN
#define STREAMS_BOOST_SIGNALS2_PREFIXED_ARGS_TEMPLATE_DECL(arity, prefix) \
  STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_INC(arity), typename STREAMS_BOOST_PP_CAT(prefix, T))
// typename T1, typename T2, ..., typename TN
#define STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_DECL(arity) STREAMS_BOOST_SIGNALS2_PREFIXED_ARGS_TEMPLATE_DECL(arity,)
// prefixR, prefixT1, prefixT2, ..., prefixTN
#define STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_INSTANTIATION(arity, prefix) \
  STREAMS_BOOST_PP_CAT(prefix, R) STREAMS_BOOST_PP_COMMA_IF(arity) STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_INC(arity), STREAMS_BOOST_PP_CAT(prefix, T))
// R, T1, T2, ..., TN
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_INSTANTIATION(arity) \
  STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_INSTANTIATION(arity,)
// streams_boost::functionN<R, T1, T2, ..., TN>
#define STREAMS_BOOST_SIGNALS2_FUNCTION_N_DECL(arity) STREAMS_BOOST_PP_CAT(streams_boost::function, arity)<\
  STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_INSTANTIATION(arity) >
// R, const streams_boost::signals2::connection&, T1, T2, ..., TN
#define STREAMS_BOOST_SIGNALS2_EXT_SLOT_TEMPLATE_INSTANTIATION(arity) \
  R, const streams_boost::signals2::connection&  STREAMS_BOOST_PP_COMMA_IF(arity) \
  STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_PP_INC(arity), T)
// streams_boost::functionN<R, const streams_boost::signals2::connection &, T1, T2, ..., TN>
#define STREAMS_BOOST_SIGNALS2_EXT_FUNCTION_N_DECL(arity) STREAMS_BOOST_PP_CAT(streams_boost::function, STREAMS_BOOST_PP_INC(arity))<\
  STREAMS_BOOST_SIGNALS2_EXT_SLOT_TEMPLATE_INSTANTIATION(arity) >
// slotN
#define STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(arity) STREAMS_BOOST_PP_CAT(slot, arity)
// slotN+1<R, const connection &, T1, T2, ..., TN, extended_slot_function_type>
#define STREAMS_BOOST_SIGNALS2_EXTENDED_SLOT_TYPE(arity) \
  STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(STREAMS_BOOST_PP_INC(arity))< \
  STREAMS_BOOST_SIGNALS2_EXT_SLOT_TEMPLATE_INSTANTIATION(arity), \
  extended_slot_function_type>
// bound_extended_slot_functionN
#define STREAMS_BOOST_SIGNALS2_BOUND_EXTENDED_SLOT_FUNCTION_N(arity) STREAMS_BOOST_PP_CAT(bound_extended_slot_function, arity)
// bound_extended_slot_function_helperN
#define STREAMS_BOOST_SIGNALS2_BOUND_EXTENDED_SLOT_FUNCTION_INVOKER_N(arity) STREAMS_BOOST_PP_CAT(bound_extended_slot_function_invoker, arity)
// typename function_traits<Signature>::argn_type
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_TO_ARGN_TYPE(z, n, Signature) \
  STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(typename function_traits<Signature>::arg, STREAMS_BOOST_PP_INC(n)), _type)
// typename function_traits<Signature>::result_type,
// typename function_traits<Signature>::arg1_type,
// typename function_traits<Signature>::arg2_type,
// ...,
// typename function_traits<Signature>::argn_type
#define STREAMS_BOOST_SIGNALS2_PORTABLE_SIGNATURE(arity, Signature) \
  typename function_traits<Signature>::result_type \
  STREAMS_BOOST_PP_COMMA_IF(arity) STREAMS_BOOST_PP_ENUM(arity, STREAMS_BOOST_SIGNALS2_SIGNATURE_TO_ARGN_TYPE, Signature)
// prefixTn & argn
#define STREAMS_BOOST_SIGNALS2_PREFIXED_FULL_REF_ARG(z, n, prefix) \
  STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(prefix, T), STREAMS_BOOST_PP_INC(n)) & STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAME(~, n, ~)
// prefixT1 & arg1, prefixT2 & arg2, ..., prefixTn & argn
#define STREAMS_BOOST_SIGNALS2_PREFIXED_FULL_REF_ARGS(arity, prefix) \
  STREAMS_BOOST_PP_ENUM(arity, STREAMS_BOOST_SIGNALS2_PREFIXED_FULL_REF_ARG, prefix)
// T1 & arg1, T2 & arg2, ..., Tn & argn
#define STREAMS_BOOST_SIGNALS2_FULL_REF_ARGS(arity) STREAMS_BOOST_SIGNALS2_PREFIXED_FULL_REF_ARGS(arity,)
// preprocessed_arg_typeN
#define STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_N_TYPE_CLASS_NAME(arity) STREAMS_BOOST_PP_CAT(preprocessed_arg_type, arity)

// typename R, typename T1, typename T2, ..., typename TN, typename SlotFunction
#define STREAMS_BOOST_SIGNALS2_SLOT_TEMPLATE_SPECIALIZATION_DECL(arity) \
  STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_DECL(arity), \
  typename SlotFunction
#define STREAMS_BOOST_SIGNALS2_SLOT_TEMPLATE_SPECIALIZATION

// typename R, typename T1, typename T2, ..., typename TN, typename Combiner, ...
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_DECL(arity) \
  STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_DECL(arity), \
  typename Combiner, \
  typename Group, \
  typename GroupCompare, \
  typename SlotFunction, \
  typename ExtendedSlotFunction, \
  typename Mutex
// typename R, typename T1, typename T2, ..., typename TN, typename Combiner = optional_last_value<R>, ...
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_DEFAULTED_DECL(arity) \
  STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_DECL(arity), \
  typename Combiner = optional_last_value<R>, \
  typename Group = int, \
  typename GroupCompare = std::less<Group>, \
  typename SlotFunction = STREAMS_BOOST_SIGNALS2_FUNCTION_N_DECL(arity), \
  typename ExtendedSlotFunction = STREAMS_BOOST_SIGNALS2_EXT_FUNCTION_N_DECL(arity), \
  typename Mutex = signals2::mutex
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_SPECIALIZATION_DECL(arity) STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_DECL(arity)
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_SPECIALIZATION

#define STREAMS_BOOST_SIGNALS2_STD_FUNCTIONAL_BASE(result_type) std_functional_base

#define STREAMS_BOOST_SIGNALS2_PP_COMMA_IF(arity) STREAMS_BOOST_PP_COMMA_IF(arity)

#else // STREAMS_BOOST_NO_VARIADIC_TEMPLATES

#define STREAMS_BOOST_SIGNALS2_SIGNAL_CLASS_NAME(arity) signal
#define STREAMS_BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(arity) weak_signal
#define STREAMS_BOOST_SIGNALS2_SIGNAL_IMPL_CLASS_NAME(arity) signal_impl
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_DECL(arity) typename Signature
#define STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_INSTANTIATION(arity) Args...
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_TEMPLATE_INSTANTIATION(arity) R (Args...)
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_FUNCTION_TYPE(arity) R (Args...)
#define STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_DECL(arity) typename ... Args
#define STREAMS_BOOST_SIGNALS2_FULL_REF_ARGS(arity) Args & ... args
#define STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(arity) slot
#define STREAMS_BOOST_SIGNALS2_EXTENDED_SLOT_TYPE(arity) slot<R (const connection &, Args...), extended_slot_function_type>
#define STREAMS_BOOST_SIGNALS2_BOUND_EXTENDED_SLOT_FUNCTION_N(arity) bound_extended_slot_function
#define STREAMS_BOOST_SIGNALS2_BOUND_EXTENDED_SLOT_FUNCTION_INVOKER_N(arity) bound_extended_slot_function_invoker
#define STREAMS_BOOST_SIGNALS2_FUNCTION_N_DECL(arity) streams_boost::function<Signature>
#define STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_DECL(arity, prefix) typename prefixSignature
#define STREAMS_BOOST_SIGNALS2_PREFIXED_SIGNATURE_TEMPLATE_INSTANTIATION(arity, prefix) prefixSignature
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_FULL_ARGS(arity) Args ... args
#define STREAMS_BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(arity) args...
#define STREAMS_BOOST_SIGNALS2_PORTABLE_SIGNATURE(arity, Signature) Signature
#define STREAMS_BOOST_SIGNALS2_SLOT_CLASS_NAME(arity) slot

#define STREAMS_BOOST_SIGNALS2_SLOT_TEMPLATE_SPECIALIZATION_DECL(arity) \
  typename SlotFunction, \
  typename R, \
  typename ... Args
#define STREAMS_BOOST_SIGNALS2_SLOT_TEMPLATE_SPECIALIZATION \
  <R (Args...), SlotFunction>

#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_DECL(arity) \
  typename Signature, \
  typename Combiner, \
  typename Group, \
  typename GroupCompare, \
  typename SlotFunction, \
  typename ExtendedSlotFunction, \
  typename Mutex
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_DEFAULTED_DECL(arity) \
  typename Signature, \
  typename Combiner = optional_last_value<typename streams_boost::function_traits<Signature>::result_type>, \
  typename Group = int, \
  typename GroupCompare = std::less<Group>, \
  typename SlotFunction = streams_boost::function<Signature>, \
  typename ExtendedSlotFunction = typename detail::variadic_extended_signature<Signature>::function_type, \
  typename Mutex = signals2::mutex
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_SPECIALIZATION_DECL(arity) \
  typename Combiner, \
  typename Group, \
  typename GroupCompare, \
  typename SlotFunction, \
  typename ExtendedSlotFunction, \
  typename Mutex, \
  typename R, \
  typename ... Args
#define STREAMS_BOOST_SIGNALS2_SIGNAL_TEMPLATE_SPECIALIZATION <\
  R (Args...), \
  Combiner, \
  Group, \
  GroupCompare, \
  SlotFunction, \
  ExtendedSlotFunction, \
  Mutex>

#define STREAMS_BOOST_SIGNALS2_STD_FUNCTIONAL_BASE(result_type) \
  std_functional_base<result_type , Args...>

#define STREAMS_BOOST_SIGNALS2_PP_COMMA_IF(arity) ,

#endif // STREAMS_BOOST_NO_VARIADIC_TEMPLATES

#endif // STREAMS_BOOST_SIGNALS2_SIGNALS_COMMON_MACROS_HPP
