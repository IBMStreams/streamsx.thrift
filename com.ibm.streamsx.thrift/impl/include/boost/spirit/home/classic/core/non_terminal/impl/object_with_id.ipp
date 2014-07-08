/*=============================================================================
    Copyright (c) 2002-2003 Joel de Guzman
    Copyright (c) 2002-2003 Martin Wille
    http://spirit.sourceforge.net/

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.streams_boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined STREAMS_BOOST_SPIRIT_OBJECT_WITH_ID_IPP
#define STREAMS_BOOST_SPIRIT_OBJECT_WITH_ID_IPP

#include <vector>
#include <streams_boost/shared_ptr.hpp>

#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
#include <streams_boost/thread/mutex.hpp>
#include <streams_boost/thread/once.hpp>
#endif

#include <streams_boost/spirit/home/classic/namespace.hpp>

///////////////////////////////////////////////////////////////////////////////
namespace streams_boost { namespace spirit {

STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_BEGIN

    namespace impl {

        //////////////////////////////////
        template <typename IdT = std::size_t>
        struct object_with_id_base_supply
        {
            typedef IdT                     object_id;
            typedef std::vector<object_id>  id_vector;

            object_with_id_base_supply() : max_id(object_id()) {}

#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
            streams_boost::mutex        mutex;
#endif
            object_id           max_id;
            id_vector           free_ids;

            object_id           acquire();
            void                release(object_id);
        };

        //////////////////////////////////
        template <typename TagT, typename IdT = std::size_t>
        struct object_with_id_base
        {
            typedef TagT        tag_t;
            typedef IdT         object_id;

        protected:

            object_id           acquire_object_id();
            void                release_object_id(object_id);

        private:
#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
            static streams_boost::mutex &mutex_instance();
            static void mutex_init();
#endif

            streams_boost::shared_ptr<object_with_id_base_supply<IdT> > id_supply;
        };

        //////////////////////////////////
        template<class TagT, typename IdT = std::size_t>
        struct object_with_id : private object_with_id_base<TagT, IdT>
        {
            typedef object_with_id<TagT, IdT>       self_t;
            typedef object_with_id_base<TagT, IdT>  base_t;
            typedef IdT                             object_id;

            object_with_id() : id(base_t::acquire_object_id()) {}
            object_with_id(self_t const &other)
                : base_t(other)
                , id(base_t::acquire_object_id())
            {} // don't copy id
            self_t &operator = (self_t const &other)
            {   // don't assign id
                base_t::operator=(other);
                return *this;
            }
            ~object_with_id() { base_t::release_object_id(id); }
            object_id get_object_id() const { return id; }

        private:

            object_id const id;
        };

        //////////////////////////////////
        template <typename IdT>
        inline IdT
        object_with_id_base_supply<IdT>::acquire()
        {
#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
            streams_boost::mutex::scoped_lock lock(mutex);
#endif
            if (free_ids.size())
            {
                object_id id = *free_ids.rbegin();
                free_ids.pop_back();
                return id;
            }
            else
            {
                if (free_ids.capacity()<=max_id)
                    free_ids.reserve(max_id*3/2+1);
                return ++max_id;
            }
        }

        //////////////////////////////////
        template <typename IdT>
        inline void
        object_with_id_base_supply<IdT>::release(IdT id)
        {
#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
            streams_boost::mutex::scoped_lock lock(mutex);
#endif
            if (max_id == id)
                max_id--;
            else
                free_ids.push_back(id); // doesn't throw
        }

        //////////////////////////////////
        template <typename TagT, typename IdT>
        inline IdT
        object_with_id_base<TagT, IdT>::acquire_object_id()
        {
            {
#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
                static streams_boost::once_flag been_here = STREAMS_BOOST_ONCE_INIT;
                streams_boost::call_once(been_here, mutex_init);
                streams_boost::mutex &mutex = mutex_instance();
                streams_boost::mutex::scoped_lock lock(mutex);
#endif
                static streams_boost::shared_ptr<object_with_id_base_supply<IdT> >
                    static_supply;

                if (!static_supply.get())
                    static_supply.reset(new object_with_id_base_supply<IdT>());
                id_supply = static_supply;
            }

            return id_supply->acquire();
        }

        //////////////////////////////////
        template <typename TagT, typename IdT>
        inline void
        object_with_id_base<TagT, IdT>::release_object_id(IdT id)
        {
            id_supply->release(id);
        }

        //////////////////////////////////
#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
        template <typename TagT, typename IdT>
        inline streams_boost::mutex &
        object_with_id_base<TagT, IdT>::mutex_instance()
        {
            static streams_boost::mutex mutex;
            return mutex;
        }
#endif

        //////////////////////////////////
#ifdef STREAMS_BOOST_SPIRIT_THREADSAFE
        template <typename TagT, typename IdT>
        inline void 
        object_with_id_base<TagT, IdT>::mutex_init()
        {
            mutex_instance();
        }
#endif

    } // namespace impl

///////////////////////////////////////////////////////////////////////////////
STREAMS_BOOST_SPIRIT_CLASSIC_NAMESPACE_END

}} // namespace streams_boost::spirit

#endif
