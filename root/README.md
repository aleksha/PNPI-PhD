Content
=======

Recepies and tips for CERN ROOT
===============================

Installation instructions can be found in **man/root.md**.

```bash
root
```

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
so add headers and namespaces. Modify *helloscript.C**:
```c++
#include <iostream>

using namespace std;

void helloscript()
{
  cout << "hello world!" << endl;
}```


To complile it before execution type in the ROOT shell:
```bash
.x helloscript.C+
```

https://en.wikibooks.org/wiki/ROOT/Getting_Started/Many_Ways_to_Use_ROOT :

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
