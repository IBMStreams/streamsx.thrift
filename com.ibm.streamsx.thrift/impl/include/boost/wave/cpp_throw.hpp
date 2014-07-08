/*=============================================================================
    Boost.Wave: A Standard compliant C++ preprocessor library

    http://www.streams_boost.org/

    Copyright (c) 2001-2010 Hartmut Kaiser. Distributed under the Boost
    Software License, Version 1.0. (See accompanying file
    LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(STREAMS_BOOST_WAVE_CPP_THROW_HPP_INCLUDED)
#define STREAMS_BOOST_WAVE_CPP_THROW_HPP_INCLUDED

#include <string>
#include <streams_boost/throw_exception.hpp>

///////////////////////////////////////////////////////////////////////////////
// helper macro for throwing exceptions
#if !defined(STREAMS_BOOST_WAVE_THROW)
#ifdef STREAMS_BOOST_NO_STRINGSTREAM
#include <strstream>
#define STREAMS_BOOST_WAVE_THROW(cls, code, msg, act_pos)                             \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::strstream stream;                                                \
            stream << cls::severity_text(cls::code) << ": "                   \
            << cls::error_text(cls::code);                                    \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        std::string throwmsg = stream.str(); stream.freeze(false);            \
        streams_boost::throw_exception(cls(throwmsg.c_str(), cls::code,               \
            (act_pos).get_line(), (act_pos).get_column(),                     \
            (act_pos).get_file().c_str()));                                   \
    }                                                                         \
    /**/
#define STREAMS_BOOST_WAVE_THROW_CTX(ctx, cls, code, msg, act_pos)                    \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::strstream stream;                                                \
            stream << cls::severity_text(cls::code) << ": "                   \
            << cls::error_text(cls::code);                                    \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        std::string throwmsg = stream.str(); stream.freeze(false);            \
        ctx.get_hooks().throw_exception(ctx.derived(), cls(throwmsg.c_str(),  \
            cls::code, (act_pos).get_line(), (act_pos).get_column(),          \
            (act_pos).get_file().c_str()));                                   \
    }                                                                         \
    /**/
#else
#include <sstream>
#define STREAMS_BOOST_WAVE_THROW(cls, code, msg, act_pos)                             \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::stringstream stream;                                             \
            stream << cls::severity_text(cls::code) << ": "                   \
            << cls::error_text(cls::code);                                    \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        streams_boost::throw_exception(cls(stream.str().c_str(), cls::code,           \
            (act_pos).get_line(), (act_pos).get_column(),                     \
            (act_pos).get_file().c_str()));                                   \
    }                                                                         \
    /**/
#define STREAMS_BOOST_WAVE_THROW_CTX(ctx, cls, code, msg, act_pos)                    \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::stringstream stream;                                             \
            stream << cls::severity_text(cls::code) << ": "                   \
            << cls::error_text(cls::code);                                    \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        ctx.get_hooks().throw_exception(ctx.derived(),                        \
            cls(stream.str().c_str(), cls::code, (act_pos).get_line(),        \
                (act_pos).get_column(), (act_pos).get_file().c_str()));       \
    }                                                                         \
    /**/
#endif // STREAMS_BOOST_NO_STRINGSTREAM
#endif // STREAMS_BOOST_WAVE_THROW

///////////////////////////////////////////////////////////////////////////////
// helper macro for throwing exceptions with additional parameter
#if !defined(STREAMS_BOOST_WAVE_THROW_NAME)
#ifdef STREAMS_BOOST_NO_STRINGSTREAM
#include <strstream>
#define STREAMS_BOOST_WAVE_THROW_NAME_CTX(ctx, cls, code, msg, act_pos, name)         \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::strstream stream;                                                \
            stream << cls::severity_text(cls::code) << ": "                   \
            << cls::error_text(cls::code);                                    \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        std::string throwmsg = stream.str(); stream.freeze(false);            \
        ctx.get_hooks().throw_exception(ctx.derived(), cls(throwmsg.c_str(),  \
            cls::code, (act_pos).get_line(), (act_pos).get_column(),          \
            (act_pos).get_file().c_str(), (name)));                           \
    }                                                                         \
    /**/
#else
#include <sstream>
#define STREAMS_BOOST_WAVE_THROW_NAME_CTX(ctx, cls, code, msg, act_pos, name)         \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::stringstream stream;                                             \
            stream << cls::severity_text(cls::code) << ": "                   \
            << cls::error_text(cls::code);                                    \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        ctx.get_hooks().throw_exception(ctx.derived(),                        \
            cls(stream.str().c_str(), cls::code, (act_pos).get_line(),        \
                (act_pos).get_column(), (act_pos).get_file().c_str(), (name))); \
    }                                                                         \
    /**/
#endif // STREAMS_BOOST_NO_STRINGSTREAM
#endif // STREAMS_BOOST_WAVE_THROW_NAME

///////////////////////////////////////////////////////////////////////////////
// helper macro for throwing exceptions with additional parameter
#if !defined(STREAMS_BOOST_WAVE_THROW_VAR)
#ifdef STREAMS_BOOST_NO_STRINGSTREAM
#include <strstream>
#define STREAMS_BOOST_WAVE_THROW_VAR_CTX(ctx, cls, code, msg, act_pos)                \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::strstream stream;                                                \
            stream << cls::severity_text(code) << ": "                        \
            << cls::error_text(code);                                         \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        std::string throwmsg = stream.str(); stream.freeze(false);            \
        ctx.get_hooks().throw_exception(ctx.derived(), cls(throwmsg.c_str(),  \
            code, (act_pos).get_line(), (act_pos).get_column(),               \
            (act_pos).get_file().c_str()));                                   \
    }                                                                         \
    /**/
#else
#include <sstream>
#define STREAMS_BOOST_WAVE_THROW_VAR_CTX(ctx, cls, code, msg, act_pos)                \
    {                                                                         \
        using namespace streams_boost::wave;                                          \
        std::stringstream stream;                                             \
            stream << cls::severity_text(code) << ": "                        \
            << cls::error_text(code);                                         \
        if ((msg)[0] != 0) stream << ": " << (msg);                           \
        stream << std::ends;                                                  \
        ctx.get_hooks().throw_exception(ctx.derived(),                        \
            cls(stream.str().c_str(), code, (act_pos).get_line(),             \
                (act_pos).get_column(), (act_pos).get_file().c_str()));       \
    }                                                                         \
    /**/
#endif // STREAMS_BOOST_NO_STRINGSTREAM
#endif // STREAMS_BOOST_WAVE_THROW_VAR

#endif // !defined(STREAMS_BOOST_WAVE_CPP_THROW_HPP_INCLUDED)
