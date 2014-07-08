// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_DETAIL_POD_SINGLETON_DWA200655_STREAMS_HPP
# define STREAMS_BOOST_DETAIL_POD_SINGLETON_DWA200655_STREAMS_HPP

namespace streams_boost { namespace detail {

template<typename T>
struct pod_singleton
{
    static T instance;
};

template<typename T>
T pod_singleton<T>::instance;

}} // namespace streams_boost::detail

#endif // STREAMS_BOOST_DETAIL_POD_SINGLETON_DWA200655_STREAMS_HPP