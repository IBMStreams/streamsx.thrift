// Copyright David Abrahams 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef FORWARD_DWA20011215_STREAMS_HPP
# define FORWARD_DWA20011215_STREAMS_HPP

# include <streams_boost/mpl/if.hpp>
# include <streams_boost/type_traits/is_scalar.hpp>
# include <streams_boost/type_traits/add_const.hpp>
# include <streams_boost/type_traits/add_reference.hpp>
# include <streams_boost/ref.hpp>
# include <streams_boost/python/detail/value_arg.hpp>
# include <streams_boost/python/detail/copy_ctor_mutates_rhs.hpp>
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#  include <streams_boost/type_traits/is_enum.hpp>
#  include <streams_boost/mpl/and.hpp>
#  include <streams_boost/mpl/not.hpp>
# else
#  include <streams_boost/mpl/or.hpp>
# endif 

namespace streams_boost { namespace python { namespace objects { 

// Very much like streams_boost::reference_wrapper<T>, except that in this
// case T can be a reference already without causing a
// reference-to-reference error.
template <class T>
struct reference_to_value
{
    typedef typename add_reference<typename add_const<T>::type>::type reference;
    
    reference_to_value(reference x) : m_value(x) {}
    reference get() const { return m_value; }
 private:
    reference m_value;
};

// A little metaprogram which selects the type to pass through an
// intermediate forwarding function when the destination argument type
// is T.
template <class T>
struct forward
    : mpl::if_<
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
          // vc6 chokes on unforwarding enums nested in classes
          mpl::and_<
              is_scalar<T>
            , mpl::not_< 
                  is_enum<T>
              >
          >
# else 
          mpl::or_<python::detail::copy_ctor_mutates_rhs<T>, is_scalar<T> >
# endif 
        , T
        , reference_to_value<T>
      >
{
};

# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template<typename T>
struct unforward
{
    typedef typename unwrap_reference<T>::type& type;
};

template<typename T>
struct unforward<reference_to_value<T> >
{
    typedef T type;
};

template <typename T>
struct unforward_cref
  : python::detail::value_arg<
        typename unwrap_reference<T>::type
    >
{
};

template<typename T>
struct unforward_cref<reference_to_value<T> >
  : add_reference<typename add_const<T>::type>
{
};

# else // no partial specialization

namespace detail
{
  typedef char (&yes_reference_to_value_t)[1];
  typedef char (&no_reference_to_value_t)[2];
      
  no_reference_to_value_t is_reference_to_value_test(...);

  template<typename T>
  yes_reference_to_value_t is_reference_to_value_test(streams_boost::type< reference_to_value<T> >);

  template<bool wrapped>
  struct unforwarder
  {
      template <class T>
      struct apply
      {
          typedef typename unwrap_reference<T>::type& type;
      };
  };

  template<>
  struct unforwarder<true>
  {
      template <class T>
      struct apply
      {
          typedef typename T::reference type;
      };
  };

  template<bool wrapped = false>
  struct cref_unforwarder
  {
      template <class T>
      struct apply
        : python::detail::value_arg<
              typename unwrap_reference<T>::type
          >
      {          
      };
  };
      
  template<>
  struct cref_unforwarder<true>
  {
      template <class T>
      struct apply
        : python::detail::value_arg<
              typename T::reference
          >
      {
      };
  };

  template<typename T>
  struct is_reference_to_value
  {
      STREAMS_BOOST_STATIC_CONSTANT(
          bool, value = (
              sizeof(is_reference_to_value_test(streams_boost::type<T>()))
              == sizeof(yes_reference_to_value_t)));
      typedef mpl::bool_<value> type;
  };
}

template <typename T>
struct unforward
    : public detail::unforwarder<
        detail::is_reference_to_value<T>::value
      >::template apply<T>
{};

template <typename T>
struct unforward_cref
    : public detail::cref_unforwarder<
        detail::is_reference_to_value<T>::value
      >::template apply<T>
{};

# endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template <class T>
typename reference_to_value<T>::reference
do_unforward(reference_to_value<T> const& x, int)
{
    return x.get();
}

template <class T>
typename reference_wrapper<T>::type&
do_unforward(reference_wrapper<T> const& x, int)
{
    return x.get();
}

template <class T>
T const& do_unforward(T const& x, ...)
{
    return x;
}

}}} // namespace streams_boost::python::objects

#endif // FORWARD_DWA20011215_STREAMS_HPP
