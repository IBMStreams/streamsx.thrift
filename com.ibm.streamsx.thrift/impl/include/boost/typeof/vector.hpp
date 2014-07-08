// Copyright (C) 2005 Arkadiy Vertleyb
// Copyright (C) 2005 Peder Holt
//
// Copyright (C) 2006 Tobias Schwinger
//
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_VECTOR_HPP_INCLUDED

#include <streams_boost/mpl/int.hpp>
#include <streams_boost/preprocessor/iteration/self.hpp>

#ifndef STREAMS_BOOST_TYPEOF_LIMIT_SIZE
#   define STREAMS_BOOST_TYPEOF_LIMIT_SIZE 50
#endif

//
// To recreate the preprocessed versions of this file preprocess and run
//
//   $(STREAMS_BOOST_ROOT)/libs/typeof/tools/preprocess.pl
//

#if defined(STREAMS_BOOST_TYPEOF_PP_INCLUDE_EXTERNAL)

#   undef STREAMS_BOOST_TYPEOF_PP_INCLUDE_EXTERNAL

#elif !defined(STREAMS_BOOST_TYPEOF_PREPROCESSING_MODE) && !STREAMS_BOOST_PP_IS_SELFISH

#   define STREAMS_BOOST_PP_INDIRECT_SELF <streams_boost/typeof/vector.hpp>
#   if   STREAMS_BOOST_TYPEOF_LIMIT_SIZE < 50
#     include STREAMS_BOOST_PP_INCLUDE_SELF()
#   elif STREAMS_BOOST_TYPEOF_LIMIT_SIZE < 100
#     include <streams_boost/typeof/vector50.hpp>
#     define  STREAMS_BOOST_TYPEOF_PP_START_SIZE 51
#     include STREAMS_BOOST_PP_INCLUDE_SELF()
#   elif STREAMS_BOOST_TYPEOF_LIMIT_SIZE < 150
#     include <streams_boost/typeof/vector100.hpp>
#     define  STREAMS_BOOST_TYPEOF_PP_START_SIZE 101
#     include STREAMS_BOOST_PP_INCLUDE_SELF()
#   elif STREAMS_BOOST_TYPEOF_LIMIT_SIZE < 200
#     include <streams_boost/typeof/vector150.hpp>
#     define  STREAMS_BOOST_TYPEOF_PP_START_SIZE 151
#     include STREAMS_BOOST_PP_INCLUDE_SELF()
#   elif STREAMS_BOOST_TYPEOF_LIMIT_SIZE <= 250
#     include <streams_boost/typeof/vector200.hpp>
#     define  STREAMS_BOOST_TYPEOF_PP_START_SIZE 201
#     include STREAMS_BOOST_PP_INCLUDE_SELF()
#   else
#     error "STREAMS_BOOST_TYPEOF_LIMIT_SIZE too high"
#   endif

#else// defined(STREAMS_BOOST_TYPEOF_PREPROCESSING_MODE) || STREAMS_BOOST_PP_IS_SELFISH

#   ifndef STREAMS_BOOST_TYPEOF_PP_NEXT_SIZE
#     define STREAMS_BOOST_TYPEOF_PP_NEXT_SIZE STREAMS_BOOST_TYPEOF_LIMIT_SIZE
#   endif
#   ifndef STREAMS_BOOST_TYPEOF_PP_START_SIZE
#     define STREAMS_BOOST_TYPEOF_PP_START_SIZE 0
#   endif

#   if STREAMS_BOOST_TYPEOF_PP_START_SIZE <= STREAMS_BOOST_TYPEOF_LIMIT_SIZE

#     include <streams_boost/preprocessor/enum_params.hpp>
#     include <streams_boost/preprocessor/repeat.hpp>
#     include <streams_boost/preprocessor/repeat_from_to.hpp>
#     include <streams_boost/preprocessor/cat.hpp>
#     include <streams_boost/preprocessor/inc.hpp>
#     include <streams_boost/preprocessor/dec.hpp>
#     include <streams_boost/preprocessor/comma_if.hpp>
#     include <streams_boost/preprocessor/iteration/local.hpp>
#     include <streams_boost/preprocessor/control/expr_iif.hpp>
#     include <streams_boost/preprocessor/logical/not.hpp>

// iterator

#     define STREAMS_BOOST_TYPEOF_spec_iter(n)\
        template<class V>\
        struct v_iter<V, mpl::int_<n> >\
        {\
            typedef typename V::item ## n type;\
            typedef v_iter<V, mpl::int_<n + 1> > next;\
        };

namespace streams_boost { namespace type_of {

    template<class V, class Increase_STREAMS_BOOST_TYPEOF_LIMIT_SIZE> struct v_iter; // not defined
#     define  STREAMS_BOOST_PP_LOCAL_MACRO  STREAMS_BOOST_TYPEOF_spec_iter
#     define  STREAMS_BOOST_PP_LOCAL_LIMITS \
        (STREAMS_BOOST_PP_DEC(STREAMS_BOOST_TYPEOF_PP_START_SIZE), \
         STREAMS_BOOST_PP_DEC(STREAMS_BOOST_TYPEOF_LIMIT_SIZE))
#     include STREAMS_BOOST_PP_LOCAL_ITERATE()

}}

#     undef STREAMS_BOOST_TYPEOF_spec_iter

// vector

#     define STREAMS_BOOST_TYPEOF_typedef_item(z, n, _)\
        typedef P ## n item ## n;

#     define STREAMS_BOOST_TYPEOF_typedef_fake_item(z, n, _)\
        typedef mpl::int_<1> item ## n;

#     define STREAMS_BOOST_TYPEOF_define_vector(n)\
        template<STREAMS_BOOST_PP_ENUM_PARAMS(n, class P) STREAMS_BOOST_PP_EXPR_IIF(STREAMS_BOOST_PP_NOT(n), class T = void)>\
        struct vector ## n\
        {\
            typedef v_iter<vector ## n<STREAMS_BOOST_PP_ENUM_PARAMS(n,P)>, streams_boost::mpl::int_<0> > begin;\
            STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_TYPEOF_typedef_item, ~)\
            STREAMS_BOOST_PP_REPEAT_FROM_TO(n, STREAMS_BOOST_TYPEOF_PP_NEXT_SIZE, STREAMS_BOOST_TYPEOF_typedef_fake_item, ~)\
        };

namespace streams_boost { namespace type_of {

#     define  STREAMS_BOOST_PP_LOCAL_MACRO  STREAMS_BOOST_TYPEOF_define_vector
#     define  STREAMS_BOOST_PP_LOCAL_LIMITS \
        (STREAMS_BOOST_TYPEOF_PP_START_SIZE,STREAMS_BOOST_TYPEOF_LIMIT_SIZE)
#     include STREAMS_BOOST_PP_LOCAL_ITERATE()

}}

#     undef STREAMS_BOOST_TYPEOF_typedef_item
#     undef STREAMS_BOOST_TYPEOF_typedef_fake_item
#     undef STREAMS_BOOST_TYPEOF_define_vector

// push_back

#     define STREAMS_BOOST_TYPEOF_spec_push_back(n)\
        template<STREAMS_BOOST_PP_ENUM_PARAMS(n, class P) STREAMS_BOOST_PP_COMMA_IF(n) class T>\
        struct push_back<STREAMS_BOOST_PP_CAT(streams_boost::type_of::vector, n)<STREAMS_BOOST_PP_ENUM_PARAMS(n, P)>, T>\
        {\
            typedef STREAMS_BOOST_PP_CAT(streams_boost::type_of::vector, STREAMS_BOOST_PP_INC(n))<\
                STREAMS_BOOST_PP_ENUM_PARAMS(n, P) STREAMS_BOOST_PP_COMMA_IF(n) T\
            > type;\
        };

namespace streams_boost { namespace type_of {

#   if   STREAMS_BOOST_TYPEOF_LIMIT_SIZE < 50
    template<class V, class T> struct push_back {
        typedef V type;
    };
#   endif
    //default behaviour is to let push_back ignore T, and return the input vector.
    //This is to let STREAMS_BOOST_TYPEOF_NESTED_TYPEDEF work properly with the default vector.
#     define  STREAMS_BOOST_PP_LOCAL_MACRO  STREAMS_BOOST_TYPEOF_spec_push_back
#     define  STREAMS_BOOST_PP_LOCAL_LIMITS \
        (STREAMS_BOOST_PP_DEC(STREAMS_BOOST_TYPEOF_PP_START_SIZE), \
         STREAMS_BOOST_PP_DEC(STREAMS_BOOST_TYPEOF_LIMIT_SIZE))
#     include STREAMS_BOOST_PP_LOCAL_ITERATE()

}}

#     undef STREAMS_BOOST_TYPEOF_spec_push_back

#   endif//STREAMS_BOOST_TYPEOF_PP_START_SIZE<=STREAMS_BOOST_TYPEOF_LIMIT_SIZE
#   undef  STREAMS_BOOST_TYPEOF_PP_START_SIZE
#   undef  STREAMS_BOOST_TYPEOF_PP_NEXT_SIZE

#endif//STREAMS_BOOST_TYPEOF_PREPROCESSING_MODE || STREAMS_BOOST_PP_IS_SELFISH

#define STREAMS_BOOST_TYPEOF_VECTOR_HPP_INCLUDED
#endif//STREAMS_BOOST_TYPEOF_VECTOR_HPP_INCLUDED

