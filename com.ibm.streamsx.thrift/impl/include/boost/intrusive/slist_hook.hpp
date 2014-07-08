/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Olaf Krzikalla 2004-2006.
// (C) Copyright Ion Gaztanaga  2006-2009
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)
//
// See http://www.streams_boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////

#ifndef STREAMS_BOOST_INTRUSIVE_SLIST_HOOK_HPP
#define STREAMS_BOOST_INTRUSIVE_SLIST_HOOK_HPP

#include <streams_boost/intrusive/detail/config_begin.hpp>
#include <streams_boost/intrusive/intrusive_fwd.hpp>
#include <streams_boost/intrusive/detail/utilities.hpp>
#include <streams_boost/intrusive/detail/slist_node.hpp>
#include <streams_boost/intrusive/circular_slist_algorithms.hpp>
#include <streams_boost/intrusive/link_mode.hpp>
#include <streams_boost/intrusive/options.hpp>
#include <streams_boost/intrusive/detail/generic_hook.hpp>

namespace streams_boost {
namespace intrusive {

/// @cond
template<class VoidPointer>
struct get_slist_node_algo
{
   typedef circular_slist_algorithms<slist_node_traits<VoidPointer> > type;
};

/// @endcond

//! Helper metafunction to define a \c slist_base_hook that yields to the same
//! type when the same options (either explicitly or implicitly) are used.
#if defined(STREAMS_BOOST_INTRUSIVE_DOXYGEN_INVOKED) || defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
template<class ...Options>
#else
template<class O1 = none, class O2 = none, class O3 = none>
#endif
struct make_slist_base_hook
{
   /// @cond
   typedef typename pack_options
      < hook_defaults, 
         #if !defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
         O1, O2, O3
         #else
         Options...
         #endif
      >::type packed_options;

   typedef detail::generic_hook
   < get_slist_node_algo<typename packed_options::void_pointer>
   , typename packed_options::tag
   , packed_options::link_mode
   , detail::SlistBaseHook
   > implementation_defined;
   /// @endcond
   typedef implementation_defined type;
};

//! Derive a class from slist_base_hook in order to store objects in 
//! in an list. slist_base_hook holds the data necessary to maintain the 
//! list and provides an appropriate value_traits class for list.
//! 
//! The hook admits the following options: \c tag<>, \c void_pointer<> and
//! \c link_mode<>.
//!
//! \c tag<> defines a tag to identify the node. 
//! The same tag value can be used in different classes, but if a class is 
//! derived from more than one \c list_base_hook, then each \c list_base_hook needs its 
//! unique tag.
//!
//! \c link_mode<> will specify the linking mode of the hook (\c normal_link,
//! \c auto_unlink or \c safe_link).
//!
//! \c void_pointer<> is the pointer type that will be used internally in the hook
//! and the the container configured to use this hook.
#if defined(STREAMS_BOOST_INTRUSIVE_DOXYGEN_INVOKED) || defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
template<class ...Options>
#else
template<class O1, class O2, class O3>
#endif
class slist_base_hook
   :  public make_slist_base_hook<
         #if !defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
         O1, O2, O3
         #else
         Options...
         #endif
      >::type
{
   #if defined(STREAMS_BOOST_INTRUSIVE_DOXYGEN_INVOKED)
   public:
   //! <b>Effects</b>: If link_mode is \c auto_unlink or \c safe_link
   //!   initializes the node to an unlinked state.
   //! 
   //! <b>Throws</b>: Nothing. 
   slist_base_hook();

   //! <b>Effects</b>: If link_mode is \c auto_unlink or \c safe_link
   //!   initializes the node to an unlinked state. The argument is ignored.
   //! 
   //! <b>Throws</b>: Nothing. 
   //! 
   //! <b>Rationale</b>: Providing a copy-constructor
   //!   makes classes using the hook STL-compliant without forcing the 
   //!   user to do some additional work. \c swap can be used to emulate
   //!   move-semantics.
   slist_base_hook(const slist_base_hook& );

   //! <b>Effects</b>: Empty function. The argument is ignored.
   //! 
   //! <b>Throws</b>: Nothing. 
   //! 
   //! <b>Rationale</b>: Providing an assignment operator 
   //!   makes classes using the hook STL-compliant without forcing the 
   //!   user to do some additional work. \c swap can be used to emulate
   //!   move-semantics.
   slist_base_hook& operator=(const slist_base_hook& );

   //! <b>Effects</b>: If link_mode is \c normal_link, the destructor does
   //!   nothing (ie. no code is generated). If link_mode is \c safe_link and the
   //!   object is stored in an slist an assertion is raised. If link_mode is
   //!   \c auto_unlink and \c is_linked() is true, the node is unlinked.
   //! 
   //! <b>Throws</b>: Nothing. 
   ~slist_base_hook();

   //! <b>Effects</b>: Swapping two nodes swaps the position of the elements 
   //!   related to those nodes in one or two containers. That is, if the node 
   //!   this is part of the element e1, the node x is part of the element e2 
   //!   and both elements are included in the containers s1 and s2, then after 
   //!   the swap-operation e1 is in s2 at the position of e2 and e2 is in s1 
   //!   at the position of e1. If one element is not in a container, then 
   //!   after the swap-operation the other element is not in a container. 
   //!   Iterators to e1 and e2 related to those nodes are invalidated. 
   //!
   //! <b>Complexity</b>: Constant 
   //!
   //! <b>Throws</b>: Nothing. 
   void swap_nodes(slist_base_hook &other);

   //! <b>Precondition</b>: link_mode must be \c safe_link or \c auto_unlink.
   //!
   //! <b>Returns</b>: true, if the node belongs to a container, false
   //!   otherwise. This function can be used to test whether \c slist::iterator_to 
   //!   will return a valid iterator. 
   //!
   //! <b>Complexity</b>: Constant 
   bool is_linked() const;

   //! <b>Effects</b>: Removes the node if it's inserted in a container.
   //!   This function is only allowed if link_mode is \c auto_unlink.
   //! 
   //! <b>Throws</b>: Nothing. 
   void unlink();
   #endif
};

//! Helper metafunction to define a \c slist_member_hook that yields to the same
//! type when the same options (either explicitly or implicitly) are used.
#if defined(STREAMS_BOOST_INTRUSIVE_DOXYGEN_INVOKED) || defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
template<class ...Options>
#else
template<class O1 = none, class O2 = none, class O3 = none>
#endif
struct make_slist_member_hook
{
   /// @cond
   typedef typename pack_options
      < hook_defaults, 
         #if !defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
         O1, O2, O3
         #else
         Options...
         #endif
      >::type packed_options;

   typedef detail::generic_hook
   < get_slist_node_algo<typename packed_options::void_pointer>
   , member_tag
   , packed_options::link_mode
   , detail::NoBaseHook
   > implementation_defined;
   /// @endcond
   typedef implementation_defined type;
};

//! Put a public data member slist_member_hook in order to store objects of this class in
//! an list. slist_member_hook holds the data necessary for maintaining the list and 
//! provides an appropriate value_traits class for list.
//! 
//! The hook admits the following options: \c void_pointer<> and
//! \c link_mode<>.
//! 
//! \c link_mode<> will specify the linking mode of the hook (\c normal_link,
//! \c auto_unlink or \c safe_link).
//!
//! \c void_pointer<> is the pointer type that will be used internally in the hook
//! and the the container configured to use this hook.
#if defined(STREAMS_BOOST_INTRUSIVE_DOXYGEN_INVOKED) || defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
template<class ...Options>
#else
template<class O1, class O2, class O3>
#endif
class slist_member_hook
   :  public make_slist_member_hook<
         #if !defined(STREAMS_BOOST_INTRUSIVE_VARIADIC_TEMPLATES)
         O1, O2, O3
         #else
         Options...
         #endif
      >::type
{
   #if defined(STREAMS_BOOST_INTRUSIVE_DOXYGEN_INVOKED)
   public:
   //! <b>Effects</b>: If link_mode is \c auto_unlink or \c safe_link
   //!   initializes the node to an unlinked state.
   //! 
   //! <b>Throws</b>: Nothing. 
   slist_member_hook();

   //! <b>Effects</b>: If link_mode is \c auto_unlink or \c safe_link
   //!   initializes the node to an unlinked state. The argument is ignored.
   //! 
   //! <b>Throws</b>: Nothing. 
   //! 
   //! <b>Rationale</b>: Providing a copy-constructor
   //!   makes classes using the hook STL-compliant without forcing the 
   //!   user to do some additional work. \c swap can be used to emulate
   //!   move-semantics.
   slist_member_hook(const slist_member_hook& );

   //! <b>Effects</b>: Empty function. The argument is ignored.
   //! 
   //! <b>Throws</b>: Nothing. 
   //! 
   //! <b>Rationale</b>: Providing an assignment operator 
   //!   makes classes using the hook STL-compliant without forcing the 
   //!   user to do some additional work. \c swap can be used to emulate
   //!   move-semantics.
   slist_member_hook& operator=(const slist_member_hook& );

   //! <b>Effects</b>: If link_mode is \c normal_link, the destructor does
   //!   nothing (ie. no code is generated). If link_mode is \c safe_link and the
   //!   object is stored in an slist an assertion is raised. If link_mode is
   //!   \c auto_unlink and \c is_linked() is true, the node is unlinked.
   //! 
   //! <b>Throws</b>: Nothing. 
   ~slist_member_hook();

   //! <b>Effects</b>: Swapping two nodes swaps the position of the elements 
   //!   related to those nodes in one or two containers. That is, if the node 
   //!   this is part of the element e1, the node x is part of the element e2 
   //!   and both elements are included in the containers s1 and s2, then after 
   //!   the swap-operation e1 is in s2 at the position of e2 and e2 is in s1 
   //!   at the position of e1. If one element is not in a container, then 
   //!   after the swap-operation the other element is not in a container. 
   //!   Iterators to e1 and e2 related to those nodes are invalidated. 
   //!
   //! <b>Complexity</b>: Constant 
   //!
   //! <b>Throws</b>: Nothing. 
   void swap_nodes(slist_member_hook &other);

   //! <b>Precondition</b>: link_mode must be \c safe_link or \c auto_unlink.
   //!
   //! <b>Returns</b>: true, if the node belongs to a container, false
   //!   otherwise. This function can be used to test whether \c slist::iterator_to 
   //!   will return a valid iterator. 
   //!
   //! <b>Complexity</b>: Constant 
   bool is_linked() const;

   //! <b>Effects</b>: Removes the node if it's inserted in a container.
   //!   This function is only allowed if link_mode is \c auto_unlink.
   //! 
   //! <b>Throws</b>: Nothing. 
   void unlink();
   #endif
};

} //namespace intrusive 
} //namespace streams_boost 

#include <streams_boost/intrusive/detail/config_end.hpp>

#endif //STREAMS_BOOST_INTRUSIVE_SLIST_HOOK_HPP
