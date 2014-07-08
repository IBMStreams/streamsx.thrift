/*=============================================================================
    Copyright (c) 2001-2003 Joel de Guzman
    http://spirit.sourceforge.net/

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef STREAMS_BOOST_SPIRIT_SYMBOLS_IPP
#define STREAMS_BOOST_SPIRIT_SYMBOLS_IPP

///////////////////////////////////////////////////////////////////////////////
#include <streams_boost/spirit/home/classic/symbols/impl/tst.ipp>
#include <streams_boost/detail/workaround.hpp>

// MSVC: void warning about the use of 'this' pointer in constructors
#if defined(STREAMS_BOOST_MSVC)
#pragma warning(push)
#pragma warning(disable : 4355)
#endif

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

///////////////////////////////////////////////////////////////////////////////
//
//  symbols class implementation
//
///////////////////////////////////////////////////////////////////////////////
template <typename T, typename CharT, typename SetT>
inline symbols<T, CharT, SetT>::symbols()
: SetT()
, add(*this)
{
}

//////////////////////////////////
template <typename T, typename CharT, typename SetT>
symbols<T, CharT, SetT>::symbols(symbols const& other)
: SetT(other)
// Tru64 CXX seems to be confused by the explicit call of the default
// constructor and generates wrong code which invalidates the just contructed
// first base class in the line above.
#if !STREAMS_BOOST_WORKAROUND(__DECCXX_VER, STREAMS_BOOST_TESTED_AT(60590041))
, parser<symbols<T, CharT, SetT> >()
#endif
, add(*this)
{
}

//////////////////////////////////
template <typename T, typename CharT, typename SetT>
inline symbols<T, CharT, SetT>::~symbols()
{}

//////////////////////////////////
template <typename T, typename CharT, typename SetT>
inline symbols<T, CharT, SetT>&
symbols<T, CharT, SetT>::operator=(symbols const& other)
{
    SetT::operator=(other);
    return *this;
}

//////////////////////////////////
template <typename T, typename CharT, typename SetT>
inline symbol_inserter<T, SetT> const&
symbols<T, CharT, SetT>::operator=(CharT const* str)
{
    return add, str;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Symbol table utilities
//
///////////////////////////////////////////////////////////////////////////////
template <typename T, typename CharT, typename SetT>
inline T*
find(symbols<T, CharT, SetT> const& table, CharT const* sym)
{
    CharT const* last = sym;
    while (*last)
        last++;
    scanner<CharT const *> scan(sym, last);
    T* result = table.find(scan);
    return scan.at_end()? result: 0;
}

//////////////////////////////////
template <typename T, typename CharT, typename SetT>
inline T*
add(symbols<T, CharT, SetT>& table, CharT const* sym, T const& data)
{
    CharT const* first = sym;
    CharT const* last = sym;
    while (*last)
        last++;
    scanner<CharT const *> scan(first, last);
    if (table.find(scan) && scan.at_end())
        return 0;               // symbol already contained in symbol table
    table.add(sym, last, data);
    first = sym;
    return table.find(scan);    // refind the inserted symbol
}

///////////////////////////////////////////////////////////////////////////////
STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace streams_boost::spirit

#if defined(STREAMS_BOOST_MSVC)
#pragma warning(pop)
#endif

#endif
