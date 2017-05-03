// altkdisplay.hpp

#ifndef _ALTKDISPLAY_HPP_
#define _ALTKDISPLAY_HPP_

#include "altk/altkobject.hpp"
#include "altk/altkmainloop.hpp"



// altk::Display
//
namespace altk
{
  class Display : public Object
  {
  private:
    ALLEGRO_DISPLAY *al_display;
    
  public:
    Display ();
    bool open ( int width,
                int height );
    bool check ();
    void dispatch();
  };

  class DisplaySource : public Source
  {
  private:
    Display *display;
    
  public:
    DisplaySource ( Display *display );
    bool check ();
    bool dispatch ();
  };
}

#endif
