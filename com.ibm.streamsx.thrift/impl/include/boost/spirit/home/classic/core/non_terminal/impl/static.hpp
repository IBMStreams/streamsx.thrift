/*=============================================================================
    Copyright (c) 2006 Joao Abecasis
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_STATIC_HPP)
#define STREAMS_BOOST_SPIRIT_STATIC_HPP

#include <streams_boost/noncopyable.hpp>
#include <streams_boost/call_traits.hpp>
#include <streams_boost/aligned_storage.hpp>

#include <streams_boost/type_traits/add_pointer.hpp>
#include <streams_boost/type_traits/alignment_of.hpp>

#include <streams_boost/thread/once.hpp>

#include <memory>   // for placement new

#include <streams_boost/spirit/home/classic/namespace.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    //
    //  Provides thread-safe initialization of a single static instance of T.
    //
    //  This instance is guaranteed to be constructed on static storage in a
    //  thread-safe manner, on the first call to the constructor of static_.
    //
    //  Requirements:
    //      T is default constructible
    //          (There's an alternate implementation that relaxes this
    //              requirement -- Joao Abecasis)
    //      T::T() MUST not throw!
    //          this is a requirement of streams_boost::call_once.
    //
    template <class T, class Tag>
    struct static_
        : streams_boost::noncopyable
    {
    private:

        struct destructor
        {
            ~destructor()
            {
                static_::get_address()->~value_type();
            }
        };

        struct default_ctor
        {
            static void construct()
            {
                ::new (static_::get_address()) value_type();
                static destructor d;
            }
        };

    public:

        typedef T value_type;
        typedef typename streams_boost::call_traits<T>::reference reference;
        typedef typename streams_boost::call_traits<T>::const_reference const_reference;

        static_(Tag = Tag())
        {
            streams_boost::call_once(&default_ctor::construct, constructed_);
        }

        operator reference()
        {
            return this->get();
        }

        operator const_reference() const
        {
            return this->get();
        }

        reference get()
        {
            return *this->get_address();
        }

        const_reference get() const
        {
            return *this->get_address();
        }

    private:
        typedef typename streams_boost::add_pointer<value_type>::type pointer;

        static pointer get_address()
        {
            return static_cast<pointer>(data_.address());
        }

        typedef streams_boost::aligned_storage<sizeof(value_type),
            streams_boost::alignment_of<value_type>::value> storage_type;

        static storage_type data_;
        static once_flag constructed_;
    };

    template <class T, class Tag>
    typename static_<T, Tag>::storage_type static_<T, Tag>::data_;

    template <class T, class Tag>
    once_flag static_<T, Tag>::constructed_ = STREAMS_BOOST_ONCE_INIT;

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace STREAMS_BOOST_SPIRIT_CLASSIC_NS

#endif // include guard
