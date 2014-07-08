///////////////////////////////////////////////////////////////////////////////
/// \file regex_error.hpp
/// Contains the definition of the regex_error exception class.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_XPRESSIVE_REGEX_ERROR_HPP_EAN_10_04_2005
#define STREAMS_BOOST_XPRESSIVE_REGEX_ERROR_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <string>
#include <stdexcept>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/exception/exception.hpp>
#include <streams_boost/xpressive/regex_constants.hpp>

//{{AFX_DOC_COMMENT
///////////////////////////////////////////////////////////////////////////////
// This is a hack to get Doxygen to show the inheritance relation between
// regex_error and std::runtime_error.
#ifdef STREAMS_BOOST_XPRESSIVE_DOXYGEN_INVOKED
/// INTERNAL ONLY
namespace std
{
    /// INTERNAL ONLY
    struct runtime_error {};
}
#endif
//}}AFX_DOC_COMMENT

namespace streams_boost { namespace xpressive
{

////////////////////////////////////////////////////////////////////////////////
//  regex_error
//
/// \brief The class regex_error defines the type of objects thrown as
/// exceptions to report errors during the conversion from a string representing
/// a regular expression to a finite state machine.
struct regex_error
  : std::runtime_error
  , streams_boost::exception
{
    /// Constructs an object of class regex_error.
    /// \param code The error_type this regex_error represents.
    /// \post code() == code
    explicit regex_error(regex_constants::error_type code, char const *str = "")
      : std::runtime_error(str)
      , streams_boost::exception()
      , code_(code)
    {
    }

    /// Accessor for the error_type value
    /// \return the error_type code passed to the constructor
    /// \throw nothrow
    regex_constants::error_type code() const
    {
        return this->code_;
    }

    /// Destructor for class regex_error
    /// \throw nothrow
    virtual ~regex_error() throw()
    {}

private:

    regex_constants::error_type code_;
};

namespace detail
{
    inline bool ensure_(
        bool cond
      , regex_constants::error_type code
      , char const *msg
      , char const *fun
      , char const *file
      , unsigned long line
    )
    {
        if(!cond)
        {
            #ifndef STREAMS_BOOST_EXCEPTION_DISABLE
            streams_boost::throw_exception(
                streams_boost::enable_error_info(streams_boost::xpressive::regex_error(code, msg))
                    << streams_boost::throw_function(fun)
                    << streams_boost::throw_file(file)
                    << streams_boost::throw_line((int)line)
            );
            #else
            streams_boost::throw_exception(streams_boost::xpressive::regex_error(code, msg));
            #endif
        }
        return true;
    }
}

#define STREAMS_BOOST_XPR_ENSURE_(pred, code, msg)                                                          \
    streams_boost::xpressive::detail::ensure_(pred, code, msg, STREAMS_BOOST_CURRENT_FUNCTION, __FILE__, __LINE__)  \
    /**/

}} // namespace streams_boost::xpressive

#endif
