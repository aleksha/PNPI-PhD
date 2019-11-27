const int N=100;
const int Nevents=1000;
TTree *tree;
TFile *rfile;

double momentum(double E, double m){
    return(sqrt(E*E-m*m));
}

void GenHit(){

 double theta_cms = 39.;
 
 //ntupe = new TNtuple()
 rfile = new TFile("MyEvents.root","RECREATE");
 tree = new TTree("tree","tree");
 Double_t x,y;
 tree->Branch("x",&x,"x/D"); 
 tree->Branch("y",&y,"y/D");

 double m_e  = 0.000510999;
 double m_mu = 0.105658375;
 double E_beam=100.; // GeV
 double p_beam = momentum(E_beam,m_mu);
 double s,t,u;

 TLorentzVector Beam_lab, Target_lab, Mu_lab, Electron_lab, Init_lab;
 TLorentzVector Beam_cms, Target_cms, Mu_cms, Electron_cms, Init_cms;

 Beam_lab.SetPxPyPzE(0,0,p_beam,E_beam);
 Target_lab.SetPxPyPzE(0,0,0,m_e);
 Init_lab = Beam_lab + Target_lab;

 TVector3 boost_vector = Init_lab.BoostVector();

 Beam_cms = Beam_lab; Target_cms = Target_lab;
 Beam_cms.Boost(-boost_vector);
 Target_cms.Boost(-boost_vector);

 

 double E_e[N], si[N], ti[N], theta_e[N], theta_mu[N], E_mu[N];
 double p_e[N], xsec[N];

 for(int i=0;i<N;i++){
     E_e[i]=1.+i;
     p_e[i] = momentum(E_e[1],m_e);
     //Electron.SetPxPyPzE();
 }

 double xs;
 int ii=0;
 for(int ii=0;ii<Nevents;ii++ ){
/*      s = Init_lab.M2();
     tx_rad = TMath::Pi()*theta_cms/180.;
     Mu_cms      .SetPxPyPzE( 0, sin(tx_rad)*Beam_cms.P(), cos(tx_rad)*Beam_cms.P(),     Beam_cms.E() );
     Electron_cms.SetXYZM( -Mu_cms.Px(), -Mu_cms.Py(), -Mu_cms.Pz(), m_e );

     t = (Beam_cms - Mu_cms).M2();

     Mu_lab = Mu_cms; Electron_lab = Electron_cms;
     
     Mu_lab.Boost(boost_vector);
     Electron_lab.Boost(boost_vector);
     xs = 0.389379*pow(1./137.,2)*pow((s*s+s*t+t*t)/(s*t),2)/s;

     ti[ii]=t; si[ii]=s;
     theta_mu[ii]= 1000.*Mu_lab.Theta();
     theta_e[ii] = 1000.*Electron_lab.Theta();
     E_mu[ii] = Mu_lab.E();
     E_e[ii]  = Electron_lab.E();
     xsec[ii]=xs;
 */



      x=gRandom->Gaus(0,0.016);
      y=gRandom->Gaus(0,0.016);

      tree->Fill();
 }

 tree->Write();
 rfile->Close();


}