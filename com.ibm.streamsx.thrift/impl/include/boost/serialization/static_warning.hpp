#ifndef STREAMS_BOOST_SERIALIZATION_STATIC_WARNING_HPP
#define STREAMS_BOOST_SERIALIZATION_STATIC_WARNING_HPP

//  (C) Copyright Robert Ramey 2003. Jonathan Turkanis 2004.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/static_assert for documentation.

/*
 Revision history:
   15 June  2003 - Initial version.
   31 March 2004 - improved diagnostic messages and portability 
                   (Jonathan Turkanis)
   03 April 2004 - works on VC6 at class and namespace scope
                 - ported to DigitalMars
                 - static warnings disabled by default; when enabled,
                   uses pragmas to enable required compiler warnings
                   on MSVC, Intel, Metrowerks and Borland 5.x.
                   (Jonathan Turkanis)
   30 May 2004   - tweaked for msvc 7.1 and gcc 3.3
                 - static warnings ENabled by default; when enabled,
                   (Robert Ramey)
*/

#include <streams_boost/config.hpp>

//
// Implementation
// Makes use of the following warnings:
//  1. GCC prior to 3.3: division by zero.
//  2. BCC 6.0 preview: unreferenced local variable.
//  3. DigitalMars: returning address of local automatic variable.
//  4. VC6: class previously seen as struct (as in 'streams_boost/mpl/print.hpp')
//  5. All others: deletion of pointer to incomplete type.
//
// The trick is to find code which produces warnings containing the name of
// a structure or variable. Details, with same numbering as above:
// 1. static_warning_impl<B>::value is zero iff B is false, so diving an int
//    by this value generates a warning iff B is false.
// 2. static_warning_impl<B>::type has a constructor iff B is true, so an
//    unreferenced variable of this type generates a warning iff B is false.
// 3. static_warning_impl<B>::type overloads operator& to return a dynamically
//    allocated int pointer only is B is true, so  returning the address of an
//    automatic variable of this type generates a warning iff B is fasle.
// 4. static_warning_impl<B>::STATIC_WARNING is decalred as a struct iff B is 
//    false. 
// 5. static_warning_impl<B>::type is incomplete iff B is false, so deleting a
//    pointer to this type generates a warning iff B is false.
//

//------------------Enable selected warnings----------------------------------//

// Enable the warnings relied on by STREAMS_BOOST_STATIC_WARNING, where possible. The 
// only pragma which is absolutely necessary here is for Borland 5.x, since 
// W8073 is disabled by default. If enabling selected warnings is considered 
// unacceptable, this section can be replaced with:
//   #if defined(__BORLANDC__) && (__BORLANDC__ <= 0x600)
//    pragma warn +st
//   #endif

// 6. replaced implementation with one which depends solely on
//    mpl::print<>.  The previous one was found to fail for functions
//    under recent versions of gcc and intel compilers - Robert Ramey

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/print.hpp>
#include <streams_boost/mpl/eval_if.hpp>

namespace streams_boost {
namespace serialization {

template<int L> 
struct STREAMS_BOOST_SERIALIZATION_STATIC_WARNING_LINE{};

template<bool B, int L>
struct static_warning_test{
    typename streams_boost::mpl::eval_if_c<
        B,
        streams_boost::mpl::true_,
        typename streams_boost::mpl::identity<
            streams_boost::mpl::print<
                STREAMS_BOOST_SERIALIZATION_STATIC_WARNING_LINE<L>
            >
        >
    >::type type;
};

template<int i>
struct STREAMS_BOOST_SERIALIZATION_SS {};

} // serialization
} // streams_boost

#define STREAMS_BOOST_SERIALIZATION_BSW(B, L) \
    typedef streams_boost::serialization::STREAMS_BOOST_SERIALIZATION_SS< \
        sizeof( streams_boost::serialization::static_warning_test< B, L > ) \
    > STREAMS_BOOST_JOIN(STATIC_WARNING_LINE, L);

#define STREAMS_BOOST_STATIC_WARNING(B) STREAMS_BOOST_SERIALIZATION_BSW(B, __LINE__)

#endif // STREAMS_BOOST_SERIALIZATION_STATIC_WARNING_HPP
