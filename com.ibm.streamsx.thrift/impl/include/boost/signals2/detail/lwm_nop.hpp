//
//  streams_boost/signals2/detail/lwm_nop.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2008 Frank Mori Hess
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_SIGNALS2_LWM_NOP_HPP
#define STREAMS_BOOST_SIGNALS2_LWM_NOP_HPP

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif


#include <streams_boost/signals2/dummy_mutex.hpp>

namespace streams_boost
{

namespace signals2
{

class mutex: public dummy_mutex
{
};

} // namespace signals2

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_SIGNALS2_LWM_NOP_HPP
