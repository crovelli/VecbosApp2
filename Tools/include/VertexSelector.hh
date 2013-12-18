#ifndef VECBOS_VERTEXSELECTION_HH
#define VECBOS_VERTEXSELECTION_HH

#include "DataFormats/include/Vertex.hh"
#include "DataFormats/include/VertexFwd.hh"

namespace vecbos {
  
  class VertexSelector {
  public:
    /// default constructor from vertex collection
    VertexSelector(VertexCollection vertices) { vertices_ = vertices; }
    /// destructor
    ~VertexSelector() { };

    /// get the filtered good collection, ordered by SumPt of the constituent tracks
    VertexCollection goodCollection();
    
  private:

    struct sortByPt {
      bool operator() (vecbos::Vertex i, vecbos::Vertex j) { return (i.sumpt()>j.sumpt()); }
    } collectionSorter;

    VertexCollection vertices_;
    
  };
}

#endif

