// altkdisplay.hpp

#include "private.hpp"
#include "altkdisplay.hpp"
#include "altkwidget.hpp"
#include "altkevent.hpp"

using namespace altk;



Display::Display ()
{
  al_display = NULL;
}



bool Display::open ( int width,
                     int height )
{
  if (al_display)
    {
      ERROR("display already open");
      return false;
    }
  if (!(al_display = al_create_display(width, height)))
    {
      ERROR("could not open display");
      return false;
    }
  Source *source = new DisplaySource(this);
  MainLoop *loop = MainLoop::get_current_loop();
  loop->attach_source(source, 0);
  source->unref();
  return true;
}



ALLEGRO_DISPLAY *Display::get_al_display ()
{
  return al_display;
}



void Display::queue_resize ( Widget *widget )
{
  resize_queue.insert((Widget *) widget->ref());
}



void Display::queue_redraw ( Widget *widget )
{
  redraw_queue.insert((Widget *) widget->ref());
}



void Display::process_redraw ()
{
  DEBUG("process redraw");
  //
  std::unordered_set<Widget *> queue;
  redraw_queue.swap(queue);
  auto end = queue.end();
  for (auto it=queue.begin(); it != end; it++)
    {
      (*it)->process_redraw(this);
      (*it)->unref();
    }
}



DisplaySource::DisplaySource ( Display *display )
{
  this->display = display; // [FIXME] ref ??
  event_pending = false;
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display->get_al_display()));
}



bool DisplaySource::check ()
{
  if (event_pending)
    return true;
  if (al_get_next_event(event_queue, &event))
    return event_pending = true;
  if (!display->resize_queue.empty())
    return true;
  if (!display->redraw_queue.empty())
    return true;
  return false;
}


bool DisplaySource::dispatch ()
{
  DEBUG("dispatch");
  if (event_pending) // just in case
    {
      event_pending = false;
      switch (event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
          DEBUG("display close, bye!");
          exit(0);
          break;
        default:
          DEBUG("unknown event: %d", event.type);
        }
    }
  else if (!display->resize_queue.empty())
    {
      std::unordered_set<Widget *> queue;
      display->resize_queue.swap(queue);
      auto end = queue.end();
      for (auto it=queue.begin(); it != end; it++)
        {
          (*it)->process_resize();
          (*it)->unref();
        }
    }
  else if (!display->redraw_queue.empty())
    {
      display->process_redraw();
    }
  return true;
}
