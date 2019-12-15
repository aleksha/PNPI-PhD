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

Run it
```bash
root helloscript.C
```
or run ROOT and use 
```bash
**root[1]** .x helloscript.C
```

How to compile standalone ROOT program
--------------------------------------

See:

 - https://en.wikibooks.org/wiki/ROOT/Getting_Started/Many_Ways_to_Use_ROOT

```bash
g++ -o hello hello.cc `root-config --cflags --glibs`
```

Thee program then just stops at **Run()** and one can end the process with ^C.
