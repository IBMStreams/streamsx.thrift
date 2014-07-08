//  (C) Copyright Gennadiy Rozental 2005-2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : simple helpers for creating cusom output manipulators
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_TRIVIAL_SIGNLETON_HPP_020505GER
#define STREAMS_BOOST_TEST_TRIVIAL_SIGNLETON_HPP_020505GER

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>

#include <streams_boost/noncopyable.hpp>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************                   singleton                  ************** //
// ************************************************************************** //

template<typename Derived>
class singleton : private streams_boost::noncopyable {
public:
    static Derived& instance() { static Derived the_inst; return the_inst; }    
protected:
    singleton()  {}
    ~singleton() {}
};

} // namespace unit_test

#define STREAMS_BOOST_TEST_SINGLETON_CONS( type )       \
friend class streams_boost::unit_test::singleton<type>; \
type() {}                                       \
/**/

#if STREAMS_BOOST_WORKAROUND(__DECCXX_VER, STREAMS_BOOST_TESTED_AT(60590042))

#define STREAMS_BOOST_TEST_SINGLETON_INST( inst ) \
template class unit_test::singleton< STREAMS_BOOST_JOIN( inst, _t ) > ; \
namespace { STREAMS_BOOST_JOIN( inst, _t)& inst = STREAMS_BOOST_JOIN( inst, _t)::instance(); }

#elif defined(__APPLE_CC__) && defined(__GNUC__) && __GNUC__ < 4
#define STREAMS_BOOST_TEST_SINGLETON_INST( inst ) \
static STREAMS_BOOST_JOIN( inst, _t)& inst = STREAMS_BOOST_JOIN (inst, _t)::instance();

#else

#define STREAMS_BOOST_TEST_SINGLETON_INST( inst ) \
namespace { STREAMS_BOOST_JOIN( inst, _t)& inst = STREAMS_BOOST_JOIN( inst, _t)::instance(); }

#endif

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_TRIVIAL_SIGNLETON_HPP_020505GER
