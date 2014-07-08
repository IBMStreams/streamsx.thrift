//  (C) Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_TOOLS_SOLVE_HPP
#define STREAMS_BOOST_MATH_TOOLS_SOLVE_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <streams_boost/config.hpp>
#include <streams_boost/assert.hpp>

#ifdef STREAMS_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable:4996 4267 4244)
#endif

#include <streams_boost/numeric/ublas/lu.hpp>
#include <streams_boost/numeric/ublas/matrix.hpp>
#include <streams_boost/numeric/ublas/vector.hpp>

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

namespace streams_boost{ namespace math{ namespace tools{

//
// Find x such that Ax = b
//
// Caution: this uses undocumented, and untested ublas code,
// however short of writing our own LU-decompostion code
// it's the only game in town.
//
template <class T>
streams_boost::numeric::ublas::vector<T> solve(
          const streams_boost::numeric::ublas::matrix<T>& A_,
          const streams_boost::numeric::ublas::vector<T>& b_)
{
   //STREAMS_BOOST_ASSERT(A_.size() == b_.size());

   streams_boost::numeric::ublas::matrix<T> A(A_);
   streams_boost::numeric::ublas::vector<T> b(b_);
   streams_boost::numeric::ublas::permutation_matrix<> piv(b.size());
   lu_factorize(A, piv);
   lu_substitute(A, piv, b);
   //
   // iterate to reduce error:
   //
   streams_boost::numeric::ublas::vector<T> delta(b.size());
   for(unsigned i = 0; i < 1; ++i)
   {
      noalias(delta) = prod(A_, b);
      delta -= b_;
      lu_substitute(A, piv, delta);
      b -= delta;

      T max_error = 0;

      for(unsigned i = 0; i < delta.size(); ++i)
      {
         T err = fabs(delta[i] / b[i]);
         if(err > max_error)
            max_error = err;
      }
      //std::cout << "Max change in LU error correction: " << max_error << std::endl;
   }

   return b;
}

}}} // namespaces

#endif // STREAMS_BOOST_MATH_TOOLS_SOLVE_HPP


