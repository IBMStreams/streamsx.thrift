// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef KEYWORDS_DWA2002323_STREAMS_HPP
# define KEYWORDS_DWA2002323_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/args_fwd.hpp>
# include <streams_boost/config.hpp>
# include <streams_boost/python/detail/preprocessor.hpp>
# include <streams_boost/python/detail/type_list.hpp>

# include <streams_boost/type_traits/is_reference.hpp>
# include <streams_boost/type_traits/remove_reference.hpp>
# include <streams_boost/type_traits/remove_cv.hpp>

# include <streams_boost/preprocessor/enum_params.hpp>
# include <streams_boost/preprocessor/repeat.hpp>
# include <streams_boost/preprocessor/facilities/intercept.hpp>
# include <streams_boost/preprocessor/iteration/local.hpp>

# include <streams_boost/python/detail/mpl_lambda.hpp>
# include <streams_boost/python/object_core.hpp>

# include <streams_boost/mpl/bool.hpp>

# include <cstddef>
# include <algorithm>

namespace streams_boost { namespace python {

typedef detail::keywords<1> arg;
typedef arg arg_; // gcc 2.96 workaround

namespace detail
{
  template <std::size_t nkeywords>
  struct keywords_base
  {
      STREAMS_BOOST_STATIC_CONSTANT(std::size_t, size = nkeywords);
      
      keyword_range range() const
      {
          return keyword_range(elements, elements + nkeywords);
      }

      keyword elements[nkeywords];

      keywords<nkeywords+1>
      operator,(python::arg const &k) const;

      keywords<nkeywords + 1>
      operator,(char const *name) const;
  };
  
  template <std::size_t nkeywords>
  struct keywords : keywords_base<nkeywords>
  {
  };

  template <>
  struct keywords<1> : keywords_base<1>
  {
      explicit keywords(char const *name)
      {
          elements[0].name = name;
      }
    
      template <class T>
      python::arg& operator=(T const& value)
      {
          object z(value);
          elements[0].default_value = handle<>(python::borrowed(object(value).ptr()));
          return *this;
      }
    
      operator detail::keyword const&() const
      {
          return elements[0];
      }
  };

  template <std::size_t nkeywords>
  inline
  keywords<nkeywords+1>
  keywords_base<nkeywords>::operator,(python::arg const &k) const
  {
      keywords<nkeywords> const& l = *static_cast<keywords<nkeywords> const*>(this);
      python::detail::keywords<nkeywords+1> res;
      std::copy(l.elements, l.elements+nkeywords, res.elements);
      res.elements[nkeywords] = k.elements[0];
      return res;
  }

  template <std::size_t nkeywords>
  inline
  keywords<nkeywords + 1>
  keywords_base<nkeywords>::operator,(char const *name) const
  {
      return this->operator,(python::arg(name));
  }

# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
  template<typename T>
  struct is_keywords
  {
      STREAMS_BOOST_STATIC_CONSTANT(bool, value = false); 
  };

  template<std::size_t nkeywords>
  struct is_keywords<keywords<nkeywords> >
  {
      STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
  };
  template <class T>
  struct is_reference_to_keywords
  {
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_ref = is_reference<T>::value);
      typedef typename remove_reference<T>::type deref;
      typedef typename remove_cv<deref>::type key_t;
      STREAMS_BOOST_STATIC_CONSTANT(bool, is_key = is_keywords<key_t>::value);
      STREAMS_BOOST_STATIC_CONSTANT(bool, value = (is_ref & is_key));
      
      typedef mpl::bool_<value> type;
      STREAMS_BOOST_PYTHON_MPL_LAMBDA_SUPPORT(1,is_reference_to_keywords,(T))
  };
# else 
  typedef char (&yes_keywords_t)[1];
  typedef char (&no_keywords_t)[2];
      
  no_keywords_t is_keywords_test(...);

  template<std::size_t nkeywords>
  yes_keywords_t is_keywords_test(void (*)(keywords<nkeywords>&));

  template<std::size_t nkeywords>
  yes_keywords_t is_keywords_test(void (*)(keywords<nkeywords> const&));

  template<typename T>
  class is_reference_to_keywords
  {
   public:
      STREAMS_BOOST_STATIC_CONSTANT(
          bool, value = (
              sizeof(detail::is_keywords_test( (void (*)(T))0 ))
              == sizeof(detail::yes_keywords_t)));

      typedef mpl::bool_<value> type;
      STREAMS_BOOST_PYTHON_MPL_LAMBDA_SUPPORT(1,is_reference_to_keywords,(T))
  };
# endif 
}

inline detail::keywords<1> args(char const* name)
{ 
    return detail::keywords<1>(name);
}

#  define STREAMS_BOOST_PYTHON_ASSIGN_NAME(z, n, _) result.elements[n].name = name##n;
#  define STREAMS_BOOST_PP_LOCAL_MACRO(n)                                               \
inline detail::keywords<n> args(STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, n, char const* name)) \
{                                                                               \
    detail::keywords<n> result;                                                 \
    STREAMS_BOOST_PP_REPEAT_1(n, STREAMS_BOOST_PYTHON_ASSIGN_NAME, _)                           \
    return result;                                                              \
}
#  define STREAMS_BOOST_PP_LOCAL_LIMITS (2, STREAMS_BOOST_PYTHON_MAX_ARITY)
#  include STREAMS_BOOST_PP_LOCAL_ITERATE()

}} // namespace streams_boost::python


# endif // KEYWORDS_DWA2002323_STREAMS_HPP
