// altkobject.hpp

#include "altkobject.hpp"

using namespace altk;



Object::Object ()
{
  ref_count = 1;
}



Object::~Object ()
{
}



// [TODO] make all this atomic
void *Object::ref ()
{
  ref_count++;
  return this;
}



void Object::unref ()
{
  if (!(--ref_count))
    delete this;
}
