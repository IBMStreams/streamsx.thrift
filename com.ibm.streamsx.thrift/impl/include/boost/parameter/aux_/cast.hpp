// Copyright Daniel Wallin 2006. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_CAST_060902_HPP
# define STREAMS_BOOST_PARAMETER_CAST_060902_HPP

# include <streams_boost/detail/workaround.hpp>

# if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
  && !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
#  include <streams_boost/type_traits/add_reference.hpp>
#  include <streams_boost/type_traits/remove_const.hpp>
# endif

namespace streams_boost { namespace parameter { namespace aux {

struct use_default_tag {};

# if defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
  || STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))

#  define STREAMS_BOOST_PARAMETER_FUNCTION_CAST(value, predicate) value

# else

// Handles possible implicit casts. Used by preprocessor.hpp to
// normalize user input.
//
// cast<void*>::execute() is identity
// cast<void*(X)>::execute() is identity
// cast<void(X)>::execute() casts to X
//
// preprocessor.hpp uses this like this:
//
//   #define X(value, predicate)
//      cast<void predicate>::execute(value)
//
//   X(something, *)
//   X(something, *(predicate))
//   X(something, (int))

template <class T>
struct cast;

template <>
struct cast<void*>
{
    static use_default_tag execute(use_default_tag)
    {
        return use_default_tag();
    }

    static use_default_tag remove_const(use_default_tag)
    {
        return use_default_tag();
    }

    template <class U>
    static U& execute(U& value)
    {
        return value;
    }

    template <class U>
    static U& remove_const(U& x)
    {
        return x;
    }
};

#if STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x580))

typedef void* voidstar;

template <class T>
struct cast<voidstar(T)>
  : cast<void*>
{
};

#else

template <class T>
struct cast<void*(T)>
  : cast<void*>
{
};

#endif

template <class T>
struct cast<void(T)>
{
    typedef typename streams_boost::add_reference<
        typename streams_boost::remove_const<T>::type 
    >::type reference;

    static use_default_tag execute(use_default_tag)
    {
        return use_default_tag();
    }

    static use_default_tag remove_const(use_default_tag)
    {
        return use_default_tag();
    }

    static T execute(T value)
    {
        return value;
    }

    template <class U>
    static reference remove_const(U const& x)
    {
        return const_cast<reference>(x);
    }
};

#  define STREAMS_BOOST_PARAMETER_FUNCTION_CAST(value, predicate) \
    streams_boost::parameter::aux::cast<void predicate>::remove_const( \
        streams_boost::parameter::aux::cast<void predicate>::execute(value) \
    )

# endif

}}} // namespace streams_boost::parameter::aux

#endif // STREAMS_BOOST_PARAMETER_CAST_060902_HPP

