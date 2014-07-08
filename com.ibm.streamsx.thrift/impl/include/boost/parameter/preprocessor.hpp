// Copyright Daniel Wallin 2006. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_PREPROCESSOR_060206_HPP
# define STREAMS_BOOST_PARAMETER_PREPROCESSOR_060206_HPP

# include <streams_boost/parameter/parameters.hpp>
# include <streams_boost/parameter/binding.hpp>
# include <streams_boost/parameter/match.hpp>

# include <streams_boost/parameter/aux_/parenthesized_type.hpp>
# include <streams_boost/parameter/aux_/cast.hpp>
# include <streams_boost/parameter/aux_/preprocessor/flatten.hpp>

# include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
# include <streams_boost/preprocessor/control/if.hpp>
# include <streams_boost/preprocessor/control/expr_if.hpp>
# include <streams_boost/preprocessor/repetition/enum_params.hpp>
# include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
# include <streams_boost/preprocessor/repetition/enum_trailing.hpp>
# include <streams_boost/preprocessor/seq/first_n.hpp>
# include <streams_boost/preprocessor/seq/for_each_product.hpp>
# include <streams_boost/preprocessor/seq/for_each_i.hpp> 
# include <streams_boost/preprocessor/tuple/elem.hpp> 
# include <streams_boost/preprocessor/seq/fold_left.hpp>
# include <streams_boost/preprocessor/seq/size.hpp>
# include <streams_boost/preprocessor/seq/enum.hpp>

# include <streams_boost/preprocessor/detail/is_nullary.hpp>

# include <streams_boost/mpl/always.hpp>
# include <streams_boost/mpl/apply_wrap.hpp>

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
#  include <streams_boost/type.hpp>
# endif

namespace streams_boost { namespace parameter { namespace aux {

#  if ! defined(STREAMS_BOOST_NO_SFINAE) && ! STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x592))

// Given Match, which is "void x" where x is an argument matching
// criterion, extract a corresponding MPL predicate.
template <class Match>
struct unwrap_predicate;

// Match anything
template <>
struct unwrap_predicate<void*>
{
    typedef mpl::always<mpl::true_> type;
};

#if STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x580))

typedef void* voidstar;

// A matching predicate is explicitly specified
template <class Predicate>
struct unwrap_predicate<voidstar (Predicate)>
{
    typedef Predicate type;
};

#else

// A matching predicate is explicitly specified
template <class Predicate>
struct unwrap_predicate<void *(Predicate)>
{
    typedef Predicate type;
};

#endif 


// A type to which the argument is supposed to be convertible is
// specified
template <class Target>
struct unwrap_predicate<void (Target)>
{
    typedef is_convertible<mpl::_, Target> type;
};

// Recast the ParameterSpec's nested match metafunction as a free metafunction
template <
    class Parameters
  , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
        STREAMS_BOOST_PARAMETER_MAX_ARITY, class A, = streams_boost::parameter::void_ STREAMS_BOOST_PP_INTERCEPT
    )
>
struct match
  : Parameters::template match<
        STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PARAMETER_MAX_ARITY, A)
    >
{};
# endif 

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)

// Function template argument deduction does many of the same things
// as type matching during partial specialization, so we call a
// function template to "store" T into the type memory addressed by
// void(*)(T).
template <class T>
msvc_store_type<T,void*(*)(void**(T))>
msvc_store_predicate_type(void*(*)(void**(T)));

template <class T>
msvc_store_type<streams_boost::is_convertible<mpl::_,T>,void*(*)(void*(T))>
msvc_store_predicate_type(void*(*)(void*(T)));

template <class FunctionType>
struct unwrap_predicate
{
    static FunctionType f;

    // We don't want the function to be evaluated, just instantiated,
    // so protect it inside of sizeof.
    enum { dummy = sizeof(msvc_store_predicate_type(f)) };

    // Now pull the type out of the instantiated base class
    typedef typename msvc_type_memory<FunctionType>::storage::type type;
};

template <>
struct unwrap_predicate<void*(*)(void**)>
{
    typedef mpl::always<mpl::true_> type;
};

# endif

# undef false_

template <
    class Parameters
  , STREAMS_BOOST_PP_ENUM_BINARY_PARAMS(
        STREAMS_BOOST_PARAMETER_MAX_ARITY, class A, = streams_boost::parameter::void_ STREAMS_BOOST_PP_INTERCEPT
    )
>
struct argument_pack
{
    typedef typename make_arg_list<
        typename STREAMS_BOOST_PARAMETER_build_arg_list(
            STREAMS_BOOST_PARAMETER_MAX_ARITY, make_items, typename Parameters::parameter_spec, A
        )::type
      , typename Parameters::deduced_list
      , tag_keyword_arg
      , mpl::false_
    >::type result;
    typedef typename mpl::first<result>::type type;
};

# if 1 //STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
// Works around VC6 problem where it won't accept rvalues.
template <class T>
T& as_lvalue(T& value, long)
{
    return value;
}

template <class T>
T const& as_lvalue(T const& value, int)
{
    return value;
}
# endif


# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) \
  || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))

template <class Predicate, class T, class Args>
struct apply_predicate
{
    STREAMS_BOOST_MPL_ASSERT((
        mpl::and_<mpl::false_,T>
    ));

    typedef typename mpl::if_<
        typename mpl::apply2<Predicate,T,Args>::type
      , char
      , int
    >::type type;
};

template <class P>
struct funptr_predicate
{
    static P p;

    template <class T, class Args, class P0>
    static typename apply_predicate<P0,T,Args>::type
    check_predicate(type<T>, Args*, void**(*)(P0));

    template <class T, class Args, class P0>
    static typename mpl::if_<
        is_convertible<T,P0>
      , char
      , int
     >::type check_predicate(type<T>, Args*, void*(*)(P0));

    template <class T, class Args>
    struct apply
    {
        STREAMS_BOOST_STATIC_CONSTANT(bool, result = 
            sizeof(check_predicate(streams_boost::type<T>(), (Args*)0, &p)) == 1
        );

        typedef mpl::bool_<apply<T,Args>::result> type;
    };
};

template <>
struct funptr_predicate<void**>
  : mpl::always<mpl::true_>
{};

# endif

}}} // namespace streams_boost::parameter::aux

# if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
// From Paul Mensonides
#  define STREAMS_BOOST_PARAMETER_IS_NULLARY(x) \
    STREAMS_BOOST_PP_SPLIT(1, STREAMS_BOOST_PARAMETER_IS_NULLARY_C x STREAMS_BOOST_PP_COMMA() 0) \
    /**/
#  define STREAMS_BOOST_PARAMETER_IS_NULLARY_C() \
    ~, 1 STREAMS_BOOST_PP_RPAREN() \
    STREAMS_BOOST_PP_TUPLE_EAT(2) STREAMS_BOOST_PP_LPAREN() ~ \
    /**/
# else
#  define STREAMS_BOOST_PARAMETER_IS_NULLARY(x) STREAMS_BOOST_PP_IS_NULLARY(x)
# endif

# define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_CHECK_STATIC_static ()
# define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_IS_STATIC(name) \
    STREAMS_BOOST_PARAMETER_IS_NULLARY( \
        STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_CHECK_STATIC_,name) \
    )

# if !defined(STREAMS_BOOST_MSVC)
#  define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC_static
#  define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC(name) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC_, name)
# else
// Workaround for MSVC preprocessor.
//
// When stripping static from "static f", msvc will produce
// " f". The leading whitespace doesn't go away when pasting
// the token with something else, so this thing is a hack to
// strip the whitespace.
#  define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC_static (
#  define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC_AUX(name) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC_, name))
#  define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC(name) \
    STREAMS_BOOST_PP_SEQ_HEAD( \
        STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC_AUX(name) \
    )
# endif

# define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STATIC(name) \
    STREAMS_BOOST_PP_EXPR_IF( \
        STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_IS_STATIC(name) \
      , static \
    )

# define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(name) \
    STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_IS_STATIC(name) \
      , STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STRIP_STATIC \
      , name STREAMS_BOOST_PP_TUPLE_EAT(1) \
    )(name)

// Calculates [begin, end) arity range.

# define STREAMS_BOOST_PARAMETER_ARITY_RANGE_M_optional(state) state
# define STREAMS_BOOST_PARAMETER_ARITY_RANGE_M_deduced_optional(state) state
# define STREAMS_BOOST_PARAMETER_ARITY_RANGE_M_required(state) STREAMS_BOOST_PP_INC(state)
# define STREAMS_BOOST_PARAMETER_ARITY_RANGE_M_deduced_required(state) STREAMS_BOOST_PP_INC(state)

# define STREAMS_BOOST_PARAMETER_ARITY_RANGE_M(s, state, x) \
    STREAMS_BOOST_PP_CAT( \
        STREAMS_BOOST_PARAMETER_ARITY_RANGE_M_ \
      , STREAMS_BOOST_PARAMETER_FN_ARG_QUALIFIER(x) \
    )(state)
/**/

# define STREAMS_BOOST_PARAMETER_ARITY_RANGE(args) \
    ( \
        STREAMS_BOOST_PP_SEQ_FOLD_LEFT(STREAMS_BOOST_PARAMETER_ARITY_RANGE_M, 0, args) \
      , STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_SEQ_SIZE(args)) \
    )
/**/

// Accessor macros for the argument specs tuple.
# define STREAMS_BOOST_PARAMETER_FN_ARG_QUALIFIER(x) \
    STREAMS_BOOST_PP_TUPLE_ELEM(4,0,x)
/**/

# define STREAMS_BOOST_PARAMETER_FN_ARG_NAME(x) \
    STREAMS_BOOST_PP_TUPLE_ELEM(4,1,x)
/**/

# define STREAMS_BOOST_PARAMETER_FN_ARG_PRED(x) \
    STREAMS_BOOST_PP_TUPLE_ELEM(4,2,x)
/**/

# define STREAMS_BOOST_PARAMETER_FN_ARG_DEFAULT(x) \
    STREAMS_BOOST_PP_TUPLE_ELEM(4,3,x)
/**/

# define STREAMS_BOOST_PARAMETETER_FUNCTION_EAT_KEYWORD_QUALIFIER_out(x)
# define STREAMS_BOOST_PARAMETETER_FUNCTION_EAT_KEYWORD_QUALIFIER_in_out(x)

// Returns 1 if x is either "out(k)" or "in_out(k)".
# define STREAMS_BOOST_PARAMETER_FUNCTION_IS_KEYWORD_QUALIFIER(x) \
    STREAMS_BOOST_PP_IS_EMPTY( \
        STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETETER_FUNCTION_EAT_KEYWORD_QUALIFIER_, x) \
    ) \
/**/

# define STREAMS_BOOST_PARAMETETER_FUNCTION_GET_KEYWORD_QUALIFIER_out(x) x
# define STREAMS_BOOST_PARAMETETER_FUNCTION_GET_KEYWORD_QUALIFIER_in_out(x) x
# define STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD_GET(x) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PARAMETETER_FUNCTION_GET_KEYWORD_QUALIFIER_, x)
/**/

// Returns the keyword of x, where x is either a keyword qualifier
// or a keyword.
//
//   k => k
//   out(k) => k
//   in_out(k) => k
//
# define STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD(x) \
    STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PARAMETER_FUNCTION_IS_KEYWORD_QUALIFIER(x) \
      , STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD_GET \
      , x STREAMS_BOOST_PP_TUPLE_EAT(1) \
    )(x)
/**/

# define STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(x) \
    STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD( \
        STREAMS_BOOST_PARAMETER_FN_ARG_NAME(x) \
    )

// Builds forwarding functions.

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_TEMPLATE_Z(z, n) \
    template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, class ParameterArgumentType)>
/**/

# if ! defined(STREAMS_BOOST_NO_SFINAE) && ! STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x592))
#  define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_MATCH_Z(z, name, parameters, n) \
    , typename streams_boost::parameter::aux::match< \
          parameters, STREAMS_BOOST_PP_ENUM_PARAMS(n, ParameterArgumentType) \
      >::type streams_boost_parameter_enabler_argument = parameters()
# else
#  define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_MATCH_Z(z, name, parameters, n)
# endif
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_NAME(base) \
    STREAMS_BOOST_PP_CAT( \
        streams_boost_param_parameters_ \
      , STREAMS_BOOST_PP_CAT(__LINE__, STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(base)) \
    )

// Produce a name for a result type metafunction for the function
// named base
# define STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(base) \
    STREAMS_BOOST_PP_CAT( \
        streams_boost_param_result_ \
      , STREAMS_BOOST_PP_CAT(__LINE__,STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(base)) \
    )

// Can't do streams_boost_param_impl_ ## basee because base might start with an underscore
// daniel: what? how is that relevant? the reason for using CAT() is to make sure
// base is expanded. i'm not sure we need to here, but it's more stable to do it.
# define STREAMS_BOOST_PARAMETER_IMPL(base) \
    STREAMS_BOOST_PP_CAT(streams_boost_param_impl,STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(base))

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION00(z, n, r, data, elem) \
    STREAMS_BOOST_PP_IF( \
        n \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_TEMPLATE_Z, STREAMS_BOOST_PP_TUPLE_EAT(2) \
    )(z,n) \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STATIC(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data)) \
    inline \
    STREAMS_BOOST_PP_EXPR_IF(n, typename) \
        STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data))<   \
        STREAMS_BOOST_PP_EXPR_IF(n, typename) \
        streams_boost::parameter::aux::argument_pack< \
            STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_NAME(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data)) \
            STREAMS_BOOST_PP_COMMA_IF(n) \
            STREAMS_BOOST_PP_IF( \
                n, STREAMS_BOOST_PP_SEQ_ENUM, STREAMS_BOOST_PP_TUPLE_EAT(1) \
            )(elem) \
        >::type \
    >::type \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data))( \
        STREAMS_BOOST_PP_IF( \
            n \
          , STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R \
          , STREAMS_BOOST_PP_TUPLE_EAT(4) \
        )( \
            r \
          , STREAMS_BOOST_PARAMETER_FUNCTION_ARGUMENT \
          , ~ \
          , elem \
        ) \
        STREAMS_BOOST_PP_IF(n, STREAMS_BOOST_PARAMETER_FUNCTION_FWD_MATCH_Z, STREAMS_BOOST_PP_TUPLE_EAT(4))( \
            z \
          , STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data) \
          , STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_NAME(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data)) \
          , n \
        ) \
    ) STREAMS_BOOST_PP_EXPR_IF(STREAMS_BOOST_PP_TUPLE_ELEM(7,4,data), const) \
    { \
        return STREAMS_BOOST_PARAMETER_IMPL(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data))( \
            STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_NAME(STREAMS_BOOST_PP_TUPLE_ELEM(7,3,data))()( \
                STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, a) \
            ) \
        ); \
    }
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION0(r, data, elem) \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION00( \
        STREAMS_BOOST_PP_TUPLE_ELEM(7,0,data) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(7,1,data) \
      , r \
      , data \
      , elem \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_ARITY_0(z, n, data) \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION00( \
        z, n, STREAMS_BOOST_PP_DEDUCE_R() \
      , (z, n, STREAMS_BOOST_PP_TUPLE_REM(5) data) \
      , ~ \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_ARITY_N(z, n, data) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH( \
        STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION0 \
      , (z, n, STREAMS_BOOST_PP_TUPLE_REM(5) data) \
      , STREAMS_BOOST_PP_SEQ_FOR_EACH_PRODUCT( \
            STREAMS_BOOST_PARAMETER_FUNCTION_FWD_PRODUCT \
          , STREAMS_BOOST_PP_SEQ_FIRST_N( \
                n, STREAMS_BOOST_PP_TUPLE_ELEM(5,3,data) \
            ) \
        ) \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION(z, n, data) \
    STREAMS_BOOST_PP_IF( \
        n \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_ARITY_N \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_ARITY_0 \
    )(z,n,data) \
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS0( \
    result,name,args,const_,combinations,range \
) \
    STREAMS_BOOST_PP_REPEAT_FROM_TO( \
        STREAMS_BOOST_PP_TUPLE_ELEM(2,0,range), STREAMS_BOOST_PP_TUPLE_ELEM(2,1,range) \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION \
      , (result,name,const_,combinations,STREAMS_BOOST_PP_TUPLE_ELEM(2,1,range)) \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS(result,name,args, const_, combinations) \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS0( \
        result, name, args, const_, combinations, STREAMS_BOOST_PARAMETER_ARITY_RANGE(args) \
    )
/**/

// Builds streams_boost::parameter::parameters<> specialization
#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_optional(tag) \
    optional<tag

#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_required(tag) \
    required<tag

#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_deduced_optional(tag) \
    optional<streams_boost::parameter::deduced<tag>

#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_deduced_required(tag) \
    required<streams_boost::parameter::deduced<tag>

# if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) && !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))

#  if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1300)
#   define STREAMS_BOOST_PARAMETER_PREDICATE_TYPE(p) void*(*) (void* p)
#  else
#   define STREAMS_BOOST_PARAMETER_PREDICATE_TYPE(p) void p
#  endif

#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_M(r,tag_namespace,i,elem) \
    STREAMS_BOOST_PP_COMMA_IF(i) \
    streams_boost::parameter::STREAMS_BOOST_PP_CAT( \
        STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_ \
      , STREAMS_BOOST_PARAMETER_FN_ARG_QUALIFIER(elem) \
    )( \
        tag_namespace::STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD( \
            STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(elem) \
        ) \
    ) \
      , typename streams_boost::parameter::aux::unwrap_predicate< \
            STREAMS_BOOST_PARAMETER_PREDICATE_TYPE(STREAMS_BOOST_PARAMETER_FN_ARG_PRED(elem)) \
        >::type \
    >
# elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_M(r,tag_namespace,i,elem) \
    STREAMS_BOOST_PP_COMMA_IF(i) \
    streams_boost::parameter::STREAMS_BOOST_PP_CAT( \
        STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_ \
      , STREAMS_BOOST_PARAMETER_FN_ARG_QUALIFIER(elem) \
    )( \
        tag_namespace::STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD( \
            STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(elem) \
        ) \
    ) \
      , streams_boost::parameter::aux::funptr_predicate< \
            void* STREAMS_BOOST_PARAMETER_FN_ARG_PRED(elem) \
        > \
    >
# elif STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
#  define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_M(r,tag_namespace,i,elem) \
    STREAMS_BOOST_PP_COMMA_IF(i) \
    streams_boost::parameter::STREAMS_BOOST_PP_CAT( \
        STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_QUALIFIER_ \
      , STREAMS_BOOST_PARAMETER_FN_ARG_QUALIFIER(elem) \
    )( \
        tag_namespace::STREAMS_BOOST_PARAMETER_FUNCTION_KEYWORD( \
            STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(elem) \
        ) \
    ) \
      , streams_boost::mpl::always<streams_boost::mpl::true_> \
    >
# endif

# define STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS(tag_namespace, base, args)             \
    template <class BoostParameterDummy>                                            \
    struct STREAMS_BOOST_PP_CAT(                                                            \
            STREAMS_BOOST_PP_CAT(streams_boost_param_params_, __LINE__)                             \
          , STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(base)                              \
    ) : streams_boost::parameter::parameters<                                               \
            STREAMS_BOOST_PP_SEQ_FOR_EACH_I(                                                \
                STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_M, tag_namespace, args          \
            )                                                                       \
        >                                                                           \
    {};                                                                             \
                                                                                    \
    typedef STREAMS_BOOST_PP_CAT( \
            STREAMS_BOOST_PP_CAT(streams_boost_param_params_, __LINE__) \
          , STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(base) \
    )<int>

// Defines result type metafunction
# define STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_ARG(z, _, i, x) \
    STREAMS_BOOST_PP_COMMA_IF(i) class STREAMS_BOOST_PP_TUPLE_ELEM(3,1,x)
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_(result, name, args)                                   \
    template <class Args>                                                                       \
    struct STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(name)                                           \
    {                                                                                           \
        typedef typename STREAMS_BOOST_PARAMETER_PARENTHESIZED_TYPE(result) type;                       \
    };

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

#  define STREAMS_BOOST_PARAMETER_FUNCTION_RESULT(result, name, args)  \
    STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_(result, name, args)        \
    template <>                                                 \
    struct STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(name)<int>      \
    { typedef int type; };

# else

#  define STREAMS_BOOST_PARAMETER_FUNCTION_RESULT(result, name, args)  \
    STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_(result, name, args)

# endif

// Defines implementation function
# define STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_HEAD(name)           \
    template <class Args>                                   \
    typename STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(name)<    \
       Args                                                 \
    >::type STREAMS_BOOST_PARAMETER_IMPL(name)(Args const& args)

# define STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_FWD(name) \
    STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_HEAD(name);
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_required(state, arg) \
    ( \
        STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, state)) \
      , STREAMS_BOOST_PP_SEQ_PUSH_BACK(STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, state), arg) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, state) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, state) \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_deduced_required(state, arg) \
    STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_required(state, arg)

# define STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_optional(state, arg) \
    ( \
        STREAMS_BOOST_PP_TUPLE_ELEM(4, 0, state) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(4, 1, state) \
      , STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, state)) \
      , STREAMS_BOOST_PP_SEQ_PUSH_BACK(STREAMS_BOOST_PP_TUPLE_ELEM(4, 3, state), arg) \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_deduced_optional(state, arg) \
    STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_optional(state, arg)

# define STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG(s, state, arg) \
    STREAMS_BOOST_PP_CAT( \
        STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG_ \
      , STREAMS_BOOST_PARAMETER_FN_ARG_QUALIFIER(arg) \
    )(state, arg)

// Returns (required_count, required, optional_count, optionals) tuple
# define STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARGS(args) \
    STREAMS_BOOST_PP_SEQ_FOLD_LEFT( \
        STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARG \
      , (0,STREAMS_BOOST_PP_SEQ_NIL, 0,STREAMS_BOOST_PP_SEQ_NIL) \
      , args \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG_NAME(keyword) \
    STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_CAT(keyword,_),type)

// Helpers used as parameters to STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_TEMPLATE_ARG(r, _, arg) \
    , class STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG_NAME( \
              STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(arg) \
      )

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG(r, _, arg) \
    , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG_NAME( \
              STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(arg) \
      )& STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(arg)

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_PARAMETER(r, _, arg) \
    , STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(arg)

// Produces a name for the dispatch functions.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(name) \
    STREAMS_BOOST_PP_CAT( \
        streams_boost_param_default_ \
      , STREAMS_BOOST_PP_CAT(__LINE__, STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_NAME(name)) \
    )

// Helper macro used below to produce lists based on the keyword argument
// names. macro is applied to every element. n is the number of
// optional arguments that should be included.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS(macro, n, split_args) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH( \
        macro \
      , ~ \
      , STREAMS_BOOST_PP_TUPLE_ELEM(4,1,split_args) \
    ) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH( \
        macro \
      , ~ \
      , STREAMS_BOOST_PP_SEQ_FIRST_N( \
          STREAMS_BOOST_PP_SUB(STREAMS_BOOST_PP_TUPLE_ELEM(4,2,split_args), n) \
        , STREAMS_BOOST_PP_TUPLE_ELEM(4,3,split_args) \
        ) \
    )

// Generates a keyword | default expression.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_EVAL_DEFAULT(arg, tag_namespace) \
    streams_boost::parameter::keyword< \
        tag_namespace::STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(arg) \
    >::instance | streams_boost::parameter::aux::use_default_tag()

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_GET_ARG(arg, tag_ns) \
    STREAMS_BOOST_PARAMETER_FUNCTION_CAST( \
        args[ \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_EVAL_DEFAULT( \
                arg, tag_ns \
            ) \
        ] \
      , STREAMS_BOOST_PARAMETER_FN_ARG_PRED(arg) \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_BODY(name, n, split_args, tag_namespace) \
    { \
        return STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(name)( \
            (ResultType(*)())0 \
          , args \
          , 0L \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
                STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_PARAMETER \
              , n \
              , split_args \
            ) \
          , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_GET_ARG( \
                STREAMS_BOOST_PP_SEQ_ELEM( \
                    STREAMS_BOOST_PP_SUB(STREAMS_BOOST_PP_TUPLE_ELEM(4,2,split_args), n) \
                  , STREAMS_BOOST_PP_TUPLE_ELEM(4,3,split_args) \
                ) \
              , tag_namespace \
            ) \
        ); \
    }

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_EVAL_ACTUAL_DEFAULT(arg) \
    STREAMS_BOOST_PARAMETER_FUNCTION_CAST( \
        streams_boost::parameter::aux::as_lvalue(STREAMS_BOOST_PARAMETER_FN_ARG_DEFAULT(arg), 0L) \
      , STREAMS_BOOST_PARAMETER_FN_ARG_PRED(arg) \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_EVAL_DEFAULT_BODY(name, n, split_args, tag_ns, const_) \
    template < \
        class ResultType \
      , class Args \
        STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_TEMPLATE_ARG \
          , STREAMS_BOOST_PP_INC(n) \
          , split_args \
        ) \
    > \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STATIC(name) \
    ResultType STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(name)( \
        ResultType(*)() \
      , Args const& args \
      , long \
        STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG \
          , STREAMS_BOOST_PP_INC(n) \
          , split_args \
        ) \
      , streams_boost::parameter::aux::use_default_tag \
    ) STREAMS_BOOST_PP_EXPR_IF(const_, const) \
    { \
        return STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(name)( \
            (ResultType(*)())0 \
          , args \
          , 0L \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
                STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_PARAMETER \
              , STREAMS_BOOST_PP_INC(n) \
              , split_args \
            ) \
          , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_EVAL_ACTUAL_DEFAULT( \
                STREAMS_BOOST_PP_SEQ_ELEM( \
                    STREAMS_BOOST_PP_SUB(STREAMS_BOOST_PP_TUPLE_ELEM(4,2,split_args), STREAMS_BOOST_PP_INC(n)) \
                  , STREAMS_BOOST_PP_TUPLE_ELEM(4,3,split_args) \
                ) \
            ) \
        ); \
    }

// Produces a forwarding layer in the default evaluation machine.
//
// data is a tuple:
//
//   (name, split_args)
//
// Where name is the base name of the function, and split_args is a tuple:
//
//   (required_count, required_args, optional_count, required_args)
//


// defines the actual function body for STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION below.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION0(z, n, data) \
    template < \
        class ResultType \
      , class Args \
        STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_TEMPLATE_ARG \
          , n \
          , STREAMS_BOOST_PP_TUPLE_ELEM(5,1,data) \
        ) \
    > \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STATIC(STREAMS_BOOST_PP_TUPLE_ELEM(5,0,data)) \
    ResultType STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(STREAMS_BOOST_PP_TUPLE_ELEM(5,0,data))( \
        ResultType(*)() \
      , Args const& args \
      , int \
        STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG \
          , n \
          , STREAMS_BOOST_PP_TUPLE_ELEM(5,1,data) \
        ) \
    ) STREAMS_BOOST_PP_EXPR_IF(STREAMS_BOOST_PP_TUPLE_ELEM(5,2,data), const) \
    STREAMS_BOOST_PP_IF( \
        n \
      , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_BODY \
      , ; STREAMS_BOOST_PP_TUPLE_EAT(4) \
    )( \
        STREAMS_BOOST_PP_TUPLE_ELEM(5,0,data) \
      , n \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,1,data) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,3,data) \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION(z, n, data) \
    STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PP_AND( \
            STREAMS_BOOST_PP_NOT(n) \
          , STREAMS_BOOST_PP_TUPLE_ELEM(5,4,data) \
        ) \
      , STREAMS_BOOST_PP_TUPLE_EAT(3) \
      , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION0 \
    )(z, n, data) \
    STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PP_EQUAL(n, STREAMS_BOOST_PP_TUPLE_ELEM(4,2,STREAMS_BOOST_PP_TUPLE_ELEM(5,1,data))) \
      , STREAMS_BOOST_PP_TUPLE_EAT(5) \
      , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_EVAL_DEFAULT_BODY \
    )( \
        STREAMS_BOOST_PP_TUPLE_ELEM(5,0,data) \
      , n \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,1,data) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,3,data) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(5,2,data) \
    )

# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_GET_ARG(r, tag_ns, arg) \
    , STREAMS_BOOST_PARAMETER_FUNCTION_CAST( \
          args[ \
              streams_boost::parameter::keyword<tag_ns::STREAMS_BOOST_PARAMETER_FN_ARG_KEYWORD(arg)>::instance \
          ] \
        , STREAMS_BOOST_PARAMETER_FN_ARG_PRED(arg) \
      )

// Generates the function template that recives a ArgumentPack, and then
// goes on to call the layers of overloads generated by 
// STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER.
# define STREAMS_BOOST_PARAMETER_FUNCTION_INITIAL_DISPATCH_FUNCTION(name, split_args, const_, tag_ns) \
    template <class Args> \
    typename STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(name)<Args>::type \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STATIC(name) \
    STREAMS_BOOST_PARAMETER_IMPL(name)(Args const& args) STREAMS_BOOST_PP_EXPR_IF(const_, const) \
    { \
        return STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(name)( \
            (typename STREAMS_BOOST_PARAMETER_FUNCTION_RESULT_NAME(name)<Args>::type(*)())0 \
          , args \
          , 0L \
 \
            STREAMS_BOOST_PP_SEQ_FOR_EACH( \
                STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_GET_ARG \
              , tag_ns \
              , STREAMS_BOOST_PP_TUPLE_ELEM(4,1,split_args) \
            ) \
 \
        ); \
    }

// Helper for STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER below.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER_AUX( \
    name, split_args, skip_fwd_decl, const_, tag_namespace \
  ) \
    STREAMS_BOOST_PP_REPEAT_FROM_TO( \
        0 \
      , STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_TUPLE_ELEM(4, 2, split_args)) \
      , STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION \
      , (name, split_args, const_, tag_namespace, skip_fwd_decl) \
    ) \
 \
    STREAMS_BOOST_PARAMETER_FUNCTION_INITIAL_DISPATCH_FUNCTION(name, split_args, const_, tag_namespace) \
\
    template < \
        class ResultType \
      , class Args \
        STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_TEMPLATE_ARG \
          , 0 \
          , split_args \
        ) \
    > \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_STATIC(name) \
    ResultType STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_NAME(name)( \
        ResultType(*)() \
      , Args const& args \
      , int \
        STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_ARGUMENTS( \
            STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_FUNCTION_ARG \
          , 0 \
          , split_args \
        ) \
    ) STREAMS_BOOST_PP_EXPR_IF(const_, const)

// Generates a bunch of forwarding functions that each extract
// one more argument.
# define STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER(name, args, skip_fwd_decl, const_, tag_ns) \
    STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER_AUX( \
        name, STREAMS_BOOST_PARAMETER_FUNCTION_SPLIT_ARGS(args), skip_fwd_decl, const_, tag_ns \
    )
/**/

// Defines the result metafunction and the parameters specialization.
# define STREAMS_BOOST_PARAMETER_FUNCTION_HEAD(result, name, tag_namespace, args)   \
      STREAMS_BOOST_PARAMETER_FUNCTION_RESULT(result, name, args)                   \
                                                                            \
          STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS(tag_namespace, name, args)    \
          STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS_NAME(name);                   \

// Helper for STREAMS_BOOST_PARAMETER_FUNCTION below.
# define STREAMS_BOOST_PARAMETER_FUNCTION_AUX(result, name, tag_namespace, args)    \
    STREAMS_BOOST_PARAMETER_FUNCTION_HEAD(result, name, tag_namespace, args)         \
    STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_HEAD(name); \
\
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS(                                  \
        result, name, args, 0                                                \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATIONS(args)                      \
    )                                                                        \
                                                                             \
    STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER(name, args, 0, 0, tag_namespace)

// Defines a Boost.Parameter enabled function with the new syntax.
# define STREAMS_BOOST_PARAMETER_FUNCTION(result, name, tag_namespace, args)    \
    STREAMS_BOOST_PARAMETER_FUNCTION_AUX(                                       \
        result, name, tag_namespace                                      \
      , STREAMS_BOOST_PARAMETER_FLATTEN(3, 2, 3, args)                           \
    )                                                                    \
/**/

// Defines a Boost.Parameter enabled function.
# define STREAMS_BOOST_PARAMETER_BASIC_FUNCTION_AUX(result, name, tag_namespace, args)    \
    STREAMS_BOOST_PARAMETER_FUNCTION_HEAD(result, name, tag_namespace, args)        \
                                                                            \
    STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_FWD(name)                                 \
                                                                            \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS(                                 \
        result, name, args, 0                                               \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATIONS(args)                     \
    )                                                                       \
                                                                            \
    STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_HEAD(name)

# define STREAMS_BOOST_PARAMETER_BASIC_FUNCTION(result, name, tag_namespace, args)  \
    STREAMS_BOOST_PARAMETER_BASIC_FUNCTION_AUX(                                     \
        result, name, tag_namespace                                     \
      , STREAMS_BOOST_PARAMETER_FLATTEN(2, 2, 3, args)                          \
    )                                                                   \
/**/

// Defines a Boost.Parameter enabled member function.
# define STREAMS_BOOST_PARAMETER_BASIC_MEMBER_FUNCTION_AUX(result, name, tag_namespace, args, const_) \
    STREAMS_BOOST_PARAMETER_FUNCTION_HEAD(result, name, tag_namespace, args)                    \
                                                                                        \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS(                                             \
        result, name, args, const_                                                      \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATIONS(args)                                 \
    )                                                                                   \
                                                                                        \
    STREAMS_BOOST_PARAMETER_FUNCTION_IMPL_HEAD(name) STREAMS_BOOST_PP_EXPR_IF(const_, const)            \
/**/

# define STREAMS_BOOST_PARAMETER_BASIC_MEMBER_FUNCTION(result, name, tag_namespace, args) \
    STREAMS_BOOST_PARAMETER_BASIC_MEMBER_FUNCTION_AUX( \
        result, name, tag_namespace \
      , STREAMS_BOOST_PARAMETER_FLATTEN(2, 2, 3, args) \
      , 0 \
    )
/**/

# define STREAMS_BOOST_PARAMETER_BASIC_CONST_MEMBER_FUNCTION(result, name, tag_namespace, args) \
    STREAMS_BOOST_PARAMETER_BASIC_MEMBER_FUNCTION_AUX( \
        result, name, tag_namespace \
      , STREAMS_BOOST_PARAMETER_FLATTEN(2, 2, 3, args) \
      , 1 \
    )
/**/



# define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_AUX(result, name, tag_namespace, const_, args)    \
    STREAMS_BOOST_PARAMETER_FUNCTION_HEAD(result, name, tag_namespace, args)         \
\
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTIONS(                                  \
        result, name, args, const_                                           \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATIONS(args)                      \
    )                                                                        \
                                                                             \
    STREAMS_BOOST_PARAMETER_FUNCTION_DEFAULT_LAYER(name, args, 1, const_, tag_namespace)

// Defines a Boost.Parameter enabled function with the new syntax.
# define STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION(result, name, tag_namespace, args)    \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_AUX(                                       \
        result, name, tag_namespace, 0                                     \
      , STREAMS_BOOST_PARAMETER_FLATTEN(3, 2, 3, args)                           \
    )                                                                    \
/**/

# define STREAMS_BOOST_PARAMETER_CONST_MEMBER_FUNCTION(result, name, tag_namespace, args)    \
    STREAMS_BOOST_PARAMETER_MEMBER_FUNCTION_AUX(                                       \
        result, name, tag_namespace, 1                                     \
      , STREAMS_BOOST_PARAMETER_FLATTEN(3, 2, 3, args)                           \
    )                                                                    \
/**/

// Defines a Boost.Parameter enabled constructor.

# define STREAMS_BOOST_PARAMETER_FUNCTION_ARGUMENT(r, _, i, elem) \
    STREAMS_BOOST_PP_COMMA_IF(i) elem& STREAMS_BOOST_PP_CAT(a, i)
/**/

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)

// Older MSVC can't do what's necessary to handle commas in base names; just
// use a typedef instead if you have a base name that contains commas.
#  define STREAMS_BOOST_PARAMETER_PARENTHESIZED_BASE(x) STREAMS_BOOST_PP_SEQ_HEAD(x)

# else

#  define STREAMS_BOOST_PARAMETER_PARENTHESIZED_BASE(x) STREAMS_BOOST_PARAMETER_PARENTHESIZED_TYPE(x)

# endif

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR00(z, n, r, data, elem) \
    STREAMS_BOOST_PP_IF( \
        n \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_FUNCTION_TEMPLATE_Z, STREAMS_BOOST_PP_TUPLE_EAT(2) \
    )(z, n) \
    STREAMS_BOOST_PP_EXPR_IF(STREAMS_BOOST_PP_EQUAL(n,1), explicit) \
    STREAMS_BOOST_PP_TUPLE_ELEM(6,2,data)( \
        STREAMS_BOOST_PP_IF( \
            n \
          , STREAMS_BOOST_PP_SEQ_FOR_EACH_I_R \
          , STREAMS_BOOST_PP_TUPLE_EAT(4) \
        )( \
            r \
          , STREAMS_BOOST_PARAMETER_FUNCTION_ARGUMENT \
          , ~ \
          , elem \
        ) \
        STREAMS_BOOST_PP_IF(n, STREAMS_BOOST_PARAMETER_FUNCTION_FWD_MATCH_Z, STREAMS_BOOST_PP_TUPLE_EAT(4))( \
            z \
          , STREAMS_BOOST_PP_TUPLE_ELEM(6,3,data) \
          , STREAMS_BOOST_PP_CAT(constructor_parameters, __LINE__) \
          , n \
        ) \
    ) \
      : STREAMS_BOOST_PARAMETER_PARENTHESIZED_BASE(STREAMS_BOOST_PP_TUPLE_ELEM(6,3,data)) ( \
            STREAMS_BOOST_PP_CAT(constructor_parameters, __LINE__)()( \
                STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, a) \
            ) \
        ) \
    {}
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR0(r, data, elem) \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR00( \
        STREAMS_BOOST_PP_TUPLE_ELEM(6,0,data) \
      , STREAMS_BOOST_PP_TUPLE_ELEM(6,1,data) \
      , r \
      , data \
      , elem \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_PRODUCT(r, product) \
    (product)
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR_ARITY_0(z, n, data) \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR00( \
        z, n, STREAMS_BOOST_PP_DEDUCE_R() \
      , (z, n, STREAMS_BOOST_PP_TUPLE_REM(4) data) \
      , ~ \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR_ARITY_N(z, n, data) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH( \
        STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR0 \
      , (z, n, STREAMS_BOOST_PP_TUPLE_REM(4) data) \
      , STREAMS_BOOST_PP_SEQ_FOR_EACH_PRODUCT( \
            STREAMS_BOOST_PARAMETER_FUNCTION_FWD_PRODUCT \
          , STREAMS_BOOST_PP_SEQ_FIRST_N( \
                n, STREAMS_BOOST_PP_TUPLE_ELEM(4,2,data) \
            ) \
        ) \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR(z, n, data) \
    STREAMS_BOOST_PP_IF( \
        n \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR_ARITY_N \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR_ARITY_0 \
    )(z,n,data) \
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTORS0(class_,base,args,combinations,range) \
    STREAMS_BOOST_PP_REPEAT_FROM_TO( \
        STREAMS_BOOST_PP_TUPLE_ELEM(2,0,range), STREAMS_BOOST_PP_TUPLE_ELEM(2,1,range) \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTOR \
      , (class_,base,combinations,STREAMS_BOOST_PP_TUPLE_ELEM(2,1,range)) \
    )
/**/

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTORS(class_,base,args,combinations) \
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTORS0( \
        class_, base, args, combinations, STREAMS_BOOST_PARAMETER_ARITY_RANGE(args) \
    )
/**/

# define STREAMS_BOOST_PARAMETER_CONSTRUCTOR_AUX(class_, base, tag_namespace, args) \
    STREAMS_BOOST_PARAMETER_FUNCTION_PARAMETERS(tag_namespace, ctor, args)          \
        STREAMS_BOOST_PP_CAT(constructor_parameters, __LINE__); \
\
    STREAMS_BOOST_PARAMETER_FUNCTION_FWD_CONSTRUCTORS( \
        class_, base, args \
      , STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATIONS(args) \
    ) \
/**/

# define STREAMS_BOOST_PARAMETER_CONSTRUCTOR(class_, base, tag_namespace, args) \
    STREAMS_BOOST_PARAMETER_CONSTRUCTOR_AUX( \
        class_, base, tag_namespace \
      , STREAMS_BOOST_PARAMETER_FLATTEN(2, 2, 3, args) \
    )
/**/

# ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
#  define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATION(r, _, i, elem) \
    (STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PARAMETER_FUNCTION_IS_KEYWORD_QUALIFIER( \
            STREAMS_BOOST_PARAMETER_FN_ARG_NAME(elem) \
        ) \
      , (const ParameterArgumentType ## i)(ParameterArgumentType ## i) \
      , (const ParameterArgumentType ## i) \
    ))
// MSVC6.5 lets us bind rvalues to T&.
# elif STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#  define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATION(r, _, i, elem) \
    (STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PARAMETER_FUNCTION_IS_KEYWORD_QUALIFIER( \
            STREAMS_BOOST_PARAMETER_FN_ARG_NAME(elem) \
        ) \
      , (ParameterArgumentType ## i) \
      , (const ParameterArgumentType ## i) \
    ))
// No partial ordering. This feature doesn't work.
// This is exactly the same as for VC6.5, but we might change it later.
# else
#  define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATION(r, _, i, elem) \
    (STREAMS_BOOST_PP_IF( \
        STREAMS_BOOST_PARAMETER_FUNCTION_IS_KEYWORD_QUALIFIER( \
            STREAMS_BOOST_PARAMETER_FN_ARG_NAME(elem) \
        ) \
      , (ParameterArgumentType ## i) \
      , (const ParameterArgumentType ## i) \
    ))
# endif

# define STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATIONS(args) \
    STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_PARAMETER_FUNCTION_FWD_COMBINATION, ~, args)

#endif // STREAMS_BOOST_PARAMETER_PREPROCESSOR_060206_HPP

