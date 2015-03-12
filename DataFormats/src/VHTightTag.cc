#include "flashgg/DataFormats/interface/VHTightTag.h"
#include <algorithm>

using namespace flashgg;

VHTightTag::VHTightTag() : DiPhotonTagBase::DiPhotonTagBase()
{}

VHtightTag::~VHtightTag() 
{}


VHtightTag::VHtightTag(edm::Ptr<DiPhotonCandidate> diPho, edm::Ptr<DiPhotonMVAResult> mvares) : DiPhotonTagBase::DiPhotonTagBase(diPho,*mvares) {}
VHtightTag::VHtightTag(edm::Ptr<DiPhotonCandidate> dipho,DiPhotonMVAResult mvares) : DiPhotonTagBase::DiPhotonTagBase(dipho,mvares) {}

VHtightTag* VHtightTag::clone () const {
  VHtightTag* result = new VHtightTag(diPhoton(),diPhotonMVA());
  result->setDiPhotonIndex(getDiPhotonIndex());
  result->setJets(Jets_);
  result->setMuons(Muons_);
  result->setElectrons(Electrons_);
  result->setMET(MET_);

return result;
}


