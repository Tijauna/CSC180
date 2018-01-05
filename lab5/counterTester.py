# coding: utf-8
x = counter(99)
y = counter(1)
for i in range(0,100, 2):
  sum = x.getState() + i
  print 'Expected:',sum
  x.evolve(i)
  x.getState()
  if (x.getState() == sum):
    print 'State is as expected.'
  else:
    print 'State is not correct'
    
for i in range(0,-50, -2):
  sum = y.getState() + i
  print 'Expected:',sum
  y.evolve(i)
  y.getState()
  if (y.getState() == sum):
    print 'State is as expected.'
  else:
    print 'State is not correct'
    
