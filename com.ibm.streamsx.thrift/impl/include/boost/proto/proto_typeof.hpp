///////////////////////////////////////////////////////////////////////////////
/// \file proto_typeof.hpp
/// Type registrations so that proto expression templates can be used together
/// with the Boost.Typeof library.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_PROTO_PROTO_TYPEOF_H
#define STREAMS_BOOST_XPRESSIVE_PROTO_PROTO_TYPEOF_H

#include <streams_boost/config.hpp>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/proto/proto_fwd.hpp>
#include <streams_boost/proto/deep_copy.hpp>
#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::terminal)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::unary_plus)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::negate)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::dereference)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::complement)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::address_of)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::logical_not)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::pre_inc)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::pre_dec)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::post_inc)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::post_dec)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::shift_left)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::shift_right)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::multiplies)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::divides)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::modulus)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::plus)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::minus)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::less)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::greater)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::less_equal)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::greater_equal)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::equal_to)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::not_equal_to)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::logical_or)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::logical_and)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::bitwise_and)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::bitwise_or)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::bitwise_xor)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::comma)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::mem_ptr)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::shift_left_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::shift_right_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::multiplies_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::divides_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::modulus_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::plus_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::minus_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::bitwise_and_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::bitwise_or_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::bitwise_xor_assign)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::subscript)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::member)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::if_else_)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::tag::function)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::proto::exprns_::is_proto_expr)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::exprns_::expr, (typename)(typename)(long))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::utility::literal, (typename)(typename))

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::term, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list1, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list2, 2)
// can't use PP metaprogramming here because all typeof registrations
// must be on separate lines.
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 3
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list3, 3)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 4
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list4, 4)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 5
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list5, 5)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 6
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list6, 6)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 7
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list7, 7)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 8
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list8, 8)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 9
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list9, 9)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 10
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list10, 10)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 11
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list11, 11)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 12
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list12, 12)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 13
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list13, 13)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 14
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list14, 14)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 15
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list15, 15)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 16
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list16, 16)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 17
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list17, 17)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 18
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list18, 18)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 19
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list19, 19)
#endif
#if STREAMS_BOOST_PROTO_MAX_ARITY >= 20
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::proto::argsns_::list20, 20)
#endif

#define STREAMS_BOOST_PROTO_AUTO(Var, Expr) STREAMS_BOOST_AUTO(Var, streams_boost::proto::deep_copy(Expr))
#define STREAMS_BOOST_PROTO_AUTO_TPL(Var, Expr) STREAMS_BOOST_AUTO_TPL(Var, streams_boost::proto::deep_copy(Expr))

#endif
