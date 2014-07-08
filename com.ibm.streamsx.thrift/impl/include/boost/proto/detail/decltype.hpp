///////////////////////////////////////////////////////////////////////////////
/// \file decltype.hpp
/// Contains definition the STREAMS_BOOST_PROTO_DECLTYPE_() macro and assorted helpers
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROTO_DETAIL_DECLTYPE_HPP_EAN_04_04_2008
#define STREAMS_BOOST_PROTO_DETAIL_DECLTYPE_HPP_EAN_04_04_2008

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/get_pointer.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/iteration/local.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/type_traits/is_class.hpp>
#include <streams_boost/type_traits/remove_cv.hpp>
#include <streams_boost/type_traits/remove_reference.hpp>
#include <streams_boost/type_traits/is_pointer.hpp>
#include <streams_boost/type_traits/is_function.hpp>
#include <streams_boost/type_traits/is_member_object_pointer.hpp>
#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/type_traits/add_reference.hpp>
#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/utility/addressof.hpp>
#include <streams_boost/utility/result_of.hpp>
#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/proto/repeat.hpp>

#ifdef STREAMS_BOOST_HAS_DECLTYPE
# define STREAMS_BOOST_PROTO_DECLTYPE_(EXPR, TYPE) typedef decltype(EXPR) TYPE;
#else
# define STREAMS_BOOST_PROTO_DECLTYPE_NESTED_TYPEDEF_TPL_(NESTED, EXPR)                                     \
    STREAMS_BOOST_TYPEOF_NESTED_TYPEDEF_TPL(STREAMS_BOOST_PP_CAT(nested_and_hidden_, NESTED), EXPR)                 \
    static int const sz = sizeof(streams_boost::proto::detail::check_reference(EXPR));                      \
    struct NESTED                                                                                   \
      : streams_boost::mpl::if_c<                                                                           \
            1==sz                                                                                   \
          , typename STREAMS_BOOST_PP_CAT(nested_and_hidden_, NESTED)::type &                               \
          , typename STREAMS_BOOST_PP_CAT(nested_and_hidden_, NESTED)::type                                 \
        >                                                                                           \
    {};
# define STREAMS_BOOST_PROTO_DECLTYPE_(EXPR, TYPE)                                                          \
    STREAMS_BOOST_PROTO_DECLTYPE_NESTED_TYPEDEF_TPL_(STREAMS_BOOST_PP_CAT(nested_, TYPE), (EXPR))                   \
    typedef typename STREAMS_BOOST_PP_CAT(nested_, TYPE)::type TYPE;
#endif

namespace streams_boost { namespace proto
{
    namespace detail
    {
        namespace anyns
        {
            ////////////////////////////////////////////////////////////////////////////////////////////
            struct any
            {
                any(...);
                any operator=(any);
                any operator[](any);
                #define M0(Z, N, DATA) any operator()(STREAMS_BOOST_PP_ENUM_PARAMS_Z(Z, N, any STREAMS_BOOST_PP_INTERCEPT));
                STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_PROTO_MAX_ARITY, M0, ~)
                #undef M0

                template<typename T>
                operator T &() const volatile;

                any operator+();
                any operator-();
                any operator*();
                any operator&();
                any operator~();
                any operator!();
                any operator++();
                any operator--();
                any operator++(int);
                any operator--(int);

                friend any operator<<(any, any);
                friend any operator>>(any, any);
                friend any operator*(any, any);
                friend any operator/(any, any);
                friend any operator%(any, any);
                friend any operator+(any, any);
                friend any operator-(any, any);
                friend any operator<(any, any);
                friend any operator>(any, any);
                friend any operator<=(any, any);
                friend any operator>=(any, any);
                friend any operator==(any, any);
                friend any operator!=(any, any);
                friend any operator||(any, any);
                friend any operator&&(any, any);
                friend any operator&(any, any);
                friend any operator|(any, any);
                friend any operator^(any, any);
                friend any operator,(any, any);
                friend any operator->*(any, any);

                friend any operator<<=(any, any);
                friend any operator>>=(any, any);
                friend any operator*=(any, any);
                friend any operator/=(any, any);
                friend any operator%=(any, any);
                friend any operator+=(any, any);
                friend any operator-=(any, any);
                friend any operator&=(any, any);
                friend any operator|=(any, any);
                friend any operator^=(any, any);
            };
        }

        using anyns::any;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        struct as_mutable
        {
            typedef T &type;
        };

        template<typename T>
        struct as_mutable<T &>
        {
            typedef T &type;
        };

        template<typename T>
        struct as_mutable<T const &>
        {
            typedef T &type;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        T make();

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        typename as_mutable<T>::type make_mutable();

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        struct subscript_wrapper
          : T
        {
            using T::operator[];

            #if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1500))
            any operator[](any const volatile &) const volatile;
            #else
            any operator[](any const &) const volatile;
            #endif
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        struct as_subscriptable
        {
            typedef
                typename mpl::if_c<
                    is_class<T>::value
                  , subscript_wrapper<T>
                  , T
                >::type
            type;
        };

        template<typename T>
        struct as_subscriptable<T const>
        {
            typedef
                typename mpl::if_c<
                    is_class<T>::value
                  , subscript_wrapper<T> const
                  , T const
                >::type
            type;
        };

        template<typename T>
        struct as_subscriptable<T &>
        {
            typedef
                typename mpl::if_c<
                    is_class<T>::value
                  , subscript_wrapper<T> &
                  , T &
                >::type
            type;
        };

        template<typename T>
        struct as_subscriptable<T const &>
        {
            typedef
                typename mpl::if_c<
                    is_class<T>::value
                  , subscript_wrapper<T> const &
                  , T const &
                >::type
            type;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        typename as_subscriptable<T>::type make_subscriptable();

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        char check_reference(T &);

        template<typename T>
        char (&check_reference(T const &))[2];

        namespace has_get_pointerns
        {
            using streams_boost::get_pointer;
            void *(&get_pointer(...))[2];

            ////////////////////////////////////////////////////////////////////////////////////////////
            template<typename T>
            struct has_get_pointer
            {
                STREAMS_BOOST_STATIC_CONSTANT(bool, value = sizeof(void *) == sizeof(get_pointer(make<T &>())));
                typedef mpl::bool_<value> type;
            };
        }

        using has_get_pointerns::has_get_pointer;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        struct classtypeof;

        template<typename T, typename U>
        struct classtypeof<T U::*>
        {
            typedef U type;
        };

        #define STREAMS_BOOST_PP_LOCAL_MACRO(N)                                                             \
        template<typename T, typename U STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>               \
        struct classtypeof<T (U::*)(STREAMS_BOOST_PP_ENUM_PARAMS(N, A))>                                    \
        {                                                                                           \
            typedef U type;                                                                         \
        };                                                                                          \
        template<typename T, typename U STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>               \
        struct classtypeof<T (U::*)(STREAMS_BOOST_PP_ENUM_PARAMS(N, A)) const>                              \
        {                                                                                           \
            typedef U type;                                                                         \
        };                                                                                          \
        /**/
        #define STREAMS_BOOST_PP_LOCAL_LIMITS (0, STREAMS_BOOST_PROTO_MAX_ARITY)
        #include STREAMS_BOOST_PP_LOCAL_ITERATE()

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename T>
        T &lvalue(T &t)
        {
            return t;
        }

        template<typename T>
        T const &lvalue(T const &t)
        {
            return t;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename U, typename V, typename T>
        U *proto_get_pointer(T &t, V *, U *)
        {
            return streams_boost::addressof(t);
        }

        template<typename U, typename V, typename T>
        U const *proto_get_pointer(T &t, V *, U const *)
        {
            return streams_boost::addressof(t);
        }

        template<typename U, typename V, typename T>
        V *proto_get_pointer(T &t, V *, ...)
        {
            return get_pointer(t);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        #define STREAMS_BOOST_PROTO_USE_GET_POINTER()                                                       \
        using namespace streams_boost::proto::detail::get_pointerns                                         \
        /**/

        #define STREAMS_BOOST_PROTO_GET_POINTER(Type, Obj)                                                  \
        streams_boost::proto::detail::proto_get_pointer<Type>(                                              \
            streams_boost::proto::detail::lvalue(Obj)                                                       \
          , (true ? 0 : get_pointer(Obj))                                                           \
          , (true ? 0 : streams_boost::addressof(streams_boost::proto::detail::lvalue(Obj)))                        \
        )                                                                                           \
        /**/

        ////////////////////////////////////////////////////////////////////////////////////////////
        namespace get_pointerns
        {
            using streams_boost::get_pointer;

            template<typename T>
            typename disable_if_c<has_get_pointer<T>::value, T *>::type
            get_pointer(T &t)
            {
                return streams_boost::addressof(t);
            }

            template<typename T>
            typename disable_if_c<has_get_pointer<T>::value, T const *>::type
            get_pointer(T const &t)
            {
                return streams_boost::addressof(t);
            }

            char test_ptr_to_const(void *);
            char (&test_ptr_to_const(void const *))[2];

            template<typename U> char test_V_is_a_U(U *);
            template<typename U> char test_V_is_a_U(U const *);
            template<typename U> char (&test_V_is_a_U(...))[2];

            ////////////////////////////////////////////////////////////////////////////////////////////
            // result_of_ is a wrapper around streams_boost::result_of that also handles "invocations" of
            // member object pointers.
            template<typename T, typename Void = void>
            struct result_of_
              : streams_boost::result_of<T>
            {};

            template<typename T, typename U, typename V>
            struct result_of_<T U::*(V), typename enable_if_c<is_member_object_pointer<T U::*>::value>::type>
            {
                STREAMS_BOOST_STATIC_CONSTANT(bool, is_V_a_smart_ptr = 2 == sizeof(test_V_is_a_U<U>(&lvalue(make<V>()))));
                STREAMS_BOOST_STATIC_CONSTANT(bool, is_ptr_to_const = 2 == sizeof(test_ptr_to_const(STREAMS_BOOST_PROTO_GET_POINTER(U, make<V>()))));

                // If V is not a U, then it is a (smart) pointer and we can always return an lvalue.
                // Otherwise, we can only return an lvalue if we are given one.
                typedef
                    typename mpl::eval_if_c<
                        (is_V_a_smart_ptr || is_reference<V>::value)
                      , mpl::eval_if_c<
                            is_ptr_to_const
                          , add_reference<typename add_const<T>::type>
                          , add_reference<T>
                        >
                      , mpl::identity<T>
                    >::type
                type;
            };

            ////////////////////////////////////////////////////////////////////////////////////////////
            template<
                typename T
              , typename U
              , bool IsMemPtr = is_member_object_pointer<
                    typename remove_reference<U>::type
                >::value
            >
            struct mem_ptr_fun
            {
                STREAMS_BOOST_PROTO_DECLTYPE_(
                    proto::detail::make_mutable<T>() ->* proto::detail::make<U>()
                  , result_type
                )

                result_type operator()(
                    typename add_reference<typename add_const<T>::type>::type t
                  , typename add_reference<typename add_const<U>::type>::type u
                ) const
                {
                    return t ->* u;
                }
            };

            ////////////////////////////////////////////////////////////////////////////////////////////
            template<typename T, typename U>
            struct mem_ptr_fun<T, U, true>
            {
                typedef
                    typename classtypeof<
                        typename remove_const<
                            typename remove_reference<U>::type
                        >::type
                    >::type
                V;

                STREAMS_BOOST_PROTO_DECLTYPE_(
                    STREAMS_BOOST_PROTO_GET_POINTER(V, proto::detail::make_mutable<T>()) ->* proto::detail::make<U>()
                  , result_type
                )

                result_type operator()(
                    typename add_reference<typename add_const<T>::type>::type t
                  , U u
                ) const
                {
                    return STREAMS_BOOST_PROTO_GET_POINTER(V, t) ->* u;
                }
            };
        }

        using get_pointerns::result_of_;
        using get_pointerns::mem_ptr_fun;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename A0, typename A1>
        struct comma_result
        {
            STREAMS_BOOST_PROTO_DECLTYPE_((proto::detail::make<A0>(), proto::detail::make<A1>()), type)
        };

        template<typename A0>
        struct comma_result<A0, void>
        {
            typedef void type;
        };

        template<typename A1>
        struct comma_result<void, A1>
        {
            typedef A1 type;
        };

        template<>
        struct comma_result<void, void>
        {
            typedef void type;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        // normalize a function type for use with streams_boost::result_of
        template<typename T, typename U = T>
        struct result_of_fixup
          : mpl::if_c<is_function<T>::value, T *, U>
        {};

        template<typename T, typename U>
        struct result_of_fixup<T &, U>
          : result_of_fixup<T, T>
        {};

        template<typename T, typename U>
        struct result_of_fixup<T const &, U>
          : result_of_fixup<T, T>
        {};

        template<typename T, typename U>
        struct result_of_fixup<T *, U>
          : result_of_fixup<T, U>
        {};

        template<typename R, typename T, typename U>
        struct result_of_fixup<R T::*, U>
        {
            typedef R T::*type;
        };

        template<typename T, typename U>
        struct result_of_fixup<T const, U>
          : result_of_fixup<T, U>
        {};

        //// Tests for result_of_fixup
        //struct bar {};
        //STREAMS_BOOST_MPL_ASSERT((is_same<bar,        result_of_fixup<bar>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<bar const,  result_of_fixup<bar const>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<bar,        result_of_fixup<bar &>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<bar const,  result_of_fixup<bar const &>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<void(*)(),  result_of_fixup<void(*)()>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<void(*)(),  result_of_fixup<void(* const)()>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<void(*)(),  result_of_fixup<void(* const &)()>::type>));
        //STREAMS_BOOST_MPL_ASSERT((is_same<void(*)(),  result_of_fixup<void(&)()>::type>));

        template<typename T, typename PMF>
        struct memfun
        {
            typedef typename remove_const<typename remove_reference<PMF>::type>::type pmf_type;
            typedef typename classtypeof<pmf_type>::type V;
            typedef typename streams_boost::result_of<pmf_type(T)>::type result_type;

            memfun(T t, PMF p)
              : obj(t)
              , pmf(p)
            {}

            result_type operator()() const
            {
                STREAMS_BOOST_PROTO_USE_GET_POINTER();
                return (STREAMS_BOOST_PROTO_GET_POINTER(V, obj) ->* pmf)();
            }

            #define STREAMS_BOOST_PROTO_LOCAL_MACRO(N, typename_A, A_const_ref, A_const_ref_a, a)           \
            template<typename_A(N)>                                                                 \
            result_type operator()(A_const_ref_a(N)) const                                          \
            {                                                                                       \
                STREAMS_BOOST_PROTO_USE_GET_POINTER();                                                      \
                return (STREAMS_BOOST_PROTO_GET_POINTER(V, obj) ->* pmf)(a(N));                             \
            }                                                                                       \
            /**/
            #define STREAMS_BOOST_PROTO_LOCAL_a STREAMS_BOOST_PROTO_a
            #define STREAMS_BOOST_PROTO_LOCAL_LIMITS (1, STREAMS_BOOST_PROTO_MAX_ARITY)
            #include STREAMS_BOOST_PROTO_LOCAL_ITERATE()

        private:
            T obj;
            PMF pmf;
        };

    } // namespace detail
}}

#endif
