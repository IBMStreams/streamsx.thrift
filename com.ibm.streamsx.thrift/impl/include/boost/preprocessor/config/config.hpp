# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_CONFIG_CONFIG_HPP
# define STREAMS_BOOST_PREPROCESSOR_CONFIG_CONFIG_HPP
#
# /* STREAMS_BOOST_PP_CONFIG_FLAGS */
#
# define STREAMS_BOOST_PP_CONFIG_STRICT() 0x0001
# define STREAMS_BOOST_PP_CONFIG_IDEAL() 0x0002
#
# define STREAMS_BOOST_PP_CONFIG_MSVC() 0x0004
# define STREAMS_BOOST_PP_CONFIG_MWCC() 0x0008
# define STREAMS_BOOST_PP_CONFIG_BCC() 0x0010
# define STREAMS_BOOST_PP_CONFIG_EDG() 0x0020
# define STREAMS_BOOST_PP_CONFIG_DMC() 0x0040
#
# ifndef STREAMS_BOOST_PP_CONFIG_FLAGS
#    if defined(__GCCXML__)
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_STRICT())
#    elif defined(__WAVE__)
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_STRICT())
#    elif defined(__MWERKS__) && __MWERKS__ >= 0x3200
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_STRICT())
#    elif defined(__EDG__) || defined(__EDG_VERSION__)
#        if defined(_MSC_VER) && __EDG_VERSION__ >= 308
#            define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_MSVC())
#        else
#            define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_EDG() | STREAMS_BOOST_PP_CONFIG_STRICT())
#        endif
#    elif defined(__MWERKS__)
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_MWCC())
#    elif defined(__DMC__)
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_DMC())
#    elif defined(__BORLANDC__) && __BORLANDC__ >= 0x581
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_STRICT())
#    elif defined(__BORLANDC__) || defined(__IBMC__) || defined(__IBMCPP__) || defined(__SUNPRO_CC)
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_BCC())
#    elif defined(_MSC_VER)
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_MSVC())
#    else
#        define STREAMS_BOOST_PP_CONFIG_FLAGS() (STREAMS_BOOST_PP_CONFIG_STRICT())
#    endif
# endif
#
# /* STREAMS_BOOST_PP_CONFIG_EXTENDED_LINE_INFO */
#
# ifndef STREAMS_BOOST_PP_CONFIG_EXTENDED_LINE_INFO
#    define STREAMS_BOOST_PP_CONFIG_EXTENDED_LINE_INFO 0
# endif
#
# /* STREAMS_BOOST_PP_CONFIG_ERRORS */
#
# ifndef STREAMS_BOOST_PP_CONFIG_ERRORS
#    ifdef NDEBUG
#        define STREAMS_BOOST_PP_CONFIG_ERRORS 0
#    else
#        define STREAMS_BOOST_PP_CONFIG_ERRORS 1
#    endif
# endif
#
# endif
