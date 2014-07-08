/*=============================================================================
  Copyright (c) 2001-2008 Joel de Guzman
  Copyright (c) 2001-2008 Hartmut Kaiser
  http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(SPIRIT_CLASSIC_NAMESPACE_HPP)
#define SPIRIT_CLASSIC_NAMESPACE_HPP

#if defined(STREAMS_BOOST_SPIRIT_USE_OLD_NAMESPACE)

// Use the old namespace for Spirit.Classic, everything is located in the 
// namespace streams_boost::spirit.
// This is in place for backwards compatibility with Spirit V1.8.x. Don't use
// it when combining Spirit.Classic with other parts of the library

#define STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN /*namespace classic {*/
#define STREAMS_BOOST_SPIRIT_CLASSIC_NS              streams_boost::spirit/*::classic*/
#define STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END   /*}*/
        
#else

// This is the normal (and suggested) mode of operation when using 
// Spirit.Classic. Everything will be located in the namespace 
// streams_boost::spirit::classic, avoiding name clashes with other parts of Spirit.

#define STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN namespace classic {
#define STREAMS_BOOST_SPIRIT_CLASSIC_NS              streams_boost::spirit::classic
#define STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END   }

#endif

#endif 
