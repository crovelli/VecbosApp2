#include <iostream>

#include "DataFormats/include/EventHeader.hh"
#include "Analysis/include/AnalysisBase.hh"

#include "DataFormats/include/SuperCluster.hh"

using namespace std;
using namespace vecbos;

AnalysisBase::AnalysisBase(TTree *tree) :
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

  // load the Event Header (run, lumi,...)
  loadEventHeader();

  // load the Super Cluster collection
  loadSuperClusters();
  loadPFSuperClusters();


  return centry;
}

void AnalysisBase::loadEventHeader() {
  EventHeader eventHeader(runNumber,eventNumber,lumiBlock);
  Event.setEventHeader(eventHeader);
}


void AnalysisBase::loadSuperClusters() {

  SuperClusters.clear();

  for(int i=0; i<nSC; ++i) {
    
    TVector3 position(xPosSC[i],yPosSC[i],zPosSC[i]);
    TVector3 direction;
    float pt = energySC[i]*fabs(sin(thetaSC[i]));
    direction.SetPtEtaPhi(pt,etaSC[i],phiSC[i]);
    
    SuperCluster::ClusterShapes shapes;
    shapes.nCrystals = nCrystalsSC[i];
    shapes.phiWidth = phiWidthSC[i];
    shapes.etaWidth = etaWidthSC[i];
    shapes.e3x3 = e3x3SC[i];
    shapes.e3x1 = e3x1SC[i];
    shapes.e1x3 = e1x3SC[i];
    shapes.e4x4 = e4x4SC[i];
    shapes.e5x5 = e5x5SC[i];
    shapes.e2x2 = e2x2SC[i];
    shapes.e1x5 = e1x5SC[i];
    shapes.e2x5Max = e2x5MaxSC[i];
    shapes.e2x5Left = e2x5LeftSC[i];
    shapes.e2x5Right = e2x5RightSC[i];
    shapes.e2x5Top = e2x5TopSC[i];
    shapes.e2x5Bottom = e2x5BottomSC[i];
    shapes.eLeft = eLeftSC[i];
    shapes.eRight = eRightSC[i];
    shapes.eTop = eTopSC[i];
    shapes.eBottom = eBottomSC[i];
    shapes.e4SwissCross = e4SwissCrossSC[i];
    shapes.eMax = eMaxSC[i];
    shapes.e2nd = e2ndSC[i];
    shapes.sigmaIetaIeta = sqrt(covIEtaIEtaSC[i]);
    shapes.sigmaIphiIphi = sqrt(covIPhiIPhiSC[i]);
    shapes.sigmaIetaIphi = sqrt(covIEtaIPhiSC[i]);

    SuperCluster supercl(energySC[i],position,direction,shapes);
    supercl.setRawEnergy(rawEnergySC[i]);
    supercl.setPreshowerEnergy(esEnergySC[i]);
    supercl.setPreshowerEnergyPlane1(esL1EnergySC[i]);
    supercl.setPreshowerEnergyPlane2(esL2EnergySC[i]);
    supercl.setClustersSize(nBCSC[i]);

    SuperClusters.push_back(supercl);

  }

}


void AnalysisBase::loadPFSuperClusters() {

  PFSuperClusters.clear();

  for(int i=0; i<nPFSC; ++i) {
    
    TVector3 position(xPosPFSC[i],yPosPFSC[i],zPosPFSC[i]);
    TVector3 direction;
    float pt = energyPFSC[i]*fabs(sin(thetaPFSC[i]));
    direction.SetPtEtaPhi(pt,etaPFSC[i],phiPFSC[i]);
    
    SuperCluster::ClusterShapes shapes;
    shapes.nCrystals = nCrystalsPFSC[i];
    shapes.phiWidth = phiWidthPFSC[i];
    shapes.etaWidth = etaWidthPFSC[i];
    shapes.e3x3 = e3x3PFSC[i];
    shapes.e3x1 = e3x1PFSC[i];
    shapes.e1x3 = e1x3PFSC[i];
    shapes.e4x4 = e4x4PFSC[i];
    shapes.e5x5 = e5x5PFSC[i];
    shapes.e2x2 = e2x2PFSC[i];
    shapes.e1x5 = e1x5PFSC[i];
    shapes.e2x5Max = e2x5MaxPFSC[i];
    shapes.e2x5Left = e2x5LeftPFSC[i];
    shapes.e2x5Right = e2x5RightPFSC[i];
    shapes.e2x5Top = e2x5TopPFSC[i];
    shapes.e2x5Bottom = e2x5BottomPFSC[i];
    shapes.eLeft = eLeftPFSC[i];
    shapes.eRight = eRightPFSC[i];
    shapes.eTop = eTopPFSC[i];
    shapes.eBottom = eBottomPFSC[i];
    shapes.e4SwissCross = e4SwissCrossPFSC[i];
    shapes.eMax = eMaxPFSC[i];
    shapes.e2nd = e2ndPFSC[i];
    shapes.sigmaIetaIeta = sqrt(covIEtaIEtaPFSC[i]);
    shapes.sigmaIphiIphi = sqrt(covIPhiIPhiPFSC[i]);
    shapes.sigmaIetaIphi = sqrt(covIEtaIPhiPFSC[i]);

    SuperCluster supercl(energyPFSC[i],position,direction,shapes);
    supercl.setRawEnergy(rawEnergyPFSC[i]);
    supercl.setPreshowerEnergy(esEnergyPFSC[i]);
    supercl.setPreshowerEnergyPlane1(esL1EnergyPFSC[i]);
    supercl.setPreshowerEnergyPlane2(esL2EnergyPFSC[i]);
    supercl.setClustersSize(nBCPFSC[i]);

    PFSuperClusters.push_back(supercl);

  }

}
