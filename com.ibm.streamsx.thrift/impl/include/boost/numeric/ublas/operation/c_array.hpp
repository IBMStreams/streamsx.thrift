/**
 * -*- c++ -*-
 *
 * \file c_array.hpp
 *
 * \brief provides specializations of matrix and vector operations for c arrays and c matrices.
 *
 * Copyright (c) 2009, Gunter Winkler
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * \author Gunter Winkler (guwi17 at gmx dot de)
 */

#ifndef STREAMS_BOOST_NUMERIC_UBLAS_OPERATION_C_ARRAY_HPP
#define STREAMS_BOOST_NUMERIC_UBLAS_OPERATION_C_ARRAY_HPP

#include <streams_boost/numeric/ublas/traits/c_array.hpp>

namespace streams_boost { namespace numeric { namespace ublas {

    namespace detail {

    
    
    } // namespace streams_boost::numeric::ublas::detail


    template <typename T>
    STREAMS_BOOST_UBLAS_INLINE
    typename ExprT::const_iterator begin(vector_expression<ExprT> const& e)
    {
        return detail::begin_impl<typename ExprT::type_category>::apply(e());
    }


}}} // Namespace streams_boost::numeric::ublas

#endif
