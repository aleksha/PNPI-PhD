double bhabha(double t, double s=0.113364){
    //double alpha = 1./137.;
    double alpha = 1.;
    double theta_W = 0.492;
    double c = 1.+2.*t/s;
    double gA = -0.5;
    double gV = -0.5*(1.-4.*pow(2.*sin(theta_W),2));
    double MZ = 91.1876;

    double Lambda = 1/pow(sin(2.*theta_W),2);
    double ksi = Lambda*t/(t-MZ*MZ);
    double chi = -Lambda*s/(MZ*MZ);

    double B1=pow(s/t,2)*pow(1+(gV*gV-gA*gA)*ksi,2);
    double B2=pow(1+(gV*gV-gA*gA)*chi,2);

    double B3 = 0.5*pow(1+(s/t)+pow(gV+gA,2)*(s*ksi/t+chi),2);
    B3       += 0.5*pow(1+(s/t)+pow(gV-gA,2)*(s*ksi/t+chi),2);


    return pow(alpha,2)*(4.*B1+pow(1-c,2)*B2+pow(1+c,2)*B3) / (8.*s);
}
double em(double t, double s=0.113364){
    return pow((s*s+s*t+t*t)/(s*t),2)/s;

}

void Bhabha(){
    cout << bhabha(-0.0024) << "  " << em(-0.0024) << endl;
}