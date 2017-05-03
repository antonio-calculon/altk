// altklabel.hpp

#include "private.hpp"
#include "altklabel.hpp"

using namespace altk;



Label::Label ( const char *text )
{
  this->text = text;
}



void Label::on_size_request ( SizeRequest *req )
{
  const char *text = this->text.c_str();
  req->width = al_get_text_width(builtin_font, text);
  req->height = al_get_font_line_height(builtin_font);
}



void Label::on_size_allocate ( Allocation *alloc )
{
  DEBUG("[TODO] size_allocate (%dx%d)", alloc->width, alloc->height);
}



void Label::on_draw_event ( Event *event )
{
  DEBUG("label draw");
  ALLEGRO_COLOR fg = al_map_rgb(0, 0, 0);
  al_draw_text(altk::builtin_font, fg, 0, 0, 0, text.c_str());
}
