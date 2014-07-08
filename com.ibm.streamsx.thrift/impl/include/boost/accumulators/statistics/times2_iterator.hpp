///////////////////////////////////////////////////////////////////////////////
// times2_iterator.hpp
//
//  Copyright 2006 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_ACCUMULATORS_STATISTICS_TIMES2_ITERATOR_HPP_DE_01_01_2006
#define STREAMS_BOOST_ACCUMULATORS_STATISTICS_TIMES2_ITERATOR_HPP_DE_01_01_2006

#include <functional>
#include <streams_boost/range/begin.hpp>
#include <streams_boost/range/end.hpp>
#include <streams_boost/range/iterator_range.hpp>
#include <streams_boost/iterator/transform_iterator.hpp>
#include <streams_boost/iterator/counting_iterator.hpp>
#include <streams_boost/iterator/permutation_iterator.hpp>

namespace streams_boost { namespace accumulators
{

namespace detail
{
    typedef transform_iterator<
        std::binder1st<std::multiplies<std::size_t> >
      , counting_iterator<std::size_t>
    > times2_iterator;

    inline times2_iterator make_times2_iterator(std::size_t i)
    {
        return make_transform_iterator(
            make_counting_iterator(i)
          , std::bind1st(std::multiplies<std::size_t>(), 2)
        );
    }


    ///////////////////////////////////////////////////////////////////////////////
    // lvalue_index_iterator
    template<typename Base>
    struct lvalue_index_iterator
      : Base
    {
        lvalue_index_iterator(Base base)
          : Base(base)
        {
        }

        typename Base::reference operator [](typename Base::difference_type n) const
        {
            return *(*this + n);
        }
    };
} // namespace detail

}}

#endif
