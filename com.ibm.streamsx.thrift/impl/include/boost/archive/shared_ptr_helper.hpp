#ifndef STREAMS_BOOST_ARCHIVE_SHARED_PTR_HELPER_HPP
#define STREAMS_BOOST_ARCHIVE_SHARED_PTR_HELPER_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// shared_ptr_helper.hpp: serialization for streams_boost shared pointer

// (C) Copyright 2004-2009 Robert Ramey, Martin Ecker and Takatoshi Kondo
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <set>
#include <list>
#include <utility>
#include <cstddef> // NULL

#include <streams_boost/config.hpp>
#include <streams_boost/shared_ptr.hpp>

#include <streams_boost/type_traits/is_polymorphic.hpp>
#include <streams_boost/serialization/type_info_implementation.hpp>
#include <streams_boost/serialization/shared_ptr_132.hpp>
#include <streams_boost/serialization/throw_exception.hpp>

#include <streams_boost/archive/archive_exception.hpp>
#include <streams_boost/archive/detail/decl.hpp>

#include <streams_boost/archive/detail/abi_prefix.hpp> // must be the last header

namespace streams_boost_132 {
    template<class T> class shared_ptr;
}
namespace streams_boost {
    template<class T> class shared_ptr;
    namespace serialization {
        class extended_type_info;
        template<class Archive, class T>
        inline void load(
            Archive & ar,
            streams_boost::shared_ptr<T> &t,
            const unsigned int file_version
        );
    }
namespace archive{
namespace detail {

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// a common class for holding various types of shared pointers

class shared_ptr_helper {
    struct collection_type_compare {
        bool operator()(
            const shared_ptr<const void> &lhs,
            const shared_ptr<const void> &rhs
        )const{
            return lhs.get() < rhs.get();
        }
    };
    typedef std::set<
        streams_boost::shared_ptr<const void>,
        collection_type_compare
    > collection_type;
    typedef collection_type::const_iterator iterator_type;
    // list of shared_pointers create accessable by raw pointer. This
    // is used to "match up" shared pointers loaded at different
    // points in the archive. Note, we delay construction until
    // it is actually used since this is by default included as
    // a "mix-in" even if shared_ptr isn't used.
    collection_type * m_pointers;

    struct null_deleter {
        void operator()(void const *) const {}
    };

    struct void_deleter {
        const streams_boost::serialization::extended_type_info * m_eti;
        void_deleter(const streams_boost::serialization::extended_type_info *eti) :
            m_eti(eti)
        {}
        void operator()(void *vp) const {
            m_eti->destroy(vp);
        }
    };

#ifdef STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    template<class Archive, class T>
    friend inline void streams_boost::serialization::load(
        Archive & ar,
        streams_boost::shared_ptr<T> &t,
        const unsigned int file_version
    );
#endif

//  #ifdef STREAMS_BOOST_SERIALIZATION_SHARED_PTR_132_HPP
    // list of loaded pointers.  This is used to be sure that the pointers
    // stay around long enough to be "matched" with other pointers loaded
    // by the same archive.  These are created with a "null_deleter" so that
    // when this list is destroyed - the underlaying raw pointers are not
    // destroyed.  This has to be done because the pointers are also held by
    // new system which is disjoint from this set.  This is implemented
    // by a change in load_construct_data below.  It makes this file suitable
    // only for loading pointers into a 1.33 or later streams_boost system.
    std::list<streams_boost_132::shared_ptr<void> > * m_pointers_132;
//  #endif

    // returns pointer to object and an indicator whether this is a
    // new entry (true) or a previous one (false)
    STREAMS_BOOST_ARCHIVE_DECL(shared_ptr<void>) 
    get_od(
        const void * od,
        const streams_boost::serialization::extended_type_info * true_type, 
        const streams_boost::serialization::extended_type_info * this_type
    );

    template<class T>
    struct non_polymorphic {
        static const streams_boost::serialization::extended_type_info * 
        get_object_identifier(T & t){
            return & streams_boost::serialization::singleton<
                STREAMS_BOOST_DEDUCED_TYPENAME 
                streams_boost::serialization::type_info_implementation<T>::type
            >::get_const_instance();
        }
    };
    template<class T>
    struct polymorphic {
        static const streams_boost::serialization::extended_type_info * 
        get_object_identifier(T & t){
            return streams_boost::serialization::singleton<
                STREAMS_BOOST_DEDUCED_TYPENAME 
                streams_boost::serialization::type_info_implementation<T>::type
            >::get_const_instance().get_derived_extended_type_info(t);
        }
    };
public:
    template<class T>
    void reset(shared_ptr<T> & s, T * t){
        if(NULL == t){
            s.reset();
            return;
        }
        const streams_boost::serialization::extended_type_info * this_type
            = & streams_boost::serialization::type_info_implementation<T>::type
                    ::get_const_instance();

        // get pointer to the most derived object.  This is effectively
        // the object identifer
        typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
            is_polymorphic<T>,
            mpl::identity<polymorphic<T> >,
            mpl::identity<non_polymorphic<T> >
        >::type type;

        const streams_boost::serialization::extended_type_info * true_type
            = type::get_object_identifier(*t);

        // note:if this exception is thrown, be sure that derived pointer
        // is either registered or exported.
        if(NULL == true_type)
            streams_boost::serialization::throw_exception(
                archive_exception(
                    archive_exception::unregistered_class,
                    this_type->get_debug_info()
                )
            );
        shared_ptr<void> r =
            get_od(
                static_cast<const void *>(t), 
                true_type,
                this_type
            );

        s = shared_ptr<T>(
            r,
            static_cast<T *>(r.get())
        );

        //s = static_pointer_cast<T,void>(
        //    const_pointer_cast<void, const void>(*r)
        //);
    }

//  #ifdef STREAMS_BOOST_SERIALIZATION_SHARED_PTR_132_HPP
    STREAMS_BOOST_ARCHIVE_DECL(void)
    append(const streams_boost_132::shared_ptr<void> & t);
//  #endif
public:
    STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY())
    shared_ptr_helper();
    STREAMS_BOOST_ARCHIVE_DECL(STREAMS_BOOST_PP_EMPTY())
    ~shared_ptr_helper();
};

} // namespace detail
} // namespace archive
} // namespace streams_boost

#include <streams_boost/archive/detail/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_ARCHIVE_SHARED_PTR_HELPER_HPP
