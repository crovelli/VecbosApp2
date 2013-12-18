#ifndef ANALYSIS_BASE_HH
#define ANALYSIS_BASE_HH

#include "Analysis/include/VecbosEventContent.h"
#include "DataFormats/include/Event.hh"
#include "DataFormats/include/VertexFwd.hh"
#include "DataFormats/include/SuperClusterFwd.hh"
#include "DataFormats/include/TrackFwd.hh"

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
    vecbos::VertexCollection PrimaryVertices;
    vecbos::SuperClusterCollection SuperClusters;
    vecbos::SuperClusterCollection PFSuperClusters;
    vecbos::TrackCollection GeneralTracks;
    vecbos::TrackCollection GsfTracks;
    vecbos::TrackCollection GlobalMuonTracks;
    vecbos::TrackCollection StandaloneMuonTracks;


  private:
    void loadEventHeader();
    void loadPrimaryVertices();
    void loadSuperClusters();
    void loadPFSuperClusters();
    void loadGeneralTracks();
    void loadGsfTracks();
    void loadGlobalMuonTracks();
    void loadStandaloneMuonTracks();

  };

}

#endif
