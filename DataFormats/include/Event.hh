#ifndef VECBOS_EVENT_H
#define VECBOS_EVENT_H

#include <DataFormats/include/EventHeader.hh>

namespace vecbos {
  
  class Event : public TObject {
  public:
    run()   { return _runNumber; }
    event() { return _eventNumber; }
    lumi()  { return _lumiSection; }

  protected:  
    vecbos::EventHeader _eventHeader;
    int                 _nElectrons;
    TClonesArray        *_Electrons;
    ClassDef(Event,1)

  };
}

#endif

