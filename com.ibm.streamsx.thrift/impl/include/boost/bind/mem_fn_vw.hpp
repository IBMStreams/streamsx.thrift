//
//  bind/mem_fn_vw.hpp - void return helper wrappers
//
//  Do not include this header directly
//
//  Copyright (c) 2001 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
//
//  See http://www.streams_boost.org/libs/bind/mem_fn.html for documentation.
//

template<class R, class T> struct STREAMS_BOOST_MEM_FN_NAME(mf0): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf0)<R, T, R (STREAMS_BOOST_MEM_FN_CC T::*) ()>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) ();
    explicit STREAMS_BOOST_MEM_FN_NAME(mf0)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf0)<R, T, F>(f) {}
};

template<class R, class T> struct STREAMS_BOOST_MEM_FN_NAME(cmf0): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf0)<R, T, R (STREAMS_BOOST_MEM_FN_CC T::*) () const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) () const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf0)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf0)<R, T, F>(f) {}
};


template<class R, class T, class A1> struct STREAMS_BOOST_MEM_FN_NAME(mf1): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf1)<R, T, A1, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf1)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf1)<R, T, A1, F>(f) {}
};

template<class R, class T, class A1> struct STREAMS_BOOST_MEM_FN_NAME(cmf1): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf1)<R, T, A1, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf1)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf1)<R, T, A1, F>(f) {}
};


template<class R, class T, class A1, class A2> struct STREAMS_BOOST_MEM_FN_NAME(mf2): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf2)<R, T, A1, A2, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf2)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf2)<R, T, A1, A2, F>(f) {}
};

template<class R, class T, class A1, class A2> struct STREAMS_BOOST_MEM_FN_NAME(cmf2): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf2)<R, T, A1, A2, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf2)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf2)<R, T, A1, A2, F>(f) {}
};


template<class R, class T, class A1, class A2, class A3> struct STREAMS_BOOST_MEM_FN_NAME(mf3): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf3)<R, T, A1, A2, A3, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf3)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf3)<R, T, A1, A2, A3, F>(f) {}
};

template<class R, class T, class A1, class A2, class A3> struct STREAMS_BOOST_MEM_FN_NAME(cmf3): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf3)<R, T, A1, A2, A3, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf3)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf3)<R, T, A1, A2, A3, F>(f) {}
};


template<class R, class T, class A1, class A2, class A3, class A4> struct STREAMS_BOOST_MEM_FN_NAME(mf4): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf4)<R, T, A1, A2, A3, A4, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf4)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf4)<R, T, A1, A2, A3, A4, F>(f) {}
};

template<class R, class T, class A1, class A2, class A3, class A4> struct STREAMS_BOOST_MEM_FN_NAME(cmf4): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf4)<R, T, A1, A2, A3, A4, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf4)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf4)<R, T, A1, A2, A3, A4, F>(f) {}
};


template<class R, class T, class A1, class A2, class A3, class A4, class A5> struct STREAMS_BOOST_MEM_FN_NAME(mf5): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf5)<R, T, A1, A2, A3, A4, A5, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf5)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf5)<R, T, A1, A2, A3, A4, A5, F>(f) {}
};

template<class R, class T, class A1, class A2, class A3, class A4, class A5> struct STREAMS_BOOST_MEM_FN_NAME(cmf5): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf5)<R, T, A1, A2, A3, A4, A5, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf5)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf5)<R, T, A1, A2, A3, A4, A5, F>(f) {}
};


template<class R, class T, class A1, class A2, class A3, class A4, class A5, class A6> struct STREAMS_BOOST_MEM_FN_NAME(mf6): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf6)<R, T, A1, A2, A3, A4, A5, A6, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5, A6)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5, A6);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf6)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf6)<R, T, A1, A2, A3, A4, A5, A6, F>(f) {}
};

template<class R, class T, class A1, class A2, class A3, class A4, class A5, class A6> struct STREAMS_BOOST_MEM_FN_NAME(cmf6): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf6)<R, T, A1, A2, A3, A4, A5, A6, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5, A6) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5, A6) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf6)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf6)<R, T, A1, A2, A3, A4, A5, A6, F>(f) {}
};


template<class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7> struct STREAMS_BOOST_MEM_FN_NAME(mf7): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf7)<R, T, A1, A2, A3, A4, A5, A6, A7, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5, A6, A7)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5, A6, A7);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf7)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf7)<R, T, A1, A2, A3, A4, A5, A6, A7, F>(f) {}
};

template<class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7> struct STREAMS_BOOST_MEM_FN_NAME(cmf7): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf7)<R, T, A1, A2, A3, A4, A5, A6, A7, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5, A6, A7) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5, A6, A7) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf7)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf7)<R, T, A1, A2, A3, A4, A5, A6, A7, F>(f) {}
};


template<class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8> struct STREAMS_BOOST_MEM_FN_NAME(mf8): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf8)<R, T, A1, A2, A3, A4, A5, A6, A7, A8, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5, A6, A7, A8)>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5, A6, A7, A8);
    explicit STREAMS_BOOST_MEM_FN_NAME(mf8)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(mf8)<R, T, A1, A2, A3, A4, A5, A6, A7, A8, F>(f) {}
};

template<class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8> struct STREAMS_BOOST_MEM_FN_NAME(cmf8): public mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf8)<R, T, A1, A2, A3, A4, A5, A6, A7, A8, R (STREAMS_BOOST_MEM_FN_CC T::*) (A1, A2, A3, A4, A5, A6, A7, A8) const>
{
    typedef R (STREAMS_BOOST_MEM_FN_CC T::*F) (A1, A2, A3, A4, A5, A6, A7, A8) const;
    explicit STREAMS_BOOST_MEM_FN_NAME(cmf8)(F f): mf<R>::STREAMS_BOOST_NESTED_TEMPLATE STREAMS_BOOST_MEM_FN_NAME2(cmf8)<R, T, A1, A2, A3, A4, A5, A6, A7, A8, F>(f) {}
};

