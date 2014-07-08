//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_C3E1741C754311DDB2834CCA55D89593
#define STREAMS_UUID_C3E1741C754311DDB2834CCA55D89593
#if defined(__GNUC__) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma GCC system_header
#endif
#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(push,1)
#endif

#include <streams_boost/detail/sp_typeinfo.hpp>
#include <streams_boost/current_function.hpp>
#include <streams_boost/config.hpp>

namespace
streams_boost
    {
    template <class T>
    inline
    char const *
    tag_type_name()
        {
#ifdef STREAMS_BOOST_NO_TYPEID
        return STREAMS_BOOST_CURRENT_FUNCTION;
#else
        return typeid(T*).name();
#endif
        }

    template <class T>
    inline
    char const *
    type_name()
        {
#ifdef STREAMS_BOOST_NO_TYPEID
        return STREAMS_BOOST_CURRENT_FUNCTION;
#else
        return typeid(T).name();
#endif
        }

    namespace
    exception_detail
        {
        struct
        type_info_
            {
            detail::sp_typeinfo const & type_;

            explicit
            type_info_( detail::sp_typeinfo const & type ):
                type_(type)
                {
                }

            friend
            bool
            operator<( type_info_ const & a, type_info_ const & b )
                {
                return 0!=(a.type_.before(b.type_));
                }
            };
        }
    }

#define STREAMS_BOOST_EXCEPTION_STATIC_TYPEID(T) ::streams_boost::exception_detail::type_info_(STREAMS_BOOST_SP_TYPEID(T))

#ifndef STREAMS_BOOST_NO_RTTI
#define STREAMS_BOOST_EXCEPTION_DYNAMIC_TYPEID(x) ::streams_boost::exception_detail::type_info_(typeid(x))
#endif

#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(pop)
#endif
#endif
