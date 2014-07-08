// Copyright (C) 2005, Fernando Luis Cacciola Carballal.
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/lib/optional for documentation.
//
// You are welcome to contact the author at:
//  fernando_cacciola@hotmail.com
//
#ifndef STREAMS_BOOST_OPTIONAL_OPTIONAL_IO_FLC_19NOV2002_HPP
#define STREAMS_BOOST_OPTIONAL_OPTIONAL_IO_FLC_19NOV2002_HPP

#if defined __GNUC__
#  if (__GNUC__ == 2 && __GNUC_MINOR__ <= 97) 
#    define STREAMS_BOOST_OPTIONAL_NO_TEMPLATED_STREAMS
#  endif
#endif // __GNUC__

#if defined STREAMS_BOOST_OPTIONAL_NO_TEMPLATED_STREAMS
#  include <iostream>
#else 
#  include <istream>
#  include <ostream>
#endif  


#include "streams_boost/optional/optional.hpp"
#include "streams_boost/utility/value_init.hpp"

namespace streams_boost
{

#if defined (STREAMS_BOOST_NO_TEMPLATED_STREAMS)
template<class T>
inline std::ostream& operator<<(std::ostream& out, optional<T> const& v)
#else
template<class CharType, class CharTrait, class T>
inline
std::basic_ostream<CharType, CharTrait>&
operator<<(std::basic_ostream<CharType, CharTrait>& out, optional<T> const& v)
#endif
{
  if ( out.good() )
  {
    if ( !v )
         out << "--" ;
    else out << ' ' << *v ;
  }

  return out;
}

#if defined (STREAMS_BOOST_NO_TEMPLATED_STREAMS)
template<class T>
inline std::istream& operator>>(std::istream& in, optional<T>& v)
#else
template<class CharType, class CharTrait, class T>
inline
std::basic_istream<CharType, CharTrait>&
operator>>(std::basic_istream<CharType, CharTrait>& in, optional<T>& v)
#endif
{
  if ( in.good() )
  {
    int d = in.get();
    if ( d == ' ' )
    {
      T x ;
      in >> x;
      v = x ;
    }
    else
      v = optional<T>() ;
  }

  return in;
}

} // namespace streams_boost

#endif

