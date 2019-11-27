#include "TVector3.h"
#include "TMath.h"
#include "TMinuit.h"

double Reso = 0.016; // 16 um per plane

TVector3 hit(TVectror3 point, TVector3 direction, TVector3 plane_p1, TVector3 plane_p2){
// A line traced form a 'point' along 'diraction'
// This function returns an intersection point of the line with
// a 'plane', which is defined by a normal vector (from 'plane_p1' to 'plane_p2')
    TVector3 Hit; Hit.SetXYZ(0,0,0);
    return Hit;
}


double my_fcn(){
    double nLL = 0;
    TVector3 vPlanes[5][2];



    vPlanes[0][0].SetXYZ(0,0,-7000.);vPlanes[0][1].SetXYZ(0,0,0);
    vPlanes[1][0].SetXYZ(0,0,-2000.);vPlanes[1][1].SetXYZ(0,0,0);
    vPlanes[2][0].SetXYZ(0,0,  100.);vPlanes[2][1].SetXYZ(0,0,0);
    vPlanes[3][0].SetXYZ(0,0, 2000.);vPlanes[3][1].SetXYZ(0,0,0);
    vPlanes[4][0].SetXYZ(0,0, 5000.);vPlanes[4][1].SetXYZ(0,0,0);

    EHit0b = hit(vVertex, vBeam, vPlanes[0][0], vPlanes[0][1]); 
    EHit1b = hit(vVertex, vBeam, vPlanes[1][0], vPlanes[1][1]); 

    EHit2m = hit(vVertex, vMuon, vPlanes[2][0], vPlanes[2][1]);
    EHit3m = hit(vVertex, vMuon, vPlanes[3][0], vPlanes[3][1]);
    EHit4m = hit(vVertex, vMuon, vPlanes[4][0], vPlanes[4][1]);

    EHit2e = hit(vVertex, vElec, vPlanes[2][0], vPlanes[2][1]);
    EHit3e = hit(vVertex, vElec, vPlanes[3][0], vPlanes[3][1]);
    EHit4e = hit(vVertex, vElec, vPlanes[4][0], vPlanes[4][1]);

    nLL -= log( TMath::Gaus((MHit0b.x()-EHit0b.x())/Reso) ); nLL -= log( TMath::Gaus((MHit0b.y()-EHit0b.y())/Reso) );
    nLL -= log( TMath::Gaus((MHit1b.x()-EHit1b.x())/Reso) ); nLL -= log( TMath::Gaus((MHit1b.y()-EHit1b.y())/Reso) );

    nLL -= log( TMath::Gaus((MHit2m.x()-EHit2m.x())/Reso) ); nLL -= log( TMath::Gaus((MHit2m.y()-EHit2m.y())/Reso) );
    nLL -= log( TMath::Gaus((MHit3m.x()-EHit3m.x())/Reso) ); nLL -= log( TMath::Gaus((MHit3m.y()-EHit3m.y())/Reso) );
    nLL -= log( TMath::Gaus((MHit4m.x()-EHit4m.x())/Reso) ); nLL -= log( TMath::Gaus((MHit4m.y()-EHit4m.y())/Reso) );

    nLL -= log( TMath::Gaus((MHit2e.x()-EHit2e.x())/Reso) ); nLL -= log( TMath::Gaus((MHit2e.y()-EHit2e.y())/Reso) );
    nLL -= log( TMath::Gaus((MHit3e.x()-EHit3e.x())/Reso) ); nLL -= log( TMath::Gaus((MHit3e.y()-EHit3e.y())/Reso) );
    nLL -= log( TMath::Gaus((MHit4e.x()-EHit4e.x())/Reso) ); nLL -= log( TMath::Gaus((MHit4e.y()-EHit4e.y())/Reso) );

    return nLL;
}

