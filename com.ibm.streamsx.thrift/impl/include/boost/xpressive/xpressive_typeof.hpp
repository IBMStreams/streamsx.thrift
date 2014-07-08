///////////////////////////////////////////////////////////////////////////////
/// \file xpressive_typeof.hpp
/// Type registrations so that xpressive can be used with the Boost.Typeof library.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_XPRESSIVE_TYPEOF_H
#define STREAMS_BOOST_XPRESSIVE_XPRESSIVE_TYPEOF_H

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/config.hpp>
#include <streams_boost/typeof/typeof.hpp>
#ifndef STREAMS_BOOST_NO_STD_LOCALE
# include <streams_boost/typeof/std/locale.hpp>
#endif
#include <streams_boost/proto/proto_typeof.hpp>
#include <streams_boost/xpressive/detail/detail_fwd.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::mpl::bool_, (bool))

///////////////////////////////////////////////////////////////////////////////
// Misc.
//
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::set_initializer)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::keeper_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::modifier_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::lookahead_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::lookbehind_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::check_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::mark_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::word_begin)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::word_end)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::generic_quant_tag, (unsigned int)(unsigned int))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::basic_regex, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::word_boundary, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::value, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::reference, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::local, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::placeholder, (typename)(int)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::tracking_ptr, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::regex_impl, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::let_, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::action_arg, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::named_mark, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::sub_match, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::nested_results, (typename))

///////////////////////////////////////////////////////////////////////////////
// Placeholders
//
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::mark_placeholder)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::posix_charset_placeholder)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::assert_bol_placeholder)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::assert_eol_placeholder)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::logical_newline_placeholder)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::self_placeholder)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::assert_word_placeholder, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::range_placeholder, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::attribute_placeholder, (typename))

///////////////////////////////////////////////////////////////////////////////
// Matchers
//
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::epsilon_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::true_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::end_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::independent_end_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::any_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::assert_bos_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::assert_eos_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::mark_begin_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::mark_end_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::repeat_begin_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::alternate_end_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::attr_end_matcher)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::assert_bol_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::assert_eol_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::literal_matcher, (typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::string_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::charset_matcher, (typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::logical_newline_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::mark_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::repeat_end_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::alternate_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::optional_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::optional_mark_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::simple_repeat_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::regex_byref_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::regex_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::posix_charset_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::assert_word_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::range_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::keeper_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::lookahead_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::lookbehind_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::set_matcher, (typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::predicate_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::action_matcher, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::attr_matcher, (typename)(typename)(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::attr_begin_matcher, (typename))

///////////////////////////////////////////////////////////////////////////////
// Ops
//
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::push)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::push_back)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::pop)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::push_front)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::pop_back)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::pop_front)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::back)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::front)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::top)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::first)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::second)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::matched)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::length)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::str)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::insert)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::op::make_pair)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::op::as, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::op::static_cast_, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::op::dynamic_cast_, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::op::const_cast_, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::op::construct, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::op::throw_, (typename))

///////////////////////////////////////////////////////////////////////////////
// Modifiers
//
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(streams_boost::xpressive::detail::icase_modifier)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::detail::locale_modifier, (typename))

///////////////////////////////////////////////////////////////////////////////
// Traits
//
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::null_regex_traits, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::cpp_regex_traits, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::c_regex_traits, (typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::xpressive::regex_traits, (typename)(typename))

#endif
