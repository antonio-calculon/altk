// altkbase.cpp -

#include "private.hpp"
#include "altkbase.hpp"
#include "altkmainloop.hpp"

using namespace altk;



ALLEGRO_FONT *altk::builtin_font = NULL;



void altk::init ()
{
  DEBUG("Hello!");
  al_init();
  al_init_font_addon();
  altk::builtin_font = al_create_builtin_font();
  MainLoop::init();
}
