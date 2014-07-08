// ----------------------------------------------------------------------------
// unset_macros.hpp
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/format for library home page

// ----------------------------------------------------------------------------

// *** Undefine 'local' macros :
#ifdef STREAMS_BOOST_NO_OVERLOAD_FOR_NON_CONST
#undef STREAMS_BOOST_NO_OVERLOAD_FOR_NON_CONST
#endif
#ifdef STREAMS_BOOST_NO_LOCALE_ISDIGIT
#undef STREAMS_BOOST_NO_LOCALE_ISDIGIT
#endif
#ifdef STREAMS_BOOST_IO_STD
#undef STREAMS_BOOST_IO_STD
#endif
#ifdef STREAMS_BOOST_IO_NEEDS_USING_DECLARATION
#undef STREAMS_BOOST_IO_NEEDS_USING_DECLARATION
#endif
#ifdef STREAMS_BOOST_NO_TEMPLATE_STD_STREAM
#undef STREAMS_BOOST_NO_TEMPLATE_STD_STREAM
#endif
#ifdef STREAMS_BOOST_FORMAT_STREAMBUF_DEFINED
#undef STREAMS_BOOST_FORMAT_STREAMBUF_DEFINED
#endif
#ifdef STREAMS_BOOST_FORMAT_OSTREAM_DEFINED
#undef STREAMS_BOOST_FORMAT_OSTREAM_DEFINED
#endif
