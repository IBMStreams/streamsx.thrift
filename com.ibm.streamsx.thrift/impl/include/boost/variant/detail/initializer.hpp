//-----------------------------------------------------------------------------
// streams_boost variant/detail/initializer.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman, Itay Maman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_DETAIL_INITIALIZER_HPP
#define STREAMS_BOOST_VARIANT_DETAIL_INITIALIZER_HPP

#include <new> // for placement new

#include "streams_boost/config.hpp"

#include "streams_boost/call_traits.hpp"
#include "streams_boost/detail/reference_content.hpp"
#include "streams_boost/variant/recursive_wrapper_fwd.hpp"

#if !defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)
#   include "streams_boost/mpl/aux_/value_wknd.hpp"
#   include "streams_boost/mpl/int.hpp"
#   include "streams_boost/mpl/iter_fold.hpp"
#   include "streams_boost/mpl/next.hpp"
#   include "streams_boost/mpl/deref.hpp"
#   include "streams_boost/mpl/pair.hpp"
#   include "streams_boost/mpl/protect.hpp"
#else
#   include "streams_boost/variant/variant_fwd.hpp"
#   include "streams_boost/preprocessor/cat.hpp"
#   include "streams_boost/preprocessor/enum.hpp"
#   include "streams_boost/preprocessor/repeat.hpp"
#endif

namespace streams_boost {
namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) support to simulate standard overload resolution rules
//
// The below initializers allows variant to follow standard overload
// resolution rules over the specified set of bounded types.
//
// On compilers where using declarations in class templates can correctly
// avoid name hiding, use an optimal solution based on the variant's typelist.
//
// Otherwise, use a preprocessor workaround based on knowledge of the fixed
// size of the variant's psuedo-variadic template parameter list.
//

#if !defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

// (detail) quoted metafunction make_initializer_node
//
// Exposes a pair whose first type is a node in the initializer hierarchy.
//
struct make_initializer_node
{
    template <typename BaseIndexPair, typename Iterator>
    struct apply
    {
    private: // helpers, for metafunction result (below)

        typedef typename BaseIndexPair::first
            base;
        typedef typename BaseIndexPair::second
            index;

        class initializer_node
            : public base
        {
        private: // helpers, for static functions (below)

            typedef typename mpl::deref<Iterator>::type
                recursive_enabled_T;
            typedef typename unwrap_recursive<recursive_enabled_T>::type
                public_T;
            typedef typename call_traits<public_T>::param_type
                param_T;

        public: // static functions

            using base::initialize;

            static int initialize(void* dest, param_T operand)
            {
                typedef typename streams_boost::detail::make_reference_content<
                      recursive_enabled_T
                    >::type internal_T;

                new(dest) internal_T(operand);
                return STREAMS_BOOST_MPL_AUX_VALUE_WKND(index)::value; // which
            }

        };

        friend class initializer_node;

    public: // metafunction result

        typedef mpl::pair<
              initializer_node
            , typename mpl::next< index >::type
            > type;

    };
};

// (detail) class initializer_root
//
// Every level of the initializer hierarchy must expose the name
// "initialize," so initializer_root provides a dummy function:
//
class initializer_root
{
public: // static functions

    static void initialize();

};

#else // defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

#   if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) 

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_PARAMS \
          STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename recursive_enabled_T) \
    /**/

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_DEFINE_PARAM_T(N) \
        typedef typename unwrap_recursive< \
              STREAMS_BOOST_PP_CAT(recursive_enabled_T,N) \
            >::type STREAMS_BOOST_PP_CAT(public_T,N); \
        typedef typename call_traits< \
              STREAMS_BOOST_PP_CAT(public_T,N) \
            >::param_type STREAMS_BOOST_PP_CAT(param_T,N); \
    /**/

#   else // MSVC7 and below

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_PARAMS \
          STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename recursive_enabled_T) \
        , STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename param_T) \
    /**/

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_DEFINE_PARAM_T(N) \
    /**/

#   endif // MSVC7 and below workaround

template < STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_PARAMS >
struct preprocessor_list_initializer
{
public: // static functions

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZE_FUNCTION(z,N,_) \
        STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_DEFINE_PARAM_T(N) \
        static int initialize( \
              void* dest \
            , STREAMS_BOOST_PP_CAT(param_T,N) operand \
            ) \
        { \
            typedef typename streams_boost::detail::make_reference_content< \
                  STREAMS_BOOST_PP_CAT(recursive_enabled_T,N) \
                >::type internal_T; \
            \
            new(dest) internal_T(operand); \
            return (N); /*which*/ \
        } \
        /**/

    STREAMS_BOOST_PP_REPEAT(
          STREAMS_BOOST_VARIANT_LIMIT_TYPES
        , STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZE_FUNCTION
        , _
        )

    #undef STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZE_FUNCTION

};

#   if defined(STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG)

#if !defined(STREAMS_BOOST_VARIANT_AUX_ECHO)
#   define STREAMS_BOOST_VARIANT_AUX_ECHO(z,N,token) token
#endif

template <>
struct preprocessor_list_initializer<
      STREAMS_BOOST_PP_ENUM(STREAMS_BOOST_VARIANT_LIMIT_TYPES, STREAMS_BOOST_VARIANT_AUX_ECHO, int)
    , STREAMS_BOOST_PP_ENUM(STREAMS_BOOST_VARIANT_LIMIT_TYPES, STREAMS_BOOST_VARIANT_AUX_ECHO, const int)
    >
{
};

#   endif // STREAMS_BOOST_MPL_CFG_MSVC_60_ETI_BUG workaround

#endif // STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE workaround

}} // namespace detail::variant
} // namespace streams_boost

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_AUX_INITIALIZER_T
//
// Given both the variant's typelist and a basename for forming the list of
// bounded types (i.e., T becomes T1, T2, etc.), exposes the initializer
// most appropriate to the current compiler.
//

#if !defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

#define STREAMS_BOOST_VARIANT_AUX_INITIALIZER_T( mpl_seq, typename_base ) \
    ::streams_boost::mpl::iter_fold< \
          mpl_seq \
        , ::streams_boost::mpl::pair< \
              ::streams_boost::detail::variant::initializer_root \
            , ::streams_boost::mpl::int_<0> \
            > \
        , ::streams_boost::mpl::protect< \
              ::streams_boost::detail::variant::make_initializer_node \
            > \
        >::type::first \
    /**/

#else // defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

#   if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_ARGS(typename_base) \
          STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename_base) \
        /**/

#   else // MSVC7 and below

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_ENUM_PARAM_TYPE(z,N,T) \
        ::streams_boost::call_traits< \
              ::streams_boost::unwrap_recursive<STREAMS_BOOST_PP_CAT(T,N)>::type \
            >::param_type \
        /**/

    #define STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_ARGS(typename_base) \
          STREAMS_BOOST_VARIANT_ENUM_PARAMS(typename_base) \
        , STREAMS_BOOST_PP_ENUM( \
              STREAMS_BOOST_VARIANT_LIMIT_TYPES \
            , STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_ENUM_PARAM_TYPE \
            , typename_base \
            ) \
        /**/

#   endif // MSVC7 workaround

#define STREAMS_BOOST_VARIANT_AUX_INITIALIZER_T( mpl_seq, typename_base ) \
    ::streams_boost::detail::variant::preprocessor_list_initializer< \
          STREAMS_BOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_ARGS(typename_base) \
        > \
    /**/

#endif // STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE workaround

#endif // STREAMS_BOOST_VARIANT_DETAIL_INITIALIZER_HPP
