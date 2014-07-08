//  (C) Copyright Jeremy Siek 2006
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PROPERTY_SERIALIZE_HPP
#define STREAMS_BOOST_PROPERTY_SERIALIZE_HPP

#include <streams_boost/pending/property.hpp>
#ifdef STREAMS_BOOST_GRAPH_USE_MPI
#include <streams_boost/mpi/datatype.hpp>
#include <streams_boost/serialization/is_bitwise_serializable.hpp>
#endif // STREAMS_BOOST_GRAPH_USE_MPI

#include <streams_boost/serialization/base_object.hpp>
#include <streams_boost/serialization/nvp.hpp>

namespace streams_boost {
  template<class Archive>
  inline void serialize(Archive&, no_property&, const unsigned int) { }

  template<class Archive, class Tag, class T, class Base>
  void 
  serialize(Archive& ar, property<Tag, T, Base>& prop, 
            const unsigned int version) 
  {
    ar & serialization::make_nvp( "property_base" , streams_boost::serialization::base_object<Base>(prop) );
    ar & serialization::make_nvp( "property_value" , prop.m_value );
  }

#ifdef STREAMS_BOOST_GRAPH_USE_MPI
  namespace mpi {
    template<typename Tag, typename T, typename Base>
    struct is_mpi_datatype<property<Tag, T, Base> >
      : mpl::and_<is_mpi_datatype<T>,
                  is_mpi_datatype<Base> > { };
  }

  namespace serialization {
    template<typename Tag, typename T, typename Base>
    struct is_bitwise_serializable<property<Tag, T, Base> >
      : mpl::and_<is_bitwise_serializable<T>,
                  is_bitwise_serializable<Base> > { };

  template<typename Tag, typename T, typename Base>
  struct implementation_level<property<Tag, T, Base>  >
   : mpl::int_<object_serializable> {} ;

  template<typename Tag, typename T, typename Base>
  struct tracking_level<property<Tag, T, Base>  >
   : mpl::int_<track_never> {} ;

  }
#endif // STREAMS_BOOST_GRAPH_USE_MPI
  
} // end namespace streams_boost

#ifdef STREAMS_BOOST_GRAPH_USE_MPI
namespace streams_boost { namespace mpi {
    template<>
    struct is_mpi_datatype<streams_boost::no_property> : mpl::true_ { };

} } // end namespace streams_boost::mpi

STREAMS_BOOST_IS_BITWISE_SERIALIZABLE(streams_boost::no_property)
STREAMS_BOOST_CLASS_IMPLEMENTATION(streams_boost::no_property,object_serializable)
STREAMS_BOOST_CLASS_TRACKING(streams_boost::no_property,track_never)
#endif // STREAMS_BOOST_GRAPH_USE_MPI

#endif // STREAMS_BOOST_PROPERTY_SERIALIZE_HPP
