// Boost.Signals library

// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

// For more information, see http://www.streams_boost.org

#ifndef STREAMS_BOOST_SIGNALS_SLOT_CALL_ITERATOR
#define STREAMS_BOOST_SIGNALS_SLOT_CALL_ITERATOR

#include <memory>
#include <streams_boost/iterator/iterator_facade.hpp>
#include <streams_boost/smart_ptr.hpp>
#include <streams_boost/signals/detail/config.hpp>
#include <streams_boost/signals/connection.hpp>
#include <streams_boost/optional.hpp>

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_PREFIX
#endif

namespace streams_boost {
  namespace STREAMS_BOOST_SIGNALS_NAMESPACE {
    namespace detail {

      // Generates a slot call iterator. Essentially, this is an iterator that:
      //   - skips over disconnected slots in the underlying list
      //   - calls the connected slots when dereferenced
      //   - caches the result of calling the slots
      template<typename Function, typename Iterator>
      class slot_call_iterator
        : public iterator_facade<slot_call_iterator<Function, Iterator>,
                                 typename Function::result_type,
                                 single_pass_traversal_tag,
                                 typename Function::result_type const&>
      {
        typedef iterator_facade<slot_call_iterator<Function, Iterator>,
                                typename Function::result_type,
                                single_pass_traversal_tag,
                                typename Function::result_type const&>
          inherited;

        typedef typename Function::result_type result_type;

        friend class iterator_core_access;

      public:
        slot_call_iterator(Iterator iter_in, Iterator end_in, Function f,
                           optional<result_type> &c)
          : iter(iter_in), end(end_in), f(f), cache(&c)
        {
          iter = std::find_if(iter, end, is_callable());
        }

        typename inherited::reference
        dereference() const
        {
          if (!cache->is_initialized()) {
            cache->reset(f(*iter));
          }

          return cache->get();
        }

        void increment()
        {
          iter = std::find_if(++iter, end, is_callable());
          cache->reset();
        }

        bool equal(const slot_call_iterator& other) const
        {
          iter = std::find_if(iter, end, is_callable());
          other.iter = std::find_if(other.iter, other.end,
                                    is_callable());
          return iter == other.iter;
        }

      private:
        mutable Iterator iter;
        Iterator end;
        Function f;
        optional<result_type>* cache;
      };
    } // end namespace detail
  } // end namespace STREAMS_BOOST_SIGNALS_NAMESPACE
} // end namespace streams_boost

#ifdef STREAMS_BOOST_HAS_ABI_HEADERS
#  include STREAMS_BOOST_ABI_SUFFIX
#endif

#endif // STREAMS_BOOST_SIGNALS_SLOT_CALL_ITERATOR
