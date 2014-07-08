/*=============================================================================
    Copyright (c) 2003 Hartmut Kaiser
    Copyright (c) 2003 Joel de Guzman
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_GRAMMAR_DEF_HPP)
#define STREAMS_BOOST_SPIRIT_GRAMMAR_DEF_HPP

#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/preprocessor/arithmetic/inc.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/enum.hpp>
#include <streams_boost/preprocessor/enum_params.hpp>
#include <streams_boost/preprocessor/repeat.hpp>
#include <streams_boost/preprocessor/repeat_from_to.hpp>
#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/phoenix/tuples.hpp>
#include <streams_boost/spirit/home/classic/core/assert.hpp>
#include <streams_boost/spirit/home/classic/utility/grammar_def_fwd.hpp>

///////////////////////////////////////////////////////////////////////////////
//
//  Spirit predefined maximum grammar start parser limit. This limit defines
//  the maximum number of of possible different parsers exposed from a
//  particular grammar. This number defaults to 3.
//  The actual maximum is rounded up in multiples of 3. Thus, if this value
//  is 4, the actual limit is 6. The ultimate maximum limit in this
//  implementation is 15.
//
//  It should NOT be greater than PHOENIX_LIMIT!
//
///////////////////////////////////////////////////////////////////////////////
#if !defined(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT)
#define STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT PHOENIX_LIMIT
#endif

///////////////////////////////////////////////////////////////////////////////
//
// ensure STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT <= PHOENIX_LIMIT and
//        STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT <= 15 and
//        STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 0
//
///////////////////////////////////////////////////////////////////////////////
STREAMS_BOOST_STATIC_ASSERT(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT <= PHOENIX_LIMIT);
STREAMS_BOOST_STATIC_ASSERT(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT <= 15);
STREAMS_BOOST_STATIC_ASSERT(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 0);

//////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

struct same {};

///////////////////////////////////////////////////////////////////////////////
namespace impl {

    ///////////////////////////////////////////////////////////////////////////
    //
    //  The make_const_pointer meta function allows to generate a T const*
    //  needed to store the pointer to a given start parser from a grammar.
    //
    ///////////////////////////////////////////////////////////////////////////
    template <typename T0, typename T = T0>
    struct make_const_pointer {

    private:
        // T0 shouldn't be of type 'same'
        STREAMS_BOOST_STATIC_ASSERT((!streams_boost::is_same<T0, same>::value));

        typedef typename streams_boost::mpl::if_c<
                    streams_boost::is_same<T, same>::value,
                    T0 const *,
                    T const *
                >::type
            ptr_type;

    public:
        // If the type in question is phoenix::nil_t, then the returned type
        // is still phoenix::nil_t, otherwise a constant pointer type to the
        // inspected type is returned.
        typedef typename streams_boost::mpl::if_c<
                    streams_boost::is_same<T, phoenix::nil_t>::value,
                    phoenix::nil_t,
                    ptr_type
                >::type
            type;
    };

    ///////////////////////////////////////////////////////////////////////////
    template <int N, typename ElementT>
    struct assign_zero_to_tuple_member {

        template <typename TupleT>
        static void do_(TupleT &t) { t[phoenix::tuple_index<N>()] = 0; }
    };

    template <int N>
    struct assign_zero_to_tuple_member<N, phoenix::nil_t> {

        template <typename TupleT>
        static void do_(TupleT& /*t*/) {}
    };

    struct phoenix_nil_type {

        typedef phoenix::nil_t type;
    };

    template <int N>
    struct init_tuple_member {

        template <typename TupleT>
        static void
        do_(TupleT &t)
        {
            typedef typename streams_boost::mpl::eval_if_c<
                        (N < TupleT::length),
                        phoenix::tuple_element<N, TupleT>,
                        phoenix_nil_type
                    >::type
                element_type;

            assign_zero_to_tuple_member<N, element_type>::do_(t);
        }
    };

///////////////////////////////////////////////////////////////////////////////
}   // namespace impl

///////////////////////////////////////////////////////////////////////////////
//
//  grammar_def class
//
//      This class may be used as a base class for the embedded definition
//      class inside the grammar<> derived user grammar.
//      It exposes the two functions needed for start rule access:
//
//          rule<> const &start() const;
//
//      and
//
//          template <int N>
//          rule<> const *get_start_parser() const;
//
//      Additionally it exposes a set o 'start_parsers' functions, which are to
//      be called by the user to define the parsers to use as start parsers
//      of the given grammar.
//
///////////////////////////////////////////////////////////////////////////////
template <
    typename T,
    STREAMS_BOOST_PP_ENUM_PARAMS(
        STREAMS_BOOST_PP_DEC(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A), typename T)
>
class grammar_def {

private:
    ///////////////////////////////////////////////////////////////////////////
    //
    //  This generates the full tuple type from the given template parameters
    //  T, T0, ...
    //
    //      typedef phoenix::tuple<
    //              typename impl::make_const_pointer<T>::type,
    //              typename impl::make_const_pointer<T, T0>::type,
    //              ...
    //          > tuple_t;
    //
    ///////////////////////////////////////////////////////////////////////////
    #define STREAMS_BOOST_SPIRIT_GRAMMARDEF_TUPLE_PARAM(z, N, _) \
        typename impl::make_const_pointer<T, STREAMS_BOOST_PP_CAT(T, N)>::type \
        /**/

    typedef phoenix::tuple<
            typename impl::make_const_pointer<T>::type,
            STREAMS_BOOST_PP_ENUM(
                STREAMS_BOOST_PP_DEC(STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A),
                STREAMS_BOOST_SPIRIT_GRAMMARDEF_TUPLE_PARAM,
                _
            )
        > tuple_t;

    #undef STREAMS_BOOST_SPIRIT_GRAMMARDEF_TUPLE_PARAM
    ///////////////////////////////////////////////////////////////////////////

protected:
    ///////////////////////////////////////////////////////////////////////////
    //
    //  This generates a sequence of 'start_parsers' functions with increasing
    //  number of arguments, which allow to initialize the tuple members with
    //  the pointers to the start parsers of the grammar:
    //
    //      template <typename TC0, ...>
    //      void start_parsers (TC0 const &t0, ...)
    //      {
    //          using phoenix::tuple_index_names::_1;
    //          t[_1] = &t0;
    //          ...
    //      }
    //
    //      where a TC0 const* must be convertible to a T0 const*
    //
    ///////////////////////////////////////////////////////////////////////////
    #define STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_PARAMS(z, N, _) \
        STREAMS_BOOST_PP_CAT(TC, N) const &STREAMS_BOOST_PP_CAT(t, N) \
        /**/
    #define STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_ASSIGN(z, N, _) \
        using phoenix::tuple_index_names::STREAMS_BOOST_PP_CAT(_, STREAMS_BOOST_PP_INC(N)); \
        t[STREAMS_BOOST_PP_CAT(_, STREAMS_BOOST_PP_INC(N))] = &STREAMS_BOOST_PP_CAT(t, N); \
        /**/
    #define STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_START(z, N, _) \
        template <STREAMS_BOOST_PP_ENUM_PARAMS_Z(z, STREAMS_BOOST_PP_INC(N), typename TC)> \
        void \
        start_parsers(STREAMS_BOOST_PP_ENUM_ ## z(STREAMS_BOOST_PP_INC(N), \
            STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_PARAMS, _) ) \
        { \
            STREAMS_BOOST_PP_REPEAT_ ## z(STREAMS_BOOST_PP_INC(N), \
                STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_ASSIGN, _) \
        } \
        /**/

    STREAMS_BOOST_PP_REPEAT(
        STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A,
        STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_START, _)

    #undef STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_START
    #undef STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_ASSIGN
    #undef STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_PARAMS
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    //
    //  This generates some initialization code, which allows to initialize all
    //  used tuple members to 0 (zero):
    //
    //      t[_1] = 0;
    //      impl::init_tuple_member<1>::do_(t);
    //      ...
    //
    ///////////////////////////////////////////////////////////////////////////
    #define STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_INIT(z, N, _) \
        impl::init_tuple_member<N>::do_(t); \
        /**/

    grammar_def()
    {
        using phoenix::tuple_index_names::_1;
        t[_1] = 0;
        STREAMS_BOOST_PP_REPEAT_FROM_TO(
            1, STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A,
            STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_INIT, _)
    }

    #undef STREAMS_BOOST_SPIRIT_GRAMMARDEF_ENUM_INIT
    ///////////////////////////////////////////////////////////////////////////

public:
    T const &
    start() const
    {
    //  If the following assertion is fired, you have probably forgot to call
    //  the start_parser() function from inside the constructor of your
    //  embedded definition class to initialize the start parsers to be exposed
    //  from your grammar.
        using phoenix::tuple_index_names::_1;
        STREAMS_BOOST_SPIRIT_ASSERT(0 != t[_1]);
        return *t[_1];
    }

    template <int N>
    typename phoenix::tuple_element<N, tuple_t>::crtype
    get_start_parser() const
    {
    //  If the following expression yields a compiler error, you have probably
    //  tried to access a start rule, which isn't exposed as such from your
    //  grammar.
        STREAMS_BOOST_STATIC_ASSERT(N > 0 && N < tuple_t::length);

    //  If the following assertion is fired, you have probably forgot to call
    //  the start_parser() function from inside the constructor of your
    //  embedded definition class to initialize the start parsers to be exposed
    //  from your grammar.
    //  Another reason may be, that there is a count mismatch between
    //  the number of template parameters to the grammar_def<> class and the
    //  number of parameters used while calling start_parsers().
        STREAMS_BOOST_SPIRIT_ASSERT(0 != t[phoenix::tuple_index<N>()]);

        return t[phoenix::tuple_index<N>()];
    }

private:
    tuple_t t;
};

#undef STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT_A

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif // STREAMS_BOOST_SPIRIT_GRAMMAR_DEF_HPP
