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
//  Description : default algorithms for string to specific type convertions
// ***************************************************************************

#ifndef STREAMS_BOOST_RT_INTERPRET_ARGUMENT_VALUE_HPP_062604GER
#define STREAMS_BOOST_RT_INTERPRET_ARGUMENT_VALUE_HPP_062604GER

// Boost.Runtime.Parameter
#include <streams_boost/test/utils/runtime/config.hpp>
#include <streams_boost/test/utils/runtime/trace.hpp>

// Boost.Test
#include <streams_boost/test/utils/basic_cstring/io.hpp>
#include <streams_boost/test/utils/basic_cstring/compare.hpp>

// Boost
#include <streams_boost/optional.hpp>
#include <streams_boost/lexical_cast.hpp>

// STL
// !! could we eliminate these includes?
#include <list>

namespace streams_boost {

namespace STREAMS_BOOST_RT_PARAM_NAMESPACE {

// ************************************************************************** //
// **************       runtime::interpret_argument_value      ************** //
// ************************************************************************** //
// returns true if source is used false otherwise

// generic case
template<typename T>
struct interpret_argument_value_impl {
    static bool _( cstring source, streams_boost::optional<T>& res )
    {
        STREAMS_BOOST_RT_PARAM_TRACE( "In interpret_argument_value_impl<" << typeid(T).name() << ">" );

        res = lexical_cast<T>( source );

        STREAMS_BOOST_RT_PARAM_TRACE( "String " << source << " is interpreted as " << *res );
        return true;
    }
};


//____________________________________________________________________________//

// dstring case
template<>
struct interpret_argument_value_impl<dstring> {
    static bool _( cstring source, streams_boost::optional<dstring>& res )
    {
        STREAMS_BOOST_RT_PARAM_TRACE( "In interpret_argument_value_impl<dstring>" );

        res = dstring();
        assign_op( *res, source, 0 );

        return true;
    }
};

//____________________________________________________________________________//

// cstring case
template<>
struct interpret_argument_value_impl<cstring> {
    static bool _( cstring source, streams_boost::optional<cstring>& res )
    {
        STREAMS_BOOST_RT_PARAM_TRACE( "In interpret_argument_value_impl<cstring>" );

        res = source;

        return true;
    }
};

//____________________________________________________________________________//

// specialization for type bool
template<>
struct interpret_argument_value_impl<bool> {
    static bool _( cstring source, streams_boost::optional<bool>& res )
    {
        STREAMS_BOOST_RT_PARAM_TRACE( "In interpret_argument_value_impl<bool>" );

        static literal_cstring YES( STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "YES" ) );
        static literal_cstring Y( STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "Y" ) );
        static literal_cstring NO( STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "NO" ) );
        static literal_cstring N( STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "N" ) );
        static literal_cstring one( STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "1" ) );
        static literal_cstring zero( STREAMS_BOOST_RT_PARAM_CSTRING_LITERAL( "0" ) );

        source.trim();

        if( case_ins_eq( source, YES ) || case_ins_eq( source, Y ) || case_ins_eq( source, one ) ) {
            res = true;
            return true;
        }
        else if( case_ins_eq( source, NO ) || case_ins_eq( source, N ) || case_ins_eq( source, zero ) ) {
            res = false;
            return true;
        }
        else {
            res = true;
            return false;
        }
    }
};

//____________________________________________________________________________//

template<typename T>
inline bool
interpret_argument_value( cstring source, streams_boost::optional<T>& res, long )
{
    return interpret_argument_value_impl<T>::_( source, res );
}

//____________________________________________________________________________//

// specialization for list of values
template<typename T>
inline bool
interpret_argument_value( cstring source, streams_boost::optional<std::list<T> >& res, int )
{
    STREAMS_BOOST_RT_PARAM_TRACE( "In interpret_argument_value<std::list<T>>" );

    res = std::list<T>();

    while( !source.is_empty() ) {
        // !! should we use token_iterator
        cstring::iterator single_value_end = std::find( source.begin(), source.end(), STREAMS_BOOST_RT_PARAM_LITERAL( ',' ) );

        streams_boost::optional<T> value;
        interpret_argument_value( cstring( source.begin(), single_value_end ), value, 0 );

        res->push_back( *value );

        source.trim_left( single_value_end + 1 );
    }

    return true;
}

//____________________________________________________________________________//

} // namespace STREAMS_BOOST_RT_PARAM_NAMESPACE

} // namespace streams_boost

#endif // STREAMS_BOOST_RT_INTERPRET_ARGUMENT_VALUE_HPP_062604GER
