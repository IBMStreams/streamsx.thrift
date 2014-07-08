#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef MAKE_HOLDER_DWA20011215_STREAMS_HPP
#  define MAKE_HOLDER_DWA20011215_STREAMS_HPP

#  include <streams_boost/python/detail/prefix.hpp>

#  include <streams_boost/python/object/instance.hpp>
#  include <streams_boost/python/converter/registry.hpp>
#if !defined( STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES) && defined( STREAMS_BOOST_PYTHON_PY_SYGNATURES_PROPER_INIT_SELF_TYPE)
#  include <streams_boost/python/detail/python_type.hpp>
#endif

#  include <streams_boost/python/object/forward.hpp>
#  include <streams_boost/python/detail/preprocessor.hpp>

#  include <streams_boost/mpl/next.hpp>
#  include <streams_boost/mpl/begin_end.hpp>
#  include <streams_boost/mpl/deref.hpp>

#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/iteration/local.hpp>
#  include <streams_boost/preprocessor/repeat.hpp>
#  include <streams_boost/preprocessor/debug/line.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_binary_params.hpp>

#  include <cstddef>

namespace streams_boost { namespace python { namespace objects {

template <int nargs> struct make_holder;

#  define STREAMS_BOOST_PYTHON_DO_FORWARD_ARG(z, index, _) , f##index(a##index)

// specializations...
#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY, <streams_boost/python/object/make_holder.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()

#  undef STREAMS_BOOST_PYTHON_DO_FORWARD_ARG

}}} // namespace streams_boost::python::objects

# endif // MAKE_HOLDER_DWA20011215_STREAMS_HPP

// For gcc 4.4 compatability, we must include the
// STREAMS_BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // STREAMS_BOOST_PP_IS_ITERATING
#if STREAMS_BOOST_PP_ITERATION_DEPTH() == 1
# if !(STREAMS_BOOST_WORKAROUND(__MWERKS__, > 0x3100)                      \
        && STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3201)))
#  line STREAMS_BOOST_PP_LINE(__LINE__, make_holder.hpp)
# endif 

# define N STREAMS_BOOST_PP_ITERATION()

template <>
struct make_holder<N>
{
    template <class Holder, class ArgList>
    struct apply
    {
# if N
        // Unrolled iteration through each argument type in ArgList,
        // choosing the type that will be forwarded on to the holder's
        // templated constructor.
        typedef typename mpl::begin<ArgList>::type iter0;
        
#  define STREAMS_BOOST_PP_LOCAL_MACRO(n)               \
    typedef typename mpl::deref<iter##n>::type t##n;        \
    typedef typename forward<t##n>::type f##n;  \
    typedef typename mpl::next<iter##n>::type   \
        STREAMS_BOOST_PP_CAT(iter,STREAMS_BOOST_PP_INC(n)); // Next iterator type
        
#  define STREAMS_BOOST_PP_LOCAL_LIMITS (0, N-1)
#  include STREAMS_BOOST_PP_LOCAL_ITERATE()
# endif 
        
        static void execute(
#if !defined( STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES) && defined( STREAMS_BOOST_PYTHON_PY_SYGNATURES_PROPER_INIT_SELF_TYPE)
            streams_boost::python::detail::python_class<STREAMS_BOOST_DEDUCED_TYPENAME Holder::value_type> *p
#else
            PyObject *p
#endif
            STREAMS_BOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(1, N, t, a))
        {
            typedef instance<Holder> instance_t;
            
            void* memory = Holder::allocate(p, offsetof(instance_t, storage), sizeof(Holder));
            try {
                (new (memory) Holder(
                    p STREAMS_BOOST_PP_REPEAT_1ST(N, STREAMS_BOOST_PYTHON_DO_FORWARD_ARG, nil)))->install(p);
            }
            catch(...) {
                Holder::deallocate(p, memory);
                throw;
            }
        }
    };
};

# undef N

#endif // STREAMS_BOOST_PP_ITERATION_DEPTH()
#endif
