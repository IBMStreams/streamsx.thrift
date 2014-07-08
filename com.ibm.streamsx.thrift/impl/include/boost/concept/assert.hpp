// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_ASSERT_DWA2006430_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_ASSERT_DWA2006430_STREAMS_HPP

# include <streams_boost/config.hpp>
# include <streams_boost/detail/workaround.hpp>

// The old protocol used a constraints() member function in concept
// checking classes.  If the compiler supports SFINAE, we can detect
// that function and seamlessly support the old concept checking
// classes.  In this release, backward compatibility with the old
// concept checking classes is enabled by default, where available.
// The old protocol is deprecated, though, and backward compatibility
// will no longer be the default in the next release.

# if !defined(STREAMS_BOOST_NO_OLD_CONCEPT_SUPPORT)                                         \
    && !defined(STREAMS_BOOST_NO_SFINAE)                                                    \
                                                                                    \
    && !(STREAMS_BOOST_WORKAROUND(__GNUC__, == 3) && STREAMS_BOOST_WORKAROUND(__GNUC_MINOR__, < 4)) \
    && !(STREAMS_BOOST_WORKAROUND(__GNUC__, == 2))

// Note: gcc-2.96 through 3.3.x have some SFINAE, but no ability to
// check for the presence of particularmember functions.

#  define STREAMS_BOOST_OLD_CONCEPT_SUPPORT

# endif

# ifdef STREAMS_BOOST_MSVC
#  include <streams_boost/concept/detail/msvc.hpp>
# elif STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
#  include <streams_boost/concept/detail/borland.hpp>
# else 
#  include <streams_boost/concept/detail/general.hpp>
# endif

  // Usage, in class or function context:
  //
  //     STREAMS_BOOST_CONCEPT_ASSERT((UnaryFunctionConcept<F,bool,int>));
  //
# define STREAMS_BOOST_CONCEPT_ASSERT(ModelInParens) \
    STREAMS_BOOST_CONCEPT_ASSERT_FN(void(*)ModelInParens)

#endif // STREAMS_BOOST_CONCEPT_ASSERT_DWA2006430_STREAMS_HPP
