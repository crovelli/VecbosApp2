#include "Analysis/include/AnalysisBase.hh"

AnalysisBase::AnalysisBase(TTree *tree) :
  fChain(0)
{
  if(tree !=0) init(tree);
  else return;
}

AnalysisBase::~AnalysisBase() { }

bool AnalysisBase::init(TTree* tree) {
  if(!tree) return;
  else Init(tree);
  
}

int AnalysisBase::loadTree(Long64_t entry) {

  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  
  // load the Vecbos Event
  loadEventHeader();

  return centry;
}

void loadEventHeader() {
  EventHeader* eventHeader = new EventHeader();
  eventHeader->setRun(runNumber);
  eventHeader->setEvent(eventNumber);
  eventHeader->setLumi(lumiBlock);
  Event->setEventHeader(eventHeader)
}

AnalysisBase::AnalysisBase(TChain *chain) {
  initVecbosTree(chain);
}

bool AnalysisBase::initVecbosTree(TTree* tree) {
  if(!tree) return false;
  
  
}
