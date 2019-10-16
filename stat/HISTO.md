ROOT histograms in Ostap
========================

Standard _ROOT_ histograms (_TH1_ class) have a lot of useful decoration.
One can use original methods as well. See:
 - https://root.cern.ch/doc/master/classTH1.html
 - https://lhcb.github.io/ostap-tutorials/getting-started/Histos.html
 - https://lhcb.github.io/ostap-tutorials/more-on-histograms/hparams.html

```ipython
In [1]: help(ROOT.TH1F)
In [3]: h1 = ROOT.TH1F("h","Histo;x;y",10,0,1)
In [4]: h1.GetXaxis().GetTitle()
Out[4]: 'x'
```

