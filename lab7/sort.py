# coding: utf-8
def bubbleSort(array):
  try:
    length = len(array)
  except:
    return False, array 
  
  #already sorted 
  if length == 1:
    return True, array 
  
  for i in range (0, length-1):
    
    for j in range (0, (length-1-i)):
      if array[j] > array[j+1]:
        temp = array[j]
        array[j] = array [j+1]
        array[j+1] = temp

        
  #status check, make sure it has sorted       
  for x in range (0, length-1):
    if array[x] <= array[x+1]:
      status = True
    else:
      status = False
      return (status, array)
      
  return (status, array)
