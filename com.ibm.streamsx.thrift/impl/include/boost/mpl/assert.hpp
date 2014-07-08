
#ifndef STREAMS_BOOST_MPL_ASSERT_HPP_INCLUDED
#define STREAMS_BOOST_MPL_ASSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: assert.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-11 02:19:02 -0400 (Sat, 11 Oct 2008) $
// $Revision: 49267 $

#include <streams_boost/mpl/not.hpp>
#include <streams_boost/mpl/aux_/value_wknd.hpp>
#include <streams_boost/mpl/aux_/nested_type_wknd.hpp>
#include <streams_boost/mpl/aux_/yes_no.hpp>
#include <streams_boost/mpl/aux_/na.hpp>
#include <streams_boost/mpl/aux_/adl_barrier.hpp>

#include <streams_boost/mpl/aux_/config/nttp.hpp>
#include <streams_boost/mpl/aux_/config/dtp.hpp>
#include <streams_boost/mpl/aux_/config/gcc.hpp>
#include <streams_boost/mpl/aux_/config/msvc.hpp>
#include <streams_boost/mpl/aux_/config/static_constant.hpp>
#include <streams_boost/mpl/aux_/config/pp_counter.hpp>
#include <streams_boost/mpl/aux_/config/workaround.hpp>

#include <streams_boost/preprocessor/cat.hpp>

#include <streams_boost/config.hpp> // make sure 'size_t' is placed into 'std'
#include <cstddef>


#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610)) \
    || (STREAMS_BOOST_MPL_CFG_GCC != 0) \
    || STREAMS_BOOST_WORKAROUND(__IBMCPP__, <= 600)
#   define STREAMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES
#endif

#if STREAMS_BOOST_WORKAROUND(__MWERKS__, < 0x3202) \
    || STREAMS_BOOST_WORKAROUND(__EDG_VERSION__, <= 238) \
    || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610)) \
    || STREAMS_BOOST_WORKAROUND(__DMC__, STREAMS_BOOST_TESTED_AT(0x840))
#   define STREAMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER
#endif

// agurt, 10/nov/06: use enums for Borland (which cannot cope with static constants) 
// and GCC (which issues "unused variable" warnings when static constants are used 
// at a function scope)
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x610)) \
    || (STREAMS_BOOST_MPL_CFG_GCC != 0)
#   define STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT(T, expr) enum { expr }
#else
#   define STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT(T, expr) STREAMS_BOOST_STATIC_CONSTANT(T, expr)
#endif


STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

struct failed {};

// agurt, 24/aug/04: MSVC 7.1 workaround here and below: return/accept 
// 'assert<false>' by reference; can't apply it unconditionally -- apparently it
// degrades the quality of GCC diagnostics
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1310)
#   define AUX778076_ASSERT_ARG(x) x&
#else
#   define AUX778076_ASSERT_ARG(x) x
#endif

template< bool C >  struct assert        { typedef void* type; };
template<>          struct assert<false> { typedef AUX778076_ASSERT_ARG(assert) type; };

template< bool C >
int assertion_failed( typename assert<C>::type );

template< bool C >
struct assertion
{
    static int failed( assert<false> );
};

template<>
struct assertion<true>
{
    static int failed( void* );
};

struct assert_
{
#if !defined(STREAMS_BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
    template< typename T1, typename T2 = na, typename T3 = na, typename T4 = na > struct types {};
#endif
    static assert_ const arg;
    enum relations { equal = 1, not_equal, greater, greater_equal, less, less_equal };
};


#if !defined(STREAMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)

bool operator==( failed, failed );
bool operator!=( failed, failed );
bool operator>( failed, failed );
bool operator>=( failed, failed );
bool operator<( failed, failed );
bool operator<=( failed, failed );

#if defined(__EDG_VERSION__)
template< bool (*)(failed, failed), long x, long y > struct assert_relation {};
#   define STREAMS_BOOST_MPL_AUX_ASSERT_RELATION(x, y, r) assert_relation<r,x,y>
#else
template< STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, x), STREAMS_BOOST_MPL_AUX_NTTP_DECL(long, y), bool (*)(failed, failed) > 
struct assert_relation {};
#   define STREAMS_BOOST_MPL_AUX_ASSERT_RELATION(x, y, r) assert_relation<x,y,r>
#endif

#else // STREAMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES

streams_boost::mpl::aux::weighted_tag<1>::type operator==( assert_, assert_ );
streams_boost::mpl::aux::weighted_tag<2>::type operator!=( assert_, assert_ );
streams_boost::mpl::aux::weighted_tag<3>::type operator>(  assert_, assert_ );
streams_boost::mpl::aux::weighted_tag<4>::type operator>=( assert_, assert_ );
streams_boost::mpl::aux::weighted_tag<5>::type operator<( assert_, assert_ );
streams_boost::mpl::aux::weighted_tag<6>::type operator<=( assert_, assert_ );

template< assert_::relations r, long x, long y > struct assert_relation {};

#endif 


#if !defined(STREAMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)

template< bool > struct assert_arg_pred_impl { typedef int type; };
template<> struct assert_arg_pred_impl<true> { typedef void* type; };

template< typename P > struct assert_arg_pred
{
    typedef typename P::type p_type;
    typedef typename assert_arg_pred_impl< p_type::value >::type type;
};

template< typename P > struct assert_arg_pred_not
{
    typedef typename P::type p_type;
    STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( bool, p = !p_type::value );
    typedef typename assert_arg_pred_impl<p>::type type;
};

template< typename Pred >
failed ************ (Pred::************ 
      assert_arg( void (*)(Pred), typename assert_arg_pred<Pred>::type )
    );

template< typename Pred >
failed ************ (streams_boost::mpl::not_<Pred>::************ 
      assert_not_arg( void (*)(Pred), typename assert_arg_pred_not<Pred>::type )
    );

template< typename Pred >
AUX778076_ASSERT_ARG(assert<false>)
assert_arg( void (*)(Pred), typename assert_arg_pred_not<Pred>::type );

template< typename Pred >
AUX778076_ASSERT_ARG(assert<false>)
assert_not_arg( void (*)(Pred), typename assert_arg_pred<Pred>::type );


#else // STREAMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER
        
template< bool c, typename Pred > struct assert_arg_type_impl
{
    typedef failed      ************ Pred::* mwcw83_wknd;
    typedef mwcw83_wknd ************* type;
};

template< typename Pred > struct assert_arg_type_impl<true,Pred>
{
    typedef AUX778076_ASSERT_ARG(assert<false>) type;
};

template< typename Pred > struct assert_arg_type
    : assert_arg_type_impl< STREAMS_BOOST_MPL_AUX_VALUE_WKND(STREAMS_BOOST_MPL_AUX_NESTED_TYPE_WKND(Pred))::value, Pred >
{
};

template< typename Pred >
typename assert_arg_type<Pred>::type 
assert_arg(void (*)(Pred), int);

template< typename Pred >
typename assert_arg_type< streams_boost::mpl::not_<Pred> >::type 
assert_not_arg(void (*)(Pred), int);

#   if !defined(STREAMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)
template< long x, long y, bool (*r)(failed, failed) >
typename assert_arg_type_impl< false,STREAMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,r) >::type
assert_rel_arg( STREAMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,r) );
#   else
template< assert_::relations r, long x, long y >
typename assert_arg_type_impl< false,assert_relation<r,x,y> >::type
assert_rel_arg( assert_relation<r,x,y> );
#   endif

#endif // STREAMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER

#undef AUX778076_ASSERT_ARG

STREAMS_BOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE


// STREAMS_BOOST_MPL_ASSERT((pred<x,...>))

#define STREAMS_BOOST_MPL_ASSERT(pred) \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,STREAMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          streams_boost::mpl::assertion_failed<false>( \
              streams_boost::mpl::assert_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
    ) \
/**/

// STREAMS_BOOST_MPL_ASSERT_NOT((pred<x,...>))

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
#   define STREAMS_BOOST_MPL_ASSERT_NOT(pred) \
enum { \
      STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,STREAMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          streams_boost::mpl::assertion<false>::failed( \
              streams_boost::mpl::assert_not_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
}\
/**/
#else
#   define STREAMS_BOOST_MPL_ASSERT_NOT(pred) \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,STREAMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          streams_boost::mpl::assertion_failed<false>( \
              streams_boost::mpl::assert_not_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
   ) \
/**/
#endif

// STREAMS_BOOST_MPL_ASSERT_RELATION(x, ==|!=|<=|<|>=|>, y)

#if defined(STREAMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)

#   if !defined(STREAMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)
// agurt, 9/nov/06: 'enum' below is a workaround for gcc 4.0.4/4.1.1 bugs #29522 and #29518
#   define STREAMS_BOOST_MPL_ASSERT_RELATION_IMPL(counter, x, rel, y)      \
enum { STREAMS_BOOST_PP_CAT(mpl_assert_rel_value,counter) = (x rel y) }; \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        streams_boost::mpl::assertion_failed<STREAMS_BOOST_PP_CAT(mpl_assert_rel_value,counter)>( \
            (streams_boost::mpl::failed ************ ( streams_boost::mpl::assert_relation< \
                  streams_boost::mpl::assert_::relations( sizeof( \
                      streams_boost::mpl::assert_::arg rel streams_boost::mpl::assert_::arg \
                    ) ) \
                , x \
                , y \
                >::************)) 0 ) \
        ) \
    ) \
/**/
#   else
#   define STREAMS_BOOST_MPL_ASSERT_RELATION_IMPL(counter, x, rel, y)    \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assert_rel,counter) = sizeof( \
          streams_boost::mpl::assert_::arg rel streams_boost::mpl::assert_::arg \
        ) \
    ); \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( bool, STREAMS_BOOST_PP_CAT(mpl_assert_rel_value,counter) = (x rel y) ); \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        streams_boost::mpl::assertion_failed<STREAMS_BOOST_PP_CAT(mpl_assert_rel_value,counter)>( \
              streams_boost::mpl::assert_rel_arg( streams_boost::mpl::assert_relation< \
                  streams_boost::mpl::assert_::relations(STREAMS_BOOST_PP_CAT(mpl_assert_rel,counter)) \
                , x \
                , y \
                >() ) \
            ) \
        ) \
    ) \
/**/
#   endif

#   define STREAMS_BOOST_MPL_ASSERT_RELATION(x, rel, y) \
STREAMS_BOOST_MPL_ASSERT_RELATION_IMPL(STREAMS_BOOST_MPL_AUX_PP_COUNTER(), x, rel, y) \
/**/

#else // !STREAMS_BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES

#   if defined(STREAMS_BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)
#   define STREAMS_BOOST_MPL_ASSERT_RELATION(x, rel, y) \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,STREAMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
        streams_boost::mpl::assertion_failed<(x rel y)>( streams_boost::mpl::assert_rel_arg( \
              streams_boost::mpl::STREAMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,(&streams_boost::mpl::operator rel))() \
            ) ) \
        ) \
    ) \
/**/
#   else
#   define STREAMS_BOOST_MPL_ASSERT_RELATION(x, rel, y) \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,STREAMS_BOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
        streams_boost::mpl::assertion_failed<(x rel y)>( (streams_boost::mpl::failed ************ ( \
            streams_boost::mpl::STREAMS_BOOST_MPL_AUX_ASSERT_RELATION(x,y,(&streams_boost::mpl::operator rel))::************))0 ) \
        ) \
    ) \
/**/
#   endif

#endif


// STREAMS_BOOST_MPL_ASSERT_MSG( (pred<x,...>::value), USER_PROVIDED_MESSAGE, (types<x,...>) ) 

#if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3202))
#   define STREAMS_BOOST_MPL_ASSERT_MSG_IMPL( counter, c, msg, types_ ) \
struct msg; \
typedef struct STREAMS_BOOST_PP_CAT(msg,counter) : streams_boost::mpl::assert_ \
{ \
    using streams_boost::mpl::assert_::types; \
    static streams_boost::mpl::failed ************ (msg::************ assert_arg()) types_ \
    { return 0; } \
} STREAMS_BOOST_PP_CAT(mpl_assert_arg,counter); \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        streams_boost::mpl::assertion<(c)>::failed( STREAMS_BOOST_PP_CAT(mpl_assert_arg,counter)::assert_arg() ) \
        ) \
    ) \
/**/
#else
#   define STREAMS_BOOST_MPL_ASSERT_MSG_IMPL( counter, c, msg, types_ )  \
struct msg; \
typedef struct STREAMS_BOOST_PP_CAT(msg,counter) : streams_boost::mpl::assert_ \
{ \
    static streams_boost::mpl::failed ************ (msg::************ assert_arg()) types_ \
    { return 0; } \
} STREAMS_BOOST_PP_CAT(mpl_assert_arg,counter); \
STREAMS_BOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , STREAMS_BOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        streams_boost::mpl::assertion_failed<(c)>( STREAMS_BOOST_PP_CAT(mpl_assert_arg,counter)::assert_arg() ) \
        ) \
    ) \
/**/
#endif

#define STREAMS_BOOST_MPL_ASSERT_MSG( c, msg, types_ ) \
STREAMS_BOOST_MPL_ASSERT_MSG_IMPL( STREAMS_BOOST_MPL_AUX_PP_COUNTER(), c, msg, types_ ) \
/**/

#endif // STREAMS_BOOST_MPL_ASSERT_HPP_INCLUDED
