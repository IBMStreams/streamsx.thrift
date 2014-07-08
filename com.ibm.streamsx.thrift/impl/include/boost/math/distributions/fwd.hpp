// Copyright Paul A. Bristow 2007.
// Copyright John Maddock 2007.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_MATH_DISTRIBUTIONS_FWD_HPP
#define STREAMS_BOOST_MATH_DISTRIBUTIONS_FWD_HPP

namespace streams_boost{ namespace math{

template <class RealType, class Policy>
class bernoulli_distribution;

template <class RealType, class Policy>
class beta_distribution;

template <class RealType, class Policy>
class binomial_distribution;

template <class RealType, class Policy>
class cauchy_distribution;

template <class RealType, class Policy>
class chi_squared_distribution;

template <class RealType, class Policy>
class exponential_distribution;

template <class RealType, class Policy>
class extreme_value_distribution;

template <class RealType, class Policy>
class fisher_f_distribution;

template <class RealType, class Policy>
class gamma_distribution;

template <class RealType, class Policy>
class hypergeometric_distribution;

template <class RealType, class Policy>
class laplace_distribution;

template <class RealType, class Policy>
class logistic_distribution;

template <class RealType, class Policy>
class lognormal_distribution;

template <class RealType, class Policy>
class negative_binomial_distribution;

template <class RealType, class Policy>
class non_central_chi_squared_distribution;

template <class RealType, class Policy>
class non_central_beta_distribution;

template <class RealType, class Policy>
class non_central_f_distribution;

template <class RealType, class Policy>
class non_central_t_distribution;

template <class RealType, class Policy>
class normal_distribution;

template <class RealType, class Policy>
class pareto_distribution;

template <class RealType, class Policy>
class poisson_distribution;

template <class RealType, class Policy>
class rayleigh_distribution;

template <class RealType, class Policy>
class students_t_distribution;

template <class RealType, class Policy>
class triangular_distribution;

template <class RealType, class Policy>
class uniform_distribution;

template <class RealType, class Policy>
class weibull_distribution;

}} // namespaces

#define STREAMS_BOOST_MATH_DECLARE_DISTRIBUTIONS(Type, Policy)\
   typedef streams_boost::math::bernoulli_distribution<Type, Policy> bernoulli;\
   typedef streams_boost::math::beta_distribution<Type, Policy> beta;\
   typedef streams_boost::math::binomial_distribution<Type, Policy> binomial;\
   typedef streams_boost::math::cauchy_distribution<Type, Policy> cauchy;\
   typedef streams_boost::math::chi_squared_distribution<Type, Policy> chi_squared;\
   typedef streams_boost::math::exponential_distribution<Type, Policy> exponential;\
   typedef streams_boost::math::extreme_value_distribution<Type, Policy> extreme_value;\
   typedef streams_boost::math::fisher_f_distribution<Type, Policy> fisher_f;\
   typedef streams_boost::math::gamma_distribution<Type, Policy> gamma;\
   typedef streams_boost::math::laplace_distribution<Type, Policy> laplace;\
   typedef streams_boost::math::logistic_distribution<Type, Policy> logistic;\
   typedef streams_boost::math::lognormal_distribution<Type, Policy> lognormal;\
   typedef streams_boost::math::negative_binomial_distribution<Type, Policy> negative_binomial;\
   typedef streams_boost::math::normal_distribution<Type, Policy> normal;\
   typedef streams_boost::math::pareto_distribution<Type, Policy> pareto;\
   typedef streams_boost::math::poisson_distribution<Type, Policy> poisson;\
   typedef streams_boost::math::rayleigh_distribution<Type, Policy> rayleigh;\
   typedef streams_boost::math::students_t_distribution<Type, Policy> students_t;\
   typedef streams_boost::math::triangular_distribution<Type, Policy> triangular;\
   typedef streams_boost::math::uniform_distribution<Type, Policy> uniform;\
   typedef streams_boost::math::weibull_distribution<Type, Policy> weibull;\
   typedef streams_boost::math::non_central_chi_squared_distribution<Type, Policy> non_central_chi_squared;\
   typedef streams_boost::math::non_central_beta_distribution<Type, Policy> non_central_beta;\
   typedef streams_boost::math::non_central_f_distribution<Type, Policy> non_central_f;\
   typedef streams_boost::math::non_central_t_distribution<Type, Policy> non_central_t;\
   typedef streams_boost::math::hypergeometric_distribution<Type, Policy> hypergeometric;\

#endif // STREAMS_BOOST_MATH_DISTRIBUTIONS_FWD_HPP