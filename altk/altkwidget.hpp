// altkwidget.hpp

#ifndef _ALTKWIDGET_HPP_
#define _ALTKWIDGET_HPP_

#include "altk/altkobject.hpp"



// altk::Widget
//
namespace altk
{
  class Widget : public Object
  {
  private:
    Widget *parent;
    
  public:
    Widget ();
    void set_parent ( Widget *parent );
  };
}

#endif
