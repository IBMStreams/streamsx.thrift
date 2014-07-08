
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is guarded externally

#ifdef __WAVE__
// this file has been generated from the master.hpp file in the same directory
#   pragma wave option(preserve: 0)
#endif

#if !defined(STREAMS_BOOST_FT_PREPROCESSING_MODE) || defined(STREAMS_BOOST_FT_CONFIG_HPP_INCLUDED)
#   error "this file used with two-pass preprocessing, only"
#endif

#include <streams_boost/preprocessor/slot/slot.hpp>
#include <streams_boost/function_types/detail/encoding/def.hpp>

namespace streams_boost { namespace function_types {

typedef detail::property_tag<STREAMS_BOOST_FT_non_variadic,STREAMS_BOOST_FT_variadic_mask> non_variadic;
typedef detail::property_tag<STREAMS_BOOST_FT_variadic,STREAMS_BOOST_FT_variadic_mask>     variadic;
                                                                       
typedef detail::property_tag<0,STREAMS_BOOST_FT_const>                     non_const;
typedef detail::property_tag<STREAMS_BOOST_FT_const,STREAMS_BOOST_FT_const>        const_qualified;
                                                                       
typedef detail::property_tag<0,STREAMS_BOOST_FT_volatile>                  non_volatile;
typedef detail::property_tag<STREAMS_BOOST_FT_volatile,STREAMS_BOOST_FT_volatile>  volatile_qualified; 

typedef detail::property_tag<STREAMS_BOOST_FT_default_cc,STREAMS_BOOST_FT_cc_mask> default_cc;

#define STREAMS_BOOST_PP_VALUE STREAMS_BOOST_FT_const|STREAMS_BOOST_FT_volatile 
#include STREAMS_BOOST_PP_ASSIGN_SLOT(1)

typedef detail::property_tag<0                , STREAMS_BOOST_PP_SLOT(1)> non_cv;
typedef detail::property_tag<STREAMS_BOOST_FT_const   , STREAMS_BOOST_PP_SLOT(1)> const_non_volatile;
typedef detail::property_tag<STREAMS_BOOST_FT_volatile, STREAMS_BOOST_PP_SLOT(1)> volatile_non_const;
typedef detail::property_tag<STREAMS_BOOST_PP_SLOT(1) , STREAMS_BOOST_PP_SLOT(1)> cv_qualified;

namespace detail {

  typedef constant<STREAMS_BOOST_FT_full_mask> full_mask;

  template <bits_t Flags, bits_t CCID> struct encode_bits_impl
  {
    STREAMS_BOOST_STATIC_CONSTANT( bits_t, value = 
      Flags | (STREAMS_BOOST_FT_default_cc * CCID) << 1 );
  };

  template <bits_t Flags, bits_t CCID, std::size_t Arity> 
  struct encode_charr_impl
  {
    STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = (std::size_t)(1+
      Flags | (STREAMS_BOOST_FT_default_cc * CCID) << 1 | Arity << STREAMS_BOOST_FT_arity_shift
    ));
  };

  template <bits_t Bits> struct decode_bits
  {
    STREAMS_BOOST_STATIC_CONSTANT(bits_t, flags = Bits & STREAMS_BOOST_FT_flags_mask);

    STREAMS_BOOST_STATIC_CONSTANT(bits_t, cc_id = 
      ( (Bits & STREAMS_BOOST_FT_full_mask) / STREAMS_BOOST_FT_default_cc) >> 1 
    );

    STREAMS_BOOST_STATIC_CONSTANT(bits_t, tag_bits = (Bits & STREAMS_BOOST_FT_full_mask));

    STREAMS_BOOST_STATIC_CONSTANT(std::size_t, arity = (std::size_t)
      (Bits >> STREAMS_BOOST_FT_arity_shift) 
    );
  };

  template <bits_t LHS_bits, bits_t LHS_mask, bits_t RHS_bits, bits_t RHS_mask>
  struct tag_ice
  {
    STREAMS_BOOST_STATIC_CONSTANT(bool, match =
      RHS_bits == (LHS_bits & RHS_mask & (RHS_bits |~STREAMS_BOOST_FT_type_mask))
    );

    STREAMS_BOOST_STATIC_CONSTANT(bits_t, combined_bits = 
      (LHS_bits & ~RHS_mask) | RHS_bits
    );

    STREAMS_BOOST_STATIC_CONSTANT(bits_t, combined_mask =
      LHS_mask | RHS_mask
    );

    STREAMS_BOOST_STATIC_CONSTANT(bits_t, extracted_bits =
      LHS_bits & RHS_mask
    );

  };

#define STREAMS_BOOST_FT_mask STREAMS_BOOST_FT_type_mask
  typedef property_tag<STREAMS_BOOST_FT_callable_builtin,STREAMS_BOOST_FT_mask>            callable_builtin_tag;
  typedef property_tag<STREAMS_BOOST_FT_non_member_callable_builtin,STREAMS_BOOST_FT_mask> nonmember_callable_builtin_tag;
  typedef property_tag<STREAMS_BOOST_FT_function,STREAMS_BOOST_FT_mask>       function_tag;
  typedef property_tag<STREAMS_BOOST_FT_reference,STREAMS_BOOST_FT_mask>      reference_tag;
  typedef property_tag<STREAMS_BOOST_FT_pointer,STREAMS_BOOST_FT_mask>        pointer_tag;
  typedef property_tag<STREAMS_BOOST_FT_member_function_pointer,STREAMS_BOOST_FT_mask> member_function_pointer_tag;
  typedef property_tag<STREAMS_BOOST_FT_member_object_pointer,STREAMS_BOOST_FT_mask> member_object_pointer_tag;
  typedef property_tag<STREAMS_BOOST_FT_member_object_pointer_flags,STREAMS_BOOST_FT_full_mask> member_object_pointer_base;
  typedef property_tag<STREAMS_BOOST_FT_member_pointer,STREAMS_BOOST_FT_mask> member_pointer_tag;
#undef  STREAMS_BOOST_FT_mask 

#define STREAMS_BOOST_PP_VALUE STREAMS_BOOST_FT_function|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_default_cc
#include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#define STREAMS_BOOST_PP_VALUE STREAMS_BOOST_FT_type_mask|STREAMS_BOOST_FT_variadic_mask|STREAMS_BOOST_FT_cc_mask
#include STREAMS_BOOST_PP_ASSIGN_SLOT(2)

  typedef property_tag< STREAMS_BOOST_PP_SLOT(1) , STREAMS_BOOST_PP_SLOT(2) > nv_dcc_func;

#define STREAMS_BOOST_PP_VALUE \
    STREAMS_BOOST_FT_member_function_pointer|STREAMS_BOOST_FT_non_variadic|STREAMS_BOOST_FT_default_cc
#include STREAMS_BOOST_PP_ASSIGN_SLOT(1)

  typedef property_tag< STREAMS_BOOST_PP_SLOT(1) , STREAMS_BOOST_PP_SLOT(2) > nv_dcc_mfp;

} // namespace detail

} } // namespace ::streams_boost::function_types

