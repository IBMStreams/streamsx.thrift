// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef NULLARY_FUNCTION_ADAPTOR_DWA2003824_STREAMS_HPP
# define NULLARY_FUNCTION_ADAPTOR_DWA2003824_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>
# include <streams_boost/preprocessor/iteration/local.hpp>
# include <streams_boost/preprocessor/facilities/intercept.hpp>
# include <streams_boost/preprocessor/repetition/enum_params.hpp>
# include <streams_boost/preprocessor/repetition/enum_binary_params.hpp>

namespace streams_boost { namespace python { namespace detail { 

// nullary_function_adaptor -- a class template which ignores its
// arguments and calls a nullary function instead.  Used for building
// error-reporting functions, c.f. pure_virtual
template <class NullaryFunction>
struct nullary_function_adaptor
{
    nullary_function_adaptor(NullaryFunction fn)
      : m_fn(fn)
    {}

    void operator()() const { m_fn(); }

# define STREAMS_BOOST_PP_LOCAL_MACRO(i)                                            \
    template <STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, i, class A)>                        \
    void operator()(                                                        \
        STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, i, A, const& STREAMS_BOOST_PP_INTERCEPT)   \
    ) const                                                                 \
    {                                                                       \
        m_fn();                                                             \
    }

# define STREAMS_BOOST_PP_LOCAL_LIMITS (1, STREAMS_BOOST_PYTHON_MAX_ARITY)
# include STREAMS_BOOST_PP_LOCAL_ITERATE()
    
 private:
    NullaryFunction m_fn;
};

}}} // namespace streams_boost::python::detail

#endif // NULLARY_FUNCTION_ADAPTOR_DWA2003824_STREAMS_HPP
