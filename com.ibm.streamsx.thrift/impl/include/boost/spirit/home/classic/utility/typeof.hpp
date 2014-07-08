/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_UTILITY_TYPEOF_HPP)
#define STREAMS_BOOST_SPIRIT_UTILITY_TYPEOF_HPP

#include <streams_boost/typeof/typeof.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/core/typeof.hpp>

#include <streams_boost/spirit/home/classic/utility/escape_char_fwd.hpp>
#include <streams_boost/spirit/home/classic/utility/confix_fwd.hpp>
#include <streams_boost/spirit/home/classic/utility/lists_fwd.hpp>
#include <streams_boost/spirit/home/classic/utility/distinct_fwd.hpp>
#include <streams_boost/spirit/home/classic/utility/grammar_def_fwd.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    // chset.hpp
    template<typename CharT> class chset;        

    // functor_parser.hpp
    template<typename FunctorT> struct functor_parser;

    // loops.hpp
    template<class ParserT, typename ExactT> class fixed_loop;
    template<class ParserT, typename MinT, typename MaxT> class finite_loop;
    template<class ParserT, typename MinT> class infinite_loop;

    // regex.hpp
    template<typename CharT> struct rxstrlit;

    // flush_multi_pass.hpp
    class flush_multi_pass_parser;  

    // scoped_lock.hpp
    template<class MutexT, class ParserT> struct scoped_lock_parser;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS


#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()


// chset.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chset,1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chset<char>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::chset<wchar_t>)


// escape_char.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::escape_char_parser,(STREAMS_BOOST_TYPEOF_INTEGRAL(unsigned long))(typename))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::escape_char_action,(class)(typename)(STREAMS_BOOST_TYPEOF_INTEGRAL(unsigned long))(typename))

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::escape_char_parser,(STREAMS_BOOST_TYPEOF_INTEGRAL(unsigned long)))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::escape_char_action,(class)(typename)(STREAMS_BOOST_TYPEOF_INTEGRAL(unsigned long)))


// functor_parser.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::functor_parser,1)


// loops.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fixed_loop,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::finite_loop,3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::infinite_loop,2)


// regex.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::rxstrlit,1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::rxstrlit<char>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::rxstrlit<wchar_t>)


// confix.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::confix_parser, 6)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::confix_parser, 5)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::confix_parser, 4)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::confix_parser, 3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::comment_nest_parser, 2)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::is_nested)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::non_nested)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::is_lexeme)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::non_lexeme)


// lists.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::list_parser,4)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::list_parser,3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::list_parser,2)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::no_list_endtoken)


// distinct.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::distinct_parser,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::distinct_parser,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::dynamic_distinct_parser,1)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::distinct_parser<>)


// flush_multi_pass.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::flush_multi_pass_parser)


// scoped_lock.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::scoped_lock_parser,2)


// grammar_gen.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::grammar_def,STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT)

#if STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT > 12
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::grammar_def,12)
#endif
#if STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT >  9
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::grammar_def, 9)
#endif
#if STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT >  6
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::grammar_def, 6)
#endif
#if STREAMS_BOOST_SPIRIT_GRAMMAR_STARTRULE_TYPE_LIMIT >  3
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::grammar_def, 3)
#endif


#endif


