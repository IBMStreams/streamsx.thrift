/*=============================================================================
    Copyright (c) 2003 Joel de Guzman
    http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(STREAMS_BOOST_SPIRIT_SAFE_BOOL_HPP)
#define STREAMS_BOOST_SPIRIT_SAFE_BOOL_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/spirit/home/classic/namespace.hpp>

namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    namespace impl
    {
        template <typename T>
        struct no_base {};

        template <typename T>
        struct safe_bool_impl
        {
#if STREAMS_BOOST_WORKAROUND(__MWERKS__, STREAMS_BOOST_TESTED_AT(0x3003))
            void stub(T*) {};
            typedef void (safe_bool_impl::*type)(T*);
#else
            typedef T* TP; // workaround to make parsing easier
            TP stub;
            typedef TP safe_bool_impl::*type;
#endif
        };
    }

    template <typename DerivedT, typename BaseT = impl::no_base<DerivedT> >
    struct safe_bool : BaseT
    {
    private:
        typedef impl::safe_bool_impl<DerivedT> impl_t;
        typedef typename impl_t::type bool_type;

    public:
        operator bool_type() const
        {
            return static_cast<const DerivedT*>(this)->operator_bool() ?
                &impl_t::stub : 0;
        }

        operator bool_type()
        {
            return static_cast<DerivedT*>(this)->operator_bool() ?
                &impl_t::stub : 0;
        }
    };

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}}

#endif

