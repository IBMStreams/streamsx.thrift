// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_REQUIRES_DWA2006430_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_REQUIRES_DWA2006430_STREAMS_HPP

# include <streams_boost/config.hpp>
# include <streams_boost/parameter/aux_/parenthesized_type.hpp>
# include <streams_boost/concept/assert.hpp>
# include <streams_boost/preprocessor/seq/for_each.hpp>

namespace streams_boost { 

// Template for use in handwritten assertions
template <class Model, class More>
struct requires_ : More
{
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
    typedef typename More::type type;
# endif 
    STREAMS_BOOST_CONCEPT_ASSERT((Model));
};

// Template for use by macros, where models must be wrapped in parens.
// This isn't in namespace detail to keep extra cruft out of resulting
// error messages.
template <class ModelFn>
struct _requires_
{
    enum { value = 0 };
    STREAMS_BOOST_CONCEPT_ASSERT_FN(ModelFn);
};

template <int check, class Result>
struct Requires_ : ::streams_boost::parameter::aux::unaryfunptr_arg_type<Result>
{
# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, <= 1300)
    typedef typename ::streams_boost::parameter::aux::unaryfunptr_arg_type<Result>::type type;
# endif 
};

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_INTEL_WIN, STREAMS_BOOST_TESTED_AT(1010))
#  define STREAMS_BOOST_CONCEPT_REQUIRES_(r,data,t) | (::streams_boost::_requires_<void(*)t>::value)
# else 
#  define STREAMS_BOOST_CONCEPT_REQUIRES_(r,data,t) + (::streams_boost::_requires_<void(*)t>::value)
# endif

#if defined(NDEBUG) || STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)

# define STREAMS_BOOST_CONCEPT_REQUIRES(models, result)                                    \
    typename ::streams_boost::parameter::aux::unaryfunptr_arg_type<void(*)result>::type

#elif STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))

// Same thing as below without the initial typename
# define STREAMS_BOOST_CONCEPT_REQUIRES(models, result)                                \
    ::streams_boost::Requires_<                                                        \
      (0 STREAMS_BOOST_PP_SEQ_FOR_EACH(STREAMS_BOOST_CONCEPT_REQUIRES_, ~, models)),           \
      ::streams_boost::parameter::aux::unaryfunptr_arg_type<void(*)result>          \
                     >::type

#else

// This just ICEs on MSVC6 :(
# define STREAMS_BOOST_CONCEPT_REQUIRES(models, result)                                        \
    typename ::streams_boost::Requires_<                                                       \
      (0 STREAMS_BOOST_PP_SEQ_FOR_EACH(STREAMS_BOOST_CONCEPT_REQUIRES_, ~, models)),                   \
      void(*)result                                                                 \
    >::type

#endif 

// C++0x proposed syntax changed.  This supports an older usage
#define STREAMS_BOOST_CONCEPT_WHERE(models,result) STREAMS_BOOST_CONCEPT_REQUIRES(models,result)

} // namespace streams_boost::concept_check

#endif // STREAMS_BOOST_CONCEPT_REQUIRES_DWA2006430_STREAMS_HPP
