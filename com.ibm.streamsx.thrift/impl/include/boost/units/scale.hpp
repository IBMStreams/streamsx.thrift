// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_SCALE_HPP_INCLUDED
#define STREAMS_BOOST_UNITS_SCALE_HPP_INCLUDED

#include <string>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/static_rational.hpp>
#include <streams_boost/units/units_fwd.hpp>
#include <streams_boost/units/detail/one.hpp>
#include <streams_boost/units/detail/static_rational_power.hpp>

namespace streams_boost {

namespace units {

template<class S, class Scale>
struct scaled_base_unit;

/// class representing a scaling factor such as 10^3
/// The exponent should be a static rational.
template<long Base, class Exponent>
struct scale
{
    static const long base = Base;
    typedef Exponent exponent;
    typedef double value_type;
    static value_type value() { return(detail::static_rational_power<Exponent>(static_cast<double>(base))); }
    // These need to be defined in specializations for
    // printing to work.
    // static std::string name();
    // static std::string symbol();
};

template<long Base, class Exponent>
const long scale<Base, Exponent>::base;

/// INTERNAL ONLY
template<long Base>
struct scale<Base, static_rational<0> >
{
    static const long base = Base;
    typedef static_rational<0> exponent;
    typedef one value_type;
    static one value() { one result; return(result); }
    static std::string name() { return(""); }
    static std::string symbol() { return(""); }
};

template<long Base>
const long scale<Base, static_rational<0> >::base;

template<long Base,class Exponent>
std::string symbol_string(const scale<Base,Exponent>&)
{
    return scale<Base,Exponent>::symbol();
}

template<long Base,class Exponent>
std::string name_string(const scale<Base,Exponent>&)
{
    return scale<Base,Exponent>::name();
}

#ifndef STREAMS_BOOST_UNITS_DOXYGEN

#define STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(base_,exponent_,val_,name_,symbol_) \
template<>                                                                   \
struct scale<base_, exponent_ >                                              \
{                                                                            \
    static const long base = base_;                                          \
    typedef exponent_ exponent;                                              \
    typedef double value_type;                                               \
    static value_type value()   { return(val_); }                            \
    static std::string name()   { return(#name_); }                          \
    static std::string symbol() { return(#symbol_); }                        \
}

#define STREAMS_BOOST_UNITS_SCALE_DEF(exponent_,value_,name_,symbol_)                 \
STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(10,static_rational<exponent_>,value_, name_, symbol_)

STREAMS_BOOST_UNITS_SCALE_DEF(-24, 1e-24 ,yocto, y);
STREAMS_BOOST_UNITS_SCALE_DEF(-21, 1e-21, zepto, z);
STREAMS_BOOST_UNITS_SCALE_DEF(-18, 1e-18, atto, a);
STREAMS_BOOST_UNITS_SCALE_DEF(-15, 1e-15, femto, f);
STREAMS_BOOST_UNITS_SCALE_DEF(-12, 1e-12, pico, p);
STREAMS_BOOST_UNITS_SCALE_DEF(-9, 1e-9, nano, n);
STREAMS_BOOST_UNITS_SCALE_DEF(-6, 1e-6, micro, u);
STREAMS_BOOST_UNITS_SCALE_DEF(-3, 1e-3, milli, m);
STREAMS_BOOST_UNITS_SCALE_DEF(-2, 1e-2, centi, c);
STREAMS_BOOST_UNITS_SCALE_DEF(-1, 1e-1, deci, d);

STREAMS_BOOST_UNITS_SCALE_DEF(1, 1e1, deka, da);
STREAMS_BOOST_UNITS_SCALE_DEF(2, 1e2, hecto, h);
STREAMS_BOOST_UNITS_SCALE_DEF(3, 1e3, kilo, k);
STREAMS_BOOST_UNITS_SCALE_DEF(6, 1e6, mega, M);
STREAMS_BOOST_UNITS_SCALE_DEF(9, 1e9, giga, G);
STREAMS_BOOST_UNITS_SCALE_DEF(12, 1e12, tera, T);
STREAMS_BOOST_UNITS_SCALE_DEF(15, 1e15, peta, P);
STREAMS_BOOST_UNITS_SCALE_DEF(18, 1e18, exa, E);
STREAMS_BOOST_UNITS_SCALE_DEF(21, 1e21, zetta, Z);
STREAMS_BOOST_UNITS_SCALE_DEF(24, 1e24, yotta, Y);

STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<10>, 1024.0, kibi, Ki);
STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<20>, 1048576.0, mebi, Mi);
STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<30>, 1073741824.0, gibi, Gi);
STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<40>, 1099511627776.0, tebi, Ti);
STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<50>, 1125899906842624.0, pebi, Pi);
STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<60>, 1152921504606846976.0, exbi, Ei);

#undef STREAMS_BOOST_UNITS_SCALE_DEF
#undef STREAMS_BOOST_UNITS_SCALE_SPECIALIZATION

#endif

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::units::scale, (long)(class))

#endif

#endif
