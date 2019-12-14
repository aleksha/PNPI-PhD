#include <iostream>
#include "TCanvas.h"
#include "TH1F.h"
#include "TRandom.h"
#include "TApplication.h"

using namespace std;

TCanvas *canv;
TH1F *h;

void test()
{
  TRandom *rnd = new TRandom(time(0));
  Double_t x = rnd->Rndm();
  cout << "x = " << x << endl;
}

void hello()
{
  cout << "hello world!" << endl;
}

#ifndef __CINT__
int main(int argc, char** argv)
{
  TApplication theApp("App",&argc, argv);
  hello();
  test();
  int a;
  canv = new TCanvas();
  h = new TH1F("h",";x;y",10,0,10);
  h->Fill(5.5);
  h->Draw();
  canv->Update();
  canv->Print("canv.png");
  cin >> a ;
  canv->Close();
  theApp.Run();
  return 0;
}
#endif
