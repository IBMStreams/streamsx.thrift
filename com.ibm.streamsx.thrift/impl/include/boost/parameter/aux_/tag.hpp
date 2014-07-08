// Copyright David Abrahams 2005. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_PARAMETER_AUX_TAG_DWA2005610_STREAMS_HPP
# define STREAMS_BOOST_PARAMETER_AUX_TAG_DWA2005610_STREAMS_HPP

# include <streams_boost/parameter/aux_/unwrap_cv_reference.hpp>
# include <streams_boost/parameter/aux_/tagged_argument.hpp>

namespace streams_boost { namespace parameter { namespace aux { 

template <class Keyword, class ActualArg
#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
        , class = typename is_cv_reference_wrapper<ActualArg>::type
#endif 
          >
struct tag
{
    typedef tagged_argument<
        Keyword
      , typename unwrap_cv_reference<ActualArg>::type
    > type;
};

#if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
template <class Keyword, class ActualArg>
struct tag<Keyword,ActualArg,mpl::false_>
{
    typedef tagged_argument<
        Keyword
      , ActualArg
    > type;
};
#endif 

}}} // namespace streams_boost::parameter::aux_

#endif // STREAMS_BOOST_PARAMETER_AUX_TAG_DWA2005610_STREAMS_HPP
