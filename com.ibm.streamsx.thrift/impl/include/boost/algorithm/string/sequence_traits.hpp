//  Boost string_algo library sequence_traits.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for updates, documentation, and revision history.

#ifndef STREAMS_BOOST_STRING_SEQUENCE_TRAITS_HPP
#define STREAMS_BOOST_STRING_SEQUENCE_TRAITS_HPP

#include <streams_boost/config.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/algorithm/string/yes_no_type.hpp>

/*! \file
    Traits defined in this header are used by various algorithms to achieve
    better performance for specific containers.
    Traits provide fail-safe defaults. If a container supports some of these
    features, it is possible to specialize the specific trait for this container.
    For lacking compilers, it is possible of define an override for a specific tester
    function.

    Due to a language restriction, it is not currently possible to define specializations for
    stl containers without including the corresponding header. To decrease the overhead
    needed by this inclusion, user can selectively include a specialization
    header for a specific container. They are located in streams_boost/algorithm/string/stl
    directory. Alternatively she can include streams_boost/algorithm/string/std_collection_traits.hpp
    header which contains specializations for all stl containers.
*/

namespace streams_boost {
    namespace algorithm {

//  sequence traits  -----------------------------------------------//

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

        //! Native replace tester
        /*!
            Declare an override of this tester function with return
            type streams_boost::string_algo::yes_type for a sequence with this property.

            \return yes_type if the container has basic_string like native replace
            method.
        */
        no_type has_native_replace_tester(...);

        //! Stable iterators tester
        /*!
            Declare an override of this tester function with return
            type streams_boost::string_algo::yes_type for a sequence with this property.

            \return yes_type if the sequence's insert/replace/erase methods do not invalidate
            existing iterators.
        */
        no_type has_stable_iterators_tester(...);

        //! const time insert tester
        /*!
            Declare an override of this tester function with return
            type streams_boost::string_algo::yes_type for a sequence with this property.

            \return yes_type if the sequence's insert method is working in constant time
        */
        no_type has_const_time_insert_tester(...);

        //! const time erase tester
        /*!
            Declare an override of this tester function with return
            type streams_boost::string_algo::yes_type for a sequence with this property.

            \return yes_type if the sequence's erase method is working in constant time
        */
        no_type has_const_time_erase_tester(...);

#endif //STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

        //! Native replace trait
        /*!
            This trait specifies that the sequence has \c std::string like replace method
        */
        template< typename T >
        class has_native_replace
        {

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        private:
            static T* t;
        public:
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=(
                sizeof(has_native_replace_tester(t))==sizeof(yes_type) ) );
#else  // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        public:
#    if STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = false };
#    else
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=false);
#    endif // STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION


            typedef mpl::bool_<has_native_replace<T>::value> type;
        };


        //! Stable iterators trait
        /*!
            This trait specifies that the sequence has stable iterators. It means
            that operations like insert/erase/replace do not invalidate iterators.
        */
        template< typename T >
        class has_stable_iterators
        {
#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        private:
            static T* t;
        public:
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=(
                sizeof(has_stable_iterators_tester(t))==sizeof(yes_type) ) );
#else  // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        public:
#    if STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = false };
#    else
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=false);
#    endif // STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

            typedef mpl::bool_<has_stable_iterators<T>::value> type;
        };


        //! Const time insert trait
        /*!
            This trait specifies that the sequence's insert method has
            constant time complexity.
        */
        template< typename T >
        class has_const_time_insert
        {
#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        private:
            static T* t;
        public:
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=(
                sizeof(has_const_time_insert_tester(t))==sizeof(yes_type) ) );
#else  // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        public:
#    if STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = false };
#    else
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=false);
#    endif // STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

            typedef mpl::bool_<has_const_time_insert<T>::value> type;
        };


        //! Const time erase trait
        /*!
            This trait specifies that the sequence's erase method has
            constant time complexity.
        */
        template< typename T >
        class has_const_time_erase
        {
#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        private:
            static T* t;
        public:
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=(
                sizeof(has_const_time_erase_tester(t))==sizeof(yes_type) ) );
#else  // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        public:
#    if STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = false };
#    else
            STREAMS_BOOST_STATIC_CONSTANT(bool, value=false);
#    endif // STREAMS_BOOST_WORKAROUND( __IBMCPP__, <= 600 )
#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

            typedef mpl::bool_<has_const_time_erase<T>::value> type;
        };

    } // namespace algorithm
} // namespace streams_boost


#endif  // STREAMS_BOOST_STRING_SEQUENCE_TRAITS_HPP
