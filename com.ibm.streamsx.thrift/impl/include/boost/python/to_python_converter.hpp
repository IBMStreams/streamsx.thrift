// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef TO_PYTHON_CONVERTER_DWA200221_STREAMS_HPP
# define TO_PYTHON_CONVERTER_DWA200221_STREAMS_HPP

# include <streams_boost/python/detail/prefix.hpp>

# include <streams_boost/python/converter/registry.hpp>
# include <streams_boost/python/converter/as_to_python_function.hpp>
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
# include <streams_boost/python/converter/pytype_function.hpp>
#endif
# include <streams_boost/python/type_id.hpp>

namespace streams_boost { namespace python { 

#if 0 //get_pytype member detection
namespace detail
{
    typedef char yes_type;
    typedef struct {char a[2]; } no_type;
    template<PyTypeObject const * (*f)()> struct test_get_pytype1 { };
    template<PyTypeObject * (*f)()>          struct test_get_pytype2 { };

    template<class T> yes_type tester(test_get_pytype1<&T::get_pytype>*);

    template<class T> yes_type tester(test_get_pytype2<&T::get_pytype>*);

    template<class T> no_type tester(...);

    template<class T>
    struct test_get_pytype_base  
    {
        STREAMS_BOOST_STATIC_CONSTANT(bool, value= (sizeof(detail::tester<T>(0)) == sizeof(yes_type)));
    };

    template<class T>
    struct test_get_pytype : streams_boost::mpl::bool_<test_get_pytype_base<T>::value> 
    {
    };

}
#endif

template < class T, class Conversion, bool has_get_pytype=false >
struct to_python_converter 
{
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
#if 0 //defined _MSC_VER && _MSC_VER >=1310
    //probably other compilers could come here as well
    typedef typename detail::test_get_pytype<Conversion> HasGetPytype;
#else
    typedef streams_boost::mpl::bool_<has_get_pytype> HasGetPytype;
#endif

    static PyTypeObject const* get_pytype_1(streams_boost::mpl::true_ *)
    {
        return Conversion::get_pytype();
    }

    static PyTypeObject const* get_pytype_1(streams_boost::mpl::false_ *)
    {
        return 0;
    }
    static PyTypeObject const* get_pytype_impl()
    {
        return get_pytype_1((HasGetPytype*)0);
    }
#endif
    
    to_python_converter();
};

//
// implementation
//

template <class T, class Conversion ,bool has_get_pytype>
to_python_converter<T,Conversion, has_get_pytype>::to_python_converter()
{
    typedef converter::as_to_python_function<
        T, Conversion
        > normalized;
            
    converter::registry::insert(
        &normalized::convert
        , type_id<T>()
#ifndef STREAMS_BOOST_PYTHON_NO_PY_SIGNATURES
        , &get_pytype_impl
#endif
        );
}

}} // namespace streams_boost::python

#endif // TO_PYTHON_CONVERTER_DWA200221_STREAMS_HPP

