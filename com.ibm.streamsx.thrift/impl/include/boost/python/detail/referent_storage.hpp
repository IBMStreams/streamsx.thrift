// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef REFERENT_STORAGE_DWA200278_STREAMS_HPP
# define REFERENT_STORAGE_DWA200278_STREAMS_HPP
# include <streams_boost/mpl/if.hpp>
# include <cstddef>

namespace streams_boost { namespace python { namespace detail {

struct alignment_dummy;
typedef void (*function_ptr)();
typedef int (alignment_dummy::*member_ptr);
typedef int (alignment_dummy::*member_function_ptr)();

# define STREAMS_BOOST_PYTHON_ALIGNER(T, n)                     \
        typename mpl::if_c<                             \
           sizeof(T) <= size, T, char>::type t##n

// Storage for size bytes, aligned to all fundamental types no larger than size
template <std::size_t size>
union aligned_storage
{
    STREAMS_BOOST_PYTHON_ALIGNER(char, 0);
    STREAMS_BOOST_PYTHON_ALIGNER(short, 1);
    STREAMS_BOOST_PYTHON_ALIGNER(int, 2);
    STREAMS_BOOST_PYTHON_ALIGNER(long, 3);
    STREAMS_BOOST_PYTHON_ALIGNER(float, 4);
    STREAMS_BOOST_PYTHON_ALIGNER(double, 5);
    STREAMS_BOOST_PYTHON_ALIGNER(long double, 6);
    STREAMS_BOOST_PYTHON_ALIGNER(void*, 7);
    STREAMS_BOOST_PYTHON_ALIGNER(function_ptr, 8);
    STREAMS_BOOST_PYTHON_ALIGNER(member_ptr, 9);
    STREAMS_BOOST_PYTHON_ALIGNER(member_function_ptr, 10);
    char bytes[size];
};

# undef STREAMS_BOOST_PYTHON_ALIGNER

  // Compute the size of T's referent. We wouldn't need this at all,
  // but sizeof() is broken in CodeWarriors <= 8.0
  template <class T> struct referent_size;
  
# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
  
  template <class T>
  struct referent_size<T&>
  {
      STREAMS_BOOST_STATIC_CONSTANT(
          std::size_t, value = sizeof(T));
  };

# else

  template <class T> struct referent_size
  {
      static T f();
      STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = sizeof(f()));
  };
  
# endif

// A metafunction returning a POD type which can store U, where T ==
// U&. If T is not a reference type, returns a POD which can store T.
template <class T>
struct referent_storage
{
    typedef aligned_storage<
        ::streams_boost::python::detail::referent_size<T>::value
    > type;
};

}}} // namespace streams_boost::python::detail

#endif // REFERENT_STORAGE_DWA200278_STREAMS_HPP
