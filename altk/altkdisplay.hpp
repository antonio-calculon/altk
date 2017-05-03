// altkdisplay.hpp

#ifndef _ALTKDISPLAY_HPP_
#define _ALTKDISPLAY_HPP_

#include "altk/altkobject.hpp"



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
  };
}

#endif
