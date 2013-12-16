#ifndef VECBOS_EVENTHEADER_H
#define VECBOS_EVENTHEADER_H

#include <TObject.h>

namespace vecbos {
  
  class EventHeader {
  public:
    /// default constructor
    EventHeader() :
      _runNumber(0), _eventNumber(0), _lumiSection(0) { };
    /// constructor from values
    EventHeader(int run, ULong64_t evt, int lumi) :
      _runNumber(run), _eventNumber(evt), _lumiSection(lumi) { };
    /// destructor
    ~EventHeader();
    // getters
    int run()   { return _runNumber; }
    ULong64_t event() { return _eventNumber; }
    int lumi()  { return _lumiSection; }

    void setRun(int n)          { _runNumber = n; }
    void setEvent(ULong64_t n)  { _eventNumber = n; }
    void setLumi(int n)         { _lumiSection = n; }

  protected:  
    int          _runNumber;
    ULong64_t    _eventNumber;
    int          _lumiSection;  

  };
}

#endif

