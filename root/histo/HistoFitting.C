
void SomeFitter(TH1F *h, TString fitter = "Minuit2", TString opts = ""){
   TVirtualFitter::SetDefaultFitter(fitter);
   gStyle->SetOptStat(1111111);
   gStyle->SetOptFit(1111111);
   TCanvas * canv = new TCanvas("canv",fitter+opts,600,600); 
   h->Fit("gaus",opts);
   h->Draw();
   canv->Print(fitter+opts+".png");
   canv->Close();
}

void HistoFitting(int N=1000){

// For Minuit2 minimizer 
   TH1F * h1m = new TH1F("h1m","Minuit2 (chi2)",100, -5, 5. );
   TH1F * h2m = new TH1F("h2m","Minuit2 (chi2 + minos error)",100, -5, 5. );
   TH1F * h3m = new TH1F("h3m","Minuit2 (chi2 + minos + integral)",100, -5, 5. );
   TH1F * h4m = new TH1F("h4m","Minuit2 (likelihood + minos)",100, -5, 5. );

// For Fumili2 minimizer
   TH1F * h1f = new TH1F("h1f","Fumili2 (chi2)",100, -5, 5. );
   TH1F * h2f = new TH1F("h2f","Fumili2 (chi2 + minos error)",100, -5, 5. );
   TH1F * h3f = new TH1F("h3f","Fumili2 (chi2 + minos + integral)",100, -5, 5. );
   TH1F * h4f = new TH1F("h4f","Fumili2 (likelihood + minos)",100, -5, 5. );

// TRandom3
   TRandom3 * r3 = new TRandom3();
   r3->SetSeed(34956);

   Double_t x;
   for (int ii=0; ii<N;ii++) {
      x = r3->Gaus(0,1);
      h1m->Fill( x );
      h2m->Fill( x );
      h3m->Fill( x );
      h4m->Fill( x );

      h1f->Fill( x );
      h2f->Fill( x );
      h3f->Fill( x );
      h4f->Fill( x );
   }

   SomeFitter(h1m,"Minuit2","Q");
   SomeFitter(h2m,"Minuit2","VE");
   SomeFitter(h3m,"Minuit2","IE");
   SomeFitter(h4m,"Minuit2","VLE");

   SomeFitter(h1f,"Fumili2","Q");
   SomeFitter(h2f,"Fumili2","VE");
   SomeFitter(h3f,"Fumili2","IE");
   SomeFitter(h4f,"Fumili2","VLE");

   gSystem->Exit(0);
}