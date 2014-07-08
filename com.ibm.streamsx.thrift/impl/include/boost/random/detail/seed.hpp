/* streams_boost random/detail/seed.hpp header file
 *
 * Copyright Steven Watanabe 2009
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org for most recent version including documentation.
 *
 * $Id: seed.hpp 53871 2009-06-13 17:54:06Z steven_watanabe $
 */

#ifndef STREAMS_BOOST_RANDOM_DETAIL_SEED_HPP
#define STREAMS_BOOST_RANDOM_DETAIL_SEED_HPP

#include <streams_boost/config.hpp>

#if !defined(STREAMS_BOOST_NO_SFINAE)

#include <streams_boost/utility/enable_if.hpp>
#include <streams_boost/type_traits/is_arithmetic.hpp>

namespace streams_boost {
namespace random {
namespace detail {

template<class T>
struct disable_seed : streams_boost::disable_if<streams_boost::is_arithmetic<T> > {};

template<class Engine, class T>
struct disable_constructor : disable_seed<T> {};

template<class Engine>
struct disable_constructor<Engine, Engine> {
};

#define STREAMS_BOOST_RANDOM_DETAIL_GENERATOR_CONSTRUCTOR(Self, Generator, gen) \
    template<class Generator>                                           \
    explicit Self(Generator& gen, typename ::streams_boost::random::detail::disable_constructor<Self, Generator>::type* = 0)

#define STREAMS_BOOST_RANDOM_DETAIL_GENERATOR_SEED(Self, Generator, gen)    \
    template<class Generator>                                       \
    void seed(Generator& gen, typename ::streams_boost::random::detail::disable_seed<Generator>::type* = 0)

#define STREAMS_BOOST_RANDOM_DETAIL_ARITHMETIC_CONSTRUCTOR(Self, T, x)  \
    explicit Self(const T& x)

#define STREAMS_BOOST_RANDOM_DETAIL_ARITHMETIC_SEED(Self, T, x) \
    void seed(const T& x)

}
}
}

#else

#include <streams_boost/type_traits/is_arithmetic.hpp>
#include <streams_boost/mpl/bool.hpp>

#define STREAMS_BOOST_RANDOM_DETAIL_GENERATOR_CONSTRUCTOR(Self, Generator, gen) \
    Self(Self& other) { *this = other; }                                \
    Self(const Self& other) { *this = other; }                          \
    template<class Generator>                                           \
    explicit Self(Generator& gen) {                                     \
        streams_boost_random_constructor_impl(gen, ::streams_boost::is_arithmetic<Generator>());\
    }                                                                   \
    template<class Generator>                                           \
    void streams_boost_random_constructor_impl(Generator& gen, ::streams_boost::mpl::false_)

#define STREAMS_BOOST_RANDOM_DETAIL_GENERATOR_SEED(Self, Generator, gen)    \
    template<class Generator>                                       \
    void seed(Generator& gen) {                                     \
        streams_boost_random_seed_impl(gen, ::streams_boost::is_arithmetic<Generator>());\
    }\
    template<class Generator>\
    void streams_boost_random_seed_impl(Generator& gen, ::streams_boost::mpl::false_)

#define STREAMS_BOOST_RANDOM_DETAIL_ARITHMETIC_CONSTRUCTOR(Self, T, x)  \
    explicit Self(const T& x) { streams_boost_random_constructor_impl(x, ::streams_boost::mpl::true_()); }\
    void streams_boost_random_constructor_impl(const T& x, ::streams_boost::mpl::true_)

#define STREAMS_BOOST_RANDOM_DETAIL_ARITHMETIC_SEED(Self, T, x) \
    void seed(const T& x) { streams_boost_random_seed_impl(x, ::streams_boost::mpl::true_()); }\
    void streams_boost_random_seed_impl(const T& x, ::streams_boost::mpl::true_)

#endif

#endif
