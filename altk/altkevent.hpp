// altkevent.hpp

#ifndef _ALTKEVENT_HPP_
#define _ALTKEVENT_HPP_

#include "altk/altkbase.hpp"



#define _EVENT_HEADER \
  EventType type; \
  Widget *widget



// altk::Event
//
namespace altk
{
  class Display;
  class Widget;
  
  typedef enum _EventType
  {
    EVENT_TYPE_DRAW,
  }
    EventType;

  typedef enum _EventMask
    {
      EVENT_MASK_DRAW = 1 << 0,
    }
    EventMask;

  typedef struct _EventAny
  {
    _EVENT_HEADER;
  }
    EventAny;

  typedef struct _EventDraw
  {
    _EVENT_HEADER;
    Display *display;
  }
    EventDraw;

  typedef union _Event
  {
    EventType type;
    EventAny any;
    EventDraw draw;
  }
    Event;
}

#endif
