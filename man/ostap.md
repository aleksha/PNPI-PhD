# How-To install Ostap

    > apt update

    > apt upgrade

    > apt install git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev

    > apt install gfortran libssl-dev libpcre3-dev xlibmesa-glu-dev libglew1.5-dev libftgl-dev
    
    > apt install libmysqlclient-dev libfftw3-dev libcfitsio-dev graphviz-dev libavahi-compat-libdnssd-dev
    
    > apt install libldap2-dev python-dev libxml2-dev libkrb5-dev libgsl0-dev libqt4-dev

    > wget https://root.cern.ch/download/root_v6.14.06.source.tar.gz

    > tar zxvf root_v6.14.06.source.tar.gz
    
    > mkdir builddir; cd builddir

    > cmake /root/root_v6.14.06

    > cmake --build . -- -j2 
