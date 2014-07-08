// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Contains the definition of the class template access_control, which
// allows the type of inheritance from a provided base class to be specified 
// using a template parameter.


#ifndef STREAMS_BOOST_IOSTREAMS_ACCESS_CONTROL_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_ACCESS_CONTROL_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/iostreams/detail/select.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace iostreams {

struct protected_ { };  // Represents protected inheritance.
struct public_ { };     // Represents public inheritance.


namespace detail {

    // Implements protected inheritance.
    template<typename U>
    struct prot_ : protected U 
    { 
        prot_() { }
        template<typename V> prot_(V v) : U(v) { }
    };

    // Implements public inheritance.
    template<typename U> struct pub_ : public U { 
        pub_() { }
        template<typename V> pub_(V v) : U(v) { }
    };

//
// Used to deduce the base type for the template access_control.
//
template<typename T, typename Access>
struct access_control_base {
    typedef int                                 bad_access_specifier;
    typedef typename 
            iostreams::select<  // Disambiguation for Tru64
                ::streams_boost::is_same<
                    Access, protected_
                >,                              prot_<T>,
                ::streams_boost::is_same<
                    Access, public_
                >,                              pub_<T>,
                else_,                          bad_access_specifier
            >::type                             type;
};

} // End namespace detail.

//
// Template name: access_control.
// Description: Allows the type of inheritance from a provided base class
//      to be specified using an int template parameter.
// Template parameters:
//      Base - The class from which to inherit (indirectly.)
//      Access - The type of access desired. Must be one of the 
//          values access_base::prot or access_base::pub.
//
template< typename T, typename Access,
          typename Base = // VC6 workaraound (Compiler Error C2516)
              typename detail::access_control_base<T, Access>::type >
struct access_control : public Base { 
    access_control() { }
    template<typename U> explicit access_control(U u) : Base(u) { }
};

//----------------------------------------------------------------------------//

} } // End namespaces iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_ACCESS_CONTROL_HPP_INCLUDED
