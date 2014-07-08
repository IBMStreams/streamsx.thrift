//  Copyright (c) 2001 Daniel C. Nuffer
//  Copyright (c) 2001-2010 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#if !defined(STREAMS_BOOST_SPIRIT_ISTREAM_POLICY_JAN_04_2010_0130PM)
#define STREAMS_BOOST_SPIRIT_ISTREAM_POLICY_JAN_04_2010_0130PM

#include <streams_boost/spirit/home/support/iterators/multi_pass_fwd.hpp>
#include <streams_boost/spirit/home/support/iterators/detail/multi_pass.hpp>

namespace streams_boost { namespace spirit { namespace iterator_policies
{
    ///////////////////////////////////////////////////////////////////////////
    //  class istream
    //  Implementation of the InputPolicy used by multi_pass
    // 
    //  The istream encapsulates an std::basic_istream
    ///////////////////////////////////////////////////////////////////////////
    struct istream
    {
        ///////////////////////////////////////////////////////////////////////
        template <typename T>
        class unique // : public detail::default_input_policy
        {
        private:
            typedef typename T::char_type result_type;

        public:
            typedef typename T::off_type difference_type;
            typedef typename T::off_type distance_type;
            typedef result_type const* pointer;
            typedef result_type const& reference;
            typedef result_type value_type;

        protected:
            unique() {}
            explicit unique(T&) {}

            void swap(unique&) {}

        public:
            template <typename MultiPass>
            static void destroy(MultiPass&) {}

            template <typename ValueType, typename MultiPass>
            static ValueType const& get_input(MultiPass& mp)
            {
                if (!mp.shared()->initialized_)
                    advance_input(mp);
                return mp.shared()->curtok_;
            }

            template <typename MultiPass>
            static void advance_input(MultiPass& mp)
            {
                mp.shared()->read_one();
            }

            // test, whether we reached the end of the underlying stream
            template <typename MultiPass>
            static bool input_at_eof(MultiPass const& mp) 
            {
                return mp.shared()->eof_reached_;
            }

            template <typename MultiPass>
            static bool input_is_valid(MultiPass const& mp, value_type const& t) 
            {
                return mp.shared()->initialized_;
            }

            // no unique data elements
        };

        ///////////////////////////////////////////////////////////////////////
        template <typename T>
        struct shared
        {
        private:
            typedef typename T::char_type result_type;

        public:
            explicit shared(T& input) 
              : input_(input), curtok_(-1)
              , initialized_(false), eof_reached_(false) 
            {}

            void read_one()
            {
                if (!(input_ >> curtok_))
                    eof_reached_ = true;
                initialized_ = true;
            }

            T& input_;
            result_type curtok_;
            bool initialized_;
            bool eof_reached_;
        };
    };

}}}

#endif