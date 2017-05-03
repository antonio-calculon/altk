// altkwindow.hpp

#ifndef _ALTKWINDOW_HPP_
#define _ALTKWINDOW_HPP_

#include "altk/altkbin.hpp"
#include "altk/altkevent.hpp"



// altk::Window
//
namespace altk
{
  class Display;

  class DrawVisitor : public WidgetVisitor
  {
    Event *event;
    bool force_draw;
    
  public:
    DrawVisitor ( Event *event );
    void visit ( Widget *widget );
  };
  
  class Window : public Bin
  {
  private:
    Display *display;
    ALLEGRO_BITMAP *backbuffer;

    void fix_backbuffer();
    
  public:
    Window ( Display *display );
    Display *get_display ();
    virtual ALLEGRO_BITMAP *get_backbuffer () { return backbuffer; }
    virtual void on_size_allocate ( Allocation *alloc );
    virtual void process_redraw ( Display *display );
    virtual void on_draw_event ( Event *event );
  };
}

#endif
