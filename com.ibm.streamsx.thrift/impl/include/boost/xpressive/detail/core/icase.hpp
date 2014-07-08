///////////////////////////////////////////////////////////////////////////////
// icase.hpp
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_DETAIL_CORE_ICASE_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_DETAIL_CORE_ICASE_HPP_EAN_10_04_2005

#include <streams_boost/xpressive/detail/detail_fwd.hpp>
#include <streams_boost/xpressive/regex_constants.hpp>
#include <streams_boost/xpressive/detail/static/modifier.hpp>
#include <streams_boost/xpressive/detail/core/linker.hpp>
#include <streams_boost/xpressive/detail/utility/ignore_unused.hpp>

namespace streams_boost { namespace xpressive { namespace regex_constants
{

///////////////////////////////////////////////////////////////////////////////
/// \brief Makes a sub-expression case-insensitive.
///
/// Use icase() to make a sub-expression case-insensitive. For instance,
/// "foo" >> icase(set['b'] >> "ar") will match "foo" exactly followed by
/// "bar" irrespective of case.
detail::modifier_op<detail::icase_modifier> const icase = {{}, regex_constants::icase_};

} // namespace regex_constants

using regex_constants::icase;

namespace detail
{
    inline void ignore_unused_icase()
    {
        ignore_unused(icase);
    }
}

}} // namespace streams_boost::xpressive

#endif
