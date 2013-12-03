#ifndef ANALYSIS_BASE_HH
#define ANALYSIS_BASE_HH

#include <DataFormats/include/VecbosEvent.hh>
#include <Analysis/include/VecbosEventContent.h>

namespace vecbos {

  class AnalysisBase : public VecbosEventContent {
  public:
    //! constructor
    AnalysisBase(TChain *chain);
    //! destructor
    virtual ~AnalysisBase();

    bool                            init(TTree* tree = 0);
    virtual bool                    nextEvent();
    bool                            notify();
    int                             loadTree(Long64_t entry);
    TTree*                          getTree();

    bool getEvent();

  private:
    void loadEventHeader();
    VecbosEvent *Event;

  };
}

#endif
