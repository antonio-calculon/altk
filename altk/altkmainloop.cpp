// altkmainloop.hpp

#include "private.hpp"
#include "altkmainloop.hpp"

using namespace altk;



#define IDLE_REST_DELAY 0.01

MainLoop *MainLoop::current_loop = NULL;



struct altk::_SourceEntry
{
  Source *source;
  int priority;
};



void MainLoop::init ()
{
  current_loop = new MainLoop();
}



void MainLoop::run ()
{
  DEBUG("running loop...");
  while (true)
    {
      bool idle = true;
      auto end = sources.end();
      for (auto it=sources.begin(); it != end; it++)
        {
          Source *source = (*it)->source;
          if (source->check())
            {
              idle = false;
              if (!source->dispatch())
                DEBUG("[TODO] remove source");
              break;
            }
        }
      if (idle)
        al_rest(IDLE_REST_DELAY);
    }
}



void MainLoop::attach_source ( Source *source,
                               int priority )
{
  SourceEntry *entry = new SourceEntry;
  DEBUG("attach source: %p", source);
  entry->source = (Source *) source->ref();
  entry->priority = priority;
  sources.push_back(entry);
}
