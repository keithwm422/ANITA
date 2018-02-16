// This will plot the dioderms hists for all configs of Tuffs 
#include <iostream>
using namespace std;

void plot_dioderms_all_configs_hists()
{

// declare the stacked hist
//THStack *hS = new THStack("hs","didoerms_stacked");

  TCanvas *c1 = new TCanvas ("C1","c1", 800,800);
// open all 6 config root files
  TFile * _file0= TFile::Open("/home/keith/tuff_dioderms_tests/runA/SimulatedAnitaTruthFile3.root");
  TFile * _file1= TFile::Open("/home/keith/tuff_dioderms_tests/runB/SimulatedAnitaTruthFile3.root");
  TFile * _file2= TFile::Open("/home/keith/tuff_dioderms_tests/runC/SimulatedAnitaTruthFile3.root");
  TFile * _file3= TFile::Open("/home/keith/tuff_dioderms_tests/runG/SimulatedAnitaTruthFile3.root");
  TFile * _file4= TFile::Open("/home/keith/tuff_dioderms_tests/runO/SimulatedAnitaTruthFile3.root");
  TFile * _file5= TFile::Open("/home/keith/tuff_dioderms_tests/runP/SimulatedAnitaTruthFile3.root");
//  TFile * _file6= TFile::Open("/home/mcbride.342/testing_commits/git_test/icemc/units_test/run3_cw_only_noise/SimulatedAnitaTruthFile3.root");

// declare Graphs
  TH1D *h_A = new TH1D("A","A", 25, 0., 1.e-12);
  TH1D *h_B = new TH1D("B","B", 25, 0., 1.e-12);
  TH1D *h_C = new TH1D("C","C", 25, 0., 1.e-12);
  TH1D *h_G = new TH1D("G","G", 25, 0., 1.e-12);
  TH1D *h_O = new TH1D("O","O", 25, 0., 1.e-12);
  TH1D *h_P = new TH1D("P","dioderms", 25, 0., 1.e-12);
//  TH1D *h_X = new TH1D("X","X", 25, 0., 1.e-12);


// get the trees
  _file0->cd();
  TTree *t_A=(TTree*)_file0->Get("triggerSettingsTree");
  h_A->SetMarkerStyle(34);
  h_A->SetLineWidth(3);
  h_A->SetLineColor(1);
  h_A->SetFillColor(1);
  h_A->SetFillStyle(3003);
  _file1->cd();
  TTree *t_B=(TTree*)_file1->Get("triggerSettingsTree");
  h_B->SetMarkerStyle(34);
  h_B->SetLineWidth(3);
  h_B->SetLineColor(2);
  h_B->SetFillColor(2);
  h_B->SetFillStyle(3003);
  _file2->cd();
  TTree *t_C=(TTree*)_file2->Get("triggerSettingsTree");
  h_C->SetMarkerStyle(34);
  h_C->SetLineWidth(3);
  h_C->SetLineColor(3);
  h_C->SetFillColor(3);
  h_C->SetFillStyle(3003);
  _file3->cd();
  TTree *t_G=(TTree*)_file3->Get("triggerSettingsTree");
  h_G->SetMarkerStyle(34);
  h_G->SetLineWidth(3);
  h_G->SetLineColor(4);
  h_G->SetFillColor(4);
  h_G->SetFillStyle(3003);
  _file4->cd();
  TTree *t_O=(TTree*)_file4->Get("triggerSettingsTree");
  h_O->SetMarkerStyle(34);
  h_O->SetLineWidth(3);
  h_O->SetLineColor(14);
  h_O->SetFillColor(14);
  h_O->SetFillStyle(3003);
  _file5->cd();
  TTree *t_P=(TTree*)_file5->Get("triggerSettingsTree");
  h_P->SetMarkerStyle(34);
  h_P->SetLineWidth(3);
  h_P->SetLineColor(6);
  h_P->SetFillColor(6);
  h_P->SetFillStyle(3003);
//  TTree *t_X=(TTree*)_file6->Get("triggerSettingsTree");
//  h_X->SetMarkerStyle(34);
//  h_X->SetLineWidth(3);
//  h_X->SetLineColor(7);
//  h_X->SetFillColor(7);
//  h_X->SetFillStyle(3003);

  double diode_A[576];
  double diode_B[576];
  double diode_C[576];
  double diode_G[576];
  double diode_O[576];
  double diode_P[576];
//  double diode_X[96];

// set branch addresses
  t_A->SetBranchAddress("dioderms",&diode_A);
  t_B->SetBranchAddress("dioderms",&diode_B);
  t_C->SetBranchAddress("dioderms",&diode_C);
  t_G->SetBranchAddress("dioderms",&diode_G);
  t_O->SetBranchAddress("dioderms",&diode_O);
  t_P->SetBranchAddress("dioderms",&diode_P);
//  t_X->SetBranchAddress("dioderms",&diode_X);

  int k=0;  
  while(k<576) {
    t_A->GetEntry(k);
    t_B->GetEntry(k);
    t_C->GetEntry(k);
    t_G->GetEntry(k);
    t_O->GetEntry(k);
    t_P->GetEntry(k);
    k++;
//    t_X->GetEntry(i);
  }



// fill graphs
  for (int j=0; j<96;j++) {
    h_A->Fill(diode_A[j]);
    h_B->Fill(diode_B[j]);
    h_C->Fill(diode_C[j]);
    h_G->Fill(diode_G[j]);
    h_O->Fill(diode_O[j]);
    h_P->Fill(diode_P[j]);
//    h_X->Fill(diode_X[j]);

  }

  h_P->Draw();
  h_B->Draw("same");
  h_G->Draw("same");
  h_C->Draw("same");
  h_O->Draw("same");
  h_A->Draw("same");
//  h_X->Draw("same");
/*
// fill the stack histogram with the dioderms histograms
  hS->Add(h_A);
  hS->Add(h_B);
  hS->Add(h_C);
  hS->Add(h_G);
  hS->Add(h_O);
  hS->Add(h_P);
  hS->Add(h_X);
  hS->Draw();
*/
  leg = new TLegend(0.7,0.5,0.9,0.7);

  leg->AddEntry(h_A,"A");
  leg->AddEntry(h_B,"B");
  leg->AddEntry(h_C,"C");
  leg->AddEntry(h_G,"G");
  leg->AddEntry(h_O,"O");
  leg->AddEntry(h_P,"P");
//  leg->AddEntry(h_X,"no Tuffs");

  leg->Draw("SAME");

  c1->Draw();
  TString filename = Form("diode_rms_all_configs_hists_first96.png");
  c1->SaveAs(filename);

}


