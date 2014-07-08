#ifndef STREAMS_BOOST_DATE_TIME_TZ_DATABASE_STREAMS_STREAMS_HPP__
#define STREAMS_BOOST_DATE_TIME_TZ_DATABASE_STREAMS_STREAMS_HPP__

/* Copyright (c) 2003-2004 CrystalClear Software, Inc.
 * Subject to the Boost Software License, Version 1.0. 
 * (See accompanying file LICENSE_1_0.txt or http://www.streams_boost.org/LICENSE_1_0.txt)
 * Author: Jeff Garland, Bart Garst
 * $Date: 2008-02-27 15:00:24 -0500 (Wed, 27 Feb 2008) $
 */

#include <string>
#include "streams_boost/date_time/local_time/custom_time_zone.hpp"
#include "streams_boost/date_time/local_time/dst_transition_day_rules.hpp"
#include "streams_boost/date_time/tz_db_base.hpp"


namespace streams_boost {
namespace local_time {

  using date_time::data_not_accessible; 
  using date_time::bad_field_count; 

  //! Object populated with streams_boost::shared_ptr<time_zone_base> objects
  /*! Object populated with streams_boost::shared_ptr<time_zone_base> objects
   * Database is populated from specs stored in external csv file. See
   * date_time::tz_db_base for greater detail */
  typedef date_time::tz_db_base<custom_time_zone, nth_kday_dst_rule> tz_database;

}} // namespace

#endif // STREAMS_BOOST_DATE_TIME_TZ_DATABASE_STREAMS_STREAMS_HPP__

