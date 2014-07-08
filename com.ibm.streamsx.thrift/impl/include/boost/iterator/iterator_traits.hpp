// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef ITERATOR_TRAITS_DWA200347_STREAMS_HPP
# define ITERATOR_TRAITS_DWA200347_STREAMS_HPP

# include <streams_boost/detail/iterator.hpp>
# include <streams_boost/detail/workaround.hpp>

namespace streams_boost { 

// Unfortunately, g++ 2.95.x chokes when we define a class template
// iterator_category which has the same name as its
// std::iterator_category() function, probably due in part to the
// "std:: is visible globally" hack it uses.  Use
// STREAMS_BOOST_ITERATOR_CATEGORY to write code that's portable to older
// GCCs.

# if STREAMS_BOOST_WORKAROUND(__GNUC__, <= 2)
#  define STREAMS_BOOST_ITERATOR_CATEGORY iterator_category_
# else
#  define STREAMS_BOOST_ITERATOR_CATEGORY iterator_category
# endif


template <class Iterator>
struct iterator_value
{
    typedef typename streams_boost::detail::iterator_traits<Iterator>::value_type type;
};
  
template <class Iterator>
struct iterator_reference
{
    typedef typename streams_boost::detail::iterator_traits<Iterator>::reference type;
};
  
  
template <class Iterator>
struct iterator_pointer
{
    typedef typename streams_boost::detail::iterator_traits<Iterator>::pointer type;
};
  
template <class Iterator>
struct iterator_difference
{
    typedef typename streams_boost::detail::iterator_traits<Iterator>::difference_type type;
};

template <class Iterator>
struct STREAMS_BOOST_ITERATOR_CATEGORY
{
    typedef typename streams_boost::detail::iterator_traits<Iterator>::iterator_category type;
};

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
template <>
struct iterator_value<int>
{
    typedef void type;
};
  
template <>
struct iterator_reference<int>
{
    typedef void type;
};

template <>
struct iterator_pointer<int>
{
    typedef void type;
};
  
template <>
struct iterator_difference<int>
{
    typedef void type;
};
  
template <>
struct STREAMS_BOOST_ITERATOR_CATEGORY<int>
{
    typedef void type;
};
# endif

} // namespace streams_boost::iterator

#endif // ITERATOR_TRAITS_DWA200347_STREAMS_HPP
