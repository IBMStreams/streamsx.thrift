// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef TUPLE_20020706_HPP
#define TUPLE_20020706_HPP

# include <streams_boost/python/detail/prefix.hpp>

#include <streams_boost/python/object.hpp>
#include <streams_boost/python/converter/pytype_object_mgr_traits.hpp>
#include <streams_boost/preprocessor/enum_params.hpp>
#include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

namespace streams_boost { namespace python {

namespace detail
{
  struct STREAMS_BOOST_PYTHON_DECL tuple_base : object
  {
   protected:
      tuple_base();
      tuple_base(object_cref sequence);
      
      STREAMS_BOOST_PYTHON_FORWARD_OBJECT_CONSTRUCTORS(tuple_base, object)

   private:
      static detail::new_reference call(object const&);
  };
}

class tuple : public detail::tuple_base
{
    typedef detail::tuple_base base;
 public:
    tuple() {}

    template <class T>
    explicit tuple(T const& sequence)
        : base(object(sequence))
    {
    }

 public: // implementation detail -- for internal use only
    STREAMS_BOOST_PYTHON_FORWARD_OBJECT_CONSTRUCTORS(tuple, base)
};

//
// Converter Specializations    // $$$ JDG $$$ moved here to prevent
//                              // G++ bug complaining specialization
                                // provided after instantiation
namespace converter
{
  template <>
  struct object_manager_traits<tuple>
      : pytype_object_manager_traits<&PyTuple_Type,tuple>
  {
  };
}

// for completeness
inline tuple make_tuple() { return tuple(); }

# define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (1, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/detail/make_tuple.hpp>))
# include STREAMS_BOOST_PP_ITERATE()

}}  // namespace streams_boost::python

#endif

