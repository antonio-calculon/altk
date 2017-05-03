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
}



void MainLoop::attach_source ( Source *source,
                               int priority )
{
  SourceEntry *entry = new SourceEntry;
  entry->source = (Source *) source->ref();
  entry->priority = priority;
  sources.push_back(entry);
}
