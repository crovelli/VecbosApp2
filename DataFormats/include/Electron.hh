#ifndef VECBOS_ELECTRON_H
#define VECBOS_ELECTRON_H

#include "DataFormats/include/Track.hh"

namespace vecbos {

  class Electron : public RecoCandidate {
  public:
    /// default constructor
    Electron() : RecoCandidate() { }
    /// constructor from constituents
    Electron( iint charge, Track gsfTrack, Track kfTrack);


  }

}

