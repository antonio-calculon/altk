// altkwidget.hpp

#ifndef _ALTKWIDGET_HPP_
#define _ALTKWIDGET_HPP_

#include "altk/altkobject.hpp"



// altk::Widget
//
namespace altk
{
  class Display;
  
  typedef enum _WidgetFlags
    {
      WIDGET_FLAG_ROOT_WIDGET = 1 << 0,
      WIDGET_FLAG_VISIBLE = 1 << 1,
      WIDGET_FLAG_NEEDS_RESIZE = 1 << 2,
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
    bool is_visible () { return flags & WIDGET_FLAG_VISIBLE; }
    bool needs_resize () { return flags & WIDGET_FLAG_NEEDS_RESIZE; }
    //
    Widget ();
    virtual Display *get_display ();
    void set_parent ( Widget *parent );
    Widget *get_root ();
    void queue_resize ();
  };
}

#endif
