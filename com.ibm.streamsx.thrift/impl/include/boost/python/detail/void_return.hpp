// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef VOID_RETURN_DWA200274_STREAMS_HPP
# define VOID_RETURN_DWA200274_STREAMS_HPP

# include <streams_boost/config.hpp>

namespace streams_boost { namespace python { namespace detail { 

struct void_return
{
    void_return() {}
 private: 
    void operator=(void_return const&);
};

template <class T>
struct returnable
{
    typedef T type;
};

# ifdef STREAMS_BOOST_NO_VOID_RETURNS
template <>
struct returnable<void>
{
    typedef void_return type;
};

#  ifndef STREAMS_BOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct returnable<const void> : returnable<void> {};
template <> struct returnable<volatile void> : returnable<void> {};
template <> struct returnable<const volatile void> : returnable<void> {};
#  endif

# endif // STREAMS_BOOST_NO_VOID_RETURNS

}}} // namespace streams_boost::python::detail

#endif // VOID_RETURN_DWA200274_STREAMS_HPP
