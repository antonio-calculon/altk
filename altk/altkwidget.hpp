// altkwidget.hpp

#ifndef _ALTKWIDGET_HPP_
#define _ALTKWIDGET_HPP_

#include "altk/altkobject.hpp"



// altk::Widget
//
namespace altk
{
  typedef enum _WidgetFlags
    {
      WIDGET_FLAG_ROOT_WIDGET = 1 << 0,
    }
    WidgetFlags;
  
  class Widget : public Object
  {
  private:
    Widget *parent;
    unsigned int flags;
    
  public:
    // flags accessors
    bool is_root_widget () { return flags & WIDGET_FLAG_ROOT_WIDGET; }
    void set_root_widget () { flags |= WIDGET_FLAG_ROOT_WIDGET; }
    //
    Widget ();
    void set_parent ( Widget *parent );
  };
}

#endif