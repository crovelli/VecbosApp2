#ifndef VECBOS_RECOCANDIDATE_h
#define VECBOS_RECOCANDIDATE_h

#include "DataFormats/include/TrackFwd.h"
#include "DataFormats/include/GsfTrackFwd.h"
#include "DataFormats/include/SuperClusterFwd.h"

namespace reco {

  class RecoCandidate : public Candidate {
  public:
    /// default constructor
    RecoCandidate() : Candidate() { }
    /// constructor from values
    RecoCandidate( int charge, const TLorentzVector & p4, const Point & vtx = Point( 0, 0, 0 ),
		   int pdgId = 0, int status = 0 ) : 
      Candidate( q, p4, vtx, pdgId, status ) { }
    /// destructor
    virtual ~RecoCandidate();
    /// check overlap with another candidate
    virtual bool overlap( const Candidate & ) const = 0;

    /// reference to a Track
    virtual vecbos::Track* track() const;
    /// reference to a GsfTrack
    virtual vecbos::GsfTrack* gsfTrack() const;
    /// reference to a stand-alone muon Track
    virtual vecbos::Track* standAloneMuon() const;
    /// reference to a stand-alone muon Track
    virtual vecbos::Track* combinedMuon() const;
    /// reference to a SuperCluster
    virtual vecbos::SuperCluster* superCluster() const;

  protected:
  
}

#endif
