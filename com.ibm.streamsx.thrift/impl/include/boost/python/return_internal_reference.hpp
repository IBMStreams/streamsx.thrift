// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef RETURN_INTERNAL_REFERENCE_DWA2002131_STREAMS_HPP
# define RETURN_INTERNAL_REFERENCE_DWA2002131_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/default_call_policies.hpp>
# include <streams_boost/python/reference_existing_object.hpp>
# include <streams_boost/python/with_custodian_and_ward.hpp>
# include <streams_boost/mpl/if.hpp>

namespace streams_boost { namespace python { 

namespace detail
{
  template <std::size_t>
  struct return_internal_reference_owner_arg_must_be_greater_than_zero
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
  {}
# endif
  ;
}

template <std::size_t owner_arg = 1, class BasePolicy_ = default_call_policies>
struct return_internal_reference
    : with_custodian_and_ward_postcall<0, owner_arg, BasePolicy_>
{
 private:
    STREAMS_BOOST_STATIC_CONSTANT(bool, legal = owner_arg > 0);
 public:
    typedef typename mpl::if_c<
        legal
        , reference_existing_object
        , detail::return_internal_reference_owner_arg_must_be_greater_than_zero<owner_arg>
    >::type result_converter;
};

}} // namespace streams_boost::python

#endif // RETURN_INTERNAL_REFERENCE_DWA2002131_STREAMS_HPP
