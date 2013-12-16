#ifndef VECBOS_TRACK_h
#define VECBOS_TRACK_h

#include "TVector3.h"

namespace reco {

  class Track {
  public:
    /// spatial vector
    typedef TVector3 Vector;
    /// point in the space
    typedef TVector3 Point;

    /// default constructor
    Track();
    /// virtual destructor   
    virtual ~Track() { }
    /// constructor from fit parameters and error matrix  
    Track( double chi2, double ndof, const Point & referencePoint,
	   const Vector & momentum, int charge);
    /// chi-squared of the fit
    double chi2() const { return chi2_; }
    /// number of degrees of freedom of the fit
    double ndof() const { return ndof_; }
    /// chi-squared divided by n.d.o.f. (or chi-squared * 1e6 if n.d.o.f. is zero)
    double normalizedChi2() const { return ndof_ != 0 ? chi2_ / ndof_ : chi2_ * 1e6; }
    /// track electric charge
    int charge() const { return charge_; }
    /// q/p 
    double qoverp() const { return charge() / p(); }
    /// polar angle  
    double theta() const { return momentum_.theta(); }
    /// Lambda angle
    double lambda() const { return M_PI/2 - momentum_.theta(); }
    /// dxy parameter. (This is the transverse impact parameter w.r.t. to (0,0,0) ONLY if refPoint is close to (0,0,0): see parametrization definition above for details). See also function dxy(myBeamSpot) below.
    double dxy() const { return ( - vx() * py() + vy() * px() ) / pt(); }
    /// dxy parameter in perigee convention (d0 = - dxy)
    double d0() const { return - dxy(); }
    /// dsz parameter (THIS IS NOT the SZ impact parameter to (0,0,0) if refPoint is far from (0,0,0): see parametrization definition above for details)
    double dsz() const { return vz()*pt()/p() - (vx()*px()+vy()*py())/pt() * pz()/p(); }
    /// dz parameter (= dsz/cos(lambda)). This is the track z0 w.r.t (0,0,0) only if the refPoint is close to (0,0,0). See also function dz(myBeamSpot) below.
    double dz() const { return vz() - (vx()*px()+vy()*py())/pt() * (pz()/pt()); }
    /// momentum vector magnitude
    double p() const { return momentum_.R(); }
    /// track transverse momentum
    double pt() const { return sqrt( momentum_.Perp2() ); }
    /// x coordinate of momentum vector
    double px() const { return momentum_.x(); }
    /// y coordinate of momentum vector
    double py() const { return momentum_.y(); }
    /// z coordinate of momentum vector
    double pz() const { return momentum_.z(); }
    /// azimuthal angle of momentum vector
    double phi() const { return momentum_.Phi(); }
    /// pseudorapidity of momentum vector
    double eta() const { return momentum_.Eta(); }
    /// x coordinate of the reference point on track
    double vx() const { return vertex_.x(); }
    /// y coordinate of the reference point on track
    double vy() const { return vertex_.y(); }
    /// z coordinate of the reference point on track
    double vz() const { return vertex_.z(); }

    /// track momentum vector
    const Vector & momentum() const { return momentum_; }

    /// Reference point on the track
    const Point & referencePoint() const { return vertex_; }

    /// reference point on the track. This method is DEPRECATED, please use referencePoint() instead
    const Point & vertex() const { return vertex_; }

    /// dxy parameter with respect to a user-given beamSpot (WARNING: this quantity can only be interpreted as a minimum transverse distance if beamSpot, if the beam spot is reasonably close to the refPoint, since linear approximations are involved). This is a good approximation for Tracker tracks.
    double dxy(const Point& myBeamSpot) const { 
      return ( - (vx()-myBeamSpot.x()) * py() + (vy()-myBeamSpot.y()) * px() ) / pt(); 
    }

    /// dxy parameter with respect to the beamSpot taking into account the beamspot slopes WARNING: this quantity can only be interpreted as a minimum transverse distance if beamSpot, if the beam spot is reasonably close to the refPoint, since linear approximations are involved). This is a good approximation for Tracker tracks.
    double dxy(const BeamSpot& theBeamSpot) const { 
      return dxy(theBeamSpot.position(vz()));
    }

    /// dsz parameter with respect to a user-given beamSpot (WARNING: this quantity can only be interpreted as the distance in the S-Z plane to the beamSpot, if the beam spot is reasonably close to the refPoint, since linear approximations are involved). This is a good approximation for Tracker tracks.
    double dsz(const Point& myBeamSpot) const { 
      return (vz()-myBeamSpot.z())*pt()/p() - ((vx()-myBeamSpot.x())*px()+(vy()-myBeamSpot.y())*py())/pt() *pz()/p(); 
    }
    /// dz parameter with respect to a user-given beamSpot (WARNING: this quantity can only be interpreted as the track z0, if the beamSpot is reasonably close to the refPoint, since linear approximations are involved). This is a good approximation for Tracker tracks.
    double dz(const Point& myBeamSpot) const { 
      return (vz()-myBeamSpot.z()) - ((vx()-myBeamSpot.x())*px()+(vy()-myBeamSpot.y())*py())/pt() * pz()/pt(); 
    }

    /// number of valid hits found 
    unsigned short numberOfValidHits() const { return numberOfValidHits_; }
    /// number of cases where track crossed a layer without getting a hit.
    unsigned short numberOfLostHits() const { return numberOfLostHits_ }
   
  private:
    float chi2_;
     /// innermost (reference) point on track
    Point vertex_;
    /// momentum vector at innermost point
    Vector momentum_;

    /// number of degrees of freedom
    float ndof_;

    /// electric charge
    char charge_;

  };

}

#endif
