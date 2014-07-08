#ifndef STREAMS_BOOST_ARCHIVE_ITERATORS_HEAD_ITERATOR_HPP
#define STREAMS_BOOST_ARCHIVE_ITERATORS_HEAD_ITERATOR_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// head_iterator.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org for updates, documentation, and revision history.

#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/iterator/iterator_adaptor.hpp>
#include <streams_boost/iterator/iterator_traits.hpp>

namespace streams_boost {
namespace archive {
namespace iterators {

template<class Predicate, class Base>
class head_iterator
    : public streams_boost::iterator_adaptor<
        head_iterator<Predicate, Base>,
        Base,
        use_default,
        single_pass_traversal_tag
    >
{
private:
    friend class iterator_core_access;
    typedef streams_boost::iterator_adaptor<
        head_iterator<Predicate, Base>,
        Base,
        use_default,
        single_pass_traversal_tag
    > super_t;

    typedef head_iterator<Predicate, Base> this_t;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME super_t::value_type value_type;
    typedef STREAMS_BOOST_DEDUCED_TYPENAME super_t::reference reference_type;

    reference_type dereference_impl(){
        if(! m_end){
            while(! m_predicate(* this->base_reference()))
                ++ this->base_reference();
            m_end = true;
        }
        return * this->base_reference();
    }

    reference_type dereference() const {
        return const_cast<this_t *>(this)->dereference_impl();
    }

    void increment(){
        ++base_reference();
    }
    Predicate m_predicate;
    bool m_end;
public:
    template<class T>
    head_iterator(Predicate f, T start) : 
        super_t(Base(start)), 
        m_predicate(f),
        m_end(false)
    {}

};

} // namespace iterators
} // namespace archive
} // namespace streams_boost

#endif // STREAMS_BOOST_ARCHIVE_ITERATORS_HEAD_ITERATOR_HPP
