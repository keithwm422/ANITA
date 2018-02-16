// This file plots the 7 config convolved with tuff outputs
#include "TFile.h"
#include "TMath.h"
#include "TString.h"
#include "TGraph.h"
#include <stdio.h>
#include <sys/stat.h>
#include <iostream>

void plot_trigger_tuffs()
{
//        string config = "A";
        TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);

        TString impname;
                impname = Form("%s/share/AnitaAnalysisFramework/responses/TUFFs/trigconfigP.imp", getenv("ANITA_UTIL_INSTALL_DIR"));

        TGraph td(impname);
        td.Draw();
        c1->SaveAs(Form("trigger_tuff_configP.png"));


}
