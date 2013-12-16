#ifndef VECBOS_CANDIDATE_H
#define VECBOS_CANDIDATE_H

#include "TLorentzVector.h"
#include "TVector3.h"

#include "DataFormats/include/CandidateFwd.hh"

namespace vecbos {
  
  class Candidate {
  public:

    /// electric charge type
    typedef int Charge;
    /// Lorentz vector
    typedef TLorentzVector LorentzVector;
    /// point in the space
    typedef TVector3 Point;
    /// point in the space
    typedef TVector3 Vector;

    /// collection of candidates
    typedef std::vector

    /// default constructor
    Candidate() {};
    /// destructor
    virtual ~Candidate();
    /// electric charge
    virtual int charge() const = 0;
    /// set electric charge
    virtual void setCharge( int q ) = 0;
    /// four-momentum Lorentz vector
    virtual const LorentzVector & p4() const = 0;
    /// four-momentum Lorentz vector
    virtual const PolarLorentzVector & polarP4() const = 0;
    /// spatial momentum vector
    virtual Vector momentum() const = 0;
    /// magnitude of momentum vector
    virtual double p() const = 0;
    /// energy
    virtual double energy() const = 0;
    /// transverse energy 
    virtual double et() const = 0;
    /// mass
    virtual float mass() const = 0;
    /// mass squared
    virtual float massSqr() const = 0;
    /// transverse mass
    virtual double mt() const = 0;
    /// transverse mass squared
    virtual double mtSqr() const = 0;
    /// x coordinate of momentum vector
    virtual double px() const = 0;
    /// y coordinate of momentum vector
    virtual double py() const = 0;
    /// z coordinate of momentum vector
    virtual double pz() const = 0;
    /// transverse momentum
    virtual float pt() const = 0;
    /// momentum azimuthal angle
    virtual float phi() const = 0;
    /// momentum polar angle
    virtual double theta() const = 0;
    /// momentum pseudorapidity
    virtual float eta() const = 0;
    /// rapidity
    virtual double rapidity() const = 0;
    /// rapidity
    virtual double y() const = 0;
    /// set 4-momentum
    virtual void setP4( const LorentzVector & p4 ) = 0;
    /// set 4-momentum
    virtual void setP4( const PolarLorentzVector & p4 )  = 0;
    /// set particle mass
    virtual void setMass( double m )  = 0;
    virtual void setPz( double pz )  = 0;
    /// vertex position
    virtual const Point & vertex() const  = 0;
    /// x coordinate of vertex position
    virtual double vx() const  = 0;
    /// y coordinate of vertex position
    virtual double vy() const  = 0;
    /// z coordinate of vertex position
    virtual double vz() const  = 0;
    /// set vertex
    virtual void setVertex( const Point & vertex )  = 0;
    /// PDG identifier
    virtual int pdgId() const  = 0;
    // set PDG identifier
    virtual void setPdgId( int pdgId )  = 0;
    /// status word
    virtual int status() const  = 0;
    /// set status word
    virtual void setStatus( int status )  = 0;
    /// returns a clone of the Candidate object
    virtual Candidate * clone() const = 0;
    /// chi-squares
    virtual double vertexChi2() const = 0;
    /** Number of degrees of freedom
     *  Meant to be Double32_t for soft-assignment fitters: 
     *  tracks may contribute to the vertex with fractional weights.
     *  The ndof is then = to the sum of the track weights.
     *  see e.g. CMS NOTE-2006/032, CMS NOTE-2004/002
     */
    virtual double vertexNdof() const = 0;
    /// chi-squared divided by n.d.o.f.
    virtual double vertexNormalizedChi2() const = 0;
    /// (i, j)-th element of error matrix, i, j = 0, ... 2
    virtual double vertexCovariance(int i, int j) const = 0;

  protected:
    /// check overlap with another Candidate
    virtual bool overlap( const Candidate & ) const = 0;

  };

}

#endif


