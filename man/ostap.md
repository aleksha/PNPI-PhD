Variants of installation
========================

Variants of machine setups are discussed in separate documents:
 - https://github.com/aleksha/PNPI-PhD/blob/master/man/linux.md

**Ostap** system requires **ROOT** as well as some python modules.
 
Highly recommend use conda way. See https://github.com/OstapHEP/ostap/blob/master/README.md

Binaries for the Ubuntu 18.04 (old documantation)
=================================================

**Note:** Binaries are compiled for the username=**user** 
(which has _sudo_ access) in **/home/user/Software/**.

Next packages (with all the dependencieas) are installed a prior
```bash
sudo apt-get --fix-missing install git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev gfortran libssl-dev libpcre3-dev xlibmesa-glu-dev libglew1.5-dev libftgl-dev libmysqlclient-dev libfftw3-dev libcfitsio-dev graphviz-dev libavahi-compat-libdnssd-dev libldap2-dev python-dev libxml2-dev libkrb5-dev libgsl0-dev libqt4-dev doxygen doxygen-gui ipython ipython-qtconsole build-essential python-pip
```

Also some packeges are installed via **pip**.
These are OSTAP dependencies.
```bash
pip install future configparser  numpy scipy pathos dill multiprocess ppt terminaltables
```

To be installed (unpacked) for example into **/home/user/Software/root**
```bash
mkdir Software
cd Software
wget http://adzyuba.web.cern.ch/adzyuba/b/README.md
wget http://adzyuba.web.cern.ch/adzyuba/b/root_v6.18.02.source.tar.gz
wget http://adzyuba.web.cern.ch/adzyuba/b/root_Ubuntu18.04_OstapFlags.tar.gz
tar zxvf root_v6.18.02.source.tar.gz
tar zxvf root_Ubuntu18.04_OstapFlags.tar.gz
cd root
cd bin
source thisroot.sh
```

You can write next into **~/.bashrc** not to run **thisroo.sh** everytime:
```bash
export ROOTSYS=/home/user/Software/root
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib/:$LD_LIBRARY_PATH
```

How this ROOT has been compiled
-------------------------------

The main is to do it with the right CMake flags:
```bash
cd /home/user/Software
wget https://root.cern/download/root_v6.18.02.source.tar.gz
tar zxvf root_v6.18.02.source.tar.gz
mkdir root
cd root
cmake /home/user/Software/root-6.18.02 -Dminuit2=ON -Dmathmore=ON -Dcxx14=ON
cmake --build . -- -j4
```

It took aproximately 1 hour at 4 core / 8 Gb RAM VPS.


Compile OSTAP
=============

```bash
cd /home/user/Software
git clone https://github.com/OstapHEP/ostap.git
cd ostap
mkdir build install
cd build/
cmake .. -DCMAKE_INSTALL_PREFIX=/home/user/Software/ostap/install
make
make install
cd ../install/
source thisostap.sh
```
Note, that simple call (**> ./thisostap.sh**) doesn't work.

How to view
===========

SimpleHTTPServer with Python
----------------------------

One can serve from current directory

```bash
python -m SimpleHTTPServer 8000
```
Then try in browser: **http://IP_ADDRESS:8000/TEMP.png**


Nginx
-----

Another option is to install **nginx**:

```bash
sudo apt-get install nginx
```

Check that Ubuntu firewall allows HTTP.
If not, allow it. Copy figure to **/var/www/html/**

```bash
sudo ufw app list
sudo ufw allow 'Nginx HTTP'
systemctl status nginx
pico histo.py
sudo cp TEMP.png /var/www/html/
```

Open in browser **http://IP_ADDRESS/TEMP.png**
