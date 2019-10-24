#include "TSystem.h"
#include "TRandom.h"
#include "TH1F.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TFile.h"


double func(double x){
 return(x);
}

void macro3(){
  TH1F* h = new TH1F("h","Title;x;y",100,0,10);


  Double_t x,y;

  for(int i=0;i<100000000;i++){
    if(!(i%10000000)){ std::cout << i << std::endl; }
    h->Fill( 10.*gRandom->Rndm() );
    if( !(i%2) ){
       x = 10.*gRandom->Rndm();
       y = 10.*gRandom->Rndm();
       if( func(x)>y ){
         h->Fill( x );
      }
    }
  }


  TF1* f = new TF1("f","gaus(0)",0,10);
  f->SetParameter( 0, 1  );
  f->SetParameter( 1, 3  );
  f->SetParameter( 2, 0.2);

  h->FillRandom( "f" , 10000000);

  TCanvas* canv1 = new TCanvas("canv1","Soviet canvas",700,700);
  // canv1->Divide(2); vertical division
  // canv1->Divide(1,2); horizontal division
  canv1->Divide(2,2); // 4 object TPad

  canv1->cd(1);
  h->SetLineColor(2);
  h->SetFillColor(2);
  h->SetFillStyle(3005);
  h->Draw();

  canv1->cd(2);
  f->SetLineColor(4);
  f->SetLineWidth(3);
  f->Draw();

//  canv1->Print("figure.png");

//  TFile* file = new TFile("file.root","RECREATE");
//  h->Write();
//  canv1->Write();
//  file->Close();

//  gSystem->Exit(0);

}
