// altkwidget.hpp

#ifndef _ALTKWIDGET_HPP_
#define _ALTKWIDGET_HPP_

#include "altk/altkobject.hpp"
#include "altk/altkevent.hpp"



// altk::Widget
//
namespace altk
{
  class Display;
  class Widget;

  typedef enum _WidgetFlags
    {
      WIDGET_FLAG_ROOT_WIDGET = 1 << 0,
      WIDGET_FLAG_VISIBLE = 1 << 1,
      WIDGET_FLAG_NEEDS_RESIZE = 1 << 2,
      WIDGET_FLAG_NEEDS_REDRAW = 1 << 3,
      WIDGET_FLAG_CHILD_NEEDS_REDRAW = 1 << 4,
    }
    WidgetFlags;

  typedef struct _SizeRequest
  {
    int width;
    int height;
  }
    SizeRequest;

  typedef struct _Allocation
  {
    int x;
    int y;
    int width;
    int height;
  }
    Allocation;

  typedef enum _WidgetVisitorMode
    {
      WIDGET_VISITOR_PREFIX,
    }
    WidgetVisitorMode;
  
  class WidgetVisitor
  {
  public:
    void start ( Widget *widget );
    virtual void visit ( Widget *widget ) = 0;
  };

  class ShowAllVisitor : public WidgetVisitor
  {
  public:
    void visit ( Widget *widget );
  };
  
  class Widget : public Object
  {
    friend ShowAllVisitor;
    
  protected:
    Widget *parent;
    unsigned int flags;
    SizeRequest request;
    Allocation allocation;
    
    void _show_all ( Widget *widget,
                     void *data );
    
  public:
    // flags accessors
    bool is_root_widget () { return flags & WIDGET_FLAG_ROOT_WIDGET; }
    void set_root_widget () { flags |= WIDGET_FLAG_ROOT_WIDGET; }
    bool is_visible () { return flags & WIDGET_FLAG_VISIBLE; }
    bool needs_resize () { return flags & WIDGET_FLAG_NEEDS_RESIZE; }
    bool needs_redraw () { return flags & WIDGET_FLAG_NEEDS_REDRAW; }
    bool child_needs_redraw () { return flags & WIDGET_FLAG_CHILD_NEEDS_REDRAW; }
    //
    Widget ();
    virtual Display *get_display ();
    void set_parent ( Widget *parent );
    Widget *get_root ();
    // [FIXME]
    virtual ALLEGRO_BITMAP *get_backbuffer () { return NULL; }
    // size management
    void queue_resize ();
    void process_resize ();
    void size_request ( SizeRequest *req );
    virtual void on_size_request ( SizeRequest *req );
    void size_allocate ( Allocation *alloc );
    virtual void on_size_allocate ( Allocation *alloc );
    void get_allocation ( Allocation *alloc ) { *alloc = this->allocation; }
    //
    void show_all ();
    void queue_draw ();
    // containers
    virtual void accept ( WidgetVisitor *visitor ) {}
    // events
    virtual void process_redraw ( Display *display ) {} // [FIXME] this is for Window
    void process_event ( Event *event );
    virtual void on_draw_event ( Event *event );
  };
}

#endif
