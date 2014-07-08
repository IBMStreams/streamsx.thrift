// Copyright (C) 2002-2003
// David Moore, William E. Kempf
// Copyright (C) 2007-8 Anthony Williams
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_BARRIER_JDM030602_HPP
#define STREAMS_BOOST_BARRIER_JDM030602_HPP

#include <streams_boost/thread/detail/config.hpp>

#include <streams_boost/thread/mutex.hpp>
#include <streams_boost/thread/condition_variable.hpp>
#include <string>
#include <stdexcept>

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{

    class barrier
    {
    public:
        barrier(unsigned int count)
            : m_threshold(count), m_count(count), m_generation(0)
        {
            if (count == 0)
                throw std::invalid_argument("count cannot be zero.");
        }
    
        bool wait()
        {
            streams_boost::mutex::scoped_lock lock(m_mutex);
            unsigned int gen = m_generation;
        
            if (--m_count == 0)
            {
                m_generation++;
                m_count = m_threshold;
                m_cond.notify_all();
                return true;
            }

            while (gen == m_generation)
                m_cond.wait(lock);
            return false;
        }

    private:
        mutex m_mutex;
        condition_variable m_cond;
        unsigned int m_threshold;
        unsigned int m_count;
        unsigned int m_generation;
    };

}   // namespace streams_boost

#include <streams_boost/config/abi_suffix.hpp>

#endif
