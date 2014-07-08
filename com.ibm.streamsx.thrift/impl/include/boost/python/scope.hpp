// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef SCOPE_DWA2002724_STREAMS_HPP
# define SCOPE_DWA2002724_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/python/object.hpp>
# include <streams_boost/python/refcount.hpp>
# include <streams_boost/utility.hpp>

namespace streams_boost { namespace python { 

namespace detail
{
  // Making this a namespace-scope variable to avoid Cygwin issues.
  // Use a PyObject* to avoid problems with static destruction after Py_Finalize
  extern STREAMS_BOOST_PYTHON_DECL PyObject* current_scope;
}

class scope
  : public object
{
 public:
    inline scope(scope const&);
    inline scope(object const&);
    inline scope();
    inline ~scope();
    
 private: // data members
    PyObject* m_previous_scope;

 private: // unimplemented functions
    void operator=(scope const&);
};

inline scope::scope(object const& new_scope)
    : object(new_scope)
    , m_previous_scope(detail::current_scope)
{
    detail::current_scope = python::incref(new_scope.ptr());
}

inline scope::scope()
    : object(detail::borrowed_reference(
                 detail::current_scope ? detail::current_scope : Py_None
                 ))
    , m_previous_scope(python::xincref(detail::current_scope))
{
}

inline scope::~scope()
{
    python::xdecref(detail::current_scope);
    detail::current_scope = m_previous_scope;
}

namespace converter
{
  template <>
  struct object_manager_traits<scope>
      : object_manager_traits<object>
  {
  };
}

// Placing this after the specialization above suppresses a CWPro8.3 bug
inline scope::scope(scope const& new_scope)
    : object(new_scope)
    , m_previous_scope(detail::current_scope)
{
    detail::current_scope = python::incref(new_scope.ptr());
}

}} // namespace streams_boost::python

#endif // SCOPE_DWA2002724_STREAMS_HPP
