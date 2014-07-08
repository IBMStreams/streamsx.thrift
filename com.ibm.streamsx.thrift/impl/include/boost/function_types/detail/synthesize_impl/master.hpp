
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the streams_boost Software License,
// Version 1.0. (See http://www.streams_boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#if   STREAMS_BOOST_FT_ARITY_LOOP_PREFIX

#   ifndef STREAMS_BOOST_FT_DETAIL_SYNTHESIZE_IMPL_MASTER_HPP_INCLUDED
#   define STREAMS_BOOST_FT_DETAIL_SYNTHESIZE_IMPL_MASTER_HPP_INCLUDED
#     include <streams_boost/preprocessor/cat.hpp>
#     include <streams_boost/preprocessor/arithmetic/dec.hpp>
#     include <streams_boost/preprocessor/iteration/local.hpp>
#     include <streams_boost/preprocessor/facilities/empty.hpp>
#     include <streams_boost/preprocessor/facilities/identity.hpp>
#   endif

#   define STREAMS_BOOST_FT_type_name type

#   ifdef STREAMS_BOOST_FT_flags
#     define STREAMS_BOOST_FT_make_type(flags,cc,arity) STREAMS_BOOST_FT_make_type_impl(flags,cc,arity)
#     define STREAMS_BOOST_FT_make_type_impl(flags,cc,arity) make_type_ ## flags ## _ ## cc ## _ ## arity
#   else
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_make_type(flags,cc,arity) STREAMS_BOOST_FT_make_type_impl(flags,cc,arity)
STREAMS_BOOST_PP_EXPAND(#) define STREAMS_BOOST_FT_make_type_impl(flags,cc,arity) make_type_ ## flags ## _ ## cc ## _ ## arity
#   endif

#   define STREAMS_BOOST_FT_iter(i) STREAMS_BOOST_PP_CAT(iter_,i)

#elif STREAMS_BOOST_FT_ARITY_LOOP_IS_ITERATING

template< STREAMS_BOOST_FT_tplargs(STREAMS_BOOST_PP_IDENTITY(typename)) >
struct STREAMS_BOOST_FT_make_type(STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,STREAMS_BOOST_FT_arity)
{
  typedef STREAMS_BOOST_FT_type ;
};

template<> 
struct synthesize_impl_o< STREAMS_BOOST_FT_flags, STREAMS_BOOST_FT_cc_id, STREAMS_BOOST_FT_n > 
{ 
  template<typename S> struct synthesize_impl_i
  {
  private:
    typedef typename mpl::begin<S>::type STREAMS_BOOST_FT_iter(0);
#   if STREAMS_BOOST_FT_n > 1
#     define STREAMS_BOOST_PP_LOCAL_MACRO(i) typedef typename mpl::next< \
          STREAMS_BOOST_FT_iter(STREAMS_BOOST_PP_DEC(i)) >::type STREAMS_BOOST_FT_iter(i);
#     define STREAMS_BOOST_PP_LOCAL_LIMITS (1,STREAMS_BOOST_FT_n-1)
#     include STREAMS_BOOST_PP_LOCAL_ITERATE()
#   endif
  public:
    typedef typename detail::STREAMS_BOOST_FT_make_type(STREAMS_BOOST_FT_flags,STREAMS_BOOST_FT_cc_id,STREAMS_BOOST_FT_arity) 
    < typename mpl::deref< STREAMS_BOOST_FT_iter(0) >::type 
#   if STREAMS_BOOST_FT_mfp
    , typename detail::cv_traits< 
          typename mpl::deref< STREAMS_BOOST_FT_iter(1) >::type >::type
#   endif
#   if STREAMS_BOOST_FT_n > (STREAMS_BOOST_FT_mfp+1)
#     define STREAMS_BOOST_PP_LOCAL_LIMITS (STREAMS_BOOST_FT_mfp+1,STREAMS_BOOST_FT_n-1)
#     define STREAMS_BOOST_PP_LOCAL_MACRO(i) \
        , typename mpl::deref< STREAMS_BOOST_FT_iter(i) >::type
#     include STREAMS_BOOST_PP_LOCAL_ITERATE()
#   endif
    >::type type;
  };
};

#elif STREAMS_BOOST_FT_ARITY_LOOP_SUFFIX

#   ifdef STREAMS_BOOST_FT_flags
#     undef STREAMS_BOOST_FT_make_type
#     undef STREAMS_BOOST_FT_make_type_impl
#   else
STREAMS_BOOST_PP_EXPAND(#) undef STREAMS_BOOST_FT_make_type
STREAMS_BOOST_PP_EXPAND(#) undef STREAMS_BOOST_FT_make_type_impl
#   endif
#   undef STREAMS_BOOST_FT_iter
#   undef STREAMS_BOOST_FT_type_name

#else
#   error "attempt to use arity loop master file without loop"
#endif

