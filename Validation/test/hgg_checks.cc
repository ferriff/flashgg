#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Rtypes.h"
#include "TBits.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "TRandom3.h"
#include "TObjString.h"

#include <iostream>

#include "turnon.cc"

#define PRESCALE 1

typedef std::map<std::string, Float_t> SelectionCounter;
typedef std::vector<std::pair<std::string, Float_t> > SelectionPrinter;


typedef struct Event {
        Int_t           candidate_id;
        Float_t         CMS_hgg_mass;
        UInt_t          event;
        Float_t         gen_h_eta;
        Float_t         gen_h_mass;
        Float_t         gen_h_phi;
        Float_t         gen_h_pt;
        Float_t         gen_h_rapidity;
        Float_t         gen_l_match;
        Float_t         gen_s_match;
        Float_t         l_egChIso;
        Float_t         l_egNhIso;
        Float_t         l_egPhIso;
        Float_t         l_eta;
        Float_t         l_hadTowOverEm;
        Float_t         l_hoe;
        Float_t         l_IdMva;
        Float_t         l_passElVeto;
        Float_t         l_phi;
        Float_t         l_phoID;
        Float_t         l_pt;
        Float_t         l_ptOMgg;
        Float_t         l_r9;
        Float_t         l_scEta;
        Float_t         l_scPhi;
        Float_t         l_sieie;
        Float_t         l_trkSumPtHollowConeDR03;
        //UChar_t         lumi;
        Int_t           lumi;
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
        Float_t         s_eta;
        Float_t         s_hadTowOverEm;
        Float_t         s_hoe;
        Float_t         s_IdMva;
        Float_t         s_passElVeto;
        Float_t         s_phi;
        Float_t         s_phoID;
        Float_t         s_pt;
        Float_t         s_ptOMgg;
        Float_t         s_r9;
        Float_t         s_scEta;
        Float_t         s_scPhi;
        Float_t         s_sieie;
        Float_t         s_trkSumPtHollowConeDR03;
        Float_t         vtx_ndof;
        Float_t         vtx_x;
        Float_t         vtx_y;
        Float_t         vtx_z;
        Float_t         weight;
        Double_t        lumiFactor;
        Float_t         puweight;
        Float_t         diphMVA;
        Bool_t          hlt_singleEle;
} Event;

Event e;


void set_adresses(TChain & c)
{
        c.SetBranchAddress("candidate_id", &e.candidate_id);
        c.SetBranchAddress("CMS_hgg_mass", &e.CMS_hgg_mass);
        c.SetBranchAddress("event", &e.event);
        c.SetBranchAddress("gen_h_eta", &e.gen_h_eta);
        c.SetBranchAddress("gen_h_mass", &e.gen_h_mass);
        c.SetBranchAddress("gen_h_phi", &e.gen_h_phi);
        c.SetBranchAddress("gen_h_pt", &e.gen_h_pt);
        c.SetBranchAddress("gen_h_rapidity", &e.gen_h_rapidity);
        c.SetBranchAddress("gen_l_match", &e.gen_l_match);
        c.SetBranchAddress("gen_s_match", &e.gen_s_match);
        c.SetBranchAddress("l_egChIso", &e.l_egChIso);
        c.SetBranchAddress("l_egNhIso", &e.l_egNhIso);
        c.SetBranchAddress("l_egPhIso", &e.l_egPhIso);
        c.SetBranchAddress("l_eta", &e.l_eta);
        c.SetBranchAddress("l_hadTowOverEm", &e.l_hadTowOverEm);
        c.SetBranchAddress("l_hoe", &e.l_hoe);
        c.SetBranchAddress("l_IdMva", &e.l_IdMva);
        c.SetBranchAddress("l_passElVeto", &e.l_passElVeto);
        c.SetBranchAddress("l_phi", &e.l_phi);
        c.SetBranchAddress("l_phoID", &e.l_phoID);
        c.SetBranchAddress("l_pt", &e.l_pt);
        c.SetBranchAddress("l_ptOMgg", &e.l_ptOMgg);
        c.SetBranchAddress("l_r9", &e.l_r9);
        c.SetBranchAddress("l_scEta", &e.l_scEta);
        c.SetBranchAddress("l_scPhi", &e.l_scPhi);
        c.SetBranchAddress("l_sieie", &e.l_sieie);
        c.SetBranchAddress("l_trkSumPtHollowConeDR03", &e.l_trkSumPtHollowConeDR03);
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
        c.SetBranchAddress("s_eta", &e.s_eta);
        c.SetBranchAddress("s_hadTowOverEm", &e.s_hadTowOverEm);
        c.SetBranchAddress("s_hoe", &e.s_hoe);
        c.SetBranchAddress("s_IdMva", &e.s_IdMva);
        c.SetBranchAddress("s_passElVeto", &e.s_passElVeto);
        c.SetBranchAddress("s_phi", &e.s_phi);
        c.SetBranchAddress("s_phoID", &e.s_phoID);
        c.SetBranchAddress("s_pt", &e.s_pt);
        c.SetBranchAddress("s_ptOMgg", &e.s_ptOMgg);
        c.SetBranchAddress("s_r9", &e.s_r9);
        c.SetBranchAddress("s_scEta", &e.s_scEta);
        c.SetBranchAddress("s_scPhi", &e.s_scPhi);
        c.SetBranchAddress("s_sieie", &e.s_sieie);
        c.SetBranchAddress("s_trkSumPtHollowConeDR03", &e.s_trkSumPtHollowConeDR03);
        c.SetBranchAddress("vtx_ndof", &e.vtx_ndof);
        c.SetBranchAddress("vtx_x", &e.vtx_x);
        c.SetBranchAddress("vtx_y", &e.vtx_y);
        c.SetBranchAddress("vtx_z", &e.vtx_z);
        c.SetBranchAddress("weight", &e.weight);
        c.SetBranchAddress("lumiFactor", &e.lumiFactor);
        c.SetBranchAddress("diphMVA", &e.diphMVA);
        if (!TString(c.GetName()).Contains("data")) c.SetBranchAddress("puweight", &e.puweight);
        else {
                c.SetBranchAddress("HLT_Ele22_eta2p1_WPLoose_Gsf_v", &e.hlt_singleEle);
        }
}


void set_statuses(TChain & c)
{
        c.SetBranchStatus("*", 1);
        /*
        c.SetBranchStatus("candidate_id", 1);
        c.SetBranchStatus("CMS_hgg_mass", 1);
        c.SetBranchStatus("event", 1);
        c.SetBranchStatus("l_egChIso", 1);
        c.SetBranchStatus("l_egNhIso", 1);
        c.SetBranchStatus("l_egPhIso", 1);
        c.SetBranchStatus("l_hadTowOverEm", 1);
        c.SetBranchStatus("l_hoe", 1);
        c.SetBranchStatus("l_IdMva", 1);
        c.SetBranchStatus("l_passElVeto", 1);
        c.SetBranchStatus("l_phoID", 1);
        c.SetBranchStatus("l_pt", 1);
        c.SetBranchStatus("l_ptOMgg", 1);
        c.SetBranchStatus("l_r9", 1);
        c.SetBranchStatus("l_scEta", 1);
        c.SetBranchStatus("l_scPhi", 1);
        c.SetBranchStatus("l_sieie", 1);
        c.SetBranchStatus("lumi", 1);
        c.SetBranchStatus("maxEta", 1);
        c.SetBranchStatus("minR9", 1);
        c.SetBranchStatus("npu", 1);
        c.SetBranchStatus("nvtx", 1);
        c.SetBranchStatus("processIndex", 1);
        c.SetBranchStatus("rho", 1);
        c.SetBranchStatus("run", 1);
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
        c.SetBranchStatus("s_scPhi", 1);
        c.SetBranchStatus("s_sieie", 1);
        c.SetBranchStatus("vtx_ndof", 1);
        c.SetBranchStatus("vtx_x", 1);
        c.SetBranchStatus("vtx_y", 1);
        c.SetBranchStatus("vtx_z", 1);
        c.SetBranchStatus("weight", 1);
        */
}


bool isEB(float eta)
{
        return fabs(eta) < 1.4442;
}


bool isEE(float eta)
{
        return fabs(eta) > 1.566 && fabs(eta) < 2.5;
}


bool isEBEB(float eta1, float eta2)
{
        return isEB(eta1) && isEB(eta2);
}


bool isEEEE(float eta1, float eta2)
{
        return isEE(eta1) && isEE(eta2);
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


bool geometrical_acceptance(float eta1, float eta2)
{
        float ae1(fabs(eta1)), ae2(fabs(eta2));
        return     (ae1 < 1.4442 || (ae1 > 1.566 && ae1 < 2.5))
                && (ae2 < 1.4442 || (ae2 > 1.566 && ae2 < 2.5));
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


bool check_bit(TBits & b, int n)
{
        if (b[n]) return false;
        else {
                b[n] = kTRUE;
        }
        return true;
}


bool turnon_hlt(float l_pt, float s_pt, TRandom & r)
{
        // turnon histograms both declared global and filled in turnon.cc
        float l_eff = _h_hlt_leading_pt->GetBinContent(_h_hlt_leading_pt->FindBin(l_pt));
        float s_eff = _h_hlt_subleading_pt->GetBinContent(_h_hlt_subleading_pt->FindBin(s_pt));
        return r.Uniform() < l_eff && r.Uniform() < s_eff;
}


bool turnon_l1(float l_pt, float s_pt, TRandom & r)
{
        // turnon histograms both declared global and filled in turnon.cc
        float l_eff = _h_l1_leading_pt->GetBinContent(_h_l1_leading_pt->FindBin(l_pt));
        float s_eff = _h_l1_subleading_pt->GetBinContent(_h_l1_subleading_pt->FindBin(s_pt));
        //printf("--> %f %f  %f %f %d %d\n", l_pt, s_pt, l_eff, s_eff, _h_l1_leading_pt->FindBin(l_pt), _h_l1_subleading_pt->FindBin(s_pt));
        return r.Uniform() < l_eff && r.Uniform() < s_eff;
}


bool turnon(float l_pt, float s_pt, TRandom & r)
{
        return turnon_l1(l_pt, s_pt, r) && turnon_hlt(l_pt, s_pt, r);
}


bool flashgg_preselection()
{
        bool presel = 
           (e.l_r9 > 0.8 || e.l_egChIso < 20 || e.l_egChIso / e.l_pt < 0.3)
        && (e.s_r9 > 0.8 || e.s_egChIso < 20 || e.s_egChIso / e.s_pt < 0.3)
        //&& (e.l_hadTowOverEm < 0.08 && e.s_hadTowOverEm < 0.08)
        && (e.l_hoe < 0.08 && e.s_hoe < 0.08)
        && (e.l_pt > 30. && e.s_pt > 20.0)
        && (fabs(e.l_scEta) < 2.5    && fabs(e.s_scEta) < 2.5)
        && (fabs(e.l_scEta) < 1.4442 || fabs(e.l_scEta) > 1.566)
        && (fabs(e.s_scEta) < 1.4442 || fabs(e.s_scEta) > 1.566)
        && (e.l_IdMva > -0.9 && e.s_IdMva > -0.9)
        ;

        // leading
        bool lead    = (isEB(e.l_scEta) && ((e.l_r9 < 0.85 && e.l_egPhIso < 4. && e.l_sieie < 0.015 && e.l_trkSumPtHollowConeDR03 < 6.) || (e.l_r9 >= 0.85)))
                    || (isEE(e.l_scEta) && ((e.l_r9 <= 0.9 && e.l_egPhIso < 4. && e.l_sieie < 0.035 && e.l_trkSumPtHollowConeDR03 < 6.) || (e.l_r9 >= 0.85)));
        // subleading
        bool sublead = (isEB(e.s_scEta) && ((e.s_r9 < 0.85 && e.s_egPhIso < 4. && e.s_sieie < 0.015 && e.s_trkSumPtHollowConeDR03 < 6.) || (e.s_r9 >= 0.85)))
                    || (isEE(e.s_scEta) && ((e.s_r9 <= 0.9 && e.s_egPhIso < 4. && e.s_sieie < 0.035 && e.s_trkSumPtHollowConeDR03 < 6.) || (e.s_r9 >= 0.85)));

        return presel && lead && sublead;
}


Double_t process_events(TChain & c, SelectionCounter & s)
{
        auto nentries = c.GetEntries();
        auto name = TString(c.GetName()).ReplaceAll("/", "_");

        bool dy   = TString(c.GetName()).Contains("DYJets");
        bool qcd  = TString(c.GetName()).Contains("QCD");
        bool gjet = TString(c.GetName()).Contains("GJet");
        bool data = TString(c.GetName()).Contains("data");

        auto fhisto = TFile::Open(name + ".root", "recreate");
        fhisto->cd();
        auto h_name = "h_" + name + "_nvtx_all";
        TH1D * h_nvtx_all = new TH1D(h_name, h_name, 50, 0, 50);
        h_name = "h_" + name + "_nvtx_selected";
        auto h_nvtx_final = (TH1D*)h_nvtx_all->Clone(h_name);

        h_name = "h_" + name + "_mass_inclusive_all";
        TH1D * h_mass_all = new TH1D(h_name, h_name, 260, 50, 180);

        h_name = "h_" + name + "_mass_inclusive_selected";
        auto h_mass_final = (TH1D*)h_mass_all->Clone(h_name);

        h_name = "h_" + name + "_mass_ebeb_selected";
        auto h_mass_ebeb_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_ebeb_hr9_selected";
        auto h_mass_ebeb_hr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_ebeb_lr9_selected";
        auto h_mass_ebeb_lr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_ebeb_nothr9_selected";
        auto h_mass_ebeb_nothr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_notebeb_hr9_selected";
        auto h_mass_notebeb_hr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_notebeb_nothr9_selected";
        auto h_mass_notebeb_nothr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_ebee_selected";
        auto h_mass_ebee_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_ebee_hr9_selected";
        auto h_mass_ebee_hr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_ebee_lr9_selected";
        auto h_mass_ebee_lr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_eeee_selected";
        auto h_mass_eeee_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_eeee_hr9_selected";
        auto h_mass_eeee_hr9_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_eeee_lr9_selected";
        auto h_mass_eeee_lr9_final = (TH1D*)h_mass_all->Clone(h_name);

        h_name = "h_" + name + "_l_r9_all";
        TH1D * h_l_r9_all = new TH1D(h_name, h_name, 1000, 0., 1.);
        h_name = "h_" + name + "_s_r9_all";
        auto h_s_r9_all = (TH1D*)h_l_r9_all->Clone(h_name);
        h_name = "h_" + name + "_l_r9_selected";
        auto h_l_r9_final = (TH1D*)h_l_r9_all->Clone(h_name);
        h_name = "h_" + name + "_s_r9_selected";
        auto h_s_r9_final = (TH1D*)h_l_r9_all->Clone(h_name);
        h_name = "h_" + name + "_eb_r9_selected";
        auto h_eb_r9_final = (TH1D*)h_l_r9_all->Clone(h_name);
        h_name = "h_" + name + "_ee_r9_selected";
        auto h_ee_r9_final = (TH1D*)h_l_r9_all->Clone(h_name);

        /*
        h_name = "h_" + name + "_mass_selected";
        auto h_mass_final = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_selected_ebeb";
        auto h_mass_final_ebeb = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_selected_eeee";
        auto h_mass_final_eeee = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_selected_turnon";
        auto h_mass_final_turnon = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_selected_turnon_ebeb";
        auto h_mass_final_turnon_ebeb = (TH1D*)h_mass_all->Clone(h_name);
        h_name = "h_" + name + "_mass_selected_turnon_eeee";
        auto h_mass_final_turnon_eeee = (TH1D*)h_mass_all->Clone(h_name);
        */

        TRandom3 r(287346);

        bool one_pass = false;
        TBits bits;
        //nentries = 100;
        Double_t tot = 0.;
        for (auto iev = 0; iev < nentries; iev += PRESCALE) {
                if (iev && iev % 23456 == 0) fprintf(stderr, "analyzed events: % 15d  (%.2f)  -  %s\r", iev, iev * 100. / nentries, c.GetName());
                c.GetEntry(iev);

                int sel = 0;
                //if (e.candidate_id != 0) continue; // FIXME
                if (e.candidate_id == 0) {
                        one_pass = false;
                        bits.ResetAllBits();
                }
                if (one_pass) continue;
                if (data) e.puweight = 1.;
                else {
                        e.hlt_singleEle = kTRUE;
                }
                if ((qcd || gjet) && e.gen_l_match == 1 && e.gen_s_match == 1) continue;

                auto w = e.weight * e.lumiFactor * PRESCALE;
                //auto w = 1.; // FIXME

                // HLT requirement
                if (data && !e.hlt_singleEle) continue;

                if ( check_bit(bits, sel++) ) {
                        s["trigger"] += w;
                        h_nvtx_all->Fill(e.nvtx, w);
                        h_l_r9_all->Fill(e.l_r9, w);
                        h_s_r9_all->Fill(e.s_r9, w);
                        if (e.CMS_hgg_mass < 115 || e.CMS_hgg_mass > 135 || !data) h_mass_all->Fill(e.CMS_hgg_mass, w);
                }

                /*
                if (! geometrical_acceptance(e.l_scEta, e.s_scEta) ) continue;
                if ( check_bit(bits, sel++) ) s["acc"] += w;

                // hand-made preselection
                if (!( e.l_r9 > 0.8 && e.s_r9 > 0.8 )) continue;
                if ( check_bit(bits, sel++) ) s["r9"] += w;

                if (!( isoCh(e.l_egChIso, e.l_scEta) < 20. && isoCh(e.s_egChIso, e.s_scEta) < 20. )) continue;
                if ( check_bit(bits, sel++) ) s["iso"] += w;

                if (!( isoCh(e.l_egChIso, e.l_scEta) / e.l_pt < 0.3 && isoCh(e.s_egChIso, e.s_scEta) / e.s_pt< 0.3)) continue;
                if ( check_bit(bits, sel++) ) s["iso_rel"] += w;

                if (!(e.l_hadTowOverEm < 0.8 && e.s_hadTowOverEm < 0.8)) continue;
                if ( check_bit(bits, sel++) ) s["hoe"] += w;

                if (!( e.l_IdMva > -0.9 && e.s_IdMva > -0.9 )) continue;
                if ( check_bit(bits, sel++) ) s["phoID_MVA"] += w;
                */

                //if (!photonID_cutBased()) continue;
                //if ( check_bit(bits, sel++) ) s["phoID_CutBasedLoose"] += w;

                if(!flashgg_preselection()) continue;
                if ( check_bit(bits, sel++) ) s["flashgg_presel"] += w;

                if (!( (!dy && e.l_passElVeto && e.s_passElVeto) || (dy && !e.l_passElVeto && !e.s_passElVeto) )) continue;
                // for Z control plots remove it for data and MC
                //if (!( not e.l_passElVeto && not e.s_passElVeto )) continue;
                if ( check_bit(bits, sel++) ) s["csev"] += w;

                // already in flashgg_preselection()
                //if (!( e.l_pt > 30 && e.s_pt > 20 )) continue;
                //if ( check_bit(bits, sel++) ) s["kin_30_20"] += w;

                if (!( e.l_ptOMgg >= 1. / 3. && e.s_ptOMgg >= 0.25)) continue;
                if ( check_bit(bits, sel++) ) s["kin_scaling"] += w;
                //printf("%d %d %d\n", e.run, e.lumi, e.event);

                //if ( ! vtx_sel() ) continue;
                //if ( check_bit(bits, sel++) ) s["vtx"] += w;

                //if (!(e.diphMVA <= -0.29)) continue;
                //if ( check_bit(bits, sel++) ) s["diphoton_MVA"] += w;

                //if (!( e.CMS_hgg_mass > 100 && e.CMS_hgg_mass < 180 )) continue;
                //if ( check_bit(bits, sel++) ) s["mass_window"] += w;
                if (!( e.CMS_hgg_mass > 70 && e.CMS_hgg_mass < 110 )) continue;
                if ( check_bit(bits, sel++) ) s["mass_window"] += w;

                //std::cout<<"run: "<<e.run<<" event: "<<e.event<<" mass: "<<e.CMS_hgg_mass<<std::endl;
                //std::cout<<"--> run: "<<e.run<<" event: "<<e.event<<" mass: "<<e.CMS_hgg_mass<<std::endl;

                h_nvtx_final->Fill(e.nvtx, w);
                h_l_r9_final->Fill(e.l_r9, w);
                h_s_r9_final->Fill(e.s_r9, w);
                if (isEB(e.l_scEta)) h_eb_r9_final->Fill(e.l_r9, w);
                else                 h_ee_r9_final->Fill(e.l_r9, w);
                if (isEB(e.s_scEta)) h_eb_r9_final->Fill(e.s_r9, w);
                else                 h_ee_r9_final->Fill(e.s_r9, w);

                if (isEBEB(e.l_scEta, e.s_scEta)) {
                        h_mass_ebeb_final->Fill(e.CMS_hgg_mass, w);
                        if (e.l_r9 >  0.94 && e.s_r9 >  0.94) h_mass_ebeb_hr9_final->Fill(e.CMS_hgg_mass, w);
                        else                                  h_mass_ebeb_nothr9_final->Fill(e.CMS_hgg_mass, w);
                        if (e.l_r9 <= 0.94 && e.s_r9 <= 0.94) h_mass_ebeb_lr9_final->Fill(e.CMS_hgg_mass, w);
                } else if (isEEEE(e.l_scEta, e.s_scEta)) {
                        h_mass_eeee_final->Fill(e.CMS_hgg_mass, w);
                        if (e.l_r9 >  0.94 && e.s_r9 >  0.94) h_mass_eeee_hr9_final->Fill(e.CMS_hgg_mass, w);
                        if (e.l_r9 <= 0.94 && e.s_r9 <= 0.94) h_mass_eeee_lr9_final->Fill(e.CMS_hgg_mass, w);
                } else {
                        h_mass_ebee_final->Fill(e.CMS_hgg_mass, w);
                        if (e.l_r9 >  0.94 && e.s_r9 >  0.94) h_mass_ebee_hr9_final->Fill(e.CMS_hgg_mass, w);
                        if (e.l_r9 <= 0.94 && e.s_r9 <= 0.94) h_mass_ebee_lr9_final->Fill(e.CMS_hgg_mass, w);
                }
                if (!isEBEB(e.l_scEta, e.s_scEta)) {
                        if (e.l_r9 >  0.94 && e.s_r9 >  0.94) h_mass_notebeb_hr9_final->Fill(e.CMS_hgg_mass, w);
                        else                                  h_mass_notebeb_nothr9_final->Fill(e.CMS_hgg_mass, w);
                }
                if (e.CMS_hgg_mass < 115 || e.CMS_hgg_mass > 135 || !data) h_mass_final->Fill(e.CMS_hgg_mass, w);

                /* // turnon simulation
                h_mass_final->Fill(e.CMS_hgg_mass, w);
                if (isEEEE(e.l_scEta, e.s_scEta)) h_mass_final_eeee->Fill(e.CMS_hgg_mass, w);
                if (isEBEB(e.l_scEta, e.s_scEta)) h_mass_final_ebeb->Fill(e.CMS_hgg_mass, w);
                if (turnon(e.l_pt, e.s_pt, r)) h_mass_final_turnon->Fill(e.CMS_hgg_mass, w);
                if (turnon(e.l_pt, e.s_pt, r)      && e.CMS_hgg_mass * r.Gaus(1, 0.04) > 95 * 1.05 && isEEEE(e.l_scEta, e.s_scEta)) h_mass_final_turnon_eeee->Fill(e.CMS_hgg_mass, w);
                else if (turnon(e.l_pt, e.s_pt, r) && e.CMS_hgg_mass * r.Gaus(1, 0.025) > 95 * 1.02 && isEBEB(e.l_scEta, e.s_scEta)) h_mass_final_turnon_ebeb->Fill(e.CMS_hgg_mass, w);
                */


                //if (!( e.l_phoID > -0.9 && e.s_phoID > -0.9 )) continue;
                //s["phoID_MVA"] += w;
                //h_nvtx_sel_MVA->Fill(e.nvtx, w);
                //one_pass = true;

                // careful: never comment out if only one photon
                // candidate per event has to be selected
                tot += w;
                one_pass = true;
        }
        TObjString os(summary(s).c_str());
        os.Write("event_count_" + name);
        _h_hlt_leading_pt->Write();
        _h_hlt_subleading_pt->Write();
        _h_l1_leading_pt->Write();
        _h_l1_subleading_pt->Write();
        fhisto->Write();
        fprintf(stderr, "\n");
        return tot;
}


int main()
{
        std::vector<std::pair<std::unique_ptr<TChain>, std::string> > trees;

        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/data_13TeV_all"))                               , "../../../prod/data_run-dep-scales_and_smearings/output_*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/data_13TeV_all"))                               , "../../../prod/data_test/output_*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GluGluHToGG_M_125_13TeV_amcatnlo_13TeV_all"))     , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/VBFHToGG_M_125_13TeV_amcatnlo_13TeV_all"))        , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_VBFHToGG_M125_13TeV_amcatnlo_pythia8*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/VHToGG_M125_13TeV_amcatnloFXFX_13TeV_all"))     , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_VHToGG_M125_13TeV_amcatnloFXFX*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/ttHJetToGG_M125_13TeV_amcatnloFXFX_13TeV_all")) , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_ttHJetToGG_M125_13TeV_amcatnloFXFX*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/DYJetsToLL_13TeV_all"))                         , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_DYJetsToLL*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/DiPhotonJetsBox_MGG_80toInf_amcatnlo_13TeV_all"))        , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_DiPhotonJets_MGG-80toInf_13TeV_amcatnloFXFX_pythia8*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GJet_Pt_20to40_MGG_80toInf_13TeV_all"))                     , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_GJet_Pt-20to40*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GJet_Pt_40toInf_MGG_80toInf_13TeV_all"))                    , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_GJet_Pt-40toInf*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GJet_Pt-20toInf_MGG-40to80_13TeV_all"))                    , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_GJet_Pt-20toInf*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/QCD_Pt_30to40_MGG_80toInf_13TeV_all"))          , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_QCD_Pt-30to40*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/QCD_Pt_30toInf_MGG_40to80_13TeV_all"))          , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_QCD_Pt-30toInf*.root" ) );
        trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/QCD_Pt_40toInf_MGG_80toInf_13TeV_all"))         , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_QCD_Pt-40toInf*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/GluGluHToGG_M_125_13TeV_powheg_13TeV_all"))     , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_GluGluHToGG_M-125_13TeV_powheg*.root" ) );
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/VBFHToGG_M_125_13TeV_powheg_13TeV_all"))        , "../../../prod/mc_SandB_run-dep-scales_and_smearings/output_VBFHToGG_M-125_13TeV_powheg*.root" ) );

        // Vittorio
        //trees.push_back( std::make_pair( std::unique_ptr<TChain>(new TChain("diphotonDumper/trees/_13TeV_all"))                               , "output_numEvent20000.root" ) );

        _build_turnon_histograms();

        std::map<std::string, Double_t> nevents;
        for (auto & t : trees) {
                SelectionCounter c;
                printf("--------- %s ---------\n", t.first->GetName());
                t.first->Add(t.second.c_str());
                set_adresses(*t.first);
                set_statuses(*t.first);
                Double_t tot = process_events(*t.first, c);
                nevents[TString(t.first->GetName()).Contains("data") ? "data" : "simulation"] += tot;
                nevents[t.first->GetName()] = tot;
        }
        for (auto & ne : nevents) {
                printf("%20s = % 12.2f\n", ne.first.c_str(), ne.second);
        }

        return 0;
}
