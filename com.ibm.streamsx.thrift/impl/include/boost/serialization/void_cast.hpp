#ifndef  STREAMS_BOOST_SERIALIZATION_VOID_CAST_HPP
#define STREAMS_BOOST_SERIALIZATION_VOID_CAST_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// void_cast.hpp:   interface for run-time casting of void pointers.

// (C) Copyright 2002-2009 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)
// gennadiy.rozental@tfn.com

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <cstddef> // for ptrdiff_t
#include <streams_boost/noncopyable.hpp>

#include <streams_boost/serialization/config.hpp>
#include <streams_boost/serialization/smart_cast.hpp>
#include <streams_boost/serialization/singleton.hpp>
#include <streams_boost/serialization/force_include.hpp>
#include <streams_boost/serialization/type_info_implementation.hpp>
#include <streams_boost/serialization/extended_type_info.hpp>
#include <streams_boost/type_traits/is_virtual_base_of.hpp>
#include <streams_boost/serialization/void_cast_fwd.hpp>

#include <streams_boost/config/abi_prefix.hpp> // must be the last header

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4251 4231 4660 4275)
#endif

namespace streams_boost { 
namespace serialization { 

class extended_type_info;

// Given a void *, assume that it really points to an instance of one type
// and alter it so that it would point to an instance of a related type.
// Return the altered pointer. If there exists no sequence of casts that
// can transform from_type to to_type, return a NULL.  

STREAMS_BOOST_SERIALIZATION_DECL(void const *)
void_upcast(
    extended_type_info const & derived,  
    extended_type_info const & base, 
    void const * const t
);

inline void *
void_upcast(
    extended_type_info const & derived,
    extended_type_info const & base,
    void * const t 
){
    return const_cast<void*>(void_upcast(
        derived, 
        base, 
        const_cast<void const *>(t)
    ));
}

STREAMS_BOOST_SERIALIZATION_DECL(void const *)
void_downcast(
    extended_type_info const & derived,  
    extended_type_info const & base, 
    void const * const t
);

inline void *
void_downcast(
    extended_type_info const & derived,
    extended_type_info const & base,
    void * const t 
){
    return const_cast<void*>(void_downcast(
        derived, 
        base, 
        const_cast<void const *>(t)
    ));
}

namespace void_cast_detail {

class STREAMS_BOOST_SERIALIZATION_DECL(STREAMS_BOOST_PP_EMPTY()) void_caster :
    private streams_boost::noncopyable
{
    friend 
    STREAMS_BOOST_SERIALIZATION_DECL(void const *)
    streams_boost::serialization::void_upcast(
        extended_type_info const & derived,
        extended_type_info const & base,
        void const * const
    );
    friend 
    STREAMS_BOOST_SERIALIZATION_DECL(void const *)  
    streams_boost::serialization::void_downcast(
        extended_type_info const & derived,
        extended_type_info const & base,
        void const * const
    );
protected:
    void recursive_register(bool includes_virtual_base = false) const;
    void recursive_unregister() const;
public:
    // Data members
    const extended_type_info * m_derived;
    const extended_type_info * m_base;
    /*const*/ std::ptrdiff_t m_difference;
    void_caster const * const m_parent;

    // note that void_casters are keyed on value of
    // member extended type info records - NOT their
    // addresses.  This is necessary in order for the
    // void cast operations to work across dll and exe
    // module boundries.
    bool operator<(const void_caster & rhs) const;

    const void_caster & operator*(){
        return *this;
    }
    // each derived class must re-implement these;
    virtual void const * upcast(void const * const t) const = 0;
    virtual void const * downcast(void const * const t) const = 0;
    // Constructor
    void_caster(
        extended_type_info const * derived,
        extended_type_info const * base,
        std::ptrdiff_t difference = 0,
        void_caster const * const parent = 0
    ) :
        m_derived(derived),
        m_base(base),
        m_difference(difference),
        m_parent(parent)
    {}
    virtual ~void_caster(){}
};

#ifdef STREAMS_BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4251 4231 4660 4275 4511 4512)
#endif

template <class Derived, class Base>
class void_caster_primitive : 
    public void_caster
{
    virtual void const * downcast(void const * const t) const {
        const Derived * d = 
            streams_boost::serialization::smart_cast<const Derived *, const Base *>(
                static_cast<const Base *>(t)
            );
        return d;
    }
    virtual void const * upcast(void const * const t) const {
        const Base * b = 
            streams_boost::serialization::smart_cast<const Base *, const Derived *>(
                static_cast<const Derived *>(t)
            );
        return b;
    }
public:
    void_caster_primitive();
    virtual ~void_caster_primitive();
};

template <class Derived, class Base>
void_caster_primitive<Derived, Base>::void_caster_primitive() :
    void_caster( 
        & type_info_implementation<Derived>::type::get_const_instance(), 
        & type_info_implementation<Base>::type::get_const_instance(),
        // note:I wanted to display from 0 here, but at least one compiler
        // treated 0 by not shifting it at all.
        reinterpret_cast<std::ptrdiff_t>(
            static_cast<Derived *>(
                reinterpret_cast<Base *>(1)
            )
        ) - 1
    )
{
    recursive_register();
}

template <class Derived, class Base>
void_caster_primitive<Derived, Base>::~void_caster_primitive(){
    recursive_unregister();
}

template <class Derived, class Base>
class void_caster_virtual_base : 
    public void_caster
{
public:
    virtual void const * downcast(void const * const t) const {
        const Derived * d = 
            dynamic_cast<const Derived *>(
                static_cast<const Base *>(t)
            );
        return d;
    }
    virtual void const * upcast(void const * const t) const {
        const Base * b = 
            dynamic_cast<const Base *>(
                static_cast<const Derived *>(t)
            );
        return b;
    }
    void_caster_virtual_base();
    virtual ~void_caster_virtual_base();
};

#ifdef STREAMS_BOOST_MSVC
#pragma warning(pop)
#endif

template <class Derived, class Base>
void_caster_virtual_base<Derived,Base>::void_caster_virtual_base() :
    void_caster( 
        & (type_info_implementation<Derived>::type::get_const_instance()), 
        & (type_info_implementation<Base>::type::get_const_instance())
    )
{
    recursive_register(true);
}

template <class Derived, class Base>
void_caster_virtual_base<Derived,Base>::~void_caster_virtual_base(){
    recursive_unregister();
}

template <class Derived, class Base>
struct void_caster_base :
    public void_caster
{
    typedef
        STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<streams_boost::is_virtual_base_of<Base,Derived>,
            mpl::identity<
                void_cast_detail::void_caster_virtual_base<Derived, Base>
            >
        ,// else
            mpl::identity<
                void_cast_detail::void_caster_primitive<Derived, Base>
            >
        >::type type;
};

} // void_cast_detail 

template<class Derived, class Base>
STREAMS_BOOST_DLLEXPORT 
inline const void_cast_detail::void_caster & void_cast_register(
    Derived const * /* dnull = NULL */, 
    Base const * /* bnull = NULL */
){
    typedef
        STREAMS_BOOST_DEDUCED_TYPENAME mpl::eval_if<streams_boost::is_virtual_base_of<Base,Derived>,
            mpl::identity<
                void_cast_detail::void_caster_virtual_base<Derived, Base>
            >
        ,// else
            mpl::identity<
                void_cast_detail::void_caster_primitive<Derived, Base>
            >
        >::type typex;
    return singleton<typex>::get_const_instance();
}

template<class Derived, class Base>
class void_caster :
    public void_cast_detail::void_caster_base<Derived, Base>::type
{
};

} // namespace serialization
} // namespace streams_boost

#ifdef STREAMS_BOOST_MSVC  
#  pragma warning(pop)  
#endif

#include <streams_boost/config/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // STREAMS_BOOST_SERIALIZATION_VOID_CAST_HPP