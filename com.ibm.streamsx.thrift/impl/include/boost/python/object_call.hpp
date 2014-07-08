# if !defined(STREAMS_BOOST_PYTHON_SYNOPSIS)
# // Copyright David Abrahams 2002.
# // Distributed under the Boost Software License, Version 1.0. (See
# // accompanying file LICENSE_1_0.txt or copy at
# // http://www.streams_boost.org/LICENSE_1_0.txt)

#  if !defined(STREAMS_BOOST_PP_IS_ITERATING)
#   error Boost.Python - do not include this file!
#  endif

#  define N STREAMS_BOOST_PP_ITERATION()

    template <STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, class A)>
    typename detail::dependent<object, A0>::type
    operator()(STREAMS_BOOST_PP_ENUM_BINARY_PARAMS_Z(1, N, A, const& a)) const
    {
        typedef typename detail::dependent<object, A0>::type obj;
        U const& self = *static_cast<U const*>(this);
        return call<obj>(get_managed_object(self, tag), STREAMS_BOOST_PP_ENUM_PARAMS_Z(1, N, a));
    }

#  undef N
# endif // STREAMS_BOOST_PYTHON_SYNOPSIS 
