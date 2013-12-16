#ifndef VECBOS_EVENT_HH
#define VECBOS_EVENT_HH

#include <DataFormats/include/EventHeader.hh>
#include <DataFormats/include/TrackFwd.hh>

class TTree;

namespace vecbos {

  class Event {
  public:

    /// default constructor
    Event() { };
    virtual ~Event();
    
    /// the event header
    vecbos::EventHeader eventHeader() { return eventHeader_; }
    void setEventHeader(vecbos::EventHeader hdr) { eventHeader_ = hdr; }

    /// track collection
    vecbos::TrackCollection tracks() { return tracks_; }
    void setTracks(vecbos::TrackCollection tracks) { tracks_ = tracks; }

  protected:
    
    /// have the event collections been cached?
    vecbos::EventHeader eventHeader_;
    vecbos::TrackCollection tracks_; 
    
  };
}

#endif
