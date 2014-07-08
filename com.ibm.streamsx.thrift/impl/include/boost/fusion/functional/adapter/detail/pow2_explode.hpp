/*=============================================================================
    Copyright (c) 2006-2007 Tobias Schwinger
  
    Use modification and distribution are subject to the Boost Software 
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt).
==============================================================================*/

#if !defined(STREAMS_BOOST_PP_IS_ITERATING)
#   error "This file has to be included by a preprocessor loop construct!"
#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 1

#   if !defined(STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_DETAIL_POW2_EXPLODE_HPP_INCLUDED)
#       include <streams_boost/preprocessor/config/limits.hpp>
#       include <streams_boost/preprocessor/slot/slot.hpp>
#       include <streams_boost/preprocessor/arithmetic/dec.hpp>
#       define STREAMS_BOOST_FUSION_FUNCTIONAL_ADAPTER_DETAIL_POW2_EXPLODE_HPP_INCLUDED
#   endif

#   define  STREAMS_BOOST_PP_VALUE 0
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)

#   define  STREAMS_BOOST_PP_FILENAME_2 \
        <streams_boost/fusion/functional/adapter/detail/pow2_explode.hpp>
#   define  STREAMS_BOOST_PP_VALUE (1 << N) >> 4 
#   if STREAMS_BOOST_PP_VALUE > STREAMS_BOOST_PP_LIMIT_ITERATION
#       error "Preprocessor limit exceeded."
#   endif

#   include STREAMS_BOOST_PP_ASSIGN_SLOT(2)
#   define  STREAMS_BOOST_PP_ITERATION_LIMITS (0,STREAMS_BOOST_PP_DEC(STREAMS_BOOST_PP_SLOT_2()))
#   include STREAMS_BOOST_PP_ITERATE()

#elif STREAMS_BOOST_PP_ITERATION_DEPTH() == 2

#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   if STREAMS_BOOST_PP_SLOT_1() < 1 << N
#   include STREAMS_BOOST_PP_INDIRECT_SELF
#   define  STREAMS_BOOST_PP_VALUE STREAMS_BOOST_PP_SLOT_1() + 1
#   include STREAMS_BOOST_PP_ASSIGN_SLOT(1)
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif
#   endif

#endif

