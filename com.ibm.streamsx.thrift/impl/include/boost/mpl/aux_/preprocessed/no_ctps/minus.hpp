
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.streams_boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "streams_boost/mpl/minus.hpp" header
// -- DO NOT modify by hand!

namespace streams_boost { namespace mpl {

template<
      typename Tag1
    , typename Tag2
    >
struct minus_impl
    : if_c<
          ( STREAMS_BOOST_MPL_AUX_NESTED_VALUE_WKND(int, Tag1)
              > STREAMS_BOOST_MPL_AUX_NESTED_VALUE_WKND(int, Tag2)
            )

        , aux::cast2nd_impl< minus_impl< Tag1,Tag1 >,Tag1, Tag2 >
        , aux::cast1st_impl< minus_impl< Tag2,Tag2 >,Tag1, Tag2 >
        >::type
{
};

/// for Digital Mars C++/compilers with no CTPS/TTP support
template<> struct minus_impl< na,na >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
        STREAMS_BOOST_STATIC_CONSTANT(int, value  = 0);
    };
};

template<> struct minus_impl< na,integral_c_tag >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
        STREAMS_BOOST_STATIC_CONSTANT(int, value  = 0);
    };
};

template<> struct minus_impl< integral_c_tag,na >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
        STREAMS_BOOST_STATIC_CONSTANT(int, value  = 0);
    };
};

template< typename T > struct minus_tag
{
    typedef typename T::tag type;
};

/// forward declaration

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(N1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(N2)
    >
struct minus2;

template<
      typename STREAMS_BOOST_MPL_AUX_NA_PARAM(N1)
    , typename STREAMS_BOOST_MPL_AUX_NA_PARAM(N2)
    , typename N3 = na, typename N4 = na, typename N5 = na
    >
struct minus

    : if_<

          is_na<N3>
        , minus2< N1,N2 >
        , minus<
              minus2< N1,N2 >
            , N3, N4, N5
            >
        >::type

{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(
          5
        , minus
        , ( N1, N2, N3, N4, N5 )
        )
};

template<
      typename N1
    , typename N2
    >
struct minus2
    : minus_impl<
          typename minus_tag<N1>::type
        , typename minus_tag<N2>::type
        >::template apply< N1,N2 >::type
{
    STREAMS_BOOST_MPL_AUX_LAMBDA_SUPPORT(2, minus2, (N1, N2))

};

STREAMS_BOOST_MPL_AUX_NA_SPEC2(2, 5, minus)

}}

namespace streams_boost { namespace mpl {
template<>
struct minus_impl< integral_c_tag,integral_c_tag >
{
    template< typename N1, typename N2 > struct apply

        : integral_c<
              typename aux::largest_int<
                  typename N1::value_type
                , typename N2::value_type
                >::type
            , ( STREAMS_BOOST_MPL_AUX_VALUE_WKND(N1)::value
                  - STREAMS_BOOST_MPL_AUX_VALUE_WKND(N2)::value
                )
            >
    {
    };
};

}}
