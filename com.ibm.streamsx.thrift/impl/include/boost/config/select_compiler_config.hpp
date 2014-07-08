//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Martin Wille 2003.
//  (C) Copyright Guillaume Melquiond 2003.
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//   http://www.streams_boost.org/LICENSE_1_0.txt)

//  See http://www.streams_boost.org/ for most recent version.


// one identification macro for each of the
// compilers we support:

#   define STREAMS_BOOST_CXX_GCCXML   0
#   define STREAMS_BOOST_CXX_COMO     0
#   define STREAMS_BOOST_CXX_DMC      0
#   define STREAMS_BOOST_CXX_INTEL    0
#   define STREAMS_BOOST_CXX_GNUC     0
#   define STREAMS_BOOST_CXX_KCC      0
#   define STREAMS_BOOST_CXX_SGI      0
#   define STREAMS_BOOST_CXX_TRU64    0
#   define STREAMS_BOOST_CXX_GHS      0
#   define STREAMS_BOOST_CXX_BORLAND  0
#   define STREAMS_BOOST_CXX_CW       0
#   define STREAMS_BOOST_CXX_SUNPRO   0
#   define STREAMS_BOOST_CXX_HPACC    0
#   define STREAMS_BOOST_CXX_MPW      0
#   define STREAMS_BOOST_CXX_IBMCPP   0
#   define STREAMS_BOOST_CXX_MSVC     0
#   define STREAMS_BOOST_CXX_PGI      0


// locate which compiler we are using and define
// STREAMS_BOOST_COMPILER_CONFIG as needed: 

#if defined(__GCCXML__)
// GCC-XML emulates other compilers, it has to appear first here!
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/gcc_xml.hpp"

#elif defined __COMO__
//  Comeau C++
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/comeau.hpp"

#elif defined __DMC__
//  Digital Mars C++
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/digitalmars.hpp"

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
//  Intel
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/intel.hpp"

# elif defined __GNUC__
//  GNU C++:
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/gcc.hpp"

#elif defined __KCC
//  Kai C++
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/kai.hpp"

#elif defined __sgi
//  SGI MIPSpro C++
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/sgi_mipspro.hpp"

#elif defined __DECCXX
//  Compaq Tru64 Unix cxx
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/compaq_cxx.hpp"

#elif defined __ghs
//  Greenhills C++
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/greenhills.hpp"

#elif defined __CODEGEARC__
//  CodeGear - must be checked for before Borland
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/codegear.hpp"

#elif defined __BORLANDC__
//  Borland
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/borland.hpp"

#elif defined  __MWERKS__
//  Metrowerks CodeWarrior
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/metrowerks.hpp"

#elif defined  __SUNPRO_CC
//  Sun Workshop Compiler C++
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/sunpro_cc.hpp"

#elif defined __HP_aCC
//  HP aCC
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/hp_acc.hpp"

#elif defined(__MRC__) || defined(__SC__)
//  MPW MrCpp or SCpp
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/mpw.hpp"

#elif defined(__IBMCPP__)
//  IBM Visual Age
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/vacpp.hpp"

#elif defined(__PGI)
//  Portland Group Inc.
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/pgi.hpp"

#elif defined _MSC_VER
//  Microsoft Visual C++
//
//  Must remain the last #elif since some other vendors (Metrowerks, for
//  example) also #define _MSC_VER
#   define STREAMS_BOOST_COMPILER_CONFIG "streams_boost/config/compiler/visualc.hpp"

#elif defined (STREAMS_BOOST_ASSERT_CONFIG)
// this must come last - generate an error if we don't
// recognise the compiler:
#  error "Unknown compiler - please configure (http://www.streams_boost.org/libs/config/config.htm#configuring) and report the results to the main streams_boost mailing list (http://www.streams_boost.org/more/mailing_lists.htm#main)"

#endif
