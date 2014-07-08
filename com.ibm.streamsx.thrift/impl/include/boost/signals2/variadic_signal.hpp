/*
  A variadic implementation of variadic streams_boost::signals2::signal, used when variadic
  template support is detected in the compiler.

  Author: Frank Mori Hess <fmhess@users.sourceforge.net>
  Begin: 2009-05-26
*/
// Copyright Frank Mori Hess 2009
// Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS2_VARIADIC_SIGNAL_HPP
#define STREAMS_BOOST_SIGNALS2_VARIADIC_SIGNAL_HPP

#include <streams_boost/signals2/detail/variadic_arg_type.hpp>
#include <streams_boost/signals2/detail/variadic_slot_invoker.hpp>
#include <streams_boost/type_traits/function_traits.hpp>

namespace streams_boost
{
  namespace signals2
  {
    namespace detail
    {
      template<typename Signature> class variadic_extended_signature;
      // partial template specialization
      template<typename R, typename ... Args>
        class variadic_extended_signature<R (Args...)>
      {
      public:
        typedef streams_boost::function<R (const streams_boost::signals2::connection &, Args...)> function_type;
      };
    } // namespace detail
  } // namespace signals2
} // namespace streams_boost

#include <streams_boost/signals2/detail/signal_template.hpp>

#endif // STREAMS_BOOST_SIGNALS2_VARIADIC_SIGNAL_HPP
