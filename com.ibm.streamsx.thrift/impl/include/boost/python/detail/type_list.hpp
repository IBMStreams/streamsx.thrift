// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef TYPE_LIST_DWA2002913_STREAMS_HPP
# define TYPE_LIST_DWA2002913_STREAMS_HPP

# include <streams_boost/config.hpp>
# include <streams_boost/python/detail/preprocessor.hpp>
# include <streams_boost/preprocessor/arithmetic/inc.hpp>

# if STREAMS_BOOST_PYTHON_MAX_ARITY + 2 > STREAMS_BOOST_PYTHON_MAX_BASES
#  define STREAMS_BOOST_PYTHON_LIST_SIZE STREAMS_BOOST_PP_INC(STREAMS_BOOST_PP_INC(STREAMS_BOOST_PYTHON_MAX_ARITY))
# else
#  define STREAMS_BOOST_PYTHON_LIST_SIZE STREAMS_BOOST_PYTHON_MAX_BASES
# endif

// Compute the MPL vector header to use for lists up to STREAMS_BOOST_PYTHON_LIST_SIZE in length
# if STREAMS_BOOST_PYTHON_LIST_SIZE > 48
#  error Arities above 48 not supported by Boost.Python due to MPL internal limit
# elif STREAMS_BOOST_PYTHON_LIST_SIZE > 38
#  include <streams_boost/mpl/vector/vector50.hpp>
# elif STREAMS_BOOST_PYTHON_LIST_SIZE > 28
#  include <streams_boost/mpl/vector/vector40.hpp>
# elif STREAMS_BOOST_PYTHON_LIST_SIZE > 18
#  include <streams_boost/mpl/vector/vector30.hpp>
# elif STREAMS_BOOST_PYTHON_LIST_SIZE > 8
#  include <streams_boost/mpl/vector/vector20.hpp>
# else
#  include <streams_boost/mpl/vector/vector10.hpp>
# endif

# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#  include <streams_boost/python/detail/type_list_impl.hpp>
# else
#  include <streams_boost/python/detail/type_list_impl_no_pts.hpp>
# endif

#endif // TYPE_LIST_DWA2002913_STREAMS_HPP
