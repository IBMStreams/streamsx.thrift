/*=============================================================================
    Copyright (c) 2006-2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_LIMITS_HPP_INCLUDED)
#   define STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_LIMITS_HPP_INCLUDED

#   include <streams_boost/fusion/container/vector/limits.hpp>

#   if !defined(STREAMS_BOOST_FUSION_UNFUSED_MAX_ARITY)
#       define STREAMS_BOOST_FUSION_UNFUSED_MAX_ARITY 6
#   elif STREAMS_BOOST_FUSION_UNFUSED_GENERIC_MAX_ARITY > FUSION_MAX_VECTOR_SIZE
#       error "STREAMS_BOOST_FUSION_UNFUSED_GENERIC_MAX_ARITY > FUSION_MAX_VECTOR_SIZE"
#   endif
#   if !defined(STREAMS_BOOST_FUSION_UNFUSED_TYPED_MAX_ARITY)
#       define STREAMS_BOOST_FUSION_UNFUSED_TYPED_MAX_ARITY 6
#   elif STREAMS_BOOST_FUSION_UNFUSED_TYPED_MAX_ARITY > FUSION_MAX_VECTOR_SIZE
#       error "STREAMS_BOOST_FUSION_UNFUSED_TYPED_MAX_ARITY > FUSION_MAX_VECTOR_SIZE"
#   endif

#endif

