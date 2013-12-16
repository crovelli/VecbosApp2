#include <iostream>

#include "DataFormats/include/SuperCluster.hh"
#include "DataFormats/include/SuperClusterFwd.hh"

#include "Analysis/include/DYToEESelection.hh"


using namespace std;
using namespace vecbos;

DYToEESelection::DYToEESelection(TChain *chain) :
  AnalysisBase(chain) { }

void DYToEESelection::Loop() {

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = loadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     cout << "Processing Event " << jentry << endl; 
     
     EventHeader header = Event.eventHeader();
     cout << "Event header: run = " << header.run() << "\tlumi = " << header.lumi() 
	  << "\t evt = " << header.event() << endl;

     cout << "this event has " << SuperClusters.size() << " SCs and " << PFSuperClusters.size() << " PF SCs " << endl;
   }

}
