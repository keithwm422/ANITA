// This will calculate the RMS for each channel and then plot all of those RMS's in a histogram. 
#include <iostream>
#include <fstream>
using namespace std;

void RMS_fVolts_calc()
{
  cout << "starting " << endl;

  TCanvas *c1 = new TCanvas ("C1","c1", 800,800);

  TFile * _file2= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/thermal_noise/rmsRun200_TUFF_260_375_0.root");

  _file2->cd();
  TString histname = Form("ant");

  TH1D *h = new TH1D ("RMS","RMS", 200, 0.0, 100.0);
  TH1D *h_1= 0;
  for(int i=0;i<96;i++){

    histname = Form("ant%d" , i);
    _file2->GetObject(histname, h_1);
    h->Add(h_1);

  }

  double norm_1 = 1;
  double scale_1 = norm_1/(h->Integral());
  h->Scale(scale_1);


//  h->Draw("HIST");
//  c1->Draw();
//  TString filename = Form("RMS_andrew_sum.png");
//  c1->SaveAs(filename);








  TH1D *h_mean = new TH1D("A","A", 50, -20., 20.);
  TH1D *h_rms = new TH1D("RMS","fVolts RMS", 60, 0.0, 30.);
  TH1D *h_rms_1 = new TH1D("RMS","fVolts RMS", 60, 0.0, 30.);
  TH1D *h_std = new TH1D("A","A", 50, -20., 20.);
  h_mean->SetMarkerStyle(34);
  h_mean->SetLineWidth(3);
  h_mean->SetLineColor(1);
  h_std->SetMarkerStyle(34);
  h_std->SetLineWidth(3);
  h_std->SetLineColor(3);
  h_rms->SetMarkerStyle(34);
  h_rms->SetLineWidth(3);
  h_rms->SetLineColor(2);
  h_rms_1->SetMarkerStyle(34);
  h_rms_1->SetLineWidth(3);
  h_rms_1->SetLineColor(4);


  TFile * _file0= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/thermal_noise/run3/SimulatedAnitaEventFile3.root");
  TFile * _file1= TFile::Open("/home/keith/anitaBuildTool/components/anitaMagicDisplay/macros/thermal_noise/run3_2/SimulatedAnitaEventFile3.root");

  _file0->cd();
  TTree *t_A=(TTree*)_file0->Get("eventTree");
  _file1->cd();
  TTree *t_B=(TTree*)_file1->Get("eventTree");
  cout << " got here " << endl;
  double fVolts[108][260];
  double fVolts_1[108][260];

  UsefulAnitaEvent* event= NULL;
  UsefulAnitaEvent* event_1= NULL;
  t_A->SetBranchAddress("event",&event);
  t_B->SetBranchAddress("event",&event_1);
//  t_A->SetBranchAddress("fVolts[108][260]",&fVolts);
// loop over all events

    for(int i=0;i<41;i++){
    t_A->GetEntry(i);
    t_B->GetEntry(i);

    cout << "got here " << endl;

    for(int k=0;k<108;k++){
      for(int j=0; j<260;j++){
        fVolts[k][j] = event->fVolts[k][j];
        fVolts_1[k][j] = event_1->fVolts[k][j];

      }
//      cout << event->fVolts[k][0] << endl;
    }

/*  for (int k=0;k<28080;k++){
    t_A->GetEntry(k);
    if(k<108){
      cout << " k is " << k  << " fVolts in channel 0 first 108 is " << fVolts[0][k] << endl;
    }
  }
*/

  double  fVolts_mean[108];
  double fVolts_sum =0.0;
  double fVolts_sum_1 =0.0;
// calc Mean

    for(int l=0;l<108;l++){
      fVolts_sum=0.0;
      for (int j=0;j<260;j++){
        fVolts_sum+=fVolts[l][j];
      }
      fVolts_mean[l]=fVolts_sum/260.0;
      //cout << "channel " << l << " has mean " << fVolts_sum/260.0 << endl;
    }

// Calc std
  double fVolts_std[108];

    for(int i=0; i<108; i++){
      fVolts_sum=0.0;
      for(int k=0;k<260;k++){
        fVolts_sum += (fVolts[i][k]-fVolts_mean[i])*(fVolts[i][k]-fVolts_mean[i]);
      }
      fVolts_std[i]=sqrt(fVolts_sum/260.0);
 //     cout << "channel " << i << " has std " << sqrt(fVolts_sum/260.0) << endl;
    }

// Calc RMS
  double fVolts_rms[108];
  double fVolts_rms_1[108];

    for(int i=0; i<108; i++){
      fVolts_sum=0.0;
      fVolts_sum_1=0.0;
      for(int k=0;k<260;k++){
        fVolts_sum += (fVolts[i][k])*(fVolts[i][k]);
        fVolts_sum_1 += (fVolts_1[i][k])*(fVolts_1[i][k]);

      }
      fVolts_rms[i]=sqrt(fVolts_sum/260.0);
      fVolts_rms_1[i]=sqrt(fVolts_sum_1/260.0);
    }

// fill histogram

    for(int k=0;k<108;k++){
      h_mean->Fill(fVolts_mean[k]);
      h_std->Fill(fVolts_std[k]);
      h_rms->Fill(fVolts_rms[k]);
      h_rms_1->Fill(fVolts_rms_1[k]);
 //     if(i==0){
   //     h_rms_1->Fill(fVolts_rms[k]);
  //    }

    }
    cout << "rms is " << fVolts_rms[0] << endl;
}

  double norm = 1;
  double scale = norm/(h_mean->Integral());
  h_mean->Scale(scale);
  scale = norm/(h_std->Integral());
  h_std->Scale(scale);
  scale = norm/(h_rms->Integral());
  h_rms->Scale(scale);
  scale = norm/(h_rms_1->Integral());
  h_rms_1->Scale(scale);


  h_mean->Draw("HIST");
  c1->Draw();
  TString filename = Form("RMS_fVolts_mean_1.png");
  c1->SaveAs(filename);


  h_rms_1->SetAxisRange(0.0, 0.16, "Y");
  h_rms_1->Draw("HIST");
  h_rms->Draw("sameHIST");
  h->Draw("sameHIST");

  leg = new TLegend(0.7,0.5,0.9,0.7);

  leg->AddEntry(h,"data");
  leg->AddEntry(h_rms,"Simulation 0.8");
  leg->AddEntry(h_rms_1,"Simulation 0.9");
  leg->Draw("same");

  c1->Draw();
  filename = Form("RMS_fVolts_rms_3.png");
  c1->SaveAs(filename);


  h_std->Draw("HIST");
  c1->Draw();
  filename = Form("RMS_fVolts_std_1.png");
  c1->SaveAs(filename);


}


