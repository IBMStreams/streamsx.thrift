// Copyright (C) 2004, 2005 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.streams_boost.org/LICENSE_1_0.txt)

// Inclusion of this file increments STREAMS_BOOST_TYPEOF_REGISTRATION_GROUP 
// This method was suggested by Paul Mensonides

#ifdef STREAMS_BOOST_TYPEOF_EMULATION
#   undef STREAMS_BOOST_TYPEOF_REGISTRATION_GROUP

#   include <streams_boost/preprocessor/slot/counter.hpp>
#   include STREAMS_BOOST_PP_UPDATE_COUNTER()
#   define STREAMS_BOOST_TYPEOF_REGISTRATION_GROUP STREAMS_BOOST_PP_COUNTER
#endif
