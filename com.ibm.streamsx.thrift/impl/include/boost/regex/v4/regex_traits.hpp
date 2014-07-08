/*
 *
 * Copyright (c) 2003
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */
 
 /*
  *   LOCATION:    see http://www.streams_boost.org for most recent version.
  *   FILE         regex_traits.hpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: Declares regular expression traits classes.
  */

#ifndef STREAMS_BOOST_REGEX_TRAITS_HPP_INCLUDED
#define STREAMS_BOOST_REGEX_TRAITS_HPP_INCLUDED

#ifndef STREAMS_BOOST_REGEX_CONFIG_HPP
#include <streams_boost/regex/config.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_WORKAROUND_HPP
#include <streams_boost/regex/v4/regex_workaround.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_SYNTAX_TYPE_HPP
#include <streams_boost/regex/v4/syntax_type.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_ERROR_TYPE_HPP
#include <streams_boost/regex/v4/error_type.hpp>
#endif
#ifndef STREAMS_BOOST_REGEX_TRAITS_DEFAULTS_HPP_INCLUDED
#include <streams_boost/regex/v4/regex_traits_defaults.hpp>
#endif
#ifndef STREAMS_BOOST_NO_STD_LOCALE
#  ifndef STREAMS_BOOST_CPP_REGEX_TRAITS_HPP_INCLUDED
#     include <streams_boost/regex/v4/cpp_regex_traits.hpp>
#  endif
#endif
#if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, < 0x560)
#  ifndef STREAMS_BOOST_C_REGEX_TRAITS_HPP_INCLUDED
#     include <streams_boost/regex/v4/c_regex_traits.hpp>
#  endif
#endif
#if defined(_WIN32) && !defined(STREAMS_BOOST_REGEX_NO_W32)
#  ifndef STREAMS_BOOST_W32_REGEX_TRAITS_HPP_INCLUDED
#     include <streams_boost/regex/v4/w32_regex_traits.hpp>
#  endif
#endif
#ifndef STREAMS_BOOST_REGEX_FWD_HPP_INCLUDED
#include <streams_boost/regex_fwd.hpp>
#endif

#include "streams_boost/mpl/has_xxx.hpp"
#include <streams_boost/static_assert.hpp>

#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4103)
#endif
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_PREFIX
#endif
#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

namespace streams_boost{

template <class charT, class implementationT >
struct regex_traits : public implementationT
{
   regex_traits() : implementationT() {}
};

//
// class regex_traits_wrapper.
// this is what our implementation will actually store;
// it provides default implementations of the "optional"
// interfaces that we support, in addition to the
// required "standard" ones:
//
namespace re_detail{
#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !STREAMS_BOOST_WORKAROUND(__HP_aCC, < 60000)
STREAMS_BOOST_MPL_HAS_XXX_TRAIT_DEF(streams_boost_extensions_tag)
#else
template<class T>
struct has_streams_boost_extensions_tag
{
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};
#endif

template <class BaseT>
struct default_wrapper : public BaseT
{
   typedef typename BaseT::char_type char_type;
   std::string error_string(::streams_boost::regex_constants::error_type e)const
   {
      return ::streams_boost::re_detail::get_default_error_string(e);
   }
   ::streams_boost::regex_constants::syntax_type syntax_type(char_type c)const
   {
      return ((c & 0x7f) == c) ? get_default_syntax_type(static_cast<char>(c)) : ::streams_boost::regex_constants::syntax_char;
   }
   ::streams_boost::regex_constants::escape_syntax_type escape_syntax_type(char_type c)const
   {
      return ((c & 0x7f) == c) ? get_default_escape_syntax_type(static_cast<char>(c)) : ::streams_boost::regex_constants::escape_type_identity;
   }
   int toi(const char_type*& p1, const char_type* p2, int radix)const
   {
      return ::streams_boost::re_detail::global_toi(p1, p2, radix, *this);
   }
   char_type translate(char_type c, bool icase)const
   {
      return (icase ? this->translate_nocase(c) : this->translate(c));
   }
   char_type translate(char_type c)const
   {
      return BaseT::translate(c);
   }
   char_type tolower(char_type c)const
   {
      return ::streams_boost::re_detail::global_lower(c);
   }
   char_type toupper(char_type c)const
   {
      return ::streams_boost::re_detail::global_upper(c);
   }
};

template <class BaseT, bool has_extensions>
struct compute_wrapper_base
{
   typedef BaseT type;
};
#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !STREAMS_BOOST_WORKAROUND(__HP_aCC, < 60000)
template <class BaseT>
struct compute_wrapper_base<BaseT, false>
{
   typedef default_wrapper<BaseT> type;
};
#else
template <>
struct compute_wrapper_base<c_regex_traits<char>, false>
{
   typedef default_wrapper<c_regex_traits<char> > type;
};
#ifndef STREAMS_BOOST_NO_WREGEX
template <>
struct compute_wrapper_base<c_regex_traits<wchar_t>, false>
{
   typedef default_wrapper<c_regex_traits<wchar_t> > type;
};
#endif
#endif

} // namespace re_detail

template <class BaseT>
struct regex_traits_wrapper 
   : public ::streams_boost::re_detail::compute_wrapper_base<
               BaseT, 
               ::streams_boost::re_detail::has_streams_boost_extensions_tag<BaseT>::value
            >::type
{
   regex_traits_wrapper(){}
private:
   regex_traits_wrapper(const regex_traits_wrapper&);
   regex_traits_wrapper& operator=(const regex_traits_wrapper&);
};

} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4103)
#endif
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif
#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

#endif // include
