#include "DataFormats/include/Vertex.hh"

using namespace std;
using namespace vecbos;

Vertex::Vertex( const Point & p , const Error & err, float chi2, float ndof ) :
  chi2_( chi2 ), ndof_( ndof ), position_( p ), positionerr_( err ) {
  validity_ = true;
}

Vertex::Vertex( const Point & p , const Error & err) :
  chi2_( 0.0 ), ndof_( 0 ), position_( p ), positionerr_( err ) {
  validity_ = true;
}

