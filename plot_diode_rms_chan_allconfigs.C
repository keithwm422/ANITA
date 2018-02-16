// This will plot the dioderms per channel for all configs of Tuffs 
#include <iostream>
using namespace std;

void plot_diode_rms_chan_allconfigs()
{
  double x[96];
  for (int i =0; i<96; i++){
    x[i]=(double)(i);
  }

// declare the variable arrays for the didoerms in the branches

  double diode_A[96];
//  double diode_B[96];
//  double diode_C[96];
//  double diode_G[96];
//  double diode_O[96];
//  double diode_P[96];
//
  TCanvas *c1 = new TCanvas ("C1","c1", 800,800);
// open all 6 config root files
  TFile * _file0= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/diodeRMSruns/runB/SimulatedAnitaTruthFile3.root");
//  TFile * _file1= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/diodeRMSruns/runB/SimulatedAnitaTruthFile3.root");
//  TFile * _file2= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/diodeRMSruns/runC/SimulatedAnitaTruthFile3.root");
//  TFile * _file3= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/diodeRMSruns/runG/SimulatedAnitaTruthFile3.root");
//  TFile * _file4= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/diodeRMSruns/runO/SimulatedAnitaTruthFile3.root");
//  TFile * _file5= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/diodeRMSruns/runP/SimulatedAnitaTruthFile3.root");
// get the trees
  _file0->cd();
  TTree *t_A=(TTree*)_file0->Get("triggerSettingsTree");
/*

  t_A->SetMarkerStyle(34);
  t_A->SetMarkerSize(1.25);
  t_A->SetMarkerColor(1);
  _file1->cd();
  TTree *t_B=(TTree*)_file0->Get("triggerSettingsTree");
  t_B->SetMarkerStyle(34);
  t_B->SetMarkerSize(1.25);
  t_B->SetMarkerColor(2);
  _file2->cd();
  TTree *t_C=(TTree*)_file0->Get("triggerSettingsTree");
  t_C->SetMarkerStyle(34);
  t_C->SetMarkerSize(1.25);
  t_C->SetMarkerColor(3);
  _file3->cd();
  TTree *t_G=(TTree*)_file0->Get("triggerSettingsTree");
  t_G->SetMarkerStyle(34);
  t_G->SetMarkerSize(1.25);
  t_G->SetMarkerColor(4);
  _file4->cd();
  TTree *t_O=(TTree*)_file0->Get("triggerSettingsTree");
  t_O->SetMarkerStyle(34);
  t_O->SetMarkerSize(1.25);
  t_O->SetMarkerColor(5);
  _file5->cd();
  TTree *t_P=(TTree*)_file0->Get("triggerSettingsTree");
  t_P->SetMarkerStyle(34);
  t_P->SetMarkerSize(1.25);
  t_P->SetMarkerColor(6);
*/

//Set Branch Address and fill the diode arrays
  t_A->SetBranchAddress("dioderms",&diode_A);
//  t_B->SetBranchAddress("dioderms",&diode_B);
//  t_C->SetBranchAddress("dioderms",&diode_C);
//  t_G->SetBranchAddress("dioderms",&diode_G);
//  t_O->SetBranchAddress("dioderms",&diode_O);
//  t_P->SetBranchAddress("dioderms",&diode_P);

  for(int j =0; j<96; j++){
    t_A->GetEntry(j);
//    t_B->GetEntry(j);
//    t_C->GetEntry(j);
//    t_G->GetEntry(j);
//    t_O->GetEntry(j);
//    t_P->GetEntry(j);
  }
//


//Declare hists
  TGraph *gA= new TGraph(96, x, diode_A);
//  TGraph *gB= new TGraph(96, x, diode_B);
//  TGraph *gC= new TGraph(96, x, diode_C);
//  TGraph *gG= new TGraph(96, x, diode_G);
//  TGraph *gO= new TGraph(96, x, diode_O);
//  TGraph *gP= new TGraph(96, x, diode_P);

  gA->Draw();
//  gB->Draw("SAME");
//  gC->Draw("SAME");
//  gG->Draw("SAME");
//  gO->Draw("SAME");
//  gP->Draw("SAME");

/*
  leg = new TLegend(0.1,0.7,0.48,0.9);
  leg->AddEntry(gA,"A");
  leg->AddEntry(gB,"B");
  leg->AddEntry(gC,"C");
  leg->AddEntry(gG,"G");
  leg->AddEntry(gO,"O");
  leg->AddEntry(gP,"P");
  leg->Draw("SAME");
*/
  c1->Draw();
  TString filename = Form("diode_rms_channel_configB.png");
  c1->SaveAs(filename);

}
