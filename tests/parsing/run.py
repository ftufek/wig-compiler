from os import listdir, system
from os.path import isfile, join
from sys import exit
from filecmp import cmpfiles

idir = "input/"
pp1dir = "pp1/"
pp2dir = "pp2/"
fwig = "../../fwig"

# Code from:
# http://stackoverflow.com/questions/287871/print-in-terminal-with-colors-using-python
class bc:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    def disable(self):
        self.HEADER = ''
        self.OKBLUE = ''
        self.OKGREEN = ''
        self.WARNING = ''
        self.FAIL = ''
        self.ENDC = ''

check = u'\u2713'

files = [ f for f in listdir(idir) if isfile(join(idir, f)) ]

for f in files:
  system(fwig+" -p "+idir+f+" > "+pp1dir+f)

for f in files:
  system(fwig+" -p "+pp1dir+f+" > "+pp2dir+f)


print bc.HEADER + "Test fwig compiler parsing phase: " + bc.ENDC
for f in files:
  if not open(pp1dir+f).readlines() == open(pp2dir+f).readlines():
    print bc.FAIL + "[X] " + f + " (failed parsing)" + bc.ENDC
    exit(1)
  else:
    print bc.OKGREEN + "[" + check + "] " + f + bc.ENDC

print
