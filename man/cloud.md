Using cloud infrastructure by non-PNPI users
============================================

Next provider are tested:
  * https://vscale.io (Russian provider, used as default one [English mode])
Was tested in past (may be outdated):
  * https://digitalocean.com (had some difficulties with connetion to Russia)
  

Create RSA key pair for SSH conection
--------------------------------------

(one can read https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/)
 
Mainly:

```bash
cd ~/.ssh/
ssh-keygen 
```

It's safer to add passphrase, but you will have to type it everytime...
To read publich key
 
```bash
cat ~/.ssh/id_rsa.pub
```


Setup server at vscale enviorement:
-----------------------------------

 1. Create an account and put some payment (200 RUB will cover half a month usage)
 
 2. Servers -> Create Server:  Choose
   * Ubuntu 18.04 64bit (as it's LTS)
   * 400 RUB/month server
   * Saint-Petersburg location (for PNPI)
   * Server name (name of server at the pannel)
   * Host name (name of server on server)
   * upload SSH public key
   * Create Server
   
 3. After server will have status _Online_ use ssh to login
 
```bash
ssh -i/.ssh/id_rsa root@IP_ADDRESS
```
First steps on new machine
==========================

Update software, create user (with name __user__ , option __-m__ creates home directory), add user to sudoers, switch to it
 
```bash
apt update
apt upgrade
apt --fix-missing install git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev gfortran libssl-dev libpcre3-dev xlibmesa-glu-dev libglew1.5-dev libftgl-dev libmysqlclient-dev libfftw3-dev libcfitsio-dev graphviz-dev libavahi-compat-libdnssd-dev libldap2-dev python-dev libxml2-dev libkrb5-dev libgsl0-dev libqt4-dev doxygen doxygen-gui ipython ipython-qtconsole build-essential python-pip
useradd -m user
passwd user
adduser user sudo
su user
```
 
 

