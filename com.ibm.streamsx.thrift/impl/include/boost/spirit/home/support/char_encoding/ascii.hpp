/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_ASCII_APRIL_26_2006_1106PM)
#define STREAMS_BOOST_SPIRIT_ASCII_APRIL_26_2006_1106PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <climits>
#include <streams_boost/assert.hpp>
#include <streams_boost/cstdint.hpp>

///////////////////////////////////////////////////////////////////////////////
// constants used to classify the single characters
///////////////////////////////////////////////////////////////////////////////
#define STREAMS_BOOST_CC_DIGIT    0x0001
#define STREAMS_BOOST_CC_XDIGIT   0x0002
#define STREAMS_BOOST_CC_ALPHA    0x0004
#define STREAMS_BOOST_CC_CTRL     0x0008
#define STREAMS_BOOST_CC_LOWER    0x0010
#define STREAMS_BOOST_CC_UPPER    0x0020
#define STREAMS_BOOST_CC_SPACE    0x0040
#define STREAMS_BOOST_CC_PUNCT    0x0080

namespace streams_boost { namespace spirit { namespace char_encoding
{
    // The detection of isgraph(), isprint() and isblank() is done programmatically
    // to keep the character type table small. Additionally, these functions are
    // rather seldom used and the programmatic detection is very simple.

    ///////////////////////////////////////////////////////////////////////////
    // ASCII character classification table
    ///////////////////////////////////////////////////////////////////////////
    const unsigned char ascii_char_types[] =
    {
        /* NUL   0   0 */   STREAMS_BOOST_CC_CTRL,
        /* SOH   1   1 */   STREAMS_BOOST_CC_CTRL,
        /* STX   2   2 */   STREAMS_BOOST_CC_CTRL,
        /* ETX   3   3 */   STREAMS_BOOST_CC_CTRL,
        /* EOT   4   4 */   STREAMS_BOOST_CC_CTRL,
        /* ENQ   5   5 */   STREAMS_BOOST_CC_CTRL,
        /* ACK   6   6 */   STREAMS_BOOST_CC_CTRL,
        /* BEL   7   7 */   STREAMS_BOOST_CC_CTRL,
        /* BS    8   8 */   STREAMS_BOOST_CC_CTRL,
        /* HT    9   9 */   STREAMS_BOOST_CC_CTRL|STREAMS_BOOST_CC_SPACE,
        /* NL   10   a */   STREAMS_BOOST_CC_CTRL|STREAMS_BOOST_CC_SPACE,
        /* VT   11   b */   STREAMS_BOOST_CC_CTRL|STREAMS_BOOST_CC_SPACE,
        /* NP   12   c */   STREAMS_BOOST_CC_CTRL|STREAMS_BOOST_CC_SPACE,
        /* CR   13   d */   STREAMS_BOOST_CC_CTRL|STREAMS_BOOST_CC_SPACE,
        /* SO   14   e */   STREAMS_BOOST_CC_CTRL,
        /* SI   15   f */   STREAMS_BOOST_CC_CTRL,
        /* DLE  16  10 */   STREAMS_BOOST_CC_CTRL,
        /* DC1  17  11 */   STREAMS_BOOST_CC_CTRL,
        /* DC2  18  12 */   STREAMS_BOOST_CC_CTRL,
        /* DC3  19  13 */   STREAMS_BOOST_CC_CTRL,
        /* DC4  20  14 */   STREAMS_BOOST_CC_CTRL,
        /* NAK  21  15 */   STREAMS_BOOST_CC_CTRL,
        /* SYN  22  16 */   STREAMS_BOOST_CC_CTRL,
        /* ETB  23  17 */   STREAMS_BOOST_CC_CTRL,
        /* CAN  24  18 */   STREAMS_BOOST_CC_CTRL,
        /* EM   25  19 */   STREAMS_BOOST_CC_CTRL,
        /* SUB  26  1a */   STREAMS_BOOST_CC_CTRL,
        /* ESC  27  1b */   STREAMS_BOOST_CC_CTRL,
        /* FS   28  1c */   STREAMS_BOOST_CC_CTRL,
        /* GS   29  1d */   STREAMS_BOOST_CC_CTRL,
        /* RS   30  1e */   STREAMS_BOOST_CC_CTRL,
        /* US   31  1f */   STREAMS_BOOST_CC_CTRL,
        /* SP   32  20 */   STREAMS_BOOST_CC_SPACE,
        /*  !   33  21 */   STREAMS_BOOST_CC_PUNCT,
        /*  "   34  22 */   STREAMS_BOOST_CC_PUNCT,
        /*  #   35  23 */   STREAMS_BOOST_CC_PUNCT,
        /*  $   36  24 */   STREAMS_BOOST_CC_PUNCT,
        /*  %   37  25 */   STREAMS_BOOST_CC_PUNCT,
        /*  &   38  26 */   STREAMS_BOOST_CC_PUNCT,
        /*  '   39  27 */   STREAMS_BOOST_CC_PUNCT,
        /*  (   40  28 */   STREAMS_BOOST_CC_PUNCT,
        /*  )   41  29 */   STREAMS_BOOST_CC_PUNCT,
        /*  *   42  2a */   STREAMS_BOOST_CC_PUNCT,
        /*  +   43  2b */   STREAMS_BOOST_CC_PUNCT,
        /*  ,   44  2c */   STREAMS_BOOST_CC_PUNCT,
        /*  -   45  2d */   STREAMS_BOOST_CC_PUNCT,
        /*  .   46  2e */   STREAMS_BOOST_CC_PUNCT,
        /*  /   47  2f */   STREAMS_BOOST_CC_PUNCT,
        /*  0   48  30 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  1   49  31 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  2   50  32 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  3   51  33 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  4   52  34 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  5   53  35 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  6   54  36 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  7   55  37 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  8   56  38 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  9   57  39 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_XDIGIT,
        /*  :   58  3a */   STREAMS_BOOST_CC_PUNCT,
        /*  ;   59  3b */   STREAMS_BOOST_CC_PUNCT,
        /*  <   60  3c */   STREAMS_BOOST_CC_PUNCT,
        /*  =   61  3d */   STREAMS_BOOST_CC_PUNCT,
        /*  >   62  3e */   STREAMS_BOOST_CC_PUNCT,
        /*  ?   63  3f */   STREAMS_BOOST_CC_PUNCT,
        /*  @   64  40 */   STREAMS_BOOST_CC_PUNCT,
        /*  A   65  41 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_UPPER,
        /*  B   66  42 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_UPPER,
        /*  C   67  43 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_UPPER,
        /*  D   68  44 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_UPPER,
        /*  E   69  45 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_UPPER,
        /*  F   70  46 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_UPPER,
        /*  G   71  47 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  H   72  48 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  I   73  49 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  J   74  4a */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  K   75  4b */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  L   76  4c */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  M   77  4d */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  N   78  4e */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  O   79  4f */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  P   80  50 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Q   81  51 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  R   82  52 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  S   83  53 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  T   84  54 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  U   85  55 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  V   86  56 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  W   87  57 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  X   88  58 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Y   89  59 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Z   90  5a */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  [   91  5b */   STREAMS_BOOST_CC_PUNCT,
        /*  \   92  5c */   STREAMS_BOOST_CC_PUNCT,
        /*  ]   93  5d */   STREAMS_BOOST_CC_PUNCT,
        /*  ^   94  5e */   STREAMS_BOOST_CC_PUNCT,
        /*  _   95  5f */   STREAMS_BOOST_CC_PUNCT,
        /*  `   96  60 */   STREAMS_BOOST_CC_PUNCT,
        /*  a   97  61 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_LOWER,
        /*  b   98  62 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_LOWER,
        /*  c   99  63 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_LOWER,
        /*  d  100  64 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_LOWER,
        /*  e  101  65 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_LOWER,
        /*  f  102  66 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_XDIGIT|STREAMS_BOOST_CC_LOWER,
        /*  g  103  67 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  h  104  68 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  i  105  69 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  j  106  6a */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  k  107  6b */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  l  108  6c */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  m  109  6d */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  n  110  6e */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  o  111  6f */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  p  112  70 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  q  113  71 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  r  114  72 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  s  115  73 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  t  116  74 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  u  117  75 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  v  118  76 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  w  119  77 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  x  120  78 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  y  121  79 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  z  122  7a */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  {  123  7b */   STREAMS_BOOST_CC_PUNCT,
        /*  |  124  7c */   STREAMS_BOOST_CC_PUNCT,
        /*  }  125  7d */   STREAMS_BOOST_CC_PUNCT,
        /*  ~  126  7e */   STREAMS_BOOST_CC_PUNCT,
        /* DEL 127  7f */   STREAMS_BOOST_CC_CTRL,
    };

    ///////////////////////////////////////////////////////////////////////////
    //  Test characters for specified conditions (using ASCII)
    ///////////////////////////////////////////////////////////////////////////
    struct ascii
    {
        typedef char char_type;

        static bool
        isascii_(int ch)
        {
            return (0 == (ch & ~0x7f)) ? true : false;
        }

        static bool
        ischar(int ch)
        {
            return isascii_(ch);
        }

        static int
        isalnum(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_ALPHA)
                || (ascii_char_types[ch] & STREAMS_BOOST_CC_DIGIT);
        }

        static int
        isalpha(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_ALPHA);
        }

        static int
        isdigit(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_DIGIT);
        }

        static int
        isxdigit(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_XDIGIT);
        }

        static int
        iscntrl(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_CTRL);
        }

        static int
        isgraph(int ch)
        {
            return ('\x21' <= ch && ch <= '\x7e');
        }

        static int
        islower(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_LOWER);
        }

        static int
        isprint(int ch)
        {
            return ('\x20' <= ch && ch <= '\x7e');
        }

        static int
        ispunct(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_PUNCT);
        }

        static int
        isspace(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_SPACE);
        }

        static int
        isblank STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (int ch)
        {
            return ('\x09' == ch || '\x20' == ch);
        }

        static int
        isupper(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return (ascii_char_types[ch] & STREAMS_BOOST_CC_UPPER);
        }

        ///////////////////////////////////////////////////////////////////////
        //  Simple character conversions
        ///////////////////////////////////////////////////////////////////////

        static int
        tolower(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return isupper(ch) ? (ch - 'A' + 'a') : ch;
        }

        static int
        toupper(int ch)
        {
            STREAMS_BOOST_ASSERT(isascii_(ch));
            return islower(ch) ? (ch - 'a' + 'A') : ch;
        }

        static ::streams_boost::uint32_t
        toucs4(int ch)
        {
            return ch;
        }
    };

}}}

///////////////////////////////////////////////////////////////////////////////
// undefine macros
///////////////////////////////////////////////////////////////////////////////
#undef STREAMS_BOOST_CC_DIGIT
#undef STREAMS_BOOST_CC_XDIGIT
#undef STREAMS_BOOST_CC_ALPHA
#undef STREAMS_BOOST_CC_CTRL
#undef STREAMS_BOOST_CC_LOWER
#undef STREAMS_BOOST_CC_UPPER
#undef STREAMS_BOOST_CC_PUNCT
#undef STREAMS_BOOST_CC_SPACE

#endif

