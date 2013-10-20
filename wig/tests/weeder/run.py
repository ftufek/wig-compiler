from os import listdir, system
from os.path import isfile, join
from sys import exit
from filecmp import cmpfiles

idir = "input/"
fwig = "../../Debug/fwig"

files = [ f for f in listdir(idir) if isfile(join(idir,f)) ]

print "Testing that the weeder correctly accepts and rejects when appropriate."
print "Showing ERROR's in the following is OK, it just shows that the weeder "
print "rejects bad functions and sessions."
print
print

for f in files:
  system(fwig+" -w "+idir+f)
