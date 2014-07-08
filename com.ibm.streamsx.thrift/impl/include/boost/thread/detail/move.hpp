// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
// (C) Copyright 2007-8 Anthony Williams

#ifndef STREAMS_BOOST_THREAD_MOVE_HPP
#define STREAMS_BOOST_THREAD_MOVE_HPP

#ifndef STREAMS_BOOST_NO_SFINAE
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/type_traits/is_convertible.hpp>
#endif

#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost
{
    namespace detail
    {
        template<typename T>
        struct thread_move_t
        {
            T& t;
            explicit thread_move_t(T& t_):
                t(t_)
            {}

            T& operator*() const
            {
                return t;
            }

            T* operator->() const
            {
                return &t;
            }
        private:
            void operator=(thread_move_t&);
        };
    }

#ifndef STREAMS_BOOST_NO_SFINAE
    template<typename T>
    typename enable_if<streams_boost::is_convertible<T&,detail::thread_move_t<T> >, detail::thread_move_t<T> >::type move(T& t)
    {
        return detail::thread_move_t<T>(t);
    }
#endif
    
    template<typename T>
    detail::thread_move_t<T> move(detail::thread_move_t<T> t)
    {
        return t;
    }
    
}

#include <streams_boost/config/abi_suffix.hpp>

#endif
