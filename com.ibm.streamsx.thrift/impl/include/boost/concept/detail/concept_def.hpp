// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
#ifndef STREAMS_BOOST_CONCEPT_DETAIL_CONCEPT_DEF_DWA200651_STREAMS_HPP
# define STREAMS_BOOST_CONCEPT_DETAIL_CONCEPT_DEF_DWA200651_STREAMS_HPP
# include <streams_boost/preprocessor/seq/for_each_i.hpp>
# include <streams_boost/preprocessor/seq/enum.hpp>
# include <streams_boost/preprocessor/comma_if.hpp>
# include <streams_boost/preprocessor/cat.hpp>
#endif // STREAMS_BOOST_CONCEPT_DETAIL_CONCEPT_DEF_DWA200651_STREAMS_HPP

// STREAMS_BOOST_concept(SomeName, (p1)(p2)...(pN))
//
// Expands to "template <class p1, class p2, ...class pN> struct SomeName"
//
// Also defines an equivalent SomeNameConcept for backward compatibility.
// Maybe in the next release we can kill off the "Concept" suffix for good.
#if STREAMS_BOOST_WORKAROUND(__GNUC__, <= 3)
# define STREAMS_BOOST_concept(name, params)                                            \
    template < STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_CONCEPT_typename,~,params) >       \
    struct name; /* forward declaration */                                      \
                                                                                \
    template < STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_CONCEPT_typename,~,params) >       \
    struct STREAMS_BOOST_PP_CAT(name,Concept)                                           \
      : name< STREAMS_BOOST_PP_SEQ_ENUM(params) >                                       \
    {                                                                           \
        /* at least 2.96 and 3.4.3 both need this */                            \
        STREAMS_BOOST_PP_CAT(name,Concept)();                                           \
    };                                                                          \
                                                                                \
    template < STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_CONCEPT_typename,~,params) >       \
    struct name                                                                
#else
# define STREAMS_BOOST_concept(name, params)                                            \
    template < STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_CONCEPT_typename,~,params) >       \
    struct name; /* forward declaration */                                      \
                                                                                \
    template < STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_CONCEPT_typename,~,params) >       \
    struct STREAMS_BOOST_PP_CAT(name,Concept)                                           \
      : name< STREAMS_BOOST_PP_SEQ_ENUM(params) >                                       \
    {                                                                           \
    };                                                                          \
                                                                                \
    template < STREAMS_BOOST_PP_SEQ_FOR_EACH_I(STREAMS_BOOST_CONCEPT_typename,~,params) >       \
    struct name                                                                
#endif
    
// Helper for STREAMS_BOOST_concept, above.
# define STREAMS_BOOST_CONCEPT_typename(r, ignored, index, t) \
    STREAMS_BOOST_PP_COMMA_IF(index) typename t

