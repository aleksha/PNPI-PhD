Examples with TGraph family and related stuff
=============================================

ThreeGraphs
-----------

 * **TGraph**, **TGraphErrors**, **TGraphAsymmErrors**
 * Draw options ("A" -  draw axis)
 * Fit with build-in 2nd order polynomial formula (see fit results in shell)
 * **TCanvas** (vertical spleeting)


XSlab.C
-------

Various cross section formulas for electron-proton elastic scattering

 * **TGraph**, **TGraphErrors**
 * Log scale
 * Axes handling
 * Line styles and color
 * Automatic build of legent (works only ROOT v6)


AdditionalAxis.C
----------------

 * **TGraph**
 * Additional axis on top (**TGaxis**)
 * Log scale
 * Axis label properties
 * **TLatex** labels


Useful methods
==============

**Eval()** - Interpolate points in this graph at x using a **TSpline**. 

**Chisquare( TF1* func)** - Return the chisquare of this graph with respect to function. 
n case of a pure **TGraph** compute sum of squared differences. In case of a 
**TGraphErrors** or **TGraphAsymmErrors** the errors are taken into account.

