from subprocess import call
from os import chdir

chdir("../")
call(["./check"])

with open("result") as f:
  with open("../testcases") as tests:
    for rLine, tLine in zip(f.readlines(), tests.readlines()):
      test = rLine.split(' : ')
      if eval(tLine) != eval(test[0]):
        print("ERROR on pretty printing: "+tLine)
      if eval(test[0]) != eval(test[1]):
        print("ERROR on calculating: "+test[0])
