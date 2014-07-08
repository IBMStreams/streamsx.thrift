// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_UNITS_UNIT_HPP
#define STREAMS_BOOST_UNITS_UNIT_HPP

#include <streams_boost/static_assert.hpp>
#include <streams_boost/mpl/bool.hpp>
#include <streams_boost/mpl/assert.hpp>
#include <streams_boost/type_traits/is_same.hpp>

#include <streams_boost/units/config.hpp>
#include <streams_boost/units/dimension.hpp>
#include <streams_boost/units/operators.hpp>
#include <streams_boost/units/units_fwd.hpp>
#include <streams_boost/units/homogeneous_system.hpp>
#include <streams_boost/units/heterogeneous_system.hpp>
#include <streams_boost/units/is_dimension_list.hpp>
#include <streams_boost/units/reduce_unit.hpp>
#include <streams_boost/units/static_rational.hpp>

namespace streams_boost {

namespace units { 

/// class representing a model-dependent unit with no associated value

/// (e.g. meters, Kelvin, feet, etc...)
template<class Dim,class System, class Enable>
class unit
{
    public:
        typedef unit<Dim, System>   unit_type;
        typedef unit<Dim,System>    this_type;
        typedef Dim                 dimension_type; 
        typedef System              system_type;
        
        unit() { }
        unit(const this_type&) { }
        //~unit() { }  
       
        this_type& operator=(const this_type&) { }
        
        // sun will ignore errors resulting from templates
        // instantiated in the return type of a function.
        // Make sure that we get an error anyway by putting.
        // the check in the destructor.
        #ifdef __SUNPRO_CC
        ~unit() {
            STREAMS_BOOST_MPL_ASSERT((detail::check_system<System, Dim>));
            STREAMS_BOOST_MPL_ASSERT((is_dimension_list<Dim>));
        }
        #else
    private:
        STREAMS_BOOST_MPL_ASSERT((detail::check_system<System, Dim>));
        STREAMS_BOOST_MPL_ASSERT((is_dimension_list<Dim>));
        #endif
};

}

}

#if STREAMS_BOOST_UNITS_HAS_STREAMS_BOOST_TYPEOF

#include STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

STREAMS_BOOST_TYPEOF_REGISTER_TEMPLATE(streams_boost::units::unit, 2)

#endif

namespace streams_boost {

namespace units {

/// Returns a unique type for every unit.
template<class Dim, class System>
struct reduce_unit<unit<Dim, System> >
{
    typedef unit<
        Dim,
        typename detail::make_heterogeneous_system<
            Dim,
            System
        >::type
    > type;
};

/// INTERNAL ONLY
template<class S1,class S2> 
struct is_implicitly_convertible :
    streams_boost::is_same<typename reduce_unit<S1>::type, typename reduce_unit<S2>::type>
{ };

/// unit unary plus typeof helper
/// INTERNAL ONLY
template<class Dim,class System>
struct unary_plus_typeof_helper< unit<Dim,System> >
{
    typedef unit<Dim,System>    type;
};

/// unit unary minus typeof helper
/// INTERNAL ONLY
template<class Dim,class System>
struct unary_minus_typeof_helper< unit<Dim,System> >
{
    typedef unit<Dim,System>    type;
};

/// unit add typeof helper
/// INTERNAL ONLY
template<class Dim,
         class System>
struct add_typeof_helper< unit<Dim,System>,unit<Dim,System> >
{
    typedef unit<Dim,System> type;
};

/// unit subtract typeof helper
/// INTERNAL ONLY
template<class Dim,
         class System>
struct subtract_typeof_helper< unit<Dim,System>,unit<Dim,System> >
{
    typedef unit<Dim,System>   type;
};

/// unit multiply typeof helper for two identical homogeneous systems
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System>
struct multiply_typeof_helper< unit<Dim1,homogeneous_system<System> >,
                               unit<Dim2,homogeneous_system<System> > >
{
    typedef unit<typename mpl::times<Dim1,Dim2>::type,homogeneous_system<System> >    type;
};

/// unit multiply typeof helper for two different homogeneous systems
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                               unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            typename detail::make_heterogeneous_system<Dim1, System1>::type,
            typename detail::make_heterogeneous_system<Dim2, System2>::type
        >::type
    > type;
};

/// unit multiply typeof helper for a heterogeneous and a homogeneous system
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                               unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            heterogeneous_system<System1>,
            typename detail::make_heterogeneous_system<Dim2, System2>::type
        >::type
    > type;
};

/// unit multiply typeof helper for a homogeneous and a heterogeneous system
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                               unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            typename detail::make_heterogeneous_system<Dim1, System1>::type,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// unit multiply typeof helper for two heterogeneous systems
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                               unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            heterogeneous_system<System1>,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// unit divide typeof helper for two identical homogeneous systems
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System>
struct divide_typeof_helper< unit<Dim1,homogeneous_system<System> >,
                             unit<Dim2,homogeneous_system<System> > >
{
    typedef unit<typename mpl::divides<Dim1,Dim2>::type,homogeneous_system<System> >    type;
};

/// unit divide typeof helper for two different homogeneous systems
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                             unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            typename detail::make_heterogeneous_system<Dim1, System1>::type,
            typename detail::make_heterogeneous_system<Dim2, System2>::type
        >::type
    > type;
};

/// unit divide typeof helper for a heterogeneous and a homogeneous system
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                             unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            heterogeneous_system<System1>,
            typename detail::make_heterogeneous_system<Dim2, System2>::type
        >::type
    > type;
};

/// unit divide typeof helper for a homogeneous and a heterogeneous system
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                             unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            typename detail::make_heterogeneous_system<Dim1, System1>::type,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// unit divide typeof helper for two heterogeneous systems
/// INTERNAL ONLY
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                             unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            heterogeneous_system<System1>,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// raise unit to a @c static_rational power
template<class Dim,class System,long N,long D> 
struct power_typeof_helper<unit<Dim,System>,static_rational<N,D> >                
{ 
    typedef unit<typename static_power<Dim,static_rational<N,D> >::type,typename static_power<System, static_rational<N,D> >::type>     type; 
    
    static type value(const unit<Dim,System>&)  
    { 
        return type();
    }
};

/// take the @c static_rational root of a unit
template<class Dim,class System,long N,long D> 
struct root_typeof_helper<unit<Dim,System>,static_rational<N,D> >                
{ 
    typedef unit<typename static_root<Dim,static_rational<N,D> >::type,typename static_root<System, static_rational<N,D> >::type>      type; 
    
    static type value(const unit<Dim,System>&)  
    { 
        return type();
    }
};

/// unit runtime unary plus
template<class Dim,class System>
typename unary_plus_typeof_helper< unit<Dim,System> >::type
operator+(const unit<Dim,System>&)
{ 
    typedef typename unary_plus_typeof_helper< unit<Dim,System> >::type type;
    
    return type();
}

/// unit runtime unary minus
template<class Dim,class System>
typename unary_minus_typeof_helper< unit<Dim,System> >::type
operator-(const unit<Dim,System>&)
{ 
    typedef typename unary_minus_typeof_helper< unit<Dim,System> >::type    type;
    
    return type();
}

/// runtime add two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename add_typeof_helper< unit<Dim1,System1>,
                            unit<Dim2,System2> >::type
operator+(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    STREAMS_BOOST_STATIC_ASSERT((streams_boost::is_same<System1,System2>::value == true));
    
    typedef System1                                                     system_type;
    typedef typename add_typeof_helper< unit<Dim1,system_type>,
                                        unit<Dim2,system_type> >::type  type;
    
    return type();
}

/// runtime subtract two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename subtract_typeof_helper< unit<Dim1,System1>,
                                 unit<Dim2,System2> >::type
operator-(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    STREAMS_BOOST_STATIC_ASSERT((streams_boost::is_same<System1,System2>::value == true));
    
    typedef System1                                                         system_type;
    typedef typename subtract_typeof_helper< unit<Dim1,system_type>,
                                             unit<Dim2,system_type> >::type type;
    
    return type();
}

/// runtime multiply two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename multiply_typeof_helper< unit<Dim1,System1>,
                                 unit<Dim2,System2> >::type
operator*(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    typedef typename multiply_typeof_helper< unit<Dim1,System1>,
                                             unit<Dim2,System2> >::type type;
    
    return type();
}

/// runtime divide two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename divide_typeof_helper< unit<Dim1,System1>,
                               unit<Dim2,System2> >::type
operator/(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    typedef typename divide_typeof_helper< unit<Dim1,System1>,
                                           unit<Dim2,System2> >::type   type;
    
    return type();
}

/// unit runtime @c operator==
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
inline
bool 
operator==(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    return streams_boost::is_same<typename reduce_unit<unit<Dim1,System1> >::type, typename reduce_unit<unit<Dim2,System2> >::type>::value;
}

/// unit runtime @c operator!=
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
inline
bool 
operator!=(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    return !streams_boost::is_same<typename reduce_unit<unit<Dim1,System1> >::type, typename reduce_unit<unit<Dim2,System2> >::type>::value;
}

} // namespace units

} // namespace streams_boost

#endif // STREAMS_BOOST_UNITS_UNIT_HPP
