Software installation:
======================

(Old version, have to be updated)

 1. Install Xubuntu 16.04 LTS

 2. Update software
 
    > sudo apt-get update
    > sudo apt-get upgrade

 3. CERN ROOT installtion

  3.1 Download ROOT from https://root.cern.ch/content/release-53436
  
  3.2 Install packages
  
    > sudo apt-get install git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev
    
    > sudo apt-get install gfortran libssl-dev libpcre3-dev xlibmesa-glu-dev libglew1.5-dev libftgl-dev libmysqlclient-dev libfftw3-dev libcfitsio-dev graphviz-dev libavahi-compat-libdnssd-dev libldap2-dev python-dev libxml2-dev libkrb5-dev libgsl0-dev libqt4-dev

  3.3 Compile ROOT
  
    > sudo cp root_v5.34.36.source.tar.gz /usr/local/
    
    > cd /usr/local/
    
    > sudo tar zxvf root_v5.34.36.source.tar.gz
    
    > cd root/
    
    > sudo ./configure
    
    > sudo make

  3.4 Add ROOT paths to .bashrc
  
        export ROOTSYS=/usr/local/root
        export PATH=$ROOTSYS/bin:/usr/local/bin:./$PATH
        export LD_LIBRARY_PATH=$ROOTSYS/lib:/usr/lib/mysql:$LD_LIBRARY_PATH
        
 4. GEANT4 installation

  4.1 Download GEANT4 to local machine http://geant4.web.cern.ch/geant4/support/download.shtml
 
  **at local machine**
  
    > scp -i ..\.ssh\YOURKEY geant4.10.04.p02.tar.gz root@IPADRESS:/home/user/Sim/
    
  4.2 Stack of commands

    > sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

    > sudo apt-get install libmotif-dev

    > cd ~/Sim/

    > tar zxvf geant4.10.04.p02.tar.gz

    > mkdir ~/Sim/geant4.10.04.p02-build

    > cd ~/Sim/geant4.10.04.p02-build

    > cmake -DCMAKE_INSTALL_PREFIX=/home/user/Sim/geant4.10.04.p02-install /home/user/Sim/geant4.10.04.p02

    > cmake -DGEANT4_INSTALL_DATA=ON .

    > make

    > make install

5. ESEPP installation

  5.1 Download and complle
  
    > cd ~/Sim
    
    > git clone https://github.com/gramolin/esepp.git
    
    > cd esepp
    
    > make
    
    > ./esepp
