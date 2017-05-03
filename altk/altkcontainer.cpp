// altkcontainer.hpp

#include "altkcontainer.hpp"

using namespace altk;



bool Container::give ( Widget *child )
{
  if (add(child))
    {
      child->unref();
      return true;
    }
  else
    {
      return false;
    }
}
