from seqdetectorlib import *

x=seqdetector()
n=0
words_list = [ "here", "are", "the", "solutions", "to", "the", "next", "blah", "exam" ] \
           + [ "here", "are", "the", "solutions", "to", "the", "next", "exam" ] \
           + [ "here", "are", "the", "solutions", "to", "the", "next", "blah", "exam" ] \
           + [ "here", "are", "the", "solutions", "to", "the", "next", "exam" ] 

answers = [ 16, 33 ]
pos = 0
passCnt = 0

for i in words_list:
   status=x.evolve(i) 
   if status == True:
      print "Detected: end position is",n
      if n == answers[pos]:
         passCnt += 1
      pos += 1
   n = n+1

print passCnt,"out of",len(answers)
