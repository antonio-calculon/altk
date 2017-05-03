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
  req->width = 100;
  req->height = 20;
}



void Label::on_size_allocate ( Allocation *alloc )
{
  DEBUG("[TODO] size_allocate (%dx%d)", alloc->width, alloc->height);
}
