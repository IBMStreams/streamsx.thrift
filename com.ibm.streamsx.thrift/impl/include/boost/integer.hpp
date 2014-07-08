//  streams_boost integer.hpp header file  -------------------------------------------//

//  Copyright Beman Dawes and Daryle Walker 1999.  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/integer for documentation.

//  Revision History
//   22 Sep 01  Added value-based integer templates. (Daryle Walker)
//   01 Apr 01  Modified to use new <streams_boost/limits.hpp> header. (John Maddock)
//   30 Jul 00  Add typename syntax fix (Jens Maurer)
//   28 Aug 99  Initial version

#ifndef STREAMS_BOOST_INTEGER_HPP
#define STREAMS_BOOST_INTEGER_HPP

#include <streams_boost/integer_fwd.hpp>  // self include

#include <streams_boost/integer_traits.hpp>  // for streams_boost::::streams_boost::integer_traits
#include <streams_boost/limits.hpp>          // for ::std::numeric_limits
#include <streams_boost/cstdint.hpp>         // for streams_boost::int64_t and STREAMS_BOOST_NO_INTEGRAL_INT64_T

//
// We simply cannot include this header on gcc without getting copious warnings of the kind:
//
// streams_boost/integer.hpp:77:30: warning: use of C99 long long integer constant
//
// And yet there is no other reasonable implementation, so we declare this a system header
// to suppress these warnings.
//
#if defined(__GNUC__) && (__GNUC__ >= 4)
#pragma GCC system_header
#endif

namespace streams_boost
{

  //  Helper templates  ------------------------------------------------------//

  //  fast integers from least integers
  //  int_fast_t<> works correctly for unsigned too, in spite of the name.
  template< typename LeastInt >
  struct int_fast_t 
  { 
     typedef LeastInt fast; 
     typedef fast     type;
  }; // imps may specialize

  namespace detail{

  //  convert category to type 
  template< int Category > struct int_least_helper {}; // default is empty

  //  specializatons: 1=long, 2=int, 3=short, 4=signed char,
  //     6=unsigned long, 7=unsigned int, 8=unsigned short, 9=unsigned char
  //  no specializations for 0 and 5: requests for a type > long are in error
#ifdef STREAMS_BOOST_HAS_LONG_LONG
  template<> struct int_least_helper<1> { typedef streams_boost::long_long_type least; };
#endif
  template<> struct int_least_helper<2> { typedef long least; };
  template<> struct int_least_helper<3> { typedef int least; };
  template<> struct int_least_helper<4> { typedef short least; };
  template<> struct int_least_helper<5> { typedef signed char least; };
#ifdef STREAMS_BOOST_HAS_LONG_LONG
  template<> struct int_least_helper<6> { typedef streams_boost::ulong_long_type least; };
#endif
  template<> struct int_least_helper<7> { typedef unsigned long least; };
  template<> struct int_least_helper<8> { typedef unsigned int least; };
  template<> struct int_least_helper<9> { typedef unsigned short least; };
  template<> struct int_least_helper<10> { typedef unsigned char least; };

  template <int Bits>
  struct exact_signed_base_helper{};
  template <int Bits>
  struct exact_unsigned_base_helper{};

  template <> struct exact_signed_base_helper<sizeof(signed char)* CHAR_BIT> { typedef signed char exact; };
  template <> struct exact_unsigned_base_helper<sizeof(unsigned char)* CHAR_BIT> { typedef unsigned char exact; };
#if USHRT_MAX != UCHAR_MAX
  template <> struct exact_signed_base_helper<sizeof(short)* CHAR_BIT> { typedef short exact; };
  template <> struct exact_unsigned_base_helper<sizeof(unsigned short)* CHAR_BIT> { typedef unsigned short exact; };
#endif
#if UINT_MAX != USHRT_MAX
  template <> struct exact_signed_base_helper<sizeof(int)* CHAR_BIT> { typedef int exact; };
  template <> struct exact_unsigned_base_helper<sizeof(unsigned int)* CHAR_BIT> { typedef unsigned int exact; };
#endif
#if ULONG_MAX != UINT_MAX
  template <> struct exact_signed_base_helper<sizeof(long)* CHAR_BIT> { typedef long exact; };
  template <> struct exact_unsigned_base_helper<sizeof(unsigned long)* CHAR_BIT> { typedef unsigned long exact; };
#endif
#if defined(STREAMS_BOOST_HAS_LONG_LONG) &&\
   ((defined(ULLONG_MAX) && (ULLONG_MAX != ULONG_MAX)) ||\
    (defined(ULONG_LONG_MAX) && (ULONG_LONG_MAX != ULONG_MAX)) ||\
    (defined(ULONGLONG_MAX) && (ULONGLONG_MAX != ULONG_MAX)) ||\
    (defined(_ULLONG_MAX) && (_ULLONG_MAX != ULONG_MAX)))
  template <> struct exact_signed_base_helper<sizeof(streams_boost::long_long_type)* CHAR_BIT> { typedef streams_boost::long_long_type exact; };
  template <> struct exact_unsigned_base_helper<sizeof(streams_boost::ulong_long_type)* CHAR_BIT> { typedef streams_boost::ulong_long_type exact; };
#endif


  } // namespace detail

  //  integer templates specifying number of bits  ---------------------------//

  //  signed
  template< int Bits >   // bits (including sign) required
  struct int_t : public detail::exact_signed_base_helper<Bits>
  {
      typedef typename detail::int_least_helper
        <
#ifdef STREAMS_BOOST_HAS_LONG_LONG
          (Bits-1 <= (int)(sizeof(streams_boost::long_long_type) * CHAR_BIT)) +
#else
           1 +
#endif
          (Bits-1 <= ::std::numeric_limits<long>::digits) +
          (Bits-1 <= ::std::numeric_limits<int>::digits) +
          (Bits-1 <= ::std::numeric_limits<short>::digits) +
          (Bits-1 <= ::std::numeric_limits<signed char>::digits)
        >::least  least;
      typedef typename int_fast_t<least>::type  fast;
  };

  //  unsigned
  template< int Bits >   // bits required
  struct uint_t : public detail::exact_unsigned_base_helper<Bits>
  {
#if (defined(__BORLANDC__) || defined(__CODEGEAR__)) && defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T)
     // It's really not clear why this workaround should be needed... shrug I guess!  JM
     STREAMS_BOOST_STATIC_CONSTANT(int, s = 
           6 +
          (Bits <= ::std::numeric_limits<unsigned long>::digits) +
          (Bits <= ::std::numeric_limits<unsigned int>::digits) +
          (Bits <= ::std::numeric_limits<unsigned short>::digits) +
          (Bits <= ::std::numeric_limits<unsigned char>::digits));
     typedef typename detail::int_least_helper< ::streams_boost::uint_t<Bits>::s>::least least;
#else
      typedef typename detail::int_least_helper
        < 
          5 +
#ifdef STREAMS_BOOST_HAS_LONG_LONG
          (Bits-1 <= (int)(sizeof(streams_boost::long_long_type) * CHAR_BIT)) +
#else
           1 +
#endif
          (Bits <= ::std::numeric_limits<unsigned long>::digits) +
          (Bits <= ::std::numeric_limits<unsigned int>::digits) +
          (Bits <= ::std::numeric_limits<unsigned short>::digits) +
          (Bits <= ::std::numeric_limits<unsigned char>::digits)
        >::least  least;
#endif
      typedef typename int_fast_t<least>::type  fast;
      // int_fast_t<> works correctly for unsigned too, in spite of the name.
  };

  //  integer templates specifying extreme value  ----------------------------//

  //  signed
#if !defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T) && defined(STREAMS_BOOST_HAS_LONG_LONG)
  template< streams_boost::long_long_type MaxValue >   // maximum value to require support
#else
  template< long MaxValue >   // maximum value to require support
#endif
  struct int_max_value_t 
  {
      typedef typename detail::int_least_helper
        <
#if !defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T) && defined(STREAMS_BOOST_HAS_LONG_LONG)
          (MaxValue <= ::streams_boost::integer_traits<streams_boost::long_long_type>::const_max) +
#else
           1 +
#endif
          (MaxValue <= ::streams_boost::integer_traits<long>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<int>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<short>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<signed char>::const_max)
        >::least  least;
      typedef typename int_fast_t<least>::type  fast;
  };

#if !defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T) && defined(STREAMS_BOOST_HAS_LONG_LONG)
  template< streams_boost::long_long_type MinValue >   // minimum value to require support
#else
  template< long MinValue >   // minimum value to require support
#endif
  struct int_min_value_t 
  {
      typedef typename detail::int_least_helper
        <
#if !defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T) && defined(STREAMS_BOOST_HAS_LONG_LONG)
          (MinValue >= ::streams_boost::integer_traits<streams_boost::long_long_type>::const_min) +
#else
           1 +
#endif
          (MinValue >= ::streams_boost::integer_traits<long>::const_min) +
          (MinValue >= ::streams_boost::integer_traits<int>::const_min) +
          (MinValue >= ::streams_boost::integer_traits<short>::const_min) +
          (MinValue >= ::streams_boost::integer_traits<signed char>::const_min)
        >::least  least;
      typedef typename int_fast_t<least>::type  fast;
  };

  //  unsigned
#if !defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T) && defined(STREAMS_BOOST_HAS_LONG_LONG)
  template< streams_boost::ulong_long_type MaxValue >   // minimum value to require support
#else
  template< unsigned long MaxValue >   // minimum value to require support
#endif
  struct uint_value_t 
  {
#if (defined(__BORLANDC__) || defined(__CODEGEAR__))
     // It's really not clear why this workaround should be needed... shrug I guess!  JM
#if defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T)
      STREAMS_BOOST_STATIC_CONSTANT(unsigned, which = 
           6 +
          (MaxValue <= ::streams_boost::integer_traits<unsigned long>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned int>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned short>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned char>::const_max));
      typedef typename detail::int_least_helper< ::streams_boost::uint_value_t<MaxValue>::which>::least least;
#else // STREAMS_BOOST_NO_INTEGRAL_INT64_T
      STREAMS_BOOST_STATIC_CONSTANT(unsigned, which = 
           5 +
          (MaxValue <= ::streams_boost::integer_traits<streams_boost::ulong_long_type>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned long>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned int>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned short>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned char>::const_max));
      typedef typename detail::int_least_helper< ::streams_boost::uint_value_t<MaxValue>::which>::least least;
#endif // STREAMS_BOOST_NO_INTEGRAL_INT64_T
#else
      typedef typename detail::int_least_helper
        < 
          5 +
#if !defined(STREAMS_BOOST_NO_INTEGRAL_INT64_T) && defined(STREAMS_BOOST_HAS_LONG_LONG)
          (MaxValue <= ::streams_boost::integer_traits<streams_boost::ulong_long_type>::const_max) +
#else
           1 +
#endif
          (MaxValue <= ::streams_boost::integer_traits<unsigned long>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned int>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned short>::const_max) +
          (MaxValue <= ::streams_boost::integer_traits<unsigned char>::const_max)
        >::least  least;
#endif
      typedef typename int_fast_t<least>::type  fast;
  };


} // namespace streams_boost

#endif  // STREAMS_BOOST_INTEGER_HPP
