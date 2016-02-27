#!/usr/bin/env cmsRun

import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

process = cms.Process("Analysis")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
#            "root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_1.root",
            #"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_222534/0000/myMicroAODOutputFile_137.root"
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_1.root",
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_1.root",
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-MoreSignal-1_2_0-25ns/1_2_0/GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8/RunIISpring15-MoreSignal-1_2_0-25ns-1_2_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160128_154054/0000/myMicroAODOutputFile_1.root",
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_10.root",
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_102.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_104.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_105.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_106.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_107.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_108.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_109.root", 
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_11.root ",

#QCD 40 inf
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223606/0000/myMicroAODOutputFile_1.root"
#QCD 30 inf
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/QCD_Pt-30toInf_DoubleEMEnriched_MGG-40to80_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223522/0000/myMicroAODOutputFile_1.root"
#QCD30-40
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/QCD_Pt-30to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223444/0000/myMicroAODOutputFile_1.root"
#gjet 40 inf
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_223028/0000/myMicroAODOutputFile_1.root"
#gjet 20-40
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_222944/0000/myMicroAODOutputFile_1.root"
#diphoton
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReMiniAOD-1_1_0-25ns/1_1_0/DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa/RunIISpring15-ReMiniAOD-1_1_0-25ns-1_1_0-v0-RunIISpring15MiniAODv2-74X_mcRun2_asymptotic_v2-v1/160105_222618/0000/myMicroAODOutputFile_1.root"

# Vittorio
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/sethzenz/flashgg/RunIISpring15-ReReco74X-1_1_0-25ns/1_1_0/DoubleEG/RunIISpring15-ReReco74X-1_1_0-25ns-1_1_0-v0-Run2015D-04Dec2015-v2/160112_095813/0000/myMicroAODOutputFile_1.root"

# Lucia
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/ferriff/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_1/GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_1-v0-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_ext2-v1/160127_023346/0000/myMicroAODOutputFile_1.root"
#"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/ferriff/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_1/GluGluHToGG_M-125_13TeV_powheg_pythia8/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_1-v0-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/160130_032602/0000/myMicroAODOutputFile_10.root"

# test 76X
"root://eoscms.cern.ch//eos/cms/store/group/phys_higgs/cmshgg/ferriff/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_1/DoubleEG/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_1-v0-Run2015C_25ns-16Dec2015-v1/160127_022819/0000/myMicroAODOutputFile_1.root"
        )
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 100 )
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True), wantSummary = cms.untracked.bool(True) )

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("test.root")
)

#from flashgg.Systematics.flashggDiPhotonSystematics_cfi import smearBins, scaleBins, smearBinsRereco, scaleBinsRereco
#process.flashggDiPhotonsScaled = cms.EDProducer('FlashggDiPhotonSystematicProducer',
#                                              src = cms.InputTag("flashggDiPhotons"),
#                                              SystMethods2D = cms.VPSet(),
#                                              # the number of syst methods matches the number of nuisance parameters
#                                              # assumed for a given systematic uncertainty and is NOT required
#                                              # to match 1-to-1 the number of bins above.
#                                              SystMethods = cms.VPSet(
#                                                      cms.PSet( PhotonMethodName = cms.string("FlashggPhotonSigEoverESmearing"),
#                                                               MethodName = cms.string("FlashggDiPhotonFromPhoton"),
#                                                               Label = cms.string("DataSigmaEOverESmearing"),
#                                                               NSigmas = cms.vint32(0,0),
#                                                               OverallRange = cms.string("1"),
#                                                               BinList = smearBinsRereco,
#                                                               ApplyCentralValue = cms.bool(True),
#                                                               Debug = cms.untracked.bool(False)),
#                                                      cms.PSet( PhotonMethodName = cms.string("FlashggPhotonScale"),
#                                                               MethodName = cms.string("FlashggDiPhotonFromPhoton"),
#                                                               Label = cms.string("DataScale"),
#                                                               NSigmas = cms.vint32(0,0),
#                                                               OverallRange = cms.string("1"),
#                                                               BinList = scaleBinsRereco,
#                                                               ApplyCentralValue = cms.bool(True),
#                                                               Debug = cms.untracked.bool(False))
#                                              ))
#
#process.flashggDiPhotonsSmeared = cms.EDProducer('FlashggDiPhotonSystematicProducer',
#                                                src = cms.InputTag("flashggDiPhotons"),
#                                                SystMethods2D = cms.VPSet(),
#                                                # the number of syst methods matches the number of nuisance parameters
#                                                # assumed for a given systematic uncertainty and is NOT required
#                                                # to match 1-to-1 the number of bins above.
#                                                SystMethods = cms.VPSet(
#                                                        cms.PSet( PhotonMethodName = cms.string("FlashggPhotonSigEoverESmearing"),
#                                                                 MethodName = cms.string("FlashggDiPhotonFromPhoton"),
#                                                                 Label = cms.string("MCSigmaEOverESmearing"),
#                                                                 NSigmas = cms.vint32(0,0),
#                                                                 OverallRange = cms.string("1"),
#                                                                 BinList = smearBinsRereco,
#                                                                 ApplyCentralValue = cms.bool(True),
#                                                                 Debug = cms.untracked.bool(False)),
#                                                        cms.PSet( PhotonMethodName = cms.string("FlashggPhotonSmearConstant"),
#                                                                 MethodName = cms.string("FlashggDiPhotonFromPhoton"),
#                                                                 #Label = cms.string("MCSmearHighR9EE"),
#                                                                 Label = cms.string("MCSmear"),
#                                                                 NSigmas = cms.vint32(-1,1),
#                                                                 #OverallRange = cms.string("r9>0.94&&abs(superCluster.eta)>=1.5"),
#                                                                 OverallRange = cms.string("1"),
#                                                                 BinList = smearBinsRereco,
#                                                                 # has to match the labels embedded in the photon object as
#                                                                 # defined e.g. in flashgg/MicroAOD/python/flashggRandomizedPerPhotonDiPhotonProducer_cff.py
#                                                                 #           or in flashgg/MicroAOD/python/flashggRandomizedPhotonProducer_cff.py (if at MicroAOD prod.)
#                                                                 RandomLabel = cms.string("rnd_g_E"),
#                                                                 Debug = cms.untracked.bool(False),
#                                                                 ApplyCentralValue = cms.bool(True),
#                                                                 ExaggerateShiftUp = cms.bool(False)),
#                                                ))

from HLTrigger.HLTfilters.hltHighLevel_cfi import hltHighLevel
#process.hltHighLevel= hltHighLevel.clone(HLTPaths = cms.vstring("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v*") )
process.hltHighLevel= hltHighLevel.clone(HLTPaths = cms.vstring(
    "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v*",
    "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v*",
    "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v*",
    "HLT_Ele22_eta2p1_WPLoose_Gsf_v*"
) )

from flashgg.Taggers.flashggPreselectedDiPhotons_cfi import flashggPreselectedDiPhotons
process.kinPreselDiPhotons = flashggPreselectedDiPhotons.clone(
        cut=cms.string(
        "1 || leadingPhoton.pt > 30 && subLeadingPhoton.pt > 20"
        ##"leadingPhoton.pt > 40 && subLeadingPhoton.pt > 30"
        ##" && abs(leadingPhoton.superCluster.eta)<2.5 && abs(subLeadingPhoton.superCluster.eta)<2.5 "
        ##" && ( abs(leadingPhoton.superCluster.eta)<1.4442 || abs(leadingPhoton.superCluster.eta)>1.566)"
        ##" && ( abs(subLeadingPhoton.superCluster.eta)<1.4442 || abs(subLeadingPhoton.superCluster.eta)>1.566)"
        ),
    variables = cms.vstring(),
    categories = cms.VPSet()
)

#############process.load("flashgg.Taggers.diphotonDumper_cfi") ##  import diphotonDumper 
#############import flashgg.Taggers.dumperConfigTools as cfgTools
##############process.diphotonDumper.src = "kinPreselDiPhotons"
#############process.diphotonDumper.src = "flashggDiPhotons"
#############process.diphotonDumper.dumpTrees = True
#############process.diphotonDumper.dumpWorkspace = False
#############process.diphotonDumper.quietRooFit = True
#############process.diphotonDumper.maxCandPerEvent = -1 # take them all
#############process.diphotonDumper.nameTemplate ="$PROCESS_$SQRTS_$LABEL"
############## split tree, histogram and datasets by process
##############process.diphotonDumper.nameTemplate ="$PROCESS_$SQRTS_$LABEL_$SUBCAT"
############### do not split by process
############### process.diphotonDumper.nameTemplate = "minitree_$SQRTS_$LABEL_$SUBCAT"

process.load("flashgg.Systematics.flashggDiPhotonSystematics_cfi")
process.flashggDiPhotonSystematics.src = "flashggUpdatedIdMVADiPhotons"

import flashgg.Taggers.dumperConfigTools as cfgTools

#process.load("flashgg.Taggers.flashggDiPhotonMVA_cfi")
#process.load("flashgg.Taggers.flashggTags_cff")
#process.load("flashgg.Taggers.flashggUpdatedIdMVADiPhotons_cfi")
process.load("flashgg/Taggers/flashggTagSequence_cfi")
process.load("flashgg/Taggers/flashggUpdatedIdMVADiPhotons_cfi")
#process.flashggDiPhotonMVA.DiPhotonTag = "flashggUpdatedIdMVADiPhotons"
process.flashggUntagged.Boundaries = cms.vdouble(-2)
process.flashggUntagged.DiPhotonTag    = "flashggDiPhotonSystematics"
process.flashggDiPhotonMVA.DiPhotonTag = "flashggDiPhotonSystematics"

from flashgg.Taggers.tagsDumpers_cfi import createTagDumper
process.diphotonDumper = createTagDumper("UntaggedTag")
process.diphotonDumper.src = "flashggUntagged"
process.diphotonDumper.maxCandPerEvent = -1 # take them all
process.diphotonDumper.splitLumiWeight=cms.untracked.bool(True)
process.diphotonDumper.dumpTrees = True
process.diphotonDumper.dumpWorkspace = False
process.diphotonDumper.quietRooFit = True
process.diphotonDumper.nameTemplate ="$PROCESS_$SQRTS_$LABEL"

process.diphotonDumper.globalVariables.addTriggerBits = cms.PSet(
    tag = cms.InputTag("TriggerResults::HLT"),
    bits = cms.vstring(
    "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95",
    "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55",
    "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55",
    "HLT_Ele22_eta2p1_WPLoose_Gsf_v"
    )
)


## define categories and associated objects to dump
cfgTools.addCategory(process.diphotonDumper,
                     "Reject",
                     #"abs(leadingPhoton.superCluster.eta)>=1.4442&&abs(leadingPhoton.superCluster.eta)<=1.566||abs(leadingPhoton.superCluster.eta)>=2.5"
                     #"||abs(subLeadingPhoton.superCluster.eta)>=1.4442 && abs(subLeadingPhoton.superCluster.eta)<=1.566||abs(subLeadingPhoton.superCluster.eta)>=2.5",
                     "0",
                      -1 ## if nSubcat is -1 do not store anythings
                     )

# interestng categories 
cfgTools.addCategories(process.diphotonDumper,
                       ## categories definition
                       ## cuts are applied in cascade. Events getting to these categories have already failed the "Reject" selection
                       #[("EBHighR9","max(abs(leadingPhoton.superCluster.eta),abs(leadingPhoton.superCluster.eta))<1.4442"
                       #  "&& min(leadingPhoton.r9,subLeadingPhoton.r9)>0.94",0), ## EB high R9
                       # ("EBLowR9","max(abs(leadingPhoton.superCluster.eta),abs(leadingPhoton.superCluster.eta))<1.4442",0), ## remaining EB is low R9
                       # ("EEHighR9","min(leadingPhoton.r9,subLeadingPhoton.r9)>0.94",0), ## then EE high R9
                       # ("EELowR9","1",0), ## evereything elese is EE low R9
                       # ],
                       [("all", "1", 0)],
                       ## variables to be dumped in trees/datasets. Same variables for all categories
                       ## if different variables wanted for different categories, can add categorie one by one with cfgTools.addCategory
                       variables=["CMS_hgg_mass[320,100,180] := diPhoton.mass",
                       "l_pt                                 := diPhoton.leadingPhoton.pt",
                       "s_pt                                 := diPhoton.subLeadingPhoton.pt",
                       "l_eta                                := diPhoton.leadingPhoton.eta",
                       "s_eta                                := diPhoton.subLeadingPhoton.eta",
                       "l_phi                                := diPhoton.leadingPhoton.phi",
                       "s_phi                                := diPhoton.subLeadingPhoton.phi",
                       "l_ptOMgg                             := diPhoton.leadingPhoton.pt / diPhoton.mass",
                       "s_ptOMgg                             := diPhoton.subLeadingPhoton.pt / diPhoton.mass",
                       "l_IdMva                              := diPhoton.leadingView.phoIdMvaWrtChosenVtx",
                       "s_IdMva                              := diPhoton.subLeadingView.phoIdMvaWrtChosenVtx",
                       "l_r9                                 := diPhoton.leadingPhoton.full5x5_r9",
                       "s_r9                                 := diPhoton.subLeadingPhoton.full5x5_r9",
                       "l_sieie                              := diPhoton.leadingPhoton.full5x5_sigmaIetaIeta",
                       "s_sieie                              := diPhoton.subLeadingPhoton.full5x5_sigmaIetaIeta",
                       "l_egChIso                            := diPhoton.leadingPhoton.egChargedHadronIso",
                       "s_egChIso                            := diPhoton.subLeadingPhoton.egChargedHadronIso",
                       "l_egNhIso                            := diPhoton.leadingPhoton.egNeutralHadronIso",
                       "s_egNhIso                            := diPhoton.subLeadingPhoton.egNeutralHadronIso",
                       "l_egPhIso                            := diPhoton.leadingPhoton.egPhotonIso",
                       "s_egPhIso                            := diPhoton.subLeadingPhoton.egPhotonIso",
                       "l_scEta                              := diPhoton.leadingPhoton.superCluster.eta",
                       "s_scEta                              := diPhoton.subLeadingPhoton.superCluster.eta",
                       "l_scPhi                              := diPhoton.leadingPhoton.superCluster.phi",
                       "s_scPhi                              := diPhoton.subLeadingPhoton.superCluster.phi",
                       "l_phoID                              := diPhoton.leadPhotonId",
                       "s_phoID                              := diPhoton.subLeadPhotonId",
                       "l_hoe                                := diPhoton.leadingPhoton.hadronicOverEm",
                       "s_hoe                                := diPhoton.subLeadingPhoton.hadronicOverEm",
                       "l_hadTowOverEm                       := diPhoton.leadingPhoton.hadTowOverEm",
                       "s_hadTowOverEm                       := diPhoton.subLeadingPhoton.hadTowOverEm",
                       "l_passElVeto                         := diPhoton.leadingPhoton.passElectronVeto",
                       "s_passElVeto                         := diPhoton.subLeadingPhoton.passElectronVeto",
                       "l_trkSumPtHollowConeDR03             := diPhoton.leadingPhoton.trkSumPtHollowConeDR03",
                       "s_trkSumPtHollowConeDR03             := diPhoton.subLeadingPhoton.trkSumPtHollowConeDR03",
                       "vtx_x                                := diPhoton.vtx.x",
                       "vtx_y                                := diPhoton.vtx.y",
                       "vtx_z                                := diPhoton.vtx.z",
                       "vtx_ndof                             := diPhoton.vtx.ndof",
                       "gen_h_pt                             := diPhoton.genP4.pt",
                       "gen_h_eta                            := diPhoton.genP4.eta",
                       "gen_h_phi                            := diPhoton.genP4.phi",
                       "gen_h_mass                           := diPhoton.genP4.M",
                       "gen_h_rapidity                       := diPhoton.genP4.Rapidity",
                       "gen_l_match                          := diPhoton.leadingPhoton.genMatchType",
                       "gen_l_pt                             := ? diPhoton.leadingPhoton.hasMatchedGenPhoton ? diPhoton.leadingPhoton.matchedGenPhoton.pt : -999",
                       "gen_l_eta                            := ? diPhoton.leadingPhoton.hasMatchedGenPhoton ? diPhoton.leadingPhoton.matchedGenPhoton.eta : -999",
                       "gen_l_phi                            := ? diPhoton.leadingPhoton.hasMatchedGenPhoton ? diPhoton.leadingPhoton.matchedGenPhoton.phi : -999",
                       "gen_s_match                          := diPhoton.subLeadingPhoton.genMatchType",
                       "gen_s_pt                             := ? diPhoton.subLeadingPhoton.hasMatchedGenPhoton ? diPhoton.subLeadingPhoton.matchedGenPhoton.pt : -999",
                       "gen_s_eta                            := ? diPhoton.subLeadingPhoton.hasMatchedGenPhoton ? diPhoton.subLeadingPhoton.matchedGenPhoton.eta : -999",
                       "gen_s_phi                            := ? diPhoton.subLeadingPhoton.hasMatchedGenPhoton ? diPhoton.subLeadingPhoton.matchedGenPhoton.phi : -999",
                       "minR9                                := min(diPhoton.leadingPhoton.r9,diPhoton.subLeadingPhoton.r9)",
                       "maxEta                               := max(abs(diPhoton.leadingPhoton.superCluster.eta),abs(diPhoton.leadingPhoton.superCluster.eta))",
                       "diphMVA                              := diPhotonMVA.mvaValue",
                       "diphVtxProb                          := diPhotonMVA.vtxprob",
                                  ],
                       ## histograms to be plotted. 
                       ## the variables need to be defined first
                       histograms=[ ]
                       )


from flashgg.MetaData.JobConfig import customize
customize.setDefault("maxEvents", 1000)
customize.setDefault("targetLumi", 2.61e+3)
#customize.setDefault("puTarget", '1.435e+05,6.576e+05,8.781e+05,1.304e+06,2.219e+06,5.052e+06,1.643e+07,6.709e+07,1.975e+08,3.527e+08,4.44e+08,4.491e+08,3.792e+08,2.623e+08,1.471e+08,6.79e+07,2.748e+07,1.141e+07,5.675e+06,3.027e+06,1.402e+06,5.119e+05,1.467e+05,3.53e+04,8270,2235,721.3,258.8,97.27,36.87,13.73,4.932,1.692,0.5519,0.1706,0.04994,0.01383,0.003627,0.0008996,0.0002111,4.689e-05,9.854e-06,1.959e-06,3.686e-07,6.562e-08,1.105e-08,1.762e-09,2.615e-10,4.768e-11,0,0,0')
customize(process)

print "processType:", customize.processType, "processId:", customize.processId

def debug_process(process):
        #print "--- Dumping modules that take diphotons as input: ---"
        #mns = process.p.moduleNames()
        #for mn in mns:
        #    module = getattr(process,mn)
        #    if hasattr(module,"src") and type(module.src) == type(cms.InputTag("")) and module.src.value().count("DiPhoton"):
        #        print str(module),module.src
        #    elif hasattr(module,"DiPhotonTag"):
        #        print str(module),module.DiPhotonTag
        #print
        vpsetlist = [process.flashggDiPhotonSystematics.SystMethods]
        print (14*"-"+" DUMPING SYSTEMATIC OVERVIEW "+14*"-")
        print "%20s %15s %20s" % ("Systematic","Central value?","Systematic shifts?")
        print 57*"-"
        printSystematicVPSet(vpsetlist)
        print (13*"-"+" DUMPING 2D SYSTEMATIC OVERVIEW "+12*"-")
        print "%20s %15s %20s" % ("Systematic","Central value?","Systematic shifts?")
        print 57*"-"
        vpsetlist2D  = [process.flashggDiPhotonSystematics.SystMethods2D]
        printSystematicVPSet(vpsetlist2D)

from flashgg.Systematics.SystematicsCustomize import *
process.load("flashgg.Systematics.escales.escale76X_16DecRereco_2015")

# remove old scales and smearings
for isyst in [ process.MCScaleHighR9EB, process.MCScaleLowR9EB, process.MCScaleHighR9EE, process.MCScaleLowR9EE ]:
    process.flashggDiPhotonSystematics.SystMethods.remove(isyst)
# add EGM scales and smearings
for isyst in [ process.MCScaleHighR9EB_EGM, process.MCScaleLowR9EB_EGM, process.MCScaleHighR9EE_EGM, process.MCScaleLowR9EE_EGM ]:
    process.flashggDiPhotonSystematics.SystMethods.insert(0, isyst)

# remove old scales and smearings
for isyst in [ process.MCSmearHighR9EE, process.MCSmearLowR9EE, process.MCSmearHighR9EB, process.MCSmearLowR9EB ]:
    process.flashggDiPhotonSystematics.SystMethods.remove(isyst)

# add EGM scales and smearings (2D)
process.flashggDiPhotonSystematics.SystMethods2D.extend([
    process.MCSmearHighR9EE_EGM,
    process.MCSmearLowR9EE_EGM,
    process.MCSmearHighR9EB_EGM,
    process.MCSmearLowR9EB_EGM ])


def feCustomizePhotonSystematicsForData(process):
    print "my customization for data"
    process.flashggDiPhotonSystematics.SystMethods = customizeVPSetForData(process.flashggDiPhotonSystematics.SystMethods, None)
    process.flashggDiPhotonSystematics.SystMethods2D = customizeVPSetForData(process.flashggDiPhotonSystematics.SystMethods2D, None)



if customize.processType == 'data':
        print 'data'
        process.p = cms.Path( process.hltHighLevel * process.flashggDiPhotonMVA * process.diphotonDumper )
        #delattr(process, "photonScaleBinsData")
        process.photonScaleBinsData = process.emptyBins.clone()
        customizePhotonSystematicsForData(process)
        #feCustomizePhotonSystematicsForData(process)
        debug_process(process)
else:
        print 'not data'
        #customizePhotonSystematicsForBackground(process)
        customizeSystematicsForMC(process)
        process.p = cms.Path( process.flashggDiPhotonMVA * process.diphotonDumper )
        process.diphotonDumper.globalVariables.puReWeight = True
        vpsetlist = [process.flashggDiPhotonSystematics.SystMethods]
        for vpset in vpsetlist:
            for pset in vpset:
                pset.NSigmas = cms.vint32()
        debug_process(process)
