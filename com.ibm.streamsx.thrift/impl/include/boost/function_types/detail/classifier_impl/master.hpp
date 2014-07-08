
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#if STREAMS_BOOST_FT_ARITY_LOOP_PREFIX

#   ifndef STREAMS_BOOST_FT_DETAIL_CLASSIFIER_IMPL_MASTER_HPP_INCLUDED
#   define STREAMS_BOOST_FT_DETAIL_CLASSIFIER_IMPL_MASTER_HPP_INCLUDED
#     include <streams_boost/preprocessor/facilities/identity.hpp>
#   endif

#   define STREAMS_BOOST_FT_type_name

#elif STREAMS_BOOST_FT_ARITY_LOOP_IS_ITERATING

template< STREAMS_BOOST_FT_tplargs(STREAMS_BOOST_PP_IDENTITY(typename)) >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,STREAMS_BOOST_FT_arity>::type
classifier_impl(STREAMS_BOOST_FT_type);

#elif STREAMS_BOOST_FT_ARITY_LOOP_SUFFIX

#   undef STREAMS_BOOST_FT_type_name

#else
#   error "attempt to use arity loop master file without loop"
#endif

