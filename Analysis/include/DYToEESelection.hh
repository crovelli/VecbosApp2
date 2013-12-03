#ifndef DY_TO_EE_SELECTION_HH
#define DY_TO_EE_SELECTION_HH

namespace vecbos {

  class DYToEESelection {
  public:
    //! constructor
    DYToEESelection(TChain *chain);
    //! destructor
    virtual ~DYToEESelection();
    //! loop over events
    void Loop();
    
  private:
    
  };
}

