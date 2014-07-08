/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_ISO8859_1_APRIL_26_2006_1106PM)
#define STREAMS_BOOST_SPIRIT_ISO8859_1_APRIL_26_2006_1106PM

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
    // ISO 8859-1 character classification table
    //
    // the comments intentionally contain non-ascii characters
    // streams_boostinspect:noascii
    ///////////////////////////////////////////////////////////////////////////
    const unsigned char iso8859_1_char_types[] =
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
        /* --  128  80 */   STREAMS_BOOST_CC_CTRL,
        /* --  129  81 */   STREAMS_BOOST_CC_CTRL,
        /* --  130  82 */   STREAMS_BOOST_CC_CTRL,
        /* --  131  83 */   STREAMS_BOOST_CC_CTRL,
        /* --  132  84 */   STREAMS_BOOST_CC_CTRL,
        /* --  133  85 */   STREAMS_BOOST_CC_CTRL,
        /* --  134  86 */   STREAMS_BOOST_CC_CTRL,
        /* --  135  87 */   STREAMS_BOOST_CC_CTRL,
        /* --  136  88 */   STREAMS_BOOST_CC_CTRL,
        /* --  137  89 */   STREAMS_BOOST_CC_CTRL,
        /* --  138  8a */   STREAMS_BOOST_CC_CTRL,
        /* --  139  8b */   STREAMS_BOOST_CC_CTRL,
        /* --  140  8c */   STREAMS_BOOST_CC_CTRL,
        /* --  141  8d */   STREAMS_BOOST_CC_CTRL,
        /* --  142  8e */   STREAMS_BOOST_CC_CTRL,
        /* --  143  8f */   STREAMS_BOOST_CC_CTRL,
        /* --  144  90 */   STREAMS_BOOST_CC_CTRL,
        /* --  145  91 */   STREAMS_BOOST_CC_CTRL,
        /* --  146  92 */   STREAMS_BOOST_CC_CTRL,
        /* --  147  93 */   STREAMS_BOOST_CC_CTRL,
        /* --  148  94 */   STREAMS_BOOST_CC_CTRL,
        /* --  149  95 */   STREAMS_BOOST_CC_CTRL,
        /* --  150  96 */   STREAMS_BOOST_CC_CTRL,
        /* --  151  97 */   STREAMS_BOOST_CC_CTRL,
        /* --  152  98 */   STREAMS_BOOST_CC_CTRL,
        /* --  153  99 */   STREAMS_BOOST_CC_CTRL,
        /* --  154  9a */   STREAMS_BOOST_CC_CTRL,
        /* --  155  9b */   STREAMS_BOOST_CC_CTRL,
        /* --  156  9c */   STREAMS_BOOST_CC_CTRL,
        /* --  157  9d */   STREAMS_BOOST_CC_CTRL,
        /* --  158  9e */   STREAMS_BOOST_CC_CTRL,
        /* --  159  9f */   STREAMS_BOOST_CC_CTRL,
        /*     160  a0 */   STREAMS_BOOST_CC_SPACE,
        /*  ¡  161  a1 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¢  162  a2 */   STREAMS_BOOST_CC_PUNCT,
        /*  £  163  a3 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¤  164  a4 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¥  165  a5 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¦  166  a6 */   STREAMS_BOOST_CC_PUNCT,
        /*  §  167  a7 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¨  168  a8 */   STREAMS_BOOST_CC_PUNCT,
        /*  ©  169  a9 */   STREAMS_BOOST_CC_PUNCT,
        /*  ª  170  aa */   STREAMS_BOOST_CC_PUNCT,
        /*  «  171  ab */   STREAMS_BOOST_CC_PUNCT,
        /*  ¬  172  ac */   STREAMS_BOOST_CC_PUNCT,
        /*  ­  173  ad */   STREAMS_BOOST_CC_PUNCT,
        /*  ®  174  ae */   STREAMS_BOOST_CC_PUNCT,
        /*  ¯  175  af */   STREAMS_BOOST_CC_PUNCT,
        /*  °  176  b0 */   STREAMS_BOOST_CC_PUNCT,
        /*  ±  177  b1 */   STREAMS_BOOST_CC_PUNCT,
        /*  ²  178  b2 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_PUNCT,
        /*  ³  179  b3 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_PUNCT,
        /*  ´  180  b4 */   STREAMS_BOOST_CC_PUNCT,
        /*  µ  181  b5 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¶  182  b6 */   STREAMS_BOOST_CC_PUNCT,
        /*  ·  183  b7 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¸  184  b8 */   STREAMS_BOOST_CC_PUNCT,
        /*  ¹  185  b9 */   STREAMS_BOOST_CC_DIGIT|STREAMS_BOOST_CC_PUNCT,
        /*  º  186  ba */   STREAMS_BOOST_CC_PUNCT,
        /*  »  187  bb */   STREAMS_BOOST_CC_PUNCT,
        /*  ¼  188  bc */   STREAMS_BOOST_CC_PUNCT,
        /*  ½  189  bd */   STREAMS_BOOST_CC_PUNCT,
        /*  ¾  190  be */   STREAMS_BOOST_CC_PUNCT,
        /*  ¿  191  bf */   STREAMS_BOOST_CC_PUNCT,
        /*  À  192  c0 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Á  193  c1 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Â  194  c2 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ã  195  c3 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ä  196  c4 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Å  197  c5 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Æ  198  c6 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ç  199  c7 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  È  200  c8 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  É  201  c9 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ê  202  ca */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ë  203  cb */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ì  204  cc */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Í  205  cd */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Î  206  ce */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ï  207  cf */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ð  208  d0 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ñ  209  d1 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ò  210  d2 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ó  211  d3 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ô  212  d4 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Õ  213  d5 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ö  214  d6 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  ×  215  d7 */   STREAMS_BOOST_CC_PUNCT,
        /*  Ø  216  d8 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ù  217  d9 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ú  218  da */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Û  219  db */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ü  220  dc */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Ý  221  dd */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  Þ  222  de */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_UPPER,
        /*  ß  223  df */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  à  224  e0 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  á  225  e1 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  â  226  e2 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ã  227  e3 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ä  228  e4 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  å  229  e5 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  æ  230  e6 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ç  231  e7 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  è  232  e8 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  é  233  e9 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ê  234  ea */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ë  235  eb */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ì  236  ec */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  í  237  ed */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  î  238  ee */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ï  239  ef */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ð  240  f0 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ñ  241  f1 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ò  242  f2 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ó  243  f3 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ô  244  f4 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  õ  245  f5 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ö  246  f6 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ÷  247  f7 */   STREAMS_BOOST_CC_PUNCT,
        /*  ø  248  f8 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ù  249  f9 */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ú  250  fa */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  û  251  fb */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ü  252  fc */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ý  253  fd */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  þ  254  fe */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
        /*  ÿ  255  ff */   STREAMS_BOOST_CC_ALPHA|STREAMS_BOOST_CC_LOWER,
    };

    ///////////////////////////////////////////////////////////////////////////
    // ISO 8859-1 character conversion table
    ///////////////////////////////////////////////////////////////////////////
    const unsigned char iso8859_1_char_conversion[] =
    {
        /* NUL   0   0 */   '\0',
        /* SOH   1   1 */   '\0',
        /* STX   2   2 */   '\0',
        /* ETX   3   3 */   '\0',
        /* EOT   4   4 */   '\0',
        /* ENQ   5   5 */   '\0',
        /* ACK   6   6 */   '\0',
        /* BEL   7   7 */   '\0',
        /* BS    8   8 */   '\0',
        /* HT    9   9 */   '\0',
        /* NL   10   a */   '\0',
        /* VT   11   b */   '\0',
        /* NP   12   c */   '\0',
        /* CR   13   d */   '\0',
        /* SO   14   e */   '\0',
        /* SI   15   f */   '\0',
        /* DLE  16  10 */   '\0',
        /* DC1  17  11 */   '\0',
        /* DC2  18  12 */   '\0',
        /* DC3  19  13 */   '\0',
        /* DC4  20  14 */   '\0',
        /* NAK  21  15 */   '\0',
        /* SYN  22  16 */   '\0',
        /* ETB  23  17 */   '\0',
        /* CAN  24  18 */   '\0',
        /* EM   25  19 */   '\0',
        /* SUB  26  1a */   '\0',
        /* ESC  27  1b */   '\0',
        /* FS   28  1c */   '\0',
        /* GS   29  1d */   '\0',
        /* RS   30  1e */   '\0',
        /* US   31  1f */   '\0',
        /* SP   32  20 */   '\0',
        /*  !   33  21 */   '\0',
        /*  "   34  22 */   '\0',
        /*  #   35  23 */   '\0',
        /*  $   36  24 */   '\0',
        /*  %   37  25 */   '\0',
        /*  &   38  26 */   '\0',
        /*  '   39  27 */   '\0',
        /*  (   40  28 */   '\0',
        /*  )   41  29 */   '\0',
        /*  *   42  2a */   '\0',
        /*  +   43  2b */   '\0',
        /*  ,   44  2c */   '\0',
        /*  -   45  2d */   '\0',
        /*  .   46  2e */   '\0',
        /*  /   47  2f */   '\0',
        /*  0   48  30 */   '\0',
        /*  1   49  31 */   '\0',
        /*  2   50  32 */   '\0',
        /*  3   51  33 */   '\0',
        /*  4   52  34 */   '\0',
        /*  5   53  35 */   '\0',
        /*  6   54  36 */   '\0',
        /*  7   55  37 */   '\0',
        /*  8   56  38 */   '\0',
        /*  9   57  39 */   '\0',
        /*  :   58  3a */   '\0',
        /*  ;   59  3b */   '\0',
        /*  <   60  3c */   '\0',
        /*  =   61  3d */   '\0',
        /*  >   62  3e */   '\0',
        /*  ?   63  3f */   '\0',
        /*  @   64  40 */   '\0',
        /*  A   65  41 */   'a',
        /*  B   66  42 */   'b',
        /*  C   67  43 */   'c',
        /*  D   68  44 */   'd',
        /*  E   69  45 */   'e',
        /*  F   70  46 */   'f',
        /*  G   71  47 */   'g',
        /*  H   72  48 */   'h',
        /*  I   73  49 */   'i',
        /*  J   74  4a */   'j',
        /*  K   75  4b */   'k',
        /*  L   76  4c */   'l',
        /*  M   77  4d */   'm',
        /*  N   78  4e */   'n',
        /*  O   79  4f */   'o',
        /*  P   80  50 */   'p',
        /*  Q   81  51 */   'q',
        /*  R   82  52 */   'r',
        /*  S   83  53 */   's',
        /*  T   84  54 */   't',
        /*  U   85  55 */   'u',
        /*  V   86  56 */   'v',
        /*  W   87  57 */   'w',
        /*  X   88  58 */   'x',
        /*  Y   89  59 */   'y',
        /*  Z   90  5a */   'z',
        /*  [   91  5b */   '\0',
        /*  \   92  5c */   '\0',
        /*  ]   93  5d */   '\0',
        /*  ^   94  5e */   '\0',
        /*  _   95  5f */   '\0',
        /*  `   96  60 */   '\0',
        /*  a   97  61 */   'A',
        /*  b   98  62 */   'B',
        /*  c   99  63 */   'C',
        /*  d  100  64 */   'D',
        /*  e  101  65 */   'E',
        /*  f  102  66 */   'F',
        /*  g  103  67 */   'G',
        /*  h  104  68 */   'H',
        /*  i  105  69 */   'I',
        /*  j  106  6a */   'J',
        /*  k  107  6b */   'K',
        /*  l  108  6c */   'L',
        /*  m  109  6d */   'M',
        /*  n  110  6e */   'N',
        /*  o  111  6f */   'O',
        /*  p  112  70 */   'P',
        /*  q  113  71 */   'Q',
        /*  r  114  72 */   'R',
        /*  s  115  73 */   'S',
        /*  t  116  74 */   'T',
        /*  u  117  75 */   'U',
        /*  v  118  76 */   'V',
        /*  w  119  77 */   'W',
        /*  x  120  78 */   'X',
        /*  y  121  79 */   'Y',
        /*  z  122  7a */   'Z',
        /*  {  123  7b */   '\0',
        /*  |  124  7c */   '\0',
        /*  }  125  7d */   '\0',
        /*  ~  126  7e */   '\0',
        /* DEL 127  7f */   '\0',
        /* --  128  80 */   '\0',
        /* --  129  81 */   '\0',
        /* --  130  82 */   '\0',
        /* --  131  83 */   '\0',
        /* --  132  84 */   '\0',
        /* --  133  85 */   '\0',
        /* --  134  86 */   '\0',
        /* --  135  87 */   '\0',
        /* --  136  88 */   '\0',
        /* --  137  89 */   '\0',
        /* --  138  8a */   '\0',
        /* --  139  8b */   '\0',
        /* --  140  8c */   '\0',
        /* --  141  8d */   '\0',
        /* --  142  8e */   '\0',
        /* --  143  8f */   '\0',
        /* --  144  90 */   '\0',
        /* --  145  91 */   '\0',
        /* --  146  92 */   '\0',
        /* --  147  93 */   '\0',
        /* --  148  94 */   '\0',
        /* --  149  95 */   '\0',
        /* --  150  96 */   '\0',
        /* --  151  97 */   '\0',
        /* --  152  98 */   '\0',
        /* --  153  99 */   '\0',
        /* --  154  9a */   '\0',
        /* --  155  9b */   '\0',
        /* --  156  9c */   '\0',
        /* --  157  9d */   '\0',
        /* --  158  9e */   '\0',
        /* --  159  9f */   '\0',
        /*     160  a0 */   '\0',
        /*  ¡  161  a1 */   '\0',
        /*  ¢  162  a2 */   '\0',
        /*  £  163  a3 */   '\0',
        /*  ¤  164  a4 */   '\0',
        /*  ¥  165  a5 */   '\0',
        /*  ¦  166  a6 */   '\0',
        /*  §  167  a7 */   '\0',
        /*  ¨  168  a8 */   '\0',
        /*  ©  169  a9 */   '\0',
        /*  ª  170  aa */   '\0',
        /*  «  171  ab */   '\0',
        /*  ¬  172  ac */   '\0',
        /*  ­  173  ad */   '\0',
        /*  ®  174  ae */   '\0',
        /*  ¯  175  af */   '\0',
        /*  °  176  b0 */   '\0',
        /*  ±  177  b1 */   '\0',
        /*  ²  178  b2 */   '\0',
        /*  ³  179  b3 */   '\0',
        /*  ´  180  b4 */   '\0',
        /*  µ  181  b5 */   '\0',
        /*  ¶  182  b6 */   '\0',
        /*  ·  183  b7 */   '\0',
        /*  ¸  184  b8 */   '\0',
        /*  ¹  185  b9 */   '\0',
        /*  º  186  ba */   '\0',
        /*  »  187  bb */   '\0',
        /*  ¼  188  bc */   '\0',
        /*  ½  189  bd */   '\0',
        /*  ¾  190  be */   '\0',
        /*  ¿  191  bf */   '\0',
        /*  à  192  c0 */   0xe0,
        /*  á  193  c1 */   0xe1,
        /*  â  194  c2 */   0xe2,
        /*  ã  195  c3 */   0xe3,
        /*  ä  196  c4 */   0xe4,
        /*  å  197  c5 */   0xe5,
        /*  æ  198  c6 */   0xe6,
        /*  ç  199  c7 */   0xe7,
        /*  è  200  c8 */   0xe8,
        /*  é  201  c9 */   0xe9,
        /*  ê  202  ca */   0xea,
        /*  ë  203  cb */   0xeb,
        /*  ì  204  cc */   0xec,
        /*  í  205  cd */   0xed,
        /*  î  206  ce */   0xee,
        /*  ï  207  cf */   0xef,
        /*  ð  208  d0 */   0xf0,
        /*  ñ  209  d1 */   0xf1,
        /*  ò  210  d2 */   0xf2,
        /*  ó  211  d3 */   0xf3,
        /*  ô  212  d4 */   0xf4,
        /*  õ  213  d5 */   0xf5,
        /*  ö  214  d6 */   0xf6,
        /*  ×  215  d7 */   '\0',
        /*  ø  216  d8 */   0xf8,
        /*  ù  217  d9 */   0xf9,
        /*  ú  218  da */   0xfa,
        /*  û  219  db */   0xfb,
        /*  ü  220  dc */   0xfc,
        /*  ý  221  dd */   0xfd,
        /*  þ  222  de */   0xfe,
        /*  ß  223  df */   '\0',
        /*  À  224  e0 */   0xc0,
        /*  Á  225  e1 */   0xc1,
        /*  Â  226  e2 */   0xc2,
        /*  Ã  227  e3 */   0xc3,
        /*  Ä  228  e4 */   0xc4,
        /*  Å  229  e5 */   0xc5,
        /*  Æ  230  e6 */   0xc6,
        /*  Ç  231  e7 */   0xc7,
        /*  È  232  e8 */   0xc8,
        /*  É  233  e9 */   0xc9,
        /*  Ê  234  ea */   0xca,
        /*  Ë  235  eb */   0xcb,
        /*  Ì  236  ec */   0xcc,
        /*  Í  237  ed */   0xcd,
        /*  Î  238  ee */   0xce,
        /*  Ï  239  ef */   0xcf,
        /*  Ð  240  f0 */   0xd0,
        /*  Ñ  241  f1 */   0xd1,
        /*  Ò  242  f2 */   0xd2,
        /*  Ó  243  f3 */   0xd3,
        /*  Ô  244  f4 */   0xd4,
        /*  Õ  245  f5 */   0xd5,
        /*  Ö  246  f6 */   0xd6,
        /*  ÷  247  f7 */   '\0',
        /*  Ø  248  f8 */   0xd8,
        /*  Ù  249  f9 */   0xd9,
        /*  Ú  250  fa */   0xda,
        /*  Û  251  fb */   0xdb,
        /*  Ü  252  fc */   0xdc,
        /*  Ý  253  fd */   0xdd,
        /*  Þ  254  fe */   0xde,
        /*  ÿ  255  ff */   '\0',
    };

    ///////////////////////////////////////////////////////////////////////////
    //  Test characters for specified conditions (using iso8859-1)
    ///////////////////////////////////////////////////////////////////////////
    struct iso8859_1
    {
        typedef unsigned char char_type;

        static bool
        isascii_(int ch)
        {
            return (0 == (ch & ~0x7f)) ? true : false;
        }

        static bool
        ischar(int ch)
        {
            // iso8859.1 uses all 8 bits
            // we have to watch out for sign extensions
            return (0 == (ch & ~0xff) || ~0 == (ch | 0xff)) ? true : false;
        }

        static int
        isalnum(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_ALPHA)
                || (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_DIGIT);
        }

        static int
        isalpha(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_ALPHA);
        }

        static int
        isdigit(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_DIGIT);
        }

        static int
        isxdigit(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_XDIGIT);
        }

        static int
        iscntrl(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_CTRL);
        }

        static int
        isgraph(int ch)
        {
            return ('\x21' <= ch && ch <= '\x7e') || ('\xa1' <= ch && ch <= '\xff');
        }

        static int
        islower(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_LOWER);
        }

        static int
        isprint(int ch)
        {
            return ('\x20' <= ch && ch <= '\x7e') || ('\xa0' <= ch && ch <= '\xff');
        }

        static int
        ispunct(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_PUNCT);
        }

        static int
        isspace(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_SPACE);
        }

        static int
        isblank STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (int ch)
        {
            return ('\x09' == ch || '\x20' == ch || '\xa0' == ch);
        }

        static int
        isupper(int ch)
        {
            STREAMS_BOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & STREAMS_BOOST_CC_UPPER);
        }

    ///////////////////////////////////////////////////////////////////////////
    //  Simple character conversions
    ///////////////////////////////////////////////////////////////////////////

        static int
        tolower(int ch)
        {
            return isupper(ch) && '\0' != iso8859_1_char_conversion[ch] ?
                iso8859_1_char_conversion[ch] : ch;
        }

        static int
        toupper(int ch)
        {
            return islower(ch) && '\0' != iso8859_1_char_conversion[ch] ?
                iso8859_1_char_conversion[ch] : ch;
        }

        static ::streams_boost::uint32_t
        toucs4(int ch)
        {
            // The first 256 characters in Unicode and the UCS are
            // identical to those in ISO/IEC-8859-1.
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

