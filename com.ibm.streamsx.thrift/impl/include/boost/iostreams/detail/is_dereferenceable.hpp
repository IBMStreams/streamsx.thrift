// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2005-2007 Jonathan Turkanis
// (C) Copyright David Abrahams 2004.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

#ifndef STREAMS_BOOST_IOSTREAMS_DETAIL_IS_DEREFERENCEABLE_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_DETAIL_IS_DEREFERENCEABLE_HPP_INCLUDED

# include <streams_boost/type_traits/detail/bool_trait_def.hpp>
# include <streams_boost/type_traits/detail/template_arity_spec.hpp>
# include <streams_boost/type_traits/remove_cv.hpp>
# include <streams_boost/mpl/aux_/lambda_support.hpp>
# include <streams_boost/mpl/bool.hpp>
# include <streams_boost/detail/workaround.hpp>

namespace streams_boost { namespace iostreams { namespace detail { 

// is_dereferenceable<T> metafunction
//
// Requires: Given x of type T&, if the expression *x is well-formed
// it must have complete type; otherwise, it must neither be ambiguous
// nor violate access.

// This namespace ensures that ADL doesn't mess things up.
namespace is_dereferenceable_
{
  // a type returned from operator* when no increment is found in the
  // type's own namespace
  struct tag {};
  
  // any soaks up implicit conversions and makes the following
  // operator* less-preferred than any other such operator that
  // might be found via ADL.
  struct any { template <class T> any(T const&); };

  // This is a last-resort operator* for when none other is found
  tag operator*(any const&);

# if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3202)) \
    || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
#  define STREAMS_BOOST_comma(a,b) (a)
# else 
  // In case an operator++ is found that returns void, we'll use ++x,0
  tag operator,(tag,int);  
#  define STREAMS_BOOST_comma(a,b) (a,b)
# endif 
  
  // two check overloads help us identify which operator++ was picked
  char (& check STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(tag) )[2];
  
  template <class T>
  char check STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(T const&);
  
  template <class T>
  struct impl
  {
      static typename streams_boost::remove_cv<T>::type& x;

      STREAMS_BOOST_STATIC_CONSTANT(
          bool
        , value = sizeof(is_dereferenceable_::check STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION(STREAMS_BOOST_comma(*x,0))) == 1
      );
  };
}

# undef STREAMS_BOOST_comma

template<typename T> 
struct is_dereferenceable 
    STREAMS_BOOST_TT_AUX_BOOL_C_BASE(is_dereferenceable_::impl<T>::value)
{ 
    STREAMS_BOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(is_dereferenceable_::impl<T>::value)
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(1,is_dereferenceable,(T))
};

} } 

STREAMS_BOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1, ::streams_boost::iostreams::detail::is_dereferenceable)

} // End namespaces detail, iostreams, streams_boost.

#endif // STREAMS_BOOST_IOSTREAMS_DETAIL_IS_DEREFERENCEABLE_HPP_INCLUDED
