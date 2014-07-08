
//  (C) Copyright John maddock 1999. 
//  (C) David Abrahams 2002.  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
//
// use this header as a workaround for missing <limits>

//  See http://www.streams_boost.org/libs/compatibility/index.html for documentation.

#ifndef STREAMS_BOOST_LIMITS
#define STREAMS_BOOST_LIMITS

#include <streams_boost/config.hpp>

#ifdef STREAMS_BOOST_NO_LIMITS
# include <streams_boost/detail/limits.hpp>
#else
# include <limits>
#endif

#if (defined(STREAMS_BOOST_HAS_LONG_LONG) && defined(STREAMS_BOOST_NO_LONG_LONG_NUMERIC_LIMITS)) \
      || (defined(STREAMS_BOOST_HAS_MS_INT64) && defined(STREAMS_BOOST_NO_MS_INT64_NUMERIC_LIMITS))
// Add missing specializations for numeric_limits:
#ifdef STREAMS_BOOST_HAS_MS_INT64
#  define STREAMS_BOOST_LLT __int64
#  define STREAMS_BOOST_ULLT unsigned __int64
#else
#  define STREAMS_BOOST_LLT  ::streams_boost::long_long_type
#  define STREAMS_BOOST_ULLT  ::streams_boost::ulong_long_type
#endif

#include <climits>  // for CHAR_BIT

namespace std
{
  template<>
  class numeric_limits<STREAMS_BOOST_LLT> 
  {
   public:

      STREAMS_BOOST_STATIC_CONSTANT(bool, is_specialized = true);
#ifdef STREAMS_BOOST_HAS_MS_INT64
      static STREAMS_BOOST_LLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0x8000000000000000i64; }
      static STREAMS_BOOST_LLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0x7FFFFFFFFFFFFFFFi64; }
#elif defined(LLONG_MAX)
      static STREAMS_BOOST_LLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return LLONG_MIN; }
      static STREAMS_BOOST_LLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return LLONG_MAX; }
#elif defined(LONGLONG_MAX)
      static STREAMS_BOOST_LLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return LONGLONG_MIN; }
      static STREAMS_BOOST_LLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return LONGLONG_MAX; }
#else
      static STREAMS_BOOST_LLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return 1LL << (sizeof(STREAMS_BOOST_LLT) * CHAR_BIT - 1); }
      static STREAMS_BOOST_LLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return ~(min)(); }
#endif
      STREAMS_BOOST_STATIC_CONSTANT(int, digits = sizeof(STREAMS_BOOST_LLT) * CHAR_BIT -1);
      STREAMS_BOOST_STATIC_CONSTANT(int, digits10 = (CHAR_BIT * sizeof (STREAMS_BOOST_LLT) - 1) * 301L / 1000);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_signed = true);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_integer = true);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_exact = true);
      STREAMS_BOOST_STATIC_CONSTANT(int, radix = 2);
      static STREAMS_BOOST_LLT epsilon() throw() { return 0; };
      static STREAMS_BOOST_LLT round_error() throw() { return 0; };

      STREAMS_BOOST_STATIC_CONSTANT(int, min_exponent = 0);
      STREAMS_BOOST_STATIC_CONSTANT(int, min_exponent10 = 0);
      STREAMS_BOOST_STATIC_CONSTANT(int, max_exponent = 0);
      STREAMS_BOOST_STATIC_CONSTANT(int, max_exponent10 = 0);

      STREAMS_BOOST_STATIC_CONSTANT(bool, has_infinity = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_quiet_NaN = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_signaling_NaN = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_denorm = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_denorm_loss = false);
      static STREAMS_BOOST_LLT infinity() throw() { return 0; };
      static STREAMS_BOOST_LLT quiet_NaN() throw() { return 0; };
      static STREAMS_BOOST_LLT signaling_NaN() throw() { return 0; };
      static STREAMS_BOOST_LLT denorm_min() throw() { return 0; };

      STREAMS_BOOST_STATIC_CONSTANT(bool, is_iec559 = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_bounded = true);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_modulo = true);

      STREAMS_BOOST_STATIC_CONSTANT(bool, traps = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, tinyness_before = false);
      STREAMS_BOOST_STATIC_CONSTANT(float_round_style, round_style = round_toward_zero);
      
  };

  template<>
  class numeric_limits<STREAMS_BOOST_ULLT> 
  {
   public:

      STREAMS_BOOST_STATIC_CONSTANT(bool, is_specialized = true);
#ifdef STREAMS_BOOST_HAS_MS_INT64
      static STREAMS_BOOST_ULLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0ui64; }
      static STREAMS_BOOST_ULLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0xFFFFFFFFFFFFFFFFui64; }
#elif defined(ULLONG_MAX) && defined(ULLONG_MIN)
      static STREAMS_BOOST_ULLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULLONG_MIN; }
      static STREAMS_BOOST_ULLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULLONG_MAX; }
#elif defined(ULONGLONG_MAX) && defined(ULONGLONG_MIN)
      static STREAMS_BOOST_ULLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULONGLONG_MIN; }
      static STREAMS_BOOST_ULLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULONGLONG_MAX; }
#else
      static STREAMS_BOOST_ULLT min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0uLL; }
      static STREAMS_BOOST_ULLT max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (){ return ~0uLL; }
#endif
      STREAMS_BOOST_STATIC_CONSTANT(int, digits = sizeof(STREAMS_BOOST_LLT) * CHAR_BIT);
      STREAMS_BOOST_STATIC_CONSTANT(int, digits10 = (CHAR_BIT * sizeof (STREAMS_BOOST_LLT)) * 301L / 1000);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_signed = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_integer = true);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_exact = true);
      STREAMS_BOOST_STATIC_CONSTANT(int, radix = 2);
      static STREAMS_BOOST_ULLT epsilon() throw() { return 0; };
      static STREAMS_BOOST_ULLT round_error() throw() { return 0; };

      STREAMS_BOOST_STATIC_CONSTANT(int, min_exponent = 0);
      STREAMS_BOOST_STATIC_CONSTANT(int, min_exponent10 = 0);
      STREAMS_BOOST_STATIC_CONSTANT(int, max_exponent = 0);
      STREAMS_BOOST_STATIC_CONSTANT(int, max_exponent10 = 0);

      STREAMS_BOOST_STATIC_CONSTANT(bool, has_infinity = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_quiet_NaN = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_signaling_NaN = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_denorm = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, has_denorm_loss = false);
      static STREAMS_BOOST_ULLT infinity() throw() { return 0; };
      static STREAMS_BOOST_ULLT quiet_NaN() throw() { return 0; };
      static STREAMS_BOOST_ULLT signaling_NaN() throw() { return 0; };
      static STREAMS_BOOST_ULLT denorm_min() throw() { return 0; };

      STREAMS_BOOST_STATIC_CONSTANT(bool, is_iec559 = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_bounded = true);
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_modulo = true);

      STREAMS_BOOST_STATIC_CONSTANT(bool, traps = false);
      STREAMS_BOOST_STATIC_CONSTANT(bool, tinyness_before = false);
      STREAMS_BOOST_STATIC_CONSTANT(float_round_style, round_style = round_toward_zero);
      
  };
}
#endif 

#endif

