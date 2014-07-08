//  Copyright (c) 2001-2010 Joel de Guzman
//  Copyright (c) 2001-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_KARMA_GRAMMAR_MAR_05_2007_0542PM)
#define STREAMS_BOOST_SPIRIT_KARMA_GRAMMAR_MAR_05_2007_0542PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <streams_boost/spirit/home/support/unused.hpp>
#include <streams_boost/spirit/home/support/info.hpp>
#include <streams_boost/spirit/home/support/assert_msg.hpp>
#include <streams_boost/spirit/home/karma/domain.hpp>
#include <streams_boost/spirit/home/karma/nonterminal/rule.hpp>
#include <streams_boost/spirit/home/karma/reference.hpp>
#include <streams_boost/noncopyable.hpp>
#include <streams_boost/type_traits/is_same.hpp>

namespace streams_boost { namespace spirit { namespace karma
{
    template <
        typename OutputIterator
      , typename T1 = unused_type
      , typename T2 = unused_type
      , typename T3 = unused_type
    >
    struct grammar
      : proto::extends<
            typename proto::terminal<
                reference<rule<OutputIterator, T1, T2, T3> const>
            >::type
          , grammar<OutputIterator, T1, T2, T3>
        >
      , generator<grammar<OutputIterator, T1, T2, T3> >
      , noncopyable
    {
        typedef OutputIterator iterator_type;
        typedef rule<OutputIterator, T1, T2, T3> start_type;
        typedef typename start_type::properties properties;
        typedef typename start_type::sig_type sig_type;
        typedef typename start_type::locals_type locals_type;
        typedef typename start_type::delimiter_type delimiter_type;
        typedef grammar<OutputIterator, T1, T2, T3> base_type;
        typedef reference<start_type const> reference_;
        typedef typename proto::terminal<reference_>::type terminal;

        static size_t const params_size = start_type::params_size;

        // the output iterator is always wrapped by karma
        typedef detail::output_iterator<OutputIterator, properties> 
            output_iterator;

        grammar(start_type const& start
              , std::string const& name_ = "unnamed-grammar")
          : proto::extends<terminal, base_type>(terminal::make(reference_(start)))
          , name_(name_)
        {}

        // This constructor is used to catch if the start rule is not 
        // compatible with the grammar. 
        template <typename Iterator_, typename T1_, typename T2_, typename T3_>
        grammar(rule<Iterator_, T1_, T2_, T3_> const&
              , std::string const& = "unnamed-grammar")
        {
            // If you see the assertion below failing then the start rule 
            // passed to the constructor of the grammar is not compatible with 
            // the grammar (i.e. it uses different template parameters).
            STREAMS_BOOST_SPIRIT_ASSERT_MSG(
                (is_same<start_type, rule<Iterator_, T1_, T2_, T3_> >::value)
              , incompatible_start_rule, (rule<Iterator_, T1_, T2_, T3_>));
        }

        std::string name() const
        {
            return name_;
        }

        void name(std::string const& str)
        {
            name_ = str;
        }

        template <typename Context, typename Delimiter, typename Attribute>
        bool generate(output_iterator& sink, Context& context
          , Delimiter const& delim, Attribute const& attr) const
        {
            return this->proto_base().child0.generate(
                sink, context, delim, attr);
        }

        template <typename Context>
        info what(Context& context) const
        {
            return info(name_);
        }

        // bring in the operator() overloads
        start_type const& get_parameterized_subject() const
        { return this->proto_base().child0.ref.get(); }
        typedef start_type parameterized_subject_type;
        #include <streams_boost/spirit/home/karma/nonterminal/detail/fcall.hpp>

        std::string name_;
    };

}}}

#endif
