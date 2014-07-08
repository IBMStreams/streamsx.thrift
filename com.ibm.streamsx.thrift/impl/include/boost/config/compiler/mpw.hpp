//  (C) Copyright John Maddock 2001 - 2002. 
//  (C) Copyright Aleksey Gurtovoy 2002. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  MPW C++ compilers setup:

#   if    defined(__SC__)
#     define STREAMS_BOOST_COMPILER "MPW SCpp version " STREAMS_BOOST_STRINGIZE(__SC__)
#   elif defined(__MRC__)
#     define STREAMS_BOOST_COMPILER "MPW MrCpp version " STREAMS_BOOST_STRINGIZE(__MRC__)
#   else
#     error "Using MPW compiler configuration by mistake.  Please update."
#   endif

//
// MPW 8.90:
//
#if (MPW_CPLUS <= 0x890) || !defined(STREAMS_BOOST_STRICT_CONFIG)
#  define STREAMS_BOOST_NO_CV_SPECIALIZATIONS
#  define STREAMS_BOOST_NO_DEPENDENT_NESTED_DERIVATIONS
#  define STREAMS_BOOST_NO_DEPENDENT_TYPES_IN_TEMPLATE_VALUE_PARAMETERS
#  define STREAMS_BOOST_NO_INCLASS_MEMBER_INITIALIZATION
#  define STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
#  define STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#  define STREAMS_BOOST_NO_USING_TEMPLATE

#  define STREAMS_BOOST_NO_CWCHAR
#  define STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS

#  define STREAMS_BOOST_NO_STD_ALLOCATOR /* actually a bug with const reference overloading */

#endif

//
// C++0x features
//
//   See streams_boost\config\suffix.hpp for STREAMS_BOOST_NO_LONG_LONG
//
#define STREAMS_BOOST_NO_AUTO_DECLARATIONS
#define STREAMS_BOOST_NO_AUTO_MULTIDECLARATIONS
#define STREAMS_BOOST_NO_CHAR16_T
#define STREAMS_BOOST_NO_CHAR32_T
#define STREAMS_BOOST_NO_CONCEPTS
#define STREAMS_BOOST_NO_CONSTEXPR
#define STREAMS_BOOST_NO_DECLTYPE
#define STREAMS_BOOST_NO_DEFAULTED_FUNCTIONS
#define STREAMS_BOOST_NO_DELETED_FUNCTIONS
#define STREAMS_BOOST_NO_EXPLICIT_CONVERSION_OPERATORS
#define STREAMS_BOOST_NO_EXTERN_TEMPLATE
#define STREAMS_BOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define STREAMS_BOOST_NO_INITIALIZER_LISTS
#define STREAMS_BOOST_NO_LAMBDAS
#define STREAMS_BOOST_NO_NULLPTR
#define STREAMS_BOOST_NO_RAW_LITERALS
#define STREAMS_BOOST_NO_RVALUE_REFERENCES
#define STREAMS_BOOST_NO_SCOPED_ENUMS
#define STREAMS_BOOST_NO_SFINAE_EXPR
#define STREAMS_BOOST_NO_STATIC_ASSERT
#define STREAMS_BOOST_NO_TEMPLATE_ALIASES
#define STREAMS_BOOST_NO_UNICODE_LITERALS
#define STREAMS_BOOST_NO_VARIADIC_TEMPLATES

//
// versions check:
// we don't support MPW prior to version 8.9:
#if MPW_CPLUS < 0x890
#  error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version is 0x890:
#if (MPW_CPLUS > 0x890)
#  if defined(STREAMS_BOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  endif
#endif


