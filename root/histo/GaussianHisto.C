void SomeStat(TH1F *h){
    cout << "\nHisto: " << h->GetName() << endl;
    cout << "Mean : " << h->GetMean()  << " +- " << h->GetMeanError() << endl;
    cout << "StdDiv : " << h->GetStdDev() << " +- " << h->GetStdDevError() << endl;

    for(Int_t i=0;i<h->GetNbinsX()+2;i++){
        if(i==0){ cout << "Underflow bin: " << h->GetBinContent(i) << " entries\n";}
        else if(i==h->GetNbinsX()+1){cout << "Overflow bin: " << h->GetBinContent(i) << " entries\n";}
        else{
            cout << "bin " << i << " : " << h->GetBinContent(i) << " entries\n";
        }
    }
}

void GaussianHisto(){
    TH1F *h10  = new TH1F("h10" ,"Histo's Title;x;y", 10,-3,3);
    TH1F *h10a = new TH1F("h10a","Histo's Title;x;y", 10,-3,3);
    TH1F *h10b = new TH1F("h10b","Histo's Title;x;y", 10,-3,3);
    TH1F *h100 = new TH1F("h100","Histo's Title;x;y",100,-3,3);

    TF1* f1 = new TF1("f1","gaus(0)",-100,100);
    
    f1->SetParameter(0,1);
    f1->SetParameter(1,0);
    f1->SetParameter(2,1);

    h10->FillRandom( "f1", 100000);
    h100->FillRandom( "f1", 100000);
    
    Double_t val;
    for(Int_t j=0;j<100000;j++){

        val = f1->GetRandom();
        h10a->Fill( val );
        if(val>=-3 && val<=3) h10b->Fill(val);
    }

    SomeStat(h10);
    SomeStat(h10a);
    SomeStat(h10b);

    h10->SetLineColor(kRed);
    h10->SetFillColor(kRed);
    h10->SetFillStyle(3005);

    h10->Scale(0.1);
    TCanvas *canv = new TCanvas("canv","title of canv",600,600);
    h10->Draw("HIST");
    h100->Draw("same E");


}