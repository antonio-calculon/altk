// altkcontainer.hpp

#ifndef _ALTKCONTAINER_HPP_
#define _ALTKCONTAINER_HPP_

#include "altk/altkwidget.hpp"



// altk::Container
//
namespace altk
{
  class Container : public Widget
  {
  public:
    virtual bool add ( Widget *child ) = 0;
    bool give ( Widget *child );
  };
}

#endif
