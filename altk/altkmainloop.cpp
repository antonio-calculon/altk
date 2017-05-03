// altkmainloop.hpp

#include "private.hpp"
#include "altkmainloop.hpp"

using namespace altk;



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
      auto end = sources.end();
      for (auto it=sources.begin(); it != end; it++)
        {
          Source *source = (*it)->source;
          DEBUG("source: %p", source);
          if (source->check())
            {
              if (!source->dispatch())
                DEBUG("[TODO] remove source");
              break;
            }
        }
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
