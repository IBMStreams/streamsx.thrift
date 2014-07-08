// Copyright David Abrahams 2005. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_PARAMETER_AUX_RESULT_OF0_DWA2005511_STREAMS_HPP
# define STREAMS_BOOST_PARAMETER_AUX_RESULT_OF0_DWA2005511_STREAMS_HPP

# include <streams_boost/utility/result_of.hpp>

// A metafunction returning the result of invoking a nullary function
// object of the given type.

#ifndef STREAMS_BOOST_NO_RESULT_OF

# include <streams_boost/utility/result_of.hpp>
namespace streams_boost { namespace parameter { namespace aux { 
template <class F>
struct result_of0 : result_of<F()>
{};

}}} // namespace streams_boost::parameter::aux_

#else

namespace streams_boost { namespace parameter { namespace aux { 
template <class F>
struct result_of0
{
    typedef typename F::result_type type;
};

}}} // namespace streams_boost::parameter::aux_

#endif 


#endif // STREAMS_BOOST_PARAMETER_AUX_RESULT_OF0_DWA2005511_STREAMS_HPP
