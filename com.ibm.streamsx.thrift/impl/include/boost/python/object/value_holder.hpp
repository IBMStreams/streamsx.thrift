#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef VALUE_HOLDER_DWA20011215_STREAMS_HPP
#  define VALUE_HOLDER_DWA20011215_STREAMS_HPP 

#  include <streams_boost/python/object/value_holder_fwd.hpp>

#  include <streams_boost/python/instance_holder.hpp>
#  include <streams_boost/python/type_id.hpp>
#  include <streams_boost/python/wrapper.hpp>

#  include <streams_boost/python/object/inheritance_query.hpp>
#  include <streams_boost/python/object/forward.hpp>

#  include <streams_boost/python/detail/force_instantiate.hpp>
#  include <streams_boost/python/detail/preprocessor.hpp>

#  include <streams_boost/preprocessor/comma_if.hpp>
#  include <streams_boost/preprocessor/enum_params.hpp>
#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/repeat.hpp>
#  include <streams_boost/preprocessor/debug/line.hpp>

#  include <streams_boost/preprocessor/repetition/enum_params.hpp>
#  include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

#  include <streams_boost/utility/addressof.hpp>

namespace streams_boost { namespace python { namespace objects { 

#  if STREAMS_BOOST_WORKAROUND(__GNUC__, == 2)
#   define STREAMS_BOOST_PYTHON_UNFORWARD_LOCAL(z, n, _) STREAMS_BOOST_PP_COMMA_IF(n) (typename unforward<A##n>::type)objects::do_unforward(a##n,0)
#  else
#   define STREAMS_BOOST_PYTHON_UNFORWARD_LOCAL(z, n, _) STREAMS_BOOST_PP_COMMA_IF(n) objects::do_unforward(a##n,0)
#  endif 

template <class Value>
struct value_holder : instance_holder
{
    typedef Value held_type;
    typedef Value value_type;

    // Forward construction to the held object
#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (4, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/object/value_holder.hpp>, 1))
#  include STREAMS_BOOST_PP_ITERATE()

 private: // required holder implementation
    void* holds(type_info, bool null_ptr_only);
    
    template <class T>
    inline void* holds_wrapped(type_info dst_t, wrapper<T>*,T* p)
    {
        return python::type_id<T>() == dst_t ? p : 0;
    }
    
    inline void* holds_wrapped(type_info, ...)
    {
        return 0;
    }
 private: // data members
    Value m_held;
};

template <class Value, class Held>
struct value_holder_back_reference : instance_holder
{
    typedef Held held_type;
    typedef Value value_type;
    
    // Forward construction to the held object
#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (4, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/object/value_holder.hpp>, 2))
#  include STREAMS_BOOST_PP_ITERATE()

private: // required holder implementation
    void* holds(type_info, bool null_ptr_only);

 private: // data members
    Held m_held;
};

#  undef STREAMS_BOOST_PYTHON_UNFORWARD_LOCAL

template <class Value>
void* value_holder<Value>::holds(type_info dst_t, bool /*null_ptr_only*/)
{
    if (void* wrapped = holds_wrapped(dst_t, streams_boost::addressof(m_held), streams_boost::addressof(m_held)))
        return wrapped;
    
    type_info src_t = python::type_id<Value>();
    return src_t == dst_t ? streams_boost::addressof(m_held)
        : find_static_type(streams_boost::addressof(m_held), src_t, dst_t);
}

template <class Value, class Held>
void* value_holder_back_reference<Value,Held>::holds(
    type_info dst_t, bool /*null_ptr_only*/)
{
    type_info src_t = python::type_id<Value>();
    Value* x = &m_held;
    
    if (dst_t == src_t)
        return x;
    else if (dst_t == python::type_id<Held>())
        return &m_held;
    else
        return find_static_type(x, src_t, dst_t);
}

}}} // namespace streams_boost::python::objects

# endif // VALUE_HOLDER_DWA20011215_STREAMS_HPP

// --------------- value_holder ---------------

// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 && STREAMS_BOOST_PP_ITERATION_FLAGS() == 1
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, value_holder.hpp(value_holder))
# endif

# define N STREAMS_BOOST_PP_ITERATION()

# if (N != 0)
    template <STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, class A)>
# endif
    value_holder(
      PyObject* self STREAMS_BOOST_PP_COMMA_IF(N) STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, A, a))
        : m_held(
            STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_UNFORWARD_LOCAL, nil)
            )
    {
        python::detail::initialize_wrapper(self, streams_boost::addressof(this->m_held));
    }

# undef N

// --------------- value_holder_back_reference ---------------

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 1 && STREAMS_BOOST_PP_ITERATION_FLAGS() == 2
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, value_holder.hpp(value_holder_back_reference))
# endif

# define N STREAMS_BOOST_PP_ITERATION()

# if (N != 0)
    template <STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, class A)>
# endif
    value_holder_back_reference(
        PyObject* p STREAMS_BOOST_PP_COMMA_IF(N) STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, A, a))
        : m_held(
            p STREAMS_BOOST_PP_COMMA_IF(N)
            STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_UNFORWARD_LOCAL, nil)
            )
    {
    }

# undef N

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif
