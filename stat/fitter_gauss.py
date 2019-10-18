#-------------------------------------------------------------------------------
import ostap.fitting.models as Models
from   ostap.utils.timing import timing
from   ostap.histos.histos  import h1_axis
execfile("Functions.py")
#-------------------------------------------------------------------------------
rfile = ROOT.TFile("test_file.root","READ")
ds = rfile["ds"]
#-------------------------------------------------------------------------------
im = ROOT.RooRealVar ('im'   , 'im'                 ,  2.240 , 2.330 )
pk = ROOT.RooRealVar ('pk'   , 'peak   '   , 2.2875 ,  2.286 , 2.289 )
sg = ROOT.RooRealVar ('sg'   , 'sigma'     , 0.0045 ,  0.003 , 0.010 )
#-------------------------------------------------------------------------------
sig_ga = Models.Gauss_pdf( 'sig_ap', xvar=im,   mean=pk, sigma=sg )
bkg0_lc  = Models.Bkg_pdf ( 'bkg0_lc' , xvar = im , power = 0 )
model_ga = Models.Fit1D   ( signal = sig_ga , background = bkg0_lc )
#-------------------------------------------------------------------------------
dh = ( ds.reduce( ROOT.RooArgSet( im ) , "im>0" ) ).binnedClone()
#-------------------------------------------------------------------------------
with timing():
    r, w = model_ga.fitTo( dh )
    r, w = model_ga.fitTo(ds, draw=True, nbins=100, ncpu=4)
#-------------------------------------------------------------------------------
print(r)
#-------------------------------------------------------------------------------
h = w.pullHist()
draw_param( r, w, h, 90, im, 0.06*ds.sumEntries(), name="Lc", XTitle ="Mass",
                Prefix="Gauss" , Type="png", var_Units = "GeV/c^{2}")
#-------------------------------------------------------------------------------
