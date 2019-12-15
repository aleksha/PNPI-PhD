//------------------------------------------------------------------------------
// Author : Alexey Dzyuba
// Date   : 2016-03-04
// E-Mail : a.dzyuba@gmail.com
//------------------------------------------------------------------------------


// kinematic lambda function
double lambda (double x, double y, double z)
{
  double T;
  T=x*x+y*y+z*z-2.*x*y-2.*x*z-2.*y*z ; 
  return (T);
}

double sqrt_l (double x, double y, double z)
{
  double T;
  T=sqrt(lambda(x,y,z));
  return (T);
}

double G_func (double x, double y, double z, double u, double v, double w)
{
  double T;
  T =     x*x*y + x*y*y + z*z*u + z*u*u + v*v*w + v*w*w ;
  T = T + x*z*w + x*u*v + y*z*w + y*u*w                 ;
  T = T - x*y*( z + u + v + w )                         ;
  T = T - z*u*( x + y + v + w )                         ;
  T = T - v*w*( x + y + z + u )                         ;
  return (T);
}


double theta2p(double theta, double p_a, double m_a, double m_b ){

    if(m_a>m_b) cout << "ERROR!!! this function is valid ONLY when m_beam <= m_target" << endl;

    double E_a = sqrt( pow(p_a,2) + pow(m_a,2) ) ; 
    
    double p ; 
    p = (m_b*E_a+m_a*m_a)*cos(theta) ;
    p = p + (E_a+m_b)*sqrt( pow(m_b,2) - pow(m_a*sin(theta),2) ) ; 
    p = p * p_a / ( pow(E_a+m_b ,2) - pow(p_a*cos(theta),2) ) ;
    
    return p ;

}

double Ge2_dipole(double t){
    // Dipole paramettrization for G_e
    double Ge = 1. / (1. - t /0.71 ) ;
    return pow(Ge,2) ;
}

double Gm2_dipole(double t){
    // Dipole paramettrization for G_m
    return pow(sqrt(Ge2_dipole(t))*2.79,2);
}

double Ge2_Kelly(double Q2, double m_b){
    // Kelly parametrization for Ge
    // PRC 70, 068202
    double t = Q2 / pow(2.*m_b,2);
    double Ge = (1. - 0.24 * t ) / (1. + 10.98*t + 12.82*t*t + 21.97*t*t*t ) ; 
    return pow(Ge,2) ;
}

double Gm2_Kelly(double Q2, double m_b){
    // Kelly parametrization for Gm
    // PRC 70, 068202
    double t = Q2 / pow(2.*m_b,2);
    double Gm = (1. + 0.12 * t ) / (1. + 10.97*t + 18.86*t*t + 6.55*t*t*t ) ; 
    return pow(Gm*2.79284735,2);
}

double XS_Rutherford( 
           double p             , 
           double theta_deg     ,  
           TString lepton = "mu" ){

    double PI = TMath::Pi();
    double R2D = 180./PI;
    double D2R = 1./R2D;

    double alpha  = 1./137. ; // fine structure constatn
    double GeV2mb = 0.38939 ; // inverse GeV^2 to mb  : 0.38939 mb = 1/GeV^2
    double GeV2fm = 0.19733 ; // inverse GeV   to fm  : 0.19733 fm = 1/GeV

    double m_e    = 0.000511 ; // mass of electron
    double m_mu   = 0.105658 ; // mass of muon
    double M      = 0.938272 ; // mass of proton
    
    double m     ; // mass of lepton
    double theta ; // lepton scatterring angle in lab frame in rad.
    if(lepton == "mu"){ m = m_mu; }
    else              { m = m_e ; }

    theta = theta_deg * D2R;


    double E  = sqrt( p*p  + m*m )       ; // initial energy of lepton in lab frame
    double sig ; // no structure cross section from Ref. Eq.2
    
    sig = GeV2mb * pow( alpha / (2.*E*pow(sin(0.5*theta),2)) , 2 ) ;

    return sig;

}

double XS_Mott( 
           double p             , 
           double theta_deg     ,  
           TString lepton = "mu" ){

// Caclulate lepton-proton elastic scattering cross section according
// Edith Borie
// lepton    : {electron, muon}
// p         : lepton momentum in lab frame [GeV/c]
// theta_deg : lepton scatterring angle in lab frame [deg.]
// ff        : parametrization of proton form factors
//           : {"Kelly","dipole"}

    double PI = TMath::Pi();
    double R2D = 180./PI;
    double D2R = 1./R2D;

    double alpha  = 1./137. ; // fine structure constatn
    double GeV2mb = 0.38939 ; // inverse GeV^2 to mb  : 0.38939 mb = 1/GeV^2
    double GeV2fm = 0.19733 ; // inverse GeV   to fm  : 0.19733 fm = 1/GeV

    double m_e    = 0.000511 ; // mass of electron
    double m_mu   = 0.105658 ; // mass of muon
    double M      = 0.938272 ; // mass of proton
    
    double m     ; // mass of lepton
    double theta ; // lepton scatterring angle in lab frame in rad.
    if(lepton == "mu"){ m = m_mu; }
    else              { m = m_e ; }

    theta = theta_deg * D2R;


    double E  = sqrt( p*p  + m*m )       ; // initial energy of lepton in lab frame
    double sig ; // no structure cross section from Ref. Eq.2
    
    sig = GeV2mb * pow( alpha * cos(0.5*theta) / (2.*E*pow(sin(0.5*theta),2)) , 2 ) ;

    return sig;

}

double XS_Mott_rec( 
           double p             , 
           double theta_deg     ,  
           TString lepton = "mu" ){

// Caclulate lepton-proton elastic scattering cross section according
// Edith Borie
// lepton    : {electron, muon}
// p         : lepton momentum in lab frame [GeV/c]
// theta_deg : lepton scatterring angle in lab frame [deg.]
// ff        : parametrization of proton form factors
//           : {"Kelly","dipole"}

    double PI = TMath::Pi();
    double R2D = 180./PI;
    double D2R = 1./R2D;

    double alpha  = 1./137. ; // fine structure constatn
    double GeV2mb = 0.38939 ; // inverse GeV^2 to mb  : 0.38939 mb = 1/GeV^2
    double GeV2fm = 0.19733 ; // inverse GeV   to fm  : 0.19733 fm = 1/GeV

    double m_e    = 0.000511 ; // mass of electron
    double m_mu   = 0.105658 ; // mass of muon
    double M      = 0.938272 ; // mass of proton
    
    double m     ; // mass of lepton
    double theta ; // lepton scatterring angle in lab frame in rad.
    if(lepton == "mu"){ m = m_mu; }
    else              { m = m_e ; }

    theta = theta_deg * D2R;


    double E  = sqrt( p*p  + m*m )       ; // initial energy of lepton in lab frame
    double p1 = theta2p(theta, p, m, M) ; // scattered lepton momentum in lab frame
    double E1 = sqrt(p1*p1 + m*m )       ; // scattered lepton energy in lab frame
    
    double sig ; // no structure cross section from Ref. Eq.2
    
    sig = GeV2mb * pow( alpha * cos(0.5*theta) / (2.*E*pow(sin(0.5*theta),2)) , 2 ) ;
    sig = sig * (E1/E);

    return sig;

}

double XS_point( 
           double p             , 
           double theta_deg     ,  
           TString lepton = "mu" ){

// Caclulate lepton-proton elastic scattering cross section according
// Edith Borie
// lepton    : {electron, muon}
// p         : lepton momentum in lab frame [GeV/c]
// theta_deg : lepton scatterring angle in lab frame [deg.]
// ff        : parametrization of proton form factors
//           : {"Kelly","dipole"}

    double PI = TMath::Pi();
    double R2D = 180./PI;
    double D2R = 1./R2D;

    double alpha  = 1./137. ; // fine structure constatn
    double GeV2mb = 0.38939 ; // inverse GeV^2 to mb  : 0.38939 mb = 1/GeV^2
    double GeV2fm = 0.19733 ; // inverse GeV   to fm  : 0.19733 fm = 1/GeV

    double m_e    = 0.000511 ; // mass of electron
    double m_mu   = 0.105658 ; // mass of muon
    double M      = 0.938272 ; // mass of proton
    
    double m     ; // mass of lepton
    double theta ; // lepton scatterring angle in lab frame in rad.
    if(lepton == "mu"){ m = m_mu; }
    else              { m = m_e ; }

    theta = theta_deg * D2R;
    
    double m2 = m*m ; 
    double M2 = M*M ;

    double E  = sqrt(p *p  + m2 )       ; // initial energy of lepton in lab frame

    double p1 = theta2p(theta, p, m, M) ; // scattered lepton momentum in lab frame
    double E1 = sqrt(p1*p1 + m2 )       ; // scattered lepton energy in lab frame

    // Mandelstam variables
    double s  = pow(E+M,2) - pow(p,2) ;
    double t  = 2.*( m2 - E*E1 + p*p1*cos(theta) ) ;  
    double u  = 2.*(m2 + M2) - s - t ;
    
 
    double p_cms = 0.5 * sqrt( lambda(s,m2,M2)  / s ) ; // momentum of lepton and proton in cms frame


    double sig ; // no structure cross section from Ref. Eq.2
    
    sig = GeV2mb * pow( alpha / (2.*E*pow(sin(0.5*theta),2)) , 2 ) *(E1/E) ;
    sig = sig * ( pow(cos(0.5*theta),2) - 0.5*pow(sin(0.5*theta),2) * t / M2  );


    return sig;

}

double XS0q2( 
           double p             , 
           double theta_deg     ,  
           TString lepton = "mu" ){

// Caclulate lepton-proton elastic scattering cross section according
// Edith Borie
// lepton    : {electron, muon}
// p         : lepton momentum in lab frame [GeV/c]
// theta_deg : lepton scatterring angle in lab frame [deg.]
// ff        : parametrization of proton form factors
//           : {"Kelly","dipole"}

    double PI = TMath::Pi();
    double R2D = 180./PI;
    double D2R = 1./R2D;

    double alpha  = 1./137. ; // fine structure constatn
    double GeV2mb = 0.38939 ; // inverse GeV^2 to mb  : 0.38939 mb = 1/GeV^2
    double GeV2fm = 0.19733 ; // inverse GeV   to fm  : 0.19733 fm = 1/GeV

    double m_e    = 0.000511 ; // mass of electron
    double m_mu   = 0.105658 ; // mass of muon
    double M      = 0.938272 ; // mass of proton
    
    double m     ; // mass of lepton
    double theta ; // lepton scatterring angle in lab frame in rad.
    if(lepton == "mu"){ m = m_mu; }
    else              { m = m_e ; }

    theta = theta_deg * D2R;
    
    double m2 = m*m ; 
    double M2 = M*M ;

    double E  = sqrt(p *p  + m2 )       ; // initial energy of lepton in lab frame

    double p1 = theta2p(theta, p, m, M) ; // scattered lepton momentum in lab frame
    double E1 = sqrt(p1*p1 + m2 )       ; // scattered lepton energy in lab frame

    // Mandelstam variables
    double s  = pow(E+M,2) - pow(p,2) ;
    double t  = 2.*( m2 - E*E1 + p*p1*cos(theta) ) ;  
    double u  = 2.*(m2 + M2) - s - t ;
    
 
    double p_cms = 0.5 * sqrt( lambda(s,m2,M2)  / s ) ; // momentum of lepton and proton in cms frame

    double Ge2,Gm2;
    
    Ge2 = Ge2_dipole( 0 );
    Gm2 = Gm2_dipole( 0 );

    double sig_ns ; // no structure cross section from Ref. Eq.2
    
    sig_ns = GeV2mb * pow( alpha / t , 2 ) ;
    sig_ns = sig_ns * (p1/p) / ( 1. + (E - (p*E1/p1)*cos(theta) ) / M );

    double Rm, Re ; 
    Re = Ge2 *   ( 4.*E*E1 + t ) / ( 1 - 0.25*t/M2 );
    Rm = Gm2 * ( ( 4.*E*E1 + t ) * ( 1. - 1./ ( 1 - 0.25*t/M2 ) ) + 0.5*t*t/M2 + t*m2/M2 ) ;

    double                     sig = sig_ns * ( Re + Rm ) ;

    return sig;

}

double XS( 
           double p             , 
           double theta_deg     ,  
           TString lepton = "mu", 
           TString ff="dipole"  , 
           TString mode = "full" ){

// Caclulate lepton-proton elastic scattering cross section according
// Edith Borie
// lepton    : {electron, muon}
// p         : lepton momentum in lab frame [GeV/c]
// theta_deg : lepton scatterring angle in lab frame [deg.]
// ff        : parametrization of proton form factors
//           : {"Kelly","dipole"}

    double PI = TMath::Pi();
    double R2D = 180./PI;
    double D2R = 1./R2D;

    double alpha  = 1./137. ; // fine structure constatn
    double GeV2mb = 0.38939 ; // inverse GeV^2 to mb  : 0.38939 mb = 1/GeV^2
    double GeV2fm = 0.19733 ; // inverse GeV   to fm  : 0.19733 fm = 1/GeV

    double m_e    = 0.000511 ; // mass of electron
    double m_mu   = 0.105658 ; // mass of muon
    double M      = 0.938272 ; // mass of proton
    
    double m     ; // mass of lepton
    double theta ; // lepton scatterring angle in lab frame in rad.
    if(lepton == "mu"){ m = m_mu; }
    else              { m = m_e ; }

    theta = theta_deg * D2R;
    
    double m2 = m*m ; 
    double M2 = M*M ;

    double E  = sqrt(p *p  + m2 )       ; // initial energy of lepton in lab frame

    double p1 = theta2p(theta, p, m, M) ; // scattered lepton momentum in lab frame
    double E1 = sqrt(p1*p1 + m2 )       ; // scattered lepton energy in lab frame

    // Mandelstam variables
    double s  = pow(E+M,2) - pow(p,2) ;
    double t  = 2.*( m2 - E*E1 + p*p1*cos(theta) ) ;  
    double u  = 2.*(m2 + M2) - s - t ;
    
 
    double p_cms = 0.5 * sqrt( lambda(s,m2,M2)  / s ) ; // momentum of lepton and proton in cms frame

    double Ge2,Gm2;
    
    if(ff == "Kelly"){
        Ge2 = Ge2_Kelly( -t, M );
        Gm2 = Gm2_Kelly( -t, M );
    }
    else{
        Ge2 = Ge2_dipole( t );
        Gm2 = Gm2_dipole( t );
    }

    double sig_ns ; // no structure cross section from Ref. Eq.2
    
    sig_ns = GeV2mb * pow( alpha / t , 2 ) ;
    sig_ns = sig_ns * (p1/p) / ( 1. + (E - (p*E1/p1)*cos(theta) ) / M );

    double Rm, Re ; 
    Re = Ge2 *   ( 4.*E*E1 + t ) / ( 1 - 0.25*t/M2 );
    Rm = Gm2 * ( ( 4.*E*E1 + t ) * ( 1. - 1./ ( 1 - 0.25*t/M2 ) ) + 0.5*t*t/M2 + t*m2/M2 ) ;

    double                     sig = sig_ns * ( Re + Rm ) ;
    if( mode == "electric" ) { sig = sig_ns * Re          ; }
    if( mode == "magnetic" ) { sig = sig_ns * Rm          ; }

    return sig;

}


const int N = 180 ;

void XSlab(){

    double p = 0.3 ; 

    double sig_p, sig_b , diff; 
    
    
    // data from PR 103,1454
    double xx[8] = {30, 45, 60, 75, 90, 105, 120, 135}; 
    double dx[8] = { 0,  0,  0,  0,  0,   0,   0,   0};
    double yy[8] = {11500 , 1520, 498, 175, 81, 40.4, 24.8, 16.8} ; // nb/sr
    double dy[8] = {  800 ,  105,  40,  15,  7,  3.5,  1.7,  1.4} ;
    for(int i=0 ; i<8; i++){
        yy[i] = yy[i]/1e6 ;
        dy[i] = dy[i]/1e6 ;
    }


    double x[N], y0[N];
    double y1[N];
    double y2[N];
    double y3[N];
    double y4[N];
    double y5[N];

    double theta;
//    for(double theta = 1. ; theta<180. ; theta = theta + 2.){

    for(int i=0 ; i<N; i++){
    
        theta = 0.5 + i ; 
        x[i] = theta ;
    
        y0[i] = XS_Rutherford ( p , theta , "e" ) ;
        y1[i] = XS_Mott       ( p , theta , "e" ) ;
        y2[i] = XS_Mott_rec   ( p , theta , "e" ) ;
        y3[i] = XS_point      ( p , theta , "e" ) ;
        y4[i] = XS0q2         ( p , theta , "e" ) ;
        y5[i] = XS            ( p , theta , "e"  , "Kelly" , "full"      ) ;
        //y2[i] = XS ( p , theta , "e"  , "Kelly" , "electric"  ) ;
        //y3[i] = XS ( p , theta , "e"  , "Kelly" , "magnetic"  ) ;
        
        cout << "  " << theta << "\t" << y0[i]  << "\t" << y1[i]  << "\t" << y2[i] << "\t" << y3[i] << "\t" << y4[i] << endl;
    }

    TGraphErrors *gre = new TGraphErrors( 8, xx, yy, dx, dy);
    gre->SetMarkerStyle(24);

    TGraph *gr0 = new TGraph( N, x, y0 );
    TGraph *gr1 = new TGraph( N, x, y1 );
    TGraph *gr2 = new TGraph( N, x, y2 );
    TGraph *gr3 = new TGraph( N, x, y3 );
    TGraph *gr4 = new TGraph( N, x, y4 );
    TGraph *gr5 = new TGraph( N, x, y5 );
    

    gr0->SetLineWidth(2);
    gr1->SetLineWidth(2);
    gr2->SetLineWidth(2);
    gr3->SetLineWidth(2);
    gr4->SetLineWidth(2);
    gr5->SetLineWidth(2);
    
    gr0->SetLineColor(1); 
    gr1->SetLineColor(2);
    gr2->SetLineColor(8);
    gr3->SetLineColor(4);
    gr4->SetLineColor(5);
    gr5->SetLineColor(6);

    gr1->SetLineStyle(2);
    gr2->SetLineStyle(3);
    gr3->SetLineStyle(5);
    gr4->SetLineStyle(6);
    gr5->SetLineStyle(7);

    TCanvas *canv = new TCanvas("canv", "canv", 700, 700);
    gr0->GetYaxis()->SetRangeUser(0.000001, 0.1);
    gr0->GetXaxis()->SetTitle("#theta, deg.");
    gr0->GetYaxis()->SetTitle("d#sigma/d#Omega, mb/sr.");
    gr0->GetYaxis()->SetTitleOffset(1.45);
    gPad->SetLogy();

    gr0->SetTitle("");
    gr1->SetTitle("Mott cross section");
    gr2->SetTitle("Mott with proton recoil");
    gr3->SetTitle("point-like with magnetic interaction");
    gr4->SetTitle("form factors at t=0");
    gr5->SetTitle("full calculation");
    gre->SetTitle("PR 103,1454");
    

    gr0->Draw("AL");     // black   : Rutherford
    gr1->Draw("L same"); // red     : Mott 
    gr2->Draw("L same"); // green   : Mott with proton recoil
    gr3->Draw("L same"); // blue    : point-like with magnetic interaction
    gr4->Draw("L same"); // yellow  : form factors at q2=0
    gr5->Draw("L same"); // magenda : full calculation
    gre->Draw("P same"); // data from     PR 103,1454

    //auto legend = new TLegend(0.1,0.7,0.48,0.9);
    //legend->SetHeader("Elastic cross section","C"); // option "C" allows to center the header
    //legend->AddEntry(h1,"Histogram filled with random numbers","f");
    //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
    //legend->AddEntry("gre","Graph with error bars","lep");
    //legend->Draw();

    gr0->SetTitle("Rutherford");

    canv->BuildLegend();
    
}
