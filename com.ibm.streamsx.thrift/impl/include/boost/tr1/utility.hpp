//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_UTILITY_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_UTILITY_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_UTILITY

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(utility)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(utility))
#  endif

#else

#if defined(STREAMS_BOOST_TR1_USE_OLD_TUPLE)

#include <streams_boost/type_traits/integral_constant.hpp>
#include <streams_boost/type_traits/add_const.hpp>
#include <streams_boost/type_traits/add_reference.hpp>
#include <streams_boost/mpl/if.hpp>


namespace std{ namespace tr1{

template <class T> struct tuple_size; // forward declaration
template < int I, class T> struct tuple_element; // forward declaration

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template <class T1, class T2> 
struct tuple_size< ::std::pair<T1, T2> >
   : public ::streams_boost::integral_constant< ::std::size_t, 2>
{
};

template <class T1, class T2> 
struct tuple_element<0, ::std::pair<T1, T2> >
{
   typedef typename std::pair<T1, T2>::first_type type;
};

template <class T1, class T2> 
struct tuple_element<1, std::pair<T1, T2> >
{
   typedef typename std::pair<T1, T2>::second_type type;
};
#endif

namespace tuple_detail{
   template <int I, class T1, class T2>
   struct tuple_get_result
   {
      typedef typename streams_boost::mpl::if_c<I==0, T1, T2>::type t1;
      typedef typename streams_boost::add_reference<t1>::type type;
   };
   template <int I, class T1, class T2>
   struct const_tuple_get_result
   {
      typedef typename streams_boost::mpl::if_c<I==0, T1, T2>::type t1;
# if STREAMS_BOOST_WORKAROUND( __BORLANDC__, STREAMS_BOOST_TESTED_AT( 0x582))
      // I have absolutely no idea why add_const is not working here for Borland!
      // It passes all other free-standing tests, some strange interaction going on
      typedef typename streams_boost::add_reference< const t1 >::type type;
# else
      typedef typename streams_boost::add_const<t1>::type t2;
      typedef typename streams_boost::add_reference<t2>::type type;
# endif
   };

template<int I, class T1, class T2> 
inline typename tuple_detail::tuple_get_result<I,T1,T2>::type get(std::pair<T1, T2>& p, const ::streams_boost::true_type&)
{
   return p.first;
}

template<int I, class T1, class T2> 
inline typename tuple_detail::const_tuple_get_result<I,T1,T2>::type get(const std::pair<T1, T2>& p, const ::streams_boost::true_type&)
{
   return p.first;
}

template<int I, class T1, class T2> 
inline typename tuple_detail::tuple_get_result<I,T1,T2>::type get(std::pair<T1, T2>& p, const ::streams_boost::false_type&)
{
   return p.second;
}

template<int I, class T1, class T2> 
inline typename tuple_detail::const_tuple_get_result<I,T1,T2>::type get(const std::pair<T1, T2>& p, const ::streams_boost::false_type&)
{
   return p.second;
}

}

template<int I, class T1, class T2> 
inline typename tuple_detail::tuple_get_result<I,T1,T2>::type get(std::pair<T1, T2>& p)
{
   return tuple_detail::get<I>(p, streams_boost::integral_constant<bool, I==0>());
}

template<int I, class T1, class T2> 
inline typename tuple_detail::const_tuple_get_result<I,T1,T2>::type get(const std::pair<T1, T2>& p)
{
   return tuple_detail::get<I>(p, streams_boost::integral_constant<bool, I==0>());
}

} } // namespaces

#else

#include <streams_boost/tr1/tuple.hpp>

#endif

#endif

#endif
