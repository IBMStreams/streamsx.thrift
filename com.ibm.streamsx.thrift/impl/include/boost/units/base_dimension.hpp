// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_BASE_DIMENSION_HPP
#define STREAMS_BOOST_UNITS_BASE_DIMENSION_HPP

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/dim.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/units_fwd.hpp>
#include <streams_boost/units/detail/dimension_list.hpp>
#include <streams_boost/units/detail/ordinal.hpp>
#include <streams_boost/units/detail/prevent_redefinition.hpp>

namespace streams_boost {

namespace units {

/// This must be in namespace streams_boost::units so that ADL
/// will work with friend functions defined inline.
/// INTERNAL ONLY
template<long N> struct base_dimension_ordinal { };

/// INTERNAL ONLY
template<class T, long N> struct base_dimension_pair { };

/// INTERNAL ONLY
template<class T, long N>
struct check_base_dimension {
    enum {
        value = 
            sizeof(streams_boost_units_is_registered(units::base_dimension_ordinal<N>())) == sizeof(detail::yes) &&
            sizeof(streams_boost_units_is_registered(units::base_dimension_pair<T, N>())) != sizeof(detail::yes)
    };
};

/// Defines a base dimension.  To define a dimension you need to provide
/// the derived class (CRTP) and a unique integer.
/// @code
/// struct my_dimension : streams_boost::units::base_dimension<my_dimension, 1> {};
/// @endcode
/// It is designed so that you will get an error message if you try
/// to use the same value in multiple definitions.
template<class Derived,
         long N
#if !defined(STREAMS_BOOST_UNITS_DOXYGEN) && !defined(__BORLANDC__)
         ,
         class = typename detail::ordinal_has_already_been_defined<
             check_base_dimension<Derived, N>::value
         >::type
#endif
>
class base_dimension : 
    public ordinal<N> 
{
    public:
        /// INTERNAL ONLY
        typedef base_dimension                                                          this_type;
        /// A convenience typedef.  Equivalent to streams_boost::units::derived_dimension<Derived,1>::type.
#ifndef STREAMS_BOOST_UNITS_DOXYGEN 
        typedef list<dim<Derived,static_rational<1> >, dimensionless_type>    dimension_type;
#else
        typedef detail::unspecified dimension_type;
#endif
        /// Provided for mpl compatability.
        typedef Derived type;

    private:
        /// Register this ordinal
        /// INTERNAL ONLY
        friend detail::yes 
        streams_boost_units_is_registered(const units::base_dimension_ordinal<N>&) 
        { detail::yes result; return(result); }
        
        /// But make sure we can identify the current instantiation!
        /// INTERNAL ONLY
        friend detail::yes 
        streams_boost_units_is_registered(const units::base_dimension_pair<Derived, N>&) 
        { detail::yes result; return(result); }
};

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_BASE_DIMENSION_HPP
