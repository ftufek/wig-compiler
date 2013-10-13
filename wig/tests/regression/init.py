from os import listdir, system
from os.path import isfile, join
from sys import exit
from filecmp import cmpfiles

idir = "input/"
odir = "output/"
tdir = "temp/"
fwig = "../../Debug/fwig"

files = [ f for f in listdir(idir) if isfile(join(idir, f)) ]

for f in files:
  system(fwig+" -p "+idir+f+" > "+odir+f)
