// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_DISPATCH_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_DISPATCH_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <streams_boost/config.hpp>                   // STREAMS_BOOST_DEDUCED_TYPENAME. 
#include <streams_boost/iostreams/detail/select.hpp>
#include <streams_boost/iostreams/traits.hpp>         // category_of. 
#include <streams_boost/mpl/void.hpp>          
#include <streams_boost/type_traits/is_convertible.hpp>         

namespace streams_boost { namespace iostreams {namespace detail {
    
template< typename T, typename Tag1, typename Tag2,
          typename Tag3 = mpl::void_, typename Tag4 = mpl::void_,
          typename Tag5 = mpl::void_, typename Tag6 = mpl::void_,
          typename Category = 
              STREAMS_BOOST_DEDUCED_TYPENAME category_of<T>::type >
struct dispatch 
    : iostreams::select<  // Disambiguation for Tru64.
          is_convertible<Category, Tag1>, Tag1,
          is_convertible<Category, Tag2>, Tag2,
          is_convertible<Category, Tag3>, Tag3,
          is_convertible<Category, Tag4>, Tag4,
          is_convertible<Category, Tag5>, Tag5,
          is_convertible<Category, Tag6>, Tag6
      >
    { };

} } } // End namespaces detail, iostreams, streams_boost.

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_DISPATCH_HPP_INCLUDED
