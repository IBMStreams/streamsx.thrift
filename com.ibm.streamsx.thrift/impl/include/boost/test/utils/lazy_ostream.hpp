//  (C) Copyright Gennadiy Rozental 2008.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision: 49312 $
//
//  Description : contains definition for all test tools in test toolbox
// ***************************************************************************

#ifndef STREAMS_BOOST_TEST_LAZY_OSTREAM_HPP_070708GER
#define STREAMS_BOOST_TEST_LAZY_OSTREAM_HPP_070708GER

// Boost.Test
#include <streams_boost/test/detail/config.hpp>

// STL
#include <iosfwd>

#include <streams_boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

// ************************************************************************** //
// **************                  lazy_ostream                ************** //
// ************************************************************************** //

namespace streams_boost {

namespace unit_test {

class lazy_ostream {
public:
    static lazy_ostream&    instance()                                              { static lazy_ostream inst; return inst; }

    friend std::ostream&    operator<<( std::ostream& ostr, lazy_ostream const& o ) { return o( ostr ); }

    // access method
    bool                    empty() const                                           { return m_empty; }

    // actual printing interface; to be accessed only by this class and children
    virtual std::ostream&   operator()( std::ostream& ostr ) const                  { return ostr; }
protected:
    explicit                lazy_ostream( bool empty = true ) : m_empty( empty )    {}

    // protected destructor to make sure right one is called
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x582))
public:
#endif
    STREAMS_BOOST_TEST_PROTECTED_VIRTUAL ~lazy_ostream()                                    {}

private:
    // Data members
    bool                    m_empty;
};

//____________________________________________________________________________//

template<typename T>
class lazy_ostream_impl : public lazy_ostream {
public:
    lazy_ostream_impl( lazy_ostream const& prev, T value )
    : lazy_ostream( false )
    , m_prev( prev )
    , m_value( value )
    {}
private:
    virtual std::ostream&   operator()( std::ostream& ostr ) const
    {
        return m_prev(ostr) << m_value;
    }

    // Data members
    lazy_ostream const&     m_prev;
    T                       m_value;
};

//____________________________________________________________________________//

template<typename T>
inline lazy_ostream_impl<T const&>
operator<<( lazy_ostream const& prev, T const& v )
{
    return lazy_ostream_impl<T const&>( prev, v );
}

//____________________________________________________________________________//

#if STREAMS_BOOST_TEST_USE_STD_LOCALE

template<typename R,typename S>
inline lazy_ostream_impl<R& (STREAMS_BOOST_TEST_CALL_DECL *)(S&)>
operator<<( lazy_ostream const& prev, R& (STREAMS_BOOST_TEST_CALL_DECL *man)(S&) )
{
    return lazy_ostream_impl<R& (STREAMS_BOOST_TEST_CALL_DECL *)(S&)>( prev, man );
}

//____________________________________________________________________________//

#endif

} // namespace unit_test

} // namespace streams_boost

//____________________________________________________________________________//

#include <streams_boost/test/detail/enable_warnings.hpp>

#endif // STREAMS_BOOST_TEST_LAZY_OSTREAM_HPP_070708GER
