#ifndef DY_TO_EE_SELECTION_HH
#define DY_TO_EE_SELECTION_HH

#include "Analysis/include/AnalysisBase.hh"

namespace vecbos {

  class DYToEESelection : public AnalysisBase {
  public:
    //! constructor
    DYToEESelection(TChain *chain);
    //! destructor
    virtual ~DYToEESelection() { };
    //! loop over events
    void Loop();
    
  private:
    
  };

}

#endif
