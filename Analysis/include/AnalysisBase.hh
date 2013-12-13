#ifndef ANALYSIS_BASE_HH
#define ANALYSIS_BASE_HH

#include <DataFormats/include/VecbosEvent.hh>
#include <Analysis/include/VecbosEventContent.h>

#include "TChain.h"

namespace vecbos {

class AnalysisBase : public VecbosEventContent {
  public:
    //! constructor
    AnalysisBase(TChain *tree);
    //! destructor
    virtual ~AnalysisBase() { }

    void                            init(TTree* tree = 0);
    virtual bool                    nextEvent();
    bool                            notify();
    int                             loadTree(Long64_t entry);
    TTree*                          getTree();

    bool getEvent();

  private:
    void loadEventHeader();
    vecbos::VecbosEvent *Event;

  };
}

#endif
