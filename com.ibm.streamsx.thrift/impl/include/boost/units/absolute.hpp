// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_ABSOLUTE_HPP
#define STREAMS_BOOST_UNITS_ABSOLUTE_HPP

#include <iosfwd>

#include <streams_boost/units/detail/absolute_impl.hpp>

namespace streams_boost {

namespace units {

/// A wrapper to represent absolute units (points rather than vectors).  Intended
/// originally for temperatures, this class implements operators for absolute units 
/// so that addition of a relative unit to an absolute unit results in another
/// absolute unit : absolute<T> +/- T -> absolute<T> and subtraction of one absolute
/// unit from another results in a relative unit : absolute<T> - absolute<T> -> T
template<class Y>
class absolute
{
    public:
        typedef absolute<Y>     this_type;
        typedef Y               value_type;
        
        absolute() : val_() { }
        absolute(const value_type& val) : val_(val) { }
        absolute(const this_type& source) : val_(source.val_) { }
   
        this_type& operator=(const this_type& source)           { val_ = source.val_; return *this; }
        
        const value_type& value() const                         { return val_; }
        
        const this_type& operator+=(const value_type& val)      { val_ += val; return *this; }
        const this_type& operator-=(const value_type& val)      { val_ -= val; return *this; }
        
    private:
        value_type   val_;
};

/// add a relative value to an absolute one
template<class Y>
absolute<Y> operator+(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()+rval);
}

/// add a relative value to an absolute one
template<class Y>
absolute<Y> operator+(const Y& rval,const absolute<Y>& aval)
{
    return absolute<Y>(aval.value()+rval);
}

/// subtract a relative value from an absolute one
template<class Y>
absolute<Y> operator-(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()-rval);
}

/// subtracting two absolutes gives a difference
template<class Y>
Y operator-(const absolute<Y>& aval1,const absolute<Y>& aval2)
{
    return Y(aval1.value()-aval2.value());
}

/// creates a quantity from an absolute unit and a raw value
template<class D, class S, class T>
quantity<absolute<unit<D, S> >, T> operator*(const T& t, const absolute<unit<D, S> >&)
{
    return(quantity<absolute<unit<D, S> >, T>::from_value(t));
}

/// creates a quantity from an absolute unit and a raw value
template<class D, class S, class T>
quantity<absolute<unit<D, S> >, T> operator*(const absolute<unit<D, S> >&, const T& t)
{
    return(quantity<absolute<unit<D, S> >, T>::from_value(t));
}

/// Print an absolute unit
template<class Char, class Traits, class Y>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,const absolute<Y>& aval)
{

    os << "absolute " << aval.value();
    
    return os;
}

} // namespace units

} // namespace streams_boost

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::units::absolute, (class))

#endif

namespace streams_boost {

namespace units {

/// Macro to define the offset between two absolute units.
/// Requires the value to be in the destination units e.g
/// @code
/// STREAMS_BOOST_UNITS_DEFINE_CONVERSION_OFFSET(celsius_base_unit, fahrenheit_base_unit, double, 32.0);
/// @endcode
/// @c STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR is also necessary to
/// specify the conversion factor.  Like @c STREAMS_BOOST_UNITS_DEFINE_CONVERSION_FACTOR
/// this macro defines both forward and reverse conversions so 
/// defining, e.g., the conversion from celsius to fahrenheit as above will also
/// define the inverse conversion from fahrenheit to celsius.
#define STREAMS_BOOST_UNITS_DEFINE_CONVERSION_OFFSET(From, To, type_, value_)   \
    namespace streams_boost {                                                   \
    namespace units {                                                   \
    template<>                                                          \
    struct affine_conversion_helper<                                    \
        reduce_unit<From::unit_type>::type,                             \
        reduce_unit<To::unit_type>::type>                               \
    {                                                                   \
        static const bool is_defined = true;                            \
        typedef type_ type;                                             \
        static type value() { return(value_); }                         \
    };                                                                  \
    }                                                                   \
    }                                                                   \
    void streams_boost_units_require_semicolon()

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_ABSOLUTE_HPP
