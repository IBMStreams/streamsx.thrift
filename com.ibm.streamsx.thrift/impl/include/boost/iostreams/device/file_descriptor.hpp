// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt.)

// See http://www.streams_boost.org/libs/iostreams for documentation.

// Inspired by fdstream.hpp, (C) Copyright Nicolai M. Josuttis 2001,
// available at http://www.josuttis.com/cppcode/fdstream.html.

#ifndef STREAMS_BOOST_IOSTREAMS_FILE_DESCRIPTOR_HPP_INCLUDED
#define STREAMS_BOOST_IOSTREAMS_FILE_DESCRIPTOR_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <string>
#include <streams_boost/cstdint.hpp>               // intmax_t.
#include <streams_boost/iostreams/categories.hpp>  // tags.
#include <streams_boost/iostreams/detail/config/auto_link.hpp>
#include <streams_boost/iostreams/detail/config/dyn_link.hpp>
#include <streams_boost/iostreams/detail/config/windows_posix.hpp>
#include <streams_boost/iostreams/detail/file_handle.hpp>
#include <streams_boost/iostreams/detail/ios.hpp>  // openmode, seekdir, int types.
#include <streams_boost/iostreams/detail/path.hpp>
#include <streams_boost/iostreams/positioning.hpp>
#include <streams_boost/shared_ptr.hpp>

// Must come last.
#include <streams_boost/config/abi_prefix.hpp>

namespace streams_boost { namespace iostreams {

// Forward declarations
class file_descriptor_source;
class file_descriptor_sink;
namespace detail { struct file_descriptor_impl; }

class STREAMS_BOOST_IOSTREAMS_DECL file_descriptor {
public:
    friend class file_descriptor_source;
    friend class file_descriptor_sink;
    typedef detail::file_handle  handle_type;
    typedef char                 char_type;
    struct category
        : seekable_device_tag,
          closable_tag
        { };

    // Default constructor
    file_descriptor();

    // Constructors taking file desciptors
    explicit file_descriptor(handle_type fd, bool close_on_exit = false);
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    explicit file_descriptor(int fd, bool close_on_exit = false);
#endif

    // Constructor taking a std:: string
    explicit file_descriptor( const std::string& path,
                              STREAMS_BOOST_IOS::openmode mode =
                                  STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out );

    // Constructor taking a C-style string
    explicit file_descriptor( const char* path,
                              STREAMS_BOOST_IOS::openmode mode =
                                  STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out );

    // Constructor taking a Boost.Filesystem path
    template<typename Path>
    explicit file_descriptor( const Path& path,
                              STREAMS_BOOST_IOS::openmode mode =
                                  STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out )
    { 
        init();
        open(detail::path(path), mode); 
    }

    // Copy constructor
    file_descriptor(const file_descriptor& other);

    // open overloads taking file descriptors
    void open(handle_type fd, bool close_on_exit = false);
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    void open(int fd, bool close_on_exit = false);
#endif

    // open overload taking a std::string
    void open( const std::string& path,
               STREAMS_BOOST_IOS::openmode mode =
                   STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out );

    // open overload taking C-style string
    void open( const char* path,
               STREAMS_BOOST_IOS::openmode mode =
                   STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out );

    // open overload taking a Boost.Filesystem path
    template<typename Path>
    void open( const Path& path,
               STREAMS_BOOST_IOS::openmode mode =
                   STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out )
    { open(detail::path(path), mode); }

    bool is_open() const;
    void close();
    std::streamsize read(char_type* s, std::streamsize n);
    std::streamsize write(const char_type* s, std::streamsize n);
    std::streampos seek(stream_offset off, STREAMS_BOOST_IOS::seekdir way);
    handle_type handle() const;
private:
    void init();

    // open overload taking a detail::path
    void open( const detail::path& path, 
               STREAMS_BOOST_IOS::openmode, 
               STREAMS_BOOST_IOS::openmode = STREAMS_BOOST_IOS::in | STREAMS_BOOST_IOS::out );

    typedef detail::file_descriptor_impl impl_type;
    shared_ptr<impl_type> pimpl_;
};

class file_descriptor_source : private file_descriptor {
public:
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    typedef void*  handle_type;  // A.k.a HANDLE
#else
    typedef int    handle_type;
#endif
    typedef char   char_type;
    struct category
      : input_seekable,
        device_tag,
        closable_tag
      { };
    using file_descriptor::is_open;
    using file_descriptor::close;
    using file_descriptor::read;
    using file_descriptor::seek;
    using file_descriptor::handle;

    // Default constructor
    file_descriptor_source() { }

    // Constructors taking file desciptors
    explicit file_descriptor_source(handle_type fd, bool close_on_exit = false);
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    explicit file_descriptor_source(int fd, bool close_on_exit = false);
#endif

    // Constructor taking a std:: string
    explicit file_descriptor_source( const std::string& path,
                                     STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::in );

    // Constructor taking a C-style string
    explicit file_descriptor_source( const char* path,
                                     STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::in );

    // Constructor taking a Boost.Filesystem path
    template<typename Path>
    explicit file_descriptor_source( const Path& path,
                                     STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::in )
    { open(detail::path(path), mode); }

    // Copy constructor
    file_descriptor_source(const file_descriptor_source& other);

    // open overloads taking file descriptors
    void open(handle_type fd, bool close_on_exit = false);
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    void open(int fd, bool close_on_exit = false);
#endif

    // open overload taking a std::string
    void open(const std::string& path, STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::in);

    // open overload taking C-style string
    void open(const char* path, STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::in);

    // open overload taking a Boost.Filesystem path
    template<typename Path>
    void open(const Path& path, STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::in);
private:

    // open overload taking a detail::path
    void open(const detail::path& path, STREAMS_BOOST_IOS::openmode);
};

class file_descriptor_sink : private file_descriptor {
public:
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    typedef void*  handle_type;  // A.k.a HANDLE
#else
    typedef int    handle_type;
#endif
    typedef char   char_type;
    struct category
      : output_seekable,
        device_tag,
        closable_tag
      { };
    using file_descriptor::is_open;
    using file_descriptor::close;
    using file_descriptor::write;
    using file_descriptor::seek;
    using file_descriptor::handle;

    // Default constructor
    file_descriptor_sink() { }

    // Constructors taking file desciptors
    explicit file_descriptor_sink(handle_type fd, bool close_on_exit = false);
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    explicit file_descriptor_sink(int fd, bool close_on_exit = false);
#endif

    // Constructor taking a std:: string
    explicit file_descriptor_sink( const std::string& path,
                                   STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::out );

    // Constructor taking a C-style string
    explicit file_descriptor_sink( const char* path,
                                   STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::out );

    // Constructor taking a Boost.Filesystem path
    template<typename Path>
    explicit file_descriptor_sink( const Path& path,
                                   STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::out )
    { open(detail::path(path), mode); }

    // Copy constructor
    file_descriptor_sink(const file_descriptor_sink& other);

    // open overloads taking file descriptors
    void open(handle_type fd, bool close_on_exit = false);
#ifdef STREAMS_BOOST_IOSTREAMS_WINDOWS
    void open(int fd, bool close_on_exit = false);
#endif

    // open overload taking a std::string
    void open( const std::string& path, 
               STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::out );

    // open overload taking C-style string
    void open( const char* path, 
               STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::out );

    // open overload taking a Boost.Filesystem path
    template<typename Path>
    void open( const Path& path, 
               STREAMS_BOOST_IOS::openmode mode = STREAMS_BOOST_IOS::out )
    { open(detail::path(path), mode); }
private:

    // open overload taking a detail::path
    void open(const detail::path& path, STREAMS_BOOST_IOS::openmode);
};

} } // End namespaces iostreams, streams_boost.

#include <streams_boost/config/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // #ifndef STREAMS_BOOST_IOSTREAMS_FILE_DESCRIPTOR_HPP_INCLUDED
