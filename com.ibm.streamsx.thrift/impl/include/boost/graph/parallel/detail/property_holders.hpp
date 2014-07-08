// Copyright (C) 2007 Douglas Gregor and Matthias Troyer
//
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//
// This file contains helper data structures for use in transmitting
// properties. The basic idea is to optimize away any storage for the
// properties when no properties are specified.
#ifndef STREAMS_BOOST_PARALLEL_DETAIL_PROPERTY_HOLDERS_HPP
#define STREAMS_BOOST_PARALLEL_DETAIL_PROPERTY_HOLDERS_HPP

#ifndef STREAMS_BOOST_GRAPH_USE_MPI
#error "Parallel BGL files should not be included unless <streams_boost/graph/use_mpi.hpp> has been included"
#endif

#include <streams_boost/mpi/datatype.hpp>
#include <streams_boost/property_map/property_map.hpp>
#include <streams_boost/serialization/base_object.hpp>
#include <streams_boost/mpl/and.hpp>
#include <streams_boost/graph/parallel/detail/untracked_pair.hpp>

namespace streams_boost { namespace detail { namespace parallel {

/**
 * This structure contains an instance of @c Property, unless @c
 * Property is a placeholder for "no property". Always access the
 * property through @c get_property. Typically used as a base class.
 */
template<typename Property>
struct maybe_store_property
{
  maybe_store_property() {}
  maybe_store_property(const Property& p) : p(p) {}

  Property&       get_property()       { return p; }
  const Property& get_property() const { return p; }

private:
  Property p;

  friend class streams_boost::serialization::access;

  template<typename Archiver>
  void serialize(Archiver& ar, const unsigned int /*version*/)
  {
    ar & p;
  }
};

template<>
struct maybe_store_property<no_property>
{
  maybe_store_property() {}
  maybe_store_property(no_property) {}

  no_property get_property() const { return no_property(); }

private:
  friend class streams_boost::serialization::access;

  template<typename Archiver>
  void serialize(Archiver&, const unsigned int /*version*/) { }
};

/**
 * This structure is a simple pair that also contains a property.
 */
template<typename T, typename U, typename Property>
class pair_with_property
  : public streams_boost::parallel::detail::untracked_pair<T, U>
  , public maybe_store_property<Property>
{
public:
  typedef streams_boost::parallel::detail::untracked_pair<T, U>           pair_base;
  typedef maybe_store_property<Property> property_base;

  pair_with_property() { }

  pair_with_property(const T& t, const U& u, const Property& property)
    : pair_base(t, u), property_base(property) { }

private:
  friend class streams_boost::serialization::access;

  template<typename Archiver>
  void serialize(Archiver& ar, const unsigned int /*version*/) 
  { 
    ar & streams_boost::serialization::base_object<pair_base>(*this)
       & streams_boost::serialization::base_object<property_base>(*this);
  }
};

template<typename T, typename U, typename Property>
inline pair_with_property<T, U, Property>
make_pair_with_property(const T& t, const U& u, const Property& property)
{
  return pair_with_property<T, U, Property>(t, u, property);
}

} } } // end namespace streams_boost::parallel::detail

namespace streams_boost { namespace mpi {

template<> 
struct is_mpi_datatype<streams_boost::detail::parallel::maybe_store_property<no_property> > : mpl::true_ { };

template<typename Property>
struct is_mpi_datatype<streams_boost::detail::parallel::maybe_store_property<Property> >
  : is_mpi_datatype<Property> { };

template<typename T, typename U, typename Property>
struct is_mpi_datatype<streams_boost::detail::parallel::pair_with_property<T, U, Property> >
  : streams_boost::mpl::and_<is_mpi_datatype<streams_boost::parallel::detail::untracked_pair<T, U> >,
                     is_mpi_datatype<Property> > { };

} } // end namespace streams_boost::mpi

STREAMS_BOOST_IS_BITWISE_SERIALIZABLE(streams_boost::detail::parallel::maybe_store_property<no_property>)

namespace streams_boost { namespace serialization {

template<typename Property>
struct is_bitwise_serializable<streams_boost::detail::parallel::maybe_store_property<Property> >
  : is_bitwise_serializable<Property> { };

template<typename Property>
struct implementation_level<streams_boost::detail::parallel::maybe_store_property<Property> >
 : mpl::int_<object_serializable> {} ;

template<typename Property>
struct tracking_level<streams_boost::detail::parallel::maybe_store_property<Property> >
 : mpl::int_<track_never> {} ;

template<typename T, typename U, typename Property>
struct is_bitwise_serializable<
        streams_boost::detail::parallel::pair_with_property<T, U, Property> >
  : streams_boost::mpl::and_<is_bitwise_serializable<streams_boost::parallel::detail::untracked_pair<T, U> >,
                     is_bitwise_serializable<Property> > { };

template<typename T, typename U, typename Property>
struct implementation_level<
        streams_boost::detail::parallel::pair_with_property<T, U, Property> >
 : mpl::int_<object_serializable> {} ;

template<typename T, typename U, typename Property>
struct tracking_level<
        streams_boost::detail::parallel::pair_with_property<T, U, Property> >
 : mpl::int_<track_never> {} ;

} } // end namespace streams_boost::serialization

#endif // STREAMS_BOOST_PARALLEL_DETAIL_PROPERTY_HOLDERS_HPP
