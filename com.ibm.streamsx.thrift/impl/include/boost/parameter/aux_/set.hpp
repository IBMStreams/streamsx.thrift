// Copyright Daniel Wallin 2006. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_SET_060912_HPP
# define STREAMS_BOOST_PARAMETER_SET_060912_HPP

# include <streams_boost/detail/workaround.hpp>

# if !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564)) \
  && !STREAMS_BOOST_WORKAROUND(__GNUC__, < 3)
#  include <streams_boost/mpl/insert.hpp>
#  include <streams_boost/mpl/set/set0.hpp>
#  include <streams_boost/mpl/has_key.hpp>

namespace streams_boost { namespace parameter { namespace aux {

typedef mpl::set0<> set0;

template <class Set, class K>
struct insert_
{
    typedef typename mpl::insert<Set, K>::type type;
};

template <class Set, class K>
struct has_key_
{
    typedef typename mpl::has_key<Set, K>::type type;
};

}}} // namespace streams_boost::parameter::aux

# else

#  include <streams_boost/mpl/list.hpp>
#  include <streams_boost/mpl/end.hpp>
#  include <streams_boost/mpl/find.hpp>
#  include <streams_boost/mpl/not.hpp>
#  include <streams_boost/mpl/push_front.hpp>

namespace streams_boost { namespace parameter { namespace aux {

typedef mpl::list0<> set0;

template <class Set, class K>
struct insert_
{
    typedef typename mpl::push_front<Set, K>::type type;
};

template <class Set, class K>
struct has_key_
{
    typedef typename mpl::find<Set, K>::type iter;
    typedef mpl::not_<
        is_same<iter, typename mpl::end<Set>::type> 
    > type;
};

}}} // namespace streams_boost::parameter::aux

# endif


#endif // STREAMS_BOOST_PARAMETER_SET_060912_HPP

