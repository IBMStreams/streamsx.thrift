#ifndef STREAMS_BOOST_BIND_MEM_FN_HPP_INCLUDED
#define STREAMS_BOOST_BIND_MEM_FN_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  mem_fn.hpp - a generalization of std::mem_fun[_ref]
//
//  Copyright (c) 2001, 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2001 David Abrahams
//  Copyright (c) 2003-2005 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  See http://www.streams_boost.org/libs/bind/mem_fn.html for documentation.
//

#include <streams_boost/config.hpp>
#include <streams_boost/get_pointer.hpp>
#include <streams_boost/detail/workaround.hpp>

namespace streams_boost
{

#if defined(STREAMS_BOOST_NO_VOID_RETURNS)

#define STREAMS_BOOST_MEM_FN_CLASS_F , class F
#define STREAMS_BOOST_MEM_FN_TYPEDEF(X)

namespace _mfi // mem_fun_impl
{

template<class V> struct mf
{

#define STREAMS_BOOST_MEM_FN_RETURN return

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X
#define STREAMS_BOOST_MEM_FN_CC

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_CDECL

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X##_cdecl
#define STREAMS_BOOST_MEM_FN_CC __cdecl

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_STDCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X##_stdcall
#define STREAMS_BOOST_MEM_FN_CC __stdcall

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_FASTCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X##_fastcall
#define STREAMS_BOOST_MEM_FN_CC __fastcall

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#undef STREAMS_BOOST_MEM_FN_RETURN

}; // struct mf<V>

template<> struct mf<void>
{

#define STREAMS_BOOST_MEM_FN_RETURN

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X
#define STREAMS_BOOST_MEM_FN_CC

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_CDECL

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X##_cdecl
#define STREAMS_BOOST_MEM_FN_CC __cdecl

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_STDCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X##_stdcall
#define STREAMS_BOOST_MEM_FN_CC __stdcall

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_FASTCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) inner_##X##_fastcall
#define STREAMS_BOOST_MEM_FN_CC __fastcall

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#undef STREAMS_BOOST_MEM_FN_RETURN

}; // struct mf<void>

#undef STREAMS_BOOST_MEM_FN_CLASS_F
#undef STREAMS_BOOST_MEM_FN_TYPEDEF_F

#define STREAMS_BOOST_MEM_FN_NAME(X) X
#define STREAMS_BOOST_MEM_FN_NAME2(X) inner_##X
#define STREAMS_BOOST_MEM_FN_CC

#include <streams_boost/bind/mem_fn_vw.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_NAME2
#undef STREAMS_BOOST_MEM_FN_CC

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_CDECL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_cdecl
#define STREAMS_BOOST_MEM_FN_NAME2(X) inner_##X##_cdecl
#define STREAMS_BOOST_MEM_FN_CC __cdecl

#include <streams_boost/bind/mem_fn_vw.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_NAME2
#undef STREAMS_BOOST_MEM_FN_CC

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_STDCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_stdcall
#define STREAMS_BOOST_MEM_FN_NAME2(X) inner_##X##_stdcall
#define STREAMS_BOOST_MEM_FN_CC __stdcall

#include <streams_boost/bind/mem_fn_vw.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_NAME2
#undef STREAMS_BOOST_MEM_FN_CC

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_FASTCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_fastcall
#define STREAMS_BOOST_MEM_FN_NAME2(X) inner_##X##_fastcall
#define STREAMS_BOOST_MEM_FN_CC __fastcall

#include <streams_boost/bind/mem_fn_vw.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_NAME2
#undef STREAMS_BOOST_MEM_FN_CC

#endif

} // namespace _mfi

#else // #ifdef STREAMS_BOOST_NO_VOID_RETURNS

#define STREAMS_BOOST_MEM_FN_CLASS_F
#define STREAMS_BOOST_MEM_FN_TYPEDEF(X) typedef X;

namespace _mfi
{

#define STREAMS_BOOST_MEM_FN_RETURN return

#define STREAMS_BOOST_MEM_FN_NAME(X) X
#define STREAMS_BOOST_MEM_FN_CC

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_CDECL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_cdecl
#define STREAMS_BOOST_MEM_FN_CC __cdecl

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_STDCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_stdcall
#define STREAMS_BOOST_MEM_FN_CC __stdcall

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_FASTCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_fastcall
#define STREAMS_BOOST_MEM_FN_CC __fastcall

#include <streams_boost/bind/mem_fn_template.hpp>

#undef STREAMS_BOOST_MEM_FN_CC
#undef STREAMS_BOOST_MEM_FN_NAME

#endif

#undef STREAMS_BOOST_MEM_FN_RETURN

} // namespace _mfi

#undef STREAMS_BOOST_MEM_FN_CLASS_F
#undef STREAMS_BOOST_MEM_FN_TYPEDEF

#endif // #ifdef STREAMS_BOOST_NO_VOID_RETURNS

#define STREAMS_BOOST_MEM_FN_NAME(X) X
#define STREAMS_BOOST_MEM_FN_CC

#include <streams_boost/bind/mem_fn_cc.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_CC

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_CDECL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_cdecl
#define STREAMS_BOOST_MEM_FN_CC __cdecl

#include <streams_boost/bind/mem_fn_cc.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_CC

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_STDCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_stdcall
#define STREAMS_BOOST_MEM_FN_CC __stdcall

#include <streams_boost/bind/mem_fn_cc.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_CC

#endif

#ifdef STREAMS_BOOST_MEM_FN_ENABLE_FASTCALL

#define STREAMS_BOOST_MEM_FN_NAME(X) X##_fastcall
#define STREAMS_BOOST_MEM_FN_CC __fastcall

#include <streams_boost/bind/mem_fn_cc.hpp>

#undef STREAMS_BOOST_MEM_FN_NAME
#undef STREAMS_BOOST_MEM_FN_CC

#endif

// data member support

namespace _mfi
{

template<class R, class T> class dm
{
public:

    typedef R const & result_type;
    typedef T const * argument_type;

private:
    
    typedef R (T::*F);
    F f_;

    template<class U> R const & call(U & u, T const *) const
    {
        return (u.*f_);
    }

    template<class U> R const & call(U & u, void const *) const
    {
        return (get_pointer(u)->*f_);
    }

public:
    
    explicit dm(F f): f_(f) {}

    R & operator()(T * p) const
    {
        return (p->*f_);
    }

    R const & operator()(T const * p) const
    {
        return (p->*f_);
    }

    template<class U> R const & operator()(U const & u) const
    {
        return call(u, &u);
    }

#if !STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300) && !STREAMS_BOOST_WORKAROUND(__MWERKS__, < 0x3200)

    R & operator()(T & t) const
    {
        return (t.*f_);
    }

    R const & operator()(T const & t) const
    {
        return (t.*f_);
    }

#endif

    bool operator==(dm const & rhs) const
    {
        return f_ == rhs.f_;
    }

    bool operator!=(dm const & rhs) const
    {
        return f_ != rhs.f_;
    }
};

} // namespace _mfi

template<class R, class T> _mfi::dm<R, T> mem_fn(R T::*f)
{
    return _mfi::dm<R, T>(f);
}

} // namespace streams_boost

#endif // #ifndef STREAMS_BOOST_BIND_MEM_FN_HPP_INCLUDED
