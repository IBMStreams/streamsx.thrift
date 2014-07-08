#if !defined(STREAMS_BOOST_PP_IS_ITERATING)

// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# ifndef CALLER_DWA20021121_STREAMS_HPP
#  define CALLER_DWA20021121_STREAMS_HPP

#  include <streams_boost/python/type_id.hpp>
#  include <streams_boost/python/handle.hpp>

#  include <streams_boost/detail/indirect_traits.hpp>

#  include <streams_boost/python/detail/invoke.hpp>
#  include <streams_boost/python/detail/signature.hpp>
#  include <streams_boost/python/detail/preprocessor.hpp>

#  include <streams_boost/python/arg_from_python.hpp>
#  include <streams_boost/python/converter/context_result_converter.hpp>
#  include <streams_boost/python/converter/builtin_converters.hpp>

#  include <streams_boost/preprocessor/iterate.hpp>
#  include <streams_boost/preprocessor/cat.hpp>
#  include <streams_boost/preprocessor/dec.hpp>
#  include <streams_boost/preprocessor/if.hpp>
#  include <streams_boost/preprocessor/iteration/local.hpp>
#  include <streams_boost/preprocessor/repetition/enum_trailing_params.hpp>
#  include <streams_boost/preprocessor/repetition/repeat.hpp>

#  include <streams_boost/compressed_pair.hpp>

#  include <streams_boost/type_traits/is_same.hpp>
#  include <streams_boost/type_traits/is_convertible.hpp>

#  include <streams_boost/mpl/apply.hpp>
#  include <streams_boost/mpl/eval_if.hpp>
#  include <streams_boost/mpl/identity.hpp>
#  include <streams_boost/mpl/size.hpp>
#  include <streams_boost/mpl/at.hpp>
#  include <streams_boost/mpl/int.hpp>
#  include <streams_boost/mpl/next.hpp>

namespace streams_boost { namespace python { namespace detail { 

template <int N>
inline PyObject* get(mpl::int_<N>, PyObject* const& args_)
{
    return PyTuple_GET_ITEM(args_,N);
}

inline unsigned arity(PyObject* const& args_)
{
    return PyTuple_GET_SIZE(args_);
}

// This "result converter" is really just used as
// a dispatch tag to invoke(...), selecting the appropriate
// implementation
typedef int void_result_to_python;

// Given a model of CallPolicies and a C++ result type, this
// metafunction selects the appropriate converter to use for
// converting the result to python.
template <class Policies, class Result>
struct select_result_converter
  : mpl::eval_if<
        is_same<Result,void>
      , mpl::identity<void_result_to_python>
      , mpl::apply1<typename Policies::result_converter,Result>
    >
{
};

template <class ArgPackage, class ResultConverter>
inline ResultConverter create_result_converter(
    ArgPackage const& args_
  , ResultConverter*
  , converter::context_result_converter*
)
{
    return ResultConverter(args_);
}
    
template <class ArgPackage, class ResultConverter>
inline ResultConverter create_result_converter(
    ArgPackage const&
  , ResultConverter*
  , ...
)
{
    return ResultConverter();
}

#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
template <class ResultConverter>
struct converter_target_type 
{
    static PyTypeObject const *get_pytype()
    {
        return create_result_converter((PyObject*)0, (ResultConverter *)0, (ResultConverter *)0).get_pytype();
    }
};

template < >
struct converter_target_type <void_result_to_python >
{
    static PyTypeObject const *get_pytype()
    {
        return 0;
    }
};
#endif

    
template <unsigned> struct caller_arity;

template <class F, class CallPolicies, class Sig>
struct caller;

#  define STREAMS_BOOST_PYTHON_NEXT(init,name,n)                                                        \
    typedef STREAMS_BOOST_PP_IF(n,typename mpl::next< STREAMS_BOOST_PP_CAT(name,STREAMS_BOOST_PP_DEC(n)) >::type, init) name##n;

#  define STREAMS_BOOST_PYTHON_ARG_CONVERTER(n)                                         \
     STREAMS_BOOST_PYTHON_NEXT(typename mpl::next<first>::type, arg_iter,n)             \
     typedef arg_from_python<STREAMS_BOOST_DEDUCED_TYPENAME arg_iter##n::type> c_t##n;  \
     c_t##n c##n(get(mpl::int_<n>(), inner_args));                              \
     if (!c##n.convertible())                                                   \
          return 0;

#  define STREAMS_BOOST_PP_ITERATION_PARAMS_1                                            \
        (3, (0, STREAMS_BOOST_PYTHON_MAX_ARITY + 1, <streams_boost/python/detail/caller.hpp>))
#  include STREAMS_BOOST_PP_ITERATE()

#  undef STREAMS_BOOST_PYTHON_ARG_CONVERTER
#  undef STREAMS_BOOST_PYTHON_NEXT

// A metafunction returning the base class used for caller<class F,
// class ConverterGenerators, class CallPolicies, class Sig>.
template <class F, class CallPolicies, class Sig>
struct caller_base_select
{
    enum { arity = mpl::size<Sig>::value - 1 };
    typedef typename caller_arity<arity>::template impl<F,CallPolicies,Sig> type;
};

// A function object type which wraps C++ objects as Python callable
// objects.
//
// Template Arguments:
//
//   F -
//      the C++ `function object' that will be called. Might
//      actually be any data for which an appropriate invoke_tag() can
//      be generated. invoke(...) takes care of the actual invocation syntax.
//
//   CallPolicies -
//      The precall, postcall, and what kind of resultconverter to
//      generate for mpl::front<Sig>::type
//
//   Sig -
//      The `intended signature' of the function. An MPL sequence
//      beginning with a result type and continuing with a list of
//      argument types.
template <class F, class CallPolicies, class Sig>
struct caller
    : caller_base_select<F,CallPolicies,Sig>::type
{
    typedef typename caller_base_select<
        F,CallPolicies,Sig
        >::type base;

    typedef PyObject* result_type;
    
    caller(F f, CallPolicies p) : base(f,p) {}

};

}}} // namespace streams_boost::python::detail

# endif // CALLER_DWA20021121_STREAMS_HPP

#else

# define N STREAMS_BOOST_PP_ITERATION()

template <>
struct caller_arity<N>
{
    template <class F, class Policies, class Sig>
    struct impl
    {
        impl(F f, Policies p) : m_data(f,p) {}

        PyObject* operator()(PyObject* args_, PyObject*) // eliminate
                                                         // this
                                                         // trailing
                                                         // keyword dict
        {
            typedef typename mpl::begin<Sig>::type first;
            typedef typename first::type result_t;
            typedef typename select_result_converter<Policies, result_t>::type result_converter;
            typedef typename Policies::argument_package argument_package;
            
            argument_package inner_args(args_);

# if N
#  define STREAMS_BOOST_PP_LOCAL_MACRO(i) STREAMS_BOOST_PYTHON_ARG_CONVERTER(i)
#  define STREAMS_BOOST_PP_LOCAL_LIMITS (0, N-1)
#  include STREAMS_BOOST_PP_LOCAL_ITERATE()
# endif 
            // all converters have been checked. Now we can do the
            // precall part of the policy
            if (!m_data.second().precall(inner_args))
                return 0;

            PyObject* result = detail::invoke(
                detail::invoke_tag<result_t,F>()
              , create_result_converter(args_, (result_converter*)0, (result_converter*)0)
              , m_data.first()
                STREAMS_BOOST_PP_ENUM_TRAILING_PARAMS(N, c)
            );
            
            return m_data.second().postcall(inner_args, result);
        }

        static unsigned min_arity() { return N; }
        
        static py_func_sig_info  signature()
        {
            const signature_element * sig = detail::signature<Sig>::elements();
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES

            typedef STREAMS_BOOST_DEDUCED_TYPENAME Policies::template extract_return_type<Sig>::type rtype;
            typedef typename select_result_converter<Policies, rtype>::type result_converter;

            static const signature_element ret = {
                (streams_boost::is_void<rtype>::value ? "void" : type_id<rtype>().name())
                , &detail::converter_target_type<result_converter>::get_pytype
                , streams_boost::detail::indirect_traits::is_reference_to_non_const<rtype>::value 
            };
            py_func_sig_info res = {sig, &ret };
#else
            py_func_sig_info res = {sig, sig };
#endif

            return  res;
        }
     private:
        compressed_pair<F,Policies> m_data;
    };
};



#endif // STREAMS_BOOST_PP_IS_ITERATING 


