// altkwindow.hpp

#ifndef _ALTKWINDOW_HPP_
#define _ALTKWINDOW_HPP_

#include "altk/altkbin.hpp"



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
  };
}

#endif
