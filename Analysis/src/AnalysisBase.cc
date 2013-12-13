#include "DataFormats/include/EventHeader.hh"

#include "Analysis/include/AnalysisBase.hh"

using namespace vecbos;

AnalysisBase::AnalysisBase(TChain *tree) :
  VecbosEventContent(tree)
{
  if(tree !=0) init(tree);
  else return;
}


void AnalysisBase::init(TTree* tree) {
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

void AnalysisBase::loadEventHeader() {
  EventHeader* eventHeader = new EventHeader();
  eventHeader->setRun(runNumber);
  eventHeader->setEvent(eventNumber);
  eventHeader->setLumi(lumiBlock);
  Event->setEventHeader(eventHeader);
}
