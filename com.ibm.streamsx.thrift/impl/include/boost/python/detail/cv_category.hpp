// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef CV_CATEGORY_DWA200222_STREAMS_HPP
# define CV_CATEGORY_DWA200222_STREAMS_HPP
# include <streams_boost/type_traits/cv_traits.hpp>

namespace streams_boost { namespace python { namespace detail { 

template <bool is_const_, bool is_volatile_>
struct cv_tag
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_const = is_const_);
    STREAMS_BOOST_STATIC_CONSTANT(bool, is_volatile = is_const_);
};

typedef cv_tag<false,false> cv_unqualified;
typedef cv_tag<true,false> const_;
typedef cv_tag<false,true> volatile_;
typedef cv_tag<true,true> const_volatile_;

template <class T>
struct cv_category
{
//    STREAMS_BOOST_STATIC_CONSTANT(bool, c = is_const<T>::value);
//    STREAMS_BOOST_STATIC_CONSTANT(bool, v = is_volatile<T>::value);
    typedef cv_tag<
        ::streams_boost::is_const<T>::value
      , ::streams_boost::is_volatile<T>::value
    > type;
};

}}} // namespace streams_boost::python::detail

#endif // CV_CATEGORY_DWA200222_STREAMS_HPP
