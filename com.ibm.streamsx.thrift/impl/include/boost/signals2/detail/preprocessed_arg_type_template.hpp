// Copyright Frank Mori Hess 2009
//
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

// This file is included iteratively, and should not be protected from multiple inclusion

#define STREAMS_BOOST_SIGNALS2_NUM_ARGS STREAMS_BOOST_PP_ITERATION()

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      template<unsigned n STREAMS_BOOST_PP_COMMA_IF(STREAMS_BOOST_SIGNALS2_NUM_ARGS)
        STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS)>
        class STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_N_TYPE_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS);

// template<typename T1, typename T2, ... , typename TN> class preprocessed_arg_typeN<n, T1, T2, ..., TN>{...} ...
#define STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_TYPE_CLASS_TEMPLATE_SPECIALIZATION(z, n, data) \
  template<STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_DECL(STREAMS_BOOST_SIGNALS2_NUM_ARGS)> \
  class STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_N_TYPE_CLASS_NAME(STREAMS_BOOST_SIGNALS2_NUM_ARGS)<n, \
    STREAMS_BOOST_SIGNALS2_ARGS_TEMPLATE_INSTANTIATION(STREAMS_BOOST_SIGNALS2_NUM_ARGS)> \
  { \
  public: \
    typedef STREAMS_BOOST_PP_CAT(T, STREAMS_BOOST_PP_INC(n)) type; \
  };
      STREAMS_BOOST_PP_REPEAT(STREAMS_BOOST_SIGNALS2_NUM_ARGS, STREAMS_BOOST_SIGNALS2_PREPROCESSED_ARG_TYPE_CLASS_TEMPLATE_SPECIALIZATION, ~)

    } // namespace detail
  } // namespace signals2
} // namespace streams_boost

#undef STREAMS_BOOST_SIGNALS2_NUM_ARGS
