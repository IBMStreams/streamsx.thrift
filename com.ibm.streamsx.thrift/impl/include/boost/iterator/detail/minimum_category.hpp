// Copyright David Abrahams 2003. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef MINIMUM_CATEGORY_DWA20031119_STREAMS_HPP
# define MINIMUM_CATEGORY_DWA20031119_STREAMS_HPP

# include <streams_boost/type_traits/is_convertible.hpp>
# include <streams_boost/type_traits/is_same.hpp>

# include <streams_boost/mpl/aux_/lambda_support.hpp>

namespace streams_boost { namespace detail { 
//
// Returns the minimum category type or error_type
// if T1 and T2 are unrelated.
//
// For compilers not supporting is_convertible this only
// works with the new streams_boost return and traversal category
// types. The exact streams_boost _types_ are required. No derived types
// will work. 
//
//
template <bool GreaterEqual, bool LessEqual>
struct minimum_category_impl
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
{
    template <class T1, class T2> struct apply
    {
        typedef T2 type;
    };
    typedef void type;
}
# endif 
;

template <class T1, class T2>
struct error_not_related_by_convertibility;
  
template <>
struct minimum_category_impl<true,false>
{
    template <class T1, class T2> struct apply
    {
        typedef T2 type;
    };
};

template <>
struct minimum_category_impl<false,true>
{
    template <class T1, class T2> struct apply
    {
        typedef T1 type;
    };
};

template <>
struct minimum_category_impl<true,true>
{
    template <class T1, class T2> struct apply
    {
        STREAMS_BOOST_STATIC_ASSERT((is_same<T1,T2>::value));
        typedef T1 type;
    };
};

template <>
struct minimum_category_impl<false,false>
{
    template <class T1, class T2> struct apply
    : error_not_related_by_convertibility<T1,T2>
    {
    };
};

template <class T1 = mpl::_1, class T2 = mpl::_2>
struct minimum_category
{
    typedef minimum_category_impl< 
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) // ETI workaround
        is_same<T2,int>::value ||
# endif 
        ::streams_boost::is_convertible<T1,T2>::value
      , ::streams_boost::is_convertible<T2,T1>::value
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) // ETI workaround
        || is_same<T1,int>::value
# endif 
    > outer;

    typedef typename outer::template apply<T1,T2> inner;
    typedef typename inner::type type;
      
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2,minimum_category,(T1,T2))
};
    
template <>
struct minimum_category<mpl::_1,mpl::_2>
{
    template <class T1, class T2>
    struct apply : minimum_category<T1,T2>
    {};

    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2,minimum_category,(mpl::_1,mpl::_2))
};

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300) // ETI workaround
template <>
struct minimum_category<int,int>
{
    typedef int type;
};
# endif
    
}} // namespace streams_boost::detail

#endif // MINIMUM_CATEGORY_DWA20031119_STREAMS_HPP
