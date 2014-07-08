/*=============================================================================
    Copyright (c) 2001-2010 Hartmut Kaiser
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_BINARY_MAY_08_2007_0808AM)
#define STREAMS_BOOST_SPIRIT_BINARY_MAY_08_2007_0808AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/support/common_terminals.hpp>
#include <streams_boost/spirit/home/support/detail/endian.hpp>
#include <streams_boost/spirit/home/support/attributes.hpp>
#include <streams_boost/spirit/home/qi/parser.hpp>
#include <streams_boost/spirit/home/qi/meta_compiler.hpp>
#include <streams_boost/spirit/home/qi/domain.hpp>
#include <streams_boost/spirit/home/qi/detail/assign_to.hpp>
#include <streams_boost/spirit/home/qi/skip_over.hpp>
#include <streams_boost/spirit/home/support/common_terminals.hpp>
#include <streams_boost/fusion/include/at.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/type_traits/is_enum.hpp>
#include <streams_boost/config.hpp>

#define STREAMS_BOOST_SPIRIT_ENABLE_BINARY(name)                                        \
    template <>                                                                 \
    struct use_terminal<qi::domain, tag::name>                                  \
      : mpl::true_ {};                                                          \
                                                                                \
    template <typename A0>                                                      \
    struct use_terminal<qi::domain                                              \
        , terminal_ex<tag::name, fusion::vector1<A0> > >                        \
      : mpl::or_<is_integral<A0>, is_enum<A0> > {};                             \
                                                                                \
    template <>                                                                 \
    struct use_lazy_terminal<qi::domain, tag::name, 1> : mpl::true_ {};         \
                                                                                \
/***/

namespace streams_boost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(byte_)                   // enables byte_
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(word)                    // enables word
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(big_word)                // enables big_word
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(little_word)             // enables little_word
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(dword)                   // enables dword
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(big_dword)               // enables big_dword
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(little_dword)            // enables little_dword
#ifdef STREAMS_BOOST_HAS_LONG_LONG
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(qword)                   // enables qword
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(big_qword)               // enables big_qword
    STREAMS_BOOST_SPIRIT_ENABLE_BINARY(little_qword)            // enables little_qword
#endif
}}

#undef STREAMS_BOOST_SPIRIT_ENABLE_BINARY

namespace streams_boost { namespace spirit { namespace qi
{
    using streams_boost::spirit::byte_;
    using streams_boost::spirit::byte__type;
    using streams_boost::spirit::word;
    using streams_boost::spirit::word_type;
    using streams_boost::spirit::big_word;
    using streams_boost::spirit::big_word_type;
    using streams_boost::spirit::little_word;
    using streams_boost::spirit::little_word_type;
    using streams_boost::spirit::dword;
    using streams_boost::spirit::dword_type;
    using streams_boost::spirit::big_dword;
    using streams_boost::spirit::big_dword_type;
    using streams_boost::spirit::little_dword;
    using streams_boost::spirit::little_dword_type;
#ifdef STREAMS_BOOST_HAS_LONG_LONG
    using streams_boost::spirit::qword;
    using streams_boost::spirit::qword_type;
    using streams_boost::spirit::big_qword;
    using streams_boost::spirit::big_qword_type;
    using streams_boost::spirit::little_qword;
    using streams_boost::spirit::little_qword_type;
#endif

    namespace detail
    {
        template <int bits>
        struct integer
        {
#ifdef STREAMS_BOOST_HAS_LONG_LONG
            STREAMS_BOOST_SPIRIT_ASSERT_MSG(
                bits == 8 || bits == 16 || bits == 32 || bits == 64,
                not_supported_binary_size, ());
#else
            STREAMS_BOOST_SPIRIT_ASSERT_MSG(
                bits == 8 || bits == 16 || bits == 32,
                not_supported_binary_size, ());
#endif
        };

        template <>
        struct integer<8>
        {
            typedef uint_least8_t type;
        };

        template <>
        struct integer<16>
        {
            typedef uint_least16_t type;
        };

        template <>
        struct integer<32>
        {
            typedef uint_least32_t type;
        };

#ifdef STREAMS_BOOST_HAS_LONG_LONG
        template <>
        struct integer<64>
        {
            typedef uint_least64_t type;
        };
#endif

        ///////////////////////////////////////////////////////////////////////
        template <STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) bits>
        struct what;

        template <>
        struct what<streams_boost::integer::endianness::native>
        {
            static std::string is()
            {
                return "native-endian binary";
            }
        };

        template <>
        struct what<streams_boost::integer::endianness::little>
        {
            static char const* is()
            {
                return "little-endian binary";
            }
        };

        template <>
        struct what<streams_boost::integer::endianness::big>
        {
            static char const* is()
            {
                return "big-endian binary";
            }
        };
    }

    ///////////////////////////////////////////////////////////////////////////
    template <STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
    struct any_binary_parser : primitive_parser<any_binary_parser<endian, bits> >
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef streams_boost::integer::endian<
                endian, typename qi::detail::integer<bits>::type, bits
            > type;
        };

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& attr) const
        {
            qi::skip_over(first, last, skipper);

            typename attribute<Context, Iterator>::type attr_;
            unsigned char* bytes = reinterpret_cast<unsigned char*>(&attr_);

            Iterator it = first;
            for (unsigned int i = 0; i < sizeof(attr_); ++i)
            {
                if (it == last)
                    return false;
                *bytes++ = *it++;
            }

            first = it;
            spirit::traits::assign_to(attr_, attr);
            return true;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info(qi::detail::what<endian>::is());
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename Int
      , STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
    struct binary_lit_parser
      : primitive_parser<binary_lit_parser<Int, endian, bits> >
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef unused_type type;
        };

        binary_lit_parser(Int n)
          : n(n) {}

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& attr) const
        {
            qi::skip_over(first, last, skipper);

            // Even if the endian types are not pod's (at least not in the
            // definition of C++03) it seems to be safe to assume they are
            // (but in C++0x the endian types _are_ PODs).
            // This allows us to treat them as a sequence of consecutive bytes.
            streams_boost::integer::endian<
                endian, typename qi::detail::integer<bits>::type, bits> attr_;

#if defined(STREAMS_BOOST_MSVC)
// warning C4244: 'argument' : conversion from 'const int' to 'foo', possible loss of data
#pragma warning(push)
#pragma warning(disable: 4244)
#endif
            attr_ = n;
#if defined(STREAMS_BOOST_MSVC)
#pragma warning(pop)
#endif

            unsigned char* bytes = reinterpret_cast<unsigned char*>(&attr_);

            Iterator it = first;
            for (unsigned int i = 0; i < sizeof(attr_); ++i)
            {
                if (it == last || *bytes++ != static_cast<unsigned char>(*it++))
                    return false;
            }

            first = it;
            spirit::traits::assign_to(attr_, attr);
            return true;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info(qi::detail::what<endian>::is());
        }

        Int n;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
    struct make_binary_parser
    {
        typedef any_binary_parser<endian, bits> result_type;
        result_type operator()(unused_type, unused_type) const
        {
            return result_type();
        }
    };

    template <typename Int
      , STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
    struct make_binary_lit_parser
    {
        typedef binary_lit_parser<Int, endian, bits> result_type;
        template <typename Terminal>
        result_type operator()(Terminal const& term, unused_type) const
        {
            return result_type(fusion::at_c<0>(term.args));
        }
    };

#define STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(name, endian, bits)                  \
    template <typename Modifiers>                                               \
    struct make_primitive<tag::name, Modifiers>                                 \
      : make_binary_parser<streams_boost::integer::endianness::endian, bits> {};        \
                                                                                \
    template <typename Modifiers, typename A0>                                  \
    struct make_primitive<                                                      \
        terminal_ex<tag::name, fusion::vector1<A0> > , Modifiers>               \
      : make_binary_lit_parser<A0, streams_boost::integer::endianness::endian, bits> {};\
                                                                                \
    /***/

    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(byte_, native, 8)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(word, native, 16)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(big_word, big, 16)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(little_word, little, 16)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(dword, native, 32)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(big_dword, big, 32)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(little_dword, little, 32)
#ifdef STREAMS_BOOST_HAS_LONG_LONG
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(qword, native, 64)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(big_qword, big, 64)
    STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(little_qword, little, 64)
#endif

#undef STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE

}}}

#endif
