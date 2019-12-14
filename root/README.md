Recepies for CERN ROOT
======================

How to compile standalone ROOT program
--------------------------------------

See:

 - https://en.wikibooks.org/wiki/ROOT/Getting_Started/Many_Ways_to_Use_ROOT

```bash
g++ -o hello hello.cc `root-config --cflags --glibs`
```

Thee program then just stops at **Run()** and one can end the process with ^C.
