/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_POINTER_TO_OTHER_HPP
#define STREAMS_BOOST_INTRUSIVE_POINTER_TO_OTHER_HPP

#include <streams_boost/intrusive/detail/config_begin.hpp>
#include <streams_boost/version.hpp>

#if (STREAMS_BOOST_VERSION < 103400)

#ifndef STREAMS_BOOST_POINTER_TO_OTHER_HPP_INCLUDED
#define STREAMS_BOOST_POINTER_TO_OTHER_HPP_INCLUDED

namespace streams_boost {

template<class T, class U>
   struct pointer_to_other;

template<class T, class U, template <class> class Sp>
   struct pointer_to_other< Sp<T>, U >
{
   typedef Sp<U> type;
};

template<class T, class T2, class U,
        template <class, class> class Sp>
   struct pointer_to_other< Sp<T, T2>, U >
{
   typedef Sp<U, T2> type;
};

template<class T, class T2, class T3, class U,
        template <class, class, class> class Sp>
struct pointer_to_other< Sp<T, T2, T3>, U >
{
   typedef Sp<U, T2, T3> type;
};

template<class T, class U>
struct pointer_to_other< T*, U > 
{
   typedef U* type;
};

} // namespace streams_boost

#endif

#else

#include <streams_boost/pointer_to_other.hpp>

#endif   //#ifndef STREAMS_BOOST_POINTER_TO_OTHER_HPP_INCLUDED

#include <streams_boost/intrusive/detail/config_end.hpp>

#endif   //#ifndef STREAMS_BOOST_INTRUSIVE_POINTER_TO_OTHER_HPP
