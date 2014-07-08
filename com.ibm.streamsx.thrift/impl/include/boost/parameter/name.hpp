// Copyright Daniel Wallin 2006. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)

#ifndef STREAMS_BOOST_PARAMETER_NAME_060806_HPP
# define STREAMS_BOOST_PARAMETER_NAME_060806_HPP

# include <streams_boost/parameter/keyword.hpp>
# include <streams_boost/parameter/value_type.hpp>
# include <streams_boost/detail/workaround.hpp>
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/stringize.hpp>
# include <streams_boost/preprocessor/control/iif.hpp>
# include <streams_boost/preprocessor/tuple/eat.hpp>
# include <streams_boost/preprocessor/tuple/elem.hpp>
# include <streams_boost/mpl/placeholders.hpp>

# if !defined(STREAMS_BOOST_NO_SFINAE) \
  && !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
  && !STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x592))

#  include <streams_boost/utility/enable_if.hpp>
#  include <streams_boost/mpl/lambda.hpp>

namespace streams_boost { namespace parameter { namespace aux {

// Tag type passed to MPL lambda.
struct lambda_tag;

struct name_tag_base 
{};

template <class Tag>
struct name_tag
{};

template <class T>
struct is_name_tag
  : mpl::false_
{};

}}} // namespace streams_boost::parameter::aux

namespace streams_boost { namespace mpl {

template <class T>
struct lambda<
    T
  , typename enable_if<
        parameter::aux::is_name_tag<T>, parameter::aux::lambda_tag
    >::type
>
{
    typedef true_ is_le;
    typedef bind3< quote3<parameter::value_type>, arg<2>, T, void> result_;
    typedef result_ type;
};

}} // namespace streams_boost::mpl

# endif

# if STREAMS_BOOST_WORKAROUND(__BORLANDC__, STREAMS_BOOST_TESTED_AT(0x564))
# include <streams_boost/preprocessor/detail/split.hpp>
// From Paul Mensonides
#  define STREAMS_BOOST_PARAMETER_IS_BINARY(x) \
    STREAMS_BOOST_PP_SPLIT(1, STREAMS_BOOST_PARAMETER_IS_BINARY_C x STREAMS_BOOST_PP_COMMA() 0) \
    /**/
#  define STREAMS_BOOST_PARAMETER_IS_BINARY_C(x,y) \
    ~, 1 STREAMS_BOOST_PP_RPAREN() \
    STREAMS_BOOST_PP_TUPLE_EAT(2) STREAMS_BOOST_PP_LPAREN() ~ \
    /**/
# else
#  include <streams_boost/preprocessor/detail/is_binary.hpp>
#  define STREAMS_BOOST_PARAMETER_IS_BINARY(x) STREAMS_BOOST_PP_IS_BINARY(x)
# endif

# if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC, < 1300)
#  define STREAMS_BOOST_PARAMETER_NAME_OBJECT(tag, name)                    \
    static ::streams_boost::parameter::keyword<tag> const& name             \
       = ::streams_boost::parameter::keyword<tag>::instance;
# else
#  define STREAMS_BOOST_PARAMETER_NAME_OBJECT(tag, name)                    \
    namespace                                                       \
    {                                                               \
       ::streams_boost::parameter::keyword<tag> const& name                 \
       = ::streams_boost::parameter::keyword<tag>::instance;                \
    }
# endif

# define STREAMS_BOOST_PARAMETER_BASIC_NAME(tag_namespace, tag, name)       \
    namespace tag_namespace                                         \
    {                                                               \
      struct tag                                                    \
      {                                                             \
          static char const* keyword_name()                         \
          {                                                         \
              return STREAMS_BOOST_PP_STRINGIZE(tag);                       \
          }                                                         \
                                                                    \
          typedef streams_boost::parameter::value_type<                     \
              streams_boost::mpl::_2, tag, streams_boost::parameter::void_          \
          > _;                                                      \
                                                                    \
          typedef streams_boost::parameter::value_type<                     \
              streams_boost::mpl::_2, tag, streams_boost::parameter::void_          \
          > _1;                                                     \
      };                                                            \
    }                                                               \
    STREAMS_BOOST_PARAMETER_NAME_OBJECT(tag_namespace::tag, name)

# define STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TUPLE1(tag,namespace)         \
    (tag, namespace), ~

# define STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TUPLE(name)                   \
    STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, (STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TUPLE1 name))

# define STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TAG(name)                     \
    STREAMS_BOOST_PP_TUPLE_ELEM(2, 0, STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TUPLE(name))

# define STREAMS_BOOST_PARAMETER_COMPLEX_NAME_NAMESPACE(name)               \
    STREAMS_BOOST_PP_TUPLE_ELEM(2, 1, STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TUPLE(name))

# define STREAMS_BOOST_PARAMETER_COMPLEX_NAME(name)                         \
    STREAMS_BOOST_PARAMETER_BASIC_NAME(                                     \
        STREAMS_BOOST_PARAMETER_COMPLEX_NAME_NAMESPACE(name)                \
      , STREAMS_BOOST_PP_TUPLE_EAT(2) name                                  \
      , STREAMS_BOOST_PARAMETER_COMPLEX_NAME_TAG(name)                      \
    )                                                               \
/**/

# define STREAMS_BOOST_PARAMETER_SIMPLE_NAME(name)                          \
    STREAMS_BOOST_PARAMETER_BASIC_NAME(tag, name, STREAMS_BOOST_PP_CAT(_, name))

# define STREAMS_BOOST_PARAMETER_NAME(name)                                 \
    STREAMS_BOOST_PP_IIF(                                                   \
        STREAMS_BOOST_PARAMETER_IS_BINARY(name)                             \
      , STREAMS_BOOST_PARAMETER_COMPLEX_NAME                                \
      , STREAMS_BOOST_PARAMETER_SIMPLE_NAME                                 \
    )(name)                                                         \
/**/


# define STREAMS_BOOST_PARAMETER_TEMPLATE_KEYWORD(name)                     \
    namespace tag                                                   \
    {                                                               \
      struct name;                                                  \
    }                                                               \
    template <class T>                                              \
    struct name                                                     \
      : streams_boost::parameter::template_keyword<tag::name, T>            \
    {};                                                             \
/**/

#endif // STREAMS_BOOST_PARAMETER_NAME_060806_HPP

