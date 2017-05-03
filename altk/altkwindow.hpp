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
  
  class Window : public Bin
  {
  private:
    Display *display;
    
  public:
    Window ( Display *display );
    Display *get_display ();
    virtual void on_draw_event ( Event *event );
  };
}

#endif
