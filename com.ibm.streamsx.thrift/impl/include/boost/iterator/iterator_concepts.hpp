// (C) Copyright Jeremy Siek 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ITERATOR_CONCEPTS_HPP
#define STREAMS_BOOST_ITERATOR_CONCEPTS_HPP

#include <streams_boost/concept_check.hpp>
#include <streams_boost/iterator/iterator_categories.hpp>

// Use streams_boost::detail::iterator_traits to work around some MSVC/Dinkumware problems.
#include <streams_boost/detail/iterator.hpp>

#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/type_traits/is_integral.hpp>

#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/mpl/or.hpp>

#include <streams_boost/static_assert.hpp>

// Use streams_boost/limits to work around missing limits headers on some compilers
#include <streams_boost/limits.hpp>
#include <streams_boost/config.hpp>

#include <algorithm>

#include <streams_boost/concept/detail/concept_def.hpp>

namespace streams_boost_concepts
{
  // Used a different namespace here (instead of "streams_boost") so that the
  // concept descriptions do not take for granted the names in
  // namespace streams_boost.

  //===========================================================================
  // Iterator Access Concepts

  STREAMS_BOOST_concept(ReadableIterator,(Iterator))
    : streams_boost::Assignable<Iterator>
    , streams_boost::CopyConstructible<Iterator>

  {
      typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::detail::iterator_traits<Iterator>::value_type value_type;
      typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::detail::iterator_traits<Iterator>::reference reference;

      STREAMS_BOOST_CONCEPT_USAGE(ReadableIterator)
      {

          value_type v = *i;
          streams_boost::ignore_unused_variable_warning(v);
      }
  private:
      Iterator i;
  };
  
  template <
      typename Iterator
    , typename ValueType = STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::detail::iterator_traits<Iterator>::value_type
  >
  struct WritableIterator
    : streams_boost::CopyConstructible<Iterator>
  {
      STREAMS_BOOST_CONCEPT_USAGE(WritableIterator)
      {
          *i = v;
      }
  private:
      ValueType v;
      Iterator i;
  };

  template <
      typename Iterator
    , typename ValueType = STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::detail::iterator_traits<Iterator>::value_type
  >
  struct WritableIteratorConcept : WritableIterator<Iterator,ValueType> {};
  
  STREAMS_BOOST_concept(SwappableIterator,(Iterator))
  {
      STREAMS_BOOST_CONCEPT_USAGE(SwappableIterator)
      {
          std::iter_swap(i1, i2);
      }
  private:
      Iterator i1;
      Iterator i2;
  };

  STREAMS_BOOST_concept(LvalueIterator,(Iterator))
  {
      typedef typename streams_boost::detail::iterator_traits<Iterator>::value_type value_type;
      
      STREAMS_BOOST_CONCEPT_USAGE(LvalueIterator)
      {
        value_type& r = const_cast<value_type&>(*i);
        streams_boost::ignore_unused_variable_warning(r);
      }
  private:
      Iterator i;
  };

  
  //===========================================================================
  // Iterator Traversal Concepts

  STREAMS_BOOST_concept(IncrementableIterator,(Iterator))
    : streams_boost::Assignable<Iterator>
    , streams_boost::CopyConstructible<Iterator>
  {
      typedef typename streams_boost::iterator_traversal<Iterator>::type traversal_category;

      STREAMS_BOOST_CONCEPT_ASSERT((
        streams_boost::Convertible<
            traversal_category
          , streams_boost::incrementable_traversal_tag
        >));

      STREAMS_BOOST_CONCEPT_USAGE(IncrementableIterator)
      {
          ++i;
          (void)i++;
      }
  private:
      Iterator i;
  };

  STREAMS_BOOST_concept(SinglePassIterator,(Iterator))
    : IncrementableIterator<Iterator>
    , streams_boost::EqualityComparable<Iterator>

  {
      STREAMS_BOOST_CONCEPT_ASSERT((
          streams_boost::Convertible<
             STREAMS_BOOST_DEDUCED_TYPENAME SinglePassIterator::traversal_category
           , streams_boost::single_pass_traversal_tag
          > ));
  };

  STREAMS_BOOST_concept(ForwardTraversal,(Iterator))
    : SinglePassIterator<Iterator>
    , streams_boost::DefaultConstructible<Iterator>
  {
      typedef typename streams_boost::detail::iterator_traits<Iterator>::difference_type difference_type;
      
      STREAMS_BOOST_MPL_ASSERT((streams_boost::is_integral<difference_type>));
      STREAMS_BOOST_MPL_ASSERT_RELATION(std::numeric_limits<difference_type>::is_signed, ==, true);

      STREAMS_BOOST_CONCEPT_ASSERT((
          streams_boost::Convertible<
             STREAMS_BOOST_DEDUCED_TYPENAME ForwardTraversal::traversal_category
           , streams_boost::forward_traversal_tag
          > ));
  };
  
  STREAMS_BOOST_concept(BidirectionalTraversal,(Iterator))
    : ForwardTraversal<Iterator>
  {
      STREAMS_BOOST_CONCEPT_ASSERT((
          streams_boost::Convertible<
             STREAMS_BOOST_DEDUCED_TYPENAME BidirectionalTraversal::traversal_category
           , streams_boost::bidirectional_traversal_tag
          > ));

      STREAMS_BOOST_CONCEPT_USAGE(BidirectionalTraversal)
      {
          --i;
          (void)i--;
      }
   private:
      Iterator i;
  };

  STREAMS_BOOST_concept(RandomAccessTraversal,(Iterator))
    : BidirectionalTraversal<Iterator>
  {
      STREAMS_BOOST_CONCEPT_ASSERT((
          streams_boost::Convertible<
             STREAMS_BOOST_DEDUCED_TYPENAME RandomAccessTraversal::traversal_category
           , streams_boost::random_access_traversal_tag
          > ));

      STREAMS_BOOST_CONCEPT_USAGE(RandomAccessTraversal)
      {
          i += n;
          i = i + n;
          i = n + i;
          i -= n;
          i = i - n;
          n = i - j;
      }
      
   private:
      typename BidirectionalTraversal<Iterator>::difference_type n;
      Iterator i, j;
  };

  //===========================================================================
  // Iterator Interoperability 

  namespace detail
  {
    template <typename Iterator1, typename Iterator2>
    void interop_single_pass_constraints(Iterator1 const& i1, Iterator2 const& i2)
    {
        bool b;
        b = i1 == i2;
        b = i1 != i2;

        b = i2 == i1;
        b = i2 != i1;
        streams_boost::ignore_unused_variable_warning(b);
    }

    template <typename Iterator1, typename Iterator2>
    void interop_rand_access_constraints(
        Iterator1 const& i1, Iterator2 const& i2,
        streams_boost::random_access_traversal_tag, streams_boost::random_access_traversal_tag)
    {
        bool b;
        typename streams_boost::detail::iterator_traits<Iterator2>::difference_type n;
        b = i1 <  i2;
        b = i1 <= i2;
        b = i1 >  i2;
        b = i1 >= i2;
        n = i1 -  i2;

        b = i2 <  i1;
        b = i2 <= i1;
        b = i2 >  i1;
        b = i2 >= i1;
        n = i2 -  i1;
        streams_boost::ignore_unused_variable_warning(b);
        streams_boost::ignore_unused_variable_warning(n);
    }

    template <typename Iterator1, typename Iterator2>
    void interop_rand_access_constraints(
        Iterator1 const&, Iterator2 const&,
        streams_boost::single_pass_traversal_tag, streams_boost::single_pass_traversal_tag)
    { }

  } // namespace detail

  STREAMS_BOOST_concept(InteroperableIterator,(Iterator)(ConstIterator))
  {
   private:
      typedef typename streams_boost::detail::pure_traversal_tag<
          typename streams_boost::iterator_traversal<
              Iterator
          >::type
      >::type traversal_category;

      typedef typename streams_boost::detail::pure_traversal_tag<
          typename streams_boost::iterator_traversal<
              ConstIterator
          >::type
      >::type const_traversal_category;
      
  public:
      STREAMS_BOOST_CONCEPT_ASSERT((SinglePassIterator<Iterator>));
      STREAMS_BOOST_CONCEPT_ASSERT((SinglePassIterator<ConstIterator>));

      STREAMS_BOOST_CONCEPT_USAGE(InteroperableIterator)
      {
          detail::interop_single_pass_constraints(i, ci);
          detail::interop_rand_access_constraints(i, ci, traversal_category(), const_traversal_category());

          ci = i;
      }
      
   private:
      Iterator      i;
      ConstIterator ci;
  };

} // namespace streams_boost_concepts

#include <streams_boost/concept/detail/concept_undef.hpp>

#endif // STREAMS_BOOST_ITERATOR_CONCEPTS_HPP
