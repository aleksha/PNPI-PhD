{
  TH1F* h = new TH1F("h","Title;x;y",100,0,10);

  for(int i=0;i<10000;i++){
    h->Fill( 10.*gRandom->Rndm() );
  }


  TF1* f = new TF1("f","gaus(0)",0,10);
  f->SetParameter( 0, 1  );
  f->SetParameter( 1, 3  );
  f->SetParameter( 2, 0.2);

  h->FillRandom( "f" , 1000);

  TCanvas* canv1 = new TCanvas("canv1","Soviet canvas",700,700);
  TCanvas* canv2 = new TCanvas("canv2","Soviet canvas",700,700);

  canv1->cd();
  h->Draw();

  canv2->cd();
  f->SetLineColor(4);
  f->SetLineWidth(3);
  f->Draw();

}
