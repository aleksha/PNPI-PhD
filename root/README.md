Recepies and tips for CERN ROOT
===============================

Installation instructions can be found in **man/root.md**.

```bash
root
```

Usefull options:
 * **-h**: Show possible options
 * **-q**: exit after execution of macro
 * **-b**: Run in batch mode without graphics
 * **-l**: don't show splash screen

Auto completion works with **Tab** key.

How to compile standalone ROOT program
--------------------------------------

See:

 - https://en.wikibooks.org/wiki/ROOT/Getting_Started/Many_Ways_to_Use_ROOT

```bash
g++ -o hello hello.cc `root-config --cflags --glibs`
```

Thee program then just stops at **Run()** and one can end the process with ^C.
