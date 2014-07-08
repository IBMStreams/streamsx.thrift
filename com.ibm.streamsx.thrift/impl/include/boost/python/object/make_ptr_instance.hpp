// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef MAKE_PTR_INSTANCE_DWA200296_STREAMS_HPP
# define MAKE_PTR_INSTANCE_DWA200296_STREAMS_HPP

# include <streams_boost/python/object/make_instance.hpp>
# include <streams_boost/python/converter/registry.hpp>
# include <streams_boost/type_traits/is_polymorphic.hpp>
# include <streams_boost/get_pointer.hpp>
# include <streams_boost/detail/workaround.hpp>
# include <typeinfo>

namespace streams_boost { namespace python { namespace objects { 

template <class T, class Holder>
struct make_ptr_instance
    : make_instance_impl<T, Holder, make_ptr_instance<T,Holder> >
{
    template <class Arg>
    static inline Holder* construct(void* storage, PyObject*, Arg& x)
    {
        return new (storage) Holder(x);
    }
    
    template <class Ptr>
    static inline PyTypeObject* get_class_object(Ptr const& x)
    {
        return get_class_object_impl(get_pointer(x));
    }
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
    static inline PyTypeObject const* get_pytype()
    {
        return converter::registered<T>::converters.get_class_object();
    }
#endif
 private:
    template <class U>
    static inline PyTypeObject* get_class_object_impl(U const volatile* p)
    {
        if (p == 0)
            return 0; // means "return None".

        PyTypeObject* derived = get_derived_class_object(
            STREAMS_BOOST_DEDUCED_TYPENAME is_polymorphic<U>::type(), p);
        
        if (derived)
            return derived;
        return converter::registered<T>::converters.get_class_object();
    }
    
    template <class U>
    static inline PyTypeObject* get_derived_class_object(mpl::true_, U const volatile* x)
    {
        converter::registration const* r = converter::registry::query(
            type_info(typeid(*get_pointer(x)))
        );
        return r ? r->m_class_object : 0;
    }
    
    template <class U>
    static inline PyTypeObject* get_derived_class_object(mpl::false_, U*)
    {
        return 0;
    }
};
  

}}} // namespace streams_boost::python::object

#endif // MAKE_PTR_INSTANCE_DWA200296_STREAMS_HPP
