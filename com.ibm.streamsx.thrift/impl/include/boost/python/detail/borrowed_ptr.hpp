#ifndef BORROWED_PTR_DWA20020601_STREAMS_HPP
# define BORROWED_PTR_DWA20020601_STREAMS_HPP
// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

# include <streams_boost/config.hpp>
# include <streams_boost/type.hpp>
# include <streams_boost/mpl/if.hpp>
# include <streams_boost/type_traits/object_traits.hpp>
# include <streams_boost/type_traits/cv_traits.hpp>
# include <streams_boost/python/tag.hpp>

namespace streams_boost { namespace python { namespace detail {

template<class T> class borrowed
{ 
    typedef T type;
};

# ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
template<typename T>
struct is_borrowed_ptr
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false); 
};

#  if !defined(__MWERKS__) || __MWERKS__ > 0x3000
template<typename T>
struct is_borrowed_ptr<borrowed<T>*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};

template<typename T>
struct is_borrowed_ptr<borrowed<T> const*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};

template<typename T>
struct is_borrowed_ptr<borrowed<T> volatile*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};

template<typename T>
struct is_borrowed_ptr<borrowed<T> const volatile*>
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};
#  else
template<typename T>
struct is_borrowed
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
};
template<typename T>
struct is_borrowed<borrowed<T> >
{
    STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
};
template<typename T>
struct is_borrowed_ptr<T*>
    : is_borrowed<typename remove_cv<T>::type>
{
};
#  endif 

# else // no partial specialization

typedef char (&yes_borrowed_ptr_t)[1];
typedef char (&no_borrowed_ptr_t)[2];

no_borrowed_ptr_t is_borrowed_ptr_test(...);

template <class T>
typename mpl::if_c<
    is_pointer<T>::value
    , T
    , int
    >::type
is_borrowed_ptr_test1(streams_boost::type<T>);

template<typename T>
yes_borrowed_ptr_t is_borrowed_ptr_test(borrowed<T> const volatile*);

template<typename T>
class is_borrowed_ptr
{
 public:
    STREAMS_BOOST_STATIC_CONSTANT(
        bool, value = (
            sizeof(detail::is_borrowed_ptr_test(is_borrowed_ptr_test1(streams_boost::type<T>())))
            == sizeof(detail::yes_borrowed_ptr_t)));
};

# endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}

template <class T>
inline T* get_managed_object(detail::borrowed<T> const volatile* p, tag_t)
{
    return (T*)p;
}

}} // namespace streams_boost::python::detail

#endif // #ifndef BORROWED_PTR_DWA20020601_STREAMS_HPP
