// altkobject.hpp

#ifndef _ALTKOBJECT_HPP_
#define _ALTKOBJECT_HPP_

#include "altk/altkbase.hpp"



// altk::Object
//
namespace altk
{
  class Object
  {
  private:
    unsigned int ref_count;

  public:
    Object ();
    virtual ~Object ();
    void *ref ();
    void unref ();
  };
}

#endif
