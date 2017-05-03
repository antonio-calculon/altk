// altkmainloop.hpp

#ifndef _ALTKMAINLOOP_HPP_
#define _ALTKMAINLOOP_HPP_

#include "altk/altkobject.hpp"

#include <vector>



// altk::MainLoop
//
namespace altk
{
  typedef struct _SourceEntry SourceEntry;
  
  class Source : public Object
  {
  public:
    virtual bool check () = 0;
    virtual bool dispatch () = 0;
  };
  
  class MainLoop : public Object
  {
  private:
    static MainLoop *current_loop;
    std::vector<SourceEntry *> sources;
    
  public:
    static void init ();
    static MainLoop *get_current_loop() { return MainLoop::current_loop; }
    void attach_source ( Source *source,
                         int priority );
    void run ();
  };
}

#endif
