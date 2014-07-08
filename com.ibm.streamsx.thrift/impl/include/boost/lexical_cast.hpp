#ifndef STREAMS_BOOST_LEXICAL_CAST_INCLUDED
#define STREAMS_BOOST_LEXICAL_CAST_INCLUDED

// Boost lexical_cast.hpp header  -------------------------------------------//
//
// See http://www.streams_boost.org/libs/conversion for documentation.
// See end of this header for rights and permissions.
//
// what:  lexical_cast custom keyword cast
// who:   contributed by Kevlin Henney,
//        enhanced with contributions from Terje Slettebo,
//        with additional fixes and suggestions from Gennaro Prota,
//        Beman Dawes, Dave Abrahams, Daryle Walker, Peter Dimov,
//        Alexander Nasonov and other Boosters
// when:  November 2000, March 2003, June 2005, June 2006

#include <climits>
#include <cstddef>
#include <istream>
#include <string>
#include <typeinfo>
#include <exception>
#include <streams_boost/config.hpp>
#include <streams_boost/limits.hpp>
#include <streams_boost/mpl/if.hpp>
#include <streams_boost/throw_exception.hpp>
#include <streams_boost/type_traits/is_pointer.hpp>
#include <streams_boost/type_traits/make_unsigned.hpp>
#include <streams_boost/call_traits.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/detail/lcast_precision.hpp>
#include <streams_boost/detail/workaround.hpp>

#ifndef STREAMS_BOOST_NO_STD_LOCALE
#include <locale>
#endif

#ifdef STREAMS_BOOST_NO_STRINGSTREAM
#include <strstream>
#else
#include <sstream>
#endif

#if defined(STREAMS_BOOST_NO_STRINGSTREAM) || defined(STREAMS_BOOST_NO_STD_WSTRING)
#define STREAMS_BOOST_LCAST_NO_WCHAR_T
#endif

#ifdef STREAMS_BOOST_NO_TYPEID
#define STREAMS_BOOST_LCAST_THROW_BAD_CAST(S, T) throw_exception(bad_lexical_cast())
#else
#define STREAMS_BOOST_LCAST_THROW_BAD_CAST(Source, Target) \
    throw_exception(bad_lexical_cast(typeid(Source), typeid(Target)))
#endif

namespace streams_boost
{
    // exception used to indicate runtime lexical_cast failure
    class bad_lexical_cast : public std::bad_cast

#if defined(__BORLANDC__) && STREAMS_BOOST_WORKAROUND( __BORLANDC__, < 0x560 )
        // under bcc32 5.5.1 bad_cast doesn't derive from exception
        , public std::exception
#endif

    {
    public:
        bad_lexical_cast() :
#ifndef STREAMS_BOOST_NO_TYPEID
          source(&typeid(void)), target(&typeid(void))
#else
          source(0), target(0) // this breaks getters
#endif
        {
        }

        bad_lexical_cast(
            const std::type_info &source_type_arg,
            const std::type_info &target_type_arg) :
            source(&source_type_arg), target(&target_type_arg)
        {
        }

        const std::type_info &source_type() const
        {
            return *source;
        }
        const std::type_info &target_type() const
        {
            return *target;
        }

        virtual const char *what() const throw()
        {
            return "bad lexical cast: "
                   "source type value could not be interpreted as target";
        }
        virtual ~bad_lexical_cast() throw()
        {
        }
    private:
        const std::type_info *source;
        const std::type_info *target;
    };

    namespace detail // selectors for choosing stream character type
    {
        template<typename Type>
        struct stream_char
        {
            typedef char type;
        };

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        template<class CharT, class Traits, class Alloc>
        struct stream_char< std::basic_string<CharT,Traits,Alloc> >
        {
            typedef CharT type;
        };
#endif

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
#ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
        template<>
        struct stream_char<wchar_t>
        {
            typedef wchar_t type;
        };
#endif

        template<>
        struct stream_char<wchar_t *>
        {
            typedef wchar_t type;
        };

        template<>
        struct stream_char<const wchar_t *>
        {
            typedef wchar_t type;
        };

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        template<>
        struct stream_char<std::wstring>
        {
            typedef wchar_t type;
        };
#endif
#endif

        template<typename TargetChar, typename SourceChar>
        struct widest_char
        {
            typedef TargetChar type;
        };

        template<>
        struct widest_char<char, wchar_t>
        {
            typedef wchar_t type;
        };
    }

    namespace detail // deduce_char_traits template
    {
#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        template<class CharT, class Target, class Source>
        struct deduce_char_traits
        {
            typedef std::char_traits<CharT> type;
        };

        template<class CharT, class Traits, class Alloc, class Source>
        struct deduce_char_traits< CharT
                                 , std::basic_string<CharT,Traits,Alloc>
                                 , Source
                                 >
        {
            typedef Traits type;
        };

        template<class CharT, class Target, class Traits, class Alloc>
        struct deduce_char_traits< CharT
                                 , Target
                                 , std::basic_string<CharT,Traits,Alloc>
                                 >
        {
            typedef Traits type;
        };

        template<class CharT, class Traits, class Alloc1, class Alloc2>
        struct deduce_char_traits< CharT
                                 , std::basic_string<CharT,Traits,Alloc1>
                                 , std::basic_string<CharT,Traits,Alloc2>
                                 >
        {
            typedef Traits type;
        };
#endif
    }

    namespace detail // lcast_src_length
    {
        // Return max. length of string representation of Source;
        // 0 if unlimited (with exceptions for some types, see below).
        // Values with limited string representation are placed to
        // the buffer locally defined in lexical_cast function.
        // 1 is returned for few types such as CharT const* or
        // std::basic_string<CharT> that already have an internal
        // buffer ready to be reused by lexical_stream_limited_src.
        // Each specialization should have a correspondent operator<<
        // defined in lexical_stream_limited_src.
        template< class CharT  // A result of widest_char transformation.
                , class Source // Source type of lexical_cast.
                >
        struct lcast_src_length
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 0);
            // To check coverage, build the test with
            // bjam --v2 profile optimization=off
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<char, bool>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<char, char>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

        // No specializations for:
        // lcast_src_length<char, signed char>
        // lcast_src_length<char, unsigned char>
        // lcast_src_length<char, signed char*>
        // lcast_src_length<char, unsigned char*>
        // lcast_src_length<char, signed char const*>
        // lcast_src_length<char, unsigned char const*>

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<>
        struct lcast_src_length<wchar_t, bool>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<wchar_t, char>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

#ifndef STREAMS_BOOST_NO_INTRINSIC_WCHAR_T
        template<>
        struct lcast_src_length<wchar_t, wchar_t>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };
#endif
#endif

        template<>
        struct lcast_src_length<char, char const*>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<char, char*>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<>
        struct lcast_src_length<wchar_t, wchar_t const*>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<wchar_t, wchar_t*>
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };
#endif

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        template<class CharT, class Traits, class Alloc>
        struct lcast_src_length< CharT, std::basic_string<CharT,Traits,Alloc> >
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };
#else
        template<>
        struct lcast_src_length< char, std::basic_string<char> >
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<>
        struct lcast_src_length< wchar_t, std::basic_string<wchar_t> >
        {
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 1);
            static void check_coverage() {}
        };
#endif
#endif

        // Helper for integral types.
        // Notes on length calculation:
        // Max length for 32bit int with grouping "\1" and thousands_sep ',':
        // "-2,1,4,7,4,8,3,6,4,7"
        //  ^                    - is_signed
        //   ^                   - 1 digit not counted by digits10
        //    ^^^^^^^^^^^^^^^^^^ - digits10 * 2
        //
        // Constant is_specialized is used instead of constant 1
        // to prevent buffer overflow in a rare case when
        // <streams_boost/limits.hpp> doesn't add missing specialization for
        // numeric_limits<T> for some integral type T.
        // When is_specialized is false, the whole expression is 0.
        template<class Source>
        struct lcast_src_length_integral
        {
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value =
                  std::numeric_limits<Source>::is_signed +
                  std::numeric_limits<Source>::is_specialized + // == 1
                  std::numeric_limits<Source>::digits10 * 2
              );
#else
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value = 156);
            STREAMS_BOOST_STATIC_ASSERT(sizeof(Source) * CHAR_BIT <= 256);
#endif
        };

#define STREAMS_BOOST_LCAST_DEF1(CharT, T)               \
    template<> struct lcast_src_length<CharT, T> \
        : lcast_src_length_integral<T>           \
    { static void check_coverage() {} };

#ifdef STREAMS_BOOST_LCAST_NO_WCHAR_T
#define STREAMS_BOOST_LCAST_DEF(T) STREAMS_BOOST_LCAST_DEF1(char, T)
#else
#define STREAMS_BOOST_LCAST_DEF(T)          \
        STREAMS_BOOST_LCAST_DEF1(char, T)   \
        STREAMS_BOOST_LCAST_DEF1(wchar_t, T)
#endif

        STREAMS_BOOST_LCAST_DEF(short)
        STREAMS_BOOST_LCAST_DEF(unsigned short)
        STREAMS_BOOST_LCAST_DEF(int)
        STREAMS_BOOST_LCAST_DEF(unsigned int)
        STREAMS_BOOST_LCAST_DEF(long)
        STREAMS_BOOST_LCAST_DEF(unsigned long)
#if defined(STREAMS_BOOST_HAS_LONG_LONG)
        STREAMS_BOOST_LCAST_DEF(streams_boost::ulong_long_type)
        STREAMS_BOOST_LCAST_DEF(streams_boost::long_long_type )
#elif defined(STREAMS_BOOST_HAS_MS_INT64)
        STREAMS_BOOST_LCAST_DEF(unsigned __int64)
        STREAMS_BOOST_LCAST_DEF(         __int64)
#endif

#undef STREAMS_BOOST_LCAST_DEF
#undef STREAMS_BOOST_LCAST_DEF1

#ifndef STREAMS_BOOST_LCAST_NO_COMPILE_TIME_PRECISION
        // Helper for floating point types.
        // -1.23456789e-123456
        // ^                   sign
        //  ^                  leading digit
        //   ^                 decimal point 
        //    ^^^^^^^^         lcast_precision<Source>::value
        //            ^        "e"
        //             ^       exponent sign
        //              ^^^^^^ exponent (assumed 6 or less digits)
        // sign + leading digit + decimal point + "e" + exponent sign == 5
        template<class Source>
        struct lcast_src_length_floating
        {
            STREAMS_BOOST_STATIC_ASSERT(
                    std::numeric_limits<Source>::max_exponent10 <=  999999L &&
                    std::numeric_limits<Source>::min_exponent10 >= -999999L
                );
            STREAMS_BOOST_STATIC_CONSTANT(std::size_t, value =
                    5 + lcast_precision<Source>::value + 6
                );
        };

        template<>
        struct lcast_src_length<char,float>
          : lcast_src_length_floating<float>
        {
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<char,double>
          : lcast_src_length_floating<double>
        {
            static void check_coverage() {}
        };

        template<>
        struct lcast_src_length<char,long double>
          : lcast_src_length_floating<long double>
        {
            static void check_coverage() {}
        };

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
    template<>
    struct lcast_src_length<wchar_t,float>
      : lcast_src_length_floating<float>
    {
        static void check_coverage() {}
    };

    template<>
    struct lcast_src_length<wchar_t,double>
      : lcast_src_length_floating<double>
    {
        static void check_coverage() {}
    };

    template<>
    struct lcast_src_length<wchar_t,long double>
      : lcast_src_length_floating<long double>
    {
        static void check_coverage() {}
    };

#endif // #ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
#endif // #ifndef STREAMS_BOOST_LCAST_NO_COMPILE_TIME_PRECISION
    }

    namespace detail // '0' and '-' constants
    {
        template<typename CharT> struct lcast_char_constants;

        template<>
        struct lcast_char_constants<char>
        {
            STREAMS_BOOST_STATIC_CONSTANT(char, zero  = '0');
            STREAMS_BOOST_STATIC_CONSTANT(char, minus = '-');
        };

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<>
        struct lcast_char_constants<wchar_t>
        {
            STREAMS_BOOST_STATIC_CONSTANT(wchar_t, zero  = L'0');
            STREAMS_BOOST_STATIC_CONSTANT(wchar_t, minus = L'-');
        };
#endif
    }

    namespace detail // lexical_streambuf_fake
    {
        struct lexical_streambuf_fake
        {
        };
    }

    namespace detail // lcast_to_unsigned
    {
#if (defined _MSC_VER)
# pragma warning( push )
// C4146: unary minus operator applied to unsigned type, result still unsigned
# pragma warning( disable : 4146 )
#elif defined( __BORLANDC__ )
# pragma option push -w-8041
#endif
        template<class T>
        inline
        STREAMS_BOOST_DEDUCED_TYPENAME make_unsigned<T>::type lcast_to_unsigned(T value)
        {
            typedef STREAMS_BOOST_DEDUCED_TYPENAME make_unsigned<T>::type result_type;
            result_type uvalue = static_cast<result_type>(value);
            return value < 0 ? -uvalue : uvalue;
        }
#if (defined _MSC_VER)
# pragma warning( pop )
#elif defined( __BORLANDC__ )
# pragma option pop
#endif
    }

    namespace detail // lcast_put_unsigned
    {
        template<class Traits, class T, class CharT>
        CharT* lcast_put_unsigned(T n, CharT* finish)
        {
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
            STREAMS_BOOST_STATIC_ASSERT(!std::numeric_limits<T>::is_signed);
#endif

#ifndef STREAMS_BOOST_LEXICAL_CAST_ASSUME_C_LOCALE
            // TODO: use STREAMS_BOOST_NO_STD_LOCALE
            std::locale loc;
            typedef std::numpunct<CharT> numpunct;
            numpunct const& np = STREAMS_BOOST_USE_FACET(numpunct, loc);
            std::string const& grouping = np.grouping();
            std::string::size_type const grouping_size = grouping.size();
            CharT thousands_sep = grouping_size ? np.thousands_sep() : 0;
            std::string::size_type group = 0; // current group number
            char last_grp_size = grouping[0] <= 0 ? CHAR_MAX : grouping[0];
            // a) Since grouping is const, grouping[grouping.size()] returns 0.
            // b) It's safe to assume here and below that CHAR_MAX
            //    is equivalent to unlimited grouping:
#ifndef STREAMS_BOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
            STREAMS_BOOST_STATIC_ASSERT(std::numeric_limits<T>::digits10 < CHAR_MAX);
#endif

            char left = last_grp_size;
#endif

            typedef typename Traits::int_type int_type;
            CharT const czero = lcast_char_constants<CharT>::zero;
            int_type const zero = Traits::to_int_type(czero);

            do
            {
#ifndef STREAMS_BOOST_LEXICAL_CAST_ASSUME_C_LOCALE
                if(left == 0)
                {
                    ++group;
                    if(group < grouping_size)
                    {
                        char const grp_size = grouping[group];
                        last_grp_size = grp_size <= 0 ? CHAR_MAX : grp_size;
                    }

                    left = last_grp_size;
                    --finish;
                    Traits::assign(*finish, thousands_sep);
                }

                --left;
#endif

                --finish;
                int_type const digit = static_cast<int_type>(n % 10U);
                Traits::assign(*finish, Traits::to_char_type(zero + digit));
                n /= 10;
            } while(n);

            return finish;
        }
    }

    namespace detail // stream wrapper for handling lexical conversions
    {
        template<typename Target, typename Source, typename Traits>
        class lexical_stream
        {
        private:
            typedef typename widest_char<
                typename stream_char<Target>::type,
                typename stream_char<Source>::type>::type char_type;

            typedef Traits traits_type;

        public:
            lexical_stream(char_type* = 0, char_type* = 0)
            {
                stream.unsetf(std::ios::skipws);
                lcast_set_precision(stream, static_cast<Source*>(0), static_cast<Target*>(0) );
            }
            ~lexical_stream()
            {
                #if defined(STREAMS_BOOST_NO_STRINGSTREAM)
                stream.freeze(false);
                #endif
            }
            bool operator<<(const Source &input)
            {
                return !(stream << input).fail();
            }
            template<typename InputStreamable>
            bool operator>>(InputStreamable &output)
            {
                return !is_pointer<InputStreamable>::value &&
                       stream >> output &&
                       stream.get() ==
#if defined(__GNUC__) && (__GNUC__<3) && defined(STREAMS_BOOST_NO_STD_WSTRING)
// GCC 2.9x lacks std::char_traits<>::eof().
// We use STREAMS_BOOST_NO_STD_WSTRING to filter out STLport and libstdc++-v3
// configurations, which do provide std::char_traits<>::eof().
    
                           EOF;
#else
                           traits_type::eof();
#endif
            }

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

            bool operator>>(std::string &output)
            {
                #if defined(STREAMS_BOOST_NO_STRINGSTREAM)
                stream << '\0';
                #endif
                stream.str().swap(output);
                return true;
            }
            #ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
            bool operator>>(std::wstring &output)
            {
                stream.str().swap(output);
                return true;
            }
            #endif

#else
            bool operator>>(std::basic_string<char_type,traits_type>& output)
            {
                stream.str().swap(output);
                return true;
            }

            template<class Alloc>
            bool operator>>(std::basic_string<char_type,traits_type,Alloc>& out)
            {
                std::basic_string<char_type,traits_type> str(stream.str());
                out.assign(str.begin(), str.end());
                return true;
            }
#endif
        private:
            #if defined(STREAMS_BOOST_NO_STRINGSTREAM)
            std::strstream stream;
            #elif defined(STREAMS_BOOST_NO_STD_LOCALE)
            std::stringstream stream;
            #else
            std::basic_stringstream<char_type,traits_type> stream;
            #endif
        };
    }

    namespace detail // optimized stream wrapper
    {
        // String representation of Source has an upper limit.
        template< class CharT // a result of widest_char transformation
                , class Base // lexical_streambuf_fake or basic_streambuf<CharT>
                , class Traits // usually char_traits<CharT>
                >
        class lexical_stream_limited_src : public Base
        {
            // A string representation of Source is written to [start, finish).
            // Currently, it is assumed that [start, finish) is big enough
            // to hold a string representation of any Source value.
            CharT* start;
            CharT* finish;

        private:

            static void widen_and_assign(char*p, char ch)
            {
                Traits::assign(*p, ch);
            }

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
            static void widen_and_assign(wchar_t* p, char ch)
            {
                // TODO: use STREAMS_BOOST_NO_STD_LOCALE
                std::locale loc;
                wchar_t w = STREAMS_BOOST_USE_FACET(std::ctype<wchar_t>, loc).widen(ch);
                Traits::assign(*p, w);
            }

            static void widen_and_assign(wchar_t* p, wchar_t ch)
            {
                Traits::assign(*p, ch);
            }

            static void widen_and_assign(char*, wchar_t ch); // undefined
#endif

            template<class OutputStreamable>
            bool lcast_put(const OutputStreamable& input)
            {
                this->setp(start, finish);
                std::basic_ostream<CharT> stream(static_cast<Base*>(this));
                lcast_set_precision(stream, static_cast<OutputStreamable*>(0));
                bool const result = !(stream << input).fail();
                finish = this->pptr();
                return result;
            }

            // Undefined:
            lexical_stream_limited_src(lexical_stream_limited_src const&);
            void operator=(lexical_stream_limited_src const&);

        public:

            lexical_stream_limited_src(CharT* sta, CharT* fin)
              : start(sta)
              , finish(fin)
            {}

        public: // output

            template<class Alloc>
            bool operator<<(std::basic_string<CharT,Traits,Alloc> const& str)
            {
                start = const_cast<CharT*>(str.data());
                finish = start + str.length();
                return true;
            }

            bool operator<<(bool);
            bool operator<<(char);
#if !defined(STREAMS_BOOST_LCAST_NO_WCHAR_T) && !defined(STREAMS_BOOST_NO_INTRINSIC_WCHAR_T)
            bool operator<<(wchar_t);
#endif
            bool operator<<(CharT const*);
            bool operator<<(short);
            bool operator<<(int);
            bool operator<<(long);
            bool operator<<(unsigned short);
            bool operator<<(unsigned int);
            bool operator<<(unsigned long);
#if defined(STREAMS_BOOST_HAS_LONG_LONG)
            bool operator<<(streams_boost::ulong_long_type);
            bool operator<<(streams_boost::long_long_type );
#elif defined(STREAMS_BOOST_HAS_MS_INT64)
            bool operator<<(unsigned __int64);
            bool operator<<(         __int64);
#endif
            // These three operators use ostream and streambuf.
            // lcast_streambuf_for_source<T>::value is true.
            bool operator<<(float);
            bool operator<<(double);
            bool operator<<(long double);

        public: // input

            // Generic istream-based algorithm.
            // lcast_streambuf_for_target<InputStreamable>::value is true.
            template<typename InputStreamable>
            bool operator>>(InputStreamable& output)
            {
#if (defined _MSC_VER)
# pragma warning( push )
  // conditional expression is constant
# pragma warning( disable : 4127 )
#endif
                if(is_pointer<InputStreamable>::value)
                    return false;

                this->setg(start, start, finish);
                std::basic_istream<CharT> stream(static_cast<Base*>(this));
                stream.unsetf(std::ios::skipws);
                lcast_set_precision(stream, static_cast<InputStreamable*>(0));
#if (defined _MSC_VER)
# pragma warning( pop )
#endif
                return stream >> output &&
                    stream.get() ==
#if defined(__GNUC__) && (__GNUC__<3) && defined(STREAMS_BOOST_NO_STD_WSTRING)
        // GCC 2.9x lacks std::char_traits<>::eof().
        // We use STREAMS_BOOST_NO_STD_WSTRING to filter out STLport and libstdc++-v3
        // configurations, which do provide std::char_traits<>::eof().

                    EOF;
#else
                Traits::eof();
#endif
            }

            bool operator>>(CharT&);

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
// This #if is in sync with lcast_streambuf_for_target

            bool operator>>(std::string&);

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
            bool operator>>(std::wstring&);
#endif

#else
            template<class Alloc>
            bool operator>>(std::basic_string<CharT,Traits,Alloc>& str)
            {
                str.assign(start, finish);
                return true;
            }
#endif
        };

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                bool value)
        {
            typedef typename Traits::int_type int_type;
            CharT const czero = lcast_char_constants<CharT>::zero;
            int_type const zero = Traits::to_int_type(czero);
            Traits::assign(*start, Traits::to_char_type(zero + value));
            finish = start + 1;
            return true;
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                char ch)
        {
            widen_and_assign(start, ch);
            finish = start + 1;
            return true;
        }

#if !defined(STREAMS_BOOST_LCAST_NO_WCHAR_T) && !defined(STREAMS_BOOST_NO_INTRINSIC_WCHAR_T)
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                wchar_t ch)
        {
            widen_and_assign(start, ch);
            finish = start + 1;
            return true;
        }
#endif

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                short n)
        {
            start = lcast_put_unsigned<Traits>(lcast_to_unsigned(n), finish);
            if(n < 0)
            {
                --start;
                CharT const minus = lcast_char_constants<CharT>::minus;
                Traits::assign(*start, minus);
            }
            return true;
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                int n)
        {
            start = lcast_put_unsigned<Traits>(lcast_to_unsigned(n), finish);
            if(n < 0)
            {
                --start;
                CharT const minus = lcast_char_constants<CharT>::minus;
                Traits::assign(*start, minus);
            }
            return true;
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                long n)
        {
            start = lcast_put_unsigned<Traits>(lcast_to_unsigned(n), finish);
            if(n < 0)
            {
                --start;
                CharT const minus = lcast_char_constants<CharT>::minus;
                Traits::assign(*start, minus);
            }
            return true;
        }

#if defined(STREAMS_BOOST_HAS_LONG_LONG)
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                streams_boost::long_long_type n)
        {
            start = lcast_put_unsigned<Traits>(lcast_to_unsigned(n), finish);
            if(n < 0)
            {
                --start;
                CharT const minus = lcast_char_constants<CharT>::minus;
                Traits::assign(*start, minus);
            }
            return true;
        }
#elif defined(STREAMS_BOOST_HAS_MS_INT64)
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                __int64 n)
        {
            start = lcast_put_unsigned<Traits>(lcast_to_unsigned(n), finish);
            if(n < 0)
            {
                --start;
                CharT const minus = lcast_char_constants<CharT>::minus;
                Traits::assign(*start, minus);
            }
            return true;
        }
#endif

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                unsigned short n)
        {
            start = lcast_put_unsigned<Traits>(n, finish);
            return true;
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                unsigned int n)
        {
            start = lcast_put_unsigned<Traits>(n, finish);
            return true;
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                unsigned long n)
        {
            start = lcast_put_unsigned<Traits>(n, finish);
            return true;
        }

#if defined(STREAMS_BOOST_HAS_LONG_LONG)
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                streams_boost::ulong_long_type n)
        {
            start = lcast_put_unsigned<Traits>(n, finish);
            return true;
        }
#elif defined(STREAMS_BOOST_HAS_MS_INT64)
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                unsigned __int64 n)
        {
            start = lcast_put_unsigned<Traits>(n, finish);
            return true;
        }
#endif

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                float val)
        {
            return this->lcast_put(val);
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                double val)
        {
            return this->lcast_put(val);
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                long double val)
        {
            return this->lcast_put(val);
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator<<(
                CharT const* str)
        {
            start = const_cast<CharT*>(str);
            finish = start + Traits::length(str);
            return true;
        }

        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator>>(
                CharT& output)
        {
            bool const ok = (finish - start == 1);
            if(ok)
                Traits::assign(output, *start);
            return ok;
        }

#ifdef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator>>(
                std::string& str)
        {
            str.assign(start, finish);
            return true;
        }

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<typename CharT, class Base, class Traits>
        inline bool lexical_stream_limited_src<CharT,Base,Traits>::operator>>(
                std::wstring& str)
        {
            str.assign(start, finish);
            return true;
        }
#endif
#endif
    }

    namespace detail // lcast_streambuf_for_source
    {
        // Returns true if optimized stream wrapper needs ostream for writing.
        template<class Source>
        struct lcast_streambuf_for_source
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };

        template<>
        struct lcast_streambuf_for_source<float>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
        };
 
        template<>
        struct lcast_streambuf_for_source<double>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
        };
  
        template<>
        struct lcast_streambuf_for_source<long double>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
        };
    }

    namespace detail // lcast_streambuf_for_target
    {
        // Returns true if optimized stream wrapper needs istream for reading.
        template<class Target>
        struct lcast_streambuf_for_target
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = true);
        };

        template<>
        struct lcast_streambuf_for_target<char>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };

#if !defined(STREAMS_BOOST_LCAST_NO_WCHAR_T) && !defined(STREAMS_BOOST_NO_INTRINSIC_WCHAR_T)
        template<>
        struct lcast_streambuf_for_target<wchar_t>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };
#endif

#ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
        template<class Traits, class Alloc>
        struct lcast_streambuf_for_target<
                    std::basic_string<char,Traits,Alloc> >
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<class Traits, class Alloc>
        struct lcast_streambuf_for_target<
                    std::basic_string<wchar_t,Traits,Alloc> >
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };
#endif
#else
        template<>
        struct lcast_streambuf_for_target<std::string>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };

#ifndef STREAMS_BOOST_LCAST_NO_WCHAR_T
        template<>
        struct lcast_streambuf_for_target<std::wstring>
        {
            STREAMS_BOOST_STATIC_CONSTANT(bool, value = false);
        };
#endif
#endif
    }

    #ifndef STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

    // call-by-const reference version

    namespace detail
    {
        template<class T>
        struct array_to_pointer_decay
        {
            typedef T type;
        };

        template<class T, std::size_t N>
        struct array_to_pointer_decay<T[N]>
        {
            typedef const T * type;
        };

#if (defined _MSC_VER)
# pragma warning( push )
# pragma warning( disable : 4701 ) // possible use of ... before initialization
# pragma warning( disable : 4702 ) // unreachable code
#endif

        template< typename Target
                , typename Source
                , bool Unlimited // string representation of Source is unlimited
                , typename CharT
                >
        Target lexical_cast(
            STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::call_traits<Source>::param_type arg,
            CharT* buf, std::size_t src_len)
        {
            typedef STREAMS_BOOST_DEDUCED_TYPENAME
                deduce_char_traits<CharT,Target,Source>::type traits;

            typedef STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::mpl::if_c<
                lcast_streambuf_for_target<Target>::value ||
                lcast_streambuf_for_source<Source>::value
              , std::basic_streambuf<CharT>
              , lexical_streambuf_fake
              >::type base;

            STREAMS_BOOST_DEDUCED_TYPENAME streams_boost::mpl::if_c<
                Unlimited
              , detail::lexical_stream<Target,Source,traits>
              , detail::lexical_stream_limited_src<CharT,base,traits>
              >::type interpreter(buf, buf + src_len);

            Target result;
            if(!(interpreter << arg && interpreter >> result))
                STREAMS_BOOST_LCAST_THROW_BAD_CAST(Source, Target);
            return result;
        }
#if (defined _MSC_VER)
# pragma warning( pop )
#endif
    }

    template<typename Target, typename Source>
    inline Target lexical_cast(const Source &arg)
    {
        typedef typename detail::array_to_pointer_decay<Source>::type src;

        typedef typename detail::widest_char<
            typename detail::stream_char<Target>::type
          , typename detail::stream_char<src>::type
          >::type char_type;

        typedef detail::lcast_src_length<char_type, src> lcast_src_length;
        std::size_t const src_len = lcast_src_length::value;
        char_type buf[src_len + 1];
        lcast_src_length::check_coverage();
        return detail::lexical_cast<Target, src, !src_len>(arg, buf, src_len);
    }

    #else

    // call-by-value fallback version (deprecated)

    template<typename Target, typename Source>
    Target lexical_cast(Source arg)
    {
        typedef typename detail::widest_char< 
            STREAMS_BOOST_DEDUCED_TYPENAME detail::stream_char<Target>::type 
          , STREAMS_BOOST_DEDUCED_TYPENAME detail::stream_char<Source>::type 
        >::type char_type; 

        typedef std::char_traits<char_type> traits;
        detail::lexical_stream<Target, Source, traits> interpreter;
        Target result;

        if(!(interpreter << arg && interpreter >> result))
#ifndef STREAMS_BOOST_NO_TYPEID
            throw_exception(bad_lexical_cast(typeid(Source), typeid(Target)));
#else
            throw_exception(bad_lexical_cast());
#endif
        return result;
    }

    #endif
}

// Copyright Kevlin Henney, 2000-2005.
// Copyright Alexander Nasonov, 2006-2007.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

#undef STREAMS_BOOST_LCAST_NO_WCHAR_T
#endif
