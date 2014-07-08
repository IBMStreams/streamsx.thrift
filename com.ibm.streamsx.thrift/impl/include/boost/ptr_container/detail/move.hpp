// (C) Copyright Daniel Wallin 2004.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// Contains the definitions of the class template move_source and the function
// template move, which together make move pointers moveable.

#ifndef STREAMS_BOOST_MOVE_HPP_INCLUDED
#define STREAMS_BOOST_MOVE_HPP_INCLUDED

namespace streams_boost { namespace ptr_container_detail {

namespace move_ptrs {

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, >= 1400)    
#pragma warning(push)    
#pragma warning(disable:4512)  
#endif  
    
template<typename Ptr>
class move_source {
public:
    move_source(Ptr& ptr) : ptr_(ptr) {}
    Ptr& ptr() const { return ptr_; }
private:
    Ptr& ptr_;
    move_source(const Ptr&);
};

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, >= 1400)    
#pragma warning(pop)    
#endif  

} // End namespace move_ptrs.


template<typename T>
move_ptrs::move_source<T> move(T& x) 
{ return move_ptrs::move_source<T>(x); }

} // namespace 'ptr_container_detail'
} // End namespace streams_boost.

#endif // #ifndef STREAMS_BOOST_MOVE_HPP_INCLUDED
