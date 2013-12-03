#ifndef VECBOS_EVENT_HH
#define VECBOS_EVENT_HH

#include <DataFormats/include/EventHeader.hh>

class TTree;

namespace vecbos {

  class VecbosEvent {
  public:
    VecbosEvent();
    virtual ~VecbosEvent();

    EventHeader*                    eventHeader() {return _eventHeader;}

    void setEventHeader(vecbos::EventHeader* hdr) { _eventHeader=hdr; }

  protected:

    vecbos::EventHeader* _eventHeader;
    
  };
}

#endif
