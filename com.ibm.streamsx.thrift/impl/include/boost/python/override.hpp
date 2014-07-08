#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2004. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef OVERRIDE_DWA2004721_STREAMS_HPP
# define OVERRIDE_DWA2004721_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/converter/return_from_python.hpp>

# include <streams_boost/python/extract.hpp>
# include <streams_boost/python/handle.hpp>

#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/repeat.hpp>
#  include <streams_boost/preprocessor/debug/line.hpp>
#  include <streams_boost/preprocessor/repetition/enum_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#  include <streams_boost/type.hpp>

namespace streams_boost { namespace python {

class override;

namespace detail
{
  class wrapper_base;
  
  // The result of calling a method.
  class method_result
  {
   private:
      friend class streams_boost::python::override;
      explicit method_result(PyObject* x)
        : m_obj(x)
      {}

   public:
      template <class T>
      operator T()
      {
          converter::return_from_python<T> converter;
          return converter(m_obj.release());
      }

#  if STREAMS_BOOST_WORKAROUND(_MSC_FULL_VER, STREAMS_BOOST_TESTED_AT(140050215))
      template <class T>
      operator T*()
      {
          converter::return_from_python<T*> converter;
          return converter(m_obj.release());
      }
#  endif 
      
#  if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, STREAMS_BOOST_TESTED_AT(1400)) || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL_WIN, >= 900)
      // No operator T&
#  else
      
      template <class T>
      operator T&() const
      {
          converter::return_from_python<T&> converter;
          return converter(const_cast<handle<>&>(m_obj).release());
      }
#  endif 

      template <class T>
      T as(type<T>* = 0)
      {
          converter::return_from_python<T> converter;
          return converter(m_obj.release());
      }

      template <class T>
      T unchecked(type<T>* = 0)
      {
          return extract<T>(m_obj)();
      }
   private:
      mutable handle<> m_obj;
  };
}

class override : public object
{
 private:
    friend class detail::wrapper_base;
    override(handle<> x)
      : object(x)
    {}
    
 public:
    detail::method_result
    operator()() const
    {
        detail::method_result x(
            PyEval_CallFunction(
                this->ptr()
              , const_cast<char*>("()")
            ));
        return x;
    }

# define STREAMS_BOOST_PYTHON_fast_arg_to_python_get(z, n, _)   \
    , converter::arg_to_python<A##n>(a##n).get()

# define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (1, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/override.hpp>))
# include STREAMS_BOOST_PP_ITERATE()

# undef STREAMS_BOOST_PYTHON_fast_arg_to_python_get
};

}} // namespace streams_boost::python

#endif // OVERRIDE_DWA2004721_STREAMS_HPP

#else
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, override.hpp)
# endif 

# define N STREAMS_BOOST_PP_ITERATION()

template <
    STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, class A)
    >
detail::method_result
operator()( STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, A, const& a) ) const
{
    detail::method_result x(
        PyEval_CallFunction(
            this->ptr()
          , const_cast<char*>("(" STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_FIXED, "O") ")")
            STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_fast_arg_to_python_get, nil)
        ));
    return x;
}

# undef N
#endif 
