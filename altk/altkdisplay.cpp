// altkdisplay.hpp

#include "private.hpp"
#include "altkdisplay.hpp"

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



DisplaySource::DisplaySource ( Display *display )
{
  this->display = display; // [FIXME] ref ??
}



bool DisplaySource::check ()
{
  return false;
}


bool DisplaySource::dispatch ()
{
  return true;
}
