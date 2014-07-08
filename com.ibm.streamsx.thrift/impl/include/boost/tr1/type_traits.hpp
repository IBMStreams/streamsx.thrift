//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TR1_TYPE_TRAITS_HPP_INCLUDED
#  define STREAMS_BOOST_TR1_TYPE_TRAITS_HPP_INCLUDED
#  include <streams_boost/tr1/detail/config.hpp>

#ifdef STREAMS_BOOST_HAS_TR1_TYPE_TRAITS

#  ifdef STREAMS_BOOST_HAS_INCLUDE_NEXT
#     include_next STREAMS_BOOST_TR1_HEADER(type_traits)
#  else
#     include <streams_boost/tr1/detail/config_all.hpp>
#     include STREAMS_BOOST_TR1_STD_HEADER(STREAMS_BOOST_TR1_PATH(type_traits))
#  endif

#else
// Boost Type Traits:
#include <streams_boost/type_traits.hpp>
#include <streams_boost/type_traits/is_base_of_tr1.hpp>

namespace std { namespace tr1{

   using ::streams_boost::integral_constant;
   using ::streams_boost::true_type;
   using ::streams_boost::false_type;
   using ::streams_boost::is_void;
   using ::streams_boost::is_integral;
   using ::streams_boost::is_floating_point;
   using ::streams_boost::is_array;
   using ::streams_boost::is_pointer;
   using ::streams_boost::is_reference;
   using ::streams_boost::is_member_object_pointer;
   using ::streams_boost::is_member_function_pointer;
   using ::streams_boost::is_enum;
   using ::streams_boost::is_union;
   using ::streams_boost::is_class;
   using ::streams_boost::is_function;
   using ::streams_boost::is_arithmetic;
   using ::streams_boost::is_fundamental;
   using ::streams_boost::is_object;
   using ::streams_boost::is_scalar;
   using ::streams_boost::is_compound;
   using ::streams_boost::is_member_pointer;
   using ::streams_boost::is_const;
   using ::streams_boost::is_volatile;
   using ::streams_boost::is_pod;
   using ::streams_boost::is_empty;
   using ::streams_boost::is_polymorphic;
   using ::streams_boost::is_abstract;
   using ::streams_boost::has_trivial_constructor;
   using ::streams_boost::has_trivial_copy;
   using ::streams_boost::has_trivial_assign;
   using ::streams_boost::has_trivial_destructor;
   using ::streams_boost::has_nothrow_constructor;
   using ::streams_boost::has_nothrow_copy;
   using ::streams_boost::has_nothrow_assign;
   using ::streams_boost::has_virtual_destructor;
   using ::streams_boost::is_signed;
   using ::streams_boost::is_unsigned;
   using ::streams_boost::alignment_of;
   using ::streams_boost::rank;
   using ::streams_boost::extent;
   using ::streams_boost::is_same;
   using ::streams_boost::tr1::is_base_of;
   using ::streams_boost::is_convertible;
   using ::streams_boost::remove_const;
   using ::streams_boost::remove_volatile;
   using ::streams_boost::remove_cv;
   using ::streams_boost::add_const;
   using ::streams_boost::add_volatile;
   using ::streams_boost::add_cv;
   using ::streams_boost::remove_reference;
   using ::streams_boost::add_reference;
   using ::streams_boost::remove_extent;
   using ::streams_boost::remove_all_extents;
   using ::streams_boost::remove_pointer;
   using ::streams_boost::add_pointer;
   using ::streams_boost::aligned_storage;

} }

#endif

#endif
