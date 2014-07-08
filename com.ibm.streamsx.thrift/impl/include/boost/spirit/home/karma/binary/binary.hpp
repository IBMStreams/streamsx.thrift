//  Copyright (c) 2001-2010 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_KARMA_BINARY_MAY_04_2007_0904AM)
#define STREAMS_BOOST_SPIRIT_KARMA_BINARY_MAY_04_2007_0904AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/support/common_terminals.hpp>
#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/spirit/home/support/detail/endian.hpp>

#include <streams_boost/spirit/home/karma/domain.hpp>
#include <streams_boost/spirit/home/karma/meta_compiler.hpp>
#include <streams_boost/spirit/home/karma/delimit_out.hpp>
#include <streams_boost/spirit/home/karma/auxiliary/lazy.hpp>
#include <streams_boost/spirit/home/karma/detail/generate_to.hpp>
#include <streams_boost/spirit/home/karma/detail/extract_from.hpp>
#include <streams_boost/spirit/home/support/unused.hpp>
#include <streams_boost/spirit/home/support/container.hpp>
#include <streams_boost/fusion/include/vector.hpp>
#include <streams_boost/fusion/include/at.hpp>
#include <streams_boost/mpl/or.hpp>
#include <streams_boost/type_traits/is_integral.hpp>
#include <streams_boost/type_traits/is_enum.hpp>
#include <streams_boost/config.hpp>

///////////////////////////////////////////////////////////////////////////////
#define STREAMS_BOOST_SPIRIT_ENABLE_BINARY(name)                                      \
    template <>                                                               \
    struct use_terminal<karma::domain, tag::name>                             \
      : mpl::true_ {};                                                        \
                                                                              \
    template <typename A0>                                                    \
    struct use_terminal<karma::domain                                         \
        , terminal_ex<tag::name, fusion::vector1<A0> > >                      \
      : mpl::or_<is_integral<A0>, is_enum<A0> > {};                           \
                                                                              \
    template <>                                                               \
    struct use_lazy_terminal<karma::domain, tag::name, 1> : mpl::true_ {};    \
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

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit { namespace karma
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
            static info is()
            {
                return info("native-endian binary");
            }
        };

        template <>
        struct what<streams_boost::integer::endianness::little>
        {
            static info is()
            {
                return info("little-endian binary");
            }
        };

        template <>
        struct what<streams_boost::integer::endianness::big>
        {
            static info is()
            {
                return info("big-endian binary");
            }
        };
    }

    ///////////////////////////////////////////////////////////////////////////
    template <STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
    struct any_binary_generator 
      : primitive_generator<any_binary_generator<endian, bits> >
    {
        template <typename Context, typename Unused = unused_type>
        struct attribute 
          : karma::detail::integer<bits>
        {};

        template <
            typename OutputIterator, typename Context, typename Delimiter
          , typename Attribute>
        static bool generate(OutputIterator& sink, Context& context
          , Delimiter const& d, Attribute const& attr)
        {
            if (!traits::has_optional_value(attr))
                return false;

            // Even if the endian types are not pod's (at least not in the
            // definition of C++03) it seems to be safe to assume they are.
            // This allows us to treat them as a sequence of consecutive bytes.
            streams_boost::integer::endian<
                endian, typename karma::detail::integer<bits>::type, bits
            > p;

#if defined(STREAMS_BOOST_MSVC)
// warning C4244: 'argument' : conversion from 'const int' to 'foo', possible loss of data
#pragma warning(push)
#pragma warning(disable: 4244)
#endif
            p = traits::extract_from(attr, context);
#if defined(STREAMS_BOOST_MSVC)
#pragma warning(pop)
#endif

            unsigned char const* bytes =
                reinterpret_cast<unsigned char const*>(&p);

            for (unsigned int i = 0; i < sizeof(p); ++i) 
            {
                if (!detail::generate_to(sink, *bytes++))
                    return false;
            }
            return karma::delimit_out(sink, d);     // always do post-delimiting
        }

        // this any_byte_director has no parameter attached, it needs to have
        // been initialized from a direct literal
        template <
            typename OutputIterator, typename Context, typename Delimiter>
        static bool generate(OutputIterator& sink, Context&, Delimiter const& d
          , unused_type)
        {
            // It is not possible (doesn't make sense) to use binary generators 
            // without providing any attribute, as the generator doesn't 'know' 
            // what to output. The following assertion fires if this situation
            // is detected in your code.
            STREAMS_BOOST_SPIRIT_ASSERT_MSG(false,
                binary_generator_not_usable_without_attribute, ());
            return false;
        }

        template <typename Context>
        static info what(Context const& /*context*/)
        {
            return karma::detail::what<endian>::is();
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
    struct literal_binary_generator
      : primitive_generator<literal_binary_generator<endian, bits> >
    {
        template <typename Context, typename Unused>
        struct attribute
        {
            typedef unused_type type;
        };

        template <typename T>
        literal_binary_generator(T const& t)
        {
#if defined(STREAMS_BOOST_MSVC)
// warning C4244: 'argument' : conversion from 'const int' to 'foo', possible loss of data
#pragma warning(push)
#pragma warning(disable: 4244)
#endif
            data_ = t;
#if defined(STREAMS_BOOST_MSVC)
#pragma warning(pop)
#endif
        }

        template <
            typename OutputIterator, typename Context, typename Delimiter
          , typename Attribute>
        bool generate(OutputIterator& sink, Context&, Delimiter const& d
          , Attribute const&) const
        {
            // Even if the endian types are not pod's (at least not in the
            // definition of C++03) it seems to be safe to assume they are
            // (but in C++0x the endian types _are_ PODs).
            // This allows us to treat them as a sequence of consecutive bytes.
            unsigned char const* bytes =
                reinterpret_cast<unsigned char const*>(&data_);

            for (unsigned int i = 0; i < sizeof(data_type); ++i)
            {
                if (!detail::generate_to(sink, *bytes++))
                    return false;
            }
            return karma::delimit_out(sink, d);  // always do post-delimiting
        }

        template <typename Context>
        static info what(Context const& /*context*/)
        {
            return karma::detail::what<endian>::is();
        }

        typedef streams_boost::integer::endian<
            endian, typename karma::detail::integer<bits>::type, bits
        > data_type;

        data_type data_;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Generator generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    namespace detail
    {
        template <STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian
          , int bits>
        struct basic_binary
        {
            typedef any_binary_generator<endian, bits> result_type;

            result_type operator()(unused_type, unused_type) const
            {
                return result_type();
            }
        };

        template <typename Modifiers
          , STREAMS_BOOST_SCOPED_ENUM(streams_boost::integer::endianness) endian, int bits>
        struct basic_binary_literal
        {
            typedef literal_binary_generator<endian, bits> result_type;

            template <typename Terminal>
            result_type operator()(Terminal const& term, unused_type) const
            {
                return result_type(fusion::at_c<0>(term.args));
            }
        };
    }

#define STREAMS_BOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(name, endian, bits)                \
    template <typename Modifiers>                                             \
    struct make_primitive<tag::name, Modifiers>                               \
      : detail::basic_binary<streams_boost::integer::endianness::endian, bits> {};    \
                                                                              \
    template <typename Modifiers, typename A0>                                \
    struct make_primitive<terminal_ex<tag::name, fusion::vector1<A0> >        \
          , Modifiers>                                                        \
      : detail::basic_binary_literal<Modifiers                                \
        , streams_boost::integer::endianness::endian, bits> {};                       \
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
