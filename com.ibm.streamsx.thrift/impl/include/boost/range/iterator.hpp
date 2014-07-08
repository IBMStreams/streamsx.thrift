// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.streams_boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.streams_boost.org/libs/range/
//

#ifndef STREAMS_BOOST_RANGE_ITERATOR_HPP
#define STREAMS_BOOST_RANGE_ITERATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <streams_boost/range/config.hpp>
#include <streams_boost/range/mutable_iterator.hpp>
#include <streams_boost/range/const_iterator.hpp>
#include <streams_boost/type_traits/is_const.hpp>
#include <streams_boost/type_traits/remove_const.hpp>
#include <streams_boost/mpl/eval_if.hpp>

namespace streams_boost
{

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1310)  

    namespace range_detail_vc7_1  
    {  
       template< typename C, typename Sig = void(C) >  
       struct range_iterator  
       {  
           typedef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME   
               mpl::eval_if_c< is_const<C>::value,   
                               range_const_iterator< typename remove_const<C>::type >,  
                               range_mutable_iterator<C> >::type type;  
       };  
    
       template< typename C, typename T >  
       struct range_iterator< C, void(T[]) >  
       {  
           typedef T* type;  
       };       
    }  
    
#endif  

    template< typename C >
    struct range_iterator
    {
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, == 1310)
  
        typedef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME  
               range_detail_vc7_1::range_iterator<C>::type type;  
           
#else  

        typedef STREAMS_BOOST_RANGE_DEDUCED_TYPENAME 
            mpl::eval_if_c< is_const<C>::value, 
                            range_const_iterator< typename remove_const<C>::type >,
                            range_mutable_iterator<C> >::type type;
        
#endif         
    };
    
} // namespace streams_boost

//#endif // STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif
