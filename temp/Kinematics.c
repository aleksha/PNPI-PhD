const int N=100;

double momentum(double E, double m){
    return(sqrt(E*E-m*m));
}

void Kinematics(){
 
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


 cout << "CMS: \n";
 cout << "Check X: " << Beam_cms.Px() << "\t" << Target_cms.Px() << "\n";
 cout << "Check Y: " << Beam_cms.Py() << "\t" << Target_cms.Py() << "\n";
 cout << "Check Z: " << Beam_cms.Pz() << "\t" << Target_cms.Pz() << "\n";
 cout << "Check E: " << Beam_cms.E()  << "\t" << Target_cms.E()  << "\n";

 //Beam_cms.Boost(boost_vector);
 //Target_cms.Boost(boost_vector);
 //cout << "LAB: \n";
 //cout << "Check X: " << Beam_cms.Px() << "\t" << Target_cms.Px() << "\n";
 //cout << "Check Y: " << Beam_cms.Py() << "\t" << Target_cms.Py() << "\n";
 //cout << "Check Z: " << Beam_cms.Pz() << "\t" << Target_cms.Pz() << "\n";
 //cout << "Check E: " << Beam_cms.E()  << "\t" << Target_cms.E()  << "\n";

 double E_e[N], si[N], ti[N], theta_e[N], theta_mu[N], E_mu[N];
 double p_e[N], xsec[N];

 for(int i=0;i<N;i++){
     E_e[i]=1.+i;
     p_e[i] = momentum(E_e[1],m_e);
     //Electron.SetPxPyPzE();
 }

 double xs;
 int ii=0;
 for(double theta_cms=1; theta_cms<101; theta_cms+=1 ){
     s = Init_lab.M2();
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

     ii++;

     cout << "---> " << theta_cms << "   " << Mu_lab.E() << "   " << Electron_lab.E()
          <<"     " << 1000.*Mu_lab.Theta() << "  "  << 1000.*Electron_lab.Theta() 
          <<" mrad      " << s << "  "  << t << "   " << xs << " mb \n";
//     cout <<"     " << Mu_lab.Pt()/Mu_lab.P()  << "\n\n";

 }

gr_e      = new TGraph(N,E_e ,theta_e);
gr_mu     = new TGraph(N,E_mu,theta_mu);
gr_angle  = new TGraph(N,theta_e,theta_mu);
gr_energy = new TGraph(N,E_e,E_mu);
gr_t      = new TGraph(N,E_e,ti);
gr_xs     = new TGraph(N,E_e,xsec);

gr_e->SetTitle("");
gr_mu->SetTitle("");
gr_angle->SetTitle("");
gr_energy->SetTitle("");
gr_t->SetTitle("");
gr_xs->SetTitle("");

gr_e->SetLineWidth(2);
gr_mu->SetLineWidth(2);
gr_angle->SetLineWidth(2);
gr_energy->SetLineWidth(2);
gr_t->SetLineWidth(2);
gr_xs->SetLineWidth(2);

gr_e->GetXaxis()->SetTitle("Electron energy, GeV");
gr_mu->GetXaxis()->SetTitle("Muon energy, GeV");
gr_angle->GetXaxis()->SetTitle("#theta_{e}, mrad");
gr_energy->GetXaxis()->SetTitle("Electron energy, GeV");
gr_t->GetXaxis()->SetTitle("Electron energy, GeV");
gr_xs->GetXaxis()->SetTitle("Electron energy, GeV");

gr_e->GetYaxis()->SetTitle("#theta_{e}, mrad");
gr_mu->GetYaxis()->SetTitle("#theta_{#mu}, mrad");
gr_angle->GetYaxis()->SetTitle("#theta_{#mu}, mrad");
gr_energy->GetYaxis()->SetTitle("Muon energy, GeV");
gr_t->GetYaxis()->SetTitle("t invariant, GeV^{2}");
gr_xs->GetYaxis()->SetTitle("Cross section, [a.u.]");

TCanvas *canv= new TCanvas("canv","canv", 900,600);
canv->Divide(3,2);
canv->cd(1);
gPad->SetLogy();
gr_e->Draw("AL");
canv->cd(4);
gr_mu->Draw("AL");
canv->cd(2);
gr_angle->Draw("AL");
canv->cd(5);
gr_energy->Draw("AL");
canv->cd(3);
gr_t->Draw("AL");
canv->cd(6);
gPad->SetLogy();
gr_xs->Draw("AL");


}