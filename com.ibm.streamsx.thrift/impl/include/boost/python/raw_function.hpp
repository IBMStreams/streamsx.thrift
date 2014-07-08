// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef RAW_FUNCTION_DWA200336_STREAMS_HPP
# define RAW_FUNCTION_DWA200336_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/tuple.hpp>
# include <streams_boost/python/dict.hpp>
# include <streams_boost/python/object/py_function.hpp>
# include <streams_boost/mpl/vector/vector10.hpp>

# include <streams_boost/limits.hpp>
# include <cstddef>

namespace streams_boost { namespace python { 

namespace detail
{
  template <class F>
  struct raw_dispatcher
  {
      raw_dispatcher(F f) : f(f) {}
      
      PyObject* operator()(PyObject* args, PyObject* keywords)
      {
          return incref(
              object(
                  f(
                      tuple(borrowed_reference(args))
                    , keywords ? dict(borrowed_reference(keywords)) : dict()
                  )
              ).ptr()
          );
      }

   private:
      F f;
  };

  object STREAMS_BOOST_PYTHON_DECL make_raw_function(objects::py_function);
}

template <class F>
object raw_function(F f, std::size_t min_args = 0)
{
    return detail::make_raw_function(
        objects::py_function(
            detail::raw_dispatcher<F>(f)
          , mpl::vector1<PyObject*>()
          , min_args
          , (std::numeric_limits<unsigned>::max)()
        )
    );
}
    
}} // namespace streams_boost::python

#endif // RAW_FUNCTION_DWA200336_STREAMS_HPP
