#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "TObjString.h"

#define PRESCALE 1

typedef std::map<std::string, Float_t> SelectionCounter;
typedef std::vector<std::pair<std::string, Float_t> > SelectionPrinter;


typedef struct Event {
        Int_t           candidate_id;
        Float_t         CMS_hgg_mass;
        UInt_t          event;
        Float_t         l_egChIso;
        Float_t         l_egNhIso;
        Float_t         l_egPhIso;
        Float_t         l_hadTowOverEm;
        Float_t         l_hoe;
        Float_t         l_IdMva;
        Float_t         l_passElVeto;
        Float_t         l_phoID;
        Float_t         l_pt;
        Float_t         l_ptOMgg;
        Float_t         l_r9;
        Float_t         l_scEta;
        Float_t         l_scPhi;
        Float_t         l_sieie;
        UChar_t         lumi;
        Float_t         maxEta;
        Float_t         minR9;
        Float_t         npu;
        Int_t           nvtx;
        Int_t           processIndex;
        Float_t         rho;
        UInt_t          run;
        Float_t         s_egChIso;
        Float_t         s_egNhIso;
        Float_t         s_egPhIso;
        Float_t         s_hadTowOverEm;
        Float_t         s_hoe;
        Float_t         s_IdMva;
        Float_t         s_passElVeto;
        Float_t         s_phoID;
        Float_t         s_pt;
        Float_t         s_ptOMgg;
        Float_t         s_r9;
        Float_t         s_scEta;
        Float_t         s_scPhi;
        Float_t         s_sieie;
        Float_t         vtx_ndof;
        Float_t         vtx_x;
        Float_t         vtx_y;
        Float_t         vtx_z;
        Float_t         weight;
} Event;

Event e;


void set_adresses(TChain & c)
{
        c.SetBranchAddress("candidate_id", &e.candidate_id);
        c.SetBranchAddress("CMS_hgg_mass", &e.CMS_hgg_mass);
        c.SetBranchAddress("event", &e.event);
        c.SetBranchAddress("l_egChIso", &e.l_egChIso);
        c.SetBranchAddress("l_egNhIso", &e.l_egNhIso);
        c.SetBranchAddress("l_egPhIso", &e.l_egPhIso);
        c.SetBranchAddress("l_hadTowOverEm", &e.l_hadTowOverEm);
        c.SetBranchAddress("l_hoe", &e.l_hoe);
        c.SetBranchAddress("l_IdMva", &e.l_IdMva);
        c.SetBranchAddress("l_passElVeto", &e.l_passElVeto);
        c.SetBranchAddress("l_phoID", &e.l_phoID);
        c.SetBranchAddress("l_pt", &e.l_pt);
        c.SetBranchAddress("l_ptOMgg", &e.l_ptOMgg);
        c.SetBranchAddress("l_r9", &e.l_r9);
        c.SetBranchAddress("l_scEta", &e.l_scEta);
        c.SetBranchAddress("l_scPhi", &e.l_scPhi);
        c.SetBranchAddress("l_sieie", &e.l_sieie);
        c.SetBranchAddress("lumi", &e.lumi);
        c.SetBranchAddress("maxEta", &e.maxEta);
        c.SetBranchAddress("minR9", &e.minR9);
        c.SetBranchAddress("npu", &e.npu);
        c.SetBranchAddress("nvtx", &e.nvtx);
        c.SetBranchAddress("processIndex", &e.processIndex);
        c.SetBranchAddress("rho", &e.rho);
        c.SetBranchAddress("run", &e.run);
        c.SetBranchAddress("s_egChIso", &e.s_egChIso);
        c.SetBranchAddress("s_egNhIso", &e.s_egNhIso);
        c.SetBranchAddress("s_egPhIso", &e.s_egPhIso);
        c.SetBranchAddress("s_hadTowOverEm", &e.s_hadTowOverEm);
        c.SetBranchAddress("s_hoe", &e.s_hoe);
        c.SetBranchAddress("s_IdMva", &e.s_IdMva);
        c.SetBranchAddress("s_passElVeto", &e.s_passElVeto);
        c.SetBranchAddress("s_phoID", &e.s_phoID);
        c.SetBranchAddress("s_pt", &e.s_pt);
        c.SetBranchAddress("s_ptOMgg", &e.s_ptOMgg);
        c.SetBranchAddress("s_r9", &e.s_r9);
        c.SetBranchAddress("s_scEta", &e.s_scEta);
        c.SetBranchAddress("s_scPhi", &e.s_scPhi);
        c.SetBranchAddress("s_sieie", &e.s_sieie);
        c.SetBranchAddress("vtx_ndof", &e.vtx_ndof);
        c.SetBranchAddress("vtx_x", &e.vtx_x);
        c.SetBranchAddress("vtx_y", &e.vtx_y);
        c.SetBranchAddress("vtx_z", &e.vtx_z);
        c.SetBranchAddress("weight", &e.weight);
}


void set_statuses(TChain & c)
{
        c.SetBranchStatus("*", 0);
        c.SetBranchStatus("candidate_id", 0);
        c.SetBranchStatus("CMS_hgg_mass", 1);
        c.SetBranchStatus("event", 0);
        c.SetBranchStatus("l_egChIso", 1);
        c.SetBranchStatus("l_egNhIso", 1);
        c.SetBranchStatus("l_egPhIso", 1);
        c.SetBranchStatus("l_hadTowOverEm", 1);
        c.SetBranchStatus("l_hoe", 1);
        c.SetBranchStatus("l_IdMva", 0);
        c.SetBranchStatus("l_passElVeto", 1);
        c.SetBranchStatus("l_phoID", 1);
        c.SetBranchStatus("l_pt", 1);
        c.SetBranchStatus("l_ptOMgg", 1);
        c.SetBranchStatus("l_r9", 1);
        c.SetBranchStatus("l_scEta", 1);
        c.SetBranchStatus("l_scPhi", 0);
        c.SetBranchStatus("l_sieie", 1);
        c.SetBranchStatus("lumi", 0);
        c.SetBranchStatus("maxEta", 1);
        c.SetBranchStatus("minR9", 1);
        c.SetBranchStatus("npu", 1);
        c.SetBranchStatus("nvtx", 1);
        c.SetBranchStatus("processIndex", 0);
        c.SetBranchStatus("rho", 1);
        c.SetBranchStatus("run", 0);
        c.SetBranchStatus("s_egChIso", 1);
        c.SetBranchStatus("s_egNhIso", 1);
        c.SetBranchStatus("s_egPhIso", 1);
        c.SetBranchStatus("s_hadTowOverEm", 1);
        c.SetBranchStatus("s_hoe", 1);
        c.SetBranchStatus("s_IdMva", 1);
        c.SetBranchStatus("s_passElVeto", 1);
        c.SetBranchStatus("s_phoID", 1);
        c.SetBranchStatus("s_pt", 1);
        c.SetBranchStatus("s_ptOMgg", 1);
        c.SetBranchStatus("s_r9", 1);
        c.SetBranchStatus("s_scEta", 1);
        c.SetBranchStatus("s_scPhi", 0);
        c.SetBranchStatus("s_sieie", 1);
        c.SetBranchStatus("vtx_ndof", 1);
        c.SetBranchStatus("vtx_x", 1);
        c.SetBranchStatus("vtx_y", 1);
        c.SetBranchStatus("vtx_z", 1);
        c.SetBranchStatus("weight", 1);
}


double ea_chIso(float eta){
        // There is NO correction of EffArea for the CH iso in Spr15 25ns ID
        if (fabs(eta) < 1.0) return 0.0;
        else if (fabs(eta) >= 1.0 && fabs(eta) < 1.479)  return 0.0;
        else if (fabs(eta) >= 1.479 && fabs(eta) < 2.0 ) return 0.0;
        else if (fabs(eta) >= 2.0 && fabs(eta) < 2.2 )   return 0.0;
        else if (fabs(eta) >= 2.2 && fabs(eta) < 2.3 )   return 0.0;
        else if (fabs(eta) >= 2.3 && fabs(eta) < 2.4 )   return 0.0;
        else if (fabs(eta) >= 2.4) return 0.0;
        else return 0.;
}


double isoCh(float iso, float eta)
{
        return TMath::Max(iso - e.rho * ea_chIso(eta), 0.);
}


double ea_nhIso(float eta) {
        if (fabs(eta) < 1.0) return 0.0599;
        else if (fabs(eta) >= 1.0 && fabs(eta) < 1.479)  return 0.0819;
        else if (fabs(eta) >= 1.479 && fabs(eta) < 2.0 ) return 0.0696;
        else if (fabs(eta) >= 2.0 && fabs(eta) < 2.2 )   return 0.0360;
        else if (fabs(eta) >= 2.2 && fabs(eta) < 2.3 )   return 0.0360;
        else if (fabs(eta) >= 2.3 && fabs(eta) < 2.4 )   return 0.0462;
        else if (fabs(eta) >= 2.4) return 0.0656;
        else return 0.;
}


double isoNh(float iso, float eta)
{
        return TMath::Max(iso - e.rho * ea_nhIso(eta), 0.);
}


double ea_phIso(float eta) {
        if (fabs(eta) < 1.0) return 0.1271;
        else if (fabs(eta) >= 1.0 && fabs(eta) < 1.479)  return 0.1101;
        else if (fabs(eta) >= 1.479 && fabs(eta) < 2.0 ) return 0.0756;
        else if (fabs(eta) >= 2.0 && fabs(eta) < 2.2 )   return 0.1175;
        else if (fabs(eta) >= 2.2 && fabs(eta) < 2.3 )   return 0.1498;
        else if (fabs(eta) >= 2.3 && fabs(eta) < 2.4 )   return 0.1857;
        else if (fabs(eta) >= 2.4) return 0.2183;
        else return 0.;
}


double isoPh(float iso, float eta)
{
        return TMath::Max(iso - e.rho * ea_phIso(eta), 0.);
}


bool phID_CB_loose_50ns(float pt, float eta, float hoe, float sieie, float chIso, float nhIso, float phIso)
{
        float ae = fabs(eta);
        if (ae < 1.4442) {
                return hoe < 0.05
                        && sieie < 0.0103
                        && chIso < 2.44
                        && nhIso < 2.57 + exp(0.0044 * pt + 0.5809)
                        && phIso < 1.92 + 0.0043 * pt;
        } else if (ae > 1.566 && ae < 2.5) {
                return hoe < 0.05
                        && sieie < 0.0277
                        && chIso < 1.84
                        && nhIso < 4.00 + exp(0.0040 * pt + 0.9402)
                        && phIso < 2.15 + 0.0041 * pt;
        }
        return false;
}


bool phID_CB_loose_25ns(float pt, float eta, float hoe, float sieie, float chIso, float nhIso, float phIso)
{
        float ae = fabs(eta);
        if (ae < 1.4442) {
                return hoe < 0.05
                        && sieie < 0.0102
                        && chIso < 3.32
                        && nhIso < 1.92 + 0.014 * pt + 0.000019 * pt * pt
                        && phIso < 0.81 + 0.0053 * pt;
        } else if (ae > 1.566 && ae < 2.5) {
                return hoe < 0.05
                        && sieie < 0.0274
                        && chIso < 1.97
                        && nhIso < 11.86 + 0.0139 * pt + 0.000025 * pt * pt
                        && phIso < 0.83 + 0.0034 * pt;
        }
        return false;
}


bool phID_CB_medium_25ns(float pt, float eta, float hoe, float sieie, float chIso, float nhIso, float phIso)
{
        float ae = fabs(eta);
        if (ae < 1.4442) {
                return hoe < 0.05
                        && sieie < 0.0102
                        && chIso < 1.37
                        && nhIso < 1.06 + 0.014 * pt + 0.000019 * pt
                        && phIso < 0.28 + 0.0053 * pt;
        } else if (ae > 1.566 && ae < 2.5) {
                return hoe < 0.05
                        && sieie < 0.0268
                        && chIso < 1.10
                        && nhIso < 2.69 + 0.0139 * pt + 0.000025 * pt * pt
                        && phIso < 0.39 + 0.0034 * pt;
        }
        return false;
}


bool photonID_cutBased()
{
        return     phID_CB_loose_25ns(e.l_pt, e.l_scEta, e.l_hoe, e.l_sieie, isoCh(e.l_egChIso, e.l_scEta), isoNh(e.l_egNhIso, e.l_scEta), isoPh(e.l_egPhIso, e.l_scEta))
                && phID_CB_loose_25ns(e.s_pt, e.s_scEta, e.s_hoe, e.s_sieie, isoCh(e.s_egChIso, e.s_scEta), isoNh(e.s_egNhIso, e.s_scEta), isoPh(e.s_egPhIso, e.s_scEta));
}


bool vtx_sel()
{
        //printf("%f %f %f %f\n", e.vtx_x, e.vtx_y, e.vtx_z, e.vtx_ndof);
        return sqrt(e.vtx_x * e.vtx_x + e.vtx_y * e.vtx_y) <= 2 
                && fabs(e.vtx_z) < 24
                && e.vtx_ndof > 4;
}


std::string summary(SelectionCounter & s)
{
        SelectionPrinter p;
        for (auto i = s.begin(); i != s.end(); ++i) {
                p.push_back(*i);
        }
        std::sort(p.begin(), p.end(), [=](std::pair<std::string, Float_t>& a, std::pair<std::string, Float_t>& b)
             { return a.second > b.second; }
            );
        char tmp[256];
        std::string ss = "\n";
        Float_t evt_first = 0, evt_prev = 0;
        for (auto el : p) {
                if (!evt_first) evt_first = el.second;
                sprintf(tmp, "%20s = % 12.2f   %.2f  %.2f\n", el.first.c_str(), el.second, el.second / evt_first, el.second / evt_prev);
                evt_prev = el.second;
                ss += tmp;
        }
        printf("%s", ss.c_str());
        return ss;
}


void process_events(TChain & c, SelectionCounter & s)
{
        auto nentries = c.GetEntries();
        auto name = TString(c.GetName()).ReplaceAll("/", "_");
        auto fhisto = TFile::Open(name + ".root", "recreate");
        fhisto->cd();
        auto h_name = "h_" + name + "_all";
        TH1D * h_nvtx_all = new TH1D(h_name, h_name, 50, 0, 50);
        h_name = "h_" + name + "_sel_MVA";
        auto h_nvtx_sel_MVA = (TH1D*)h_nvtx_all->Clone(h_name);
        h_name = "h_" + name + "_sel_CB";
        auto h_nvtx_sel_CB = (TH1D*)h_nvtx_all->Clone(h_name);
        //h_name = "h_" + name + "_";
        //auto h_nvtx_sel_CB = (TH1D*)h_nvtx_all->Clone(h_name);
        for (auto iev = 0; iev < nentries; iev += PRESCALE) {
                if (iev && iev % 23456 == 0) fprintf(stderr, "analyzed events: % 15d  (%.2f)  -  %s\r", iev, iev * 100. / nentries, c.GetName());
                c.GetEntry(iev);
                auto w = e.weight * PRESCALE;
                s["all"] += w;
                h_nvtx_all->Fill(e.nvtx, w);
                if (e.l_r9 > 0.8 && e.s_r9 > 0.8
                    && isoCh(e.l_egChIso, e.l_scEta) < 20. && isoCh(e.s_egChIso, e.s_scEta) < 20.
                    && isoCh(e.l_egChIso, e.l_scEta) / e.l_pt < 0.3 && isoCh(e.s_egChIso, e.s_scEta) / e.s_pt< 0.3) {
                        s["isos"] += w;
                        if (e.l_hadTowOverEm < 0.8 && e.s_hadTowOverEm < 0.8) {
                                s["hoe"] += w;
                                if (photonID_cutBased()) {
                                        s["phoID_CutBasedLoose"] += w;
                                        h_nvtx_sel_CB->Fill(e.nvtx, w);
                                        if (e.l_ptOMgg >= 1. / 3. && e.s_ptOMgg >= 0.25 && e.maxEta < 2.5) {
                                                s["kin"] += w;
                                                if (vtx_sel()) {
                                                        s["vtx"] += w;
                                                        if (e.CMS_hgg_mass > 100 && e.CMS_hgg_mass < 180) {
                                                                s["mass_window"] += w;
                                                                if (e.l_passElVeto && e.s_passElVeto) {
                                                                        s["csev"] += w;
                                                                        if (e.l_phoID > -0.9 && e.s_phoID > -0.9) {
                                                                                s["phoID_MVA"] += w;
                                                                                h_nvtx_sel_MVA->Fill(e.nvtx, w);
                                                                        }
                                                                        if (e.l_IdMva > -0.9 && e.s_IdMva > -0.9) {
                                                                                s["phoID_MVA_view"] += w;
                                                                                h_nvtx_sel_MVA->Fill(e.nvtx, w);
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }

        }
        TObjString os(summary(s).c_str());
        os.Write("event_count_" + name);
        fhisto->Write();
        fprintf(stderr, "\n");
}


int main()
{
        std::vector<std::pair<std::unique_ptr<TChain>, std::string> > trees;
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/data_13TeV_all")), "../../../prod/data_DoubleEG_v5/output_*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/data_13TeV_all")), "../../../prod/data_DoubleEG_noMissing_v5/output_*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/_13TeV_all")), "output_singleshot.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/DYJetsToLL_13TeV_all")), "../../../prod/mc_SplusB_v5/output_DYJetsToLL*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/DiPhotonJetsBox_MGG_80toInf_13TeV_all")), "../../../prod/mc_SplusB_v5/output_DiPhotonJetsBox_MGG-80toInf*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GJet_Pt_20to40_13TeV_all")), "../../../prod/mc_SplusB_v5/output_GJet_Pt-20to40*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GJet_Pt_40toInf_13TeV_all")), "../../../prod/mc_SplusB_v5/output_GJet_Pt-40toInf*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/QCD_Pt_30to40_MGG_80toInf_13TeV_all")), "../../../prod/mc_SplusB_v5/output_QCD_Pt-30to40*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/QCD_Pt_30toInf_MGG_40to80_13TeV_all")), "../../../prod/mc_SplusB_v5/output_QCD_Pt-30toInf*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/QCD_Pt_40toInf_MGG_80toInf_13TeV_all")), "../../../prod/mc_SplusB_v5/output_QCD_Pt-40toInf*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GluGluHToGG_M_125_13TeV_powheg_13TeV_all")), "../../../prod/mc_SplusB_v5/output_GluGluHToGG_M-125_13TeV_powheg*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/VBFHToGG_M_125_13TeV_powheg_13TeV_all")), "../../../prod/mc_SplusB_v5/output_VBFHToGG_M-125_13TeV_powheg*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/VHToGG_M125_13TeV_amcatnloFXFX_13TeV_all")), "../../../prod/mc_SplusB_v5/output_VHToGG_M125_13TeV_amcatnloFXFX*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/ttHJetToGG_M125_13TeV_amcatnloFXFX_13TeV_all")), "../../../prod/mc_SplusB_v5/output_ttHJetToGG_M125_13TeV_amcatnloFXFX*.root" ) );

        for (auto & t : trees) {
                SelectionCounter c;
                printf("--------- %s ---------\n", t.first->GetName());
                t.first->Add(t.second.c_str());
                set_adresses(*t.first);
                set_statuses(*t.first);
                process_events(*t.first, c);
        }

        return 0;
}
