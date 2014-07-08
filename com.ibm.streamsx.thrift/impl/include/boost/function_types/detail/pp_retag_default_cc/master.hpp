
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

#if !defined(STREAMS_BOOST_PP_VALUE)
#   include <streams_boost/preprocessor/slot/slot.hpp>
#   include <streams_boost/preprocessor/iteration/self.hpp>

#   include <streams_boost/function_types/detail/encoding/def.hpp>
#   include <streams_boost/function_types/detail/encoding/aliases_def.hpp>

namespace streams_boost { namespace function_types {

namespace detail
{
  template<class Tag, class RefTag> struct selector_bits
  {
#   define  STREAMS_BOOST_PP_VALUE non_member|member|non_variadic|variadic
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)

    STREAMS_BOOST_STATIC_CONSTANT(bits_t, value = (
        (::streams_boost::function_types::detail::bits<Tag>::value & STREAMS_BOOST_FT_default_cc) 
      | (::streams_boost::function_types::detail::bits<RefTag>::value & STREAMS_BOOST_PP_SLOT(1))
    ));
  };

  template<bits_t SelectorBits> struct default_cc_tag; 
  
  template<class Tag, class RefTag> struct retag_default_cc
    : detail::compound_tag
      < Tag, detail::default_cc_tag< 
          ::streams_boost::function_types::detail::selector_bits<Tag,RefTag>::value > >
  { };

  template<bits_t SelectorBits> struct default_cc_tag
  {
    typedef null_tag::bits bits;
    typedef null_tag::mask mask;
  };

  class test_class;
  typedef constant<STREAMS_BOOST_FT_cc_mask> cc_mask_constant;

#   define STREAMS_BOOST_FT_self \
      <streams_boost/function_types/detail/pp_retag_default_cc/master.hpp>

#   define  default_cc_ STREAMS_BOOST_FT_default_cc

#   define  STREAMS_BOOST_PP_VALUE default_cc_|non_member|non_variadic
#   define  STREAMS_BOOST_FT_tester void (*tester)()
#   define  STREAMS_BOOST_PP_INDIRECT_SELF STREAMS_BOOST_FT_self
#   include STREAMS_BOOST_PP_INCLUDE_SELF()

#   define  STREAMS_BOOST_PP_VALUE default_cc_|non_member|variadic
#   define  STREAMS_BOOST_FT_tester void (*tester)(...)
#   define  STREAMS_BOOST_PP_INDIRECT_SELF STREAMS_BOOST_FT_self
#   include STREAMS_BOOST_PP_INCLUDE_SELF()

#   define  STREAMS_BOOST_PP_VALUE default_cc_|member|non_variadic
#   define  STREAMS_BOOST_FT_tester void (test_class::*tester)()
#   define  STREAMS_BOOST_PP_INDIRECT_SELF STREAMS_BOOST_FT_self
#   include STREAMS_BOOST_PP_INCLUDE_SELF()

#   define  STREAMS_BOOST_PP_VALUE default_cc_|member|variadic
#   define  STREAMS_BOOST_FT_tester void (test_class::*tester)(...)
#   define  STREAMS_BOOST_PP_INDIRECT_SELF STREAMS_BOOST_FT_self
#   include STREAMS_BOOST_PP_INCLUDE_SELF()

#   undef   default_cc_

#   undef STREAMS_BOOST_FT_self

} } } // namespace ::streams_boost::function_types::detail

#   include <streams_boost/function_types/detail/encoding/aliases_undef.hpp>
#   include <streams_boost/function_types/detail/encoding/undef.hpp>

#else // if defined(STREAMS_BOOST_PP_VALUE)

#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)

  template<> struct default_cc_tag<STREAMS_BOOST_PP_SLOT(1)> 
  {
    typedef STREAMS_BOOST_FT_tester;
    typedef mpl::bitand_<components<tester>::bits,cc_mask_constant> bits;
    typedef cc_mask_constant mask;
  };

#   undef STREAMS_BOOST_FT_tester

#endif

