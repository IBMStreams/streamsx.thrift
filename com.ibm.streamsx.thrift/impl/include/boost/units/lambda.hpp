// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// $Id: lambda.hpp 27 2008-06-16 14:50:58Z maehne $

#ifndef STREAMS_BOOST_UNITS_LAMBDA_HPP
#define STREAMS_BOOST_UNITS_LAMBDA_HPP


////////////////////////////////////////////////////////////////////////
///
/// \file lambda.hpp
///
/// \brief Definitions to ease the usage of Boost.Units' quantity,
///        unit, and absolute types in functors created with the
///        Boost.Lambda library.
///
/// \author Torsten Maehne
/// \date   2008-06-16
///
/// Boost.Lambda's return type deduction system is extented to make
/// use of Boost.Units' typeof_helper trait classes for Boost.Units'
/// quantity, absolute, and unit template classes.
///
////////////////////////////////////////////////////////////////////////


#include <streams_boost/lambda/lambda.hpp>
#include <streams_boost/units/units_fwd.hpp>
#include <streams_boost/units/detail/dimensionless_unit.hpp>
#include <streams_boost/units/operators.hpp>

namespace streams_boost {

namespace lambda {

    /// Partial specialization of return type trait for action
    /// unit<Dim, System> * Y.
    template<typename System, typename Dim, typename Y>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::unit<Dim, System>,
                               Y > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            streams_boost::units::unit<Dim, System>, Y >::type type;
    };

} // namespace lambda

namespace units {

    template<typename System, typename Dim, typename Arg>
    struct multiply_typeof_helper<streams_boost::units::unit<Dim, System>, streams_boost::lambda::lambda_functor<Arg> > {
        typedef streams_boost::lambda::lambda_functor<
          streams_boost::lambda::lambda_functor_base<
              streams_boost::lambda::arithmetic_action<streams_boost::lambda::multiply_action>,
              tuple<typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type, streams_boost::lambda::lambda_functor<Arg> >
          >
        > type;
    };

    /// Disambiguating overload for action
    /// unit<Dim, System> * lambda_functor<Arg>
    /// based on \<streams_boost/lambda/detail/operators.hpp\>.
    template<typename System, typename Dim, typename Arg>
    inline const typename multiply_typeof_helper<streams_boost::units::unit<Dim, System>, streams_boost::lambda::lambda_functor<Arg> >::type
    operator*(const streams_boost::units::unit<Dim, System>& a,
              const streams_boost::lambda::lambda_functor<Arg>& b) {
        return typename multiply_typeof_helper<streams_boost::units::unit<Dim, System>, streams_boost::lambda::lambda_functor<Arg> >::type::inherited
               (tuple<typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type,
                      streams_boost::lambda::lambda_functor<Arg> >
                     (a, b));
    }

} // namespace units

namespace lambda {

    /// Partial specialization of return type trait for action
    /// unit<Dim, System> / Y.
    template<typename System, typename Dim, typename Y>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               streams_boost::units::unit<Dim, System>,
                               Y > {
        typedef typename streams_boost::units::divide_typeof_helper<
            streams_boost::units::unit<Dim, System>, Y >::type type;
    };

} // namespace lambda

namespace units {

    template<typename System, typename Dim, typename Arg>
    struct divide_typeof_helper<streams_boost::units::unit<Dim, System>, streams_boost::lambda::lambda_functor<Arg> > {
        typedef streams_boost::lambda::lambda_functor<
          streams_boost::lambda::lambda_functor_base<
            streams_boost::lambda::arithmetic_action<streams_boost::lambda::divide_action>,
              tuple<typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type, streams_boost::lambda::lambda_functor<Arg> >
          >
        > type;
    };

    /// Disambiguating overload for action
    /// unit<Dim, System> / lambda_functor<Arg>
    /// based on \<streams_boost/lambda/detail/operators.hpp\>.
    template<typename System, typename Dim, typename Arg>
    inline const typename divide_typeof_helper<streams_boost::units::unit<Dim, System>, streams_boost::lambda::lambda_functor<Arg> >::type
    operator/(const streams_boost::units::unit<Dim, System>& a,
              const streams_boost::lambda::lambda_functor<Arg>& b) {
        return typename divide_typeof_helper<streams_boost::units::unit<Dim, System>, streams_boost::lambda::lambda_functor<Arg> >::type::inherited
               (tuple<typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type,
                      streams_boost::lambda::lambda_functor<Arg> >
                     (a, b));
    }

} // namespace units

namespace lambda {

    /// Partial specialization of return type trait for action
    /// Y * unit<Dim, System>.
    template<typename System, typename Dim, typename Y>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               Y,
                               streams_boost::units::unit<Dim, System> > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            Y, streams_boost::units::unit<Dim, System> >::type type;
    };

} // namespace lambda

namespace units {

    template<typename System, typename Dim, typename Arg>
    struct multiply_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::unit<Dim, System> > {
        typedef streams_boost::lambda::lambda_functor<
          streams_boost::lambda::lambda_functor_base<
            streams_boost::lambda::arithmetic_action<streams_boost::lambda::multiply_action>,
              tuple<streams_boost::lambda::lambda_functor<Arg>, typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type>
          >
        > type;
    };

    /// Disambiguating overload for action
    /// lambda_functor<Arg> * unit<Dim, System>
    /// based on \<streams_boost/lambda/detail/operators.hpp\>.
    template<typename System, typename Dim, typename Arg>
    inline const typename multiply_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::unit<Dim, System> >::type
    operator*(const streams_boost::lambda::lambda_functor<Arg>& a,
              const streams_boost::units::unit<Dim, System>& b) {
        return typename multiply_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::unit<Dim, System> >::type::inherited
               (tuple<streams_boost::lambda::lambda_functor<Arg>,
                      typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type>
                     (a, b));
    }

} // namespace units

namespace lambda {

    /// Partial specialization of return type trait for action
    /// Y / unit<Dim, System>.
    template<typename System, typename Dim, typename Y>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               Y,
                               streams_boost::units::unit<Dim, System> > {
        typedef typename streams_boost::units::divide_typeof_helper<
            Y, streams_boost::units::unit<Dim, System> >::type type;
    };

} // namespace lambda

namespace units {

    template<typename System, typename Dim, typename Arg>
    struct divide_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::unit<Dim, System> > {
        typedef streams_boost::lambda::lambda_functor<
          streams_boost::lambda::lambda_functor_base<
            streams_boost::lambda::arithmetic_action<streams_boost::lambda::divide_action>,
              tuple<streams_boost::lambda::lambda_functor<Arg>, typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type>
          >
        > type;
    };

    /// Disambiguating overload for action
    /// lambda_functor<Arg> / unit<Dim, System>
    /// based on \<streams_boost/lambda/detail/operators.hpp\>.
    template<typename System, typename Dim, typename Arg>
    inline const typename divide_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::unit<Dim, System> >::type
    operator/(const streams_boost::lambda::lambda_functor<Arg>& a,
              const streams_boost::units::unit<Dim, System>& b) {
        return typename divide_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::unit<Dim, System> >::type::inherited
               (tuple<streams_boost::lambda::lambda_functor<Arg>,
                      typename streams_boost::lambda::const_copy_argument<const streams_boost::units::unit<Dim, System> >::type>
                     (a, b));
    }

} // namespace units

namespace lambda {

    /// Partial specialization of return type trait for action
    /// quantity<Unit, X> * X.
    template<typename Unit, typename X>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::quantity<Unit, X>,
                               X> {
        typedef typename streams_boost::units::multiply_typeof_helper<
            streams_boost::units::quantity<Unit, X>, X>::type type;
    };

    /// Partial specialization of return type trait for action
    /// X * quantity<Unit, X>.
    template<typename Unit, typename X>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               X,
                               streams_boost::units::quantity<Unit, X> > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            X, streams_boost::units::quantity<Unit, X> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit, X> / X.
    template<typename Unit, typename X>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               streams_boost::units::quantity<Unit, X>,
                               X> {
        typedef typename streams_boost::units::divide_typeof_helper<
            streams_boost::units::quantity<Unit, X>, X>::type type;
    };

    /// Partial specialization of return type trait for action
    /// X / quantity<Unit, X>.
    template<typename Unit, typename X>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               X,
                               streams_boost::units::quantity<Unit, X> > {
        typedef typename streams_boost::units::divide_typeof_helper<
            X, streams_boost::units::quantity<Unit, X> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// unit<Dim1, System1> * quantity<Unit2, Y>.
    template<typename System1, typename Dim1, typename Unit2, typename Y>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::unit<Dim1, System1>,
                               streams_boost::units::quantity<Unit2, Y> > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            streams_boost::units::unit<Dim1, System1>,
            streams_boost::units::quantity<Unit2, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// unit<Dim1, System1> / quantity<Unit2, Y>.
    template<typename System1, typename Dim1, typename Unit2, typename Y>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               streams_boost::units::unit<Dim1, System1>,
                               streams_boost::units::quantity<Unit2, Y> > {
        typedef typename streams_boost::units::divide_typeof_helper<
            streams_boost::units::unit<Dim1, System1>,
            streams_boost::units::quantity<Unit2, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit1, Y> * unit<Dim2, System2>.
    template<typename Unit1, typename Y, typename System2, typename Dim2>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::quantity<Unit1, Y>,
                               streams_boost::units::unit<Dim2, System2> > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            streams_boost::units::quantity<Unit1, Y>,
            streams_boost::units::unit<Dim2, System2> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit1, Y> / unit<Dim2, System2>.
    template<typename Unit1, typename Y, typename System2, typename Dim2>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               streams_boost::units::quantity<Unit1, Y>,
                               streams_boost::units::unit<Dim2, System2> > {
        typedef typename streams_boost::units::divide_typeof_helper<
            streams_boost::units::quantity<Unit1, Y>,
            streams_boost::units::unit<Dim2, System2> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// +quantity<Unit, Y>.
    template<typename Unit, typename Y>
    struct plain_return_type_1<unary_arithmetic_action<plus_action>,
                               streams_boost::units::quantity<Unit, Y> > {
        typedef typename streams_boost::units::unary_plus_typeof_helper<
            streams_boost::units::quantity<Unit, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// -quantity<Unit, Y>.
    template<typename Unit, typename Y>
    struct plain_return_type_1<unary_arithmetic_action<minus_action>,
                               streams_boost::units::quantity<Unit, Y> > {
        typedef typename streams_boost::units::unary_minus_typeof_helper<
            streams_boost::units::quantity<Unit, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit1, X> + quantity<Unit2, Y>.
    template<typename Unit1, typename X, typename Unit2, typename Y>
    struct plain_return_type_2<arithmetic_action<plus_action>,
                               streams_boost::units::quantity<Unit1, X>,
                               streams_boost::units::quantity<Unit2, Y> > {
        typedef typename streams_boost::units::add_typeof_helper<
            streams_boost::units::quantity<Unit1, X>,
            streams_boost::units::quantity<Unit2, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<dimensionless, X> + Y.
    template<typename System, typename X, typename Y>
    struct plain_return_type_2<arithmetic_action<plus_action>,
                               streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), X>,
                               Y> {
        typedef typename streams_boost::units::add_typeof_helper<
            streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), X>,
            Y>::type type;
    };

    /// Partial specialization of return type trait for action
    /// X + quantity<dimensionless, Y>.
    template<typename System, typename X, typename Y>
    struct plain_return_type_2<arithmetic_action<plus_action>,
                               X,
                               streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), Y> > {
        typedef typename streams_boost::units::add_typeof_helper<
            X,
            streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit1, X> - quantity<Unit2, Y>.
    template<typename Unit1, typename X, typename Unit2, typename Y>
    struct plain_return_type_2<arithmetic_action<minus_action>,
                               streams_boost::units::quantity<Unit1, X>,
                               streams_boost::units::quantity<Unit2, Y> > {
        typedef typename streams_boost::units::subtract_typeof_helper<
            streams_boost::units::quantity<Unit1, X>,
            streams_boost::units::quantity<Unit2, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<dimensionless, X> - Y.
    template<typename System, typename X, typename Y>
    struct plain_return_type_2<arithmetic_action<minus_action>,
                               streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), X>,
                               Y> {
        typedef typename streams_boost::units::subtract_typeof_helper<
            streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), X>,
            Y>::type type;
    };

    /// Partial specialization of return type trait for action
    /// X - quantity<dimensionless, Y>.
    template<typename System, typename X, typename Y>
    struct plain_return_type_2<arithmetic_action<minus_action>,
                               X,
                               streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), Y> > {
        typedef typename streams_boost::units::subtract_typeof_helper<
            X,
            streams_boost::units::quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(System), Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit1, X> * quantity<Unit2, Y>.
    template<typename Unit1, typename X, typename Unit2, typename Y>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::quantity<Unit1, X>,
                               streams_boost::units::quantity<Unit2, Y> > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            streams_boost::units::quantity<Unit1, X>,
            streams_boost::units::quantity<Unit2, Y> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// quantity<Unit1, X> / quantity<Unit2, Y>.
    template<typename Unit1, typename X, typename Unit2, typename Y>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               streams_boost::units::quantity<Unit1, X>,
                               streams_boost::units::quantity<Unit2, Y> > {
        typedef typename streams_boost::units::divide_typeof_helper<
            streams_boost::units::quantity<Unit1, X>,
            streams_boost::units::quantity<Unit2, Y> >::type type;
    };


    ////////////////////////////////////////////////////////////////////////
    // Partial specialization of Boost.Lambda's trait classes for all
    // operators overloaded in <streams_boost/units/unit.hpp>
    ////////////////////////////////////////////////////////////////////////

    /// Partial specialization of return type trait for action
    /// +unit<Dim, System>.
    template<typename Dim, typename System>
    struct plain_return_type_1<unary_arithmetic_action<plus_action>,
                               streams_boost::units::unit<Dim, System> > {
        typedef typename streams_boost::units::unary_plus_typeof_helper<
            streams_boost::units::unit<Dim, System> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// -unit<Dim, System>.
    template<typename Dim, typename System>
    struct plain_return_type_1<unary_arithmetic_action<minus_action>,
                               streams_boost::units::unit<Dim, System> > {
        typedef typename streams_boost::units::unary_minus_typeof_helper<
            streams_boost::units::unit<Dim, System> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// unit<Dim1, System1> + unit<Dim2, System2>.
    template<typename Dim1, typename Dim2, typename System1, typename System2>
    struct plain_return_type_2<arithmetic_action<plus_action>,
                               streams_boost::units::unit<Dim1, System1>,
                               streams_boost::units::unit<Dim2, System2> > {
        typedef typename streams_boost::units::add_typeof_helper<
            streams_boost::units::unit<Dim1, System1>,
            streams_boost::units::unit<Dim2, System2> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// unit<Dim1, System1> - unit<Dim2, System2>.
    template<typename Dim1, typename Dim2, typename System1, typename System2>
    struct plain_return_type_2<arithmetic_action<minus_action>,
                               streams_boost::units::unit<Dim1, System1>,
                               streams_boost::units::unit<Dim2, System2> > {
        typedef typename streams_boost::units::subtract_typeof_helper<
            streams_boost::units::unit<Dim1, System1>,
            streams_boost::units::unit<Dim2, System2> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// unit<Dim1, System1> * unit<Dim2, System2>.
    template<typename Dim1, typename Dim2, typename System1, typename System2>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::unit<Dim1, System1>,
                               streams_boost::units::unit<Dim2, System2> > {
        typedef typename streams_boost::units::multiply_typeof_helper<
            streams_boost::units::unit<Dim1, System1>,
            streams_boost::units::unit<Dim2, System2> >::type type;
    };

    /// Partial specialization of return type trait for action
    /// unit<Dim1, System1> / unit<Dim2, System2>.
    template<typename Dim1, typename Dim2, typename System1, typename System2>
    struct plain_return_type_2<arithmetic_action<divide_action>,
                               streams_boost::units::unit<Dim1, System1>,
                               streams_boost::units::unit<Dim2, System2> > {
        typedef typename streams_boost::units::divide_typeof_helper<
            streams_boost::units::unit<Dim1, System1>,
            streams_boost::units::unit<Dim2, System2> >::type type;
    };


    ////////////////////////////////////////////////////////////////////////
    // Partial specialization of Boost.Lambda's trait classes for all
    // operators overloaded in <streams_boost/units/absolute.hpp>
    ////////////////////////////////////////////////////////////////////////


    /// Partial specialization of return type trait for action
    /// absolute<Y> + Y.
    template<typename Y>
    struct plain_return_type_2<arithmetic_action<plus_action>,
                               streams_boost::units::absolute<Y>,
                               Y> {
        typedef typename streams_boost::units::absolute<Y> type;
    };

    /// Partial specialization of return type trait for action
    /// Y + absolute<Y>.
    template<typename Y>
    struct plain_return_type_2<arithmetic_action<plus_action>,
                               Y,
                               streams_boost::units::absolute<Y> > {
        typedef typename streams_boost::units::absolute<Y> type;
    };

    /// Partial specialization of return type trait for action
    /// absolute<Y> - Y.
    template<typename Y>
    struct plain_return_type_2<arithmetic_action<minus_action>,
                               streams_boost::units::absolute<Y>,
                               Y> {
        typedef typename streams_boost::units::absolute<Y> type;
    };

    /// Partial specialization of return type trait for action
    /// absolute<Y> - absolute<Y>.
    template<typename Y>
    struct plain_return_type_2<arithmetic_action<minus_action>,
                               streams_boost::units::absolute<Y>,
                               streams_boost::units::absolute<Y> > {
        typedef Y type;
    };

    /// Partial specialization of return type trait for action
    /// T * absolute<unit<D, S> >.
    template<typename D, typename S, typename T>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               T,
                               streams_boost::units::absolute<streams_boost::units::unit<D, S> > > {
        typedef typename streams_boost::units::quantity<
            streams_boost::units::absolute<streams_boost::units::unit<D, S> >, T> type;
    };

} // namespace lambda

namespace units {
    
    template<typename System, typename Dim, typename Arg>
    struct multiply_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > > {
        typedef streams_boost::lambda::lambda_functor<
          streams_boost::lambda::lambda_functor_base<
            streams_boost::lambda::arithmetic_action<streams_boost::lambda::multiply_action>,
              tuple<streams_boost::lambda::lambda_functor<Arg>,
                    typename streams_boost::lambda::const_copy_argument<const streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > >::type>
          >
        > type;
    };

    /// Disambiguating overload for action
    /// lambda_functor<Arg> * absolute<unit<Dim, System> >
    /// based on \<streams_boost/lambda/detail/operators.hpp\>.
    template<typename System, typename Dim, typename Arg>
    inline const typename multiply_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > >::type
    operator*(const streams_boost::lambda::lambda_functor<Arg>& a,
              const streams_boost::units::absolute<streams_boost::units::unit<Dim, System> >& b) {
        return typename multiply_typeof_helper<streams_boost::lambda::lambda_functor<Arg>, streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > >::type::inherited
               (tuple<streams_boost::lambda::lambda_functor<Arg>,
                      typename streams_boost::lambda::const_copy_argument<const streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > >::type>
                     (a, b));
    }

} // namespace units

namespace lambda {

    /// Partial specialization of return type trait for action
    /// absolute<unit<D, S> > * T.
    template<typename D, typename S, typename T>
    struct plain_return_type_2<arithmetic_action<multiply_action>,
                               streams_boost::units::absolute<streams_boost::units::unit<D, S> >,
                               T> {
        typedef typename streams_boost::units::quantity<
            streams_boost::units::absolute<streams_boost::units::unit<D, S> >, T> type;
    };

} // namespace lambda

namespace units {
    
    template<typename System, typename Dim, typename Arg>
    struct multiply_typeof_helper<streams_boost::units::absolute<streams_boost::units::unit<Dim, System> >, streams_boost::lambda::lambda_functor<Arg> > {
        typedef streams_boost::lambda::lambda_functor<
          streams_boost::lambda::lambda_functor_base<
            streams_boost::lambda::arithmetic_action<streams_boost::lambda::multiply_action>,
              tuple<typename streams_boost::lambda::const_copy_argument<const streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > >::type,
                    streams_boost::lambda::lambda_functor<Arg> >
          >
        > type;
    };

    /// Disambiguating overload for action
    /// absolute<unit<Dim, System> > * lambda_functor<Arg>
    /// based on \<streams_boost/lambda/detail/operators.hpp\>.
    template<typename System, typename Dim, typename Arg>
    inline const typename multiply_typeof_helper<streams_boost::units::absolute<streams_boost::units::unit<Dim, System> >, streams_boost::lambda::lambda_functor<Arg> >::type
    operator*(const streams_boost::units::absolute<streams_boost::units::unit<Dim, System> >& a,
              const streams_boost::lambda::lambda_functor<Arg>& b) {
        return typename multiply_typeof_helper<streams_boost::units::absolute<streams_boost::units::unit<Dim, System> >, streams_boost::lambda::lambda_functor<Arg> >::type::inherited
               (tuple<typename streams_boost::lambda::const_copy_argument<const streams_boost::units::absolute<streams_boost::units::unit<Dim, System> > >::type,
                      streams_boost::lambda::lambda_functor<Arg> >
                     (a, b));
    }

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_LAMBDA_HPP
