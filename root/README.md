About
=====

ROOT is  C++ based free data analysis software and library developed at CERN.
Documenration as well as sources can be found in: https://root.cern.ch/

Important ROOT classes
----------------------
 * **Windows:** TBrowser, TCanvas, TPad
 * **Histogramms:** TH1, TH2, TH3
 * **Graphics:** TGraph, TGraphErrors, TGraphAsymmErrors
 * **Functions:** TFormula, TF1, TF2, TF3
 * **Fitting:** TFitResult, TMinuit
 * **Physics:** TVector3, TRotation, TLorentzVector, TLorentzRotation
 * **Data:** TTree, TBranch, TChain, TSelector


Recepies and tips for CERN ROOT
===============================

Installation instructions can be found in **man/root.md**.

```bash
root
```

This run an nterpreter for C and C++ code, which could be **cling** for current
ROOT version or CINT for old ones. More details:
 - https://root.cern.ch/cling
 - https://root.cern.ch/cint

 > An interpreter is a software that executes code line after line rather than 
 > compiling it all at once. This has the advantage that you needn't wait for 
 > the compiler and can see / check the result immediately. On the other hand, 
 > interpreting code is much slower than executing compiled code. 

To exit type: **.q** and **Enter**.

Usefull options:
 * **-h**: Show possible options
 * **-q**: exit after execution of macro
 * **-b**: Run in batch mode without graphics
 * **-l**: don't show splash screen

Auto completion works with **Tab** key.

ROOT Macros
-----------

Create file **helloscript.C** with next content:
```c++
void helloscript()
{
  cout << "hello world!" << endl;
}
```

Run it from shell
```bash
root helloscript.C
```
or run ROOT and use **.x** command in ROOT command line interface
```bash
.x helloscript.C
```

Working in ROOT command line or running macros one uses ROOT in so-called interpetator regime.
To run it fast, one should compile his routines. First one have to make programm be valid C++,
so add headers and namespaces. Modify **helloscript.C** as:
```c++
#include <iostream>

using namespace std;

void helloscript()
{
  cout << "hello world!" << endl;
}
```


To complile it before execution type in the ROOT shell:
```bash
.x helloscript.C+
```

 > Complation is done y a program called ACLiC (The Automatic Compiler of Libraries for CINT). 
 > ACLiC is a smart tool that makes use of your installed compiler and builds up and reuses 
 > a library from your compiled code. You can, however, tell ACLiC to build up the library
 > from scratch even if not necessary by adding “++” at the end. 


How to compile standalone ROOT program
--------------------------------------

Use **g++** compiler, but first apply C++ standard to a file. 

CINT defines the preprocessor variable __CINT__. One can screen a main function to be visible 
when **g++** processes the code but not when CINT does.


```bash
g++ -o hello hello.cc `root-config --cflags --glibs`
./hello
```

Important thing is to add **TApplication** class. Without it you won't be able to see canvas
(though its printing into PNG-file will be done). The program then just stops 
at **Run()** and one can end the process with ^C.


Data types
----------

Standard data types depend on machine and compiler. There so-called
**machine independent data types** in ROOT, which lways have the same definition.
It is strongly recommended to use them when programming ROOT. 

 - **Bool_t** 	logical value (false/true)
 - **Char_t** 		signed integer value 	/ 1 byte
 - **UChar_t** 		unsigned integer value 	/ 1 byte
 - **Short_t** 		signed integer value 	/ 2 bytes
 - **UShort_t** 	unsigned integer value 	/ 2 bytes
 - **Int_t** 		signed integer value 	/ 4 bytes
 - **UInt_t** 		unsigned integer value 	/ 4 bytes
 - **Long_t** 		signed integer value 	/ 8 byte
 - **ULong_t** 		unsigned integer value 	/ 8 byte
 - **Float_t** 		floating point value 	/ 4 bytes
 - **Double_t** 	floating point value 	/ 8 bytes 

More tips
---------

To exit ROOT from macro:
```c++
#include "TSystem.h"
...
gSystem->Exit(0);
...

```

Quotes are from
===============

 - https://en.wikibooks.org/wiki/ROOT/Getting_Started/Many_Ways_to_Use_ROOT

