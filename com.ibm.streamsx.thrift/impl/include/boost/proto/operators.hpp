///////////////////////////////////////////////////////////////////////////////
/// \file operators.hpp
/// Contains all the overloaded operators that make it possible to build
/// Proto expression trees.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROTO_OPERATORS_HPP_EAN_04_01_2005
#define STREAMS_BOOST_PROTO_OPERATORS_HPP_EAN_04_01_2005

#include <streams_boost/preprocessor/punctuation/comma.hpp>
#include <streams_boost/preprocessor/seq/seq.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/proto/proto_fwd.hpp>
#include <streams_boost/proto/tags.hpp>
#include <streams_boost/proto/expr.hpp>
#include <streams_boost/proto/matches.hpp>
#include <streams_boost/proto/generate.hpp>
#include <streams_boost/proto/make_expr.hpp>

namespace streams_boost { namespace proto
{
    namespace detail
    {
        template<typename Domain1, typename Domain2>
        struct choose_domain2
        {
            STREAMS_BOOST_MPL_ASSERT((streams_boost::is_same<Domain1, Domain2>));
            typedef Domain1 type;
        };

        template<typename Domain1>
        struct choose_domain2<Domain1, proto::default_domain>
        {
            typedef Domain1 type;
        };

        template<typename Domain2>
        struct choose_domain2<proto::default_domain, Domain2>
        {
            typedef Domain2 type;
        };

        template<>
        struct choose_domain2<proto::default_domain, proto::default_domain>
        {
            typedef proto::default_domain type;
        };

        template<typename Domain, typename Expr, typename EnableIf = void>
        struct generate_if
          : lazy_enable_if_c<
                matches<Expr, typename Domain::proto_grammar>::value
              , typename Domain::template result<Domain(Expr)>
            >
        {};

        // Optimization, generate fewer templates...
        template<typename Expr>
        struct generate_if<proto::default_domain, Expr, void>
        {
            typedef Expr type;
        };

        template<typename Domain, typename Tag, typename Left, typename Right>
        struct generate_if_left
          : lazy_enable_if_c<
                matches<proto::expr<Tag, proto::list2<Left &, Right>, 2>, typename Domain::proto_grammar>::value
              , typename Domain::template result<Domain(
                    proto::expr<Tag, proto::list2<Left &, typename Domain::template result<Domain(Right)>::type>, 2>
                )>
            >
        {};

        // Optimization, generate fewer templates...
        template<typename Tag, typename Left, typename Right>
        struct generate_if_left<proto::default_domain, Tag, Left, Right>
        {
            typedef proto::expr<Tag, proto::list2<Left &, Right>, 2> type;
        };

        template<typename Domain, typename Tag, typename Left, typename Right>
        struct generate_if_right
          : lazy_enable_if_c<
                matches<proto::expr<Tag, proto::list2<Left, Right &>, 2>, typename Domain::proto_grammar>::value
              , typename Domain::template result<Domain(
                    proto::expr<Tag, proto::list2<typename Domain::template result<Domain(Left)>::type, Right &>, 2>
                )>
            >
        {};

        // Optimization, generate fewer templates...
        template<typename Tag, typename Left, typename Right>
        struct generate_if_right<proto::default_domain, Tag, Left, Right>
        {
            typedef proto::expr<Tag, proto::list2<Left, Right &>, 2> type;
        };

        template<typename Tag, typename Left, typename Right, typename Enable1 = void, typename Enable2 = void>
        struct as_expr_if2
        {};

        template<typename Tag, typename Left, typename Right>
        struct as_expr_if2<Tag, Left, Right, typename Left::proto_is_expr_, void>
          : generate_if_left<
                typename Left::proto_domain
              , Tag
              , Left
              , proto::expr<tag::terminal, term<Right &>, 0>
            >
        {
            typedef proto::expr<tag::terminal, term<Right &>, 0> term_type;
            typedef typename Left::proto_domain proto_domain;
            typedef proto::expr<Tag, list2<Left &, typename proto_domain::template result<proto_domain(term_type)>::type>, 2> expr_type;

            static typename proto_domain::template result<proto_domain(expr_type)>::type
            make(Left &left, Right &right)
            {
                term_type term = {right};
                expr_type that = {left, proto_domain()(term)};
                return proto_domain()(that);
            }
        };

        template<typename Tag, typename Left, typename Right>
        struct as_expr_if2<Tag, Left, Right, void, typename Right::proto_is_expr_>
          : generate_if_right<
                typename Right::proto_domain
              , Tag
              , proto::expr<tag::terminal, term<Left &>, 0>
              , Right
            >
        {
            typedef proto::expr<tag::terminal, term<Left &>, 0> term_type;
            typedef typename Right::proto_domain proto_domain;
            typedef proto::expr<Tag, list2<typename proto_domain::template result<proto_domain(term_type)>::type, Right &>, 2> expr_type;

            static typename proto_domain::template result<proto_domain(expr_type)>::type
            make(Left &left, Right &right)
            {
                term_type term = {left};
                expr_type that = {proto_domain()(term), right};
                return proto_domain()(that);
            }
        };

        template<typename Tag, typename Left, typename Right, typename Enable1 = void, typename Enable2 = void>
        struct as_expr_if
          : as_expr_if2<Tag, Left, Right>
        {};

        template<typename Tag, typename Left, typename Right>
        struct as_expr_if<Tag, Left, Right, typename Left::proto_is_expr_, typename Right::proto_is_expr_>
          : generate_if<
                typename choose_domain2<typename Left::proto_domain, typename Right::proto_domain>::type
              , proto::expr<Tag, list2<Left &, Right &>, 2>
            >
        {
            typedef proto::expr<Tag, list2<Left &, Right &>, 2> expr_type;
            typedef typename choose_domain2<typename Left::proto_domain, typename Right::proto_domain>::type proto_domain;

            static typename proto_domain::template result<proto_domain(expr_type)>::type
            make(Left &left, Right &right)
            {
                expr_type that = {left, right};
                return proto_domain()(that);
            }
        };

        template<typename Arg, typename Trait, typename Enable = void>
        struct arg_weight
        {
            STREAMS_BOOST_STATIC_CONSTANT(int, value = 1 + Trait::value);
        };

        template<typename Arg, typename Trait>
        struct arg_weight<Arg, Trait, typename Arg::proto_is_expr_>
        {
            STREAMS_BOOST_STATIC_CONSTANT(int, value = 0);
        };

        template<typename Domain, typename Trait, typename Arg, typename Expr>
        struct enable_unary
          : streams_boost::enable_if_c<
                streams_boost::mpl::and_<Trait, streams_boost::proto::matches<Expr, typename Domain::proto_grammar> >::value
              , Expr
            >
        {};

        template<typename Trait, typename Arg, typename Expr>
        struct enable_unary<deduce_domain, Trait, Arg, Expr>
          : streams_boost::enable_if_c<
                streams_boost::mpl::and_<
                    Trait
                  , streams_boost::proto::matches<Expr, typename domain_of<Arg>::type::proto_grammar>
                >::value
              , Expr
            >
        {};

        template<typename Trait, typename Arg, typename Expr>
        struct enable_unary<default_domain, Trait, Arg, Expr>
          : streams_boost::enable_if_c<Trait::value, Expr>
        {};

        template<typename Domain, typename Trait1, typename Arg1, typename Trait2, typename Arg2, typename Expr>
        struct enable_binary
          : streams_boost::enable_if_c<
                streams_boost::mpl::and_<
                    mpl::bool_<(3 <= (arg_weight<Arg1, Trait1>::value + arg_weight<Arg2, Trait2>::value))>
                  , streams_boost::proto::matches<Expr, typename Domain::proto_grammar>
                >::value
              , Expr
            >
        {};

        template<typename Trait1, typename Arg1, typename Trait2, typename Arg2, typename Expr>
        struct enable_binary<deduce_domain, Trait1, Arg1, Trait2, Arg2, Expr>
          : streams_boost::enable_if_c<
                streams_boost::mpl::and_<
                    mpl::bool_<(3 <= (arg_weight<Arg1, Trait1>::value + arg_weight<Arg2, Trait2>::value))>
                  , streams_boost::proto::matches<Expr, typename deduce_domain2<Arg1, Arg2>::type::proto_grammar>
                >::value
              , Expr
            >
        {};

        template<typename Trait1, typename Arg1, typename Trait2, typename Arg2, typename Expr>
        struct enable_binary<default_domain, Trait1, Arg1, Trait2, Arg2, Expr>
          : streams_boost::enable_if_c<
                (3 <= (arg_weight<Arg1, Trait1>::value + arg_weight<Arg2, Trait2>::value))
              , Expr
            >
        {};

    } // detail

#define STREAMS_BOOST_PROTO_UNARY_OP_IS_POSTFIX_0
#define STREAMS_BOOST_PROTO_UNARY_OP_IS_POSTFIX_1 , int

#define STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(OP, TAG, POST)                                            \
    template<typename Arg>                                                                          \
    typename detail::generate_if<                                                                   \
        typename Arg::proto_domain                                                                  \
      , proto::expr<TAG, list1<Arg &>, 1>                                                           \
      , typename Arg::proto_is_expr_                                                                \
    >::type const                                                                                   \
    operator OP(Arg &arg STREAMS_BOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                                  \
    {                                                                                               \
        typedef proto::expr<TAG, list1<Arg &>, 1> that_type;                                        \
        that_type that = {arg};                                                                     \
        return typename Arg::proto_domain()(that);                                                  \
    }                                                                                               \
    template<typename Arg>                                                                          \
    typename detail::generate_if<                                                                   \
        typename Arg::proto_domain                                                                  \
      , proto::expr<TAG, list1<Arg const &>, 1>                                                     \
      , typename Arg::proto_is_expr_                                                                \
    >::type const                                                                                   \
    operator OP(Arg const &arg STREAMS_BOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                            \
    {                                                                                               \
        typedef proto::expr<TAG, list1<Arg const &>, 1> that_type;                                  \
        that_type that = {arg};                                                                     \
        return typename Arg::proto_domain()(that);                                                  \
    }                                                                                               \
    /**/

#define STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(OP, TAG)                                                 \
    template<typename Left, typename Right>                                                         \
    inline typename detail::as_expr_if<TAG, Left, Right>::type const                                \
    operator OP(Left &left, Right &right)                                                           \
    {                                                                                               \
        return detail::as_expr_if<TAG, Left, Right>::make(left, right);                             \
    }                                                                                               \
    template<typename Left, typename Right>                                                         \
    inline typename detail::as_expr_if<TAG, Left, Right const>::type const                          \
    operator OP(Left &left, Right const &right)                                                     \
    {                                                                                               \
        return detail::as_expr_if<TAG, Left, Right const>::make(left, right);                       \
    }                                                                                               \
    template<typename Left, typename Right>                                                         \
    inline typename detail::as_expr_if<TAG, Left const, Right>::type const                          \
    operator OP(Left const &left, Right &right)                                                     \
    {                                                                                               \
        return detail::as_expr_if<TAG, Left const, Right>::make(left, right);                       \
    }                                                                                               \
    template<typename Left, typename Right>                                                         \
    inline typename detail::as_expr_if<TAG, Left const, Right const>::type const                    \
    operator OP(Left const &left, Right const &right)                                               \
    {                                                                                               \
        return detail::as_expr_if<TAG, Left const, Right const>::make(left, right);                 \
    }                                                                                               \
    /**/

    namespace exprns_
    {

        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(+, tag::unary_plus, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(-, tag::negate, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(*, tag::dereference, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(~, tag::complement, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(&, tag::address_of, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(!, tag::logical_not, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(++, tag::pre_inc, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(--, tag::pre_dec, 0)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(++, tag::post_inc, 1)
        STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(--, tag::post_dec, 1)

        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<<, tag::shift_left)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>>, tag::shift_right)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(*, tag::multiplies)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(/, tag::divides)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(%, tag::modulus)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(+, tag::plus)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(-, tag::minus)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<, tag::less)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>, tag::greater)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<=, tag::less_equal)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>=, tag::greater_equal)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(==, tag::equal_to)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(!=, tag::not_equal_to)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(||, tag::logical_or)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(&&, tag::logical_and)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(&, tag::bitwise_and)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(|, tag::bitwise_or)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(^, tag::bitwise_xor)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(STREAMS_BOOST_PP_COMMA(), tag::comma)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(->*, tag::mem_ptr)

        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<<=, tag::shift_left_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>>=, tag::shift_right_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(*=, tag::multiplies_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(/=, tag::divides_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(%=, tag::modulus_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(+=, tag::plus_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(-=, tag::minus_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(&=, tag::bitwise_and_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(|=, tag::bitwise_or_assign)
        STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(^=, tag::bitwise_xor_assign)

        /// if_else
        ///
        template<typename A0, typename A1, typename A2>
        typename functional::make_expr<tag::if_else_>::impl<A0 const &, A1 const &, A2 const &>::result_type const
        if_else(A0 const &a0, A1 const &a1, A2 const &a2)
        {
            return functional::make_expr<tag::if_else_>::impl<A0 const &, A1 const &, A2 const &>()(a0, a1, a2);
        }
    }

    using exprns_::if_else;

#undef STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR
#undef STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR

#define STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(OP, TAG, TRAIT, DOMAIN, POST)                             \
    template<typename Arg>                                                                          \
    typename streams_boost::proto::detail::enable_unary<DOMAIN, TRAIT<Arg>, Arg                             \
        , typename streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Arg &>::result_type       \
    >::type const                                                                                   \
    operator OP(Arg &arg STREAMS_BOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                                  \
    {                                                                                               \
        return streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Arg &>()(arg);                \
    }                                                                                               \
    template<typename Arg>                                                                          \
    typename streams_boost::proto::detail::enable_unary<DOMAIN, TRAIT<Arg>, Arg                             \
        , typename streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Arg const &>::result_type \
    >::type const                                                                                   \
    operator OP(Arg const &arg STREAMS_BOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                            \
    {                                                                                               \
        return streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Arg const &>()(arg);          \
    }                                                                                               \
    /**/

#define STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(OP, TAG, TRAIT, DOMAIN)                                  \
    template<typename Left, typename Right>                                                         \
    typename streams_boost::proto::detail::enable_binary<DOMAIN, TRAIT<Left>, Left, TRAIT<Right>, Right     \
        , typename streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left &, Right &>::result_type\
    >::type const                                                                                   \
    operator OP(Left &left, Right &right)                                                           \
    {                                                                                               \
        return streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left &, Right &>()(left, right);\
    }                                                                                               \
    template<typename Left, typename Right>                                                         \
    typename streams_boost::proto::detail::enable_binary<DOMAIN, TRAIT<Left>, Left, TRAIT<Right>, Right     \
        , typename streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left &, Right const &>::result_type\
    >::type const                                                                                   \
    operator OP(Left &left, Right const &right)                                                     \
    {                                                                                               \
        return streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left &, Right const &>()(left, right);\
    }                                                                                               \
    template<typename Left, typename Right>                                                         \
    typename streams_boost::proto::detail::enable_binary<DOMAIN, TRAIT<Left>, Left, TRAIT<Right>, Right     \
        , typename streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left const &, Right &>::result_type\
    >::type const                                                                                   \
    operator OP(Left const &left, Right &right)                                                     \
    {                                                                                               \
        return streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left const &, Right &>()(left, right);\
    }                                                                                               \
    template<typename Left, typename Right>                                                         \
    typename streams_boost::proto::detail::enable_binary<DOMAIN, TRAIT<Left>, Left, TRAIT<Right>, Right     \
        , typename streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left const &, Right const &>::result_type\
    >::type const                                                                                   \
    operator OP(Left const &left, Right const &right)                                               \
    {                                                                                               \
        return streams_boost::proto::functional::make_expr<TAG, DOMAIN>::impl<Left const &, Right const &>()(left, right);\
    }                                                                                               \
    /**/

#define STREAMS_BOOST_PROTO_DEFINE_OPERATORS(TRAIT, DOMAIN)                                                 \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(+, streams_boost::proto::tag::unary_plus, TRAIT, DOMAIN, 0)           \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(-, streams_boost::proto::tag::negate, TRAIT, DOMAIN, 0)               \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(*, streams_boost::proto::tag::dereference, TRAIT, DOMAIN, 0)          \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(~, streams_boost::proto::tag::complement, TRAIT, DOMAIN, 0)           \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(&, streams_boost::proto::tag::address_of, TRAIT, DOMAIN, 0)           \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(!, streams_boost::proto::tag::logical_not, TRAIT, DOMAIN, 0)          \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(++, streams_boost::proto::tag::pre_inc, TRAIT, DOMAIN, 0)             \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(--, streams_boost::proto::tag::pre_dec, TRAIT, DOMAIN, 0)             \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(++, streams_boost::proto::tag::post_inc, TRAIT, DOMAIN, 1)            \
    STREAMS_BOOST_PROTO_DEFINE_UNARY_OPERATOR(--, streams_boost::proto::tag::post_dec, TRAIT, DOMAIN, 1)            \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<<, streams_boost::proto::tag::shift_left, TRAIT, DOMAIN)            \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>>, streams_boost::proto::tag::shift_right, TRAIT, DOMAIN)           \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(*, streams_boost::proto::tag::multiplies, TRAIT, DOMAIN)             \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(/, streams_boost::proto::tag::divides, TRAIT, DOMAIN)                \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(%, streams_boost::proto::tag::modulus, TRAIT, DOMAIN)                \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(+, streams_boost::proto::tag::plus, TRAIT, DOMAIN)                   \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(-, streams_boost::proto::tag::minus, TRAIT, DOMAIN)                  \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<, streams_boost::proto::tag::less, TRAIT, DOMAIN)                   \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>, streams_boost::proto::tag::greater, TRAIT, DOMAIN)                \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<=, streams_boost::proto::tag::less_equal, TRAIT, DOMAIN)            \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>=, streams_boost::proto::tag::greater_equal, TRAIT, DOMAIN)         \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(==, streams_boost::proto::tag::equal_to, TRAIT, DOMAIN)              \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(!=, streams_boost::proto::tag::not_equal_to, TRAIT, DOMAIN)          \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(||, streams_boost::proto::tag::logical_or, TRAIT, DOMAIN)            \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(&&, streams_boost::proto::tag::logical_and, TRAIT, DOMAIN)           \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(&, streams_boost::proto::tag::bitwise_and, TRAIT, DOMAIN)            \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(|, streams_boost::proto::tag::bitwise_or, TRAIT, DOMAIN)             \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(^, streams_boost::proto::tag::bitwise_xor, TRAIT, DOMAIN)            \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(STREAMS_BOOST_PP_COMMA(), streams_boost::proto::tag::comma, TRAIT, DOMAIN)   \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(->*, streams_boost::proto::tag::mem_ptr, TRAIT, DOMAIN)              \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(<<=, streams_boost::proto::tag::shift_left_assign, TRAIT, DOMAIN)    \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(>>=, streams_boost::proto::tag::shift_right_assign, TRAIT, DOMAIN)   \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(*=, streams_boost::proto::tag::multiplies_assign, TRAIT, DOMAIN)     \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(/=, streams_boost::proto::tag::divides_assign, TRAIT, DOMAIN)        \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(%=, streams_boost::proto::tag::modulus_assign, TRAIT, DOMAIN)        \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(+=, streams_boost::proto::tag::plus_assign, TRAIT, DOMAIN)           \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(-=, streams_boost::proto::tag::minus_assign, TRAIT, DOMAIN)          \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(&=, streams_boost::proto::tag::bitwise_and_assign, TRAIT, DOMAIN)    \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(|=, streams_boost::proto::tag::bitwise_or_assign, TRAIT, DOMAIN)     \
    STREAMS_BOOST_PROTO_DEFINE_BINARY_OPERATOR(^=, streams_boost::proto::tag::bitwise_xor_assign, TRAIT, DOMAIN)    \
    /**/

    template<typename T>
    struct is_extension
      : mpl::false_
    {};

    namespace exops
    {
        STREAMS_BOOST_PROTO_DEFINE_OPERATORS(is_extension, default_domain)
        using proto::if_else;
    }

}}

#endif
