// ----------------------------------------------------------------------------
// format.hpp :  primary header
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/format for library home page


// ----------------------------------------------------------------------------

#ifndef STREAMS_BOOST_FORMAT_HPP
#define STREAMS_BOOST_FORMAT_HPP

#include <vector>
#include <string>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/config.hpp>

#ifndef STREAMS_BOOST_NO_STD_LOCALE
#include <locale>
#endif

// ***   Compatibility framework
#include <streams_boost/format/detail/compat_workarounds.hpp>

#ifdef STREAMS_BOOST_NO_LOCALE_ISIDIGIT
#include <cctype>  // we'll use the non-locale  <cctype>'s std::isdigit(int)
#endif

// ****  Forward declarations ----------------------------------
#include <streams_boost/format/format_fwd.hpp>     // basic_format<Ch,Tr>, and other frontends
#include <streams_boost/format/internals_fwd.hpp>  // misc forward declarations for internal use

// ****  Auxiliary structs (stream_format_state<Ch,Tr> , and format_item<Ch,Tr> )
#include <streams_boost/format/internals.hpp>    

// ****  Format  class  interface --------------------------------
#include <streams_boost/format/format_class.hpp>

// **** Exceptions -----------------------------------------------
#include <streams_boost/format/exceptions.hpp>

// **** Implementation -------------------------------------------
#include <streams_boost/format/format_implementation.hpp>   // member functions
#include <streams_boost/format/group.hpp>                   // class for grouping arguments
#include <streams_boost/format/feed_args.hpp>               // argument-feeding functions
#include <streams_boost/format/parsing.hpp>                 // format-string parsing (member-)functions

// **** Implementation of the free functions ----------------------
#include <streams_boost/format/free_funcs.hpp>


// *** Undefine 'local' macros :
#include <streams_boost/format/detail/unset_macros.hpp>

#endif // STREAMS_BOOST_FORMAT_HPP
