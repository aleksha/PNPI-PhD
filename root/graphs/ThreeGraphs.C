void ThreeGraphs(){
   TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",600,900);
   Double_t   x[100],   y[100];
   Double_t  ex[100],  ey[100];
   Double_t exl[100], eyl[100]; // low
   Double_t exh[100], eyh[100]; // high
   Int_t n = 20;
   for (Int_t i=0;i<n;i++) {
     x[i]   = i*0.1;
     ex[i]  = 0.06;
     exl[i] = 0.06;
     exh[i] = 0.03;
     y[i] = 10*sin(x[i]+0.2);
     ey[i]  = y[i]*0.2;
     eyl[i] = y[i]*0.2;
     eyh[i] = y[i]*0.1;
   }

   TGraph*            gr   = new TGraph(n,x,y);
   TGraphErrors*      gre  = new TGraphErrors(n,x,y,ex,ey);
   TGraphAsymmErrors* grae = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);

   gr->SetTitle("TGraph");
   gre->SetTitle("TGraphErrors");
   grae->SetTitle("TGraphAsymmErrors");

   gr->SetLineStyle(9);
   gr->SetLineWidth(3);

   gre->SetMarkerStyle(24);
   grae->SetMarkerStyle(20);

   grae->SetMarkerColor(kGreen+3);
   grae->SetLineColor(kGreen+3);
   grae->SetLineWidth(2);

   c1->Divide(1,3);
   c1->cd(1);
   gr->Draw("AL");
   gr->Fit("pol2");
   c1->cd(2);
   gre->Draw("APE");
   gre->Fit("pol2");
   c1->cd(3);
   grae->Draw("APE");
   grae->Fit("pol2");

}