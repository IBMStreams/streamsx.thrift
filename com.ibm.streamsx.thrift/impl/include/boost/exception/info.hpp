//Copyright (c) 2006-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_UUID_8D22C4CA9CC811DCAA9133D256D89593
#define STREAMS_UUID_8D22C4CA9CC811DCAA9133D256D89593
#if defined(__GNUC__) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma GCC system_header
#endif
#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(push,1)
#endif

#include <streams_boost/exception/exception.hpp>
#include <streams_boost/exception/to_string_stub.hpp>
#include <streams_boost/exception/detail/error_info_impl.hpp>
#include <streams_boost/shared_ptr.hpp>
#include <streams_boost/config.hpp>
#include <map>

namespace
streams_boost
    {
    template <class Tag,class T>
    inline
    typename enable_if<has_to_string<T>,std::string>::type
    to_string( error_info<Tag,T> const & x )
        {
        return to_string(x.value());
        }

    template <class Tag,class T>
    inline
    error_info<Tag,T>::
    error_info( value_type const & value ):
        value_(value)
        {
        }

    template <class Tag,class T>
    inline
    error_info<Tag,T>::
    ~error_info() throw()
        {
        }

    template <class Tag,class T>
    inline
    char const *
    error_info<Tag,T>::
    tag_typeid_name() const
        {
        return tag_type_name<Tag>();
        }

    template <class Tag,class T>
    inline
    std::string
    error_info<Tag,T>::
    value_as_string() const
        {
        return to_string_stub(*this);
        }

    namespace
    exception_detail
        {
        class
        error_info_container_impl:
            public error_info_container
            {
            public:

            error_info_container_impl():
                count_(0)
                {
                }

            ~error_info_container_impl() throw()
                {
                }

            void
            set( shared_ptr<error_info_base> const & x, type_info_ const & typeid_ )
                {
                STREAMS_BOOST_ASSERT(x);
                info_[typeid_] = x;
                diagnostic_info_str_.clear();
                }

            shared_ptr<error_info_base>
            get( type_info_ const & ti ) const
                {
                error_info_map::const_iterator i=info_.find(ti);
                if( info_.end()!=i )
                    {
                    shared_ptr<error_info_base> const & p = i->second;
#ifndef STREAMS_BOOST_NO_RTTI
                    STREAMS_BOOST_ASSERT( STREAMS_BOOST_EXCEPTION_DYNAMIC_TYPEID(*p).type_==ti.type_ );
#endif
                    return p;
                    }
                return shared_ptr<error_info_base>();
                }

            char const *
            diagnostic_information( char const * header ) const
                {
                if( header )
                    {
                    STREAMS_BOOST_ASSERT(*header!=0);
                    std::ostringstream tmp;
                    tmp << header;
                    for( error_info_map::const_iterator i=info_.begin(),end=info_.end(); i!=end; ++i )
                        {
                        shared_ptr<error_info_base const> const & x = i->second;
                        tmp << '[' << x->tag_typeid_name() << "] = " << x->value_as_string() << '\n';
                        }
                    tmp.str().swap(diagnostic_info_str_);
                    }
                return diagnostic_info_str_.c_str();
                }

            private:

            friend class streams_boost::exception;

            typedef std::map< type_info_, shared_ptr<error_info_base> > error_info_map;
            error_info_map info_;
            mutable std::string diagnostic_info_str_;
            mutable int count_;

            void
            add_ref() const
                {
                ++count_;
                }

            void
            release() const
                {
                if( !--count_ )
                    delete this;
                }
            };
        }

    template <class E,class Tag,class T>
    inline
    E const &
    operator<<( E const & x, error_info<Tag,T> const & v )
        {
        typedef error_info<Tag,T> error_info_tag_t;
        shared_ptr<error_info_tag_t> p( new error_info_tag_t(v) );
        exception_detail::error_info_container * c=x.data_.get();
        if( !c )
            x.data_.adopt(c=new exception_detail::error_info_container_impl);
        c->set(p,STREAMS_BOOST_EXCEPTION_STATIC_TYPEID(error_info_tag_t));
        return x;
        }
    }

#if defined(_MSC_VER) && !defined(STREAMS_BOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(pop)
#endif
#endif
