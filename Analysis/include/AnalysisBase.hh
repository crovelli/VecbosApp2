#ifndef ANALYSIS_BASE_HH
#define ANALYSIS_BASE_HH

#include "DataFormats/include/Event.hh"
#include "Analysis/include/VecbosEventContent.h"

#include "DataFormats/include/SuperClusterFwd.hh"

#include "TTree.h"

namespace vecbos {
  
  class AnalysisBase : public VecbosEventContent {
  public:
    //! constructor
    AnalysisBase(TTree *tree);
    //! destructor
    virtual ~AnalysisBase() { }
    
    void init(TTree* tree = 0);
    int  loadTree(Long64_t entry);

  protected:
    vecbos::Event Event;
    vecbos::SuperClusterCollection SuperClusters;
    vecbos::SuperClusterCollection PFSuperClusters;

  private:
    void loadEventHeader();
    void loadSuperClusters();
    void loadPFSuperClusters();
    
  };

}

#endif
