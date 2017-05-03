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
    std::vector<Widget *> attached_widgets;
    std::unordered_set<Widget *> resize_queue;
    std::unordered_set<Widget *> redraw_queue;
    
  public:
    Display ();
    int get_width () { return al_get_display_width(al_display); }
    int get_height () { return al_get_display_height(al_display); }
    bool open ( int width,
                int height );
    ALLEGRO_DISPLAY *get_al_display ();
    void attach_widget ( Widget *widget );
    void queue_resize ( Widget *widget );
    void queue_redraw ( Widget *widget );
    void process_redraw ();
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
