from os import listdir, system
from os.path import isfile, join
from sys import exit
from filecmp import cmpfiles

idir = "input/"
pp1dir = "pp1/"
pp2dir = "pp2/"
fwig = "../../Debug/fwig"

files = [ f for f in listdir(idir) if isfile(join(idir, f)) ]

for f in files:
  system(fwig+" -p "+idir+f+" > "+pp1dir+f)

for f in files:
  system(fwig+" -p "+pp1dir+f+" > "+pp2dir+f)


print "Testing that the following is true for all the benchmark files: "
print "pretty(parse(pretty(parse(X)))) = pretty(parse(X))"
print

for f in files:
  if not cmp(pp1dir+f,pp2dir+f):
    print "ERROR for file "+f
    exit(1)
  else:
    print "SUCCESS for file "+f
