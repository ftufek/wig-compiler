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

print bc.HEADER + "Test fwig compiler codegen system" + bc.ENDC
print

for f in files:
  py_out = f.split(".wig")[0]
  system(fwig+" -c -t -s -w -p -o "+odir+py_out+".py "+idir+f)
  system("chmod +x "+odir+py_out+".py")
  print bc.OKGREEN + "[" + check + "] " + f + bc.ENDC
