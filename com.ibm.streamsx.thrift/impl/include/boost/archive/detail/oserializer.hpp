#ifndef STREAMS_BOOST_ARCHIVE_OSERIALIZER_HPP
#define STREAMS_BOOST_ARCHIVE_OSERIALIZER_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#pragma inline_depth(511)
#pragma inline_recursion(on)
#endif

#if defined(__MWERKS__)
#pragma inline_depth(511)
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// oserializer.hpp: interface for serialization system.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <cassert>
#include <cstddef> // NULL

#include <streams_boost/config.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/detail/workaround.hpp>

#include <streams_boost/mpl/eval_if.hpp>
#include <streams_boost/mpl/equal_to.hpp>
#include <streams_boost/mpl/greater_equal.hpp>
#include <streams_boost/mpl/identity.hpp>

#ifndef STREAMS_BOOST_SERIALIZATION_DEFAULT_TYPE_INFO   
    #include <streams_boost/serialization/extended_type_info_typeid.hpp>   
#endif
#include <streams_boost/serialization/throw_exception.hpp>
#include <streams_boost/serialization/smart_cast.hpp>
#include <streams_boost/serialization/assume_abstract.hpp>
#include <streams_boost/serialization/static_warning.hpp>

#include <streams_boost/type_traits/is_pointer.hpp>
#include <streams_boost/type_traits/is_enum.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/is_polymorphic.hpp>
#include <streams_boost/type_traits/remove_extent.hpp>

#include <streams_boost/serialization/serialization.hpp>
#include <streams_boost/serialization/version.hpp>
#include <streams_boost/serialization/level.hpp>
#include <streams_boost/serialization/tracking.hpp>
#include <streams_boost/serialization/type_info_implementation.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/void_cast.hpp>
#include <streams_boost/serialization/array.hpp>
#include <streams_boost/serialization/collection_size_type.hpp>
#include <streams_boost/serialization/singleton.hpp>

#include <streams_boost/archive/archive_exception.hpp>
#include <streams_boost/archive/detail/basic_oarchive.hpp>
#include <streams_boost/archive/detail/basic_oserializer.hpp>
#include <streams_boost/archive/detail/basic_pointer_oserializer.hpp>
#include <streams_boost/archive/detail/archive_serializer_map.hpp>
#include <streams_boost/archive/detail/check.hpp>

namespace streams_boost {

namespace serialization {
    class extended_type_info;
} // namespace serialization

namespace archive {

// an accessor to permit friend access to archives.  Needed because
// some compilers don't handle friend templates completely
class save_access {
public:
    template<class Archive>
    static void end_preamble(Archive & ar){
        ar.end_preamble();
    }
    template<class Archive, class T>
    static void save_primitive(Archive & ar, const  T & t){
        ar.end_preamble();
        ar.save(t);
    }
};

namespace detail {

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

template<class Archive, class T>
class oserializer : public basic_oserializer
{
private:
    // private constructor to inhibit any existence other than the 
    // static one
public:
    explicit STREAMS_BOOST_DLLEXPORT oserializer() :
        basic_oserializer(
            streams_boost::serialization::singleton<
                STREAMS_BOOST_DEDUCED_TYPENAME 
                streams_boost::serialization::type_info_implementation<T>::type
            >::get_const_instance()
        )
    {}
    virtual STREAMS_BOOST_DLLEXPORT void save_object_data(
        basic_oarchive & ar,    
        const void *x
    ) const STREAMS_BOOST_USED;
    virtual bool class_info() const {
        return streams_boost::serialization::implementation_level<T>::value 
            >= streams_boost::serialization::object_class_info;
    }
    virtual bool tracking(const unsigned int /* flags */) const {
        return streams_boost::serialization::tracking_level<T>::value == streams_boost::serialization::track_always
            || (streams_boost::serialization::tracking_level<T>::value == streams_boost::serialization::track_selectively
                && serialized_as_pointer());
    }
    virtual version_type version() const {
        return version_type(::streams_boost::serialization::version<T>::value);
    }
    virtual bool is_polymorphic() const {
        return streams_boost::is_polymorphic<T>::value;
    }
    virtual ~oserializer(){}
};

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(pop)
#endif

template<class Archive, class T>
STREAMS_BOOST_DLLEXPORT void oserializer<Archive, T>::save_object_data(
    basic_oarchive & ar,    
    const void *x
) const {
    // make sure call is routed through the highest interface that might
    // be specialized by the user.
    STREAMS_BOOST_STATIC_ASSERT(streams_boost::is_const<T>::value == false);
    streams_boost::serialization::serialize_adl(
        streams_boost::serialization::smart_cast_reference<Archive &>(ar),
        * static_cast<T *>(const_cast<void *>(x)),
        version()
    );
}

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

template<class Archive, class T>
class pointer_oserializer :
    public basic_pointer_oserializer
{
private:
    const basic_oserializer & 
    get_basic_serializer() const {
        return streams_boost::serialization::singleton<
            oserializer<Archive, T>
        >::get_const_instance();
    }
    virtual STREAMS_BOOST_DLLEXPORT void save_object_ptr(
        basic_oarchive & ar,
        const void * x
    ) const STREAMS_BOOST_USED;
public:
    pointer_oserializer();
    ~pointer_oserializer();
};

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(pop)
#endif

template<class Archive, class T>
STREAMS_BOOST_DLLEXPORT void pointer_oserializer<Archive, T>::save_object_ptr(
    basic_oarchive & ar,
    const void * x
) const {
    assert(NULL != x);
    // make sure call is routed through the highest interface that might
    // be specialized by the user.
    T * t = static_cast<T *>(const_cast<void *>(x));
    const unsigned int file_version = streams_boost::serialization::version<T>::value;
    Archive & ar_impl 
        = streams_boost::serialization::smart_cast_reference<Archive &>(ar);
    streams_boost::serialization::save_construct_data_adl<Archive, T>(
        ar_impl, 
        t, 
        file_version
    );
    ar_impl << streams_boost::serialization::make_nvp(NULL, * t);
}

template<class Archive, class T>
pointer_oserializer<Archive, T>::pointer_oserializer() :
    basic_pointer_oserializer(
        streams_boost::serialization::singleton<
            STREAMS_BOOST_DEDUCED_TYPENAME 
            streams_boost::serialization::type_info_implementation<T>::type
        >::get_const_instance()
    )
{
    // make sure appropriate member function is instantiated
    streams_boost::serialization::singleton<
        oserializer<Archive, T> 
    >::get_mutable_instance().set_bpos(this);
    archive_serializer_map<Archive>::insert(this);
}

template<class Archive, class T>
pointer_oserializer<Archive, T>::~pointer_oserializer(){
    archive_serializer_map<Archive>::erase(this);
}

template<class Archive>
struct save_non_pointer_type {
    // note this bounces the call right back to the archive
    // with no runtime overhead
    struct save_primitive {
        template<class T>
        static void invoke(Archive & ar, const T & t){
            save_access::save_primitive(ar, t);
        }
    };
    // same as above but passes through serialization
    struct save_only {
        template<class T>
        static void invoke(Archive & ar, const T & t){
            // make sure call is routed through the highest interface that might
            // be specialized by the user.
            streams_boost::serialization::serialize_adl(
                ar, 
                const_cast<T &>(t), 
                ::streams_boost::serialization::version<T>::value
            );
        }
    };
    // adds class information to the archive. This includes
    // serialization level and class version
    struct save_standard {
        template<class T>
        static void invoke(Archive &ar, const T & t){
            ar.save_object(
                & t, 
                streams_boost::serialization::singleton<
                    oserializer<Archive, T>
                >::get_const_instance()
            );
        }
    };

    // adds class information to the archive. This includes
    // serialization level and class version
    struct save_conditional {
        template<class T>
        static void invoke(Archive &ar, const T &t){
            //if(0 == (ar.get_flags() & no_tracking))
                save_standard::invoke(ar, t);
            //else
            //   save_only::invoke(ar, t);
        }
    };


    template<class T>
    static void invoke(Archive & ar, const T & t){
        typedef 
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
            // if its primitive
                mpl::equal_to<
                    streams_boost::serialization::implementation_level<T>,
                    mpl::int_<streams_boost::serialization::primitive_type>
                >,
                mpl::identity<save_primitive>,
            // else
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
                // class info / version
                mpl::greater_equal<
                    streams_boost::serialization::implementation_level<T>,
                    mpl::int_<streams_boost::serialization::object_class_info>
                >,
                // do standard save
                mpl::identity<save_standard>,
            // else
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
                    // no tracking
                mpl::equal_to<
                    streams_boost::serialization::tracking_level<T>,
                    mpl::int_<streams_boost::serialization::track_never>
                >,
                // do a fast save
                mpl::identity<save_only>,
            // else
                // do a fast save only tracking is turned off
                mpl::identity<save_conditional>
            > > >::type typex; 
        check_object_versioning<T>();
        typex::invoke(ar, t);
    }
    template<class T>
    static void invoke(Archive & ar, T & t){
        check_object_level<T>();
        check_object_tracking<T>();
        invoke(ar, const_cast<const T &>(t));
    }
};

template<class Archive>
struct save_pointer_type {
    struct abstract
    {
        template<class T>
        static const basic_pointer_oserializer * register_type(Archive & /* ar */){
            // it has? to be polymorphic
            STREAMS_BOOST_STATIC_ASSERT(streams_boost::is_polymorphic<T>::value);
            return NULL;
        }
    };

    struct non_abstract
    {
        template<class T>
        static const basic_pointer_oserializer * register_type(Archive & ar){
            return ar.register_type(static_cast<T *>(NULL));
        }
    };

    template<class T>
    static const basic_pointer_oserializer * register_type(Archive &ar, T & /*t*/){
        // there should never be any need to save an abstract polymorphic 
        // class pointer.  Inhibiting code generation for this
        // permits abstract base classes to be used - note: exception
        // virtual serialize functions used for plug-ins
        typedef 
            STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
                streams_boost::serialization::is_abstract<T>,
                mpl::identity<abstract>,
                mpl::identity<non_abstract>       
            >::type typex;
        return typex::template register_type<T>(ar);
    }

    struct non_polymorphic
    {
        template<class T>
        static void save(
            Archive &ar, 
            T & t
        ){
            const basic_pointer_oserializer & bpos = 
                streams_boost::serialization::singleton<
                    pointer_oserializer<Archive, T>
                >::get_const_instance();
            // save the requested pointer type
            ar.save_pointer(& t, & bpos);
        }
    };

    struct polymorphic
    {
        template<class T>
        static void save(
            Archive &ar, 
            T & t
        ){
            STREAMS_BOOST_DEDUCED_TYPENAME 
            streams_boost::serialization::type_info_implementation<T>::type const
            & i = streams_boost::serialization::singleton<
                STREAMS_BOOST_DEDUCED_TYPENAME 
                streams_boost::serialization::type_info_implementation<T>::type
            >::get_const_instance();

            streams_boost::serialization::extended_type_info const * const this_type = & i;

            // retrieve the true type of the object pointed to
            // if this assertion fails its an error in this library
            assert(NULL != this_type);

            const streams_boost::serialization::extended_type_info * true_type =
                i.get_derived_extended_type_info(t);

            // note:if this exception is thrown, be sure that derived pointer
            // is either registered or exported.
            if(NULL == true_type){
                streams_boost::serialization::throw_exception(
                    archive_exception(
                        archive_exception::unregistered_class,
                        true_type->get_debug_info()
                    )
                );
            }

            // if its not a pointer to a more derived type
            const void *vp = static_cast<const void *>(&t);
            if(*this_type == *true_type){
                const basic_pointer_oserializer * bpos = register_type(ar, t);
                ar.save_pointer(vp, bpos);
                return;
            }
            // convert pointer to more derived type. if this is thrown
            // it means that the base/derived relationship hasn't be registered
            vp = serialization::void_downcast(
                *true_type, 
                *this_type, 
                static_cast<const void *>(&t)
            );
            if(NULL == vp){
                streams_boost::serialization::throw_exception(
                    archive_exception(
                        archive_exception::unregistered_cast,
                        true_type->get_debug_info(),
                        this_type->get_debug_info()
                    )
                );
            }

            // since true_type is valid, and this only gets made if the 
            // pointer oserializer object has been created, this should never
            // fail
            const basic_pointer_oserializer * bpos
                = static_cast<const basic_pointer_oserializer *>(
                    streams_boost::serialization::singleton<
                        archive_serializer_map<Archive>
                    >::get_const_instance().find(*true_type)
                );
            assert(NULL != bpos);
            if(NULL == bpos)
                streams_boost::serialization::throw_exception(
                    archive_exception(
                        archive_exception::unregistered_class,
                        bpos->get_debug_info()
                    )
                );
            ar.save_pointer(vp, bpos);
        }
    };

    template<class T>
    static void save(
        Archive & ar, 
        const T & t
    ){
        check_pointer_level<T>();
        check_pointer_tracking<T>();
        typedef STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<
            is_polymorphic<T>,
            mpl::identity<polymorphic>,
            mpl::identity<non_polymorphic>
        >::type type;
        type::save(ar, const_cast<T &>(t));
    }

    template<class TPtr>
    static void invoke(Archive &ar, const TPtr t){
        register_type(ar, * t);
        if(NULL == t){
            basic_oarchive & boa 
                = streams_boost::serialization::smart_cast_reference<basic_oarchive &>(ar);
            boa.save_null_pointer();
            save_access::end_preamble(ar);
            return;
        }
        save(ar, * t);
    }
};

template<class Archive>
struct save_enum_type
{
    template<class T>
    static void invoke(Archive &ar, const T &t){
        // convert enum to integers on save
        const int i = static_cast<int>(t);
        ar << streams_boost::serialization::make_nvp(NULL, i);
    }
};

template<class Archive>
struct save_array_type
{
    template<class T>
    static void invoke(Archive &ar, const T &t){
        typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::remove_extent<T>::type value_type;
        
        save_access::end_preamble(ar);
        // consider alignment
        std::size_t c = sizeof(t) / (
            static_cast<const char *>(static_cast<const void *>(&t[1])) 
            - static_cast<const char *>(static_cast<const void *>(&t[0]))
        );
        streams_boost::serialization::collection_size_type count(c);
        ar << STREAMS_BOOST_SERIALIZATION_NVP(count);
        ar << serialization::make_array(static_cast<value_type const*>(&t[0]),count);
    }
};

} // detail

template<class Archive, class T>
inline void save(Archive & ar, /*const*/ T &t){
    typedef 
        STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<is_pointer<T>,
            mpl::identity<detail::save_pointer_type<Archive> >,
        //else
        STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<is_enum<T>,
            mpl::identity<detail::save_enum_type<Archive> >,
        //else
        STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<is_array<T>,
            mpl::identity<detail::save_array_type<Archive> >,
        //else
            mpl::identity<detail::save_non_pointer_type<Archive> >
        >
        >
        >::type typex;
    typex::invoke(ar, t);
}

} // namespace archive
} // namespace streams_boost

#endif // STREAMS_BOOST_ARCHIVE_OSERIALIZER_HPP
