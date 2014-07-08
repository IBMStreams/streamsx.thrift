/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2007 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_20070508_2207)
#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_20070508_2207

#include <streams_boost/fusion/support/tag_of_fwd.hpp>
#include <streams_boost/fusion/adapted/struct/extension.hpp>
#include <streams_boost/fusion/adapted/struct/struct_iterator.hpp>
#include <streams_boost/fusion/adapted/struct/detail/is_view_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/is_sequence_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/category_of_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/begin_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/end_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/size_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/at_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/value_at_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/has_key_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/at_key_impl.hpp>
#include <streams_boost/fusion/adapted/struct/detail/value_at_key_impl.hpp>

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/punctuation/comma_if.hpp>
#include <streams_boost/preprocessor/seq/for_each_i.hpp>
#include <streams_boost/preprocessor/tuple/elem.hpp>
#include <streams_boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/config/no_tr1/utility.hpp>

namespace streams_boost { namespace fusion { namespace extension {
    template<typename Struct, typename Key>
    struct struct_assoc_member;
}}}


#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT(name, bseq)                                   \
    STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_I(                                                \
        name, STREAMS_BOOST_PP_CAT(STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_X bseq, 0))                \
    /***/

#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_X(x, y, z) ((x, y, z)) STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_Y
#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_Y(x, y, z) ((x, y, z)) STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_X
#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_X0
#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_Y0

// STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_I generates the overarching structure and uses
// SEQ_FOR_EACH_I to generate the "linear" substructures.
// Thanks to Paul Mensonides for the PP macro help

#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_I(name, seq)                            \
    namespace streams_boost { namespace fusion { namespace traits                       \
    {                                                                           \
        template <>                                                             \
        struct tag_of<name>                                                     \
        {                                                                       \
            typedef struct_tag type;                                            \
        };                                                                      \
    }}}                                                                         \
                                                                                \
    namespace streams_boost { namespace mpl                                             \
    {                                                                           \
        template<typename>                                                      \
        struct sequence_tag;                                                    \
                                                                                \
        template<>                                                              \
        struct sequence_tag<name>                                               \
        {                                                                       \
            typedef fusion::fusion_sequence_tag type;                           \
        };                                                                      \
                                                                                \
        template<>                                                              \
        struct sequence_tag<name const>                                         \
        {                                                                       \
            typedef fusion::fusion_sequence_tag type;                           \
        };                                                                      \
    }}                                                                          \
                                                                                \
    namespace streams_boost { namespace fusion { namespace extension                    \
    {                                                                           \
        template <>                                                             \
        struct struct_size<name> : mpl::int_<STREAMS_BOOST_PP_SEQ_SIZE(seq)> {};        \
        STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_C, name, seq)   \
    }}}                                                                         \
    /***/

#define STREAMS_BOOST_FUSION_ADAPT_ASSOC_STRUCT_C(r, name, i, xy)                       \
    template <>                                                                 \
    struct struct_member<name, i>                                               \
    {                                                                           \
        typedef STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, xy) type;                             \
        static type& call(name& struct_)                                        \
        {                                                                       \
            return struct_.STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, xy);                       \
        };                                                                      \
    };                                                                          \
    template<>                                                                  \
    struct struct_assoc_member<name, STREAMS_BOOST_PP_TUPLE_ELEM(3, 2, xy)>             \
    {                                                                           \
        typedef STREAMS_BOOST_PP_TUPLE_ELEM(3, 0, xy) type;                             \
        static type& call(name& struct_)                                        \
        {                                                                       \
            return struct_.STREAMS_BOOST_PP_TUPLE_ELEM(3, 1, xy);                       \
        };                                                                      \
    };
    /***/

#endif
