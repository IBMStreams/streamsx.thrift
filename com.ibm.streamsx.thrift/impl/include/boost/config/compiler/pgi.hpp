//  (C) Copyright Noel Belcourt 2007.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for most recent version.

//  PGI C++ compiler setup:

#define STREAMS_BOOST_COMPILER_VERSION __PGIC__##__PGIC_MINOR__
#define STREAMS_BOOST_COMPILER "PGI compiler version " STREAMS_BOOST_STRINGIZE(_COMPILER_VERSION)

//
// Threading support:
// Turn this on unconditionally here, it will get turned off again later
// if no threading API is detected.
//

#if (__PGIC__ >= 7)

#define STREAMS_BOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL 
#define STREAMS_BOOST_NO_TWO_PHASE_NAME_LOOKUP
#define STREAMS_BOOST_NO_SWPRINTF

#else

#  error "Pgi compiler not configured - please reconfigure"

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
// version check:
// probably nothing to do here?

