from os import listdir, system
from os.path import isfile, join
from sys import exit
from collections import Counter

idir = "input/"
odir = "output/"
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

files = [ f for f in listdir(idir) if isfile(join(idir,f)) ]
compare = compare = lambda x, y: Counter(x) == Counter(y)

def errors_for(file):
  lines = open(file).readlines()
  errors = []
  if lines[0].startswith("/*"):
    for error in lines[1:]:
      if error.strip() == "*/":
        break
      errors.append(error.strip())
  return errors

def expected_results(ifile, ofile):
  errors_ifile = errors_for(ifile)
  errors_ofile = errors_for(ofile)
  if not compare(errors_ifile, errors_ofile):
    return False
  return True

print bc.HEADER + "Test fwig typecheck system" + bc.ENDC
print

for f in files:
  system(fwig+" -s -w -p "+idir+f+" -o "+odir+f)
  if expected_results(idir+f, odir+f):
    print bc.OKGREEN + "[" + check + "] " + f + bc.ENDC
  else:
    print bc.FAIL + "[X] " + f + " (failed didn't get expected errors)" + bc.ENDC
