/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_CORE_TYPEOF_HPP)
#define STREAMS_BOOST_SPIRIT_CORE_TYPEOF_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/cstdint.hpp>

#include <streams_boost/typeof/typeof.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/nil.hpp>
#include <streams_boost/spirit/home/classic/core/primitives/numerics_fwd.hpp>
#include <streams_boost/spirit/home/classic/core/scanner/scanner_fwd.hpp>
#include <streams_boost/spirit/home/classic/core/scanner/skipper_fwd.hpp>
#include <streams_boost/spirit/home/classic/core/non_terminal/subrule_fwd.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    // parser.hpp
    template <typename IteratorT> struct parse_info;
    struct plain_parser_category;
    struct binary_parser_category;
    struct unary_parser_category;
    struct action_parser_category;

    // match.hpp
    template<typename T> class match; 

    // primitives/primitives.hpp
    template<class ParserT> struct negated_char_parser;
    template<typename CharT> struct chlit;
    template<typename CharT> struct range;
    template<typename IteratorT> class chseq;
    template<typename IteratorT> class strlit;
    struct nothing_parser;
    struct anychar_parser;
    struct alnum_parser;
    struct alpha_parser;
    struct cntrl_parser;
    struct digit_parser;
    struct xdigit_parser;
    struct graph_parser;
    struct upper_parser;
    struct lower_parser;
    struct print_parser;
    struct punct_parser;
    struct blank_parser;
    struct space_parser;
    struct eol_parser;
    struct end_parser; 

    // non_terminal/parser_context.hpp
    template<typename T> struct parser_context;

    // non_terminal/parser_id.hpp
    class parser_id;
    template<int N> struct parser_tag;
    class dynamic_parser_tag;
    struct parser_address_tag;

    // non_terminal/rule.hpp
    template<typename T0, typename T1, typename T2> class rule; 

    // non_terminal/grammar.hpp
    template<class DerivedT, typename ContextT> struct grammar; 

    // composite.hpp
    template<class ParserT, typename ActionT> class action;
    template<class A, class B> struct alternative;
    template<class A, class B> struct difference;
    template<class A, class B> struct exclusive_or;
    template<class A, class B> struct intersection;
    template<class a, class b> struct sequence;
    template<class A, class B> struct sequential_or;
    template<class S> struct kleene_star;
    template<class S> struct positive;
    template<class S> struct optional;
    // composite/directives.hpp
    template<class ParserT> struct contiguous;
    template<class ParserT> struct inhibit_case;
    template<class BaseT> struct inhibit_case_iteration_policy;
    template<class A, class B> struct longest_alternative;
    template<class A, class B> struct shortest_alternative;
    template<class ParserT, typename BoundsT> struct min_bounded;
    template<class ParserT, typename BoundsT> struct max_bounded;
    template<class ParserT, typename BoundsT> struct bounded;
    // composite/no_actions.hpp
    template<class Parser> struct no_actions_parser;
    template<class Base> struct no_actions_action_policy;
    // composite/epsilon.hpp
    struct epsilon_parser;
    template<typename CondT, bool positive> struct condition_parser;
    template<typename SubjectT> struct empty_match_parser;
    template<typename SubjectT> struct negated_empty_match_parser;

    // deprecated assign/push_back actor -- they live somewhere else, now
    struct assign_action;
    struct push_back_action;
    template<typename T, typename ActionT> class ref_value_actor;
    template<typename T, typename ValueT, typename ActionT> 
    class ref_const_ref_actor;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS



#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()


// parser.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parse_info,1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::plain_parser_category)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::binary_parser_category)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::unary_parser_category)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::action_parser_category)


// nil.hpp (included directly)

#if !defined(STREAMS_BOOST_SPIRIT_NIL_T_TYPEOF_REGISTERED)
// registration guard to decouple the iterators from the core
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::nil_t)
#   define STREAMS_BOOST_SPIRIT_NIL_T_TYPEOF_REGISTERED
#endif

// match.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::match, 1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::match<STREAMS_BOOST_SPIRIT_CLASSIC_NS::nil_t>)


// primitives/primitives.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::negated_char_parser, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chlit, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::range, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chseq, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strlit, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::nothing_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::anychar_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::alnum_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::alpha_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::cntrl_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::digit_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::xdigit_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::graph_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::upper_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::lower_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::print_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::punct_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::blank_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::space_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::eol_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::end_parser)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chlit<char>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chlit<wchar_t>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::range<char>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::range<wchar_t>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chseq<char const *>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chseq<wchar_t const *>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strlit<char const *>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strlit<wchar_t const *>)


// primitives/numerics.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::int_parser, (class)(int)(unsigned)(int))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::uint_parser, (class)(int)(unsigned)(int))
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::sign_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::real_parser, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::real_parser_policies, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::ureal_parser_policies, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strict_real_parser_policies, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strict_ureal_parser_policies, 1)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::int_parser, (class)(int))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::uint_parser, (class)(int))
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::int_parser<streams_boost::int32_t>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::uint_parser<streams_boost::uint32_t>)
#if !defined(STREAMS_BOOST_NO_INT64_T)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::int_parser<streams_boost::int64_t>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::uint_parser<streams_boost::uint64_t>)
#endif
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::real_parser_policies<float>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::real_parser_policies<double>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::ureal_parser_policies<float>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::ureal_parser_policies<double>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strict_real_parser_policies<float>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strict_real_parser_policies<double>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strict_ureal_parser_policies<float>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::strict_ureal_parser_policies<double>)


// scanner/scanner.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner_policies,3)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::iteration_policy)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::action_policy)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::match_policy)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner_policies,2)


// scanner/skipper.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::skipper_iteration_policy,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::no_skipper_iteration_policy,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::skip_parser_iteration_policy,2)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::skipper_iteration_policy<>)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::skip_parser_iteration_policy,1)


// non_terminal/parser_context.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parser_context,1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parser_context<STREAMS_BOOST_SPIRIT_CLASSIC_NS::nil_t>)


// non_terminal/parser_id.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parser_id)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parser_tag, (int))
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::dynamic_parser_tag)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::parser_address_tag)


// non_terminal/subrule.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule,(int)(class))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule_parser,(int)(class)(class))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule_list,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrules_scanner,2)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule,(int))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule_parser,(int)(class))
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<0>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<1>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<2>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<3>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<4>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<5>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<6>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::subrule<7>)


// non_terminal/rule.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::rule,3)
#if STREAMS_BOOST_SPIRIT_RULE_SCANNERTYPE_LIMIT > 1
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner_list,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scanner_list,STREAMS_BOOST_SPIRIT_RULE_SCANNERTYPE_LIMIT)
#endif


// non_terminal/grammar.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::grammar,2)


// composite.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::action, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::alternative, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::difference, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::exclusive_or, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::intersection, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::sequence, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::sequential_or, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::kleene_star, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::positive, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::optional, 1)


// composite/directives.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::contiguous, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::inhibit_case, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::inhibit_case_iteration_policy,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::longest_alternative, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::shortest_alternative, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::min_bounded, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::max_bounded, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::bounded, 2)


// composite/no_actions.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::no_actions_parser, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::no_actions_action_policy, 1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::no_actions_action_policy<STREAMS_BOOST_SPIRIT_CLASSIC_NS::action_policy>)


// composite/epsilon.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::epsilon_parser)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::condition_parser, (class)(bool))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::empty_match_parser, 1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::negated_empty_match_parser, 1)


#if !defined(STREAMS_BOOST_SPIRIT_ACTOR_TYPEOF_HPP)
// deprecated assign/push_back actor -- they live somewhere else, now
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::ref_value_actor,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::ref_const_ref_actor,3)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::assign_action)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::push_back_action)
#endif


#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,STREAMS_BOOST_TESTED_AT(1400)) && STREAMS_BOOST_MSVC >= 1400
namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    nil_t & operator* (nil_t);
    nil_t & operator+ (nil_t);

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

} } // namespace ::STREAMS_BOOST_SPIRIT_CLASSIC_NS
#endif


#endif
 
