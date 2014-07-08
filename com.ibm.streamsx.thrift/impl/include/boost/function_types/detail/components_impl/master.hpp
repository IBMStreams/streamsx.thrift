
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#if   STREAMS_BOOST_FT_ARITY_LOOP_PREFIX

#   ifndef STREAMS_BOOST_FT_DETAIL_COMPONENTS_IMPL_MASTER_HPP_INCLUDED
#   define STREAMS_BOOST_FT_DETAIL_COMPONENTS_IMPL_MASTER_HPP_INCLUDED
#     include <streams_boost/preprocessor/cat.hpp>
#     include <streams_boost/preprocessor/facilities/empty.hpp>
#     include <streams_boost/preprocessor/facilities/identity.hpp>
#     include <streams_boost/preprocessor/arithmetic/dec.hpp>
#     include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#   endif

#   define STREAMS_BOOST_FT_type_name

#   if !STREAMS_BOOST_FT_mfp

#     define STREAMS_BOOST_FT_types \
          R STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_FT_arity) STREAMS_BOOST_FT_params(STREAMS_BOOST_PP_EMPTY)
#   else

#     define STREAMS_BOOST_FT_types \
          R, typename class_transform<T0 STREAMS_BOOST_FT_cv, L>::type \
          STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(STREAMS_BOOST_FT_arity)) \
          STREAMS_BOOST_FT_params(STREAMS_BOOST_PP_EMPTY)

#   endif

#elif STREAMS_BOOST_FT_ARITY_LOOP_IS_ITERATING

template< STREAMS_BOOST_FT_tplargs(STREAMS_BOOST_PP_IDENTITY(typename)), typename L>
struct components_impl<STREAMS_BOOST_FT_type, L>
{
  typedef encode_bits<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id> bits;
  typedef constant<STREAMS_BOOST_FT_full_mask> mask;

  typedef function_types::components<STREAMS_BOOST_FT_type, L> type;
  typedef components_mpl_sequence_tag tag;

  typedef mpl::integral_c<std::size_t,STREAMS_BOOST_FT_arity> function_arity;

  typedef STREAMS_BOOST_PP_CAT(mpl::vector,STREAMS_BOOST_FT_n)< STREAMS_BOOST_FT_types > types;
};

#elif STREAMS_BOOST_FT_ARITY_LOOP_SUFFIX

#   undef STREAMS_BOOST_FT_types
#   undef STREAMS_BOOST_FT_type_name

#else
#   error "attempt to use arity loop master file without loop"
#endif

