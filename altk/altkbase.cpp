// altkbase.cpp -

#include "private.hpp"
#include "altkbase.hpp"
#include "altkmainloop.hpp"

using namespace altk;



void altk::init ()
{
  DEBUG("Hello!");
  MainLoop::init();
}
