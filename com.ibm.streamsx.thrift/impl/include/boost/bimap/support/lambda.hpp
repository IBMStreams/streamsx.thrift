// Boost.Bimap
//
// Copyright (c) 2006-2007 Matias Capeletto
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

/// \file support/lambda.hpp
/// \brief Placeholders definition to help in bimap modify function

#ifndef STREAMS_BOOST_BIMAP_SUPPORT_LAMBDA_HPP
#define STREAMS_BOOST_BIMAP_SUPPORT_LAMBDA_HPP

#if defined(_MSC_VER) && (_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp>

#include <streams_boost/lambda/lambda.hpp>

namespace streams_boost {
namespace bimaps {

namespace {

/*
streams_boost::lambda::placeholder1_type & _first  = streams_boost::lambda::_1;
streams_boost::lambda::placeholder2_type & _second = streams_boost::lambda::_2;

streams_boost::lambda::placeholder1_type & _left   = streams_boost::lambda::_1;
streams_boost::lambda::placeholder2_type & _right  = streams_boost::lambda::_2;
*/

streams_boost::lambda::placeholder1_type & _key  = streams_boost::lambda::_1;
streams_boost::lambda::placeholder1_type & _data = streams_boost::lambda::_1;

}

} // namespace bimaps
} // namespace streams_boost


#endif // STREAMS_BOOST_BIMAP_SUPPORT_LAMBDA_HPP

