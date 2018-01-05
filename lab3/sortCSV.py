# coding: utf-8
import sys

fin=""
fout=""
col=""
dir=""

nargs=len(sys.argv)
skip=False
for i in range(1,nargs):
   if not skip:
      arg=sys.argv[i]
      if arg == "--fin":
         if i != nargs-1:
            fin=sys.argv[i+1]
            skip=True
      elif arg == "--fout":
         if i != nargs-1:
            fout=sys.argv[i+1]
            skip=True
      elif arg == "--col":
         if i != nargs-1:
            col=int(sys.argv[i+1])
            skip=True
      elif arg == "--dir":
         if i != nargs-1:
            dir=sys.argv[i+1]
            skip=True
      else:
         print "ERR: unknown arg:",arg
   else:
      skip=False

try:
  f=open(fin,'r')
except:
  print "ERR: File is not present or cannot be opened"
  
lines =f.readlines()
f.close()
accum = []
rows = 0
columns = 0

for i in lines:
  columns = 0
  j = i.split('\n')[0]
  k = j.split(',')
  r = []
  for x in k:
    r = r+[float(x)]
    columns = columns + 1
  accum = accum + [r]
  rows = rows + 1

#print columns
#print col

if ((col >= columns) or (col < 0)):
  print "ERR: Column input not valid. Stopping."
  exit()  
else:
  def genSortKey(col,up):
    def key(x):
      return x[col] if up else -x[col]
    return key
  if (dir == '+'):
    temp = True
  if (dir == '-'):
    temp = False
  dir = temp

accum = sorted(accum,key=genSortKey(col, dir))

try:
  g=open(fout,'w')
except:
  print "ERR: File is not present for writing"

for z in range(0, rows):
  for x in range (0, columns):
    g.write(str(accum[z][x]))
    if (x<columns-1):
      g.write(',')
  g.write("\n")

g.close()
