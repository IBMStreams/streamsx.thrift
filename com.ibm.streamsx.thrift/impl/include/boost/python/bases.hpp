// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef BASES_DWA2002321_STREAMS_HPP
# define BASES_DWA2002321_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/type_traits/object_traits.hpp>
# include <streams_boost/python/detail/type_list.hpp>
# include <streams_boost/mpl/if.hpp>
# include <streams_boost/mpl/bool.hpp>
# include <streams_boost/preprocessor/enum_params_with_a_default.hpp>
# include <streams_boost/preprocessor/enum_params.hpp>

namespace streams_boost { namespace python { 

# define STREAMS_BOOST_PYTHON_BASE_PARAMS STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, STREAMS_BOOST_PYTHON_MAX_BASES, Base)

  // A type list for specifying bases
  template < STREAMS_BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(STREAMS_BOOST_PYTHON_MAX_BASES, typename Base, mpl::void_) >
  struct bases : detail::type_list< STREAMS_BOOST_PYTHON_BASE_PARAMS >::type
  {};

  namespace detail
  {
# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
    template <class T> struct specifies_bases
        : mpl::false_
    {
    };
    
    template < STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, STREAMS_BOOST_PYTHON_MAX_BASES, class Base) >
    struct specifies_bases< bases< STREAMS_BOOST_PYTHON_BASE_PARAMS > >
        : mpl::true_
    {
    };
# else
    template < STREAMS_BOOST_PP_ENUM_PARAMS(STREAMS_BOOST_PYTHON_MAX_BASES, class Base) >
    static char is_bases_helper(bases< STREAMS_BOOST_PYTHON_BASE_PARAMS > const&);
    
    static char (& is_bases_helper(...) )[256];

    template <class T>
    struct specifies_bases
    {
     private:
        static typename add_reference<T>::type make();
        STREAMS_BOOST_STATIC_CONSTANT(bool, non_ref = !is_reference<T>::value);
     public:
        STREAMS_BOOST_STATIC_CONSTANT(bool, value = non_ref & (sizeof(is_bases_helper(make())) == 1));
        typedef mpl::bool_<value> type;
    };
# endif
    template <class T, class Prev = bases<> >
    struct select_bases
        : mpl::if_<
                specifies_bases<T>
                , T
                , Prev
          >
    {
    };
  }
# undef STREAMS_BOOST_PYTHON_BASE_PARAMS
}} // namespace streams_boost::python

#endif // BASES_DWA2002321_STREAMS_HPP
