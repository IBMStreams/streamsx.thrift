/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.streams_boost.org for most recent version.
  *   FILE         instances.cpp
  *   VERSION      see <streams_boost/version.hpp>
  *   DESCRIPTION: Defines those template instances that are placed in the
  *                library rather than in the users object files.
  */

//
// note no include guard, we may include this multiple times:
//
#ifndef STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES

namespace streams_boost{

//
// this header can be included multiple times, each time with
// a different character type, STREAMS_BOOST_REGEX_CHAR_T must be defined
// first:
//
#ifndef STREAMS_BOOST_REGEX_CHAR_T
#  error "STREAMS_BOOST_REGEX_CHAR_T not defined"
#endif

#ifndef STREAMS_BOOST_REGEX_TRAITS_T
#  define STREAMS_BOOST_REGEX_TRAITS_T , streams_boost::regex_traits<STREAMS_BOOST_REGEX_CHAR_T >
#endif

//
// what follows is compiler specific:
//

#if  defined(__BORLANDC__) && (__BORLANDC__ < 0x600)

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_PREFIX
#endif

#  ifndef STREAMS_BOOST_REGEX_INSTANTIATE
#     pragma option push -Jgx
#  endif

template class STREAMS_BOOST_REGEX_DECL basic_regex< STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >;
template class STREAMS_BOOST_REGEX_DECL match_results< const STREAMS_BOOST_REGEX_CHAR_T* >;
#ifndef STREAMS_BOOST_NO_STD_ALLOCATOR
template class STREAMS_BOOST_REGEX_DECL ::streams_boost::re_detail::perl_matcher<STREAMS_BOOST_REGEX_CHAR_T const *, match_results< const STREAMS_BOOST_REGEX_CHAR_T* >::allocator_type STREAMS_BOOST_REGEX_TRAITS_T >;
#endif

#  ifndef STREAMS_BOOST_REGEX_INSTANTIATE
#     pragma option pop
#  endif

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif

#elif defined(STREAMS_BOOST_MSVC) || defined(__ICL)

#  ifndef STREAMS_BOOST_REGEX_INSTANTIATE
#     ifdef __GNUC__
#        define template __extension__ extern template
#     else
#        if STREAMS_BOOST_MSVC > 1310
#           define STREAMS_BOOST_REGEX_TEMPLATE_DECL
#        endif
#        define template extern template
#     endif
#  endif

#ifndef STREAMS_BOOST_REGEX_TEMPLATE_DECL
#  define STREAMS_BOOST_REGEX_TEMPLATE_DECL STREAMS_BOOST_REGEX_DECL
#endif

#  ifdef STREAMS_BOOST_MSVC
#     pragma warning(push)
#     pragma warning(disable : 4251 4231 4660)
#  endif

template class STREAMS_BOOST_REGEX_TEMPLATE_DECL basic_regex< STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >;

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
template class STREAMS_BOOST_REGEX_TEMPLATE_DECL match_results< const STREAMS_BOOST_REGEX_CHAR_T* >;
#endif
#ifndef STREAMS_BOOST_NO_STD_ALLOCATOR
template class STREAMS_BOOST_REGEX_TEMPLATE_DECL ::streams_boost::re_detail::perl_matcher<STREAMS_BOOST_REGEX_CHAR_T const *, match_results< const STREAMS_BOOST_REGEX_CHAR_T* >::allocator_type STREAMS_BOOST_REGEX_TRAITS_T >;
#endif
#if !(defined(STREAMS_BOOST_DINKUMWARE_STDLIB) && (STREAMS_BOOST_DINKUMWARE_STDLIB <= 1))\
   && !(defined(STREAMS_BOOST_INTEL_CXX_VERSION) && (STREAMS_BOOST_INTEL_CXX_VERSION <= 800))\
   && !(defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION))\
   && !defined(STREAMS_BOOST_REGEX_ICU_INSTANCES)
#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
template class STREAMS_BOOST_REGEX_TEMPLATE_DECL match_results< std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator >;
#endif
#ifndef STREAMS_BOOST_NO_STD_ALLOCATOR
template class STREAMS_BOOST_REGEX_TEMPLATE_DECL ::streams_boost::re_detail::perl_matcher< std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator, match_results< std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator >::allocator_type, streams_boost::regex_traits<STREAMS_BOOST_REGEX_CHAR_T > >;
#endif
#endif


#  ifdef STREAMS_BOOST_MSVC
#     pragma warning(pop)
#  endif

#  ifdef template
#     undef template
#  endif

#undef STREAMS_BOOST_REGEX_TEMPLATE_DECL

#elif (defined(__GNUC__) && (__GNUC__ >= 3))

#  ifndef STREAMS_BOOST_REGEX_INSTANTIATE
#     define template __extension__ extern template
#  endif

#if !defined(STREAMS_BOOST_NO_STD_LOCALE) && !defined(STREAMS_BOOST_REGEX_ICU_INSTANCES)
namespace re_detail{
template STREAMS_BOOST_REGEX_DECL
std::locale cpp_regex_traits_base<STREAMS_BOOST_REGEX_CHAR_T>::imbue(const std::locale& l);

template STREAMS_BOOST_REGEX_DECL
cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::string_type 
   cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::transform_primary(const STREAMS_BOOST_REGEX_CHAR_T* p1, const STREAMS_BOOST_REGEX_CHAR_T* p2) const;
template STREAMS_BOOST_REGEX_DECL
cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::string_type 
   cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::transform(const STREAMS_BOOST_REGEX_CHAR_T* p1, const STREAMS_BOOST_REGEX_CHAR_T* p2) const;
template STREAMS_BOOST_REGEX_DECL
cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::string_type 
   cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::lookup_collatename(const STREAMS_BOOST_REGEX_CHAR_T* p1, const STREAMS_BOOST_REGEX_CHAR_T* p2) const;
template STREAMS_BOOST_REGEX_DECL
void cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::init();
template STREAMS_BOOST_REGEX_DECL
cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::char_class_type 
   cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::lookup_classname_imp(const STREAMS_BOOST_REGEX_CHAR_T* p1, const STREAMS_BOOST_REGEX_CHAR_T* p2) const;
#ifdef STREAMS_BOOST_REGEX_BUGGY_CTYPE_FACET
template STREAMS_BOOST_REGEX_DECL
bool cpp_regex_traits_implementation<STREAMS_BOOST_REGEX_CHAR_T>::isctype(const STREAMS_BOOST_REGEX_CHAR_T c, char_class_type mask) const;
#endif
} // namespace
template STREAMS_BOOST_REGEX_DECL
int cpp_regex_traits<STREAMS_BOOST_REGEX_CHAR_T>::toi(const STREAMS_BOOST_REGEX_CHAR_T*& first, const STREAMS_BOOST_REGEX_CHAR_T* last, int radix)const;
template STREAMS_BOOST_REGEX_DECL
std::string cpp_regex_traits<STREAMS_BOOST_REGEX_CHAR_T>::catalog_name(const std::string& name);
template STREAMS_BOOST_REGEX_DECL
std::string& cpp_regex_traits<STREAMS_BOOST_REGEX_CHAR_T>::get_catalog_name_inst();
template STREAMS_BOOST_REGEX_DECL
std::string cpp_regex_traits<STREAMS_BOOST_REGEX_CHAR_T>::get_catalog_name();
#ifdef STREAMS_BOOST_HAS_THREADS
template STREAMS_BOOST_REGEX_DECL
static_mutex& cpp_regex_traits<STREAMS_BOOST_REGEX_CHAR_T>::get_mutex_inst();
#endif
#endif

template STREAMS_BOOST_REGEX_DECL basic_regex<STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >& 
   basic_regex<STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >::do_assign(
      const STREAMS_BOOST_REGEX_CHAR_T* p1, 
      const STREAMS_BOOST_REGEX_CHAR_T* p2, 
      flag_type f);
template STREAMS_BOOST_REGEX_DECL basic_regex<STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >::locale_type STREAMS_BOOST_REGEX_CALL 
   basic_regex<STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >::imbue(locale_type l);

template STREAMS_BOOST_REGEX_DECL void STREAMS_BOOST_REGEX_CALL 
   match_results<const STREAMS_BOOST_REGEX_CHAR_T*>::maybe_assign(
      const match_results<const STREAMS_BOOST_REGEX_CHAR_T*>& m);

namespace re_detail{
template STREAMS_BOOST_REGEX_DECL void perl_matcher<STREAMS_BOOST_REGEX_CHAR_T const *, match_results< const STREAMS_BOOST_REGEX_CHAR_T* >::allocator_type STREAMS_BOOST_REGEX_TRAITS_T >::construct_init(
      const basic_regex<STREAMS_BOOST_REGEX_CHAR_T STREAMS_BOOST_REGEX_TRAITS_T >& e, match_flag_type f);
template STREAMS_BOOST_REGEX_DECL bool perl_matcher<STREAMS_BOOST_REGEX_CHAR_T const *, match_results< const STREAMS_BOOST_REGEX_CHAR_T* >::allocator_type STREAMS_BOOST_REGEX_TRAITS_T >::match();
template STREAMS_BOOST_REGEX_DECL bool perl_matcher<STREAMS_BOOST_REGEX_CHAR_T const *, match_results< const STREAMS_BOOST_REGEX_CHAR_T* >::allocator_type STREAMS_BOOST_REGEX_TRAITS_T >::find();
} // namespace

#if (defined(__GLIBCPP__) || defined(__GLIBCXX__)) \
   && !defined(STREAMS_BOOST_REGEX_ICU_INSTANCES)\
   && !defined(__SGI_STL_PORT)\
   && !defined(_STLPORT_VERSION)
// std:basic_string<>::const_iterator instances as well:
template STREAMS_BOOST_REGEX_DECL void STREAMS_BOOST_REGEX_CALL 
   match_results<std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator>::maybe_assign(
      const match_results<std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator>& m);

namespace re_detail{
template STREAMS_BOOST_REGEX_DECL void perl_matcher<std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator, match_results< std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator >::allocator_type, streams_boost::regex_traits<STREAMS_BOOST_REGEX_CHAR_T > >::construct_init(
      const basic_regex<STREAMS_BOOST_REGEX_CHAR_T>& e, match_flag_type f);
template STREAMS_BOOST_REGEX_DECL bool perl_matcher<std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator, match_results< std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator >::allocator_type, streams_boost::regex_traits<STREAMS_BOOST_REGEX_CHAR_T > >::match();
template STREAMS_BOOST_REGEX_DECL bool perl_matcher<std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator, match_results< std::basic_string<STREAMS_BOOST_REGEX_CHAR_T>::const_iterator >::allocator_type, streams_boost::regex_traits<STREAMS_BOOST_REGEX_CHAR_T > >::find();
} // namespace
#endif

#  ifdef template
#     undef template
#  endif


#endif

} // namespace streams_boost

#endif // STREAMS_BOOST_REGEX_NO_EXTERNAL_TEMPLATES





