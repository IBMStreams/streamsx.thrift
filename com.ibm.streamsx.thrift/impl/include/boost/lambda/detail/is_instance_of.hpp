// Boost Lambda Library - is_instance_of.hpp ---------------------

// Copyright (C) 2001 Jaakko Jarvi (jaakko.jarvi@cs.utu.fi)
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see www.streams_boost.org

// ---------------------------------------------------------------

#ifndef STREAMS_BOOST_LAMBDA_IS_INSTANCE_OF
#define STREAMS_BOOST_LAMBDA_IS_INSTANCE_OF

#include "streams_boost/config.hpp" // for STREAMS_BOOST_STATIC_CONSTANT
#include "streams_boost/type_traits/conversion_traits.hpp" // for is_convertible
#include "streams_boost/preprocessor/enum_shifted_params.hpp"
#include "streams_boost/preprocessor/repeat_2nd.hpp"

// is_instance_of --------------------------------
// 
// is_instance_of_n<A, B>::value is true, if type A is 
// an instantiation of a template B, or A derives from an instantiation 
// of template B
//
// n is the number of template arguments for B
// 
// Example:
// is_instance_of_2<std::istream, basic_stream>::value == true

// The original implementation was somewhat different, with different versions
// for different compilers. However, there was still a problem
// with gcc.3.0.2 and 3.0.3 compilers, which didn't think regard
// is_instance_of_N<...>::value was a constant.
// John Maddock suggested the way around this problem by building 
// is_instance_of templates using streams_boost::is_convertible.
// Now we only have one version of is_instance_of templates, which delagate
// all the nasty compiler tricks to is_convertible. 

#define STREAMS_BOOST_LAMBDA_CLASS(z, N,A) STREAMS_BOOST_PP_COMMA_IF(N) class
#define STREAMS_BOOST_LAMBDA_CLASS_ARG(z, N,A) STREAMS_BOOST_PP_COMMA_IF(N) class A##N 
#define STREAMS_BOOST_LAMBDA_ARG(z, N,A) STREAMS_BOOST_PP_COMMA_IF(N) A##N 

#define STREAMS_BOOST_LAMBDA_CLASS_LIST(n, NAME) STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_LAMBDA_CLASS, NAME)

#define STREAMS_BOOST_LAMBDA_CLASS_ARG_LIST(n, NAME) STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_LAMBDA_CLASS_ARG, NAME)

#define STREAMS_BOOST_LAMBDA_ARG_LIST(n, NAME) STREAMS_BOOST_PP_REPEAT(n, STREAMS_BOOST_LAMBDA_ARG, NAME)

namespace streams_boost {
namespace lambda {

#define STREAMS_BOOST_LAMBDA_IS_INSTANCE_OF_TEMPLATE(INDEX)                         \
                                                                            \
namespace detail {                                                          \
                                                                            \
template <template<STREAMS_BOOST_LAMBDA_CLASS_LIST(INDEX,T)> class F>               \
struct STREAMS_BOOST_PP_CAT(conversion_tester_,INDEX) {                             \
  template<STREAMS_BOOST_LAMBDA_CLASS_ARG_LIST(INDEX,A)>                            \
  STREAMS_BOOST_PP_CAT(conversion_tester_,INDEX)                                    \
    (const F<STREAMS_BOOST_LAMBDA_ARG_LIST(INDEX,A)>&);                             \
};                                                                          \
                                                                            \
} /* end detail */                                                          \
                                                                            \
template <class From, template <STREAMS_BOOST_LAMBDA_CLASS_LIST(INDEX,T)> class To> \
struct STREAMS_BOOST_PP_CAT(is_instance_of_,INDEX)                                  \
{                                                                           \
 private:                                                                   \
   typedef ::streams_boost::is_convertible<                                         \
     From,                                                                  \
     STREAMS_BOOST_PP_CAT(detail::conversion_tester_,INDEX)<To>                     \
   > helper_type;                                                           \
                                                                            \
public:                                                                     \
  STREAMS_BOOST_STATIC_CONSTANT(bool, value = helper_type::value);                  \
};


#define STREAMS_BOOST_LAMBDA_HELPER(z, N, A) STREAMS_BOOST_LAMBDA_IS_INSTANCE_OF_TEMPLATE( STREAMS_BOOST_PP_INC(N) )

// Generate the traits for 1-4 argument templates

STREAMS_BOOST_PP_REPEAT_2ND(4,STREAMS_BOOST_LAMBDA_HELPER,FOO)

#undef STREAMS_BOOST_LAMBDA_HELPER
#undef STREAMS_BOOST_LAMBDA_IS_INSTANCE_OF_TEMPLATE
#undef STREAMS_BOOST_LAMBDA_CLASS
#undef STREAMS_BOOST_LAMBDA_ARG
#undef STREAMS_BOOST_LAMBDA_CLASS_ARG
#undef STREAMS_BOOST_LAMBDA_CLASS_LIST
#undef STREAMS_BOOST_LAMBDA_ARG_LIST
#undef STREAMS_BOOST_LAMBDA_CLASS_ARG_LIST

} // lambda
} // streams_boost

#endif





