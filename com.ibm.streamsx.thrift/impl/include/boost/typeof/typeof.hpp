// Copyright (C) 2004 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_TYPEOF_TYPEOF_HPP_INCLUDED
#define STREAMS_BOOST_TYPEOF_TYPEOF_HPP_INCLUDED

#if defined(STREAMS_BOOST_TYPEOF_COMPLIANT)
#   define STREAMS_BOOST_TYPEOF_EMULATION
#endif

#if defined(STREAMS_BOOST_TYPEOF_EMULATION) && defined(STREAMS_BOOST_TYPEOF_NATIVE)
#   error both typeof emulation and native mode requested
#endif

#if defined(__COMO__)
#   ifdef __GNUG__
#       ifndef(STREAMS_BOOST_TYPEOF_EMULATION)
#           ifndef STREAMS_BOOST_TYPEOF_NATIVE
#               define STREAMS_BOOST_TYPEOF_NATIVE
#           endif
#           define STREAMS_BOOST_TYPEOF_KEYWORD typeof
#       endif
#   else
#       ifndef STREAMS_BOOST_TYPEOF_NATIVE
#           ifndef STREAMS_BOOST_TYPEOF_EMULATION
#               define STREAMS_BOOST_TYPEOF_EMULATION
#           endif
#       else
#           error native typeof is not supported
#       endif
#   endif

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
#   ifdef __GNUC__
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           ifndef STREAMS_BOOST_TYPEOF_NATIVE
#               define STREAMS_BOOST_TYPEOF_NATIVE
#           endif
#           define STREAMS_BOOST_TYPEOF_KEYWORD __typeof__
#       endif
#   else
#       ifndef STREAMS_BOOST_TYPEOF_NATIVE
#           ifndef STREAMS_BOOST_TYPEOF_EMULATION
#               define STREAMS_BOOST_TYPEOF_EMULATION
#           endif
#       else
#           error native typeof is not supported
#       endif
#   endif

#elif defined(__GNUC__)
#   ifndef STREAMS_BOOST_TYPEOF_EMULATION
#       ifndef STREAMS_BOOST_TYPEOF_NATIVE
#           define STREAMS_BOOST_TYPEOF_NATIVE
#       endif
#       define STREAMS_BOOST_TYPEOF_KEYWORD __typeof__
#   endif

#elif defined(__MWERKS__)
#   if(__MWERKS__ <= 0x3003)  // 8.x
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           ifndef STREAMS_BOOST_TYPEOF_NATIVE
#               define STREAMS_BOOST_TYPEOF_NATIVE
#           endif
#           define STREAMS_BOOST_TYPEOF_KEYWORD __typeof__
#       else
#           error typeof emulation is not supported
#       endif
#   else // 9.x
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           ifndef STREAMS_BOOST_TYPEOF_NATIVE
#               define STREAMS_BOOST_TYPEOF_NATIVE
#           endif
#           define STREAMS_BOOST_TYPEOF_KEYWORD __typeof__
#       endif
#   endif

#elif defined __DMC__
#   ifndef STREAMS_BOOST_TYPEOF_EMULATION
#       ifndef STREAMS_BOOST_TYPEOF_NATIVE
#           define STREAMS_BOOST_TYPEOF_NATIVE
#       endif
#       include <streams_boost/typeof/dmc/typeof_impl.hpp>
#       define MSVC_TYPEOF_HACK
#   endif
#elif defined(_MSC_VER)
#   if (_MSC_VER <= 1300)  // 6.5, 7.0
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           ifndef STREAMS_BOOST_TYPEOF_NATIVE
#               define STREAMS_BOOST_TYPEOF_NATIVE
#           endif
#           include <streams_boost/typeof/msvc/typeof_impl.hpp>
#           define MSVC_TYPEOF_HACK
#       else
#           error typeof emulation is not supported
#       endif
#   elif (_MSC_VER >= 1310)  // 7.1, 8.0
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           ifndef STREAMS_BOOST_TYPEOF_NATIVE
#               define STREAMS_BOOST_TYPEOF_NATIVE
#           endif
#           include <streams_boost/typeof/msvc/typeof_impl.hpp>
#           define MSVC_TYPEOF_HACK
#       endif
/*#   else // 8.0
#       ifndef STREAMS_BOOST_TYPEOF_NATIVE
#           ifndef STREAMS_BOOST_TYPEOF_EMULATION
#               define STREAMS_BOOST_TYPEOF_EMULATION
#           endif
#       else
#           error native typeof is not supported
#       endif*/
#   endif

#elif defined(__HP_aCC)
#   ifndef STREAMS_BOOST_TYPEOF_NATIVE
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           define STREAMS_BOOST_TYPEOF_EMULATION
#       endif
#   else
#       error native typeof is not supported
#   endif

#elif defined(__DECCXX)
#   ifndef STREAMS_BOOST_TYPEOF_NATIVE
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           define STREAMS_BOOST_TYPEOF_EMULATION
#       endif
#   else
#       error native typeof is not supported
#   endif

#elif defined(__BORLANDC__)
#   if (__BORLANDC__ < 0x590)
#       define STREAMS_BOOST_TYPEOF_NO_FUNCTION_TYPES
#       define STREAMS_BOOST_TYPEOF_NO_MEMBER_FUNCTION_TYPES
#   endif
#   ifndef STREAMS_BOOST_TYPEOF_NATIVE
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           define STREAMS_BOOST_TYPEOF_EMULATION
#       endif
#   else
#       error native typeof is not supported
#   endif

#else //unknown compiler
#   ifndef STREAMS_BOOST_TYPEOF_NATIVE
#       ifndef STREAMS_BOOST_TYPEOF_EMULATION
#           define STREAMS_BOOST_TYPEOF_EMULATION
#       endif
#   else
#       ifndef STREAMS_BOOST_TYPEOF_KEYWORD
#           define STREAMS_BOOST_TYPEOF_KEYWORD typeof
#       endif
#   endif

#endif

#define STREAMS_BOOST_TYPEOF_UNIQUE_ID()\
     STREAMS_BOOST_TYPEOF_REGISTRATION_GROUP * 0x10000 + __LINE__

#define STREAMS_BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()\
     <streams_boost/typeof/incr_registration_group.hpp>

#ifdef STREAMS_BOOST_TYPEOF_EMULATION
#   define STREAMS_BOOST_TYPEOF_TEXT "using typeof emulation"
#   include <streams_boost/typeof/message.hpp>
#   include <streams_boost/typeof/typeof_impl.hpp>
#   include <streams_boost/typeof/type_encoding.hpp>
#   include <streams_boost/typeof/template_encoding.hpp>
#   include <streams_boost/typeof/modifiers.hpp>
#   include <streams_boost/typeof/pointers_data_members.hpp>
#   include <streams_boost/typeof/register_functions.hpp>
#   include <streams_boost/typeof/register_fundamental.hpp>

#elif defined(STREAMS_BOOST_TYPEOF_NATIVE)
#   define STREAMS_BOOST_TYPEOF_TEXT "using native typeof"
#   include <streams_boost/typeof/message.hpp>
#   include <streams_boost/typeof/native.hpp>
#else
#   error typeof configuration error
#endif

// auto
#define STREAMS_BOOST_AUTO(Var, Expr) STREAMS_BOOST_TYPEOF(Expr) Var = Expr
#define STREAMS_BOOST_AUTO_TPL(Var, Expr) STREAMS_BOOST_TYPEOF_TPL(Expr) Var = Expr

#endif//STREAMS_BOOST_TYPEOF_TYPEOF_HPP_INCLUDED
