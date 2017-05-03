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
    ALLEGRO_DISPLAY *get_al_display ();
  };

  class DisplaySource : public Source
  {
  private:
    Display *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_EVENT event;
    bool event_pending;
    
  public:
    DisplaySource ( Display *display );
    bool check ();
    bool dispatch ();
  };
}

#endif
