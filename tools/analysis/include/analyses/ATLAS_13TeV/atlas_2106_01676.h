#include "RestFrames/RestFrames.hh"
#ifndef ATLAS_2106_01676_H_
#define ATLAS_2106_01676_H_
// AUTHOR: Junjie Cao, Liangliang Shang, Yuanfang Yue, Di Zhang, Pengxuan Zhu
//  EMAIL: junjiec@itp.ac.cn, shlwell1988@gmail.com, yuanfang405@gmail.com, dz481655@gmail.com, zhupengxuan326@hotmail.com
#include "AnalysisBase.h"
using namespace RestFrames;

class Atlas_2106_01676 : public AnalysisBase {
  public:
    Atlas_2106_01676() : AnalysisBase()  {}               
    ~Atlas_2106_01676() {}
  
    void initialize();
    void analyze();        
    void finalize();

  private:
    
    unique_ptr<RestFrames::LabRecoFrame> LAB_3L;
    unique_ptr<RestFrames::LabRecoFrame> LAB_comb;
    unique_ptr<RestFrames::LabRecoFrame> LAB_2L1L;
    unique_ptr<RestFrames::DecayRecoFrame> C1N2_3L;
    unique_ptr<RestFrames::DecayRecoFrame> C1a_3L;
    unique_ptr<RestFrames::DecayRecoFrame> N2b_3L;
    unique_ptr<RestFrames::DecayRecoFrame> CM_comb;
    unique_ptr<RestFrames::DecayRecoFrame> S_comb;
    unique_ptr<RestFrames::DecayRecoFrame> CM_2L1L;
    unique_ptr<RestFrames::DecayRecoFrame> S_2L1L;
    unique_ptr<RestFrames::DecayRecoFrame> Ca_2L1L;
    unique_ptr<RestFrames::DecayRecoFrame> Z_2L1L;
    unique_ptr<RestFrames::DecayRecoFrame> Cb_2L1L;
    unique_ptr<RestFrames::VisibleRecoFrame> L1a_3L;
    unique_ptr<RestFrames::VisibleRecoFrame> L1b_3L;
    unique_ptr<RestFrames::VisibleRecoFrame> L2b_3L;
    unique_ptr<RestFrames::VisibleRecoFrame> ISR_comb;
    unique_ptr<RestFrames::VisibleRecoFrame> J_comb;
    unique_ptr<RestFrames::VisibleRecoFrame> L_comb;
    unique_ptr<RestFrames::VisibleRecoFrame> ISR_2L1L;
    unique_ptr<RestFrames::VisibleRecoFrame> L1_2L1L;
    unique_ptr<RestFrames::VisibleRecoFrame> L2_2L1L;
    unique_ptr<RestFrames::VisibleRecoFrame> Lb_2L1L;
    unique_ptr<RestFrames::InvisibleRecoFrame> X1a_3L;
    unique_ptr<RestFrames::InvisibleRecoFrame> X1b_3L;
    unique_ptr<RestFrames::InvisibleRecoFrame> I_comb;
    unique_ptr<RestFrames::InvisibleRecoFrame> Ia_2L1L;
    unique_ptr<RestFrames::InvisibleRecoFrame> Ib_2L1L;
    
    //Jigsaw rules:
    unique_ptr<RestFrames::InvisibleGroup> INV_3L;
    unique_ptr<RestFrames::InvisibleGroup> INV_comb;
    unique_ptr<RestFrames::InvisibleGroup> INV_2L1L;
    unique_ptr<RestFrames::SetMassInvJigsaw> X1_mass_3L;
    unique_ptr<RestFrames::SetRapidityInvJigsaw> X1_eta_3L;
    unique_ptr<RestFrames::ContraBoostInvJigsaw> X1X1_contra_3L;
    unique_ptr<RestFrames::SetMassInvJigsaw> InvMass_comb;
    unique_ptr<RestFrames::SetMassInvJigsaw> InvMass_2L1L;
    unique_ptr<RestFrames::SetRapidityInvJigsaw> InvRapidity_2L1L;
    unique_ptr<RestFrames::ContraBoostInvJigsaw> SplitINV_2L1L;
    unique_ptr<RestFrames::CombinatoricGroup> JETS_comb;
    unique_ptr<RestFrames::MinMassesCombJigsaw> SplitJETS_comb;

    bool check_nTrack_jet(Jet* jet, std::vector<Track*> tracks, int nTracksMin);
    std::vector<Jet*> overlapRemoval_jet_tracks_muon(std::vector<Jet*> cand_jets, std::vector<Muon*> cand_muons, double deltaR, int nTracks);
};

#endif
