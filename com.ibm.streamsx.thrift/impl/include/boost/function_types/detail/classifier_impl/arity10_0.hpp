
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

// input:  STREAMS_BOOST_FT_syntax     type macro to use
// input:  STREAMS_BOOST_FT_cc         empty or cc specifier 
// input:  STREAMS_BOOST_FT_ell        empty or "..."
// input:  STREAMS_BOOST_FT_cv         empty or cv qualifiers
// input:  STREAMS_BOOST_FT_flags      single decimal integer encoding the flags
// output: STREAMS_BOOST_FT_n          number of component types (arity+1)
// output: STREAMS_BOOST_FT_arity      current arity
// output: STREAMS_BOOST_FT_type       macro that expands to the type
// output: STREAMS_BOOST_FT_tplargs(p) template arguments with given prefix
// output: STREAMS_BOOST_FT_params(p)  parameters with given prefix

template< typename R >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,0> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (STREAMS_BOOST_FT_nullary_param STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,1> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,2> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,3> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,4> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,5> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,6> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,7> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,8> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,9> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 >
typename encode_charr<STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,10> ::type
classifier_impl(STREAMS_BOOST_FT_syntax(STREAMS_BOOST_FT_cc, STREAMS_BOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 STREAMS_BOOST_FT_ell) STREAMS_BOOST_FT_cv);

