// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef OBJECT_PROTOCOL_DWA2002615_STREAMS_HPP
# define OBJECT_PROTOCOL_DWA2002615_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/object_protocol_core.hpp>
# include <streams_boost/python/object_core.hpp>

# include <streams_boost/detail/workaround.hpp>

namespace streams_boost { namespace python { namespace api {

# if STREAMS_BOOST_WORKAROUND(__SUNPRO_CC, STREAMS_BOOST_TESTED_AT(0x590))
// attempt to use SFINAE to prevent functions accepting T const& from
// coming up as ambiguous with the one taking a char const* when a
// string literal is passed
#  define STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(T)             , T (*)() = 0
# else 
#  define STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(T) 
# endif

template <class Target, class Key>
object getattr(Target const& target, Key const& key STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    return getattr(object(target), object(key));
}

template <class Target, class Key, class Default>
object getattr(Target const& target, Key const& key, Default const& default_ STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    return getattr(object(target), object(key), object(default_));
}


template <class Key, class Value>
void setattr(object const& target, Key const& key, Value const& value STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    setattr(target, object(key), object(value));
}

template <class Key>
void delattr(object const& target, Key const& key STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    delattr(target, object(key));
}

template <class Target, class Key>
object getitem(Target const& target, Key const& key STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    return getitem(object(target), object(key));
}


template <class Key, class Value>
void setitem(object const& target, Key const& key, Value const& value STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    setitem(target, object(key), object(value));
}

template <class Key>
void delitem(object const& target, Key const& key STREAMS_BOOST_PYTHON_NO_ARRAY_ARG(Key))
{
    delitem(target, object(key));
}

template <class Target, class Begin, class End>
object getslice(Target const& target, Begin const& begin, End const& end)
{
    return getslice(object(target), object(begin), object(end));
}

template <class Begin, class End, class Value>
void setslice(object const& target, Begin const& begin, End const& end, Value const& value)
{
    setslice(target, object(begin), object(end), object(value));
}

template <class Begin, class End>
void delslice(object const& target, Begin const& begin, End const& end)
{
    delslice(target, object(begin), object(end));
}

}}} // namespace streams_boost::python::api

#endif // OBJECT_PROTOCOL_DWA2002615_STREAMS_HPP
