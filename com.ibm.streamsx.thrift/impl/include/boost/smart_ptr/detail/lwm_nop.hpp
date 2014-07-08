#ifndef STREAMS_BOOST_SMART_PTR_DETAIL_LWM_NOP_HPP_INCLUDED
#define STREAMS_BOOST_SMART_PTR_DETAIL_LWM_NOP_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  streams_boost/detail/lwm_nop.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//

namespace streams_boost
{

namespace detail
{

class lightweight_mutex
{
public:

    typedef lightweight_mutex scoped_lock;
};

} // namespace detail

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_SMART_PTR_DETAIL_LWM_NOP_HPP_INCLUDED
