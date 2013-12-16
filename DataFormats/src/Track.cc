#include "DataFormats/include/Track.hh"

using namespace vecbos;

Track::Track() :
  chi2_(0), vertex_(0,0,0), momentum_(0,0,0), ndof_(0), charge_(0) { }


Track::Track( double chi2, double ndof, 
	      const Point & vertex, const Vector & momentum, int charge) :
  chi2_( chi2 ), vertex_( vertex ), 
  momentum_( momentum ), ndof_( ndof ), charge_( charge ) { }
