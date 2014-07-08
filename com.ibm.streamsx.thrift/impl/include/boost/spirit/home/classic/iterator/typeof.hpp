/*=============================================================================
    Copyright (c) 2006 Tobias Schwinger
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_ITERATOR_TYPEOF_HPP)
#define STREAMS_BOOST_SPIRIT_ITERATOR_TYPEOF_HPP

#include <streams_boost/typeof/typeof.hpp>
#include <streams_boost/typeof/std/string.hpp>

#include <streams_boost/spirit/home/classic/namespace.hpp>
#include <streams_boost/spirit/home/classic/iterator/multi_pass_fwd.hpp>
#include <streams_boost/spirit/home/classic/iterator/file_iterator_fwd.hpp>
#include <streams_boost/spirit/home/classic/iterator/position_iterator_fwd.hpp>

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    // external (from core)
    struct nil_t;

    // fixed_size_queue.hpp
    template<typename T, std::size_t N> class fixed_size_queue;
    template<typename QueueT, typename T, typename PointerT>
    class fsq_iterator;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

#if !defined(STREAMS_BOOST_SPIRIT_NIL_T_TYPEOF_REGISTERED)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::nil_t)
#   define STREAMS_BOOST_SPIRIT_NIL_T_TYPEOF_REGISTERED
#endif


// multi_pass.hpp (has forward header)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass,5)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::ref_counted)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::first_owner)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::buf_id_check)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::no_check)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::std_deque)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::fixed_size_queue,(STREAMS_BOOST_TYPEOF_INTEGRAL(std::size_t)))
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::input_iterator)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::lex_input)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass_policies::functor_input)

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass,3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::multi_pass,1)


// file_iterator.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_iterator,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fileiter_impl::std_file_iterator,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fileiter_impl::mmap_file_iterator,1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fileiter_impl::std_file_iterator<char>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fileiter_impl::std_file_iterator<wchar_t>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fileiter_impl::mmap_file_iterator<char>)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fileiter_impl::mmap_file_iterator<wchar_t>)


// fixed_size_queue.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fixed_size_queue,(typename)(STREAMS_BOOST_TYPEOF_INTEGRAL(std::size_t)))
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::fsq_iterator,3)


// position_iterator.hpp

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::position_iterator,3)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::position_iterator2,2)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::position_policy,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_position_base,1)
STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_position_without_column_base,1)

STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_position)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_position_base<std::basic_string<wchar_t> >)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_position_without_column)
STREAMS_BOOST_TYPEOF_REGISTER_TYPE(STREAMS_BOOST_SPIRIT_CLASSIC_NS::file_position_without_column_base<std::basic_string<wchar_t> >)

#endif

