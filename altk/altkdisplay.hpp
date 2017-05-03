// altkdisplay.hpp

#ifndef _ALTKDISPLAY_HPP_
#define _ALTKDISPLAY_HPP_

#include "altk/altkobject.hpp"
#include "altk/altkmainloop.hpp"

#include <unordered_set>



// altk::Display
//
namespace altk
{
  class Widget;
  class DisplaySource;
  
  class Display : public Object
  {
    friend DisplaySource;
    
  private:
    ALLEGRO_DISPLAY *al_display;
    std::unordered_set<Widget *> resize_queue;
    
  public:
    Display ();
    bool open ( int width,
                int height );
    ALLEGRO_DISPLAY *get_al_display ();
    void queue_resize ( Widget *widget );
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
