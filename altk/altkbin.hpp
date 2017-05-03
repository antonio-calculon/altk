// altkbin.hpp

#ifndef _ALTKBIN_HPP_
#define _ALTKBIN_HPP_

#include "altk/altkcontainer.hpp"



// altk::Bin
//
namespace altk
{
  class Bin : public Container
  {
  private:
    Widget *child;

  public:
    Bin ();
    virtual bool add ( Widget *child );
  };
}

#endif
