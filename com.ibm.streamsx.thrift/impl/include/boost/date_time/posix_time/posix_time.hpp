#ifndef POSIX_TIME_STREAMS_HPP___
#define POSIX_TIME_STREAMS_HPP___

/* Copyright (c) 2002-2005 CrystalClear Software, Inc.
 * Use, modification and distribution is subject to the 
 * Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or http://www.streams_boost.org/LICENSE_1_0.txt)
 * Author: Jeff Garland, Bart Garst 
 * $Date: 2008-02-27 15:00:24 -0500 (Wed, 27 Feb 2008) $
 */
/*!@file posix_time.hpp Global header file to get all of posix time types 
 */

#include "streams_boost/date_time/compiler_config.hpp"
#include "streams_boost/date_time/posix_time/ptime.hpp"
#if defined(STREAMS_BOOST_DATE_TIME_OPTIONAL_GREGORIAN_TYPES)
#include "streams_boost/date_time/posix_time/date_duration_operators.hpp"
#endif

// output functions
#if defined(STREAMS_BOOST_DATE_TIME_INCLUDE_LIMITED_HEADERS)
#include "streams_boost/date_time/posix_time/time_formatters_limited.hpp"
#else
#include "streams_boost/date_time/posix_time/time_formatters.hpp"
#endif // STREAMS_BOOST_DATE_TIME_INCLUDE_LIMITED_HEADERS

// streaming operators
#if defined(USE_DATE_TIME_PRE_1_33_FACET_IO)
#include "streams_boost/date_time/posix_time/posix_time_legacy_io.hpp"
#else
#include "streams_boost/date_time/posix_time/posix_time_io.hpp"
#endif // USE_DATE_TIME_PRE_1_33_FACET_IO

#include "streams_boost/date_time/posix_time/time_parsers.hpp"
#include "streams_boost/date_time/posix_time/conversion.hpp"


#endif

