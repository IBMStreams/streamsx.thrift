/*=============================================================================
    Copyright (c) 2005-2006 Joao Abecasis
    Copyright (c) 2006-2007 Tobias Schwinger

    Use modification and distribution are subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_FUNCTIONAL_INVOCATION_INVOKE_PROCEDURE_HPP_INCLUDED)
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

#include <streams_boost/preprocessor/cat.hpp>
#include <streams_boost/preprocessor/iteration/iterate.hpp>
#include <streams_boost/preprocessor/arithmetic/dec.hpp>
#include <streams_boost/preprocessor/repetition/repeat_from_to.hpp>
#include <streams_boost/preprocessor/repetition/enum.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted.hpp>
#include <streams_boost/preprocessor/repetition/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_shifted_params.hpp>

#include <streams_boost/type_traits/remove_reference.hpp>

#include <streams_boost/mpl/front.hpp>

#include <streams_boost/function_types/is_callable_builtin.hpp>
#include <streams_boost/function_types/is_member_function_pointer.hpp>
#include <streams_boost/function_types/parameter_types.hpp>

#include <streams_boost/fusion/support/category_of.hpp>
#include <streams_boost/fusion/sequence/intrinsic/at.hpp>
#include <streams_boost/fusion/sequence/intrinsic/size.hpp>
#include <streams_boost/fusion/sequence/intrinsic/begin.hpp>
#include <streams_boost/fusion/iterator/next.hpp>
#include <streams_boost/fusion/iterator/deref.hpp>
#include <streams_boost/fusion/functional/invocation/limits.hpp>
#include <streams_boost/fusion/functional/invocation/detail/that_ptr.hpp>

namespace streams_boost { namespace fusion
{
    namespace result_of
    {
        template <typename Function, class Sequence> struct invoke_procedure
        {
            typedef void type;
        };
    }

    template <typename Function, class Sequence>
    inline void invoke_procedure(Function, Sequence &);

    template <typename Function, class Sequence>
    inline void invoke_procedure(Function, Sequence const &);

    //----- ---- --- -- - -  -   -

    namespace detail
    {
        namespace ft = function_types;

        template<
            typename Function, class Sequence,
            int N = result_of::size<Sequence>::value,
            bool MFP = ft::is_member_function_pointer<Function>::value,
            bool RandomAccess = traits::is_random_access<Sequence>::value
            >
        struct invoke_procedure_impl;

        #define  STREAMS_BOOST_PP_FILENAME_1 \
            <streams_boost/fusion/functional/invocation/invoke_procedure.hpp>
        #define  STREAMS_BOOST_PP_ITERATION_LIMITS \
            (0, STREAMS_BOOST_FUSION_INVOKE_PROCEDURE_MAX_ARITY)
        #include STREAMS_BOOST_PP_ITERATE()

    }

    template <typename Function, class Sequence>
    inline void invoke_procedure(Function f, Sequence & s)
    {
        detail::invoke_procedure_impl<
                typename streams_boost::remove_reference<Function>::type,Sequence
            >::call(f,s);
    }

    template <typename Function, class Sequence>
    inline void invoke_procedure(Function f, Sequence const & s)
    {
        detail::invoke_procedure_impl<
                typename streams_boost::remove_reference<Function>::type,Sequence const
            >::call(f,s);
    }

}}

#define STREAMS_BOOST_FUSION_FUNCTIONAL_INVOCATION_INVOKE_PROCEDURE_HPP_INCLUDED
#else // defined(STREAMS_BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#define N STREAMS_BOOST_PP_ITERATION()

#define M(z,j,data) fusion::at_c<j>(s)

        template <typename Function, class Sequence>
        struct invoke_procedure_impl<Function,Sequence,N,false,true>
        {
            static inline void call(Function & f, Sequence & s)
            {
                f(STREAMS_BOOST_PP_ENUM(N,M,~));
            }
        };

#if N > 0
        template <typename Function, class Sequence>
        struct invoke_procedure_impl<Function,Sequence,N,true,true>
        {
            static inline void call(Function & f, Sequence & s)
            {
                (that_ptr<typename mpl::front<
                                ft::parameter_types<Function> >::type
                    >::get(fusion::at_c<0>(s))->*f)(STREAMS_BOOST_PP_ENUM_SHIFTED(N,M,~));
            }
        };
#endif

#undef M

#define M(z,j,data)                                                             \
            typedef typename result_of::next< STREAMS_BOOST_PP_CAT(I,STREAMS_BOOST_PP_DEC(j))  \
                >::type I ## j ;                                               \
            I##j i##j = fusion::next(STREAMS_BOOST_PP_CAT(i,STREAMS_BOOST_PP_DEC(j)));

        template <typename Function, class Sequence>
        struct invoke_procedure_impl<Function,Sequence,N,false,false>
        {
            static inline void call(Function & f, Sequence & s)
            {
#if N > 0
                typedef typename result_of::begin<Sequence>::type I0;
                I0 i0 = fusion::begin(s);
                STREAMS_BOOST_PP_REPEAT_FROM_TO(1,N,M,~)
#endif
                f( STREAMS_BOOST_PP_ENUM_PARAMS(N,*i) );
            }
        };

#if N > 0
        template <typename Function, class Sequence>
        struct invoke_procedure_impl<Function,Sequence,N,true,false>
        {
            static inline void call(Function & f, Sequence & s)
            {
                typedef typename result_of::begin<Sequence>::type I0;
                I0 i0 = fusion::begin(s);
                STREAMS_BOOST_PP_REPEAT_FROM_TO(1,N,M,~)

                (that_ptr<typename mpl::front<
                                ft::parameter_types<Function> >::type
                    >::get(*i0)->*f)(STREAMS_BOOST_PP_ENUM_SHIFTED_PARAMS(N,*i));
            }
        };
#endif

#undef M

#undef N
#endif // defined(STREAMS_BOOST_PP_IS_ITERATING)
#endif

