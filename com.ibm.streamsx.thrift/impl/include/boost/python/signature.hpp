///////////////////////////////////////////////////////////////////////////////
//
// Copyright David Abrahams 2002, Joel de Guzman, 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////
#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

# ifndef SIGNATURE_JDG20020813_HPP
#  define SIGNATURE_JDG20020813_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/mpl/if.hpp>
# include <streams_boost/type_traits/is_convertible.hpp>

#  include <streams_boost/python/detail/preprocessor.hpp>
#  include <streams_boost/preprocessor/repeat.hpp>
#  include <streams_boost/preprocessor/enum.hpp>
#  include <streams_boost/preprocessor/enum_params.hpp>
#  include <streams_boost/preprocessor/empty.hpp>
#  include <streams_boost/preprocessor/arithmetic/sub.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/python/detail/type_list.hpp>

#  include <streams_boost/preprocessor/debug/line.hpp>
#  include <streams_boost/preprocessor/arithmetic/sub.hpp>
#  include <streams_boost/preprocessor/arithmetic/inc.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>

# define STREAMS_BOOST_PYTHON_LIST_INC(n)        \
   STREAMS_BOOST_PP_CAT(mpl::vector, STREAMS_BOOST_PP_INC(n))

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace python { namespace detail {

// A metafunction returning C1 if C1 is derived from C2, and C2
// otherwise
template <class C1, class C2>
struct most_derived
{
    typedef typename mpl::if_<
        is_convertible<C1*,C2*>
      , C1
      , C2
    >::type type;
};

//  The following macros generate expansions for::
//
//      template <class RT, class T0... class TN>
//      inline mpl::vector<RT, T0...TN>
//      get_signature(RT(*)(T0...TN), void* = 0)
//      {
//          return mpl::list<RT, T0...TN>();
//      }
//
//   And, for an appropriate assortment of cv-qualifications::
//
//      template <class RT, class ClassT, class T0... class TN>
//      inline mpl::vector<RT, ClassT&, T0...TN>
//      get_signature(RT(ClassT::*)(T0...TN) cv))
//      {
//          return mpl::list<RT, ClassT&, T0...TN>();
//      }
//
//      template <class Target, class RT, class ClassT, class T0... class TN>
//      inline mpl::vector<
//          RT
//        , typename most_derived<Target, ClassT>::type&
//        , T0...TN
//      >
//      get_signature(RT(ClassT::*)(T0...TN) cv), Target*)
//      {
//          return mpl::list<RT, ClassT&, T0...TN>();
//      }
//
//  There are two forms for invoking get_signature::
//
//      get_signature(f)
//
//  and ::
//
//      get_signature(f,(Target*)0)
//
//  These functions extract the return type, class (for member
//  functions) and arguments of the input signature and stuff them in
//  an mpl type sequence.  Note that cv-qualification is dropped from
//  the "hidden this" argument of member functions; that is a
//  necessary sacrifice to ensure that an lvalue from_python converter
//  is used.  A pointer is not used so that None will be rejected for
//  overload resolution.
//
//  The second form of get_signature essentially downcasts the "hidden
//  this" argument of member functions to Target, because the function
//  may actually be a member of a base class which is not wrapped, and
//  in that case conversion from python would fail.
//
// @group {

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                   \
    (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/signature.hpp>))

#  include STREAMS_BOOST_PP_ITERATE()
#  undef STREAMS_BOOST_PYTHON_LIST_INC

// }

}}} // namespace streams_boost::python::detail


# endif // SIGNATURE_JDG20020813_HPP

// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 // defined(STREAMS_BOOST_PP_IS_ITERATING)

# define N STREAMS_BOOST_PP_ITERATION()

template <
    class RT STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class T)>
inline STREAMS_BOOST_PYTHON_LIST_INC(N)<
    RT STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, T)>
get_signature(RT(*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, T)), void* = 0)
{
    return STREAMS_BOOST_PYTHON_LIST_INC(N)<
            RT STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, T)
        >();
}

# undef N

# define STREAMS_BOOST_PP_ITERATION_PARAMS_2 \
    (3, (0, 3, <streams_boost/python/signature.hpp>))
# include STREAMS_BOOST_PP_ITERATE()

#else

# define N STREAMS_BOOST_PP_RELATIVE_ITERATION(1)
# define Q STREAMS_BOOST_PYTHON_CV_QUALIFIER(STREAMS_BOOST_PP_ITERATION())

template <
    class RT, class ClassT STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class T)>
inline STREAMS_BOOST_PYTHON_LIST_INC(STREAMS_BOOST_PP_INC(N))<
    RT, ClassT& STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, T)>
get_signature(RT(ClassT::*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, T)) Q)
{
    return STREAMS_BOOST_PYTHON_LIST_INC(STREAMS_BOOST_PP_INC(N))<
            RT, ClassT& STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, T)
        >();
}

template <
    class Target
  , class RT
  , class ClassT
    STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, class T)
>
inline STREAMS_BOOST_PYTHON_LIST_INC(STREAMS_BOOST_PP_INC(N))<
    RT
  , typename most_derived<Target, ClassT>::type&
    STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, T)
>
get_signature(
    RT(ClassT::*)(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, T)) Q
  , Target*
)
{
    return STREAMS_BOOST_PYTHON_LIST_INC(STREAMS_BOOST_PP_INC(N))<
        RT
      , STREAMS_BOOST_DEDUCED_TYPENAME most_derived<Target, ClassT>::type&
        STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS_Z(1, N, T)
    >();
}

# undef Q
# undef N

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif // !defined(STREAMS_BOOST_PP_IS_ITERATING)
