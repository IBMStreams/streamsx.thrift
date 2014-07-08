//  Boost math_fwd.hpp header file  ------------------------------------------//

//  (C) Copyright Hubert Holin and Daryle Walker 2001-2002.  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/math for documentation.

#ifndef STREAMS_BOOST_MATH_FWD_HPP
#define STREAMS_BOOST_MATH_FWD_HPP


namespace streams_boost
{
namespace math
{


//  From <streams_boost/math/quaternion.hpp>  ----------------------------------------//

template < typename T >
    class quaternion;

template < >
    class quaternion< float >;
template < >
    class quaternion< double >;
template < >
    class quaternion< long double >;

// Also has many function templates (including operators)


//  From <streams_boost/math/octonion.hpp>  ------------------------------------------//

template < typename T >
    class octonion;

template < >
    class octonion< float >;
template < >
    class octonion< double >;
template < >
    class octonion< long double >;

// Also has many function templates (including operators)


//  From <streams_boost/math/special_functions/acosh.hpp>  ---------------------------//

// Only has function template


//  From <streams_boost/math/special_functions/asinh.hpp>  ---------------------------//

// Only has function template


//  From <streams_boost/math/special_functions/atanh.hpp>  ---------------------------//

// Only has function template


//  From <streams_boost/math/special_functions/sinc.hpp>  ----------------------------//

// Only has function templates


//  From <streams_boost/math/special_functions/sinhc.hpp>  ---------------------------//

// Only has function templates


//  From <streams_boost/math/common_factor.hpp>  -------------------------------------//

// Only #includes other headers


//  From <streams_boost/math/common_factor_ct.hpp>  ----------------------------------//

template < unsigned long Value1, unsigned long Value2 >
    struct static_gcd;
template < unsigned long Value1, unsigned long Value2 >
    struct static_lcm;


//  From <streams_boost/math/common_factor_rt.hpp>  ----------------------------------//

template < typename IntegerType >
    class gcd_evaluator;
template < typename IntegerType >
    class lcm_evaluator;

// Also has a couple of function templates


}  // namespace math
}  // namespace streams_boost


#endif  // STREAMS_BOOST_MATH_FWD_HPP
