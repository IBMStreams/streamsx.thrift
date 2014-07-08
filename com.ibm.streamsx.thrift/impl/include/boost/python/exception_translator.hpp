// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef EXCEPTION_TRANSLATOR_DWA2002810_STREAMS_HPP
# define EXCEPTION_TRANSLATOR_DWA2002810_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/bind.hpp>
# include <streams_boost/type.hpp>
# include <streams_boost/python/detail/translate_exception.hpp>
# include <streams_boost/python/detail/exception_handler.hpp>

namespace streams_boost { namespace python { 

template <class ExceptionType, class Translate>
void register_exception_translator(Translate translate, streams_boost::type<ExceptionType>* = 0)
{
    detail::register_exception_handler(
        bind<bool>(detail::translate_exception<ExceptionType,Translate>(), _1, _2, translate)
        );
}

}} // namespace streams_boost::python

#endif // EXCEPTION_TRANSLATOR_DWA2002810_STREAMS_HPP
