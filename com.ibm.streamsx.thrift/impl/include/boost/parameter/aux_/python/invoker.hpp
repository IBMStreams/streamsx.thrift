// Copyright Daniel Wallin 2005. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_INVOKER_051210_HPP
# define STREAMS_BOOST_PARAMETER_INVOKER_051210_HPP

# include <streams_boost/mpl/begin.hpp>
# include <streams_boost/mpl/next.hpp>
# include <streams_boost/mpl/deref.hpp>
# include <streams_boost/mpl/size.hpp>
# include <streams_boost/parameter/keyword.hpp>
# include <streams_boost/preprocessor/iteration/iterate.hpp>

namespace streams_boost { namespace parameter { namespace python { namespace aux {

template <long Arity, class M, class R, class Args>
struct invoker;

template <class M, class R>
struct make_invoker
{
    template <class Args>
    struct apply
    {
        typedef invoker<
            mpl::size<Args>::value, M, R, Args
        > type;
    };
};

template <long Arity, class M, class R, class T, class Args>
struct member_invoker;

template <class M, class R, class T>
struct make_member_invoker
{
    template <class Args>
    struct apply
    {
        typedef member_invoker<
            mpl::size<Args>::value, M, R, T, Args
        > type;
    };
};

template <long Arity, class T, class R, class Args>
struct call_invoker;

template <class T, class R>
struct make_call_invoker
{
    template <class Args>
    struct apply
    {
        typedef call_invoker<
            mpl::size<Args>::value, T, R, Args
        > type;
    };
};

template <long Arity, class T, class Args>
struct init_invoker;

template <class T>
struct make_init_invoker
{
    template <class Args>
    struct apply
    {
        typedef init_invoker<
            mpl::size<Args>::value, T, Args
        > type;
    };
};

template <class M, class R, class Args>
struct invoker<0, M, R, Args>
{
    static R execute()
    {
        return M()(streams_boost::type<R>());
    }
};

template <class M, class R, class T, class Args>
struct member_invoker<0, M, R, T, Args>
{
    static R execute(T& self)
    {
        return M()(streams_boost::type<R>(), self);
    }
};

template <class T, class R, class Args>
struct call_invoker<0, T, R, Args>
{
    static R execute(T& self)
    {
        return self();
    }
};

template <class T, class Args>
struct init_invoker<0, T, Args>
{
    static T* execute(T& self)
    {
        return new T;
    }
};

# define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (4, \
    (1, STREAMS_BOOST_PARAMETER_MAX_ARITY, <streams_boost/parameter/aux_/python/invoker_iterate.hpp>, 1))
# include STREAMS_BOOST_PP_ITERATE()

# define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (4, \
    (1, STREAMS_BOOST_PARAMETER_MAX_ARITY, <streams_boost/parameter/aux_/python/invoker_iterate.hpp>, 2))
# include STREAMS_BOOST_PP_ITERATE()

# define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (4, \
    (1, STREAMS_BOOST_PARAMETER_MAX_ARITY, <streams_boost/parameter/aux_/python/invoker_iterate.hpp>, 3))
# include STREAMS_BOOST_PP_ITERATE()

# define STREAMS_BOOST_PP_ITERATION_PARAMS_1 (4, \
    (1, STREAMS_BOOST_PARAMETER_MAX_ARITY, <streams_boost/parameter/aux_/python/invoker_iterate.hpp>, 4))
# include STREAMS_BOOST_PP_ITERATE()

}}}} // namespace streams_boost::parameter::python::aux

#endif // STREAMS_BOOST_PARAMETER_INVOKER_051210_HPP

