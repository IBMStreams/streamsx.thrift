
#ifndef STREAMS_BOOST_MPL_STRING_HPP_INCLUDED
#define STREAMS_BOOST_MPL_STRING_HPP_INCLUDED

// Copyright Eric Niebler 2009
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/mpl for documentation.

// $Id: string.hpp 49239 2009-04-01 09:10:26Z eric_niebler $
// $Date: 2009-04-01 02:10:26 -0700 (Wed, 1 Apr 2009) $
// $Revision: 49239 $
//
// Thanks to:
//   Dmitry Goncharov for porting this to the Sun compiler

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/detail/endian.hpp>
#include <streams_boost/mpl/limits/string.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/char.hpp>
#include <streams_boost/mpl/copy.hpp>
#include <streams_boost/mpl/size.hpp>
#include <streams_boost/mpl/empty.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/mpl/size_t.hpp>
#include <streams_boost/mpl/begin_end.hpp>
#include <streams_boost/mpl/joint_view.hpp>
#include <streams_boost/mpl/insert_range.hpp>
#include <streams_boost/mpl/back_inserter.hpp>
#include <streams_boost/mpl/front_inserter.hpp>
#include <streams_boost/mpl/iterator_range.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/arithmetic/add.hpp>
#include <streams_boost/preprocessor/arithmetic/div.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/repetition/repeat.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#include <iterator> // for bidirectional_iterator_tag
#include <climits>

namespace streams_boost { namespace mpl
{
    #define STREAMS_BOOST_MPL_STRING_MAX_PARAMS                                                             \
      STREAMS_BOOST_PP_DIV(STREAMS_BOOST_PP_ADD(STREAMS_BOOST_MPL_LIMIT_STRING_SIZE, 3), 4)

    // Low-level bit-twiddling is done by macros. Any implementation-defined behavior of
    // multi-character literals should be localized to these macros.

    #define STREAMS_BOOST_MPL_MULTICHAR_LENGTH(c)                                                           \
      (std::size_t)((c<CHAR_MIN) ? 4 : ((c>0xffffff)+(c>0xffff)+(c>0xff)+1))

    #if defined(STREAMS_BOOST_LITTLE_ENDIAN) && defined(__SUNPRO_CC)

        #define STREAMS_BOOST_MPL_MULTICHAR_AT(c,i)                                                         \
          (char)(0xff&((unsigned)(c)>>(8*(std::size_t)(i))))

        #define STREAMS_BOOST_MPL_MULTICHAR_PUSH_BACK(c,i)                                                  \
          ((((unsigned char)(i))<<(STREAMS_BOOST_MPL_MULTICHAR_LENGTH(c)*8))|(unsigned)(c))

        #define STREAMS_BOOST_MPL_MULTICHAR_PUSH_FRONT(c,i)                                                 \
          (((unsigned)(c)<<8)|(unsigned char)(i))

        #define STREAMS_BOOST_MPL_MULTICHAR_POP_BACK(c)                                                     \
          (((1<<((STREAMS_BOOST_MPL_MULTICHAR_LENGTH(c)-1)*8))-1)&(unsigned)(c))

        #define STREAMS_BOOST_MPL_MULTICHAR_POP_FRONT(c)                                                    \
          ((unsigned)(c)>>8)

    #else

        #define STREAMS_BOOST_MPL_MULTICHAR_AT(c,i)                                                         \
          (char)(0xff&((unsigned)(c)>>(8*(STREAMS_BOOST_MPL_MULTICHAR_LENGTH(c)-(std::size_t)(i)-1))))

        #define STREAMS_BOOST_MPL_MULTICHAR_PUSH_BACK(c,i)                                                  \
          (((unsigned)(c)<<8)|(unsigned char)(i))

        #define STREAMS_BOOST_MPL_MULTICHAR_PUSH_FRONT(c,i)                                                 \
          ((((unsigned char)(i))<<(STREAMS_BOOST_MPL_MULTICHAR_LENGTH(c)*8))|(unsigned)(c))

        #define STREAMS_BOOST_MPL_MULTICHAR_POP_BACK(c)                                                     \
          ((unsigned)(c)>>8)

        #define STREAMS_BOOST_MPL_MULTICHAR_POP_FRONT(c)                                                    \
          (((1<<((STREAMS_BOOST_MPL_MULTICHAR_LENGTH(c)-1)*8))-1)&(unsigned)(c))

    #endif

    struct string_tag;
    struct string_iterator_tag;

    template<STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C, 0)>
    struct string;

    template<typename Sequence, int I, int J>
    struct string_iterator;

    template<typename Sequence>
    struct sequence_tag;

    template<typename Tag>
    struct size_impl;

    template<>
    struct size_impl<mpl::string_tag>
    {
        template<typename Sequence>
        struct apply;

        #define M0(z, n, data)                                                                      \
        + STREAMS_BOOST_MPL_MULTICHAR_LENGTH(STREAMS_BOOST_PP_CAT(C,n))

        #define M1(z, n, data)                                                                      \
        template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, int C)>                                               \
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)> >                                 \
          : mpl::size_t<(0 STREAMS_BOOST_PP_REPEAT_ ## z(n, M0, ~))>                                        \
        {};

        STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_MPL_STRING_MAX_PARAMS), M1, ~)
        #undef M0
        #undef M1
    };

    template<>
    struct size_impl<mpl::string_tag>::apply<mpl::string<> >
      : mpl::size_t<0>
    {};

    template<typename Tag>
    struct begin_impl;

    template<>
    struct begin_impl<mpl::string_tag>
    {
        template<typename Sequence>
        struct apply
        {
            typedef mpl::string_iterator<Sequence, 0, 0> type;
        };
    };

    template<typename Tag>
    struct end_impl;

    template<>
    struct end_impl<mpl::string_tag>
    {
        template<typename Sequence>
        struct apply;

        #define M0(z,n,data)                                                                        \
        template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, int C)>                                               \
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)> >                                 \
        {                                                                                           \
            typedef mpl::string_iterator<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)>, n, 0> type;  \
        };

        STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_MPL_STRING_MAX_PARAMS), M0, ~)
        #undef M0
    };

    template<>
    struct end_impl<mpl::string_tag>::apply<mpl::string<> >
    {
        typedef mpl::string_iterator<mpl::string<>, 0, 0> type;
    };

    template<typename Tag>
    struct push_back_impl;

    template<>
    struct push_back_impl<mpl::string_tag>
    {
        template<typename Sequence, typename Value, bool B = (4==STREAMS_BOOST_MPL_MULTICHAR_LENGTH(Sequence::back_))>
        struct apply
        {
            STREAMS_BOOST_MPL_ASSERT_MSG(
                (STREAMS_BOOST_MPL_LIMIT_STRING_SIZE != mpl::size<Sequence>::type::value)
              , PUSH_BACK_FAILED_MPL_STRING_IS_FULL
              , (Sequence)
            );
            // If the above assertion didn't fire, then the string is sparse.
            // Repack the string and retry the push_back
            typedef
                typename mpl::push_back<
                    typename mpl::copy<
                        Sequence
                      , mpl::back_inserter<mpl::string<> >
                    >::type
                  , Value
                >::type
            type;
        };

        template<typename Value>
        struct apply<mpl::string<>, Value, false>
        {
            typedef mpl::string<(char)Value::value> type;
        };

        #define M0(z,n,data)                                                                        \
        template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, int C), typename Value>                               \
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)>, Value, false>                    \
        {                                                                                           \
            typedef                                                                                 \
                mpl::string<                                                                        \
                    STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), C)                                   \
                    STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n))                                              \
                    ((unsigned)STREAMS_BOOST_PP_CAT(C,STREAMS_BOOST_PP_DEC(n))>0xffffff)                            \
                    ?STREAMS_BOOST_PP_CAT(C,STREAMS_BOOST_PP_DEC(n))                                                \
                    :STREAMS_BOOST_MPL_MULTICHAR_PUSH_BACK(STREAMS_BOOST_PP_CAT(C,STREAMS_BOOST_PP_DEC(n)), Value::value)   \
                  , ((unsigned)STREAMS_BOOST_PP_CAT(C,STREAMS_BOOST_PP_DEC(n))>0xffffff)                            \
                    ?(char)Value::value                                                             \
                    :0                                                                              \
                >                                                                                   \
            type;                                                                                   \
        };

        STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_MPL_STRING_MAX_PARAMS, M0, ~)
        #undef M0

        template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C), typename Value>
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)>, Value, false>
        {
            typedef
                mpl::string<
                    STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PP_DEC(STREAMS_BOOST_MPL_STRING_MAX_PARAMS), C)
                  , STREAMS_BOOST_MPL_MULTICHAR_PUSH_BACK(STREAMS_BOOST_PP_CAT(C,STREAMS_BOOST_PP_DEC(STREAMS_BOOST_MPL_STRING_MAX_PARAMS)), Value::value)
                >
            type;
        };
    };

    template<typename Tag>
    struct pop_back_impl;

    template<>
    struct pop_back_impl<mpl::string_tag>
    {
        template<typename Sequence>
        struct apply;

        #define M0(z,n,data)                                                                        \
        template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, int C)>                                               \
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)> >                                 \
        {                                                                                           \
            STREAMS_BOOST_MPL_ASSERT_MSG((C0 != 0), POP_BACK_FAILED_MPL_STRING_IS_EMPTY, (mpl::string<>));  \
            typedef                                                                                 \
                mpl::string<                                                                        \
                    STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_DEC(n), C)                                   \
                    STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_PP_DEC(n))                                              \
                    STREAMS_BOOST_MPL_MULTICHAR_POP_BACK(STREAMS_BOOST_PP_CAT(C,STREAMS_BOOST_PP_DEC(n)))                   \
                >                                                                                   \
            type;                                                                                   \
        };

        STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_PP_INC(STREAMS_BOOST_MPL_STRING_MAX_PARAMS), M0, ~)
        #undef M0
    };

    template<typename Tag>
    struct push_front_impl;

    template<>
    struct push_front_impl<mpl::string_tag>
    {
        template<typename Sequence, typename Value, bool B = (4==STREAMS_BOOST_MPL_MULTICHAR_LENGTH(Sequence::front_))>
        struct apply
        {
            STREAMS_BOOST_MPL_ASSERT_MSG(
                (STREAMS_BOOST_MPL_LIMIT_STRING_SIZE != mpl::size<Sequence>::type::value)
              , PUSH_FRONT_FAILED_MPL_STRING_IS_FULL
              , (Sequence)
            );
            // If the above assertion didn't fire, then the string is sparse.
            // Repack the string and retry the push_front.
            typedef
                typename mpl::push_front<
                    typename mpl::reverse_copy<
                        Sequence
                      , mpl::front_inserter<string<> >
                    >::type
                  , Value
                >::type
            type;
        };

        #if !STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x590))
        template<typename Value>
        struct apply<mpl::string<>, Value, false>
        {
            typedef mpl::string<(char)Value::value> type;
        };
        #endif

        #define M0(z,n,data)                                                                        \
        template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, int C), typename Value>                               \
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)>, Value, true>                     \
        {                                                                                           \
            typedef                                                                                 \
                mpl::string<                                                                        \
                    (char)Value::value                                                              \
                    STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, C)                                        \
                >                                                                                   \
            type;                                                                                   \
        };

        STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_MPL_STRING_MAX_PARAMS, M0, ~)
        #undef M0

        template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C), typename Value>
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)>, Value, false>
        {
            typedef
                mpl::string<
                    STREAMS_BOOST_MPL_MULTICHAR_PUSH_FRONT(C0, Value::value)
                  , STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)
                >
            type0;

            #if STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x590))
            typedef
                typename mpl::if_<
                    mpl::empty<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)> >
                  , mpl::string<(char)Value::value>
                  , type0
                >::type
            type;
            #else
            typedef type0 type;
            #endif
        };
    };

    template<typename Tag>
    struct pop_front_impl;

    template<>
    struct pop_front_impl<mpl::string_tag>
    {
        template<typename Sequence, bool B = (1==STREAMS_BOOST_MPL_MULTICHAR_LENGTH(Sequence::front_))>
        struct apply;

        #define M0(z,n,data)                                                                        \
        template<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, int C)>                                               \
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, n, C)>, true>                            \
        {                                                                                           \
            STREAMS_BOOST_MPL_ASSERT_MSG((C0 != 0), POP_FRONT_FAILED_MPL_STRING_IS_EMPTY, (mpl::string<>)); \
            typedef                                                                                 \
                mpl::string<STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, n, C)>                                \
            type;                                                                                   \
        };

        STREAMS_BOOST_PP_REPEAT_FROM_TO(1, STREAMS_BOOST_MPL_STRING_MAX_PARAMS, M0, ~)
        #undef M0

        template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C)>
        struct apply<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)>, false>
        {
            typedef
                mpl::string<
                    STREAMS_BOOST_MPL_MULTICHAR_POP_FRONT(C0)
                  , STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)
                >
            type;
        };
    };

    template<typename Tag>
    struct insert_range_impl;

    template<>
    struct insert_range_impl<mpl::string_tag>
    {
        template<typename Sequence, typename Pos, typename Range>
        struct apply
          : mpl::copy<
                mpl::joint_view<
                    mpl::iterator_range<
                        mpl::string_iterator<Sequence, 0, 0>
                      , Pos
                    >
                  , mpl::joint_view<
                        Range
                      , mpl::iterator_range<
                            Pos
                          , typename mpl::end<Sequence>::type
                        >
                    >
                >
              , mpl::back_inserter<mpl::string<> >
            >
        {};
    };

    template<typename Tag>
    struct insert_impl;

    template<>
    struct insert_impl<mpl::string_tag>
    {
        template<typename Sequence, typename Pos, typename Value>
        struct apply
          : mpl::insert_range<Sequence, Pos, mpl::string<(char)Value::value> >
        {};
    };

    template<typename Tag>
    struct erase_impl;

    template<>
    struct erase_impl<mpl::string_tag>
    {
        template<typename Sequence, typename First, typename Last>
        struct apply
          : mpl::copy<
                mpl::joint_view<
                    mpl::iterator_range<
                        mpl::string_iterator<Sequence, 0, 0>
                      , First
                    >
                  , mpl::iterator_range<
                        typename mpl::if_na<Last, typename mpl::next<First>::type>::type
                      , typename mpl::end<Sequence>::type
                    >
                >
              , mpl::back_inserter<mpl::string<> >
            >
        {};
    };

    template<typename Tag>
    struct clear_impl;

    template<>
    struct clear_impl<mpl::string_tag>
    {
        template<typename>
        struct apply
        {
            typedef mpl::string<> type;
        };
    };

    #define M0(z, n, data)                                                                            \
    template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C), int J>                         \
    struct string_iterator<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)>, n, J>   \
    {                                                                                                 \
        enum { eomc_ = (STREAMS_BOOST_MPL_MULTICHAR_LENGTH(STREAMS_BOOST_PP_CAT(C, n)) == J + 1) };                   \
        typedef mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)> string;             \
        typedef std::bidirectional_iterator_tag category;                                             \
        typedef                                                                                       \
            mpl::string_iterator<string, n + eomc_, eomc_ ? 0 : J + 1>                                \
        next;                                                                                         \
        typedef                                                                                       \
            mpl::string_iterator<string, n, J - 1>                                                    \
        prior;                                                                                        \
        typedef mpl::char_<STREAMS_BOOST_MPL_MULTICHAR_AT(STREAMS_BOOST_PP_CAT(C, n), J)> type;                       \
    };                                                                                                \
    template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C)>                                \
    struct string_iterator<mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)>, n, 0>   \
    {                                                                                                 \
        enum { eomc_ = (STREAMS_BOOST_MPL_MULTICHAR_LENGTH(STREAMS_BOOST_PP_CAT(C, n)) == 1) };                       \
        typedef mpl::string<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, C)> string;             \
        typedef std::bidirectional_iterator_tag category;                                             \
        typedef                                                                                       \
            mpl::string_iterator<string, n + eomc_, !eomc_>                                           \
        next;                                                                                         \
        typedef                                                                                       \
            mpl::string_iterator<                                                                     \
                string                                                                                \
              , n - 1                                                                                 \
              , STREAMS_BOOST_MPL_MULTICHAR_LENGTH(STREAMS_BOOST_PP_CAT(C, STREAMS_BOOST_PP_DEC(n))) - 1                      \
            >                                                                                         \
        prior;                                                                                        \
        typedef mpl::char_<STREAMS_BOOST_MPL_MULTICHAR_AT(STREAMS_BOOST_PP_CAT(C, n), 0)> type;                       \
    };

    STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, M0, ~)
    #undef M0

    template<STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_MPL_STRING_MAX_PARAMS, int C)>
    struct string
    {
        /// INTERNAL ONLY
        enum
        {
            front_  = C0
          , back_   = STREAMS_BOOST_PP_CAT(C, STREAMS_BOOST_PP_DEC(STREAMS_BOOST_MPL_STRING_MAX_PARAMS))
        };

        typedef char        value_type;
        typedef string      type;
        typedef string_tag  tag;
    };

    namespace aux_
    {
        template<typename It, typename End>
        struct next_unless
          : mpl::next<It>
        {};

        template<typename End>
        struct next_unless<End, End>
        {
            typedef End type;
        };

        template<typename It, typename End>
        struct deref_unless
          : mpl::deref<It>
        {};

        template<typename End>
        struct deref_unless<End, End>
        {
            typedef mpl::char_<'\0'> type;
        };
    }

    template<typename Sequence>
    struct c_str
    {
        typedef typename mpl::end<Sequence>::type iend;
        typedef typename mpl::begin<Sequence>::type i0;
        #define M0(z, n, data)                                                                      \
        typedef                                                                                     \
            typename mpl::aux_::next_unless<STREAMS_BOOST_PP_CAT(i, n), iend>::type                         \
        STREAMS_BOOST_PP_CAT(i, STREAMS_BOOST_PP_INC(n));
        STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_MPL_LIMIT_STRING_SIZE, M0, ~)
        #undef M0

        typedef c_str type;
        static typename Sequence::value_type const value[STREAMS_BOOST_MPL_LIMIT_STRING_SIZE+1];
    };

    template<typename Sequence>
    typename Sequence::value_type const c_str<Sequence>::value[STREAMS_BOOST_MPL_LIMIT_STRING_SIZE+1] =
    {
        #define M0(z, n, data)                                                                      \
        mpl::aux_::deref_unless<STREAMS_BOOST_PP_CAT(i, n), iend>::type::value,
        STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_MPL_LIMIT_STRING_SIZE, M0, ~)
        #undef M0
        '\0'
    };

}} // namespace streams_boost

#endif // STREAMS_BOOST_MPL_STRING_HPP_INCLUDED
