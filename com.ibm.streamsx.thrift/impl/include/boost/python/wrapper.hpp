// Copyright David Abrahams 2004. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef WRAPPER_DWA2004720_STREAMS_HPP
# define WRAPPER_DWA2004720_STREAMS_HPP

# include <streams_boost/python/detail/wrapper_base.hpp>
# include <streams_boost/python/override.hpp>
# include <streams_boost/python/converter/registered.hpp>
# include <streams_boost/python/detail/sfinae.hpp>

namespace streams_boost { namespace python { 

template <class T>
class wrapper : public detail::wrapper_base
{
 public:
    // Do not touch this implementation detail!
    typedef T _wrapper_wrapped_type_;

 protected:
    override get_override(char const* name) const
    {
        typedef detail::wrapper_base base;
        converter::registration const& r
            = converter::registered<T>::converters;
        PyTypeObject* type = r.get_class_object();
        
        return this->base::get_override(name, type);
    }
};

}} // namespace streams_boost::python

#endif // WRAPPER_DWA2004720_STREAMS_HPP
