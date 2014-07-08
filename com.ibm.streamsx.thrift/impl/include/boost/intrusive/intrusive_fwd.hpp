/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga  2007-2009
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_FWD_HPP
#define STREAMS_BOOST_INTRUSIVE_FWD_HPP

#include <cstddef>
#include <streams_boost/intrusive/link_mode.hpp>
#include <streams_boost/intrusive/detail/workaround.hpp>

/// @cond

namespace streams_boost {

namespace intrusive {

struct none;

}  //namespace intrusive{
}  //namespace streams_boost{

namespace streams_boost {
namespace intrusive {

////////////////////////////
//     Node algorithms
////////////////////////////

//Algorithms predeclarations
template<class NodeTraits>
class circular_list_algorithms;

template<class NodeTraits>
class circular_slist_algorithms;

template<class NodeTraits>
class rbtree_algorithms;

////////////////////////////
//       Containers
////////////////////////////

//slist
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   , class O5  = none
   >
#else
template<class T, class ...Options>
#endif
class slist;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class slist_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class slist_member_hook;

//list
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class T, class ...Options>
#endif
class list;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class list_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class list_member_hook;

//rbtree/set/multiset
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class rbtree;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class set;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class multiset;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class ...Options>
#endif
class set_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class ...Options>
#endif
class set_member_hook;

//splaytree/splay_set/splay_multiset
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class splaytree;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class splay_set;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class splay_multiset;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class splay_set_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class splay_set_member_hook;

//avltree/avl_set/avl_multiset
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class avltree;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class avl_set;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class avl_multiset;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class ...Options>
#endif
class avl_set_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class ...Options>
#endif
class avl_set_member_hook;


//treap/treap_set/treap_multiset
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class treap;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class treap_set;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class treap_multiset;

//Default priority comparison functor
template <class T>
struct priority_compare;

//sgtree/sg_set/sg_multiset
#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class sgtree;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class sg_set;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class T, class ...Options>
#endif
class sg_multiset;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class bs_set_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class bs_set_member_hook;

//hashtable/unordered_set/unordered_multiset

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   , class O5  = none
   , class O6  = none
   , class O7  = none
   , class O8  = none
   , class O9  = none
   , class O10 = none
   >
#else
template<class T, class ...Options>
#endif
class hashtable;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   , class O5  = none
   , class O6  = none
   , class O7  = none
   , class O8  = none
   , class O9  = none
   , class O10 = none
   >
#else
template<class T, class ...Options>
#endif
class unordered_set;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class T
   , class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   , class O5  = none
   , class O6  = none
   , class O7  = none
   , class O8  = none
   , class O9  = none
   , class O10 = none
   >
#else
template<class T, class ...Options>
#endif
class unordered_multiset;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class ...Options>
#endif
class unordered_set_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   , class O4  = none
   >
#else
template<class ...Options>
#endif
class unordered_set_member_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class any_base_hook;

#ifndef STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES
template
   < class O1  = none
   , class O2  = none
   , class O3  = none
   >
#else
template<class ...Options>
#endif
class any_member_hook;

}  //namespace intrusive {
}  //namespace streams_boost {

/// @endcond

#endif   //#ifndef STREAMS_BOOST_INTRUSIVE_FWD_HPP
