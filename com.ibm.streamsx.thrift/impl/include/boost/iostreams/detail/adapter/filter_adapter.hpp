/*
 * Defines the class template streams_boost::iostreams::detail::filter_adapter,
 * a convenience base class for filter adapters.
 *
 * File:        streams_boost/iostreams/detail/adapter/filter_adapter.hpp
 * Date:        Mon Nov 26 14:35:48 MST 2007
 * Copyright:   2007-2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)
 * 
 * See http://www.streams_boost.org/libs/iostreams for documentation.
 */

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_FILTER_ADAPTER_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_FILTER_ADAPTER_HPP_INCLUDED

#include <streams_boost/iostreams/categories.hpp>
#include <streams_boost/iostreams/detail/call_traits.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>
#include <streams_boost/iostreams/operations.hpp>
#include <streams_boost/iostreams/traits.hpp>
#include <streams_boost/static_assert.hpp>

namespace streams_boost { namespace iostreams { namespace detail {

template<typename T>
class filter_adapter {
private:
    typedef typename detail::value_type<T>::type value_type;
    typedef typename detail::param_type<T>::type param_type;
public:
    explicit filter_adapter(param_type t) : t_(t) { }
    T& component() { return t_; }

    template<typename Device>
    void close(Device& dev) 
    { 
        detail::close_all(t_, dev); 
    }

    template<typename Device>
    void close(Device& dev, STREAMS_BOOST_IOS::openmode which) 
    { 
        iostreams::close(t_, dev, which); 
    }

    template<typename Device>
    void flush(Device& dev) 
    { 
        return iostreams::flush(t_, dev); 
    }

    template<typename Locale> // Avoid dependency on <locale>
    void imbue(const Locale& loc) { iostreams::imbue(t_, loc); }

    std::streamsize optimal_buffer_size() const 
    { return iostreams::optimal_buffer_size(t_); }
public:
    value_type t_;
};

//----------------------------------------------------------------------------//

} } } // End namespaces detail, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_FILTER_ADAPTER_HPP_INCLUDED
