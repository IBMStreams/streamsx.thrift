//
//  streams_boost/signals2/detail/lwm_pthreads.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2008 Frank Mori Hess
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//

#ifndef STREAMS_BOOST_SIGNALS2_LWM_PTHREADS_HPP
#define STREAMS_BOOST_SIGNALS2_LWM_PTHREADS_HPP

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif


#include <pthread.h>

namespace streams_boost
{

namespace signals2
{

class mutex
{
private:

    pthread_mutex_t m_;

    mutex(mutex const &);
    mutex & operator=(mutex const &);

public:

    mutex()
    {

// HPUX 10.20 / DCE has a nonstandard pthread_mutex_init

#if defined(__hpux) && defined(_DECTHREADS_)
        pthread_mutex_init(&m_, pthread_mutexattr_default);
#else
        pthread_mutex_init(&m_, 0);
#endif
    }

    ~mutex()
    {
        pthread_mutex_destroy(&m_);
    }

    void lock()
    {
        pthread_mutex_lock(&m_);
    }

    bool try_lock()
    {
        return pthread_mutex_trylock(&m_) == 0;
    }

    void unlock()
    {
        pthread_mutex_unlock(&m_);
    }
};

} // namespace signals2

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_SIGNALS2_LWM_PTHREADS_HPP
