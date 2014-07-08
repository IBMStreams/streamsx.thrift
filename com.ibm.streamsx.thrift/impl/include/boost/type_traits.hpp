//  (C) Copyright John Maddock 2000. 
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt).
//
//  See http://www.streams_boost.org/libs/type_traits for most recent version including documentation.

//  See streams_boost/type_traits/*.hpp for full copyright notices.

#ifndef STREAMS_BOOST_TYPE_TRAITS_HPP
#define STREAMS_BOOST_TYPE_TRAITS_HPP

#include "streams_boost/type_traits/add_const.hpp"
#include "streams_boost/type_traits/add_cv.hpp"
#include "streams_boost/type_traits/add_pointer.hpp"
#include "streams_boost/type_traits/add_reference.hpp"
#include "streams_boost/type_traits/add_volatile.hpp"
#include "streams_boost/type_traits/alignment_of.hpp"
#include "streams_boost/type_traits/has_nothrow_assign.hpp"
#include "streams_boost/type_traits/has_nothrow_constructor.hpp"
#include "streams_boost/type_traits/has_nothrow_copy.hpp"
#include "streams_boost/type_traits/has_nothrow_destructor.hpp"
#include "streams_boost/type_traits/has_trivial_assign.hpp"
#include "streams_boost/type_traits/has_trivial_constructor.hpp"
#include "streams_boost/type_traits/has_trivial_copy.hpp"
#include "streams_boost/type_traits/has_trivial_destructor.hpp"
#include "streams_boost/type_traits/has_virtual_destructor.hpp"
#include "streams_boost/type_traits/is_signed.hpp"
#include "streams_boost/type_traits/is_unsigned.hpp"
#include "streams_boost/type_traits/is_abstract.hpp"
#include "streams_boost/type_traits/is_arithmetic.hpp"
#include "streams_boost/type_traits/is_array.hpp"
#include "streams_boost/type_traits/is_base_and_derived.hpp"
#include "streams_boost/type_traits/is_base_of.hpp"
#include "streams_boost/type_traits/is_class.hpp"
#include "streams_boost/type_traits/is_compound.hpp"
#include "streams_boost/type_traits/is_const.hpp"
#include "streams_boost/type_traits/is_convertible.hpp"
#include "streams_boost/type_traits/is_empty.hpp"
#include "streams_boost/type_traits/is_enum.hpp"
#include "streams_boost/type_traits/is_float.hpp"
#include "streams_boost/type_traits/is_floating_point.hpp"
#include "streams_boost/type_traits/is_function.hpp"
#include "streams_boost/type_traits/is_fundamental.hpp"
#include "streams_boost/type_traits/is_integral.hpp"
#include "streams_boost/type_traits/is_member_function_pointer.hpp"
#include "streams_boost/type_traits/is_member_object_pointer.hpp"
#include "streams_boost/type_traits/is_member_pointer.hpp"
#include "streams_boost/type_traits/is_object.hpp"
#include "streams_boost/type_traits/is_pod.hpp"
#include "streams_boost/type_traits/is_polymorphic.hpp"
#include "streams_boost/type_traits/is_pointer.hpp"
#include "streams_boost/type_traits/is_reference.hpp"
#include "streams_boost/type_traits/is_same.hpp"
#include "streams_boost/type_traits/is_scalar.hpp"
#include "streams_boost/type_traits/is_stateless.hpp"
#include "streams_boost/type_traits/is_union.hpp"
#include "streams_boost/type_traits/is_void.hpp"
#include "streams_boost/type_traits/is_volatile.hpp"
#include "streams_boost/type_traits/rank.hpp"
#include "streams_boost/type_traits/extent.hpp"
#include "streams_boost/type_traits/remove_bounds.hpp"
#include "streams_boost/type_traits/remove_extent.hpp"
#include "streams_boost/type_traits/remove_all_extents.hpp"
#include "streams_boost/type_traits/remove_const.hpp"
#include "streams_boost/type_traits/remove_cv.hpp"
#include "streams_boost/type_traits/remove_pointer.hpp"
#include "streams_boost/type_traits/remove_reference.hpp"
#include "streams_boost/type_traits/remove_volatile.hpp"
#include "streams_boost/type_traits/type_with_alignment.hpp"
#include "streams_boost/type_traits/function_traits.hpp"
#include "streams_boost/type_traits/aligned_storage.hpp"
#include "streams_boost/type_traits/floating_point_promotion.hpp"
#if !(defined(__sgi) && defined(__EDG_VERSION__) && (__EDG_VERSION__ == 238))
#include "streams_boost/type_traits/integral_promotion.hpp"
#include "streams_boost/type_traits/promote.hpp"
#endif
#include <streams_boost/type_traits/make_unsigned.hpp>
#include <streams_boost/type_traits/make_signed.hpp>
#include <streams_boost/type_traits/decay.hpp>
#include <streams_boost/type_traits/is_complex.hpp>

#include "streams_boost/type_traits/ice.hpp"

#endif // STREAMS_BOOST_TYPE_TRAITS_HPP




