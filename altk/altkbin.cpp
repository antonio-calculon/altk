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
