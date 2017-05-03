// altkbin.hpp

#include "private.hpp"
#include "altkbin.hpp"

using namespace altk;



Bin::Bin ()
{
  child = NULL;
}



bool Bin::add ( Widget *child )
{
  if (this->child)
    {
      ERROR("Bin already has a child");
      return false;
    }
  this->child = (Widget *) child->ref();
  child->set_parent(this);
  child->queue_resize();
  return true;
}



void Bin::accept ( WidgetVisitor *v )
{
  if (child)
    v->visit(child);
}



void Bin::on_size_request ( SizeRequest *req )
{
  if (child && child->is_visible())
    child->size_request(req);
}



void Bin::on_size_allocate ( Allocation *alloc )
{
  if (child && child->is_visible())
    child->size_allocate(alloc);
}
