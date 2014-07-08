/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_ATTRIBUTE_TYPEOF_HPP)
#define STREAMS_BOOST_SPIRIT_ATTRIBUTE_TYPEOF_HPP

#include <streams_boost/typeof/typeof.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/typeof.hpp>
#include <streams_boost/spirit/home/classic/attribute/closure_fwd.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    // parametric.hpp
    template<typename ChGenT>                        struct f_chlit;
    template<typename ChGenAT, typename ChGenBT>     struct f_range;
    template<typename IterGenAT, typename IterGenBT> class f_chseq;
    template<typename IterGenAT, typename IterGenBT> class f_strlit;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS


#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()


// parametric.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::f_chlit,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::f_range,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::f_chseq,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::f_strlit,2)


// closure.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure,STREAMS_BOOST_SPIRIT_CLOSURE_LIMIT)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure_context,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::init_closure_context,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::init_closure_parser,2)


#if STREAMS_BOOST_SPIRIT_CLOSURE_LIMIT  > 12
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure,12)
#endif
#if STREAMS_BOOST_SPIRIT_CLOSURE_LIMIT > 9
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure, 9)
#endif
#if STREAMS_BOOST_SPIRIT_CLOSURE_LIMIT > 6
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure, 6)
#endif
#if STREAMS_BOOST_SPIRIT_CLOSURE_LIMIT > 3
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::closure, 3)
#endif



#endif

