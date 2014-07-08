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

#ifndef STREAMS_BOOST_TEST_CUSTOM_MANIP_HPP_071894GER
#define STREAMS_BOOST_TEST_CUSTOM_MANIP_HPP_071894GER

// STL
#include <iosfwd>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace streams_boost {

namespace unit_test {

// ************************************************************************** //
// **************          custom manipulators helpers         ************** //
// ************************************************************************** //

template<typename Manip>
struct custom_printer {
    explicit custom_printer( std::ostream& ostr ) : m_ostr( &ostr ) {}

    std::ostream& operator*() const { return *m_ostr; }

private:
    std::ostream* const m_ostr;
};

//____________________________________________________________________________//

template<typename Uniq> struct custom_manip {};

//____________________________________________________________________________//

template<typename Uniq>
inline custom_printer<custom_manip<Uniq> >
operator<<( std::ostream& ostr, custom_manip<Uniq> const& ) { return custom_printer<custom_manip<Uniq> >( ostr ); }

//____________________________________________________________________________//

} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_CUSTOM_MANIP_HPP_071894GER
