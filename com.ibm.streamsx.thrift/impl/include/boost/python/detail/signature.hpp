#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef SIGNATURE_DWA20021121_STREAMS_HPP
#  define SIGNATURE_DWA20021121_STREAMS_HPP

#  include <streams_boost/python/type_id.hpp>

#  include <streams_boost/python/detail/preprocessor.hpp>
#  include <streams_boost/python/detail/indirect_traits.hpp>
#  include <streams_boost/python/converter/pytype_function.hpp>

#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/iteration/local.hpp>

#  include <streams_boost/mpl/at.hpp>
#  include <streams_boost/mpl/size.hpp>

namespace streams_boost { namespace python { namespace detail { 

struct signature_element
{
    char const* basename;
    converter::pytype_function pytype_f;
    bool lvalue;
};

struct py_func_sig_info
{
    signature_element const *signature;
    signature_element const *ret;
};

template <unsigned> struct signature_arity;

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                            \
        (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY + 1, <streams_boost/python/detail/signature.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()

// A metafunction returning the base class used for
//
//   signature<class F, class CallPolicies, class Sig>.
//
template <class Sig>
struct signature_base_select
{
    enum { arity = mpl::size<Sig>::value - 1 };
    typedef typename signature_arity<arity>::template impl<Sig> type;
};

template <class Sig>
struct signature
    : signature_base_select<Sig>::type
{
};

}}} // namespace streams_boost::python::detail

# endif // SIGNATURE_DWA20021121_STREAMS_HPP

#else

# define N STREAMS_BOOST_PP_ITERATION()

template <>
struct signature_arity<N>
{
    template <class Sig>
    struct impl
    {
        static signature_element const* elements()
        {
            static signature_element const result[N+2] = {
                
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
# define STREAMS_BOOST_PP_LOCAL_MACRO(i)                                                            \
                {                                                                           \
                  type_id<STREAMS_BOOST_DEDUCED_TYPENAME mpl::at_c<Sig,i>::type>().name()           \
                  , &converter::expected_pytype_for_arg<STREAMS_BOOST_DEDUCED_TYPENAME mpl::at_c<Sig,i>::type>::get_pytype   \
                  , indirect_traits::is_reference_to_non_const<STREAMS_BOOST_DEDUCED_TYPENAME mpl::at_c<Sig,i>::type>::value \
                },
#else
# define STREAMS_BOOST_PP_LOCAL_MACRO(i)                                                            \
                {                                                                           \
                  type_id<STREAMS_BOOST_DEDUCED_TYPENAME mpl::at_c<Sig,i>::type>().name()           \
                  , 0 \
                  , indirect_traits::is_reference_to_non_const<STREAMS_BOOST_DEDUCED_TYPENAME mpl::at_c<Sig,i>::type>::value \
                },
#endif
                
# define STREAMS_BOOST_PP_LOCAL_LIMITS (0, N)
# include STREAMS_BOOST_PP_LOCAL_ITERATE()
                {0,0,0}
            };
            return result;
        }
    };
};

#endif // STREAMS_BOOST_PP_IS_ITERATING 


