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
        )
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1 )
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True), wantSummary = cms.untracked.bool(True) )

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("test.root")
)

from flashgg.Systematics.flashggDiPhotonSystematics_cfi import smearBins, scaleBins, smearBinsRereco, scaleBinsRereco
process.flashggDiPhotonsScaled = cms.EDProducer('FlashggDiPhotonSystematicProducer',
                                              src = cms.InputTag("flashggDiPhotons"),
                                              SystMethods2D = cms.VPSet(),
                                              # the number of syst methods matches the number of nuisance parameters
                                              # assumed for a given systematic uncertainty and is NOT required
                                              # to match 1-to-1 the number of bins above.
                                              SystMethods = cms.VPSet(
                                                      cms.PSet( PhotonMethodName = cms.string("FlashggPhotonSigEoverESmearing"),
                                                               MethodName = cms.string("FlashggDiPhotonFromPhoton"),
                                                               Label = cms.string("DataSigmaEOverESmearing"),
                                                               NSigmas = cms.vint32(0,0),
                                                               OverallRange = cms.string("1"),
                                                               BinList = smearBinsRereco,
                                                               Debug = cms.untracked.bool(False)),
                                                      cms.PSet( PhotonMethodName = cms.string("FlashggPhotonScale"),
                                                               MethodName = cms.string("FlashggDiPhotonFromPhoton"),
                                                               Label = cms.string("DataScale"),
                                                               NSigmas = cms.vint32(0,0),
                                                               OverallRange = cms.string("1"),
                                                               BinList = scaleBinsRereco,
                                                               NoCentralShift = cms.bool(False),
                                                               Debug = cms.untracked.bool(False))
                                              ))

process.flashggDiPhotonsSmeared = cms.EDProducer('FlashggDiPhotonSystematicProducer',
                                                src = cms.InputTag("flashggDiPhotons"),
                                                SystMethods2D = cms.VPSet(),
                                                # the number of syst methods matches the number of nuisance parameters
                                                # assumed for a given systematic uncertainty and is NOT required
                                                # to match 1-to-1 the number of bins above.
                                                SystMethods = cms.VPSet(
                                                        cms.PSet( PhotonMethodName = cms.string("FlashggPhotonSigEoverESmearing"),
                                                                 MethodName = cms.string("FlashggDiPhotonFromPhoton"),
                                                                 Label = cms.string("MCSigmaEOverESmearing"),
                                                                 NSigmas = cms.vint32(0,0),
                                                                 OverallRange = cms.string("1"),
                                                                 BinList = smearBinsRereco,
                                                                 Debug = cms.untracked.bool(False)),
                                                        cms.PSet( PhotonMethodName = cms.string("FlashggPhotonSmearConstant"),
                                                                 MethodName = cms.string("FlashggDiPhotonFromPhoton"),
                                                                 #Label = cms.string("MCSmearHighR9EE"),
                                                                 Label = cms.string("MCSmear"),
                                                                 NSigmas = cms.vint32(-1,1),
                                                                 #OverallRange = cms.string("r9>0.94&&abs(superCluster.eta)>=1.5"),
                                                                 OverallRange = cms.string("1"),
                                                                 BinList = smearBinsRereco,
                                                                 # has to match the labels embedded in the photon object as
                                                                 # defined e.g. in flashgg/MicroAOD/python/flashggRandomizedPerPhotonDiPhotonProducer_cff.py
                                                                 #           or in flashgg/MicroAOD/python/flashggRandomizedPhotonProducer_cff.py (if at MicroAOD prod.)
                                                                 RandomLabel = cms.string("rnd_g_E"),
                                                                 Debug = cms.untracked.bool(False),
                                                                 ExaggerateShiftUp = cms.bool(False)),
                                                ))


from HLTrigger.HLTfilters.hltHighLevel_cfi import hltHighLevel
process.hltHighLevel= hltHighLevel.clone(HLTPaths = cms.vstring("HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95_v*") )

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

process.load("flashgg.Taggers.diphotonDumper_cfi") ##  import diphotonDumper 
import flashgg.Taggers.dumperConfigTools as cfgTools
#process.diphotonDumper.src = "kinPreselDiPhotons"
process.diphotonDumper.src = "flashggDiPhotons"
process.diphotonDumper.dumpTrees = True
process.diphotonDumper.dumpWorkspace = False
process.diphotonDumper.quietRooFit = True
process.diphotonDumper.maxCandPerEvent = -1 # take them all
process.diphotonDumper.nameTemplate ="$PROCESS_$SQRTS_$LABEL"
# split tree, histogram and datasets by process
#process.diphotonDumper.nameTemplate ="$PROCESS_$SQRTS_$LABEL_$SUBCAT"
## do not split by process
## process.diphotonDumper.nameTemplate = "minitree_$SQRTS_$LABEL_$SUBCAT"

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
                       variables=["CMS_hgg_mass[320,100,180]  := mass", 
                                  "l_pt                     := leadingPhoton.pt",
                                  "s_pt                     := subLeadingPhoton.pt",
                                  "l_eta                    := leadingPhoton.eta",
                                  "s_eta                    := subLeadingPhoton.eta",
                                  "l_phi                    := leadingPhoton.phi",
                                  "s_phi                    := subLeadingPhoton.phi",
                                  "l_ptOMgg                 := leadingPhoton.pt / mass",
                                  "s_ptOMgg                 := subLeadingPhoton.pt / mass",
                                  "l_IdMva                  := leadingView.phoIdMvaWrtChosenVtx",
                                  "s_IdMva                  := subLeadingView.phoIdMvaWrtChosenVtx",
                                  "l_r9                     := leadingPhoton.full5x5_r9",
                                  "s_r9                     := subLeadingPhoton.full5x5_r9",
                                  "l_sieie                  := leadingPhoton.full5x5_sigmaIetaIeta",
                                  "s_sieie                  := subLeadingPhoton.full5x5_sigmaIetaIeta",
                                  "l_egChIso                := leadingPhoton.egChargedHadronIso",
                                  "s_egChIso                := subLeadingPhoton.egChargedHadronIso",
                                  "l_egNhIso                := leadingPhoton.egNeutralHadronIso",
                                  "s_egNhIso                := subLeadingPhoton.egNeutralHadronIso",
                                  "l_egPhIso                := leadingPhoton.egPhotonIso",
                                  "s_egPhIso                := subLeadingPhoton.egPhotonIso",
                                  "l_scEta                  := leadingPhoton.superCluster.eta",
                                  "s_scEta                  := subLeadingPhoton.superCluster.eta",
                                  "l_scPhi                  := leadingPhoton.superCluster.phi",
                                  "s_scPhi                  := subLeadingPhoton.superCluster.phi",
                                  "l_phoID                  := leadPhotonId",
                                  "s_phoID                  := subLeadPhotonId",
                                  "l_hoe                    := leadingPhoton.hadronicOverEm",
                                  "s_hoe                    := subLeadingPhoton.hadronicOverEm",
                                  "l_hadTowOverEm           := leadingPhoton.hadTowOverEm",
                                  "s_hadTowOverEm           := subLeadingPhoton.hadTowOverEm",
                                  "l_passElVeto             := leadingPhoton.passElectronVeto",
                                  "s_passElVeto             := subLeadingPhoton.passElectronVeto",
                                  "l_trkSumPtHollowConeDR03 := leadingPhoton.trkSumPtHollowConeDR03",
                                  "s_trkSumPtHollowConeDR03 := subLeadingPhoton.trkSumPtHollowConeDR03",
                                  "vtx_x                    := vtx.x",
                                  "vtx_y                    := vtx.y",
                                  "vtx_z                    := vtx.z",
                                  "vtx_ndof                 := vtx.ndof",
                                  "gen_h_pt                 := genP4.pt",
                                  "gen_h_eta                := genP4.eta",
                                  "gen_h_phi                := genP4.phi",
                                  "gen_h_mass               := genP4.M",
                                  "gen_h_rapidity           := genP4.Rapidity",
                                  "gen_l_match              := leadingPhoton.genMatchType",
                                  "gen_s_match              := subLeadingPhoton.genMatchType",
                                  "minR9                    := min(leadingPhoton.r9,subLeadingPhoton.r9)",
                                  "maxEta                   := max(abs(leadingPhoton.superCluster.eta),abs(leadingPhoton.superCluster.eta))",
                                  ],
                       ## histograms to be plotted. 
                       ## the variables need to be defined first
                       histograms=[ ]
                       )




from flashgg.MetaData.JobConfig import customize
customize.setDefault("maxEvents", 20000)
customize.setDefault("targetLumi", 2.61e+3)
#customize.setDefault("puTarget", '1.435e+05,6.576e+05,8.781e+05,1.304e+06,2.219e+06,5.052e+06,1.643e+07,6.709e+07,1.975e+08,3.527e+08,4.44e+08,4.491e+08,3.792e+08,2.623e+08,1.471e+08,6.79e+07,2.748e+07,1.141e+07,5.675e+06,3.027e+06,1.402e+06,5.119e+05,1.467e+05,3.53e+04,8270,2235,721.3,258.8,97.27,36.87,13.73,4.932,1.692,0.5519,0.1706,0.04994,0.01383,0.003627,0.0008996,0.0002111,4.689e-05,9.854e-06,1.959e-06,3.686e-07,6.562e-08,1.105e-08,1.762e-09,2.615e-10,4.768e-11,0,0,0')
customize(process)

print "processType:", customize.processType, "processId:", customize.processId

if customize.processType == 'data':
        process.kinPreselDiPhotons.src = "flashggDiPhotonsScaled"
        process.diphotonDumper.src = "flashggDiPhotonsScaled" ################# FIXME
        #process.diphotonDumper.src = "flashggDiPhotons"
        #process.p = cms.Path( process.hltHighLevel * process.kinPreselDiPhotons * process.diphotonDumper )
        process.p = cms.Path( process.hltHighLevel * process.diphotonDumper )
else:
        process.kinPreselDiPhotons.src = "flashggDiPhotonsSmeared"
        process.diphotonDumper.src = "flashggDiPhotonsSmeared" ################# FIXME
        #process.diphotonDumper.src = "flashggDiPhotons"
        process.diphotonDumper.globalVariables.puReWeight = True
        process.p = cms.Path( process.diphotonDumper )
