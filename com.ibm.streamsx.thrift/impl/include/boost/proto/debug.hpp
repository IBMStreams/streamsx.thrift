///////////////////////////////////////////////////////////////////////////////
/// \file debug.hpp
/// Utilities for debugging Proto expression trees
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROTO_DEBUG_HPP_EAN_12_31_2006
#define STREAMS_BOOST_PROTO_DEBUG_HPP_EAN_12_31_2006

#include <streams_boost/preprocessor/iteration/local.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <streams_boost/proto/proto_fwd.hpp>
#include <streams_boost/proto/expr.hpp>
#include <streams_boost/proto/traits.hpp>
#include <streams_boost/proto/detail/dont_care.hpp>

namespace streams_boost { namespace proto
{
    namespace tag
    {
        namespace hidden_detail_
        {
            typedef char (&not_ostream)[sizeof(std::ostream)+1];
            not_ostream operator<<(std::ostream &, detail::dont_care);

            template<typename Tag, std::size_t S>
            struct printable_tag_
            {
                typedef char const *type;
                static type call() { return typeid(Tag).name(); }
            };

            template<typename Tag>
            struct printable_tag_<Tag, sizeof(std::ostream)>
            {
                typedef Tag type;
                static type call() { return Tag(); }
            };

            template<typename Tag>
            struct printable_tag
              : printable_tag_<Tag, sizeof(std::cout << Tag())>
            {};
        }

        /// INTERNAL ONLY
        template<typename Tag>
        inline typename hidden_detail_::printable_tag<Tag>::type proto_tag_name(Tag)
        {
            return hidden_detail_::printable_tag<Tag>::call();
        }

    #define STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(Tag)                                    \
        /** \brief INTERNAL ONLY */                                             \
        inline char const *proto_tag_name(tag::Tag)                             \
        {                                                                       \
            return #Tag;                                                        \
        }                                                                       \
        /**/

        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(terminal)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(unary_plus)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(negate)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(dereference)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(complement)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(address_of)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(logical_not)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(pre_inc)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(pre_dec)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(post_inc)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(post_dec)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(shift_left)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(shift_right)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(multiplies)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(divides)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(modulus)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(plus)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(minus)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(less)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(greater)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(less_equal)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(greater_equal)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(equal_to)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(not_equal_to)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(logical_or)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(logical_and)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(bitwise_and)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(bitwise_or)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(bitwise_xor)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(comma)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(mem_ptr)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(shift_left_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(shift_right_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(multiplies_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(divides_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(modulus_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(plus_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(minus_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(bitwise_and_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(bitwise_or_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(bitwise_xor_assign)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(subscript)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(member)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(if_else_)
        STREAMS_BOOST_PROTO_DEFINE_TAG_NAME(function)

    #undef STREAMS_BOOST_PROTO_DEFINE_TAG_NAME
    }

    namespace functional
    {
        /// \brief Pretty-print a Proto expression tree.
        ///
        /// A PolymorphicFunctionObject which accepts a Proto expression
        /// tree and pretty-prints it to an \c ostream for debugging
        /// purposes.
        struct display_expr
        {
            typedef void result_type;

            /// \param sout  The \c ostream to which the expression tree
            ///              will be written.
            /// \param depth The starting indentation depth for this node.
            ///              Children nodes will be displayed at a starting
            ///              depth of <tt>depth+4</tt>.
            explicit display_expr(std::ostream &sout = std::cout, int depth = 0)
              : depth_(depth)
              , first_(true)
              , sout_(sout)
            {}

            /// \brief Pretty-print the current node in a Proto expression
            /// tree.
            template<typename Tag, typename Args>
            void operator()(proto::expr<Tag, Args, 0> const &expr) const
            {
                using namespace tag;
                this->sout_ << std::setw(this->depth_) << (this->first_? "" : ", ")
                    << proto_tag_name(Tag()) << "(" << proto::value(expr) << ")\n";
                this->first_ = false;
            }

        #define STREAMS_BOOST_PROTO_CHILD(Z, N, DATA)                                                       \
            display(proto::child_c<N>(expr));                                                       \
            /**/

        #define STREAMS_BOOST_PP_LOCAL_MACRO(N)                                                             \
            /** \overload */                                                                        \
            template<typename Tag, typename Args>                                                   \
            void operator()(proto::expr<Tag, Args, N> const &expr) const                            \
            {                                                                                       \
                using namespace tag;                                                                \
                this->sout_ << std::setw(this->depth_) << (this->first_? "" : ", ")                 \
                    << proto_tag_name(Tag()) << "(\n";                                              \
                display_expr display(this->sout_, this->depth_ + 4);                                \
                STREAMS_BOOST_PP_REPEAT(N, STREAMS_BOOST_PROTO_CHILD, _)                                            \
                this->sout_ << std::setw(this->depth_) << "" << ")\n";                              \
                this->first_ = false;                                                               \
            }                                                                                       \
            /**/

        #define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_PROTO_MAX_ARITY)
        #include STREAMS_BOOST_PP_LOCAL_ITERATE()
        #undef STREAMS_BOOST_PROTO_CHILD

            /// \overload
            ///
            template<typename T>
            void operator()(T const &t) const
            {
                (*this)(t.proto_base());
            }

        private:
            display_expr &operator =(display_expr const &);
            int depth_;
            mutable bool first_;
            std::ostream &sout_;
        };
    }

    /// \brief Pretty-print a Proto expression tree.
    ///
    /// \note Equivalent to <tt>functional::display_expr(0, sout)(expr)</tt>
    /// \param expr The Proto expression tree to pretty-print
    /// \param sout The \c ostream to which the output should be
    ///             written. If not specified, defaults to
    ///             <tt>std::cout</tt>.
    template<typename Expr>
    void display_expr(Expr const &expr, std::ostream &sout)
    {
        functional::display_expr(sout, 0)(expr);
    }

    /// \overload
    ///
    template<typename Expr>
    void display_expr(Expr const &expr)
    {
        functional::display_expr()(expr);
    }

}}

#endif
