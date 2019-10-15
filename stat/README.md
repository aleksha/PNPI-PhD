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

The standard call launch IPython and create default canvas (can be called as __canvas__).
The ROOT decoration is preloaded.
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

To exit use **exit()**, or **quit()**, or **Ctrl+D**.
