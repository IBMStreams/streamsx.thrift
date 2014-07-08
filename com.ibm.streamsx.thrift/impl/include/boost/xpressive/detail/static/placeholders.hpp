///////////////////////////////////////////////////////////////////////////////
// placeholders.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_STATIC_PLACEHOLDERS_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_STATIC_PLACEHOLDERS_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
# pragma warning(push)
# pragma warning(disable:4510) // default constructor could not be generated
# pragma warning(disable:4610) // can never be instantiated - user defined constructor required
#endif

#include <string>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/xpressive/detail/core/quant_style.hpp>
#include <streams_boost/xpressive/detail/core/regex_impl.hpp>

namespace streams_boost { namespace xpressive { namespace detail
{

///////////////////////////////////////////////////////////////////////////////
// mark_placeholder
//
struct mark_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_variable_width, unknown_width::value, true)

    int mark_number_;
};

///////////////////////////////////////////////////////////////////////////////
// posix_charset_placeholder
//
struct posix_charset_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_fixed_width, 1, true)

    char const *name_;
    bool not_;
};

///////////////////////////////////////////////////////////////////////////////
// assert_word_placeholder
//
template<typename Cond>
struct assert_word_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_none, 0, true)
};

///////////////////////////////////////////////////////////////////////////////
// range_placeholder
//
template<typename Char>
struct range_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_fixed_width, 1, true)

    Char ch_min_;
    Char ch_max_;
    bool not_;
};

///////////////////////////////////////////////////////////////////////////////
// assert_bol_placeholder
//
struct assert_bol_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_none, 0, true)
};

///////////////////////////////////////////////////////////////////////////////
// assert_eol_placeholder
//
struct assert_eol_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_none, 0, true)
};

///////////////////////////////////////////////////////////////////////////////
// logical_newline_placeholder
//
struct logical_newline_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_variable_width, unknown_width::value, true)
};

///////////////////////////////////////////////////////////////////////////////
// self_placeholder
//
struct self_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_variable_width, unknown_width::value, false)
};

///////////////////////////////////////////////////////////////////////////////
// attribute_placeholder
//
template<typename Nbr>
struct attribute_placeholder
{
    STREAMS_BOOST_XPR_QUANT_STYLE(quant_variable_width, unknown_width::value, false)

    typedef Nbr nbr_type;
    static Nbr nbr() { return Nbr(); }
};

}}} // namespace streams_boost::xpressive::detail

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma warning(pop)
#endif

#endif
