from os import listdir, system
from os.path import isfile, join
from sys import exit
from filecmp import cmp

idir = "input/"
odir = "output/"
tdir = "temp/"
fwig = "../../fwig"

files = [ f for f in listdir(idir) if isfile(join(idir, f)) ]

for f in files:
  system(fwig+" < "+idir+f+" > "+tdir+f)
  if not cmp(odir+f,tdir+f):
    print "error in comparaison on file: "+f
    exit(1)
