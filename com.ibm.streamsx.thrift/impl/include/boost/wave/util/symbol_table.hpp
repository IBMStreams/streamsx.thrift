/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(SYMBOL_TABLE_HPP_32B0F7C6_3DD6_4113_95A5_E16516C6F45A_INCLUDED)
#define SYMBOL_TABLE_HPP_32B0F7C6_3DD6_4113_95A5_E16516C6F45A_INCLUDED

#include <map>

#include <streams_boost/wave/wave_config.hpp>
#include <streams_boost/intrusive_ptr.hpp> 

#if STREAMS_BOOST_WAVE_SERIALIZATION != 0
#include <streams_boost/serialization/serialization.hpp>
#include <streams_boost/serialization/map.hpp>
#include <streams_boost/shared_ptr.hpp>
#else
#include <streams_boost/intrusive_ptr.hpp> 
#endif

#include <streams_boost/iterator/transform_iterator.hpp>

// this must occur after all of the includes and before any code appears
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_PREFIX
#endif

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost {
namespace wave {
namespace util {

///////////////////////////////////////////////////////////////////////////////
//
//  The symbol_table class is used for the storage of defined macros. 
//
///////////////////////////////////////////////////////////////////////////////

template <typename StringT, typename MacroDefT>
struct symbol_table 
#if STREAMS_BOOST_WAVE_SERIALIZATION != 0
:   public std::map<StringT, streams_boost::shared_ptr<MacroDefT> > 
#else
:   public std::map<StringT, streams_boost::intrusive_ptr<MacroDefT> > 
#endif
{
#if STREAMS_BOOST_WAVE_SERIALIZATION != 0
    typedef std::map<StringT, streams_boost::shared_ptr<MacroDefT> > base_type;
#else
    typedef std::map<StringT, streams_boost::intrusive_ptr<MacroDefT> > base_type;
#endif
    typedef typename base_type::iterator iterator_type;
    typedef typename base_type::const_iterator const_iterator_type;

    symbol_table(long uid_ = 0) 
    {}

#if STREAMS_BOOST_WAVE_SERIALIZATION != 0
private:
    friend class streams_boost::serialization::access;
    template<typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        using namespace streams_boost::serialization;
        ar & make_nvp("symbol_table", 
            streams_boost::serialization::base_object<base_type>(*this));
    }
#endif

private:
    ///////////////////////////////////////////////////////////////////////////
    //
    //  This is a special iterator allowing to iterate the names of all defined 
    //  macros.
    //
    ///////////////////////////////////////////////////////////////////////////
    template <typename StringT1>
    struct get_first
    {
        typedef StringT1 const& result_type;

        template <typename First, typename Second>
        StringT1 const& operator() (std::pair<First, Second> const& p) const
        {
            return p.first;
        }
    };
    typedef get_first<StringT> unary_functor;

public:
    typedef transform_iterator<unary_functor, iterator_type> 
        name_iterator;
    typedef transform_iterator<unary_functor, const_iterator_type> 
        const_name_iterator;

    template <typename Iterator>
    static 
    transform_iterator<unary_functor, Iterator> make_iterator(Iterator it)
    {
        return streams_boost::make_transform_iterator<unary_functor>(it);
    }
};

///////////////////////////////////////////////////////////////////////////////
}   // namespace util
}   // namespace wave
}   // namespace streams_boost

// the suffix header occurs after all of the code
#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#include STREAMS_BOOST_ABI_SUFFIX
#endif

#endif // !defined(SYMBOL_TABLE_HPP_32B0F7C6_3DD6_4113_95A5_E16516C6F45A_INCLUDED)
