// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_DETAIL_ONE_HPP
#define STREAMS_BOOST_UNITS_DETAIL_ONE_HPP

#include <streams_boost/units/operators.hpp>

namespace streams_boost {

namespace units {

struct one { one() {} };

// workaround for pathscale.
inline one make_one() {
    one result;
    return(result);
}

template<class T>
struct multiply_typeof_helper<one, T>
{
    typedef T type;
};

template<class T>
struct multiply_typeof_helper<T, one>
{
    typedef T type;
};

template<>
struct multiply_typeof_helper<one, one>
{
    typedef one type;
};

template<class T>
inline T operator*(const one&, const T& t)
{
    return(t);
}

template<class T>
inline T operator*(const T& t, const one&)
{
    return(t);
}

inline one operator*(const one&, const one&)
{
    one result;
    return(result);
}

template<class T>
struct divide_typeof_helper<T, one>
{
    typedef T type;
};

template<class T>
struct divide_typeof_helper<one, T>
{
    typedef T type;
};

template<>
struct divide_typeof_helper<one, one>
{
    typedef one type;
};

template<class T>
inline T operator/(const T& t, const one&)
{
    return(t);
}

template<class T>
inline T operator/(const one&, const T& t)
{
    return(1/t);
}

inline one operator/(const one&, const one&)
{
    one result;
    return(result);
}

} // namespace units

} // namespace streams_boost

#endif
