// Copyright Alexander Nasonov 2006-2009
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef FILE_streams_boost_scope_exit_hpp_INCLUDED
#define FILE_streams_boost_scope_exit_hpp_INCLUDED

#include <streams_boost/config.hpp>

#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/facilities/empty.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/seq/cat.hpp>
#include <streams_boost/preprocessor/seq/for_each_i.hpp>
#include <streams_boost/preprocessor/tuple/elem.hpp>
#include <streams_boost/typeof/typeof.hpp>

#if defined(__GNUC__) && !defined(STREAMS_BOOST_INTEL)
# define STREAMS_BOOST_SCOPE_EXIT_AUX_GCC (__GNUC__ * 100 + __GNUC_MINOR__)
#else
# define STREAMS_BOOST_SCOPE_EXIT_AUX_GCC 0
#endif

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_SCOPE_EXIT_AUX_GCC, STREAMS_BOOST_TESTED_AT(413))
#define STREAMS_BOOST_SCOPE_EXIT_AUX_TPL_WORKAROUND
#endif

// Steven Watanabe's trick with a modification suggested by Kim Barrett
namespace streams_boost { namespace scope_exit { namespace aux {

    // Type of a local streams_boost_scope_exit_args variable.
    // First use in a local scope will declare the streams_boost_scope_exit_args
    // variable, subsequent uses will be resolved as two comparisons
    // (cmp1 with 0 and cmp2 with streams_boost_scope_exit_args).
    template<int Dummy = 0>
    struct declared
    {
        void* value;
        static int const cmp2 = 0;
        friend void operator>(int, declared const&) {}
    };

    struct undeclared { declared<> dummy[2]; };

    template<int> struct resolve;

    template<>
    struct resolve<sizeof(declared<>)>
    {
        static const int cmp1 = 0;
    };

    template<>
    struct resolve<sizeof(undeclared)>
    {
        template<int>
        struct cmp1
        {
            static int const cmp2 = 0;
        };
    };
} } }

extern streams_boost::scope_exit::aux::undeclared streams_boost_scope_exit_args; // undefined


namespace streams_boost { namespace scope_exit { namespace aux {

typedef void (*ref_tag)(int&);
typedef void (*val_tag)(int );

template<class T, class Tag> struct member;

template<class T>
struct member<T,ref_tag>
{
    T& value;
#ifndef STREAMS_BOOST_SCOPE_EXIT_AUX_TPL_WORKAROUND
    member(T& ref) : value(ref) {}
#endif
};

template<class T>
struct member<T,val_tag>
{
    T value;
#ifndef STREAMS_BOOST_SCOPE_EXIT_AUX_TPL_WORKAROUND
    member(T& val) : value(val) {}
#endif
};

template<class T> inline T& deref(T* p, ref_tag) { return *p; }
template<class T> inline T& deref(T& r, val_tag) { return  r; }

template<class T>
struct wrapper
{
    typedef T type;
};

template<class T> wrapper<T> wrap(T&);

} } }

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::scope_exit::aux::wrapper, 1)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD(id)     STREAMS_BOOST_PP_CAT(streams_boost_se_guard_,    id)
#define STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD_T(id)   STREAMS_BOOST_PP_CAT(streams_boost_se_guard_t_,  id)
#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS(id)    STREAMS_BOOST_PP_CAT(streams_boost_se_params_,   id)
#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T(id)  STREAMS_BOOST_PP_CAT(streams_boost_se_params_t_, id)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_TAG(id, i) \
    STREAMS_BOOST_PP_SEQ_CAT( (streams_boost_se_tag_)(i)(_)(id) )

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM(id, i, var) \
    STREAMS_BOOST_PP_SEQ_CAT( (streams_boost_se_param_)(i)(_)(id) )

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_T(id, i, var) \
    STREAMS_BOOST_PP_SEQ_CAT( (streams_boost_se_param_t_)(i)(_)(id) )

#define STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_T(id, i, var) \
    STREAMS_BOOST_PP_SEQ_CAT( (streams_boost_se_capture_t_)(i)(_)(id) )

#define STREAMS_BOOST_SCOPE_EXIT_AUX_WRAPPED(id, i) \
    STREAMS_BOOST_PP_SEQ_CAT( (streams_boost_se_wrapped_t_)(i)(_)(id) )

#define STREAMS_BOOST_SCOPE_EXIT_AUX_DEREF(id, i, var) \
    streams_boost::scope_exit::aux::deref(var, (STREAMS_BOOST_SCOPE_EXIT_AUX_TAG(id,i))0)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_MEMBER(r, id, i, var) \
    streams_boost::scope_exit::aux::member<                \
        STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_T(id,i,var),    \
        STREAMS_BOOST_SCOPE_EXIT_AUX_TAG(id,i)             \
    > STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM(id,i,var);

// idty is (id,typename) or (id,STREAMS_BOOST_PP_EMPTY())
#define STREAMS_BOOST_SCOPE_EXIT_AUX_ARG_DECL(r, idty, i, var)             \
    STREAMS_BOOST_PP_COMMA_IF(i) STREAMS_BOOST_PP_TUPLE_ELEM(2,1,idty)             \
    STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty)):: \
    STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_T(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var) var
 
#define STREAMS_BOOST_SCOPE_EXIT_AUX_ARG(r, id, i, var) STREAMS_BOOST_PP_COMMA_IF(i) \
    streams_boost_se_params_->STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM(id,i,var).value

#define STREAMS_BOOST_SCOPE_EXIT_AUX_TAG_DECL(r, id, i, var) \
    typedef void (*STREAMS_BOOST_SCOPE_EXIT_AUX_TAG(id,i))(int var);


#ifdef STREAMS_BOOST_SCOPE_EXIT_AUX_TPL_WORKAROUND

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T_CTOR(id, seq)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_INIT(r, id, i, var) \
    STREAMS_BOOST_PP_COMMA_IF(i) { STREAMS_BOOST_SCOPE_EXIT_AUX_DEREF(id,i,var) }

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_INIT(id, seq) \
    = { STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_INIT, id, seq) };

#else

#define STREAMS_BOOST_SCOPE_EXIT_AUX_CTOR_ARG(r, id, i, var) STREAMS_BOOST_PP_COMMA_IF(i) \
    STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_T(id,i,var) & STREAMS_BOOST_PP_CAT(a,i)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_MEMBER_INIT(r, id, i, var) STREAMS_BOOST_PP_COMMA_IF(i) \
    STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM(id,i,var) ( STREAMS_BOOST_PP_CAT(a,i) )

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T_CTOR(id, seq)                        \
    STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T(id)(                                     \
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_CTOR_ARG, id, seq ) ) \
    : STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_MEMBER_INIT, id, seq) {}

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_INIT(r, id, i, var) \
    STREAMS_BOOST_PP_COMMA_IF(i) STREAMS_BOOST_SCOPE_EXIT_AUX_DEREF(id,i,var)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_INIT(id, seq) \
    ( STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_INIT, id, seq) );

#endif

#if defined(STREAMS_BOOST_TYPEOF_EMULATION)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_DECL(r, idty, i, var)                   \
    struct STREAMS_BOOST_SCOPE_EXIT_AUX_WRAPPED(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i)    \
        : STREAMS_BOOST_TYPEOF(streams_boost::scope_exit::aux::wrap(                         \
        STREAMS_BOOST_SCOPE_EXIT_AUX_DEREF(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var)))  \
    {}; typedef STREAMS_BOOST_PP_TUPLE_ELEM(2,1,idty)                                \
        STREAMS_BOOST_SCOPE_EXIT_AUX_WRAPPED(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i)::type \
        STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_T(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var);

#elif defined(STREAMS_BOOST_INTEL)

#define STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_DECL(r, idty, i, var)                 \
    typedef STREAMS_BOOST_TYPEOF_KEYWORD(                                          \
        STREAMS_BOOST_SCOPE_EXIT_AUX_DEREF(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var)) \
        STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_T(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var);

#else

#define STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_DECL(r, idty, i, var)                   \
    typedef STREAMS_BOOST_TYPEOF(streams_boost::scope_exit::aux::wrap(                       \
        STREAMS_BOOST_SCOPE_EXIT_AUX_DEREF(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var)))  \
        STREAMS_BOOST_SCOPE_EXIT_AUX_WRAPPED(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i);      \
    typedef STREAMS_BOOST_PP_TUPLE_ELEM(2,1,idty)                                    \
        STREAMS_BOOST_SCOPE_EXIT_AUX_WRAPPED(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i)::type \
        STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_T(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var);

#endif

#define STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_DECL(r, idty, i, var) \
    typedef STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_T(              \
        STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var)           \
        STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_T(STREAMS_BOOST_PP_TUPLE_ELEM(2,0,idty), i, var);


#define STREAMS_BOOST_SCOPE_EXIT_AUX_IMPL(id, seq, ty)                                 \
    STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_TAG_DECL, id, seq)            \
    STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_CAPTURE_DECL, (id,ty), seq)   \
    struct STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T(id) {                                 \
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_PARAM_DECL, (id,ty), seq) \
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_MEMBER, id, seq)          \
        STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T_CTOR(id, seq)                            \
    } STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS(id) STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_INIT(id,seq) \
    streams_boost::scope_exit::aux::declared< streams_boost::scope_exit::aux::resolve<         \
        sizeof(streams_boost_scope_exit_args)>::cmp1<0>::cmp2 > streams_boost_scope_exit_args; \
    streams_boost_scope_exit_args.value = &STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS(id);            \
    struct STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD_T(id) {                                  \
        STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T(id)* streams_boost_se_params_;                   \
        STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD_T(id) (void* streams_boost_se_params)               \
            : streams_boost_se_params_(                                                \
                  (STREAMS_BOOST_SCOPE_EXIT_AUX_PARAMS_T(id)*)streams_boost_se_params)         \
        {}                                                                     \
        ~STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD_T(id)() { streams_boost_se_body(                   \
            STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_SCOPE_EXIT_AUX_ARG, id, seq) ); }    \
        static void streams_boost_se_body(STREAMS_BOOST_PP_SEQ_FOR_EACH_I(                     \
            STREAMS_BOOST_SCOPE_EXIT_AUX_ARG_DECL, (id,ty), seq) )

#if defined(STREAMS_BOOST_MSVC)

#define STREAMS_BOOST_SCOPE_EXIT_END } STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD(__COUNTER__) ( \
    streams_boost_scope_exit_args.value);

#define STREAMS_BOOST_SCOPE_EXIT(seq) \
    STREAMS_BOOST_SCOPE_EXIT_AUX_IMPL(__COUNTER__, seq, STREAMS_BOOST_PP_EMPTY())

#else

#define STREAMS_BOOST_SCOPE_EXIT_END } STREAMS_BOOST_SCOPE_EXIT_AUX_GUARD(__LINE__) ( \
    streams_boost_scope_exit_args.value);

#define STREAMS_BOOST_SCOPE_EXIT(seq) \
    STREAMS_BOOST_SCOPE_EXIT_AUX_IMPL(__LINE__, seq, STREAMS_BOOST_PP_EMPTY())

#endif

#ifdef STREAMS_BOOST_SCOPE_EXIT_AUX_TPL_WORKAROUND
#define STREAMS_BOOST_SCOPE_EXIT_TPL(seq) \
    STREAMS_BOOST_SCOPE_EXIT_AUX_IMPL(__LINE__, seq, typename)
#else
#define STREAMS_BOOST_SCOPE_EXIT_TPL(seq) STREAMS_BOOST_SCOPE_EXIT(seq)
#endif

#endif // #ifndef FILE_streams_boost_scope_exit_hpp_INCLUDED

