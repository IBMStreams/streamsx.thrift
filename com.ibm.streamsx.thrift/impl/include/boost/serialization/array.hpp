#ifndef STREAMS_BOOST_SERIALIZATION_ARRAY_HPP
#define STREAMS_BOOST_SERIALIZATION_ARRAY_HPP

// (C) Copyright 2005 Matthias Troyer and Dave Abrahams
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <cstddef> // std::size_t
#include <cstddef>
#include <streams_boost/config.hpp> // msvc 6.0 needs this for warning suppression
#if defined(STREAMS_BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::size_t; 
} // namespace std
#endif

#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/split_member.hpp>
#include <streams_boost/serialization/wrapper.hpp>
#include <streams_boost/mpl/always.hpp>
#include <streams_boost/mpl/apply.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/type_traits/remove_const.hpp>
#include <streams_boost/array.hpp>

namespace streams_boost { namespace serialization {

// traits to specify whether to use  an optimized array serialization

#ifdef __BORLANDC__
// workaround for Borland compiler
template <class Archive>
struct use_array_optimization {
  template <class T> struct apply : streams_boost::mpl::false_ {};
};

#else
template <class Archive>
struct use_array_optimization : streams_boost::mpl::always<streams_boost::mpl::false_> {};
#endif

template<class T>
class array :
    public wrapper_traits<const array<T> >
{
public:    
    typedef T value_type;
    
    array(value_type* t, std::size_t s) :
        m_t(t),
        m_element_count(s)
    {}
    array(const array & rhs) :
        m_t(rhs.m_t),
        m_element_count(rhs.m_element_count)
    {}
    array & operator=(const array & rhs){
        m_t = rhs.m_t;
        m_element_count = rhs.m_element_count;
    }

    // default implementation
    template<class Archive>
    void serialize_optimized(Archive &ar, const unsigned int, mpl::false_ ) const
    {
      // default implemention does the loop
      std::size_t c = count();
      value_type * t = address();
      while(0 < c--)
            ar & streams_boost::serialization::make_nvp("item", *t++);
    }

    // optimized implementation
    template<class Archive>
    void serialize_optimized(Archive &ar, const unsigned int version, mpl::true_ )
    {
      streams_boost::serialization::split_member(ar, *this, version);
    }

    // default implementation
    template<class Archive>
    void save(Archive &ar, const unsigned int version) const
    {
      ar.save_array(*this,version);
    }

    // default implementation
    template<class Archive>
    void load(Archive &ar, const unsigned int version)
    {
      ar.load_array(*this,version);
    }
    
    // default implementation
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
      typedef STREAMS_BOOST_DEDUCED_TYPENAME 
          streams_boost::serialization::use_array_optimization<Archive>::template apply<
                    STREAMS_BOOST_DEDUCED_TYPENAME remove_const<T>::type 
                >::type use_optimized;
      serialize_optimized(ar,version,use_optimized());
    }
    
    value_type* address() const
    {
      return m_t;
    }

    std::size_t count() const
    {
      return m_element_count;
    }
    
private:
    value_type* m_t;
    std::size_t m_element_count;
};

template<class T>
inline
#ifndef STREAMS_BOOST_NO_FUNCTION_TEMPLATE_ORDERING
const
#endif
array<T> make_array( T* t, std::size_t s){
    return array<T>(t, s);
}

template <class Archive, class T, std::size_t N>
void serialize(Archive& ar, streams_boost::array<T,N>& a, const unsigned int /* version */)
{
  ar & streams_boost::serialization::make_nvp("elems",a.elems);
}



} } // end namespace streams_boost::serialization

#ifdef __BORLANDC__
// ignore optimizations for Borland
#define STREAMS_BOOST_SERIALIZATION_USE_ARRAY_OPTIMIZATION(Archive)      
#else
#define STREAMS_BOOST_SERIALIZATION_USE_ARRAY_OPTIMIZATION(Archive)           \
namespace streams_boost { namespace serialization {                           \
template <> struct use_array_optimization<Archive> {                  \
  template <class ValueType>                                          \
  struct apply : streams_boost::mpl::apply1<Archive::use_array_optimization   \
      , STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::remove_const<ValueType>::type   \
    >::type {};                                                       \
}; }}
#endif // __BORLANDC__

#endif //STREAMS_BOOST_SERIALIZATION_ARRAY_HPP
