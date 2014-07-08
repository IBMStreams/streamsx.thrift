//  Copyright (c) 2001 Daniel C. Nuffer
//  Copyright (c) 2001-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_ITERATOR_INPUT_ITERATOR_POLICY_MAR_16_2007_1156AM)
#define STREAMS_BOOST_SPIRIT_ITERATOR_INPUT_ITERATOR_POLICY_MAR_16_2007_1156AM

#include <streams_boost/spirit/home/support/iterators/multi_pass_fwd.hpp>
#include <streams_boost/spirit/home/support/iterators/detail/multi_pass.hpp>
#include <streams_boost/detail/iterator.hpp> // for streams_boost::detail::iterator_traits
#include <streams_boost/assert.hpp>

namespace streams_boost { namespace spirit { namespace iterator_policies
{
    namespace input_iterator_is_valid_test_
    {
        ///////////////////////////////////////////////////////////////////////
        template <typename Token>
        inline bool token_is_valid(Token const& c)
        {
            return c ? true : false;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //  class input_iterator
    //  Implementation of the InputPolicy used by multi_pass
    // 
    //  The input_iterator encapsulates an input iterator of type T
    ///////////////////////////////////////////////////////////////////////////
    struct input_iterator
    {
        ///////////////////////////////////////////////////////////////////////
        template <typename T>
        class unique // : public detail::default_input_policy
        {
        private:
            typedef
                typename streams_boost::detail::iterator_traits<T>::value_type
            result_type;

        public:
            typedef
                typename streams_boost::detail::iterator_traits<T>::difference_type
            difference_type;
            typedef
                typename streams_boost::detail::iterator_traits<T>::difference_type
            distance_type;
            typedef
                typename streams_boost::detail::iterator_traits<T>::pointer
            pointer;
            typedef
                typename streams_boost::detail::iterator_traits<T>::reference
            reference;
            typedef result_type value_type;

        protected:
            unique() {}
            explicit unique(T x) {}

            void swap(unique&) {}

        public:
            template <typename MultiPass>
            static void destroy(MultiPass&) {}

            template <typename ValueType, typename MultiPass>
            static ValueType const& get_input(MultiPass& mp)
            {
                return *mp.shared()->input_;
            }

            template <typename MultiPass>
            static void advance_input(MultiPass& mp)
            {
                ++mp.shared()->input_;
            }

            // test, whether we reached the end of the underlying stream
            template <typename MultiPass>
            static bool input_at_eof(MultiPass const& mp) 
            {
                static T const end_iter;
                return mp.shared()->input_ == end_iter;
            }

            template <typename MultiPass>
            static bool input_is_valid(MultiPass const& mp, value_type const& t) 
            {
                using namespace input_iterator_is_valid_test_;
                return token_is_valid(t);
            }

            // no unique data elements
        };

        ///////////////////////////////////////////////////////////////////////
        template <typename T>
        struct shared
        {
            explicit shared(T const& input) : input_(input) {}

            T input_;
        };
    };

}}}

#endif
