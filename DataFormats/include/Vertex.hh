#ifndef VECBOS_VERTEX_HH
#define VECBOS_VERTEX_HH

#include <math.h>
#include "TVector3.h"

namespace vecbos {

  class Vertex {
  public:
    /// point in the space
    typedef TVector3 Point;
    /// error on the point in the space
    typedef TVector3 Error;

    /// default constructor - The vertex will not be valid. Position, error,
    /// chi2, ndof will have random entries
    /// Use the isValid method to check that your vertex is valid. 
    Vertex():  chi2_( 0.0 ), ndof_( 0 ), position_(0.,0.,0. ), positionerr_(0.,0.,0. ) { validity_ = false; }
    /// Constructor for a fake vertex.
    Vertex( const Point &position, const Error &positionerr);
    /// constructor for a valid vertex, with all data
    Vertex( const Point &position, const Error &positionerr, float chi2, float ndof );
    /// Tells whether the vertex is valid.
    bool isValid() const {return validity_;}
    /// Tells whether a Vertex is fake, i.e. not a vertex made out of a proper
    /// fit with tracks.
    /// For a primary vertex, it could simply be the beam line.
    bool isFake() const { return isFake_; }
    /// number of tracks
    int tracksSize() const { return tracksSize_; }
    /// chi-squares
    float chi2() const { return chi2_; }
    /** Number of degrees of freedom
     *  Meant to be Double32_t for soft-assignment fitters: 
     *  tracks may contribute to the vertex with fractional weights.
     *  The ndof is then = to the sum of the track weights.
     *  see e.g. CMS NOTE-2006/032, CMS NOTE-2004/002
     */
    float ndof() const { return ndof_; }
    /// chi-squared divided by n.d.o.f.
    float normalizedChi2() const { return ndof_ != 0 ? chi2_ / ndof_ : chi2_ * 1e6; }
    /// position 
    const Point & position() const { return position_; }
    /// x coordinate 
    float x() const { return position_.X(); }
    /// y coordinate 
    float y() const { return position_.Y(); }
    /// y coordinate 
    float z() const { return position_.Z(); }
    /// error on x
    float xError() const { return positionerr_.X(); }
    /// error on y
    float yError() const { return positionerr_.Y(); }
    /// error on z
    float zError() const { return positionerr_.Z(); }
    /// Returns the modulo of the momentum of the sum of the tracks, assuming the pion mass of the constituents
    float sumpt() const { return sumpt_; } 
    /// rho (distance from the Beam Spot) 
    float rho() const { return position_.Perp(); }

    /// setters of the remaining properties
    void setValidity(int validity) { validity_ = (validity==0) ? false : true; }
    void setFake(int isFake) { isFake_ = (isFake==0) ? false : true; }
    void setSumPt(float sumpt) { sumpt_ = sumpt; }
    void setTracksSize(int tracksize) { tracksSize_ = tracksize; }
    
    /// good standard selected vertex
    bool isGood() { return !isFake_ && ndof_ > 4 && fabs(z()) < 24 && rho() <= 2; }

  private:
    /// chi-sqared
    float chi2_;
    /// number of degrees of freedom
    float ndof_;
    /// position
    Point position_;
    /// position error
    Error positionerr_;
    /// position wrt the Beam Spot
    
    /// tells wether the vertex is really valid.
    bool validity_;
    /// tells wether the vertex is fake
    bool isFake_;
    ///  modulo of the momentum of the sum of the tracks
    float sumpt_;
    /// number of tracks
    int tracksSize_;

  };
  
}

#endif
