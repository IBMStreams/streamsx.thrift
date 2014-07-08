//
// (C) Copyright Jeremy Siek 2000.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
// Revision History:
//   05 May   2001: Workarounds for HP aCC from Thomas Matelich. (Jeremy Siek)
//   02 April 2001: Removed limits header altogether. (Jeremy Siek)
//   01 April 2001: Modified to use new <streams_boost/limits.hpp> header. (JMaddock)
//

// See http://www.streams_boost.org/libs/concept_check for documentation.

#ifndef STREAMS_BOOST_CONCEPT_CHECKS_HPP
# define STREAMS_BOOST_CONCEPT_CHECKS_HPP

# include <streams_boost/concept/assert.hpp>

# include <streams_boost/iterator.hpp>
# include <streams_boost/type_traits/conversion_traits.hpp>
# include <utility>
# include <streams_boost/type_traits/is_same.hpp>
# include <streams_boost/type_traits/is_void.hpp>
# include <streams_boost/mpl/assert.hpp>
# include <streams_boost/mpl/bool.hpp>
# include <streams_boost/detail/workaround.hpp>
# include <streams_boost/detail/iterator.hpp>

# include <streams_boost/concept/usage.hpp>
# include <streams_boost/concept/detail/concept_def.hpp>

namespace streams_boost
{

  //
  // Backward compatibility
  //
  
  template <class Model>
  inline void function_requires(Model* = 0)
  {
      STREAMS_BOOST_CONCEPT_ASSERT((Model));
  }    
  template <class T> inline void ignore_unused_variable_warning(T const&) {}
  
#  define STREAMS_BOOST_CLASS_REQUIRE(type_var, ns, concept)    \
    STREAMS_BOOST_CONCEPT_ASSERT((ns::concept<type_var>))

#  define STREAMS_BOOST_CLASS_REQUIRE2(type_var1, type_var2, ns, concept)   \
    STREAMS_BOOST_CONCEPT_ASSERT((ns::concept<type_var1,type_var2>))

#  define STREAMS_BOOST_CLASS_REQUIRE3(tv1, tv2, tv3, ns, concept)  \
    STREAMS_BOOST_CONCEPT_ASSERT((ns::concept<tv1,tv2,tv3>))

#  define STREAMS_BOOST_CLASS_REQUIRE4(tv1, tv2, tv3, tv4, ns, concept) \
    STREAMS_BOOST_CONCEPT_ASSERT((ns::concept<tv1,tv2,tv3,tv4>))

  
  //
  // Begin concept definitions
  //
  STREAMS_BOOST_concept(Integer, (T))
  {
      STREAMS_BOOST_CONCEPT_USAGE(Integer)
        { 
            x.error_type_must_be_an_integer_type();
        }
   private:
      T x;
  };

  template <> struct Integer<signed char> {};
  template <> struct Integer<unsigned char> {};
  template <> struct Integer<short> {};
  template <> struct Integer<unsigned short> {};
  template <> struct Integer<int> {};
  template <> struct Integer<unsigned int> {};
  template <> struct Integer<long> {};
  template <> struct Integer<unsigned long> {};
# if defined(STREAMS_BOOST_HAS_LONG_LONG)
  template <> struct Integer< ::streams_boost::long_long_type> {};
  template <> struct Integer< ::streams_boost::ulong_long_type> {};
# elif defined(STREAMS_BOOST_HAS_MS_INT64)
  template <> struct Integer<__int64> {};
  template <> struct Integer<unsigned __int64> {};
# endif

  STREAMS_BOOST_concept(SignedInteger,(T)) {
    STREAMS_BOOST_CONCEPT_USAGE(SignedInteger) { 
      x.error_type_must_be_a_signed_integer_type();
    }
   private:
    T x;
  };
  template <> struct SignedInteger<signed char> { };
  template <> struct SignedInteger<short> {};
  template <> struct SignedInteger<int> {};
  template <> struct SignedInteger<long> {};
# if defined(STREAMS_BOOST_HAS_LONG_LONG)
  template <> struct SignedInteger< ::streams_boost::long_long_type> {};
# elif defined(STREAMS_BOOST_HAS_MS_INT64)
  template <> struct SignedInteger<__int64> {};
# endif      

  STREAMS_BOOST_concept(UnsignedInteger,(T)) {
    STREAMS_BOOST_CONCEPT_USAGE(UnsignedInteger) { 
      x.error_type_must_be_an_unsigned_integer_type();
    }
   private:
    T x;
  };
  
  template <> struct UnsignedInteger<unsigned char> {};
  template <> struct UnsignedInteger<unsigned short> {};
  template <> struct UnsignedInteger<unsigned int> {};
  template <> struct UnsignedInteger<unsigned long> {};
# if defined(STREAMS_BOOST_HAS_LONG_LONG)
  template <> struct UnsignedInteger< ::streams_boost::ulong_long_type> {};
# elif defined(STREAMS_BOOST_HAS_MS_INT64)
  template <> struct UnsignedInteger<unsigned __int64> {};
# endif

  //===========================================================================
  // Basic Concepts

  STREAMS_BOOST_concept(DefaultConstructible,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(DefaultConstructible) {
      TT a;               // require default constructor
      ignore_unused_variable_warning(a);
    }
  };

  STREAMS_BOOST_concept(Assignable,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(Assignable) {
#if !defined(_ITERATOR_) // back_insert_iterator broken for VC++ STL
      a = a;             // require assignment operator
#endif
      const_constraints(a);
    }
   private:
    void const_constraints(const TT& b) {
#if !defined(_ITERATOR_) // back_insert_iterator broken for VC++ STL
      a = b;              // const required for argument to assignment
#else
      ignore_unused_variable_warning(b);
#endif
    }
   private:
    TT a;
  };

  
  STREAMS_BOOST_concept(CopyConstructible,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(CopyConstructible) {
      TT a(b);            // require copy constructor
      TT* ptr = &a;       // require address of operator
      const_constraints(a);
      ignore_unused_variable_warning(ptr);
    }
   private:
    void const_constraints(const TT& a) {
      TT c(a);            // require const copy constructor
      const TT* ptr = &a; // require const address of operator
      ignore_unused_variable_warning(c);
      ignore_unused_variable_warning(ptr);
    }
    TT b;
  };

#if (defined _MSC_VER)
# pragma warning( push )
# pragma warning( disable : 4510 ) // default constructor could not be generated
# pragma warning( disable : 4610 ) // object 'class' can never be instantiated - user-defined constructor required
#endif
  // The SGI STL version of Assignable requires copy constructor and operator=
  STREAMS_BOOST_concept(SGIAssignable,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(SGIAssignable) {
      TT b(a);
#if !defined(_ITERATOR_) // back_insert_iterator broken for VC++ STL
      a = a;              // require assignment operator
#endif
      const_constraints(a);
      ignore_unused_variable_warning(b);
    }
   private:
    void const_constraints(const TT& b) {
      TT c(b);
#if !defined(_ITERATOR_) // back_insert_iterator broken for VC++ STL
      a = b;              // const required for argument to assignment
#endif
      ignore_unused_variable_warning(c);
    }
    TT a;
  };
#if (defined _MSC_VER)
# pragma warning( pop )
#endif

  STREAMS_BOOST_concept(Convertible,(X)(Y))
  {
    STREAMS_BOOST_CONCEPT_USAGE(Convertible) {
      Y y = x;
      ignore_unused_variable_warning(y);
    }
   private:
    X x;
  };

  // The C++ standard requirements for many concepts talk about return
  // types that must be "convertible to bool".  The problem with this
  // requirement is that it leaves the door open for evil proxies that
  // define things like operator|| with strange return types.  Two
  // possible solutions are:
  // 1) require the return type to be exactly bool
  // 2) stay with convertible to bool, and also
  //    specify stuff about all the logical operators.
  // For now we just test for convertible to bool.
  template <class TT>
  void require_boolean_expr(const TT& t) {
    bool x = t;
    ignore_unused_variable_warning(x);
  }

  STREAMS_BOOST_concept(EqualityComparable,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(EqualityComparable) {
      require_boolean_expr(a == b);
      require_boolean_expr(a != b);
    }
   private:
    TT a, b;
  };

  STREAMS_BOOST_concept(LessThanComparable,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(LessThanComparable) {
      require_boolean_expr(a < b);
    }
   private:
    TT a, b;
  };

  // This is equivalent to SGI STL's LessThanComparable.
  STREAMS_BOOST_concept(Comparable,(TT))
  {
    STREAMS_BOOST_CONCEPT_USAGE(Comparable) {
      require_boolean_expr(a < b);
      require_boolean_expr(a > b);
      require_boolean_expr(a <= b);
      require_boolean_expr(a >= b);
    }
   private:
    TT a, b;
  };

#define STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(OP,NAME)    \
  STREAMS_BOOST_concept(NAME, (First)(Second))                          \
  {                                                             \
      STREAMS_BOOST_CONCEPT_USAGE(NAME) { (void)constraints_(); }                         \
     private:                                                   \
        bool constraints_() { return a OP b; }                  \
        First a;                                                \
        Second b;                                               \
  }

#define STREAMS_BOOST_DEFINE_BINARY_OPERATOR_CONSTRAINT(OP,NAME)    \
  STREAMS_BOOST_concept(NAME, (Ret)(First)(Second))                 \
  {                                                         \
      STREAMS_BOOST_CONCEPT_USAGE(NAME) { (void)constraints_(); }                     \
  private:                                                  \
      Ret constraints_() { return a OP b; }                 \
      First a;                                              \
      Second b;                                             \
  }

  STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(==, EqualOp);
  STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(!=, NotEqualOp);
  STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(<, LessThanOp);
  STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(<=, LessEqualOp);
  STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(>, GreaterThanOp);
  STREAMS_BOOST_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(>=, GreaterEqualOp);

  STREAMS_BOOST_DEFINE_BINARY_OPERATOR_CONSTRAINT(+, PlusOp);
  STREAMS_BOOST_DEFINE_BINARY_OPERATOR_CONSTRAINT(*, TimesOp);
  STREAMS_BOOST_DEFINE_BINARY_OPERATOR_CONSTRAINT(/, DivideOp);
  STREAMS_BOOST_DEFINE_BINARY_OPERATOR_CONSTRAINT(-, SubtractOp);
  STREAMS_BOOST_DEFINE_BINARY_OPERATOR_CONSTRAINT(%, ModOp);

  //===========================================================================
  // Function Object Concepts

  STREAMS_BOOST_concept(Generator,(Func)(Return))
  {
      STREAMS_BOOST_CONCEPT_USAGE(Generator) { test(is_void<Return>()); }
      
   private:
      void test(streams_boost::mpl::false_)
      {
          // Do we really want a reference here?
          const Return& r = f();
          ignore_unused_variable_warning(r);
      }

      void test(streams_boost::mpl::true_)
      {
          f();
      }
      
      Func f;
  };

  STREAMS_BOOST_concept(UnaryFunction,(Func)(Return)(Arg))
  {
      STREAMS_BOOST_CONCEPT_USAGE(UnaryFunction) { test(is_void<Return>()); }
      
   private:
      void test(streams_boost::mpl::false_)
      {
          f(arg);               // "priming the pump" this way keeps msvc6 happy (ICE)
          Return r = f(arg);
          ignore_unused_variable_warning(r); 
      }
      
      void test(streams_boost::mpl::true_)
      {
          f(arg);
      }
      
      Func f;
      Arg arg;
  };

  STREAMS_BOOST_concept(BinaryFunction,(Func)(Return)(First)(Second))
  {
      STREAMS_BOOST_CONCEPT_USAGE(BinaryFunction) { test(is_void<Return>()); }
   private:
      void test(streams_boost::mpl::false_)
      {
          f(first,second);
          Return r = f(first, second); // require operator()
          (void)r;
      }
      
      void test(streams_boost::mpl::true_)
      {
          f(first,second);
      }
      
      Func f;
      First first;
      Second second;
  };

  STREAMS_BOOST_concept(UnaryPredicate,(Func)(Arg))
  {
    STREAMS_BOOST_CONCEPT_USAGE(UnaryPredicate) {
      require_boolean_expr(f(arg)); // require operator() returning bool
    }
   private:
    Func f;
    Arg arg;
  };

  STREAMS_BOOST_concept(BinaryPredicate,(Func)(First)(Second))
  {
    STREAMS_BOOST_CONCEPT_USAGE(BinaryPredicate) {
      require_boolean_expr(f(a, b)); // require operator() returning bool
    }
   private:
    Func f;
    First a;
    Second b;
  };

  // use this when functor is used inside a container class like std::set
  STREAMS_BOOST_concept(Const_BinaryPredicate,(Func)(First)(Second))
    : BinaryPredicate<Func, First, Second>
  {
    STREAMS_BOOST_CONCEPT_USAGE(Const_BinaryPredicate) { 
      const_constraints(f);
    }
   private:
    void const_constraints(const Func& fun) {
      // operator() must be a const member function
      require_boolean_expr(fun(a, b));
    }
    Func f;
    First a;
    Second b;
  };

  STREAMS_BOOST_concept(AdaptableGenerator,(Func)(Return))
    : Generator<Func, typename Func::result_type>
  {
      typedef typename Func::result_type result_type;
      
      STREAMS_BOOST_CONCEPT_USAGE(AdaptableGenerator)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<result_type, Return>));
      }
  };

  STREAMS_BOOST_concept(AdaptableUnaryFunction,(Func)(Return)(Arg))
    : UnaryFunction<Func, typename Func::result_type, typename Func::argument_type>
  {
      typedef typename Func::argument_type argument_type;
      typedef typename Func::result_type result_type;

      ~AdaptableUnaryFunction()
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<result_type, Return>));
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<Arg, argument_type>));
      }
  };

  STREAMS_BOOST_concept(AdaptableBinaryFunction,(Func)(Return)(First)(Second))
    : BinaryFunction<
          Func
        , typename Func::result_type
        , typename Func::first_argument_type
        , typename Func::second_argument_type
      >
  {
      typedef typename Func::first_argument_type first_argument_type;
      typedef typename Func::second_argument_type second_argument_type;
      typedef typename Func::result_type result_type;
      
      ~AdaptableBinaryFunction()
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<result_type, Return>));
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<First, first_argument_type>));
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<Second, second_argument_type>));
      }
  };

  STREAMS_BOOST_concept(AdaptablePredicate,(Func)(Arg))
    : UnaryPredicate<Func, Arg>
    , AdaptableUnaryFunction<Func, bool, Arg>
  {
  };

  STREAMS_BOOST_concept(AdaptableBinaryPredicate,(Func)(First)(Second))
    : BinaryPredicate<Func, First, Second>
    , AdaptableBinaryFunction<Func, bool, First, Second>
  {
  };

  //===========================================================================
  // Iterator Concepts

  STREAMS_BOOST_concept(InputIterator,(TT))
    : Assignable<TT>
    , EqualityComparable<TT>
  {
      typedef typename streams_boost::detail::iterator_traits<TT>::value_type value_type;
      typedef typename streams_boost::detail::iterator_traits<TT>::difference_type difference_type;
      typedef typename streams_boost::detail::iterator_traits<TT>::reference reference;
      typedef typename streams_boost::detail::iterator_traits<TT>::pointer pointer;
      typedef typename streams_boost::detail::iterator_traits<TT>::iterator_category iterator_category;

      STREAMS_BOOST_CONCEPT_USAGE(InputIterator)
      {
        STREAMS_BOOST_CONCEPT_ASSERT((SignedInteger<difference_type>));
        STREAMS_BOOST_CONCEPT_ASSERT((Convertible<iterator_category, std::input_iterator_tag>));
        
        TT j(i);
        (void)*i;           // require dereference operator
        ++j;                // require preincrement operator
        i++;                // require postincrement operator
      }
   private:
    TT i;
  };

  STREAMS_BOOST_concept(OutputIterator,(TT)(ValueT))
    : Assignable<TT>
  {
    STREAMS_BOOST_CONCEPT_USAGE(OutputIterator) {
      
      ++i;                // require preincrement operator
      i++;                // require postincrement operator
      *i++ = t;           // require postincrement and assignment
    }
   private:
    TT i, j;
    ValueT t;
  };

  STREAMS_BOOST_concept(ForwardIterator,(TT))
    : InputIterator<TT>
  {
      STREAMS_BOOST_CONCEPT_USAGE(ForwardIterator)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<
              STREAMS_BOOST_DEDUCED_TYPENAME ForwardIterator::iterator_category
            , std::forward_iterator_tag
          >));
          
          typename InputIterator<TT>::reference r = *i;
          ignore_unused_variable_warning(r);
      }
      
   private:
      TT i;
  };

  STREAMS_BOOST_concept(Mutable_ForwardIterator,(TT))
    : ForwardIterator<TT>
  {
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_ForwardIterator) {
        *i++ = *i;         // require postincrement and assignment
      }
   private:
      TT i;
  };

  STREAMS_BOOST_concept(BidirectionalIterator,(TT))
    : ForwardIterator<TT>
  {
      STREAMS_BOOST_CONCEPT_USAGE(BidirectionalIterator)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<
              STREAMS_BOOST_DEDUCED_TYPENAME BidirectionalIterator::iterator_category
            , std::bidirectional_iterator_tag
          >));

          --i;                // require predecrement operator
          i--;                // require postdecrement operator
      }
   private:
      TT i;
  };

  STREAMS_BOOST_concept(Mutable_BidirectionalIterator,(TT))
    : BidirectionalIterator<TT>
    , Mutable_ForwardIterator<TT>
  {
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_BidirectionalIterator)
      {
          *i-- = *i;                  // require postdecrement and assignment
      }
   private:
      TT i;
  };

  STREAMS_BOOST_concept(RandomAccessIterator,(TT))
    : BidirectionalIterator<TT>
    , Comparable<TT>
  {
      STREAMS_BOOST_CONCEPT_USAGE(RandomAccessIterator)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Convertible<
              STREAMS_BOOST_DEDUCED_TYPENAME BidirectionalIterator<TT>::iterator_category
            , std::random_access_iterator_tag
          >));

          i += n;             // require assignment addition operator
          i = i + n; i = n + i; // require addition with difference type
          i -= n;             // require assignment subtraction operator
          i = i - n;                  // require subtraction with difference type
          n = i - j;                  // require difference operator
          (void)i[n];                 // require element access operator
      }
      
   private:
    TT a, b;
    TT i, j;
      typename streams_boost::detail::iterator_traits<TT>::difference_type n;
  };

  STREAMS_BOOST_concept(Mutable_RandomAccessIterator,(TT))
    : RandomAccessIterator<TT>
    , Mutable_BidirectionalIterator<TT>
  {
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_RandomAccessIterator)
      {
          i[n] = *i;                  // require element access and assignment
      }
   private:
    TT i;
    typename streams_boost::detail::iterator_traits<TT>::difference_type n;
  };

  //===========================================================================
  // Container s

  STREAMS_BOOST_concept(Container,(C))
    : Assignable<C>
  {
    typedef typename C::value_type value_type;
    typedef typename C::difference_type difference_type;
    typedef typename C::size_type size_type;
    typedef typename C::const_reference const_reference;
    typedef typename C::const_pointer const_pointer;
    typedef typename C::const_iterator const_iterator;

      STREAMS_BOOST_CONCEPT_USAGE(Container)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((InputIterator<const_iterator>));
          const_constraints(c);
      }
      
   private:
      void const_constraints(const C& cc) {
          i = cc.begin();
          i = cc.end();
          n = cc.size();
          n = cc.max_size();
          b = cc.empty();
      }
      C c;
      bool b;
      const_iterator i;
      size_type n;
  };

  STREAMS_BOOST_concept(Mutable_Container,(C))
    : Container<C>
  {
      typedef typename C::reference reference;
      typedef typename C::iterator iterator;
      typedef typename C::pointer pointer;
    
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_Container)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((
               Assignable<typename Mutable_Container::value_type>));
          
          STREAMS_BOOST_CONCEPT_ASSERT((InputIterator<iterator>));
          
          i = c.begin();
          i = c.end();
          c.swap(c2);
      }
      
   private:
      iterator i;
      C c, c2;
  };

  STREAMS_BOOST_concept(ForwardContainer,(C))
    : Container<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(ForwardContainer)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((
               ForwardIterator<
                    typename ForwardContainer::const_iterator
               >));
      }
  };  

  STREAMS_BOOST_concept(Mutable_ForwardContainer,(C))
    : ForwardContainer<C>
    , Mutable_Container<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_ForwardContainer)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((
               Mutable_ForwardIterator<
                   typename Mutable_ForwardContainer::iterator
               >));
      }
  };  

  STREAMS_BOOST_concept(ReversibleContainer,(C))
    : ForwardContainer<C>
  {
      typedef typename
        C::const_reverse_iterator
      const_reverse_iterator;

      STREAMS_BOOST_CONCEPT_USAGE(ReversibleContainer)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((
              BidirectionalIterator<
                  typename ReversibleContainer::const_iterator>));
          
          STREAMS_BOOST_CONCEPT_ASSERT((BidirectionalIterator<const_reverse_iterator>));
          
          const_constraints(c);
      }
   private:
      void const_constraints(const C& cc)
      {
          const_reverse_iterator i = cc.rbegin();
          i = cc.rend();
      }
      C c;
  };

  STREAMS_BOOST_concept(Mutable_ReversibleContainer,(C))
    : Mutable_ForwardContainer<C>
    , ReversibleContainer<C>
  {
      typedef typename C::reverse_iterator reverse_iterator;
      
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_ReversibleContainer)
      {
          typedef typename Mutable_ForwardContainer<C>::iterator iterator;
          STREAMS_BOOST_CONCEPT_ASSERT((Mutable_BidirectionalIterator<iterator>));
          STREAMS_BOOST_CONCEPT_ASSERT((Mutable_BidirectionalIterator<reverse_iterator>));
          
          reverse_iterator i = c.rbegin();
          i = c.rend();
      }
   private:  
      C c;
  };

  STREAMS_BOOST_concept(RandomAccessContainer,(C))
    : ReversibleContainer<C>
  {
      typedef typename C::size_type size_type;
      typedef typename C::const_reference const_reference;

      STREAMS_BOOST_CONCEPT_USAGE(RandomAccessContainer)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((
              RandomAccessIterator<
                  typename RandomAccessContainer::const_iterator
              >));
          
          const_constraints(c);
      }
   private:
      void const_constraints(const C& cc)
      {
          const_reference r = cc[n];
          ignore_unused_variable_warning(r);
      }
    
      C c;
      size_type n;
  };

  STREAMS_BOOST_concept(Mutable_RandomAccessContainer,(C))
    : Mutable_ReversibleContainer<C>
    , RandomAccessContainer<C>
  {
   private:
      typedef Mutable_RandomAccessContainer self;
   public:
      STREAMS_BOOST_CONCEPT_USAGE(Mutable_RandomAccessContainer)
      {
          STREAMS_BOOST_CONCEPT_ASSERT((Mutable_RandomAccessIterator<typename self::iterator>));
          STREAMS_BOOST_CONCEPT_ASSERT((Mutable_RandomAccessIterator<typename self::reverse_iterator>));
          
          typename self::reference r = c[i];
          ignore_unused_variable_warning(r);
      }
      
   private:
      typename Mutable_ReversibleContainer<C>::size_type i;
      C c;
  };

  // A Sequence is inherently mutable
  STREAMS_BOOST_concept(Sequence,(S))
    : Mutable_ForwardContainer<S>
      // Matt Austern's book puts DefaultConstructible here, the C++
      // standard places it in Container --JGS
      // ... so why aren't we following the standard?  --DWA
    , DefaultConstructible<S>
  {
      STREAMS_BOOST_CONCEPT_USAGE(Sequence)
      {
          S 
              c(n),
              c2(n, t),
              c3(first, last);

          c.insert(p, t);
          c.insert(p, n, t);
          c.insert(p, first, last);

          c.erase(p);
          c.erase(p, q);

          typename Sequence::reference r = c.front();

          ignore_unused_variable_warning(c);
          ignore_unused_variable_warning(c2);
          ignore_unused_variable_warning(c3);
          ignore_unused_variable_warning(r);
          const_constraints(c);
      }
   private:
      void const_constraints(const S& c) {
          typename Sequence::const_reference r = c.front();
          ignore_unused_variable_warning(r);
      }
    
      typename S::value_type t;
      typename S::size_type n;
      typename S::value_type* first, *last;
      typename S::iterator p, q;
  };

  STREAMS_BOOST_concept(FrontInsertionSequence,(S))
    : Sequence<S>
  {
      STREAMS_BOOST_CONCEPT_USAGE(FrontInsertionSequence)
      {
          c.push_front(t);
          c.pop_front();
      }
   private:
      S c;
      typename S::value_type t;
  };

  STREAMS_BOOST_concept(BackInsertionSequence,(S))
    : Sequence<S>
  {
      STREAMS_BOOST_CONCEPT_USAGE(BackInsertionSequence)
      {
          c.push_back(t);
          c.pop_back();
          typename BackInsertionSequence::reference r = c.back();
          ignore_unused_variable_warning(r);
          const_constraints(c);
      }
   private:
      void const_constraints(const S& cc) {
          typename BackInsertionSequence::const_reference
              r = cc.back();
          ignore_unused_variable_warning(r);
      };
      S c;
      typename S::value_type t;
  };

  STREAMS_BOOST_concept(AssociativeContainer,(C))
    : ForwardContainer<C>
    , DefaultConstructible<C>
  {
      typedef typename C::key_type key_type;
      typedef typename C::key_compare key_compare;
      typedef typename C::value_compare value_compare;
      typedef typename C::iterator iterator;

      STREAMS_BOOST_CONCEPT_USAGE(AssociativeContainer)
      {
          i = c.find(k);
          r = c.equal_range(k);
          c.erase(k);
          c.erase(i);
          c.erase(r.first, r.second);
          const_constraints(c);
          STREAMS_BOOST_CONCEPT_ASSERT((BinaryPredicate<key_compare,key_type,key_type>));
          
          typedef typename AssociativeContainer::value_type value_type_;
          STREAMS_BOOST_CONCEPT_ASSERT((BinaryPredicate<value_compare,value_type_,value_type_>));
      }
      
      // Redundant with the base concept, but it helps below.
      typedef typename C::const_iterator const_iterator;
   private:
      void const_constraints(const C& cc)
      {
          ci = cc.find(k);
          n = cc.count(k);
          cr = cc.equal_range(k);
      }

      C c;
      iterator i;
      std::pair<iterator,iterator> r;
      const_iterator ci;
      std::pair<const_iterator,const_iterator> cr;
      typename C::key_type k;
      typename C::size_type n;
  };

  STREAMS_BOOST_concept(UniqueAssociativeContainer,(C))
    : AssociativeContainer<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(UniqueAssociativeContainer)
      {
          C c(first, last);
      
          pos_flag = c.insert(t);
          c.insert(first, last);

          ignore_unused_variable_warning(c);
      }
   private:
      std::pair<typename C::iterator, bool> pos_flag;
      typename C::value_type t;
      typename C::value_type* first, *last;
  };

  STREAMS_BOOST_concept(MultipleAssociativeContainer,(C))
    : AssociativeContainer<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(MultipleAssociativeContainer)
      {
          C c(first, last);
      
          pos = c.insert(t);
          c.insert(first, last);

          ignore_unused_variable_warning(c);
          ignore_unused_variable_warning(pos);
      }
   private:
      typename C::iterator pos;
      typename C::value_type t;
      typename C::value_type* first, *last;
  };

  STREAMS_BOOST_concept(SimpleAssociativeContainer,(C))
    : AssociativeContainer<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(SimpleAssociativeContainer)
      {
          typedef typename C::key_type key_type;
          typedef typename C::value_type value_type;
          STREAMS_BOOST_MPL_ASSERT((streams_boost::is_same<key_type,value_type>));
      }
  };

  STREAMS_BOOST_concept(PairAssociativeContainer,(C))
    : AssociativeContainer<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(PairAssociativeContainer)
      {
          typedef typename C::key_type key_type;
          typedef typename C::value_type value_type;
          typedef typename C::mapped_type mapped_type;
          typedef std::pair<const key_type, mapped_type> required_value_type;
          STREAMS_BOOST_MPL_ASSERT((streams_boost::is_same<value_type,required_value_type>));
      }
  };

  STREAMS_BOOST_concept(SortedAssociativeContainer,(C))
    : AssociativeContainer<C>
    , ReversibleContainer<C>
  {
      STREAMS_BOOST_CONCEPT_USAGE(SortedAssociativeContainer)
      {
          C 
              c(kc),
              c2(first, last),
              c3(first, last, kc);

          p = c.upper_bound(k);
          p = c.lower_bound(k);
          r = c.equal_range(k);
      
          c.insert(p, t);
      
          ignore_unused_variable_warning(c);
          ignore_unused_variable_warning(c2);
          ignore_unused_variable_warning(c3);
          const_constraints(c);
      }
      
      void const_constraints(const C& c)
      {
          kc = c.key_comp();
          vc = c.value_comp();

          cp = c.upper_bound(k);
          cp = c.lower_bound(k);
          cr = c.equal_range(k);
      }
      
   private:
      typename C::key_compare kc;
      typename C::value_compare vc;
      typename C::value_type t;
      typename C::key_type k;
      typedef typename C::iterator iterator;
      typedef typename C::const_iterator const_iterator;

      typedef SortedAssociativeContainer self;
      iterator p;
      const_iterator cp;
      std::pair<typename self::iterator,typename self::iterator> r;
      std::pair<typename self::const_iterator,typename self::const_iterator> cr;
      typename C::value_type* first, *last;
  };

  // HashedAssociativeContainer

} // namespace streams_boost

# include <streams_boost/concept/detail/concept_undef.hpp>

#endif // STREAMS_BOOST_CONCEPT_CHECKS_HPP
