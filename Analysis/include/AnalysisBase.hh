#ifndef ANALYSIS_BASE_HH
#define ANALYSIS_BASE_HH

#include <DataFormats/include/VecbosEvent.hh>
#include <Analysis/include/VecbosEventContent.h>

#include "TTree.h"

namespace vecbos {

class AnalysisBase : public VecbosEventContent {
  public:
    //! constructor
    AnalysisBase(TTree *tree);
    //! destructor
    virtual ~AnalysisBase() { }

    void                            init(TTree* tree = 0);
    int                             loadTree(Long64_t entry);

  private:
    void loadEventHeader();
    vecbos::VecbosEvent *Event;

  };
}

#endif
