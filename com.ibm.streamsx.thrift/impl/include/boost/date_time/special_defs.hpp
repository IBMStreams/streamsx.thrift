#ifndef DATE_TIME_SPECIAL_DEFS_STREAMS_HPP__
#define DATE_TIME_SPECIAL_DEFS_STREAMS_HPP__

/* Copyright (c) 2002,2003 CrystalClear Software, Inc.
 * Use, modification and distribution is subject to the 
 * Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or http://www.streams_boost.org/LICENSE_1_0.txt)
 * Author: Jeff Garland 
 * $Date: 2008-02-27 15:00:24 -0500 (Wed, 27 Feb 2008) $
 */

namespace streams_boost {
namespace date_time {

    enum special_values {not_a_date_time, 
                         neg_infin, pos_infin, 
                         min_date_time,  max_date_time,
                         not_special, NumSpecialValues};


} } //namespace date_time


#endif

