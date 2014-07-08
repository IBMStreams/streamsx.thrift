// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef SHARED_PTR_DELETER_DWA2002121_STREAMS_HPP
# define SHARED_PTR_DELETER_DWA2002121_STREAMS_HPP

namespace streams_boost { namespace python { namespace converter { 

struct STREAMS_BOOST_PYTHON_DECL shared_ptr_deleter
{
    shared_ptr_deleter(handle<> owner);
    ~shared_ptr_deleter();

    void operator()(void const*);
        
    handle<> owner;
};

}}} // namespace streams_boost::python::converter

#endif // SHARED_PTR_DELETER_DWA2002121_STREAMS_HPP
