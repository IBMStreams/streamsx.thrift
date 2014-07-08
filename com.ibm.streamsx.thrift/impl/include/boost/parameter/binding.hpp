// Copyright David Abrahams 2005. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_PARAMETER_BINDING_DWA200558_STREAMS_HPP
# define STREAMS_BOOST_PARAMETER_BINDING_DWA200558_STREAMS_HPP

# include <streams_boost/mpl/apply.hpp>
# include <streams_boost/mpl/assert.hpp>
# include <streams_boost/mpl/and.hpp>
# include <streams_boost/parameter/aux_/result_of0.hpp>
# include <streams_boost/parameter/aux_/void.hpp>
# include <streams_boost/type_traits/is_same.hpp>

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#  include <streams_boost/mpl/eval_if.hpp>
# endif

namespace streams_boost { namespace parameter { 

// A metafunction that, given an argument pack, returns the type of
// the parameter identified by the given keyword.  If no such
// parameter has been specified, returns Default

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
  || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
template <class Parameters, class Keyword, class Default>
struct binding0
{
    typedef typename mpl::apply_wrap3<
        typename Parameters::binding,Keyword,Default,mpl::true_
    >::type type;

    STREAMS_BOOST_MPL_ASSERT_NOT((
        mpl::and_<
            is_same<Default, void_>
          , is_same<type, void_>
        >
    ));
};
# endif

template <class Parameters, class Keyword, class Default = void_>
# if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
struct binding
# else
struct binding_eti
# endif
{
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) \
  || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
    typedef typename mpl::eval_if<
        mpl::is_placeholder<Parameters>
      , mpl::identity<int>
      , binding0<Parameters,Keyword,Default>
    >::type type;
# else
    typedef typename mpl::apply_wrap3<
        typename Parameters::binding,Keyword,Default,mpl::true_
    >::type type;

    STREAMS_BOOST_MPL_ASSERT_NOT((
        mpl::and_<
            is_same<Default, void_>
          , is_same<type, void_>
        >
    ));
# endif

# if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,binding,(Parameters,Keyword,Default))
# endif
};

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
template <class Parameters, class Keyword, class Default = void_>
struct binding
{
    typedef typename mpl::eval_if<
        is_same<Parameters, int>
      , mpl::identity<int>
      , binding_eti<Parameters, Keyword, Default>
    >::type type;

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(3,binding,(Parameters,Keyword,Default))
};
# endif

// A metafunction that, given an argument pack, returns the type of
// the parameter identified by the given keyword.  If no such
// parameter has been specified, returns the type returned by invoking
// DefaultFn
template <class Parameters, class Keyword, class DefaultFn>
struct lazy_binding
{
  typedef typename mpl::apply_wrap3<
      typename Parameters::binding
    , Keyword
    , typename aux::result_of0<DefaultFn>::type
    , mpl::true_
  >::type type;
};


}} // namespace streams_boost::parameter

#endif // STREAMS_BOOST_PARAMETER_BINDING_DWA200558_STREAMS_HPP
