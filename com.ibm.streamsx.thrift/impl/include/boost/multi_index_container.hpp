/* Multiply indexed container.
 *
 * Copyright 2003-2009 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.streams_boost.org/LICENSE_1_0.txt)
 *
 * See http://www.streams_boost.org/libs/multi_index for library home page.
 */

#ifndef STREAMS_BOOST_MULTI_INDEX_HPP
#define STREAMS_BOOST_MULTI_INDEX_HPP

#if defined(_MSC_VER)&&(_MSC_VER>=1200)
#pragma once
#endif

#include <streams_boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <algorithm>
#include <streams_boost/detail/allocator_utilities.hpp>
#include <streams_boost/detail/no_exceptions_support.hpp>
#include <streams_boost/detail/workaround.hpp>
#include <streams_boost/mpl/at.hpp>
#include <streams_boost/mpl/contains.hpp>
#include <streams_boost/mpl/find_if.hpp>
#include <streams_boost/mpl/identity.hpp>
#include <streams_boost/mpl/int.hpp>
#include <streams_boost/mpl/size.hpp>
#include <streams_boost/mpl/deref.hpp>
#include <streams_boost/multi_index_container_fwd.hpp>
#include <streams_boost/multi_index/detail/access_specifier.hpp>
#include <streams_boost/multi_index/detail/adl_swap.hpp>
#include <streams_boost/multi_index/detail/base_type.hpp>
#include <streams_boost/multi_index/detail/converter.hpp>
#include <streams_boost/multi_index/detail/header_holder.hpp>
#include <streams_boost/multi_index/detail/has_tag.hpp>
#include <streams_boost/multi_index/detail/no_duplicate_tags.hpp>
#include <streams_boost/multi_index/detail/prevent_eti.hpp>
#include <streams_boost/multi_index/detail/safe_mode.hpp>
#include <streams_boost/multi_index/detail/scope_guard.hpp>
#include <streams_boost/static_assert.hpp>
#include <streams_boost/type_traits/is_same.hpp>
#include <streams_boost/utility/base_from_member.hpp>

#if !defined(STREAMS_BOOST_MULTI_INDEX_DISABLE_SERIALIZATION)
#include <streams_boost/multi_index/detail/archive_constructed.hpp>
#include <streams_boost/serialization/collection_size_type.hpp>
#include <streams_boost/serialization/nvp.hpp>
#include <streams_boost/serialization/split_member.hpp>
#include <streams_boost/serialization/version.hpp>
#include <streams_boost/throw_exception.hpp> 
#endif

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)
#include <streams_boost/multi_index/detail/invariant_assert.hpp>
#define STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT                                    \
  detail::scope_guard STREAMS_BOOST_JOIN(check_invariant_,__LINE__)=                 \
    detail::make_obj_guard(*this,&multi_index_container::check_invariant_);  \
  STREAMS_BOOST_JOIN(check_invariant_,__LINE__).touch();
#else
#define STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT
#endif

namespace streams_boost{

namespace multi_index{

template<typename Value,typename IndexSpecifierList,typename Allocator>
class multi_index_container:
  private ::streams_boost::base_from_member<
    typename streams_boost::detail::allocator::rebind_to<
      Allocator,
      typename detail::multi_index_node_type<
        Value,IndexSpecifierList,Allocator>::type
    >::type>,
  STREAMS_BOOST_MULTI_INDEX_PRIVATE_IF_MEMBER_TEMPLATE_FRIENDS detail::header_holder<
    typename detail::prevent_eti<
      Allocator,
      typename streams_boost::detail::allocator::rebind_to<
        Allocator,
        typename detail::multi_index_node_type<
          Value,IndexSpecifierList,Allocator>::type
      >::type
    >::type::pointer,
    multi_index_container<Value,IndexSpecifierList,Allocator> >,
  public detail::multi_index_base_type<
    Value,IndexSpecifierList,Allocator>::type
{
#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)&&\
    STREAMS_BOOST_WORKAROUND(__MWERKS__,<=0x3003)
/* The "ISO C++ Template Parser" option in CW8.3 has a problem with the
 * lifetime of const references bound to temporaries --precisely what
 * scopeguards are.
 */

#pragma parse_mfunc_templ off
#endif

private:
#if !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
  template <typename,typename,typename> friend class  detail::index_base;
  template <typename,typename>          friend struct detail::header_holder;
  template <typename,typename>          friend struct detail::converter;
#endif

  typedef typename detail::multi_index_base_type<
      Value,IndexSpecifierList,Allocator>::type   super;
  typedef typename
  streams_boost::detail::allocator::rebind_to<
      Allocator,
      typename super::node_type
  >::type                                         node_allocator;
  typedef ::streams_boost::base_from_member<
    node_allocator>                               bfm_allocator;
  typedef detail::header_holder<
    typename detail::prevent_eti<
      Allocator,
      node_allocator
    >::type::pointer,
    multi_index_container>                        bfm_header;

#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<1300)
  /* see definition of index_type_list below */
  typedef typename super::index_type_list         super_index_type_list;
#endif

public:
  /* All types are inherited from super, a few are explicitly
   * brought forward here to save us some typename's.
   */

  typedef typename super::ctor_args_list          ctor_args_list;
  typedef IndexSpecifierList                      index_specifier_type_list;
 
#if STREAMS_BOOST_WORKAROUND(STREAMS_BOOST_MSVC,<1300)
  /* MSVC++ 6.0 chokes on moderately long index lists (around 6 indices
   * or more), with errors ranging from corrupt exes to duplicate
   * comdats. The following type hiding hack alleviates this condition;
   * best results combined with type hiding of the indexed_by construct
   * itself, as explained in the "Compiler specifics" section of
   * the documentation.
   */

  struct index_type_list:super_index_type_list
  {
    typedef index_type_list                      type;
    typedef typename super_index_type_list::back back;
    typedef mpl::v_iter<type,0>                  begin;
    typedef mpl::v_iter<
      type,
      mpl::size<super_index_type_list>::value>   end;
  };
#else
  typedef typename super::index_type_list          index_type_list;
#endif

  typedef typename super::iterator_type_list       iterator_type_list;
  typedef typename super::const_iterator_type_list const_iterator_type_list;
  typedef typename super::value_type               value_type;
  typedef typename super::final_allocator_type     allocator_type;
  typedef typename super::iterator                 iterator;
  typedef typename super::const_iterator           const_iterator;

  STREAMS_BOOST_STATIC_ASSERT(
    detail::no_duplicate_tags_in_index_list<index_type_list>::value);

  /* global project() needs to see this publicly */

  typedef typename super::node_type node_type;

  /* construct/copy/destroy */

  explicit multi_index_container(

#if STREAMS_BOOST_WORKAROUND(__IBMCPP__,<=600)
    /* VisualAge seems to have an ETI issue with the default values
     * for arguments args_list and al.
     */

    const ctor_args_list& args_list=
      typename mpl::identity<multi_index_container>::type::
        ctor_args_list(),
    const allocator_type& al=
      typename mpl::identity<multi_index_container>::type::
        allocator_type()):
#else
    const ctor_args_list& args_list=ctor_args_list(),
    const allocator_type& al=allocator_type()):
#endif

    bfm_allocator(al),
    super(args_list,bfm_allocator::member),
    node_count(0)
  {
    STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT;
  }    

  explicit multi_index_container(const allocator_type& al):
    bfm_allocator(al),
    super(ctor_args_list(),bfm_allocator::member),
    node_count(0)
  {
    STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT;
  }

  template<typename InputIterator>
  multi_index_container(
    InputIterator first,InputIterator last,

#if STREAMS_BOOST_WORKAROUND(__IBMCPP__,<=600)
    /* VisualAge seems to have an ETI issue with the default values
     * for arguments args_list and al.
     */

    const ctor_args_list& args_list=
      typename mpl::identity<multi_index_container>::type::
        ctor_args_list(),
    const allocator_type& al=
      typename mpl::identity<multi_index_container>::type::
        allocator_type()):
#else
    const ctor_args_list& args_list=ctor_args_list(),
    const allocator_type& al=allocator_type()):
#endif

    bfm_allocator(al),
    super(args_list,bfm_allocator::member),
    node_count(0)
  {
    STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT;
    STREAMS_BOOST_TRY{
      iterator hint=super::end();
      for(;first!=last;++first){
        hint=super::make_iterator(insert_(*first,hint.get_node()).first);
      }
    }
    STREAMS_BOOST_CATCH(...){
      clear_();
      STREAMS_BOOST_RETHROW;
    }
    STREAMS_BOOST_CATCH_END
  }

  multi_index_container(
    const multi_index_container<Value,IndexSpecifierList,Allocator>& x):
    bfm_allocator(x.bfm_allocator::member),
    bfm_header(),
    super(x),
    node_count(0)
  {
    copy_map_type map(bfm_allocator::member,x.size(),x.header(),header());
    for(const_iterator it=x.begin(),it_end=x.end();it!=it_end;++it){
      map.clone(it.get_node());
    }
    super::copy_(x,map);
    map.release();
    node_count=x.size();

    /* Not until this point are the indices required to be consistent,
     * hence the position of the invariant checker.
     */

    STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT;
  }

  ~multi_index_container()
  {
    delete_all_nodes_();
  }

  multi_index_container<Value,IndexSpecifierList,Allocator>& operator=(
    multi_index_container<Value,IndexSpecifierList,Allocator> x)
  {
    STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT;
    this->swap(x);
    return *this;
  }

  allocator_type get_allocator()const
  {
    return allocator_type(bfm_allocator::member);
  }

  /* retrieval of indices by number */

#if !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATES)
  template<int N>
  struct nth_index
  {
    STREAMS_BOOST_STATIC_ASSERT(N>=0&&N<mpl::size<index_type_list>::type::value);
    typedef typename mpl::at_c<index_type_list,N>::type type;
  };

  template<int N>
  typename nth_index<N>::type& get(STREAMS_BOOST_EXPLICIT_TEMPLATE_NON_TYPE(int,N))
  {
    STREAMS_BOOST_STATIC_ASSERT(N>=0&&N<mpl::size<index_type_list>::type::value);
    return *this;
  }

  template<int N>
  const typename nth_index<N>::type& get(
    STREAMS_BOOST_EXPLICIT_TEMPLATE_NON_TYPE(int,N))const
  {
    STREAMS_BOOST_STATIC_ASSERT(N>=0&&N<mpl::size<index_type_list>::type::value);
    return *this;
  }
#endif

  /* retrieval of indices by tag */

#if !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATES)
  template<typename Tag>
  struct index
  {
    typedef typename mpl::find_if<
      index_type_list,
      detail::has_tag<Tag>
    >::type                                    iter;

    STREAMS_BOOST_STATIC_CONSTANT(
      bool,index_found=!(is_same<iter,typename mpl::end<index_type_list>::type >::value));
    STREAMS_BOOST_STATIC_ASSERT(index_found);

    typedef typename mpl::deref<iter>::type    type;
  };

  template<typename Tag>
  typename index<Tag>::type& get(STREAMS_BOOST_EXPLICIT_TEMPLATE_TYPE(Tag))
  {
    return *this;
  }

  template<typename Tag>
  const typename index<Tag>::type& get(
    STREAMS_BOOST_EXPLICIT_TEMPLATE_TYPE(Tag))const
  {
    return *this;
  }
#endif

  /* projection of iterators by number */

#if !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATES)
  template<int N>
  struct nth_index_iterator
  {
    typedef typename nth_index<N>::type::iterator type;
  };

  template<int N>
  struct nth_index_const_iterator
  {
    typedef typename nth_index<N>::type::const_iterator type;
  };

  template<int N,typename IteratorType>
  typename nth_index_iterator<N>::type project(
    IteratorType it
    STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(int,N))
  {
    typedef typename nth_index<N>::type index;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    STREAMS_BOOST_STATIC_ASSERT(
      (mpl::contains<iterator_type_list,IteratorType>::value));
#endif

    STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<typename IteratorType::container_type&>(*this));

    return index::make_iterator(static_cast<node_type*>(it.get_node()));
  }

  template<int N,typename IteratorType>
  typename nth_index_const_iterator<N>::type project(
    IteratorType it
    STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(int,N))const
  {
    typedef typename nth_index<N>::type index;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    STREAMS_BOOST_STATIC_ASSERT((
      mpl::contains<iterator_type_list,IteratorType>::value||
      mpl::contains<const_iterator_type_list,IteratorType>::value));
#endif

    STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<const typename IteratorType::container_type&>(*this));
    return index::make_iterator(static_cast<node_type*>(it.get_node()));
  }
#endif

  /* projection of iterators by tag */

#if !defined(STREAMS_BOOST_NO_MEMBER_TEMPLATES)
  template<typename Tag>
  struct index_iterator
  {
    typedef typename index<Tag>::type::iterator type;
  };

  template<typename Tag>
  struct index_const_iterator
  {
    typedef typename index<Tag>::type::const_iterator type;
  };

  template<typename Tag,typename IteratorType>
  typename index_iterator<Tag>::type project(
    IteratorType it
    STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))
  {
    typedef typename index<Tag>::type index;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    STREAMS_BOOST_STATIC_ASSERT(
      (mpl::contains<iterator_type_list,IteratorType>::value));
#endif

    STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<typename IteratorType::container_type&>(*this));
    return index::make_iterator(static_cast<node_type*>(it.get_node()));
  }

  template<typename Tag,typename IteratorType>
  typename index_const_iterator<Tag>::type project(
    IteratorType it
    STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))const
  {
    typedef typename index<Tag>::type index;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    STREAMS_BOOST_STATIC_ASSERT((
      mpl::contains<iterator_type_list,IteratorType>::value||
      mpl::contains<const_iterator_type_list,IteratorType>::value));
#endif

    STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<const typename IteratorType::container_type&>(*this));
    return index::make_iterator(static_cast<node_type*>(it.get_node()));
  }
#endif

STREAMS_BOOST_MULTI_INDEX_PROTECTED_IF_MEMBER_TEMPLATE_FRIENDS:
  typedef typename super::copy_map_type copy_map_type;

  node_type* header()const
  {
    return &*bfm_header::member;
  }

  node_type* allocate_node()
  {
    return &*bfm_allocator::member.allocate(1);
  }

  void deallocate_node(node_type* x)
  {
    typedef typename node_allocator::pointer node_pointer;
    bfm_allocator::member.deallocate(static_cast<node_pointer>(x),1);
  }

  bool empty_()const
  {
    return node_count==0;
  }

  std::size_t size_()const
  {
    return node_count;
  }

  std::size_t max_size_()const
  {
    return static_cast<std::size_t >(-1);
  }

  std::pair<node_type*,bool> insert_(const Value& v)
  {
    node_type* x=allocate_node();
    STREAMS_BOOST_TRY{
      node_type* res=super::insert_(v,x);
      if(res==x){
        ++node_count;
        return std::pair<node_type*,bool>(res,true);
      }
      else{
        deallocate_node(x);
        return std::pair<node_type*,bool>(res,false);
      }
    }
    STREAMS_BOOST_CATCH(...){
      deallocate_node(x);
      STREAMS_BOOST_RETHROW;
    }
    STREAMS_BOOST_CATCH_END
  }

  std::pair<node_type*,bool> insert_(const Value& v,node_type* position)
  {
    node_type* x=allocate_node();
    STREAMS_BOOST_TRY{
      node_type* res=super::insert_(v,position,x);
      if(res==x){
        ++node_count;
        return std::pair<node_type*,bool>(res,true);
      }
      else{
        deallocate_node(x);
        return std::pair<node_type*,bool>(res,false);
      }
    }
    STREAMS_BOOST_CATCH(...){
      deallocate_node(x);
      STREAMS_BOOST_RETHROW;
    }
    STREAMS_BOOST_CATCH_END
  }

  void erase_(node_type* x)
  {
    --node_count;
    super::erase_(x);
    deallocate_node(x);
  }

  void delete_node_(node_type* x)
  {
    super::delete_node_(x);
    deallocate_node(x);
  }

  void delete_all_nodes_()
  {
    super::delete_all_nodes_();
  }

  void clear_()
  {
    delete_all_nodes_();
    super::clear_();
    node_count=0;
  }

  void swap_(multi_index_container<Value,IndexSpecifierList,Allocator>& x)
  {
    if(bfm_allocator::member!=x.bfm_allocator::member){
      detail::adl_swap(bfm_allocator::member,x.bfm_allocator::member);
    }
    std::swap(bfm_header::member,x.bfm_header::member);
    super::swap_(x);
    std::swap(node_count,x.node_count);
  }

  bool replace_(const Value& k,node_type* x)
  {
    return super::replace_(k,x);
  }

  template<typename Modifier>
  bool modify_(Modifier& mod,node_type* x)
  {
    mod(const_cast<value_type&>(x->value()));

    STREAMS_BOOST_TRY{
      if(!super::modify_(x)){
        deallocate_node(x);
        --node_count;
        return false;
      }
      else return true;
    }
    STREAMS_BOOST_CATCH(...){
      deallocate_node(x);
      --node_count;
      STREAMS_BOOST_RETHROW;
    }
    STREAMS_BOOST_CATCH_END
  }

  template<typename Modifier,typename Rollback>
  bool modify_(Modifier& mod,Rollback& back,node_type* x)
  {
    mod(const_cast<value_type&>(x->value()));

    bool b;
    STREAMS_BOOST_TRY{
      b=super::modify_rollback_(x);
    }
    STREAMS_BOOST_CATCH(...){
      STREAMS_BOOST_TRY{
        back(const_cast<value_type&>(x->value()));
        STREAMS_BOOST_RETHROW;
      }
      STREAMS_BOOST_CATCH(...){
        this->erase_(x);
        STREAMS_BOOST_RETHROW;
      }
      STREAMS_BOOST_CATCH_END
    }
    STREAMS_BOOST_CATCH_END

    STREAMS_BOOST_TRY{
      if(!b){
        back(const_cast<value_type&>(x->value()));
        return false;
      }
      else return true;
    }
    STREAMS_BOOST_CATCH(...){
      this->erase_(x);
      STREAMS_BOOST_RETHROW;
    }
    STREAMS_BOOST_CATCH_END
  }

#if !defined(STREAMS_BOOST_MULTI_INDEX_DISABLE_SERIALIZATION)
  /* serialization */

  friend class streams_boost::serialization::access;

  STREAMS_BOOST_SERIALIZATION_SPLIT_MEMBER()

  typedef typename super::index_saver_type        index_saver_type;
  typedef typename super::index_loader_type       index_loader_type;

  template<class Archive>
  void save(Archive& ar,const unsigned int version)const
  {

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    const serialization::collection_size_type s(size_());
    ar<<serialization::make_nvp("count",s);
#else
    const std::size_t s=size_();
    ar<<serialization::make_nvp("count",s);
#endif

    index_saver_type sm(bfm_allocator::member,s);

    for(iterator it=super::begin(),it_end=super::end();it!=it_end;++it){
      ar<<serialization::make_nvp("item",*it);
      sm.add(it.get_node(),ar,version);
    }
    sm.add_track(header(),ar,version);

    super::save_(ar,version,sm);
  }

  template<class Archive>
  void load(Archive& ar,const unsigned int version)
  {
    STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT;

    clear_(); 

#if !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    serialization::collection_size_type s;
    if(version<1){
      std::size_t sz;
      ar>>serialization::make_nvp("count",sz);
      s=sz;
    }
    else{
      ar>>serialization::make_nvp("count",s);
    }
#else
    std::size_t s;
    ar>>serialization::make_nvp("count",s);
#endif

    index_loader_type lm(bfm_allocator::member,s);

    for(std::size_t n=0;n<s;++n){
      detail::archive_constructed<Value> value("item",ar,version);
      std::pair<node_type*,bool> p=insert_(
        value.get(),super::end().get_node());
      if(!p.second)throw_exception(
        archive::archive_exception(
          archive::archive_exception::other_exception));
      ar.reset_object_address(&p.first->value(),&value.get());
      lm.add(p.first,ar,version);
    }
    lm.add_track(header(),ar,version);

    super::load_(ar,version,lm);
  }
#endif

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)
  /* invariant stuff */

  bool invariant_()const
  {
    return super::invariant_();
  }

  void check_invariant_()const
  {
    STREAMS_BOOST_MULTI_INDEX_INVARIANT_ASSERT(invariant_());
  }
#endif

private:
  std::size_t node_count;

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)&&\
    STREAMS_BOOST_WORKAROUND(__MWERKS__,<=0x3003)
#pragma parse_mfunc_templ reset
#endif
};

/* retrieval of indices by number */

template<typename MultiIndexContainer,int N>
struct nth_index
{
  STREAMS_BOOST_STATIC_CONSTANT(
    int,
    M=mpl::size<typename MultiIndexContainer::index_type_list>::type::value);
  STREAMS_BOOST_STATIC_ASSERT(N>=0&&N<M);
  typedef typename mpl::at_c<
    typename MultiIndexContainer::index_type_list,N>::type type;
};

template<int N,typename Value,typename IndexSpecifierList,typename Allocator>
typename nth_index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type&
get(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(int,N))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>    multi_index_type;
  typedef typename nth_index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    N
  >::type                                  index;

  STREAMS_BOOST_STATIC_ASSERT(N>=0&&
    N<
    mpl::size<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::index_type_list
    >::type::value);

  return detail::converter<multi_index_type,index>::index(m);
}

template<int N,typename Value,typename IndexSpecifierList,typename Allocator>
const typename nth_index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type&
get(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(int,N))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>    multi_index_type;
  typedef typename nth_index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    N
  >::type                                  index;

  STREAMS_BOOST_STATIC_ASSERT(N>=0&&
    N<
    mpl::size<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::index_type_list
    >::type::value);

  return detail::converter<multi_index_type,index>::index(m);
}

/* retrieval of indices by tag */

template<typename MultiIndexContainer,typename Tag>
struct index
{
  typedef typename MultiIndexContainer::index_type_list index_type_list;

  typedef typename mpl::find_if<
    index_type_list,
    detail::has_tag<Tag>
  >::type                                      iter;

  STREAMS_BOOST_STATIC_CONSTANT(
    bool,index_found=!(is_same<iter,typename mpl::end<index_type_list>::type >::value));
  STREAMS_BOOST_STATIC_ASSERT(index_found);

  typedef typename mpl::deref<iter>::type       type;
};

template<
  typename Tag,typename Value,typename IndexSpecifierList,typename Allocator
>
typename ::streams_boost::multi_index::index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&
get(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::streams_boost::multi_index::index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    Tag
  >::type                                       index;

  return detail::converter<multi_index_type,index>::index(m);
}

template<
  typename Tag,typename Value,typename IndexSpecifierList,typename Allocator
>
const typename ::streams_boost::multi_index::index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&
get(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::streams_boost::multi_index::index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    Tag
  >::type                                       index;

  return detail::converter<multi_index_type,index>::index(m);
}

/* projection of iterators by number */

template<typename MultiIndexContainer,int N>
struct nth_index_iterator
{
  typedef typename detail::prevent_eti<
    nth_index<MultiIndexContainer,N>,
    typename nth_index<MultiIndexContainer,N>::type>::type::iterator type;
};

template<typename MultiIndexContainer,int N>
struct nth_index_const_iterator
{
  typedef typename detail::prevent_eti<
    nth_index<MultiIndexContainer,N>,
    typename nth_index<MultiIndexContainer,N>::type
  >::type::const_iterator type;
};

template<
  int N,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename nth_index_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type
project(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(int,N))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>                multi_index_type;
  typedef typename nth_index<multi_index_type,N>::type index;

#if (!defined(STREAMS_BOOST_MSVC)||!(STREAMS_BOOST_MSVC<1310))&&  /* MSVC++ 6.0/7.0 fails */\
    (!defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580)) /* as does Sun C++ 5.7  */
  STREAMS_BOOST_STATIC_ASSERT((
    mpl::contains<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value));
#endif

  STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    STREAMS_BOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index>::iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

template<
  int N,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename nth_index_const_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type
project(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(int,N))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>                multi_index_type;
  typedef typename nth_index<multi_index_type,N>::type index;

#if (!defined(STREAMS_BOOST_MSVC)||!(STREAMS_BOOST_MSVC<1310))&&  /* MSVC++ 6.0/7.0 fails */\
    (!defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580)) /* as does Sun C++ 5.7  */
  STREAMS_BOOST_STATIC_ASSERT((
    mpl::contains<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value||
    mpl::contains<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::const_iterator_type_list,
      IteratorType>::value));
#endif

  STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    STREAMS_BOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index>::const_iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

/* projection of iterators by tag */

template<typename MultiIndexContainer,typename Tag>
struct index_iterator
{
  typedef typename ::streams_boost::multi_index::index<
    MultiIndexContainer,Tag>::type::iterator    type;
};

template<typename MultiIndexContainer,typename Tag>
struct index_const_iterator
{
  typedef typename ::streams_boost::multi_index::index<
    MultiIndexContainer,Tag>::type::const_iterator type;
};

template<
  typename Tag,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename index_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type
project(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::streams_boost::multi_index::index<
    multi_index_type,Tag>::type                 index;

#if (!defined(STREAMS_BOOST_MSVC)||!(STREAMS_BOOST_MSVC<1310))&&  /* MSVC++ 6.0/7.0 fails */\
    (!defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580)) /* as does Sun C++ 5.7  */
  STREAMS_BOOST_STATIC_ASSERT((
    mpl::contains<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value));
#endif

  STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    STREAMS_BOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index>::iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

template<
  typename Tag,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename index_const_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type
project(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it
  STREAMS_BOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(Tag))
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::streams_boost::multi_index::index<
    multi_index_type,Tag>::type                 index;

#if (!defined(STREAMS_BOOST_MSVC)||!(STREAMS_BOOST_MSVC<1310))&&  /* MSVC++ 6.0/7.0 fails */\
    (!defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580)) /* as does Sun C++ 5.7  */
  STREAMS_BOOST_STATIC_ASSERT((
    mpl::contains<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value||
    mpl::contains<
      STREAMS_BOOST_DEDUCED_TYPENAME multi_index_type::const_iterator_type_list,
      IteratorType>::value));
#endif

  STREAMS_BOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(STREAMS_BOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    STREAMS_BOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  STREAMS_BOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index>::const_iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

/* Comparison. Simple forward to first index. */

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator==(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)==get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator<(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)<get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator!=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)!=get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator>(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)>get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator>=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)>=get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator<=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)<=get<0>(y);
}

/*  specialized algorithms */

template<typename Value,typename IndexSpecifierList,typename Allocator>
void swap(
  multi_index_container<Value,IndexSpecifierList,Allocator>& x,
  multi_index_container<Value,IndexSpecifierList,Allocator>& y)
{
  x.swap(y);
}

} /* namespace multi_index */

#if !defined(STREAMS_BOOST_MULTI_INDEX_DISABLE_SERIALIZATION)&&\
    !defined(STREAMS_BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
/* Serialization class version bump as we now serialize the size
 * through streams_boost::serialization::collection_size_type.
 */

namespace serialization {
template<typename Value,typename IndexSpecifierList,typename Allocator>
struct version<
  streams_boost::multi_index_container<Value,IndexSpecifierList,Allocator>
>
{
  STREAMS_BOOST_STATIC_CONSTANT(unsigned int,value=1);
};
} /* namespace serialization */
#endif

/* Associated global functions are promoted to namespace streams_boost, except
 * comparison operators and swap, which are meant to be Koenig looked-up.
 */

using multi_index::get;
using multi_index::project;

} /* namespace streams_boost */

#undef STREAMS_BOOST_MULTI_INDEX_CHECK_INVARIANT

#endif
