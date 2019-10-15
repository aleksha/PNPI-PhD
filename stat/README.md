Introduction tutorial
=====================

Precursors:
 * Ostap software stack installed

Download the project, go to **stat** directory, start __Ostap__:
```bash
git clone https://github.com/aleksha/PNPI-PhD.git
cd PNPI-PhD/stat/
ostap
```
To exit __Ostap__ use **exit()**, or **quit()**, or **Ctrl+D** follower by **Enter**.

The standard call launch IPython and create default canvas (can be called as __canvas__).
The ROOT decoration is preloaded.
For exaple next commands create ROOT hystogram, fill it with 2 and 1.9 (it returns bin number;
remember that in ROOT bin numbering starts from 1), draw, and save into file **temp.png**
```ipython
In [1]: h = ROOT.TH1F("h","h",10,0,10)
In [2]: h.Fill(2)
Out[2]: 3
In [3]: h.Fill(1.9)
Out[3]: 2
In [5]: h.Draw()
In [6]: canvas >> "temp.png"
Out[6]: <ROOT.TCanvas object ("glCanvas") at 0x561613c75f20>
```
To see, which ROOT object are available type:
```ipython
In [7]: dir(ROOT)
```
To see, which methods are available for particular object see help (type **q** to exit help).
For example:
```ipython
In [8]: help(ROOT.TH1F)
```
**Note: that there a lot of methods in addition to the standard ROOT one!**
