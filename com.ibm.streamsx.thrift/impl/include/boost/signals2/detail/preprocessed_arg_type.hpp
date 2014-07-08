// Boost.Signals2 library

// Copyright Frank Mori Hess 2007-2009.
// Copyright Timmo Stange 2007.
// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_TYPE_HPP
#define STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_TYPE_HPP

#include <streams_boost/preprocessor/repetition.hpp>
#include <streams_boost/signals2/detail/signals_common_macros.hpp>

#define STREAMS_BOOST_PP_ITERATION_LIMITS (0, STREAMS_BOOST_PP_INC(STREAMS_BOOST_SIGNALS2_MAX_ARGS))
#define STREAMS_BOOST_PP_FILENAME_1 <streams_boost/signals2/detail/preprocessed_arg_type_template.hpp>
#include STREAMS_BOOST_PP_ITERATE()

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      struct std_functional_base
      {};
    } // namespace detail
  } // namespace signals2
} // namespace streams_boost

#endif // STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_TYPE_HPP
