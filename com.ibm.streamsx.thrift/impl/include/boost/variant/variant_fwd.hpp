//-----------------------------------------------------------------------------
// streams_boost variant/variant_fwd.hpp header file
// See http://www.streams_boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman, Itay Maman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_VARIANT_VARIANT_FWD_HPP
#define STREAMS_BOOST_VARIANT_VARIANT_FWD_HPP

#include "streams_boost/variant/detail/config.hpp"

#include "streams_boost/blank_fwd.hpp"
#include "streams_boost/mpl/arg.hpp"
#include "streams_boost/mpl/limits/arity.hpp"
#include "streams_boost/mpl/aux_/na.hpp"
#include "streams_boost/preprocessor/cat.hpp"
#include "streams_boost/preprocessor/enum.hpp"
#include "streams_boost/preprocessor/enum_params.hpp"
#include "streams_boost/preprocessor/enum_shifted_params.hpp"
#include "streams_boost/preprocessor/repeat.hpp"

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_LIMIT_TYPES
//
// Implementation-defined preprocessor symbol describing the actual
// length of variant's pseudo-variadic template parameter list.
//
#include "streams_boost/mpl/limits/list.hpp"
#define STREAMS_BOOST_VARIANT_LIMIT_TYPES \
    STREAMS_BOOST_MPL_LIMIT_LIST_SIZE

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_NO_REFERENCE_SUPPORT
//
// Defined if variant does not support references as bounded types. 
//
#if defined(STREAMS_BOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING) \
 && !defined(STREAMS_BOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND) \
 && !defined(STREAMS_BOOST_VARIANT_NO_REFERENCE_SUPPORT)
#   define STREAMS_BOOST_VARIANT_NO_REFERENCE_SUPPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT
//
// Defined if variant does not support make_variant_over (see below). 
//
#if defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)
#   define STREAMS_BOOST_VARIANT_NO_TYPE_SEQUENCE_SUPPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT
//
// Defined if make_recursive_variant cannot be supported as documented.
//
// Note: Currently, MPL lambda facility is used as workaround if defined, and
// so only types declared w/ MPL lambda workarounds will work.
//

#include "streams_boost/variant/detail/substitute_fwd.hpp"

#if defined(STREAMS_BOOST_VARIANT_DETAIL_NO_SUBSTITUTE) \
 && !defined(STREAMS_BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT)
#   define STREAMS_BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT
#endif

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_RECURSIVE_VARIANT_MAX_ARITY
//
// Exposes maximum allowed arity of class templates with recursive_variant
// arguments. That is,
//   make_recursive_variant< ..., T<[1], recursive_variant_, ... [N]> >.
//
#include "streams_boost/mpl/limits/arity.hpp"
#define STREAMS_BOOST_VARIANT_RECURSIVE_VARIANT_MAX_ARITY \
    STREAMS_BOOST_MPL_LIMIT_METAFUNCTION_ARITY

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_ENUM_PARAMS
//
// Convenience macro for enumeration of STREAMS_BOOST_VARIANT_LIMIT_TYPES params.
//
// Rationale: Cleaner, simpler code for clients of variant library.
//
#define STREAMS_BOOST_VARIANT_ENUM_PARAMS( param )  \
    STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_VARIANT_LIMIT_TYPES, param)

///////////////////////////////////////////////////////////////////////////////
// macro STREAMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS
//
// Convenience macro for enumeration of STREAMS_BOOST_VARIANT_LIMIT_TYPES-1 params.
//
#define STREAMS_BOOST_VARIANT_ENUM_SHIFTED_PARAMS( param )  \
    STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_VARIANT_LIMIT_TYPES, param)


namespace streams_boost {

namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) class void_ and class template convert_void
// 
// Provides the mechanism by which void(NN) types are converted to
// mpl::void_ (and thus can be passed to mpl::list).
//
// Rationale: This is particularly needed for the using-declarations
// workaround (below), but also to avoid associating mpl namespace with
// variant in argument dependent lookups (which used to happen because of
// defaulting of template parameters to mpl::void_).
//

struct void_;

template <typename T>
struct convert_void
{
    typedef T type;
};

template <>
struct convert_void< void_ >
{
    typedef mpl::na type;
};

///////////////////////////////////////////////////////////////////////////////
// (workaround) STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE
//
// Needed to work around compilers that don't support using-declaration
// overloads. (See the variant::initializer workarounds below.)
//

#if defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

// (detail) tags voidNN -- NN defined on [0, STREAMS_BOOST_VARIANT_LIMIT_TYPES)
//
// Defines void types that are each unique and specializations of
// convert_void that yields mpl::na for each voidNN type.
//

#define STREAMS_BOOST_VARIANT_DETAIL_DEFINE_VOID_N(z,N,_)          \
    struct STREAMS_BOOST_PP_CAT(void,N);                           \
                                                           \
    template <>                                            \
    struct convert_void< STREAMS_BOOST_PP_CAT(void,N) >            \
    {                                                      \
        typedef mpl::na type;                              \
    };                                                     \
    /**/

STREAMS_BOOST_PP_REPEAT(
      STREAMS_BOOST_VARIANT_LIMIT_TYPES
    , STREAMS_BOOST_VARIANT_DETAIL_DEFINE_VOID_N
    , _
    )

#undef STREAMS_BOOST_VARIANT_DETAIL_DEFINE_VOID_N

#endif // STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE workaround

}} // namespace detail::variant

///////////////////////////////////////////////////////////////////////////////
// (detail) macro STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAM
//
// Template parameter list for variant and recursive_variant declarations.
//

#if !defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

#   define STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    typename STREAMS_BOOST_PP_CAT(T,N) = detail::variant::void_ \
    /**/

#else // defined(STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

#   define STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    typename STREAMS_BOOST_PP_CAT(T,N) = STREAMS_BOOST_PP_CAT(detail::variant::void,N) \
    /**/

#endif // STREAMS_BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE workaround

#define STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS \
    STREAMS_BOOST_PP_ENUM( \
          STREAMS_BOOST_VARIANT_LIMIT_TYPES \
        , STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS_IMPL \
        , T \
        ) \
    /**/

///////////////////////////////////////////////////////////////////////////////
// class template variant (concept inspired by Andrei Alexandrescu)
//
// Efficient, type-safe bounded discriminated union.
//
// Preconditions:
//  - Each type must be unique.
//  - No type may be const-qualified.
//
// Proper declaration form:
//   variant<types>    (where types is a type-sequence)
// or
//   variant<T0,T1,...,Tn>  (where T0 is NOT a type-sequence)
//
template < STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS > class variant;

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant
//
// Exposes a streams_boost::variant with recursive_variant_ tags (below) substituted
// with the variant itself (wrapped as needed with streams_boost::recursive_wrapper).
//
template < STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS > struct make_recursive_variant;

#undef STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS_IMPL
#undef STREAMS_BOOST_VARIANT_AUX_DECLARE_PARAMS

///////////////////////////////////////////////////////////////////////////////
// type recursive_variant_
//
// Tag type indicates where recursive variant substitution should occur.
//
#if !defined(STREAMS_BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT)
    struct recursive_variant_;
#else
    typedef mpl::arg<1> recursive_variant_;
#endif

///////////////////////////////////////////////////////////////////////////////
// metafunction make_variant_over
//
// Result is a variant w/ types of the specified type sequence.
//
template <typename Types> struct make_variant_over;

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant_over
//
// Result is a recursive variant w/ types of the specified type sequence.
//
template <typename Types> struct make_recursive_variant_over;

} // namespace streams_boost

#endif // STREAMS_BOOST_VARIANT_VARIANT_FWD_HPP
