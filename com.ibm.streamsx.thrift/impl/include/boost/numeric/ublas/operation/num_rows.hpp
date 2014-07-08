/**
 * -*- c++ -*-
 *
 * \file num_rows.hpp
 *
 * \brief The \c num_rows operation.
 *
 * Copyright (c) 2009, Marco Guazzone
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * \author Marco Guazzone, marco.guazzone@gmail.com
 */

#ifndef STREAMS_BOOST_NUMERIC_UBLAS_OPERATION_NUM_ROWS_HPP
#define STREAMS_BOOST_NUMERIC_UBLAS_OPERATION_NUM_ROWS_HPP


#include <streams_boost/numeric/ublas/detail/config.hpp>


namespace streams_boost { namespace numeric { namespace ublas {

    /**
     * \brief Return the number of rows.
     * \tparam MatrixExprT A type which models the matrix expression concept.
     * \param m A matrix expression.
     * \return The number of rows.
     */
    template <typename MatrixExprT>
    STREAMS_BOOST_UBLAS_INLINE
    typename MatrixExprT::size_type num_rows(MatrixExprT const& m)
    {
        return m.size1();
    }

}}} // Namespace streams_boost::numeric::ublas


#endif // STREAMS_BOOST_NUMERIC_UBLAS_OPERATION_NUM_ROWS_HPP
