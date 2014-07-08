//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_E788439ED9F011DCB181F25B55D89593
#define STREAMS_UUID_E788439ED9F011DCB181F25B55D89593
#if defined(__GNUC__) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma GCC system_header
#endif
#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(push,1)
#endif

#include <streams_boost/exception/to_string.hpp>
#include <streams_boost/exception/detail/object_hex_dump.hpp>
#include <streams_boost/assert.hpp>

namespace
streams_boost
    {
    namespace
    exception_detail
        {
        template <bool ToStringAvailable>
        struct
        to_string_dispatcher
            {
            template <class T,class Stub>
            static
            std::string
            convert( T const & x, Stub )
                {
                return to_string(x);
                }
            };

        template <>
        struct
        to_string_dispatcher<false>
            {
            template <class T,class Stub>
            static
            std::string
            convert( T const & x, Stub s )
                {
                return s(x);
                }

            template <class T>
            static
            std::string
            convert( T const & x, std::string s )
                {
                return s;
                }

            template <class T>
            static
            std::string
            convert( T const & x, char const * s )
                {
                STREAMS_BOOST_ASSERT(s!=0);
                return s;
                }
            };

        namespace
        to_string_dispatch
            {
            template <class T,class Stub>
            inline
            std::string
            dispatch( T const & x, Stub s )
                {
                return to_string_dispatcher<has_to_string<T>::value>::convert(x,s);
                }
            }

        template <class T>
        inline
        std::string
        string_stub_dump( T const & x )
            {
            return "[ " + exception_detail::object_hex_dump(x) + " ]";
            }
        }

    template <class T>
    inline
    std::string
    to_string_stub( T const & x )
        {
        return exception_detail::to_string_dispatch::dispatch(x,&exception_detail::string_stub_dump<T>);
        }

    template <class T,class Stub>
    inline
    std::string
    to_string_stub( T const & x, Stub s )
        {
        return exception_detail::to_string_dispatch::dispatch(x,s);
        }
    }

#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(pop)
#endif
#endif
