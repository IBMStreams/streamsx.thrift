
#ifndef STREAMS_BOOST_MPL_HAS_XXX_HPP_INCLUDED
#define STREAMS_BOOST_MPL_HAS_XXX_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2006
// Copyright David Abrahams 2002-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: has_xxx.hpp 49273 2008-10-11 06:54:06Z agurtovoy $
// $Date: 2008-10-11 02:54:06 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49273 $

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/aux_/type_wrapper.hpp>
#include <streams_boost/mpl/aux_/yes_no.hpp>
#include <streams_boost/mpl/aux_/config/has_xxx.hpp>
#include <streams_boost/mpl/aux_/config/msvc_typename.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#include <streams_boost/preprocessor/cat.hpp>

#if STREAMS_BOOST_WORKAROUND( __BORLANDC__, STREAMS_BOOST_TESTED_AT(0x590) )
# include <streams_boost/type_traits/is_class.hpp>
#endif

#if !defined(STREAMS_BOOST_MPL_CFG_NO_HAS_XXX)

#   if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

// agurt, 11/sep/02: MSVC-specific version (< 7.1), based on a USENET 
// newsgroup's posting by John Madsen (comp.lang.c++.moderated, 
// 1999-11-12 19:17:06 GMT); the code is _not_ standard-conforming, but 
// it works way more reliably than the SFINAE-based implementation

// Modified dwa 8/Oct/02 to handle reference types.

#   include <streams_boost/mpl/if.hpp>
#   include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace mpl { namespace aux {

struct has_xxx_tag;

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)
template< typename U > struct msvc_incomplete_array
{
    typedef char (&type)[sizeof(U) + 1];
};
#endif

template< typename T >
struct msvc_is_incomplete
{
    // MSVC is capable of some kinds of SFINAE.  If U is an incomplete
    // type, it won't pick the second overload
    static char tester(...);

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)
    template< typename U >
    static typename msvc_incomplete_array<U>::type tester(type_wrapper<U>);
#else
    template< typename U >
    static char (& tester(type_wrapper<U>) )[sizeof(U)+1];
#endif 
    
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = 
          sizeof(tester(type_wrapper<T>())) == 1
        );
};

template<>
struct msvc_is_incomplete<int>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};

}}}

#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, default_) \
template< typename T, typename name = ::streams_boost::mpl::aux::has_xxx_tag > \
struct STREAMS_BOOST_PP_CAT(trait,_impl) : T \
{ \
    static streams_boost::mpl::aux::no_tag \
    test(void(*)(::streams_boost::mpl::aux::has_xxx_tag)); \
    \
    static streams_boost::mpl::aux::yes_tag test(...); \
    \
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = \
          sizeof(test(static_cast<void(*)(name)>(0))) \
            != sizeof(streams_boost::mpl::aux::no_tag) \
        ); \
    typedef streams_boost::mpl::bool_<value> type; \
}; \
\
template< typename T, typename fallback_ = streams_boost::mpl::bool_<default_> > \
struct trait \
    : streams_boost::mpl::if_c< \
          streams_boost::mpl::aux::msvc_is_incomplete<T>::value \
        , streams_boost::mpl::bool_<false> \
        , STREAMS_BOOST_PP_CAT(trait,_impl)<T> \
        >::type \
{ \
}; \
\
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, void) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, bool) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, char) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed char) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned char) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed short) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned short) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed int) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned int) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed long) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned long) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, float) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, double) \
STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, long double) \
/**/

#   define STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, T) \
template<> struct trait<T> \
{ \
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false); \
    typedef streams_boost::mpl::bool_<false> type; \
}; \
/**/

#if !defined(STREAMS_BOOST_NO_INTRINSIC_WCHAR_T)
#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, unused) \
    STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, unused) \
    STREAMS_BOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, wchar_t) \
/**/
#else
#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, unused) \
    STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, unused) \
/**/
#endif


// SFINAE-based implementations below are derived from a USENET newsgroup's 
// posting by Rani Sharoni (comp.lang.c++.moderated, 2002-03-17 07:45:09 PST)

#   elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) \
      || STREAMS_BOOST_WORKAROUND(__IBMCPP__, <= 700)

// MSVC 7.1+ & VACPP

// agurt, 15/jun/05: replace overload-based SFINAE implementation with SFINAE
// applied to partial specialization to fix some apparently random failures 
// (thanks to Daniel Wallin for researching this!)

#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T > \
struct STREAMS_BOOST_PP_CAT(trait, _msvc_sfinae_helper) \
{ \
    typedef void type; \
};\
\
template< typename T, typename U = void > \
struct STREAMS_BOOST_PP_CAT(trait,_impl_) \
{ \
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false); \
    typedef streams_boost::mpl::bool_<value> type; \
}; \
\
template< typename T > \
struct STREAMS_BOOST_PP_CAT(trait,_impl_)< \
      T \
    , typename STREAMS_BOOST_PP_CAT(trait, _msvc_sfinae_helper)< typename T::name >::type \
    > \
{ \
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true); \
    typedef streams_boost::mpl::bool_<value> type; \
}; \
\
template< typename T, typename fallback_ = streams_boost::mpl::bool_<default_> > \
struct trait \
    : STREAMS_BOOST_PP_CAT(trait,_impl_)<T> \
{ \
}; \
/**/

#   elif STREAMS_BOOST_WORKAROUND( __BORLANDC__, STREAMS_BOOST_TESTED_AT(0x590) )

#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_BCB_DEF(trait, trait_tester, name, default_) \
template< typename T, bool IS_CLASS > \
struct trait_tester \
{ \
    STREAMS_BOOST_STATIC_CONSTANT( bool,  value = false ); \
}; \
template< typename T > \
struct trait_tester< T, true > \
{ \
    struct trait_tester_impl \
    { \
        template < class U > \
        static int  resolve( streams_boost::mpl::aux::type_wrapper<U> const volatile * \
                           , streams_boost::mpl::aux::type_wrapper<typename U::name >* = 0 ); \
        static char resolve( ... ); \
    }; \
    typedef streams_boost::mpl::aux::type_wrapper<T> t_; \
    STREAMS_BOOST_STATIC_CONSTANT( bool, value = ( sizeof( trait_tester_impl::resolve( static_cast< t_ * >(0) ) ) == sizeof(int) ) ); \
}; \
template< typename T, typename fallback_ = streams_boost::mpl::bool_<default_> > \
struct trait           \
{                      \
    STREAMS_BOOST_STATIC_CONSTANT( bool, value = (trait_tester< T, streams_boost::is_class< T >::value >::value) );     \
    typedef streams_boost::mpl::bool_< trait< T, fallback_ >::value > type; \
};

#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
    STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_BCB_DEF( trait \
                                         , STREAMS_BOOST_PP_CAT(trait,_tester)      \
                                         , name       \
                                         , default_ ) \
/**/

#   else // other SFINAE-capable compilers

#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T, typename fallback_ = streams_boost::mpl::bool_<default_> > \
struct trait \
{ \
    struct gcc_3_2_wknd \
    { \
        template< typename U > \
        static streams_boost::mpl::aux::yes_tag test( \
              streams_boost::mpl::aux::type_wrapper<U> const volatile* \
            , streams_boost::mpl::aux::type_wrapper<STREAMS_BOOST_MSVC_TYPENAME U::name>* = 0 \
            ); \
    \
        static streams_boost::mpl::aux::no_tag test(...); \
    }; \
    \
    typedef streams_boost::mpl::aux::type_wrapper<T> t_; \
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = \
          sizeof(gcc_3_2_wknd::test(static_cast<t_*>(0))) \
            == sizeof(streams_boost::mpl::aux::yes_tag) \
        ); \
    typedef streams_boost::mpl::bool_<value> type; \
}; \
/**/

#   endif // STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)


#else // STREAMS_BOOST_MPL_CFG_NO_HAS_XXX

// placeholder implementation

#   define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T, typename fallback_ = streams_boost::mpl::bool_<default_> > \
struct trait \
{ \
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = fallback_::value); \
    typedef fallback_ type; \
}; \
/**/

#endif

#define STREAMS_BOOST_MPL_HAS_XXX_TRAIT_DEF(name) \
    STREAMS_BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(STREAMS_BOOST_PP_CAT(has_,name), name, false) \
/**/

#endif // STREAMS_BOOST_MPL_HAS_XXX_HPP_INCLUDED
