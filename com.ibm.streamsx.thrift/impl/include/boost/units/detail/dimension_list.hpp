// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_DIMENSION_LIST_HPP
#define STREAMS_BOOST_UNITS_DIMENSION_LIST_HPP

#include <streams_boost/mpl/next.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/mpl/push_front_fwd.hpp>
#include <streams_boost/mpl/pop_front_fwd.hpp>
#include <streams_boost/mpl/size_fwd.hpp>
#include <streams_boost/mpl/begin_end_fwd.hpp>
#include <streams_boost/mpl/front_fwd.hpp>

#include <streams_boost/units/config.hpp>

namespace streams_boost {

namespace units {

struct dimensionless_type;

namespace detail {

struct dimension_list_tag { };

} // namespace detail

template<class Item, class Next>
struct list
{
    typedef detail::dimension_list_tag  tag;
    typedef list              type;
    typedef Item                        item;
    typedef Next                        next;
    typedef typename mpl::next<typename Next::size>::type size;
};

} // namespace units

namespace mpl {

// INTERNAL ONLY
template<>
struct size_impl<units::detail::dimension_list_tag>
{
    template<class L> struct apply : public L::size { };
};

// INTERNAL ONLY
template<>
struct begin_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef L type;
    };
};

// INTERNAL ONLY
template<>
struct end_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef units::dimensionless_type type;
    };
};

// INTERNAL ONLY
template<>
struct push_front_impl<units::detail::dimension_list_tag>
{
    template<class L, class T>
    struct apply 
    {
        typedef units::list<T, L> type;
    };
};

// INTERNAL ONLY
template<>
struct pop_front_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef typename L::next type;
    };
};

// INTERNAL ONLY
template<>
struct front_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef typename L::item type;
    };
};

// INTERNAL ONLY
template<class Item, class Next>
struct deref<units::list<Item, Next> >
{
    typedef Item type;
};

} // namespace mpl

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::units::list, 2)

#endif

#include <streams_boost/units/dimensionless_type.hpp>

#endif // STREAMS_BOOST_UNITS_DIMENSION_LIST_HPP
