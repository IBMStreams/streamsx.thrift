//  Boost common_factor_ct.hpp header file  ----------------------------------//

//  (C) Copyright Daryle Walker and Stephen Cleary 2001-2002.
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history. 

#ifndef STREAMS_BOOST_MATH_COMMON_FACTOR_CT_HPP
#define STREAMS_BOOST_MATH_COMMON_FACTOR_CT_HPP

#include <streams_boost/math_fwd.hpp>  // self include

#include <streams_boost/config.hpp>  // for STREAMS_BOOST_STATIC_CONSTANT, etc.


namespace streams_boost
{
namespace math
{


//  Implementation details  --------------------------------------------------//

namespace detail
{
#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    // Build GCD with Euclid's recursive algorithm
    template < unsigned long Value1, unsigned long Value2 >
    struct static_gcd_helper_t
    {
    private:
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, new_value1 = Value2 );
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, new_value2 = Value1 % Value2 );

        #ifndef __BORLANDC__
        #define STREAMS_BOOST_DETAIL_GCD_HELPER_VAL(Value) static_cast<unsigned long>(Value)
        #else
        typedef static_gcd_helper_t  self_type;
        #define STREAMS_BOOST_DETAIL_GCD_HELPER_VAL(Value)  (self_type:: Value )
        #endif

        typedef static_gcd_helper_t< STREAMS_BOOST_DETAIL_GCD_HELPER_VAL(new_value1),
         STREAMS_BOOST_DETAIL_GCD_HELPER_VAL(new_value2) >  next_step_type;

        #undef STREAMS_BOOST_DETAIL_GCD_HELPER_VAL

    public:
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = next_step_type::value );
    };

    // Non-recursive case
    template < unsigned long Value1 >
    struct static_gcd_helper_t< Value1, 0UL >
    {
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = Value1 );
    };
#else
    // Use inner class template workaround from Peter Dimov
    template < unsigned long Value1 >
    struct static_gcd_helper2_t
    {
        template < unsigned long Value2 >
        struct helper
        {
            STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value
             = static_gcd_helper2_t<Value2>::STREAMS_BOOST_NESTED_TEMPLATE
             helper<Value1 % Value2>::value );
        };

        template <  >
        struct helper< 0UL >
        {
            STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = Value1 );
        };
    };

    // Special case
    template <  >
    struct static_gcd_helper2_t< 0UL >
    {
        template < unsigned long Value2 >
        struct helper
        {
            STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = Value2 );
        };
    };

    // Build the GCD from the above template(s)
    template < unsigned long Value1, unsigned long Value2 >
    struct static_gcd_helper_t
    {
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value
         = static_gcd_helper2_t<Value1>::STREAMS_BOOST_NESTED_TEMPLATE
         helper<Value2>::value );
    };
#endif

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    // Build the LCM from the GCD
    template < unsigned long Value1, unsigned long Value2 >
    struct static_lcm_helper_t
    {
        typedef static_gcd_helper_t<Value1, Value2>  gcd_type;

        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = Value1 / gcd_type::value
         * Value2 );
    };

    // Special case for zero-GCD values
    template < >
    struct static_lcm_helper_t< 0UL, 0UL >
    {
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = 0UL );
    };
#else
    // Adapt GCD's inner class template workaround for LCM
    template < unsigned long Value1 >
    struct static_lcm_helper2_t
    {
        template < unsigned long Value2 >
        struct helper
        {
            typedef static_gcd_helper_t<Value1, Value2>  gcd_type;

            STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = Value1
             / gcd_type::value * Value2 );
        };

        template <  >
        struct helper< 0UL >
        {
            STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = 0UL );
        };
    };

    // Special case
    template <  >
    struct static_lcm_helper2_t< 0UL >
    {
        template < unsigned long Value2 >
        struct helper
        {
            STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value = 0UL );
        };
    };

    // Build the LCM from the above template(s)
    template < unsigned long Value1, unsigned long Value2 >
    struct static_lcm_helper_t
    {
        STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value
         = static_lcm_helper2_t<Value1>::STREAMS_BOOST_NESTED_TEMPLATE
         helper<Value2>::value );
    };
#endif

}  // namespace detail


//  Compile-time greatest common divisor evaluator class declaration  --------//

template < unsigned long Value1, unsigned long Value2 >
struct static_gcd
{
    STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value
     = (detail::static_gcd_helper_t<Value1, Value2>::value) );

};  // streams_boost::math::static_gcd


//  Compile-time least common multiple evaluator class declaration  ----------//

template < unsigned long Value1, unsigned long Value2 >
struct static_lcm
{
    STREAMS_BOOST_STATIC_CONSTANT( unsigned long, value
     = (detail::static_lcm_helper_t<Value1, Value2>::value) );

};  // streams_boost::math::static_lcm


}  // namespace math
}  // namespace streams_boost


#endif  // STREAMS_BOOST_MATH_COMMON_FACTOR_CT_HPP
