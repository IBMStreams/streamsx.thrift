// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef EXCEPTION_HANDLER_DWA2002810_STREAMS_HPP
# define EXCEPTION_HANDLER_DWA2002810_STREAMS_HPP

# include <streams_boost/python/detail/config.hpp>
# include <streams_boost/function/function0.hpp>
# include <streams_boost/function/function2.hpp>

namespace streams_boost { namespace python { namespace detail {

struct STREAMS_BOOST_PYTHON_DECL_FORWARD exception_handler;

typedef function2<bool, exception_handler const&, function0<void> const&> handler_function;

struct STREAMS_BOOST_PYTHON_DECL exception_handler
{
 private: // types
    
 public:
    explicit exception_handler(handler_function const& impl);

    inline bool handle(function0<void> const& f) const;
    
    bool operator()(function0<void> const& f) const;
 
    static exception_handler* chain;
    
 private:
    static exception_handler* tail;
    
    handler_function m_impl;
    exception_handler* m_next;
};


inline bool exception_handler::handle(function0<void> const& f) const
{
    return this->m_impl(*this, f);
}

STREAMS_BOOST_PYTHON_DECL void register_exception_handler(handler_function const& f);

}}} // namespace streams_boost::python::detail

#endif // EXCEPTION_HANDLER_DWA2002810_STREAMS_HPP
