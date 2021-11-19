#include "atlas_2106_01676.h"
// AUTHOR: Junjie Cao, Liangliang Shang, Yuanfang Yue, Di Zhang, Pengxuan Zhu
//  EMAIL: junjiec@itp.ac.cn, shlwell1988@gmail.com, yuanfang405@gmail.com, dz481655@gmail.com, zhupengxuan326@hotmail.com
void Atlas_2106_01676::initialize()
{
  setAnalysisName("atlas_2106_01676");
  setInformation(""
                 "# ATLAS\n"
                 "# Atlas_2106_01676\n"
                 "# 3 leptons + missingET, on-shell and off-shell, atlas_conf_2020_015\n"
                 "# sqrt(s) = 13 TeV\n"
                 "# Luminosity = 139 fb^-1\n"
                 "");
  setLuminosity(139.0 * units::INVFB);
  bookSignalRegions("SR3l_Low;SR3l_ISR;SR_WZ_01;SR_WZ_02;SR_WZ_03;SR_WZ_04;SR_WZ_05;SR_WZ_06;SR_WZ_07;SR_WZ_08;SR_WZ_09;SR_WZ_10;SR_WZ_11;SR_WZ_12;SR_WZ_13;SR_WZ_14;SR_WZ_15;SR_WZ_16;SR_WZ_17;SR_WZ_18;SR_WZ_19;SR_WZ_20;SR_Wh_SFOS_01;SR_Wh_SFOS_02;SR_Wh_SFOS_03;SR_Wh_SFOS_04;SR_Wh_SFOS_05;SR_Wh_SFOS_06;SR_Wh_SFOS_07;SR_Wh_SFOS_08;SR_Wh_SFOS_09;SR_Wh_SFOS_10;SR_Wh_SFOS_11;SR_Wh_SFOS_12;SR_Wh_SFOS_13;SR_Wh_SFOS_14;SR_Wh_SFOS_15;SR_Wh_SFOS_16;SR_Wh_SFOS_17;SR_Wh_SFOS_18;SR_Wh_SFOS_19;SR_Wh_DFOS_01;SR_Wh_DFOS_02;SR_WZoff_low_0jb;SR_WZoff_low_0jc;SR_WZoff_low_0jd;SR_WZoff_low_0je;SR_WZoff_low_0jf1;SR_WZoff_low_0jf2;SR_WZoff_low_0jg1;SR_WZoff_low_0jg2;SR_WZoff_low_njb;SR_WZoff_low_njc;SR_WZoff_low_njd;SR_WZoff_low_nje;SR_WZoff_low_njf1;SR_WZoff_low_njf2;SR_WZoff_low_njg1;SR_WZoff_low_njg2;SR_WZoff_high_0jb;SR_WZoff_high_0jc;SR_WZoff_high_0jd;SR_WZoff_high_0je;SR_WZoff_high_0jf1;SR_WZoff_high_0jf2;SR_WZoff_high_0jg1;SR_WZoff_high_0jg2;SR_WZoff_high_nja;SR_WZoff_high_njb;SR_WZoff_high_njc;SR_WZoff_high_njd;SR_WZoff_high_nje;SR_WZoff_high_njf;SR_WZoff_high_njg;SR_incWZ_01;SR_incWZ_02;SR_incWZ_03;SR_incWZ_04;SR_incWZ_05;SR_incWZ_06;SR_incWh_SFOS_07;SR_incWh_SFOS_08;SR_incWh_SFOS_09;SR_incWh_SFOS_10;SR_incWh_SFOS_11;SR_incWh_DFOS_12;SR_incWZoff_high_nja;SR_incWZoff_high_njb;SR_incWZoff_high_njc1;SR_incWZoff_high_njc2;SR_incWZoff_low_b;SR_incWZoff_high_b;SR_incWZoff_low_c;SR_incWZoff_high_c;SR_incWZoff_d;SR_incWZoff_e1;SR_incWZoff_e2;SR_incWZoff_f1;SR_incWZoff_f2;SR_incWZoff_g1;SR_incWZoff_g2;SR_incWZoff_g3;SR_incWZoff_g4");
  // You can also book cutflow regions with bookCutflowRegions("CR1;CR2;..."). Note that the regions are
  //  always ordered alphabetically in the cutflow output files.

  // You should initialize any declared variables here
  RestFrames::RFKey ensure_autoload(1);
  LAB_3L.reset(new RestFrames::LabRecoFrame("LAB_3L", "LAB_3L"));
  C1N2_3L.reset(new RestFrames::DecayRecoFrame("C1N2_3L", "C1N2_3L"));
  C1a_3L.reset(new RestFrames::DecayRecoFrame("C1a_3L", "C1a_3L"));
  N2b_3L.reset(new RestFrames::DecayRecoFrame("N2b_3L", "N2b_3L"));

  L1a_3L.reset(new RestFrames::VisibleRecoFrame("L1a_3L", "L1a_3L"));
  L1b_3L.reset(new RestFrames::VisibleRecoFrame("L1b_3L", "L1b_3L"));
  L2b_3L.reset(new RestFrames::VisibleRecoFrame("L2b_3L", "L2b_3L"));

  X1a_3L.reset(new RestFrames::InvisibleRecoFrame("X1a_3L", "X1a_3L"));
  X1b_3L.reset(new RestFrames::InvisibleRecoFrame("X1b_3L", "X1b_3L"));

  LAB_3L->SetChildFrame(*C1N2_3L);

  C1N2_3L->AddChildFrame(*C1a_3L);
  C1N2_3L->AddChildFrame(*N2b_3L);

  C1a_3L->AddChildFrame(*L1a_3L);
  C1a_3L->AddChildFrame(*X1a_3L);

  N2b_3L->AddChildFrame(*L1b_3L);
  N2b_3L->AddChildFrame(*L2b_3L);
  N2b_3L->AddChildFrame(*X1b_3L);

  if (LAB_3L->InitializeTree())
  {
    g_Log << LogInfo << "... Successfully initialized reconstruction trees: LAB_3L"
          << LogEnd;
  }
  else
  {
    g_Log << LogError << "... Failed initlializing reconstruction trees: LAB_3L"
          << LogEnd;
  }

  //setting the invisible components
  INV_3L.reset(new RestFrames::InvisibleGroup("INV_3L", "Invisible sys LSP mass Jigsaw"));
  INV_3L->AddFrame(*X1a_3L);
  INV_3L->AddFrame(*X1b_3L);

  // Set di-LSP mass to minimum Lorentz-invariant expression
  X1_mass_3L.reset(new RestFrames::SetMassInvJigsaw("X1_mass_3L", "X1_mass_3L"));
  INV_3L->AddJigsaw(*X1_mass_3L);

  // Set di-LSP rapidity to that of visible particles and neutrino
  X1_eta_3L.reset(new RestFrames::SetRapidityInvJigsaw("X1_eta_3L", "X1_eta_3L"));
  INV_3L->AddJigsaw(*X1_eta_3L);
  X1_eta_3L->AddVisibleFrames(C1N2_3L->GetListVisibleFrames());

  X1X1_contra_3L.reset(new RestFrames::ContraBoostInvJigsaw("X1X1_contra_3L", "X1X1_contra_3L"));
  INV_3L->AddJigsaw(*X1X1_contra_3L);
  X1X1_contra_3L->AddVisibleFrames(C1a_3L->GetListVisibleFrames(),0);
  X1X1_contra_3L->AddVisibleFrames(N2b_3L->GetListVisibleFrames(),1);
  X1X1_contra_3L->AddInvisibleFrames(C1a_3L->GetListInvisibleFrames(),0);
  X1X1_contra_3L->AddInvisibleFrames(N2b_3L->GetListInvisibleFrames(),1);

  if (LAB_3L->InitializeAnalysis())
  {
    g_Log << LogInfo
          << "...Successfully initialized analysis in Decay Tree: LAB_3L"
          << std::endl
          << LogEnd;
  }
  else
  {
    g_Log << LogError << "...Failed initializing analysis in Decay Tree: LAB_3L"
          << LogEnd;
  }

  // Compressed tree time
  // combinatoric (transverse) tree
  // for jet assignment
  LAB_comb.reset(new RestFrames::LabRecoFrame("LAB_comb", "Lab_comb"));
  CM_comb.reset(new RestFrames::DecayRecoFrame("CM_comb", "CM_comb"));
  S_comb.reset(new RestFrames::DecayRecoFrame("S_comb", "S_comb"));
  ISR_comb.reset(new RestFrames::VisibleRecoFrame("ISR_comb", "ISR_comb"));
  J_comb.reset(new RestFrames::VisibleRecoFrame("J_comb", "J_comb"));
  L_comb.reset(new RestFrames::VisibleRecoFrame("L_comb", "L_comb"));
  I_comb.reset(new RestFrames::InvisibleRecoFrame("I_comb", "I_comb"));

  LAB_comb->SetChildFrame(*CM_comb);
  CM_comb->AddChildFrame(*ISR_comb);
  CM_comb->AddChildFrame(*S_comb);
  S_comb->AddChildFrame(*L_comb);
  S_comb->AddChildFrame(*J_comb);
  S_comb->AddChildFrame(*I_comb);
  
  if (LAB_comb->InitializeTree())
  {
    g_Log << LogInfo
          << "... Successfully initialized reconstruction trees: LAB_comb"
          << LogEnd;
  }
  else
  {
    g_Log << LogError
          << "... Failed initlializing reconstruction trees: LAB_comb" << LogEnd;
  }

  // 2L+1L tree (Z->ll + Z/W->l)
  LAB_2L1L.reset(new RestFrames::LabRecoFrame("LAB_2L1L", "Lab_2L1L"));
  CM_2L1L.reset(new RestFrames::DecayRecoFrame("CM_2L1L", "CM_2L1L"));
  S_2L1L.reset(new RestFrames::DecayRecoFrame("S_2L1L", "S_2L1L"));
  ISR_2L1L.reset(new RestFrames::VisibleRecoFrame("ISR_2L1L", "ISR_2L1L"));
  Ca_2L1L.reset(new RestFrames::DecayRecoFrame("Ca_2L1L", "Ca_2L1L"));
  Z_2L1L.reset(new RestFrames::DecayRecoFrame("Z_2L1L", "Z_2L1L"));
  L1_2L1L.reset(new RestFrames::VisibleRecoFrame("L1_2L1L", "L1_2L1L"));
  L2_2L1L.reset(new RestFrames::VisibleRecoFrame("L2_2L1L", "L2_2L1L"));
  Cb_2L1L.reset(new RestFrames::DecayRecoFrame("Cb_2L1L", "Cb_2L1L"));
  Lb_2L1L.reset(new RestFrames::VisibleRecoFrame("Lb_2L1L", "Lb_2L1L"));
  Ia_2L1L.reset(new RestFrames::InvisibleRecoFrame("Ia_2L1L", "Ia_2L1L"));
  Ib_2L1L.reset(new RestFrames::InvisibleRecoFrame("Ib_2L1L", "Ib_2L1L"));

  LAB_2L1L->SetChildFrame(*CM_2L1L);
  CM_2L1L->AddChildFrame(*ISR_2L1L);
  CM_2L1L->AddChildFrame(*S_2L1L);
  S_2L1L->AddChildFrame(*Ca_2L1L);
  S_2L1L->AddChildFrame(*Cb_2L1L);
  Ca_2L1L->AddChildFrame(*Z_2L1L);
  Ca_2L1L->AddChildFrame(*Ia_2L1L);
  Z_2L1L->AddChildFrame(*L1_2L1L);
  Z_2L1L->AddChildFrame(*L2_2L1L);
  Cb_2L1L->AddChildFrame(*Lb_2L1L);
  Cb_2L1L->AddChildFrame(*Ib_2L1L);

  if (LAB_2L1L->InitializeTree())
  {
    g_Log << LogInfo
          << "... Successfully initialized reconstruction trees: LAB_2L1L"
          << LogEnd;
  }
  else
  {
    g_Log << LogError
          << "... Failed initlializing reconstruction trees: LAB_2L1L" << LogEnd;
  }

  ////////////// Jigsaw rules set-up /////////////////

  // combinatoric (transverse) tree
  // for jet assignment
  INV_comb.reset(new RestFrames::InvisibleGroup("INV_comb", "INV_comb"));
  INV_comb->AddFrame(*I_comb);

  InvMass_comb.reset(new RestFrames::SetMassInvJigsaw("InvMass_comb", "InvMass_comb"));
  INV_comb->AddJigsaw(*InvMass_comb);

  JETS_comb.reset(new RestFrames::CombinatoricGroup("JETS_comb", "JETS_comb"));
  JETS_comb->AddFrame(*ISR_comb);
  JETS_comb->SetNElementsForFrame(*ISR_comb, 1,false);
  JETS_comb->AddFrame(*J_comb);
  JETS_comb->SetNElementsForFrame(*J_comb, 0,false);

  SplitJETS_comb.reset(new RestFrames::MinMassesCombJigsaw("SplitJETS_comb", "SplitJETS_comb"));
  JETS_comb->AddJigsaw(*SplitJETS_comb);
  SplitJETS_comb->AddFrame(*ISR_comb, 0);
  SplitJETS_comb->AddFrame(*J_comb, 1);
  SplitJETS_comb->AddObjectFrame(*ISR_comb,0);
  SplitJETS_comb->AddObjectFrame(*S_comb,1);

  if (LAB_comb->InitializeAnalysis())
  {
    g_Log << LogInfo
          << "...Successfully initialized analysis in Decay Tree: LAB_comb"
          << std::endl
          << LogEnd;
  }
  else
  {
    g_Log << LogError
          << "...Failed initializing analysis in Decay Tree: LAB_comb" << LogEnd;
  }

  // 2L+1L tree (Z->ll + Z/W->l)
  INV_2L1L.reset(new RestFrames::InvisibleGroup("INV_2L1L", "INV_2L1L"));
  INV_2L1L->AddFrame(*Ia_2L1L);
  INV_2L1L->AddFrame(*Ib_2L1L);

  InvMass_2L1L.reset(new RestFrames::SetMassInvJigsaw("InvMass_2L1L", "InvMass_2L1L"));
  INV_2L1L->AddJigsaw(*InvMass_2L1L);
  InvRapidity_2L1L.reset(new RestFrames::SetRapidityInvJigsaw("InvRapidity_2L1L", "RapidityJigsaw"));
  INV_2L1L->AddJigsaw(*InvRapidity_2L1L);
  InvRapidity_2L1L->AddVisibleFrames(S_2L1L->GetListVisibleFrames());
  SplitINV_2L1L.reset(new RestFrames::ContraBoostInvJigsaw("SplitINV_2L1L", "SplitINV_2L1L"));
  INV_2L1L->AddJigsaw(*SplitINV_2L1L);
  SplitINV_2L1L->AddVisibleFrames(Ca_2L1L->GetListVisibleFrames(), 0);
  SplitINV_2L1L->AddVisibleFrames(Cb_2L1L->GetListVisibleFrames(), 1);
  SplitINV_2L1L->AddInvisibleFrame(*Ia_2L1L, 0);
  SplitINV_2L1L->AddInvisibleFrame(*Ib_2L1L, 1);

  if (LAB_2L1L->InitializeAnalysis())
  {
    g_Log << LogInfo
          << "...Successfully initialized analysis in Decay Tree: LAB_2L1L"
          << std::endl
          << LogEnd;
  }
  else
  {
    g_Log << LogError
          << "...Failed initializing analysis in Decay Tree: LAB_2L1L" << LogEnd;
  }

}

void Atlas_2106_01676::analyze()
{
  // Your eventwise analysis code goes here
  // The following objects are always defined unless they are 'ignored' above. They form std::vector objects of the respective Delphes class type (except for Etmiss which is a single object)
  // All std::vector members and etmiss have the common properties PT, Eta, Phi and P4() with the latter giving access to the full ROOT TLorentzVector.
  // Within a std::vector, all members are ordered with highest pt coming first.

  // electronsLoose, electronsMedium, electronsTight   are list of electrons that passed respective efficiency and reconstruction cuts
  // muonsCombinedPlus, muonsCombined                  as above for muons
  // photonsMedium                                     as above for photons
  // jets are all reconstructed jets                   as above for jets. Note that electrons are most certainly also reconstructed as a jet -> overlap removal do avoid double counting necessary!
  // tracks, towers                                    calorimeter and tracker information. Usually not needed.
  // missingET                                         rec missing ET EXCLUDING muons.

  // Here is a couple of useful functions and lines:
  //------------Phase Space Cuts (defined for jets, electronsXYZ, muonsXYZ, photonsXYZ)
  // jets = filterPhaseSpace(jets, 20., -2.8, 2.8)  // The vector 'jets' only contains jets with pt >= 20 GeV and -2.8 < eta < 2.8. This function is applicable to other particles too (electronsMedium, ... ).
  // jets = overlapRemoval(jets, electronsLoose, 0.2) Removes all jets for which there exists any electron in 'electronsLoose' with deltaR < 0.2.
  // jets = overlapRemovel(jets, 0.2) If two jets overlap within deltaR < 0.2, only the harder jet is stored.

  //------------Isolation Checks (defined for electronsXYZ, muonsXYZ, photonsXYZ
  //------------        For each object, if the user entered N isolation conditions, they can be
  //------------        checked individually be the second argument (running from 0 to N-1).
  // electronsMedium = filterIsolation(electronsMedium, 0)            Removes electrons that do not pass the first isolation condition entered into the AnalysisManager by the user
  // std::vector<int> flags; flags.push_back(0); flags.push_back(2);
  // electronsMedium = filterIsolation(electronsMedium, flags)        Same as above, but both the first and the third condition have to be fulfilled
  // electronsMedium = filterIsolation(electronsMedium)               Same as above, but all conditions have to be fulfilled.

  //-----------Flavour Tag Checks (defined for jets only)
  //----------          Tau tags "loose", "medium" or "tight" can be individually checked if the user enabled tau tagging in the AM.
  //----------          For b-tags, if N working points have been defined, the ith condition can be tested by putting i-1 into the second argument (if there is only one, the argument can be omitted)
  // if checkTauTag(jets[0], "tight") leadingJetIsTagged = True;
  // if checkBTag(jets[0], 0) leadingJetIsBTagged = True;

  //-----------Auxiliary Information
  // - Always ensure that you don't access vectors out of bounds. E.g. 'if(jets[1]->PT > 150)' should rather be if (jets.size() > 1 && jets[1]->PT > 150).
  // - Use rand()/(RAND_MAX+1.) for random numbers between 0 and 1. The random seed is determined from system time or by the RandomSeed parameter in CheckMATE.
  // - The 'return' statement will end this function for the current event and hence should be called whenever the current event is to be vetoed.
  // - Many advanced kinematical functions like mT2 are implemented. Check the manual for more information.
  // - If you need output to be stored in other files than the cutflow/signal files we provide, check the manual for how to do this conveniently.

  missingET->addMuons(muonsCombined); // Adds muons to missing ET. This should almost always be done which is why this line is not commented out.

  TLorentzVector ptmiss_soft = TLorentzVector(0., 0., 0., 0.);
  TLorentzVector ptmiss = TLorentzVector(0., 0., 0., 0.);
  double sumET = 0.;
  countCutflowEvent("000_all");

  std::vector<Electron *> electrons_base;
  electrons_base = filterPhaseSpace(electronsLoose, 4.5, -2.47, 2.47, false);

  std::vector<Muon *> muons_base;
  muons_base = filter_candidates_in_eta_range(muons, -2.5, 2.5, 0.7);
  muons_base = filter_candidates_in_pT_range(muons_base, 3., 1e6, 1.);

  std::vector<Jet *> jets_base;
  jets_base = filterPhaseSpace(jets, 20., -4.5, 4.5);

  std::vector<Photon *> photons_offshell;
  for (int i = 0; i < photons.size(); i++)
  {
    if (photons[i]->PT > 3. && fabs(photons[i]->Eta) > 1.37 && fabs(photons[i]->Eta) < 1.52)
    {
      photons_offshell.push_back(photons[i]);
      sumET += photons[i]->PT;
      ptmiss -= photons[i]->P4();
    }
  }
  for (int i = 0; i < photonsMedium.size(); i++)
  {
    if (photonsMedium[i]->PT > 3. && fabs(photonsMedium[i]->Eta) < 2.37)
    {
      if (fabs(photonsMedium[i]->Eta) > 1.52 || fabs(photonsMedium[i]->Eta < 1.37))
      {
        photons_offshell.push_back(photonsMedium[i]);
        sumET += photonsMedium[i]->PT;
        ptmiss -= photonsMedium[i]->P4();
      }
    }
  }

  std::vector<FinalStateObject *> leptons_base;
  for (int i = 0; i < electrons_base.size(); i++)
  {
    sumET += electrons_base[i]->PT;
    ptmiss += electrons_base[i]->P4();
    FinalStateObject *lep = newFinalStateObject(electrons_base[i]);
    leptons_base.push_back(lep);
  }
  for (int i = 0; i < muons_base.size(); i++)
  {
    sumET += muons_base[i]->PT;
    ptmiss += muons_base[i]->P4();
    FinalStateObject *lep = newFinalStateObject(muons_base[i]);
    leptons_base.push_back(lep);
  }
  std::sort(leptons_base.begin(), leptons_base.end(), FinalStateObject::sortByPT);

  for (int i = 0; i < jets_base.size(); i++)
  {
    sumET += jets_base[i]->PT;
    ptmiss -= jets_base[i]->P4();
  }

  if (leptons_base.size() != 3) return;

  electrons_base = overlapRemoval(electrons_base, muons_base, 0.01);
  jets_base = overlapRemoval(jets_base, electrons_base, 0.2);
  jets_base = overlapRemoval_jet_tracks_muon(jets_base, muons_base, 0.4, 2);
  electrons_base = overlapRemoval(electrons_base, jets_base, 0.4);
  muons_base = overlapRemoval(muons_base, jets_base, 0.4);

  if (leptons_base.size() != 3) return;
  countCutflowEvent("001_3leptons_base");

  std::vector<Jet *> jets_sig;
  std::vector<Jet *> jets_30sig;
  for (int i = 0; i < jets_base.size(); i++) 
  {
    if (fabs(jets_base[i]->Eta) < 2.8)
    {
      if (jets_base[i]->PT < 120.)
      {
        if (fabs(jets_base[i]->Eta) < 2.5)
        {
          jets_sig.push_back(jets_base[i]);
        }
      }
      else
      {
        jets_sig.push_back(jets_base[i]);
      }
      if (jets_base[i]->PT > 30.) {
        jets_30sig.push_back(jets_base[i]);
      }
    }
  }

  std::vector<Jet *> bjets;
  for (int i = 0; i < jets_sig.size(); i++)
  {
    if (fabs(jets_sig[i]->Eta) < 2.5 && checkBTag(jets_sig[i]))
    {
      bjets.push_back(jets_sig[i]);
    }
  }

  std::vector<Track *> tracks;
  bool used = false;
  for (std::vector<Track *>::iterator it = tracks.begin(); it != tracks.end(); it++)
  {
    for (int ii = 0; ii < jets_base.size() && !used; ii++)
    {
      for (int p = 0; p < (jets_base[ii]->Particles.GetEntries()); p++)
      {
        if ((*it)->PT > 0.5 && (jets_base[ii]->Particles.At(p) == (*it)->Particle))
        {
          used = true;
          break;
        }
      }
    }
    if (!used)
    {
      sumET += (*it)->PT;
      ptmiss_soft -= (*it)->P4();
    }
  }
  ptmiss = ptmiss + ptmiss_soft;

  double met = ptmiss.Perp();
  double metsig = met / sqrt(sumET);

  std::vector<Electron *> electrons_onshell;
  std::vector<Muon *> muons_onshell;
  std::vector<Electron *> electrons_offshell;
  std::vector<Muon *> muons_offshell;
  std::vector<Electron *> electrons_RJR;
  std::vector<Muon *> muons_RJR;
  std::vector<Jet *> jets_RJR;
  std::vector<Jet *> bjets_RJR;

  checkSubset(electrons_base, electronsMedium);
  electrons_onshell = filterPhaseSpace(electrons_base, 10., -2.47, 2.47, false);
  muons_onshell = filterPhaseSpace(muons_base, 10., -2.5, 2.5, false);
  electrons_offshell = filterPhaseSpace(electrons_base, 4.5, -2.47, 2.47, false);
  muons_offshell = filterPhaseSpace(muons_base, 3.0, -2.5, 2.5, false);
  electrons_RJR = filterPhaseSpace(electrons_base, 10, 2.47, false);
  muons_RJR = filterPhaseSpace(muons_base, 10, 2.4, false);
  jets_RJR = filterPhaseSpace(jets_base, 20, 2.4);
  bjets_RJR = filterPhaseSpace(bjets, 20, 2.4);

  std::vector<FinalStateObject *> leptons_RJR;
  for (int i = 0; i < electrons_RJR.size(); i++)
  {
    FinalStateObject *lep = newFinalStateObject(electrons_RJR[i]);
    leptons_RJR.push_back(lep);
  }
  for (int i = 0; i < muons_RJR.size(); i++)
  {
    FinalStateObject *lep = newFinalStateObject(muons_RJR[i]);
    leptons_RJR.push_back(lep);
  }
  std::sort(leptons_RJR.begin(), leptons_RJR.end(), FinalStateObject::sortByPT);

  std::vector<FinalStateObject *> leptons_onshell;
  for (int i = 0; i < electrons_onshell.size(); i++)
  {
    FinalStateObject *lep = newFinalStateObject(electrons_onshell[i]);
    leptons_onshell.push_back(lep);
  }
  for (int i = 0; i < muons_onshell.size(); i++)
  {
    FinalStateObject *lep = newFinalStateObject(muons_onshell[i]);
    leptons_onshell.push_back(lep);
  }
  std::sort(leptons_onshell.begin(), leptons_onshell.end(), FinalStateObject::sortByPT);

  std::vector<FinalStateObject *> leptons_offshell;
  for (int i = 0; i < electrons_offshell.size(); i++)
  {
    FinalStateObject *lep = newFinalStateObject(electrons_offshell[i]);
    leptons_offshell.push_back(lep);
  }
  for (int i = 0; i < muons_offshell.size(); i++)
  {
    FinalStateObject *lep = newFinalStateObject(muons_offshell[i]);
    leptons_offshell.push_back(lep);
  }
  std::sort(leptons_offshell.begin(), leptons_offshell.end(), FinalStateObject::sortByPT);

  int num_fnp(0),num_fnp_electron(0),num_fnp_muon(0),num_fnp_track(0);
  
  for (int i = 0; i < jets_sig.size(); i++)
  {
    for (typename std::vector<Electron *>::iterator it = electrons_offshell.begin(); it != electrons_offshell.end(); it++)
    {
      for (int part = 0; part < jets_sig[i]->Particles.GetEntries(); part++)
      {
        if (jets_sig[i]->Particles.At(part) == (*it)->Particle)
        {
          num_fnp_electron++;
        }
      }
      if (num_fnp_electron > 0)
        break;
    }
    for (typename std::vector<Muon *>::iterator it = muons_offshell.begin(); it != muons_offshell.end(); it++)
    {
      for (int part = 0; part < jets_sig[i]->Particles.GetEntries(); part++)
      {
        if (jets_sig[i]->Particles.At(part) == (*it)->Particle)
        {
          num_fnp_muon++;
        }
      }
      if (num_fnp_muon > 0)
        break;
    }
  }
  for (std::vector<Track *>::iterator it = tracks.begin(); it != tracks.end(); it++)
  {
    for (int i = 0; i < electrons.size(); i++)
    {
      if ((*it)->Particle == electrons[i]->Particle)
      {
        num_fnp_track++;
        break;
      }
    }
    for (int j = 0; j < electrons.size(); j++)
    {
      if ((*it)->Particle == electrons[j]->Particle)
      {
        num_fnp_track++;
        break;
      }
    }
  }

  num_fnp = num_fnp_electron + num_fnp_muon + num_fnp_track;

  bool single_trigger(false),dilep_trigger_onshell(false),dilep_trigger_offshell(false),trilep_trigger(false);
  
  // single muon trigger
  if (muons_offshell.size() > 0 && muons_offshell[0]->PT > 27.3)
  {
    single_trigger = true;
  }
  // dielectron trigger of off-shell
  if (electrons_offshell.size() > 1 && electrons_offshell[0]->PT > 18. && electrons_offshell[1]->PT > 18.)
  {
    dilep_trigger_offshell = true;
  }
  else if (muons_offshell.size() > 1 && muons_offshell[0]->PT > 14.7 && muons_offshell[1]->PT > 14.7)
  {
    dilep_trigger_offshell = true;
  }
  else if (electrons_offshell.size() > 0 && muons_offshell.size() > 0 && electrons_offshell[0]->PT > 18. && muons_offshell[0]->PT > 14.7)
  {
    dilep_trigger_offshell = true;
  }
  // trilepton trigger
  else if (electrons_offshell.size() > 0 && muons_offshell.size() > 1 && electrons_offshell[0]->PT > 18. && muons_offshell[0]->PT > 6.5 && muons_offshell[1]->PT > 6.5)
  {
    trilep_trigger = true;
  }
  else if (electrons_offshell.size() > 1 && muons_offshell.size() > 0 && electrons_offshell[0]->PT > 18. && electrons_offshell[1]->PT > 18. && muons_offshell[0]->PT > 14.7)
  {
    trilep_trigger = true;
  }

  // dilepton trigger of on-shell
  if (electrons_onshell.size() > 1 && electrons_onshell[0]->PT > 18. && electrons_onshell[1]->PT > 18.)
  {
    dilep_trigger_onshell = true;
  }
  else if (muons_onshell.size() > 1 && muons_onshell[0]->PT > 14.7 && muons_onshell[1]->PT > 14.7)
  {
    dilep_trigger_onshell = true;
  }
  else if (electrons_onshell.size() > 0 && muons_onshell.size() > 0 && electrons_onshell[0]->PT > 18. && muons_onshell[0]->PT > 14.7)
  {
    dilep_trigger_onshell = true;
  }

  bool met_trigger = false;
  if (met > 30.)
  {
    met_trigger = true;
  }

  double HT = 0.;
  for (int i = 0; i < jets_sig.size(); i++)
  {
    HT += jets_sig[i]->PT;
  }

  bool offshell = false;
  if (leptons_offshell.size() == 3)
  {
    offshell = true;
  }

  //jigsaw
  bool RJR = false;
  if (leptons_RJR.size() == 3 && bjets_RJR.size() == 0 && (leptons_RJR[0]->PT > 25. && leptons_RJR[1]->PT > 25. && leptons_RJR[2]->PT > 20.)) {
    RJR = true;
  }

  if (RJR) {
    bool iscomp = false;
    if (jets_RJR.size() > 0 && bjets_RJR.size() == 0) {
        iscomp = true;
    }

    LAB_3L->ClearEvent();
    // SFOS criteria
    double diff = 10000000000.0;
    int Zlep1 = -99;
    int Zlep2 = -99;
    double Zmass = -999.0;
    bool foundSFOS = false;

    for (unsigned int i = 0; i < leptons_RJR.size(); i++)
    {
      for (unsigned int j = i + 1; j < leptons_RJR.size(); j++)
      {
        if (leptons_RJR[i]->Type == leptons_RJR[j]->Type && (leptons_RJR[i]->Charge * leptons_RJR[j]->Charge) < 0)
        {
          double mass = (leptons_RJR[i]->P4() + leptons_RJR[j]->P4()).M();
          double massdiff = fabs(mass - 91.1876);
          if (massdiff < diff)
          {
            diff = massdiff;
            Zmass = mass;
            Zlep1 = i;
            Zlep2 = j;
            foundSFOS = true;
          }
        }
      }
    }

    if (!foundSFOS)
    {
      return;
    }
    int Wlep1 = -999;
    if ((Zlep1 == 0 && Zlep2 == 1) || (Zlep1 == 1 && Zlep2 == 0))
        Wlep1 = 2;
    else if ((Zlep1 == 0 && Zlep2 == 2) || (Zlep1 == 2 && Zlep2 == 0))
        Wlep1 = 1;
    else if ((Zlep1 == 1 && Zlep2 == 2) || (Zlep1 == 2 && Zlep2 == 1))
        Wlep1 = 0;

    double mll = Zmass;
    double wlepMetphi = leptons_RJR[Wlep1]->P4().DeltaPhi(ptmiss);
    double mTW = sqrt(2 * leptons_RJR[Wlep1]->P4().Pt() * ptmiss.Pt() * (1 - TMath::Cos(wlepMetphi)));

    // Send the leptons to their place
    L1a_3L->SetLabFrameFourVector(leptons_RJR[Wlep1]->P4());
    L1b_3L->SetLabFrameFourVector(leptons_RJR[Zlep1]->P4());
    L2b_3L->SetLabFrameFourVector(leptons_RJR[Zlep2]->P4());

    // met
    INV_3L->SetLabFrameThreeVector(ptmiss.Vect());

    LAB_3L->AnalyzeEvent();

    TLorentzVector vP_V1aPP = L1a_3L->GetFourVector(C1N2_3L->GetFourVector());
    TLorentzVector vP_V1bPP = L1b_3L->GetFourVector(C1N2_3L->GetFourVector());
    TLorentzVector vP_V2bPP = L2b_3L->GetFourVector(C1N2_3L->GetFourVector());
    TLorentzVector vP_I1aPP = X1a_3L->GetFourVector(C1N2_3L->GetFourVector());
    TLorentzVector vP_I1bPP = X1b_3L->GetFourVector(C1N2_3L->GetFourVector());

    double H4PP = vP_V1aPP.P() + vP_V1bPP.P() + vP_V2bPP.P() + (vP_I1aPP + vP_I1bPP).P();      //H(3,1)PP
    double HT4PP = vP_V1aPP.Pt() + vP_V1bPP.Pt() + vP_V2bPP.Pt() + (vP_I1aPP + vP_I1bPP).Pt(); //HT(3,1)PP

    double R_HT4PP_H4PP = HT4PP / H4PP;

    TVector3 vP_PP = C1N2_3L->GetFourVector(LAB_3L->GetFourVector()).Vect();
    double Pt_PP = vP_PP.Pt();
    double RPT_HT4PP = Pt_PP / (Pt_PP + HT4PP);

    // P frame
    TLorentzVector vP_V1aPa = L1a_3L->GetFourVector(C1a_3L->GetFourVector());
    TLorentzVector vP_I1aPa = X1a_3L->GetFourVector(C1a_3L->GetFourVector());

    TLorentzVector vP_V1bPb = L1b_3L->GetFourVector(N2b_3L->GetFourVector());
    TLorentzVector vP_V2bPb = L2b_3L->GetFourVector(N2b_3L->GetFourVector());
    TLorentzVector vP_I1bPb = X1b_3L->GetFourVector(N2b_3L->GetFourVector());

    double H2Pa = (vP_V1aPa).P() + (vP_I1aPa).P();          //H(1,1)P
    double H2Pb = (vP_V1bPb + vP_V2bPb).P() + vP_I1bPb.P(); //H(1,1)P

    double H3Pa = vP_V1aPa.P() + vP_I1aPa.P();                //H(1,1)P
    double H3Pb = vP_V1bPb.P() + vP_V2bPb.P() + vP_I1bPb.P(); //H(2,1)P

    double minH2P = std::min(H2Pa, H2Pb);
    double minH3P = std::min(H3Pa, H3Pb);
    double R_H2Pa_H2Pb = H2Pa / H2Pb;
    double R_H3Pa_H3Pb = H3Pa / H3Pb;
    double R_minH2P_minH3P = H2Pb / H3Pb;

    // Low mass
    if (jets_RJR.size() == 0 && leptons_RJR[0]->PT > 60. && leptons_RJR[1]->PT > 40. && leptons_RJR[2]->PT > 30. && mll > 75. && mll < 105. && mTW > 100. && H4PP > 250. && RPT_HT4PP < 0.05 && R_HT4PP_H4PP > 0.9) {
      countSignalEvent("SR3l_Low");
    }

    // Compressed time
    if (iscomp)
    {
      // Combinatoric setup for jets
      LAB_comb->ClearEvent();
      // do mass minimisation for jets
      std::vector<RFKey> jetID;
      for (int i = 0; i < int(jets_RJR.size()); i++)
      {
        TLorentzVector jet = jets_RJR[i]->P4();
        jet.SetPtEtaPhiM(jet.Pt(), 0.0, jet.Phi(), jet.M());
        jetID.push_back(JETS_comb->AddLabFrameFourVector(jet));
      }

      TLorentzVector lepSys(0., 0., 0., 0.);
      for (int i = 0; i < int(leptons_RJR.size()); i++)
      {
        TLorentzVector lep1;
        // transverse view of mu 4-vectors
        lep1.SetPtEtaPhiM(leptons_RJR[i]->P4().Pt(), 0.0, leptons_RJR[i]->P4().Phi(), leptons_RJR[i]->P4().M());
        lepSys = lepSys + lep1;
      }
      L_comb->SetLabFrameFourVector(lepSys);

      INV_comb->SetLabFrameThreeVector(ptmiss.Vect());

      LAB_comb->AnalyzeEvent();

      LAB_2L1L->ClearEvent();

      TLorentzVector vISR(0.0, 0.0, 0.0, 0.0);
      //std::cout << "no of jets: " << jetID.size() << std::endl;
      for (int i = 0; i < jets_RJR.size(); i++)
      {
        if (JETS_comb->GetFrame(jetID[i]) != *J_comb) {
          vISR += jets_RJR[i]->P4();
        }
      }
      ISR_2L1L->SetLabFrameFourVector(vISR);

      L1_2L1L->SetLabFrameFourVector(leptons_RJR[Zlep1]->P4());
      L2_2L1L->SetLabFrameFourVector(leptons_RJR[Zlep2]->P4());
      Lb_2L1L->SetLabFrameFourVector(leptons_RJR[Wlep1]->P4());

      INV_2L1L->SetLabFrameThreeVector(ptmiss.Vect());

      LAB_2L1L->AnalyzeEvent();

      // Make the variables
      TLorentzVector vP_CM;
      TLorentzVector vP_ISR;
      TLorentzVector vP_Ia;
      TLorentzVector vP_Ib;
      TLorentzVector vP_I;
      vP_Ia = Ia_2L1L->GetFourVector();
      vP_Ib = Ib_2L1L->GetFourVector();
      vP_CM = CM_2L1L->GetFourVector();
      vP_ISR = ISR_2L1L->GetFourVector();
      vP_I = vP_Ia + vP_Ib;

      double PTCM = vP_CM.Pt();

      TVector3 boostZ = vP_CM.BoostVector();
      boostZ.SetX(0.);
      boostZ.SetY(0.);

      vP_CM.Boost(-boostZ);
      vP_ISR.Boost(-boostZ);
      vP_I.Boost(-boostZ);

      TVector3 boostT = vP_CM.BoostVector();
      vP_ISR.Boost(-boostT);
      vP_I.Boost(-boostT);

      TVector3 vPt_ISR = vP_ISR.Vect();
      TVector3 vPt_I = vP_I.Vect();
      vPt_ISR -= vPt_ISR.Dot(boostZ.Unit()) * boostZ.Unit();
      vPt_I -= vPt_I.Dot(boostZ.Unit()) * boostZ.Unit();

      double PTISR = vPt_ISR.Mag();
      double RISR = -vPt_I.Dot(vPt_ISR.Unit()) / PTISR;
      double PTI = vPt_I.Mag();
      double dphiISRI = fabs(vPt_ISR.Angle(vPt_I));

      // finally do the selections
      if (jets_RJR.size() < 4 && leptons_RJR[0]->PT > 25. && leptons_RJR[1]->PT > 25. && leptons_RJR[2]->PT > 20. && mll > 75. && mll < 105. && mTW > 100. && dphiISRI > 2.0 && RISR > 0.55 && RISR < 1.0 && PTISR > 100. && PTI > 80. && PTCM < 25.) {
        countSignalEvent("SR3l_ISR");
      }
    }

  }

  // onshell
  bool onshell = false;
  if (leptons_onshell.size() == 3 && leptons_onshell[0]->PT > 25. && leptons_onshell[1]->PT > 20. && leptons_onshell[2]->PT > 10. && met > 50.)
  {
    onshell = true;
  }
  if (onshell)
  {
    countCutflowEvent("002_3leptons_onshell");
    bool WZ_onshell = false;
    bool WH_onshell_75 = false;
    bool WH_onshell_105 = false;
    bool WH_dfos_onshell = false;
    int num_sfos_onshell = 0;
    int num_dfos_onshell = 0;
    int num_lmdilep_onshell = 0;
    double mll_onshell = -999.;
    double mdiff_onshell = 1e6;
    TLorentzVector lepiW_onshell = TLorentzVector(0., 0., 0., 0);
    TLorentzVector lepi_onshell = TLorentzVector(0., 0., 0., 0);
    TLorentzVector lepj_onshell = TLorentzVector(0., 0., 0., 0);
    TLorentzVector lepsfss_onshell = TLorentzVector(0., 0., 0., 0.);
    TLorentzVector lepdfos_onshell = TLorentzVector(0., 0., 0., 0.);
    for (int i = 0; i < (leptons_onshell.size() - 1); i++)
    {
      for (int j = i + 1; j < leptons_onshell.size(); j++)
      {
        int k = leptons_onshell.size() - i - j;
        if ((leptons_onshell[i]->Charge * leptons_onshell[j]->Charge > 0) && (leptons_onshell[i]->Type == leptons_onshell[j]->Type))
        {
          lepsfss_onshell = leptons_onshell[i]->P4() + leptons_onshell[j]->P4();
        }
        if (leptons_onshell[i]->Charge * leptons_onshell[j]->Charge < 0)
        {
          if (leptons_onshell[i]->Type != leptons_onshell[j]->Type)
          {
            lepdfos_onshell = leptons_onshell[i]->P4() + leptons_onshell[j]->P4();
            num_dfos_onshell++;
          }
          if (leptons_onshell[i]->Type == leptons_onshell[j]->Type)
          {
            num_sfos_onshell++;
            if ((leptons_onshell[i]->P4() + leptons_onshell[j]->P4()).M() <= 12.)
            {
              num_lmdilep_onshell++;
            }
            lepi_onshell = leptons_onshell[i]->P4();
            lepj_onshell = leptons_onshell[j]->P4();
            double imll = (lepi_onshell + lepj_onshell).M();
            double imdiff_z = fabs(91.1876 - imll);
            if (imdiff_z < mdiff_onshell)
            {
              mdiff_onshell = imdiff_z;
              mll_onshell = imll;
              lepiW_onshell = leptons_onshell[k]->P4();
            }
          }
        }
      }
    }

    // wz_onshell
    double wlepMetphi = lepiW_onshell.DeltaPhi(ptmiss);
    double mTW_onshell = sqrt(2*lepiW_onshell.Pt()*met*(1-TMath::Cos(wlepMetphi)));
    double HTlep_onshell = leptons_onshell[0]->PT + leptons_onshell[1]->PT + leptons_onshell[2]->PT;
    if (num_sfos_onshell >= 1)
    {
      countCutflowEvent("003_sfos_wz_onshell");
      if (dilep_trigger_onshell)
      {
        countCutflowEvent("004_trigger_wz_onshell");
        if (bjets.size() == 0)
        {
          countCutflowEvent("005_0bjets_wz_onshell");
          if (num_lmdilep_onshell == 0)
          {
            countCutflowEvent("006_resonance_veto_wz_onshell");
            if (fabs((leptons_onshell[0]->P4() + leptons_onshell[1]->P4() + leptons_onshell[2]->P4()).M() - 90.) > 15.)
            {
              countCutflowEvent("007_m3l_wz_onshell");
              if (mll_onshell >= 75. && mll_onshell <= 105.)
              {
                WZ_onshell = true;
                countCutflowEvent("008_mll_wz_onshell");
              }
            }
          }
        }
      }
    }

    bool WZ_0j_onshell(false),WZ_nj_onshell(false),WZ_nj_ht_onshell(false),WZ_nj_htlep_onshell(false);
    bool SR_WZ_01(false),SR_WZ_02(false),SR_WZ_03(false),SR_WZ_04(false),SR_WZ_05(false),SR_WZ_06(false),SR_WZ_07(false),SR_WZ_08(false),SR_WZ_09(false),SR_WZ_10(false),SR_WZ_11(false),SR_WZ_12(false),SR_WZ_13(false),SR_WZ_14(false),SR_WZ_15(false),SR_WZ_16(false),SR_WZ_17(false),SR_WZ_18(false),SR_WZ_19(false),SR_WZ_20(false);
    
    if (WZ_onshell)
    {
      if (jets_sig.size() == 0)
      {
        WZ_0j_onshell = true;
      }
      if (jets_sig.size() > 0)
      {
        WZ_nj_onshell = true;
        if (HT < 200.)
        {
          WZ_nj_ht_onshell = true;
        }
        if (HT > 200.)
        { 
          countCutflowEvent("031_wz_nj_ht_200more");
          if (HTlep_onshell < 350.)
          {  
            WZ_nj_htlep_onshell = true;
          }
        }
      }
    }

    if (WZ_0j_onshell)
    {
      countCutflowEvent("009_wz_0j_onshell");
      if (mTW_onshell >= 100. && mTW_onshell <= 160.)
      {
        countCutflowEvent("010_wz_0j_mTW100-160_onshell");
        if (met <= 100. && met > 50.)
        {
          SR_WZ_01 = true;
          countSignalEvent("SR_WZ_01");
          countCutflowEvent("011_SR_WZ_01");
        }
        if (met <= 150. && met > 100.)
        {
          SR_WZ_02 = true;
          countSignalEvent("SR_WZ_02");
          countCutflowEvent("012_SR_WZ_02");
        }
        if (met <= 200. && met > 150.)
        {
          SR_WZ_03 = true;
          countSignalEvent("SR_WZ_03");
          countCutflowEvent("013_SR_WZ_03");
        }
        if (met > 200)
        {
          SR_WZ_04 = true;
          countSignalEvent("SR_WZ_04");
          countCutflowEvent("014_SR_WZ_04");
        }
      }
      else if (mTW_onshell > 160.)
      {
        countCutflowEvent("015_wz_0j_mTW160_onshell");
        if (met <= 150.)
        {
          SR_WZ_05 = true;
          countSignalEvent("SR_WZ_05");
          countCutflowEvent("016_SR_WZ_05");
        }
        else if (met <= 200.)
        {
          SR_WZ_06 = true;
          countSignalEvent("SR_WZ_06");
          countCutflowEvent("017_SR_WZ_06");
        }
        else if (met <= 350.)
        {
          SR_WZ_07 = true;
          countSignalEvent("SR_WZ_07");
          countCutflowEvent("018_SR_WZ_07");
        }
        else
        {
          SR_WZ_08 = true;
          countSignalEvent("SR_WZ_08");
          countCutflowEvent("019_SR_WZ_08");
        }
      }
    }

    if (SR_WZ_02 || SR_WZ_03)
    {
      countSignalEvent("SR_incWZ_01");
    }
    if (SR_WZ_04)
    {
      countSignalEvent("SR_incWZ_02");
    }
    if (SR_WZ_07 || SR_WZ_08)
    {
      countSignalEvent("SR_incWZ_05");
    }

    if (WZ_nj_ht_onshell)
    {
      countCutflowEvent("020_wz_nj_ht_onshell");
      if (mTW_onshell >= 100. && mTW_onshell <= 160.)
      {
        countCutflowEvent("021_wz_nj_ht_mtw100-160_onshell");
        if (met > 100. && met <= 150.)
        {
          SR_WZ_09 = true;
          countSignalEvent("SR_WZ_09");
          countCutflowEvent("022_SR_WZ_09");
        }
        if (met > 150. && met <= 250.)
        {
          SR_WZ_10 = true;
          countSignalEvent("SR_WZ_10");
          countCutflowEvent("023_SR_WZ_10");
        }
        if (met > 250. && met <= 300.)
        {
          SR_WZ_11 = true;
          countSignalEvent("SR_WZ_11");
          countCutflowEvent("024_SR_WZ_11");
        }
        if (met > 300.)
        {
          SR_WZ_12 = true;
          countSignalEvent("SR_WZ_12");
          countCutflowEvent("025_SR_WZ_12");
        }
      }
      else if (mTW_onshell > 160.)
      {
        countCutflowEvent("026_wz_nj_ht_mtw160_onshell");
        if (met <= 150.)
        {
          SR_WZ_13 = true;
          countSignalEvent("SR_WZ_13");
          countCutflowEvent("027_SR_WZ_13");
        }
        else if (met <= 250.)
        {
          SR_WZ_14 = true;
          countSignalEvent("SR_WZ_14");
          countCutflowEvent("028_SR_WZ_14");
        }
        else if (met <= 400.)
        {
          SR_WZ_15 = true;
          countSignalEvent("SR_WZ_15");
          countCutflowEvent("029_SR_WZ_15");
        }
        else
        {
          SR_WZ_16 = true;
          countSignalEvent("SR_WZ_16");
          countCutflowEvent("030_SR_WZ_16");
        }
      }
    }

    if (WZ_nj_htlep_onshell)
    {
      countCutflowEvent("032_wz_nj_htlep_onshell");
      if (mTW_onshell > 100.) {
        countCutflowEvent("033_wz_htlep_mtw100more_onshell");
        if (met > 150. && met <= 200.)
        {
          SR_WZ_17 = true;
          countSignalEvent("SR_WZ_17");
          countCutflowEvent("034_SR_WZ_17");
        }
        if (met > 200. && met <= 300.)
        {
          SR_WZ_18 = true;
          countSignalEvent("SR_WZ_18");
          countCutflowEvent("035_SR_WZ_18");
        }
        if (met > 300. && met <= 400.)
        {
          SR_WZ_19 = true;
          countSignalEvent("SR_WZ_19");
          countCutflowEvent("036_SR_WZ_19");
        }
        if (met > 400.)
        {
          SR_WZ_20 = true;
          countSignalEvent("SR_WZ_20");
          countCutflowEvent("037_SR_WZ_20");
        }
      }
    }

    if (SR_WZ_10)
    {
      countSignalEvent("SR_incWZ_03");
    }
    if (SR_WZ_11 || SR_WZ_12)
    {
      countSignalEvent("SR_incWZ_04");
    }
    if (WZ_nj_ht_onshell && mTW_onshell > 160.)
    {
      if (met > 200.)
      {
        countSignalEvent("SR_incWZ_06");
      }
    }

    // wh_onshell
    double dros = lepdfos_onshell.DeltaR(lepsfss_onshell);
    bool SR_Wh_DFOS_01(false),SR_Wh_DFOS_02(false);

    if (dilep_trigger_onshell)
    {
      countCutflowEvent("038_trigger_wh_onshell");
      if (bjets.size() == 0)
      {
        countCutflowEvent("039_0bjets_wh_onshell");
        if (num_sfos_onshell >= 1)
        {
          countCutflowEvent("040_sfos_wh_onshell");
          if (num_lmdilep_onshell == 0)
          {
            countCutflowEvent("041_resonance_veto_wh_onshell");
            if (fabs((leptons_onshell[0]->P4() + leptons_onshell[1]->P4() + leptons_onshell[2]->P4()).M() - 91.1876) > 15.)
            {
              countCutflowEvent("042_m3l_wh_onshell");
              if (mll_onshell < 75.)
              {
                WH_onshell_75 = true;
              }
              if (mll_onshell >= 105.)
              {
                WH_onshell_105 = true;
              }
            }
          }
        }
        if (num_sfos_onshell == 0 && num_dfos_onshell > 0)
        {
          countCutflowEvent("066_wh_dfos_onshell");
          if (jets_sig.size() == 0)
          {
            countCutflowEvent("067_wh_dfos_0j_onshell");
            if (leptons_onshell[2]->PT > 15.)
            {
              countCutflowEvent("068_wh_dfos_ptl3_15_onshell");
              if (metsig > 8.)
              {
                countCutflowEvent("069_wh_dfos_metsig8_onshell");
                if (dros < 1.2)
                {
                  SR_Wh_DFOS_01 = true;
                  countCutflowEvent("070_wh_dfos_dros1.2_onshell");
                  countSignalEvent("SR_Wh_DFOS_01");
                }
              }
            }
          }
          if (jets_sig.size() >= 1 && jets_sig.size() <= 2)
          {
            countCutflowEvent("071_wh_dfos_nj_onshell");
            if (leptons_onshell[2]->PT > 20.)
            {
              countCutflowEvent("072_wh_dfos_ptl3_20_onshell");
              if (metsig > 8.)
              {
                countCutflowEvent("073_wh_dfos_metsig8_onshell");
                if (dros < 1.0)
                {
                  SR_Wh_DFOS_02 = true;
                  countCutflowEvent("074_wh_dfos_dros1.0_onshell");
                  countSignalEvent("SR_Wh_DFOS_02");
                }
              }
            }
          }
        }
        if (SR_Wh_DFOS_01 || SR_Wh_DFOS_02)
        {
          countCutflowEvent("075_wh_dfos");
          countSignalEvent("SR_incWh_DFOS_12");
        }
      }
    }

    bool WH_0j_onshell_75(false),WH_nj_ht_onshell_75(false),WH_nj_onshell_75(false);
    bool SR_Wh_SFOS_01(false),SR_Wh_SFOS_02(false),SR_Wh_SFOS_03(false),SR_Wh_SFOS_04(false),SR_Wh_SFOS_05(false),SR_Wh_SFOS_06(false),SR_Wh_SFOS_07(false),SR_Wh_SFOS_08(false);
    bool SR_Wh_SFOS_09(false),SR_Wh_SFOS_10(false),SR_Wh_SFOS_11(false),SR_Wh_SFOS_12(false),SR_Wh_SFOS_13(false),SR_Wh_SFOS_14(false),SR_Wh_SFOS_15(false),SR_Wh_SFOS_16(false);
    
    if (WH_onshell_75)
    {
      countCutflowEvent("043_sfos_wh_onshell75");
      if (jets_sig.size() == 0)
      {
        WH_0j_onshell_75 = true;
      }
      else
      {
        WH_nj_onshell_75 = true;
        if (HT < 200.)
        {
          WH_nj_ht_onshell_75 = true;
        }
      }
    }

    if (WH_0j_onshell_75)
    {
      countCutflowEvent("044_wh_0j_onshell_75");
      if (mTW_onshell > 0. && mTW_onshell <= 100.)
      {
        if (met > 50. && met <= 100.)
        {
          SR_Wh_SFOS_01 = true;
          countSignalEvent("SR_Wh_SFOS_01");
          countCutflowEvent("045_SR_Wh_SFOS_01");
        }
        if (met > 100. && met <= 150.)
        {
          SR_Wh_SFOS_02 = true;
          countSignalEvent("SR_Wh_SFOS_02");
          countCutflowEvent("046_SR_Wh_SFOS_02");
        }
        if (met > 150.)
        {
          SR_Wh_SFOS_03 = true;
          countSignalEvent("SR_Wh_SFOS_03");
          countCutflowEvent("047_SR_Wh_SFOS_03");
        }
      }
      if (mTW_onshell > 100. && mTW_onshell <= 160.)
      {
        if (met > 50. && met <= 100.)
        {
          SR_Wh_SFOS_04 = true;
          countSignalEvent("SR_Wh_SFOS_04");
          countCutflowEvent("048_SR_Wh_SFOS_04");
        }
        if (met > 100.)
        {
          SR_Wh_SFOS_05 = true;
          countSignalEvent("SR_Wh_SFOS_05");
          countCutflowEvent("049_SR_Wh_SFOS_05");
        }
      }
      if (mTW_onshell > 160.)
      {
        if (met > 50. && met <= 100.)
        {
          SR_Wh_SFOS_06 = true;
          countSignalEvent("SR_Wh_SFOS_06");
          countCutflowEvent("050_SR_Wh_SFOS_06");
        }
        if (met > 100.)
        {
          SR_Wh_SFOS_07 = true;
          countSignalEvent("SR_Wh_SFOS_07");
          countCutflowEvent("051_SR_Wh_SFOS_07");
        }
      }
    }

    if (WH_nj_ht_onshell_75)
    {
      countCutflowEvent("052_wh_nj_onshell_75");
      if (mTW_onshell > 0. && mTW_onshell <= 50.)
      {
        if (met <= 100.)
        {
          SR_Wh_SFOS_08 = true;
          countSignalEvent("SR_Wh_SFOS_08");
          countCutflowEvent("053_SR_Wh_SFOS_08");
        }
      }
      if (mTW_onshell > 50. && mTW_onshell <= 100.)
      {
        if (met <= 100.)
        {
          SR_Wh_SFOS_09 = true;
          countSignalEvent("SR_Wh_SFOS_09");
          countCutflowEvent("054_SR_Wh_SFOS_09");
        }
      }
      if (mTW_onshell > 0. && mTW_onshell <= 100.)
      {
        if (met > 100. && met <= 150.)
        {
          SR_Wh_SFOS_10 = true;
          countSignalEvent("SR_Wh_SFOS_10");
          countCutflowEvent("055_SR_Wh_SFOS_10");
        }
        else if (met > 150.)
        {
          SR_Wh_SFOS_11 = true;
          countSignalEvent("SR_Wh_SFOS_11");
          countCutflowEvent("056_SR_Wh_SFOS_11");
        }
      }
      if (mTW_onshell > 100. && mTW_onshell <= 160.)
      {
        if (met <= 100.)
        {
          SR_Wh_SFOS_12 = true;
          countSignalEvent("SR_Wh_SFOS_12");
          countCutflowEvent("057_SR_Wh_SFOS_12");
        }
        else if (met <= 150.)
        {
          SR_Wh_SFOS_13 = true;
          countSignalEvent("SR_Wh_SFOS_13");
          countCutflowEvent("058_SR_Wh_SFOS_13");
        }
        else
        {
          SR_Wh_SFOS_14 = true;
          countSignalEvent("SR_Wh_SFOS_14");
          countCutflowEvent("059_SR_Wh_SFOS_14");
        }
      }
      if (mTW_onshell > 160.)
      {
        if (met <= 150.)
        {
          SR_Wh_SFOS_15 = true;
          countSignalEvent("SR_Wh_SFOS_15");
          countCutflowEvent("060_SR_Wh_SFOS_15");
        }
        else
        {
          SR_Wh_SFOS_16 = true;
          countSignalEvent("SR_Wh_SFOS_16");
          countCutflowEvent("061_SR_Wh_SFOS_16");
        }
      }
    }

    if (SR_Wh_SFOS_01 || SR_Wh_SFOS_02 || SR_Wh_SFOS_03)
    {
      countSignalEvent("SR_incWh_SFOS_07");
    }
    if (SR_Wh_SFOS_04 || SR_Wh_SFOS_05)
    {
      countSignalEvent("SR_incWh_SFOS_08");
    }
    if (SR_Wh_SFOS_06 || SR_Wh_SFOS_07)
    {
      countSignalEvent("SR_incWh_SFOS_10");
    }

    if (WH_nj_onshell_75)
    {
      if (mTW_onshell > 100. && mTW_onshell <= 160.)
      {
        if (met > 75.)
        {
          countSignalEvent("SR_incWh_SFOS_09");
        }
      }
      else if (mTW_onshell > 160.)
      {
        if (met > 75.)
        {
          countSignalEvent("SR_incWh_SFOS_11");
        }
      }
    }

    if (WH_onshell_105)
    {
      countCutflowEvent("062_mll_wh_sfos_onshell105");
      if (jets_sig.size() == 0)
      {
        if (mTW_onshell > 100.)
        {
          if (met <= 100.)
          {
            countSignalEvent("SR_Wh_SFOS_17");
            countCutflowEvent("063_SR_Wh_SFOS_17");
          }
          else if (met <= 200.)
          {
            countSignalEvent("SR_Wh_SFOS_18");
            countCutflowEvent("064_SR_Wh_SFOS_18");
          }
          else
          {
            countSignalEvent("SR_Wh_SFOS_19");
            countCutflowEvent("065_SR_Wh_SFOS_19");
          }
        }
      }
    }
  }

  // offshell
  if (offshell)
  {
    double mZ = 91.1876;
    double mll_offshell = -999.;
    double mdiff_offshell = 1e6;
    double mll_min_offshell = 1e6;
    double mll_max_offshell = -999;
    double drll_sfos_min_offshell = 1e6;
    double drll_min_offshell = 1e6;
    int num_sfos_offshell = 0;
    int i0, i1, i2;
    int iZ1(-1), iZ2(-1), iW(-1); // closest to mZ order
    int jZ1(-1), jZ2(-1), jW(-1); // minmll order
    // lepton permutations Z1, Z2, W
    std::string index = "012";
    do
    {
      i0 = index[0] - '0';
      i1 = index[1] - '0';
      i2 = index[2] - '0'; // char2int

      // only Z1,Z2 with Z1>Z2
      if (i0 < i1)
        continue;

      double idR = leptons_offshell[i0]->P4().DeltaR(leptons_offshell[i1]->P4());
      // mindR_3L
      if (idR < drll_min_offshell)
        drll_min_offshell = idR;

      // OSSF pairs only
      if ((leptons_offshell[i0]->Charge == leptons_offshell[i1]->Charge) || (leptons_offshell[i0]->Type != leptons_offshell[i1]->Type))
        continue;
      num_sfos_offshell++;

      double imll = (leptons_offshell[i0]->P4() + leptons_offshell[i1]->P4()).M();
      double imdiff = fabs(imll - mZ);

      // closest to mZ
      if (imdiff < mdiff_offshell)
      {
        mdiff_offshell = imdiff;
        mll_offshell = imll;
        iZ1 = i0;
        iZ2 = i1;
        iW = i2;
      }
      // minmll
      if (imll < mll_min_offshell)
      {
        mll_min_offshell = imll;
        jZ1 = i0;
        jZ2 = i1;
        jW = i2;
      }
      // maxmll
      if (imll > mll_max_offshell) {
        mll_max_offshell = imll;
      }
      // mindR_OSSF
      if (idR < drll_sfos_min_offshell) {
        drll_sfos_min_offshell = idR;
      }

    } while (std::next_permutation(index.begin(), index.end()));

    if (num_sfos_offshell == 0) {
      return;
    }

    if (iZ1 == -1 || iZ2 == -1 || iW == -1 || jZ1 == -1 || jZ2 == -1 || jW == -1) {
      return;
    }

    double ptlep = (leptons_offshell[0]->P4() + leptons_offshell[1]->P4() + leptons_offshell[2]->P4()).Pt();
    double PtlepOverMet = ptlep / met;
    double mt2_offshell = mT2((leptons_offshell[jZ1]->P4() + leptons_offshell[jZ2]->P4()), leptons_offshell[jW]->P4(), 100.);
    double mt_minmll_offshell = mT(leptons_offshell[jW]->P4(), ptmiss);
    bool SR_WZ_lowmet_be_offshell = false;

    if (met < 200. && ((mt_minmll_offshell > 3.0 && mt_minmll_offshell < 3.2) || (mt_minmll_offshell > 9. && mt_minmll_offshell < 12.))) return;
    // dR cleaning
    if (drll_min_offshell < 0.4) {
      return;
    }

    countCutflowEvent("076_3leptons_offshell");
    if (bjets.size() > 0) return;
    countCutflowEvent("077_bveto_offshell");
    if ((!single_trigger && !dilep_trigger_offshell && !trilep_trigger)) return;
    countCutflowEvent("078_trigger_offshell");
    if (mll_max_offshell >= 75. || mll_offshell >= 75.) return;
    countCutflowEvent("079_mllmax_offshell");

    // lowmet signal regions of off-shell signal regions
    if (mll_min_offshell > 12. && mll_min_offshell < 40.)
    {
      countCutflowEvent("080_lowmet_mllmin_12-40_offshell");
      if (leptons_offshell[2]->PT > 10.)
      {
        countCutflowEvent("081_lowmet_ptl10_offshell");
        if (num_fnp == 0)
        {
          countCutflowEvent("082_lowmet_nofnp_offshell");
          if (mll_offshell < 60.)
          {
            SR_WZ_lowmet_be_offshell = true;
          }
        }
      }
    }

    bool SR_WZ_lowmet_b_offshell(false),SR_WZ_lowmet_c_offshell(false),SR_WZ_lowmet_d_offshell(false),SR_WZ_lowmet_e_offshell(false);
    bool SR_WZoff_low_0jb(false),SR_WZoff_low_0jc(false),SR_WZoff_low_0jd(false),SR_WZoff_low_0je(false);
    bool SR_WZoff_low_njb(false),SR_WZoff_low_njc(false),SR_WZoff_low_njd(false),SR_WZoff_low_nje(false);
    bool SR_WZoff_low_0jf1(false),SR_WZoff_low_0jf2(false),SR_WZoff_low_0jg1(false),SR_WZoff_low_0jg2(false);
    bool SR_WZoff_low_njf1(false),SR_WZoff_low_njf2(false),SR_WZoff_low_njg1(false),SR_WZoff_low_njg2(false);
    
    if (SR_WZ_lowmet_be_offshell)
    {
      countCutflowEvent("083_lowmet_mllmax60_offshell");
      if (mll_min_offshell > 12. && mll_min_offshell <= 15.)
      {
        countCutflowEvent("084_SR_WZ_lowmet_b_mll_offshell");
        if (mt2_offshell < 115.)
        {
          countCutflowEvent("085_SR_WZ_lowmet_b_mt2_offshell");
          if (drll_sfos_min_offshell < 1.6)
          {
            SR_WZ_lowmet_b_offshell = true;
          }
        }
      }
      if (mll_min_offshell > 15. && mll_min_offshell <= 20.)
      {
        countCutflowEvent("097_SR_WZ_lowmet_c_mll_offshell");
        if (mt2_offshell < 120.)
        {
          countCutflowEvent("098_SR_WZ_lowmet_c_mt2_offshell");
          if (drll_sfos_min_offshell < 1.6)
          {
            SR_WZ_lowmet_c_offshell = true;
          }
        }
      }
      if (mll_min_offshell > 20. && mll_min_offshell <= 30.)
      {
        countCutflowEvent("110_SR_WZ_lowmet_d_mll_offshell");
        if (mt2_offshell < 130.)
        {
          countCutflowEvent("111_SR_WZ_lowmet_d_mt2_offshell");
          if (drll_sfos_min_offshell < 1.6)
          {
            SR_WZ_lowmet_d_offshell = true;
          }
        }
      }
      if (mll_min_offshell > 30. && mll_min_offshell <= 40.)
      {
        countCutflowEvent("123_SR_WZ_lowmet_e_mll_offshell");
        SR_WZ_lowmet_e_offshell = true;
      }
    }

    if (SR_WZ_lowmet_b_offshell)
    {
      countCutflowEvent("086_SR_WZ_lowmet_b_drll_offshell");
      if (jets_30sig.size() == 0)
      {
        countCutflowEvent("087_SR_WZ_lowmet_b_0j_offshell");
        if (met < 50.)
        {
          countCutflowEvent("088_SR_WZ_lowmet_b_0j_met_offshell");
          if (metsig > 1.5)
          {
            countCutflowEvent("089_SR_WZ_lowmet_b_0j_metsig_offshell");
            if (mt_minmll_offshell < 50.)
            {
              countCutflowEvent("090_SR_WZ_lowmet_b_0j_mt_offshell");
              if (PtlepOverMet < 1.1)
              {
                SR_WZoff_low_0jb = true;
                countCutflowEvent("091_SR_WZ_lowmet_b_0j_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_0jb");
              }
            }
          }
        }
      }
      if (jets_30sig.size() > 0)
      {
        countCutflowEvent("092_SR_WZ_lowmet_b_nj_offshell");
        if (met < 200.)
        {
          countCutflowEvent("093_SR_WZ_lowmet_b_nj_met_offshell");
          if (metsig > 3.0)
          {
            countCutflowEvent("094_SR_WZ_lowmet_b_nj_metsig_offshell");
            if (mt_minmll_offshell < 50.)
            {
              countCutflowEvent("095_SR_WZ_lowmet_b_nj_mt_offshell");
              if (PtlepOverMet < 1.0)
              {
                SR_WZoff_low_njb = true;
                countCutflowEvent("096_SR_WZ_lowmet_b_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njb");
              }
            }
          }
        }
      }
    }

    if (SR_WZ_lowmet_c_offshell)
    {
      countCutflowEvent("099_SR_WZ_lowmet_c_drll_offshell");
      if (jets_30sig.size() == 0)
      {
        countCutflowEvent("100_SR_WZ_lowmet_c_0j_offshell");
        if (met < 50.)
        {
          countCutflowEvent("101_SR_WZ_lowmet_c_0j_met_offshell");
          if (metsig > 1.5)
          {
            countCutflowEvent("102_SR_WZ_lowmet_c_0j_metsig_offshell");
            if (mt_minmll_offshell < 50.)
            {
              countCutflowEvent("103_SR_WZ_lowmet_c_0j_mt_offshell");
              if (PtlepOverMet < 1.1)
              {
                SR_WZoff_low_0jc = true;
                countCutflowEvent("104_SR_WZ_lowmet_c_0j_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_0jc");
              }
            }
          }
        }
      }
      if (jets_30sig.size() > 0)
      {
        countCutflowEvent("105_SR_WZ_lowmet_c_nj_offshell");
        if (met < 200.)
        {
          countCutflowEvent("106_SR_WZ_lowmet_c_nj_met_offshell");
          if (metsig > 3.0)
          {
            countCutflowEvent("107_SR_WZ_lowmet_c_nj_metsig_offshell");
            if (mt_minmll_offshell < 50.)
            {
              countCutflowEvent("108_SR_WZ_lowmet_c_nj_mt_offshell");
              if (PtlepOverMet < 1.0)
              {
                SR_WZoff_low_njc = true;
                countCutflowEvent("109_SR_WZ_lowmet_c_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njc");
              }
            }
          }
        }
      }
    }

    if (SR_WZ_lowmet_d_offshell)
    {
      countCutflowEvent("112_SR_WZ_lowmet_d_drll_offshell");
      if (jets_30sig.size() == 0)
      {
        countCutflowEvent("113_SR_WZ_lowmet_d_0j_offshell");
        if (met < 50.)
        {
          countCutflowEvent("114_SR_WZ_lowmet_d_0j_met_offshell");
          if (metsig > 1.5)
          {
            countCutflowEvent("115_SR_WZ_lowmet_d_0j_metsig_offshell");
            if (mt_minmll_offshell < 50.)
            {
              countCutflowEvent("116_SR_WZ_lowmet_d_0j_mt_offshell");
              if (PtlepOverMet < 1.1)
              {
                SR_WZoff_low_0jd = true;
                countCutflowEvent("117_SR_WZ_lowmet_d_0j_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_0jd");
              }
            }
          }
        }
      }
      if (jets_30sig.size() > 0)
      {
        countCutflowEvent("118_SR_WZ_lowmet_d_nj_offshell");
        if (met < 200.)
        {
          countCutflowEvent("119_SR_WZ_lowmet_d_nj_met_offshell");
          if (metsig > 3.0)
          {
            countCutflowEvent("120_SR_WZ_lowmet_d_nj_metsig_offshell");
            if (mt_minmll_offshell < 50.)
            {
              countCutflowEvent("121_SR_WZ_lowmet_d_nj_mt_offshell");
              if (PtlepOverMet < 1.0)
              {
                SR_WZoff_low_njd = true;
                countCutflowEvent("122_SR_WZ_lowmet_d_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njd");
              }
            }
          }
        }
      }
    }
    if (SR_WZ_lowmet_e_offshell)
    {
      countCutflowEvent("124_SR_WZ_lowmet_e_drll_offshell");
      if (jets_30sig.size() == 0)
      {
        countCutflowEvent("125_SR_WZ_lowmet_e_0j_offshell");
        if (met < 50.)
        {
          countCutflowEvent("126_SR_WZ_lowmet_e_0j_met_offshell");
          if (metsig > 1.5)
          {
            countCutflowEvent("127_SR_WZ_lowmet_e_0j_metsig_offshell");
            if (mt_minmll_offshell < 60.)
            {
              countCutflowEvent("128_SR_WZ_lowmet_e_0j_mt_offshell");
              if (PtlepOverMet < 1.3)
              {
                SR_WZoff_low_0je = true;
                countCutflowEvent("129_SR_WZ_lowmet_e_0j_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_0je");
              }
            }
          }
        }
      }
      if (jets_30sig.size() > 0)
      {
        countCutflowEvent("130_SR_WZ_lowmet_e_nj_offshell");
        if (met < 200.)
        {
          countCutflowEvent("131_SR_WZ_lowmet_e_nj_met_offshell");
          if (metsig > 3.0)
          {
            countCutflowEvent("132_SR_WZ_lowmet_e_nj_metsig_offshell");
            if (mt_minmll_offshell < 60.)
            {
              countCutflowEvent("133_SR_WZ_lowmet_e_nj_mt_offshell");
              if (PtlepOverMet < 1.0)
              {
                SR_WZoff_low_nje = true;
                countCutflowEvent("134_SR_WZ_lowmet_e_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_nje");
              }
            }
          }
        }
      }
    }

    if (SR_WZoff_low_0jb || SR_WZoff_low_njb)
    {
      countSignalEvent("SR_incWZoff_low_b");
    }
    if (SR_WZoff_low_0jb || SR_WZoff_low_njb || SR_WZoff_low_0jc || SR_WZoff_low_njc)
    {
      countSignalEvent("SR_incWZoff_low_c");
    }

    bool SR_WZ_lowmet_f1g2_offshell = false;
    if (mll_min_offshell > 40. && mll_min_offshell <= 75.)
    {
      countCutflowEvent("135_lowmet_mllmin_40-75_offshell");
      if (leptons_offshell[0]->PT > 15. && leptons_offshell[1]->PT > 15. && leptons_offshell[2]->PT > 15.)
      {
        countCutflowEvent("136_lowmet_ptl15_offshell");
        if ((electrons.size() + muons.size()) == 3)
        {
          SR_WZ_lowmet_f1g2_offshell = true;
        }
      }
    }

    bool SR_WZ_lowmet_f1f2_offshell = false;
    bool SR_WZ_lowmet_g1g2_offshell = false;
    if (SR_WZ_lowmet_f1g2_offshell)
    {
      countCutflowEvent("137_lowmet_nofnp_offshell");
      if (mll_min_offshell > 40. && mll_min_offshell <= 60.)
      {
        SR_WZ_lowmet_f1f2_offshell = true;
      }
      if (mll_min_offshell > 60. && mll_min_offshell <= 75.)
      {
        SR_WZ_lowmet_g1g2_offshell = true;
      }
    }

    if (SR_WZ_lowmet_f1f2_offshell)
    {
      countCutflowEvent("138_SR_WZ_lowmet_f1f2_mll_offshell");
      if (jets_30sig.size() == 0)
      {
        countCutflowEvent("139_SR_WZ_lowmet_f1f2_0j_offshell");
        if (met < 50.)
        {
          countCutflowEvent("140_SR_WZ_lowmet_f1f2_0j_met_offshell");
          if (metsig > 1.5)
          {
            countCutflowEvent("141_SR_WZ_lowmet_f1f2_0j_metsig_offshell");
            if ((leptons_offshell[0]->P4() + leptons_offshell[1]->P4() + leptons_offshell[2]->P4()).M() > 100.)
            {
              countCutflowEvent("142_SR_WZ_lowmet_f1f2_0j_m3l_offshell");
              if (mt_minmll_offshell < 60.)
              {
                countCutflowEvent("143_SR_WZ_lowmet_f1_0j_mt_offshell");
                if (PtlepOverMet < 1.4)
                {
                  SR_WZoff_low_0jf1 = true;
                  countCutflowEvent("144_SR_WZ_lowmet_f1_0j_ptlep_offshell");
                  countSignalEvent("SR_WZoff_low_0jf1");
                }
              }
              if (mt_minmll_offshell > 90.)
              {
                countCutflowEvent("145_SR_WZ_lowmet_f2_0j_mt_offshell");
                if (PtlepOverMet < 1.4)
                {
                  SR_WZoff_low_0jf2 = true;
                  countCutflowEvent("146_SR_WZ_lowmet_f2_0j_ptlep_offshell");
                  countSignalEvent("SR_WZoff_low_0jf2");
                }
              }
            }
          }
        }
      }
      if (jets_30sig.size() > 0)
      {
        countCutflowEvent("147_SR_WZ_lowmet_f1f2_nj_offshell");
        if (met < 200.)
        {
          countCutflowEvent("148_SR_WZ_lowmet_f1f2_nj_met_offshell");
          if (metsig > 3.0)
          {
            countCutflowEvent("149_SR_WZ_lowmet_f1f2_nj_metsig_offshell");
            if (mt_minmll_offshell < 60.)
            {
              countCutflowEvent("150_SR_WZ_lowmet_f1_nj_mt_offshell");
              if (PtlepOverMet < 1.2)
              {
                SR_WZoff_low_njf1 = true;
                countCutflowEvent("151_SR_WZ_lowmet_f1_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njf1");
              }
            }
            if (mt_minmll_offshell > 90.)
            {
              countCutflowEvent("152_SR_WZ_lowmet_f2_nj_mt_offshell");
              if (PtlepOverMet < 1.2)
              {
                SR_WZoff_low_njf2 = true;
                countCutflowEvent("153_SR_WZ_lowmet_f2_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njf2");
              }
            }
          }
        }
      }
    }
    if (SR_WZ_lowmet_g1g2_offshell)
    {
      countCutflowEvent("154_SR_WZ_lowmet_g1g2_mll_offshell");
      ;
      if (jets_30sig.size() == 0)
      {
        countCutflowEvent("155_SR_WZ_lowmet_g1g2_0j_offshell");
        if (met < 50.)
        {
          countCutflowEvent("156_SR_WZ_lowmet_g1g2_0j_met_offshell");
          if (metsig > 1.5)
          {
            countCutflowEvent("157_SR_WZ_lowmet_g1g2_0j_metsig_offshell");
            if ((leptons_offshell[0]->P4() + leptons_offshell[1]->P4() + leptons_offshell[2]->P4()).M() > 100.)
            {
              countCutflowEvent("158_SR_WZ_lowmet_g1g2_0j_m3l_offshell");
              if (mt_minmll_offshell < 60.)
              {
                countCutflowEvent("159_SR_WZ_lowmet_g1_0j_mt_offshell");
                if (PtlepOverMet < 1.4)
                {
                  SR_WZoff_low_0jg1 = true;
                  countCutflowEvent("160_SR_WZ_lowmet_g1_0j_ptlep_offshell");
                  countSignalEvent("SR_WZoff_low_0jg1");
                }
              }
              if (mt_minmll_offshell > 90.)
              {
                countCutflowEvent("161_SR_WZ_lowmet_g2_0j_mt_offshell");
                if (PtlepOverMet < 1.4)
                {
                  SR_WZoff_low_0jg2 = true;
                  countCutflowEvent("162_SR_WZ_lowmet_g2_0j_ptlep_offshell");
                  countSignalEvent("SR_WZoff_low_0jg2");
                }
              }
            }
          }
        }
      }
      if (jets_30sig.size() > 0)
      {
        countCutflowEvent("163_SR_WZ_lowmet_g1g2_nj_offshell");
        if (met < 200.)
        {
          countCutflowEvent("164_SR_WZ_lowmet_g1g2_nj_met_offshell");
          if (metsig > 3.0)
          {
            countCutflowEvent("165_SR_WZ_lowmet_g1g2_nj_metsig_offshell");
            if (mt_minmll_offshell < 60.)
            {
              countCutflowEvent("166_SR_WZ_lowmet_g1_nj_mt_offshell");
              if (PtlepOverMet < 1.2)
              {
                SR_WZoff_low_njg1 = true;
                countCutflowEvent("167_SR_WZ_lowmet_g1_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njg1");
              }
            }
            else if (mt_minmll_offshell > 90.)
            {
              countCutflowEvent("168_SR_WZ_lowmet_g2_nj_mt_offshell");
              if (PtlepOverMet < 1.2)
              {
                SR_WZoff_low_njg2 = true;
                countCutflowEvent("169_SR_WZ_lowmet_g2_nj_ptlep_offshell");
                countSignalEvent("SR_WZoff_low_njg2");
              }
            }
          }
        }
      }
    }

    bool SR_WZ_highmet_0j_offshell = false;
    bool SR_WZ_highmet_nj_offshell = false;
    if (leptons_offshell[0]->PT > 25. && leptons_offshell[1]->PT > 15. && leptons_offshell[2]->PT > 10.)
    {
      SR_WZ_highmet_0j_offshell = true;
    }
    double minptl1 = leptons_offshell[0]->Type == "electron" ? 4.5 : 3.0;
    double minptl2 = leptons_offshell[1]->Type == "electron" ? 4.5 : 3.0;
    double minptl3 = leptons_offshell[2]->Type == "electron" ? 4.5 : 3.0;
    if (leptons_offshell[0]->PT > minptl1 && leptons_offshell[1]->PT > minptl2 && leptons_offshell[2]->PT > minptl3)
    {
      SR_WZ_highmet_nj_offshell = true;
    }

    bool SR_WZoff_high_0jb(false),SR_WZoff_high_0jc(false),SR_WZoff_high_0jd(false),SR_WZoff_high_0je(false),SR_WZoff_high_0jf1(false),SR_WZoff_high_0jf2(false),SR_WZoff_high_0jg1(false),SR_WZoff_high_0jg2(false);
   
    if (SR_WZ_highmet_0j_offshell)
    {
      countCutflowEvent("170_SR_WZ_highmet_0j_pt3l_offshell");
      if (mll_min_offshell > 12. && mll_min_offshell <= 15.)
      {
        countCutflowEvent("171_SR_WZ_highmet_0j_b_mll_offshell");
        if (mt2_offshell < 115.)
        {
          countCutflowEvent("172_SR_WZ_highmet_0j_b_mt2_offshell");
          if (jets_30sig.size() == 0)
          {
            countCutflowEvent("173_SR_WZ_highmet_0j_b_offshell");
            if (met > 50.)
            {
              countCutflowEvent("174_SR_WZ_highmet_0j_b_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("175_SR_WZ_highmet_0j_b_metsig_offshell");
                if (mt_minmll_offshell < 50.)
                {
                  SR_WZoff_high_0jb = true;
                  countCutflowEvent("176_SR_WZ_highmet_0j_b_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jb");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 15. && mll_min_offshell <= 20.)
      {
        countCutflowEvent("177_SR_WZ_highmet_0j_c_mll_offshell");
        if (mt2_offshell < 120.)
        {
          countCutflowEvent("178_SR_WZ_highmet_0j_c_mt2_offshell");
          if (jets_30sig.size() == 0)
          {
            countCutflowEvent("179_SR_WZ_highmet_0j_c_offshell");
            if (met > 50.)
            {
              countCutflowEvent("180_SR_WZ_highmet_0j_c_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("181_SR_WZ_highmet_0j_c_metsig_offshell");
                if (mt_minmll_offshell < 50.)
                {
                  SR_WZoff_high_0jc = true;
                  countCutflowEvent("182_SR_WZ_highmet_0j_c_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jc");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 20. && mll_min_offshell <= 30.)
      {
        countCutflowEvent("183_SR_WZ_highmet_0j_d_mll_offshell");
        if (mt2_offshell < 130.)
        {
          countCutflowEvent("184_SR_WZ_highmet_0j_d_mt2_offshell");
          if (jets_30sig.size() == 0)
          {
            countCutflowEvent("185_SR_WZ_highmet_0j_d_offshell");
            if (met > 50.)
            {
              countCutflowEvent("186_SR_WZ_highmet_0j_d_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("187_SR_WZ_highmet_0j_d_metsig_offshell");
                if (mt_minmll_offshell < 60.)
                {
                  SR_WZoff_high_0jd = true;
                  countCutflowEvent("188_SR_WZ_highmet_0j_d_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jd");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 30. && mll_min_offshell <= 40.)
      {
        countCutflowEvent("189_SR_WZ_highmet_0j_e_mll_offshell");
        if (mt2_offshell < 140.)
        {
          countCutflowEvent("190_SR_WZ_highmet_0j_e_mt2_offshell");
          if (jets_30sig.size() == 0)
          {
            countCutflowEvent("191_SR_WZ_highmet_0j_e_offshell");
            if (met > 50.)
            {
              countCutflowEvent("192_SR_WZ_highmet_0j_e_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("193_SR_WZ_highmet_0j_e_metsig_offshell");
                if (mt_minmll_offshell < 60.)
                {
                  SR_WZoff_high_0je = true;
                  countCutflowEvent("194_SR_WZ_highmet_0j_e_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0je");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 40. && mll_min_offshell <= 60.)
      {
        countCutflowEvent("195_SR_WZ_highmet_0j_f1f2_mll_offshell");
        if (mt2_offshell < 160.)
        {
          countCutflowEvent("196_SR_WZ_highmet_0j_f1f2_mt2_offshell");
          if (jets_30sig.size() == 0)
          {
            countCutflowEvent("197_SR_WZ_highmet_0j_f1f2_offshell");
            if (met > 50.)
            {
              countCutflowEvent("198_SR_WZ_highmet_0j_f1f2_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("199_SR_WZ_highmet_0j_f1f2_metsig_offshell");
                if (mt_minmll_offshell < 70.)
                {
                  SR_WZoff_high_0jf1 = true;
                  countCutflowEvent("200_SR_WZ_highmet_0j_f1_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jf1");
                }
                else if (mt_minmll_offshell > 90.)
                {
                  SR_WZoff_high_0jf2 = true;
                  countCutflowEvent("201_SR_WZ_highmet_0j_f2_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jf2");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 60. && mll_min_offshell <= 75.)
      {
        countCutflowEvent("202_SR_WZ_highmet_0j_g1g2_mll_offshell");
        if (mt2_offshell < 175.)
        {
          countCutflowEvent("203_SR_WZ_highmet_0j_g1g2_mt2_offshell");
          if (jets_30sig.size() == 0)
          {
            countCutflowEvent("204_SR_WZ_highmet_0j_g1g2_offshell");
            if (met > 50.)
            {
              countCutflowEvent("205_SR_WZ_highmet_0j_g1g2_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("206_SR_WZ_highmet_0j_g1g2_metsig_offshell");
                if (mt_minmll_offshell < 70.)
                {
                  SR_WZoff_high_0jg1 = true;
                  countCutflowEvent("207_SR_WZ_highmet_0j_g1_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jg1");
                }
                else if (mt_minmll_offshell > 90.)
                {
                  SR_WZoff_high_0jg2 = true;
                  countCutflowEvent("208_SR_WZ_highmet_0j_g2_mt_offshell");
                  countSignalEvent("SR_WZoff_high_0jg2");
                }
              }
            }
          }
        }
      }
    }

    bool SR_WZoff_high_nja(false),SR_WZoff_high_njb(false),SR_WZoff_high_njc(false),SR_WZoff_high_njd(false),SR_WZoff_high_nje(false),SR_WZoff_high_njf(false),SR_WZoff_high_njg(false);
    
    if (SR_WZ_highmet_nj_offshell)
    {
      countCutflowEvent("209_SR_WZ_highmet_nj_pt3l_offshell");
      if (mll_min_offshell > 1. && mll_min_offshell <= 12.)
      {
        countCutflowEvent("210_SR_WZ_highmet_nj_a_mll_offshell");
        if (mt2_offshell < 112.)
        {
          countCutflowEvent("211_SR_WZ_highmet_nj_a_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("212_SR_WZ_highmet_nj_a_offshell");
            if (met > 200.)
            {
              countCutflowEvent("213_SR_WZ_highmet_nj_a_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("214_SR_WZ_highmet_nj_a_metsig_offshell");
                if (PtlepOverMet < 0.2)
                {
                  SR_WZoff_high_nja = true;
                  countCutflowEvent("215_SR_WZ_highmet_nj_a_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_nja");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 12. && mll_min_offshell <= 15.)
      {
        countCutflowEvent("216_SR_WZ_highmet_nj_b_mll_offshell");
        if (mt2_offshell < 115.)
        {
          countCutflowEvent("217_SR_WZ_highmet_nj_b_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("218_SR_WZ_highmet_nj_b_offshell");
            if (met > 200.)
            {
              countCutflowEvent("219_SR_WZ_highmet_nj_b_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("220_SR_WZ_highmet_nj_b_metsig_offshell");
                if (PtlepOverMet < 0.2)
                {
                  SR_WZoff_high_njb = true;
                  countCutflowEvent("221_SR_WZ_highmet_nj_b_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_njb");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 15. && mll_min_offshell <= 20.)
      {
        countCutflowEvent("222_SR_WZ_highmet_nj_c_mll_offshell");
        if (mt2_offshell < 120.)
        {
          countCutflowEvent("223_SR_WZ_highmet_nj_c_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("224_SR_WZ_highmet_nj_c_offshell");
            if (met > 200.)
            {
              countCutflowEvent("225_SR_WZ_highmet_nj_c_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("226_SR_WZ_highmet_nj_c_metsig_offshell");
                if (PtlepOverMet < 0.3)
                {
                  SR_WZoff_high_njc = true;
                  countCutflowEvent("227_SR_WZ_highmet_nj_c_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_njc");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 20. && mll_min_offshell <= 30.)
      {
        countCutflowEvent("228_SR_WZ_highmet_nj_d_mll_offshell");
        if (mt2_offshell < 130.)
        {
          countCutflowEvent("229_SR_WZ_highmet_nj_d_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("230_SR_WZ_highmet_nj_d_offshell");
            if (met > 200.)
            {
              countCutflowEvent("231_SR_WZ_highmet_nj_d_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("232_SR_WZ_highmet_nj_d_metsig_offshell");
                if (PtlepOverMet < 0.3)
                {
                  SR_WZoff_high_njd = true;
                  countCutflowEvent("233_SR_WZ_highmet_nj_d_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_njd");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 30. && mll_min_offshell <= 40.)
      {
        countCutflowEvent("234_SR_WZ_highmet_nj_e_mll_offshell");
        if (mt2_offshell < 140.)
        {
          countCutflowEvent("235_SR_WZ_highmet_nj_e_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("236_SR_WZ_highmet_nj_e_offshell");
            if (met > 200.)
            {
              countCutflowEvent("237_SR_WZ_highmet_nj_e_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("238_SR_WZ_highmet_nj_e_metsig_offshell");
                if (PtlepOverMet < 0.3)
                {
                  SR_WZoff_high_nje = true;
                  countCutflowEvent("239_SR_WZ_highmet_nj_e_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_nje");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 40. && mll_min_offshell <= 60.)
      {
        countCutflowEvent("240_SR_WZ_highmet_nj_f_mll_offshell");
        if (mt2_offshell < 160.)
        {
          countCutflowEvent("241_SR_WZ_highmet_nj_f_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("242_SR_WZ_highmet_nj_f_offshell");
            if (met > 200.)
            {
              countCutflowEvent("243_SR_WZ_highmet_nj_f_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("244_SR_WZ_highmet_nj_f_metsig_offshell");
                if (PtlepOverMet < 1.0)
                {
                  SR_WZoff_high_njf = true;
                  countCutflowEvent("245_SR_WZ_highmet_nj_f_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_njf");
                }
              }
            }
          }
        }
      }
      if (mll_min_offshell > 60. && mll_min_offshell <= 75.)
      {
        countCutflowEvent("246_SR_WZ_highmet_nj_g_mll_offshell");
        if (mt2_offshell < 175.)
        {
          countCutflowEvent("247_SR_WZ_highmet_nj_g_mt2_offshell");
          if (jets_30sig.size() > 0)
          {
            countCutflowEvent("248_SR_WZ_highmet_nj_g_offshell");
            if (met > 200.)
            {
              countCutflowEvent("249_SR_WZ_highmet_nj_g_met_offshell");
              if (metsig > 3.)
              {
                countCutflowEvent("250_SR_WZ_highmet_nj_g_metsig_offshell");
                if (PtlepOverMet < 1.0)
                {
                  SR_WZoff_high_njg = true;
                  countCutflowEvent("251_SR_WZ_highmet_nj_g_ptlep_offshell");
                  countSignalEvent("SR_WZoff_high_njg");
                }
              }
            }
          }
        }
      }
    }

    if (SR_WZoff_low_0jb || SR_WZoff_low_0jc || SR_WZoff_low_0jd || SR_WZoff_low_njb || SR_WZoff_low_njc || SR_WZoff_low_njd ||
        SR_WZoff_high_0jb || SR_WZoff_high_0jc || SR_WZoff_high_0jd || SR_WZoff_high_njb || SR_WZoff_high_njc || SR_WZoff_high_njd)
    {
      countSignalEvent("SR_incWZoff_d");
    }
    if (SR_WZoff_low_0jb || SR_WZoff_low_0jc || SR_WZoff_low_0jd || SR_WZoff_low_0je || SR_WZoff_low_njb || SR_WZoff_low_njc || SR_WZoff_low_njd ||
        SR_WZoff_low_nje || SR_WZoff_high_0jb || SR_WZoff_high_0jc || SR_WZoff_high_0jd || SR_WZoff_high_0je || SR_WZoff_high_njb || SR_WZoff_high_njc || SR_WZoff_high_njd || SR_WZoff_high_nje)
    {
      countSignalEvent("SR_incWZoff_e1");
    }
    if (SR_WZoff_low_0jc || SR_WZoff_low_0jd || SR_WZoff_low_0je || SR_WZoff_low_njc || SR_WZoff_low_njd ||
        SR_WZoff_low_nje || SR_WZoff_high_0jc || SR_WZoff_high_0jd || SR_WZoff_high_0je || SR_WZoff_high_njc || SR_WZoff_high_njd || SR_WZoff_high_nje)
    {
      countSignalEvent("SR_incWZoff_e2");
    }
    if (SR_WZoff_low_0jc || SR_WZoff_low_0jd || SR_WZoff_low_0je || SR_WZoff_low_0jf1 || SR_WZoff_low_0jf2 || SR_WZoff_low_njc || SR_WZoff_low_njd ||
        SR_WZoff_low_nje || SR_WZoff_low_njf1 || SR_WZoff_low_njf2 || SR_WZoff_high_0jc || SR_WZoff_high_0jd || SR_WZoff_high_0je || SR_WZoff_high_0jf1 || SR_WZoff_high_0jf2 ||
        SR_WZoff_high_njc || SR_WZoff_high_njd || SR_WZoff_high_nje || SR_WZoff_high_njf)
    {
      countSignalEvent("SR_incWZoff_f1");
    }
    if (SR_WZoff_low_0je || SR_WZoff_low_0jf1 || SR_WZoff_low_0jf2 ||
        SR_WZoff_low_nje || SR_WZoff_low_njf1 || SR_WZoff_low_njf2 || SR_WZoff_high_0je || SR_WZoff_high_0jf1 || SR_WZoff_high_0jf2 ||
        SR_WZoff_high_nje || SR_WZoff_high_njf)
    {
      countSignalEvent("SR_incWZoff_f2");
    }
    if (SR_WZoff_low_0jb || SR_WZoff_low_0jc || SR_WZoff_low_0jd || SR_WZoff_low_0je || SR_WZoff_low_0jf1 || SR_WZoff_low_0jf2 || SR_WZoff_low_0jg1 || SR_WZoff_low_0jg2 || SR_WZoff_low_njb || SR_WZoff_low_njc || SR_WZoff_low_njd ||
        SR_WZoff_low_nje || SR_WZoff_low_njf1 || SR_WZoff_low_njf2 || SR_WZoff_low_njg1 || SR_WZoff_low_njg2 || SR_WZoff_high_0jb || SR_WZoff_high_0jc || SR_WZoff_high_0jd || SR_WZoff_high_0je || SR_WZoff_high_0jf1 || SR_WZoff_high_0jf2 || SR_WZoff_high_0jg1 || SR_WZoff_high_0jg2 ||
        SR_WZoff_high_njb || SR_WZoff_high_njc || SR_WZoff_high_njd || SR_WZoff_high_nje || SR_WZoff_high_njf || SR_WZoff_high_njg)
    {
      countSignalEvent("SR_incWZoff_g1");
    }
    if (SR_WZoff_low_0je || SR_WZoff_low_0jf1 || SR_WZoff_low_0jf2 || SR_WZoff_low_0jg1 || SR_WZoff_low_0jg2 ||
        SR_WZoff_low_nje || SR_WZoff_low_njf1 || SR_WZoff_low_njf2 || SR_WZoff_low_njg1 || SR_WZoff_low_njg2 || SR_WZoff_high_0je || SR_WZoff_high_0jf1 || SR_WZoff_high_0jf2 || SR_WZoff_high_0jg1 || SR_WZoff_high_0jg2 ||
        SR_WZoff_high_nje || SR_WZoff_high_njf || SR_WZoff_high_njg)
    {
      countSignalEvent("SR_incWZoff_g2");
    }
    if (SR_WZoff_low_0jf1 || SR_WZoff_low_0jf2 || SR_WZoff_low_0jg1 || SR_WZoff_low_0jg2 ||
        SR_WZoff_low_njf1 || SR_WZoff_low_njf2 || SR_WZoff_low_njg1 || SR_WZoff_low_njg2 || SR_WZoff_high_0jf1 || SR_WZoff_high_0jf2 || SR_WZoff_high_0jg1 || SR_WZoff_high_0jg2 ||
        SR_WZoff_high_njf || SR_WZoff_high_njg)
    {
      countSignalEvent("SR_incWZoff_g3");
    }
    if (SR_WZoff_low_0jg1 || SR_WZoff_low_0jg2 ||
        SR_WZoff_low_njg1 || SR_WZoff_low_njg2 || SR_WZoff_high_0jg1 || SR_WZoff_high_0jg2 ||
        SR_WZoff_high_njg)
    {
      countSignalEvent("SR_incWZoff_g4");
    }

    if (SR_WZoff_high_0jb || SR_WZoff_high_njb)
    {
      countSignalEvent("SR_incWZoff_high_b");
    }
    if (SR_WZoff_high_0jb || SR_WZoff_high_njb || SR_WZoff_high_0jc || SR_WZoff_high_njc)
    {
      countSignalEvent("SR_incWZoff_high_c");
    }

    if (SR_WZoff_high_nja)
    {
      countSignalEvent("SR_incWZoff_high_nja");
    }
    if (SR_WZoff_high_njb)
    {
      countSignalEvent("SR_incWZoff_high_njb");
    }
    if (SR_WZoff_high_nja || SR_WZoff_high_njb || SR_WZoff_high_njc)
    {
      countSignalEvent("SR_incWZoff_high_njc1");
    }
    if (SR_WZoff_high_njc)
    {
      countSignalEvent("SR_incWZoff_high_njc2");
    }
  }
}

void Atlas_2106_01676::finalize()
{
  // Whatever should be done after the run goes here
}

bool Atlas_2106_01676::check_nTrack_jet(Jet * jet, std::vector<Track *> tracks, int nTracksMin)
{
  int nTracks = 0;
  for (std::vector<Track *>::iterator it = tracks.begin(); it != tracks.end(); it++)
  {
    for (int part = 0; part < jet->Particles.GetEntries(); part++)
    {
      if ((*it)->PT > 0.5 && jet->Particles.At(part) == (*it)->Particle)
      {
        nTracks++;
        break;
      }
    }
  }
  return nTracks > nTracksMin;
}
std::vector<Jet *> Atlas_2106_01676::overlapRemoval_jet_tracks_muon(std::vector<Jet *> cand_jets, std::vector<Muon *> cand_muons, double deltaR, int nTracks)
{
  std::vector<Jet *> passed;
  for (std::vector<Jet *>::iterator jet = cand_jets.begin(); jet != cand_jets.end(); jet++)
  {
    bool match_mu = false;
    for (std::vector<Muon *>::iterator mu = cand_muons.begin(); mu != cand_muons.end(); mu++)
    {
      if ((*jet)->P4().DeltaR((*mu)->P4()) < deltaR)
      {
        match_mu = true;
        break;
      }
    }
    if (check_nTrack_jet(*jet, tracks, nTracks) || !match_mu)
    {
      passed.push_back(*jet);
    }
  }
  return passed;
}