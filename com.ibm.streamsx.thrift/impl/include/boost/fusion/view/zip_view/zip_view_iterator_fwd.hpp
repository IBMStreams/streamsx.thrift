/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.streams_boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ZIP_VIEW_ITERATOR_FWD)
#define FUSION_ZIP_VIEW_ITERATOR_FWD

#include <streams_boost/fusion/view/detail/strictest_traversal.hpp>

namespace streams_boost { namespace fusion {

    template<
        typename IteratorSequence, 
        typename Traversal = typename detail::strictest_traversal<IteratorSequence>::type>
    struct zip_view_iterator;

}}

#endif
