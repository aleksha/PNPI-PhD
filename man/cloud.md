Using cloud infrastructure by non-PNPI users
============================================

Instread of using virtual machines, which share limitations of the existing PCs 
and have some difficulties with installation of the operation systems,
a cloud solution is proposed.

Next provider are tested:
  * https://vscale.io (Russian provider, used as default one [English mode])
  * https://digitalocean.com (had some difficulties with connetion to Russia)
  
**Note:** the opportunity to use other ways as locally installed software,
virtual machines and so on is not forbidden, but will have no support from
teachers.

Create RSA key pair for SSH conection
--------------------------------------

 (one can read https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/)
 
 Mainly:

  > cd ~/.ssh/
  
  > ssh-keygen 

 It's safer to add passphrase, but you will have to type it everytime...

 To read publich key
 
  > cat ~/.ssh/id_rsa.pub



Setup server at vscale enviorement:
-----------------------------------

 1. Create an account and put some payment (200 RUB will cover half a month usage)
 
 2. Servers -> Create Server:  Choose
   * Ubuntu 16.04 64bit
   * 400 RUB/month server
   * Saint-Petersburg location (for PNPI)
   * Server name (name of server at the pannel)
   * Host name (name of server on server)
   * upload SSH public key
   * Create Server
   
 3. After server will have status _Online_ use ssh to login
 
   > ssh -i/.ssh/id_rsa root@IP_ADDRESS

 4. Update software, create user, switch to it
 
   > apt update
   
   > apt upgrade
   
   > useradd -m user
   
   > adduser user sudo
     
   > su user
 
 
 

