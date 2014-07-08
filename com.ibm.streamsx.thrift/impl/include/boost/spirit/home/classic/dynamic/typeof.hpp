/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_DYNAMIC_TYPEOF_HPP)
#define STREAMS_BOOST_SPIRIT_DYNAMIC_TYPEOF_HPP

#include <streams_boost/typeof/typeof.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/typeof.hpp>

#include <streams_boost/spirit/home/classic/dynamic/stored_rule_fwd.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    // if.hpp
    template <class ParsableT, typename CondT> struct if_parser;
    template <class ParsableTrueT, class ParsableFalseT, typename CondT>
    struct if_else_parser;

    // for.hpp
    namespace impl {
    template<typename InitF, typename CondT, typename StepF, class ParsableT>
    struct for_parser;
    }

    // while.hpp
    template<typename ParsableT, typename CondT, bool is_do_parser>
    struct while_parser;

    // lazy.hpp
    template<typename ActorT> struct lazy_parser;

    // rule_alias.hpp
    template <typename ParserT> class rule_alias; 

    // switch.hpp
    template <typename CaseT, typename CondT>       struct switch_parser;
    template <int N, class ParserT, bool IsDefault> struct case_parser;

    // select.hpp
    template <typename TupleT, typename BehaviourT, typename T> 
    struct select_parser;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS


#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

// if.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::if_parser,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::if_else_parser,3)

// for.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::impl::for_parser,4)

// while.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::while_parser,(class)(class)(bool))

// lazy.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::lazy_parser,1)

// stored_rule.hpp (has forward header)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::stored_rule,(typename)(typename)(typename)(bool))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::stored_rule,3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::stored_rule,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::stored_rule,1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::stored_rule<>)

// rule_alias.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::rule_alias,1)

// switch.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::switch_parser,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::case_parser,(int)(class)(bool))

// select.hpp
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::select_parser,3)

#endif

