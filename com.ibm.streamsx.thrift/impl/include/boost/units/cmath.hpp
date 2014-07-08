// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_CMATH_HPP 
#define STREAMS_BOOST_UNITS_CMATH_HPP

#include <streams_boost/config/no_tr1/cmath.hpp>
#include <cstdlib>

#include <streams_boost/math/special_functions/fpclassify.hpp>
#include <streams_boost/math/special_functions/hypot.hpp>
#include <streams_boost/math/special_functions/next.hpp>
#include <streams_boost/math/special_functions/round.hpp>
#include <streams_boost/math/special_functions/sign.hpp>

#include <streams_boost/units/dimensionless_quantity.hpp>
#include <streams_boost/units/pow.hpp>
#include <streams_boost/units/quantity.hpp>
#include <streams_boost/units/detail/cmath_impl.hpp>

#include <streams_boost/units/systems/si/plane_angle.hpp>

/// \file 
/// \brief Overloads of functions in \<cmath\> for quantities
///
/// \detailed Only functions for which a dimensionally-correct result type  
/// can be determined are overloaded. All functions work with dimensionless
/// quantities.

// STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION is needed on certain compilers that define 
// some <cmath> functions as macros; it is used for all functions even though it
// isn't necessary -- I didn't want to think :)
//
// the form using namespace detail; return(f(x)); is used
// to enable ADL for UDTs

namespace streams_boost {

namespace units { 

template<class Unit,class Y>
inline 
bool 
isfinite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{ 
    using streams_boost::math::isfinite;
    return isfinite STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value());
}

template<class Unit,class Y>
inline 
bool 
isinf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{ 
    using streams_boost::math::isinf;
    return isinf STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value());
}

template<class Unit,class Y>
inline
bool 
isnan STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{ 
    using streams_boost::math::isnan;
    return isnan STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value());
}

template<class Unit,class Y>
inline 
bool 
isnormal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{ 
    using streams_boost::math::isnormal;
    return isnormal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value());
}

template<class Unit,class Y>
inline 
bool 
isgreater STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                            const quantity<Unit,Y>& q2)
{ 
    using namespace detail;
    return isgreater STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value());
}

template<class Unit,class Y>
inline 
bool 
isgreaterequal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                                 const quantity<Unit,Y>& q2)
{ 
    using namespace detail;
    return isgreaterequal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value());
}

template<class Unit,class Y>
inline 
bool 
isless STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                         const quantity<Unit,Y>& q2)
{ 
    using namespace detail;
    return isless STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value());
}

template<class Unit,class Y>
inline 
bool 
islessequal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                              const quantity<Unit,Y>& q2)
{ 
    using namespace detail;
    return islessequal STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value());
}

template<class Unit,class Y>
inline 
bool 
islessgreater STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                                const quantity<Unit,Y>& q2)
{ 
    using namespace detail;
    return islessgreater STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value());
}

template<class Unit,class Y>
inline 
bool 
isunordered STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                              const quantity<Unit,Y>& q2)
{ 
    using namespace detail;
    return isunordered STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value());
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
abs STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using std::abs;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(abs STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
ceil STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using std::ceil;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(ceil STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
         const quantity<Unit,Y>& q2)
{
    using streams_boost::math::copysign;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(copysign STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
fabs STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using std::fabs;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(fabs STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
floor STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using std::floor;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(floor STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
fdim STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                       const quantity<Unit,Y>& q2)
{
    using namespace detail;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(fdim STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}

#if 0

template<class Unit1,class Unit2,class Unit3,class Y>
inline 
typename add_typeof_helper<
    typename multiply_typeof_helper<quantity<Unit1,Y>,
                                    quantity<Unit2,Y> >::type,
    quantity<Unit3,Y> >::type 
fma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit1,Y>& q1,
                                      const quantity<Unit2,Y>& q2,
                                      const quantity<Unit3,Y>& q3)
{
    using namespace detail;

    typedef quantity<Unit1,Y>   type1;
    typedef quantity<Unit2,Y>   type2;
    typedef quantity<Unit3,Y>   type3;
    
    typedef typename multiply_typeof_helper<type1,type2>::type  prod_type;
    typedef typename add_typeof_helper<prod_type,type3>::type   quantity_type;
    
    return quantity_type::from_value(fma STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value(),q3.value()));
}

#endif

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                       const quantity<Unit,Y>& q2)
{
    using namespace detail;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(fmax STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                       const quantity<Unit,Y>& q2)
{
    using namespace detail;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(fmin STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}

template<class Unit,class Y>
inline 
int 
fpclassify STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{ 
    using streams_boost::math::fpclassify;

    return fpclassify STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value());
}

template<class Unit,class Y>
inline 
typename root_typeof_helper<
    typename add_typeof_helper<
        typename power_typeof_helper<quantity<Unit,Y>,
                                     static_rational<2> >::type,
        typename power_typeof_helper<quantity<Unit,Y>,
                                     static_rational<2> >::type>::type,
        static_rational<2> >::type
hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,const quantity<Unit,Y>& q2)
{
    using streams_boost::math::hypot;

    typedef quantity<Unit,Y>    type1;
    
    typedef typename power_typeof_helper<type1,static_rational<2> >::type   pow_type;
    typedef typename add_typeof_helper<pow_type,pow_type>::type             add_type;
    typedef typename root_typeof_helper<add_type,static_rational<2> >::type quantity_type;
        
    return quantity_type::from_value(hypot STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}

// does ISO C++ support long long? g++ claims not
//template<class Unit,class Y>
//inline 
//quantity<Unit,long long> 
//llrint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
//{
//    using namespace detail;
//
//    typedef quantity<Unit,long long>    quantity_type;
//    
//    return quantity_type::from_value(llrint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
//}

// does ISO C++ support long long? g++ claims not
//template<class Unit,class Y>
//inline 
//quantity<Unit,long long> 
//llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
//{
//    using namespace detail;
//
//    typedef quantity<Unit,long long>    quantity_type;
//    
//    return quantity_type::from_value(llround STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
//}

#if 0

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
nearbyint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using namespace detail;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(nearbyint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

#endif

template<class Unit,class Y>
inline 
quantity<Unit,Y> nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                                             const quantity<Unit,Y>& q2)
{
    using streams_boost::math::nextafter;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}
template<class Unit,class Y>
inline 
quantity<Unit,Y> nexttoward STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q1,
                                                              const quantity<Unit,Y>& q2)
{
    // the only difference between nextafter and nexttowards is
    // in the argument types.  Since we are requiring identical
    // argument types, there is no difference.
    using streams_boost::math::nextafter;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(nextafter STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q1.value(),q2.value()));
}

#if 0

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
rint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using namespace detail;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(rint STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

#endif

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using streams_boost::math::round;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(round STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

template<class Unit,class Y>
inline 
int 
signbit STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{ 
    using streams_boost::math::signbit;

    return signbit STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value());
}

template<class Unit,class Y>
inline 
quantity<Unit,Y> 
trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (const quantity<Unit,Y>& q)
{
    using namespace detail;

    typedef quantity<Unit,Y>    quantity_type;
    
    return quantity_type::from_value(trunc STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (q.value()));
}

template<class Unit,class Y>
inline
quantity<Unit, Y>
fmod(const quantity<Unit,Y>& q1, const quantity<Unit,Y>& q2)
{
    using std::fmod;
    
    typedef quantity<Unit,Y> quantity_type;

    return quantity_type::from_value(fmod(q1.value(), q2.value()));
}

template<class Unit, class Y>
inline
quantity<Unit, Y>
modf(const quantity<Unit, Y>& q1, quantity<Unit, Y>* q2)
{
    using std::modf;

    typedef quantity<Unit,Y> quantity_type;

    return quantity_type::from_value(modf(q1.value(), &quantity_cast<Y&>(*q2)));
}

template<class Unit, class Y, class Int>
inline
quantity<Unit, Y>
frexp(const quantity<Unit, Y>& q,Int* ex)
{
    using std::frexp;

    typedef quantity<Unit,Y> quantity_type;

    return quantity_type::from_value(frexp(q.value(),ex));
}

/// For non-dimensionless quantities, integral and rational powers 
/// and roots can be computed by @c pow<Ex> and @c root<Rt> respectively.
template<class S, class Y>
inline
quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>
pow(const quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>& q1,
    const quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>& q2)
{
    using std::pow;

    typedef quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S),Y> quantity_type;

    return quantity_type::from_value(pow(q1.value(), q2.value()));
}

template<class S, class Y>
inline
quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>
exp(const quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>& q)
{
    using std::exp;

    typedef quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y> quantity_type;

    return quantity_type::from_value(exp(q.value()));
}

template<class Unit, class Y, class Int>
inline
quantity<Unit, Y>
ldexp(const quantity<Unit, Y>& q,const Int& ex)
{
    using std::ldexp;

    typedef quantity<Unit,Y> quantity_type;

    return quantity_type::from_value(ldexp(q.value(), ex));
}

template<class S, class Y>
inline
quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>
log(const quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>& q)
{
    using std::log;

    typedef quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y> quantity_type;

    return quantity_type::from_value(log(q.value()));
}

template<class S, class Y>
inline
quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>
log10(const quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y>& q)
{
    using std::log10;

    typedef quantity<STREAMS_BOOST_UNITS_DIMENSIONLESS_UNIT(S), Y> quantity_type;

    return quantity_type::from_value(log10(q.value()));
}

template<class Unit,class Y>
inline 
typename root_typeof_helper<
                            quantity<Unit,Y>,
                            static_rational<2>
                           >::type
sqrt(const quantity<Unit,Y>& q)
{
    using std::sqrt;

    typedef typename root_typeof_helper<
                                        quantity<Unit,Y>,
                                        static_rational<2>
                                       >::type quantity_type;

    return quantity_type::from_value(sqrt(q.value()));
}

} // namespace units

} // namespace streams_boost

namespace streams_boost {

namespace units {

// trig functions with si argument/return types

/// cos of theta in radians
template<class Y>
typename dimensionless_quantity<si::system,Y>::type 
cos(const quantity<si::plane_angle,Y>& theta)
{
    using std::cos;
    return cos(theta.value());
}

/// sin of theta in radians
template<class Y>
typename dimensionless_quantity<si::system,Y>::type 
sin(const quantity<si::plane_angle,Y>& theta)
{
    using std::sin;
    return sin(theta.value());
}

/// tan of theta in radians
template<class Y>
typename dimensionless_quantity<si::system,Y>::type 
tan(const quantity<si::plane_angle,Y>& theta)
{
    using std::tan;
    return tan(theta.value());
}

/// cos of theta in other angular units 
template<class System,class Y>
typename dimensionless_quantity<System,Y>::type 
cos(const quantity<unit<plane_angle_dimension,System>,Y>& theta)
{
    return cos(quantity<si::plane_angle,Y>(theta));
}

/// sin of theta in other angular units 
template<class System,class Y>
typename dimensionless_quantity<System,Y>::type 
sin(const quantity<unit<plane_angle_dimension,System>,Y>& theta)
{
    return sin(quantity<si::plane_angle,Y>(theta));
}

/// tan of theta in other angular units 
template<class System,class Y>
typename dimensionless_quantity<System,Y>::type 
tan(const quantity<unit<plane_angle_dimension,System>,Y>& theta)
{
    return tan(quantity<si::plane_angle,Y>(theta));
}

/// acos of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<plane_angle_dimension, homogeneous_system<System> >,Y>
acos(const quantity<unit<dimensionless_type, homogeneous_system<System> >,Y>& val)
{
    using std::acos;
    return quantity<unit<plane_angle_dimension, homogeneous_system<System> >,Y>(acos(val.value())*si::radians);
}

/// asin of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<plane_angle_dimension, homogeneous_system<System> >,Y>
asin(const quantity<unit<dimensionless_type, homogeneous_system<System> >,Y>& val)
{
    using std::asin;
    return quantity<unit<plane_angle_dimension, homogeneous_system<System> >,Y>(asin(val.value())*si::radians);
}

/// atan of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<plane_angle_dimension, homogeneous_system<System> >,Y>
atan(const quantity<unit<dimensionless_type, homogeneous_system<System> >, Y>& val)
{
    using std::atan;
    return quantity<unit<plane_angle_dimension, homogeneous_system<System> >,Y>(atan(val.value())*si::radians);
}

/// atan2 of @c value_type returning angle in radians
template<class Y, class Dimension, class System>
quantity<unit<plane_angle_dimension, homogeneous_system<System> >, Y>
atan2(const quantity<unit<Dimension, homogeneous_system<System> >, Y>& y,
      const quantity<unit<Dimension, homogeneous_system<System> >, Y>& x)
{
    using std::atan2;
    return quantity<unit<plane_angle_dimension, homogeneous_system<System> >, Y>(atan2(y.value(),x.value())*si::radians);
}

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_CMATH_HPP
