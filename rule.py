# coding: utf-8
def rule (value, list1):
  length = len(list1)
  total = 0
  
  for i in range(0, length):
    total = total + list1[i]
    
  if value == 1:
    if (total == 2 or total == 3):
      return 1
    else:
      return 0
  else:
    if total == 3:
      return 1
    else:
      return 0
    
