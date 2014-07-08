//  (C) Copyright Daniel Frey and Robert Ramey 2009.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.
 
#ifndef STREAMS_BOOST_TT_IS_VIRTUAL_BASE_OF_HPP_INCLUDED
#define STREAMS_BOOST_TT_IS_VIRTUAL_BASE_OF_HPP_INCLUDED

#include <streams_boost/type_traits/is_base_of.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/not.hpp>

// should be the last #include
#include <streams_boost/type_traits/detail/bool_trait_def.hpp>

namespace streams_boost {
namespace detail {


#ifdef STREAMS_BOOST_MSVC
#pragma warning( push )
#pragma warning( disable : 4584 )
#elif defined __GNUC__
#pragma GCC system_header
#endif

template<typename Base, typename Derived, typename tag>
struct is_virtual_base_of_impl
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

template<typename Base, typename Derived>
struct is_virtual_base_of_impl<Base, Derived, mpl::true_>
{
#ifdef __BORLANDC__
    struct X : public virtual Derived, public virtual Base 
    {
       X();
       X(const X&);
       X& operator=(const X&);
       ~X()throw();
    };
    struct Y : public virtual Derived 
    {
       Y();
       Y(const Y&);
       Y& operator=(const Y&);
       ~Y()throw();
    };
#else
    struct X : Derived, virtual Base 
    {
       X();
       X(const X&);
       X& operator=(const X&);
       ~X()throw();
    };
    struct Y : Derived 
    {
       Y();
       Y(const Y&);
       Y& operator=(const Y&);
       ~Y()throw();
    };
#endif
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = (sizeof(X)==sizeof(Y)));
};

template<typename Base, typename Derived>
struct is_virtual_base_of_impl2
{
   typedef typename mpl::and_<is_base_of<Base, Derived>, mpl::not_<is_same<Base, Derived> > >::type tag_type;
   typedef is_virtual_base_of_impl<Base, Derived, tag_type> imp;
   STREAMS_BOOST_STATIC_CONSTANT(bool, value = imp::value);
};

#ifdef STREAMS_BOOST_MSVC
#pragma warning( pop )
#endif

} // namespace detail

STREAMS_BOOST_TT_AUX_BOOL_TRAIT_DEF2(
      is_virtual_base_of
       , Base
       , Derived
       , (::streams_boost::detail::is_virtual_base_of_impl2<Base,Derived>::value) 
)

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_virtual_base_of,Base&,Derived,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_virtual_base_of,Base,Derived&,false)
STREAMS_BOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(typename Base,typename Derived,is_virtual_base_of,Base&,Derived&,false)
#endif

} // namespace streams_boost

#include <streams_boost/type_traits/detail/bool_trait_undef.hpp>

#endif
