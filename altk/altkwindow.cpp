// altkwindow.hpp

#include "private.hpp"
#include "altkwindow.hpp"

using namespace altk;



Window::Window ( Display *display )
{
  this->display = display; // ref ??
  set_root_widget();
}



Display *Window::get_display ()
{
  return display;
}



void Window::on_draw_event ( Event *event )
{
  DEBUG("[TODO] draw");
}
