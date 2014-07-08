// Copyright David Abrahams 2004. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef UNWRAP_WRAPPER_DWA2004723_STREAMS_HPP
# define UNWRAP_WRAPPER_DWA2004723_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/detail/is_wrapper.hpp>
# include <streams_boost/mpl/eval_if.hpp>
# include <streams_boost/mpl/identity.hpp>

namespace streams_boost { namespace python { namespace detail { 

template <class T>
struct unwrap_wrapper_helper
{
    typedef typename T::_wrapper_wrapped_type_ type;
};

template <class T>
struct unwrap_wrapper_
  : mpl::eval_if<is_wrapper<T>,unwrap_wrapper_helper<T>,mpl::identity<T> >
{};

template <class T>
typename unwrap_wrapper_<T>::type*
unwrap_wrapper(T*)
{
    return 0;
}

}}} // namespace streams_boost::python::detail

#endif // UNWRAP_WRAPPER_DWA2004723_STREAMS_HPP
