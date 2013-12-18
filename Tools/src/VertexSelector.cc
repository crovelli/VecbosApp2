#include <algorithm> 

#include "Tools/include/VertexSelector.hh"

using namespace vecbos;

VertexCollection VertexSelector::goodCollection() {

  VertexCollection filtered;
  for(vertex_iterator it = vertices_.begin(); it != vertices_.end(); ++it)
    if(it->isGood()) filtered.push_back(*it);

  std::sort(filtered.begin(), filtered.end(), collectionSorter);
  return filtered;
  
}
