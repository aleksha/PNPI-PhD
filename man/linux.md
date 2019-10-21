Variants of installation
========================

Local Linux machine
-------------------

**Note: Nowdays an attempt to install Linux as second operation system aside 
to the Windows one is tricky buisness, which can destroy Windows installation.
Strongly recomend to do it if one 100% sure in his skills!!!**

Recommend to use **Ubuntu 18.04 LTS (Long Term Support)** family:
 * Ubuntu https://ubuntu.com/download
 * Xubuntu (xfce window manager) https://xubuntu.org/release/18-04/

Install using instructions, and follow:
  - https://github.com/aleksha/PNPI-PhD/blob/master/man/ostap.md#binaries-for-the-ubuntu-1804

Another option is to use **conda**:
 - https://github.com/OstapHEP/ostap/blob/master/README.md#%D1%81onda

Virtual Linux machine
---------------------

Instructions how to setup it for VirtualBox is kindly provided by
Vladimir Chulikov:
 - https://github.com/aleksha/PNPI-PhD/blob/master/man/VirtualBox_Instructions.docx

**Xubuntu 18.04 LTS** also works fine.

Follow this part of guide after setup:
  - https://github.com/aleksha/PNPI-PhD/blob/master/man/ostap.md#binaries-for-the-ubuntu-1804


Docker for Windows and MacOS
----------------------------
 - https://github.com/OstapHEP/ostap/blob/master/README.md#docker


CERN LXPLUS (CERN users only)
-----------------------------

At lxplus/7 you can do it with several LCG versions (94,95). 
Check on which platform is the preferred version of LCG located and run LbLogin, 
for instance for LCG 95 and x86_64-centos7-gcc8-opt.

See for details:
 - https://github.com/OstapHEP/ostap/blob/master/README.md

Cloud machine (non-PNPI only)
------------------------------

Instread of using virtual machines, which share limitations of the existing PCs 
and have some difficulties with installation of the operation systems,
a cloud solution is proposed.

Access via command line using _ssh_.
To access commad line:
 * **Linux** -- use any terminal
 * **Windows** -- http://cmder.net/
 * **macOS** -- https://www.iterm2.com/ (not tested)

See instructions:
 - https://github.com/aleksha/PNPI-PhD/blob/master/man/cloud.md

