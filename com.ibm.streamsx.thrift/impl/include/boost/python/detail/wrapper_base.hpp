// Copyright David Abrahams 2004. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef WRAPPER_BASE_DWA2004722_STREAMS_HPP
# define WRAPPER_BASE_DWA2004722_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/type_traits/is_polymorphic.hpp>
# include <streams_boost/mpl/bool.hpp>

namespace streams_boost { namespace python {

class override;

namespace detail
{
  class STREAMS_BOOST_PYTHON_DECL_FORWARD wrapper_base;
  
  namespace wrapper_base_ // ADL disabler
  {
    inline PyObject* get_owner(wrapper_base const volatile& w);

    inline PyObject*
    owner_impl(void const volatile* /*x*/, mpl::false_)
    {
        return 0;
    }
    
    template <class T>
    inline PyObject*
    owner_impl(T const volatile* x, mpl::true_);
    
    template <class T>
    inline PyObject*
    owner(T const volatile* x)
    {
        return wrapper_base_::owner_impl(x,is_polymorphic<T>());
    }
  }
  
  class STREAMS_BOOST_PYTHON_DECL wrapper_base
  {
      friend void initialize_wrapper(PyObject* self, wrapper_base* w);
      friend PyObject* wrapper_base_::get_owner(wrapper_base const volatile& w);
   protected:
      wrapper_base() : m_self(0) {}
          
      override get_override(
          char const* name, PyTypeObject* class_object) const;

   private:
      void detach();
      
   private:
      PyObject* m_self;
  };

  namespace wrapper_base_ // ADL disabler
  {
    template <class T>
    inline PyObject*
    owner_impl(T const volatile* x, mpl::true_)
    {
        if (wrapper_base const volatile* w = dynamic_cast<wrapper_base const volatile*>(x))
        {
            return wrapper_base_::get_owner(*w);
        }
        return 0;
    }
    
    inline PyObject* get_owner(wrapper_base const volatile& w)
    {
        return w.m_self;
    }
  }
  
  inline void initialize_wrapper(PyObject* self, wrapper_base* w)
  {
      w->m_self = self;
  }

  inline void initialize_wrapper(PyObject* /*self*/, ...) {}

  
  
} // namespace detail

}} // namespace streams_boost::python

#endif // WRAPPER_BASE_DWA2004722_STREAMS_HPP
