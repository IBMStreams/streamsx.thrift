#ifndef STREAMS_BOOST_SMART_PTR_MAKE_SHARED_HPP_INCLUDED
#define STREAMS_BOOST_SMART_PTR_MAKE_SHARED_HPP_INCLUDED

//  make_shared.hpp
//
//  Copyright (c) 2007, 2008 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt
//
//  See http://www.streams_boost.org/libs/smart_ptr/make_shared.html
//  for documentation.

#include <streams_boost/config.hpp>
#include <streams_boost/smart_ptr/shared_ptr.hpp>
#include <streams_boost/type_traits/type_with_alignment.hpp>
#include <streams_boost/type_traits/alignment_of.hpp>
#include <cstddef>
#include <new>

namespace streams_boost
{

namespace detail
{

template< std::size_t N, std::size_t A > struct sp_aligned_storage
{
    union type
    {
        char data_[ N ];
        typename streams_boost::type_with_alignment< A >::type align_;
    };
};

template< class T > class sp_ms_deleter
{
private:

    typedef typename sp_aligned_storage< sizeof( T ), ::streams_boost::alignment_of< T >::value >::type storage_type;

    bool initialized_;
    storage_type storage_;

private:

    void destroy()
    {
        if( initialized_ )
        {
            reinterpret_cast< T* >( storage_.data_ )->~T();
            initialized_ = false;
        }
    }

public:

    sp_ms_deleter(): initialized_( false )
    {
    }

    // optimization: do not copy storage_
    sp_ms_deleter( sp_ms_deleter const & ): initialized_( false )
    {
    }

    ~sp_ms_deleter()
    {
        destroy();
    }

    void operator()( T * )
    {
        destroy();
    }

    void * address()
    {
        return storage_.data_;
    }

    void set_initialized()
    {
        initialized_ = true;
    }
};

#if defined( STREAMS_BOOST_HAS_RVALUE_REFS )
template< class T > T&& forward( T &&t )
{
    return t;
}
#endif

} // namespace detail

// Zero-argument versions
//
// Used even when variadic templates are available because of the new T() vs new T issue

template< class T > streams_boost::shared_ptr< T > make_shared()
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T();
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A > streams_boost::shared_ptr< T > allocate_shared( A const & a )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T();
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

#if defined( STREAMS_BOOST_HAS_VARIADIC_TMPL ) && defined( STREAMS_BOOST_HAS_RVALUE_REFS )

// Variadic templates, rvalue reference

template< class T, class... Args > streams_boost::shared_ptr< T > make_shared( Args && ... args )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( detail::forward<Args>( args )... );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class... Args > streams_boost::shared_ptr< T > allocate_shared( A const & a, Args && ... args )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( detail::forward<Args>( args )... );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

#else

// C++03 version

template< class T, class A1 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9 >
streams_boost::shared_ptr< T > make_shared( A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8, A9 const & a9 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >() );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8, a9 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

template< class T, class A, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9 >
streams_boost::shared_ptr< T > allocate_shared( A const & a, A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4, A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8, A9 const & a9 )
{
    streams_boost::shared_ptr< T > pt( static_cast< T* >( 0 ), detail::sp_ms_deleter< T >(), a );

    detail::sp_ms_deleter< T > * pd = streams_boost::get_deleter< detail::sp_ms_deleter< T > >( pt );

    void * pv = pd->address();

    ::new( pv ) T( a1, a2, a3, a4, a5, a6, a7, a8, a9 );
    pd->set_initialized();

    T * pt2 = static_cast< T* >( pv );

    streams_boost::detail::sp_enable_shared_from_this( &pt, pt2, pt2 );
    return streams_boost::shared_ptr< T >( pt, pt2 );
}

#endif

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_SMART_PTR_MAKE_SHARED_HPP_INCLUDED
