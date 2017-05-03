// altkwindow.hpp

#include "private.hpp"
#include "altkwindow.hpp"
#include "altkdisplay.hpp"

using namespace altk;



Window::Window ( Display *display )
{
  this->display = display; // ref ??
  set_root_widget();
  this->backbuffer = NULL;
  display->attach_widget(this);
  event_mask = EVENT_MASK_DRAW;
}



Display *Window::get_display ()
{
  return display;
}



void Window::fix_backbuffer ()
{
  ASSERT(display); // [todo]
  int dw = allocation.width;
  int dh = allocation.height;
  if (backbuffer)
    {
      int bw = al_get_bitmap_width(backbuffer);
      int bh = al_get_bitmap_height(backbuffer);
      // [FIXME] shrink if necessary ?
      if (bw < dw || bh < dh)
        {
          al_destroy_bitmap(backbuffer);
          backbuffer = NULL;
        }
    }
  if (!backbuffer)
    {
      ALLEGRO_STATE state;
      al_store_state(&state, ALLEGRO_STATE_DISPLAY | ALLEGRO_STATE_TARGET_BITMAP);
      al_set_target_backbuffer(display->get_al_display());
      backbuffer = al_create_bitmap(dw, dh);
      al_restore_state(&state);
    }
}



void Window::on_size_allocate ( Allocation *alloc )
{
  fix_backbuffer();
  Bin::on_size_allocate(alloc);
}



DrawVisitor::DrawVisitor ( Event *event )
{
  this->event = event;
  force_draw = false;
}



void DrawVisitor::visit ( Widget *widget )
{
  if (force_draw || widget->needs_redraw())
    {
      // [FIXME] make a copy ?
      event->draw.widget = widget;
      widget->process_event(event);
      force_draw = true;
    }
  if (force_draw || widget->child_needs_redraw())
    {
      widget->accept(this);
    }
}



void Window::process_redraw ( Display *display )
{
  ASSERT(display == this->display);
  ASSERT(backbuffer); // just in case
  DEBUG("process redraw");
  ALLEGRO_STATE state;
  Event event;
  al_store_state(&state, ALLEGRO_STATE_DISPLAY | ALLEGRO_STATE_TARGET_BITMAP);
  al_set_target_bitmap(backbuffer);
  event.type = EVENT_TYPE_DRAW;
  event.draw.display = display;
  DrawVisitor visitor(&event);
  visitor.start(this);
  al_restore_state(&state);
}



void Window::on_draw_event ( Event *event )
{
  DEBUG("window draw!");
  ALLEGRO_COLOR bg = al_map_rgb(255, 0, 0);
  al_clear_to_color(bg);
}
