# coding: utf-8
def ge_fw(matrix):
  
  rows = len(matrix)
  columns = len(matrix[0])

 

  rowiterator = 0
  columniterator = 0
  
  while (columniterator < columns) and (rowiterator < rows):   
    
    #find the first non zero row
    if matrix [rowiterator][columniterator] == 0:
      for i in range(rowiterator, len(matrix)):
        if matrix[i][columniterator] != 0:
          #swap
          matrix[rowiterator], matrix[i] = matrix[i], matrix[rowiterator]
          break
      
    #get zeroes underneath the first value in the column
    for rowcounter in range(rowiterator + 1,rows):
      scalarcounter = 0
    

      while (scalarcounter < rowiterator+1):
        
        if matrix[rowcounter][columniterator] != 0:
          #keep the scalar multiple
          scalar = matrix[rowcounter][columniterator] / matrix[rowiterator][columniterator]
      
  
            
          #apply the subtraction across all columns 
          for columncounter in range(0, columns):
          
            matrix[rowcounter][columncounter] = matrix[rowcounter][columncounter] - (scalar * matrix[rowiterator][columncounter])
 
  
        scalarcounter = scalarcounter + 1

    
    rowiterator = rowiterator + 1
    columniterator = columniterator + 1 
    
  return matrix 
  
  
def ge_bw(matrix):
  rows = len(matrix)
  
  columns = len(matrix[0])
  
  #find the last non zero row at the bottom
  if matrix [rows-1][columns-1] == 0:
    for i in range(rows -1, -1, -1):
      if matrix[i][columns-1] != 0:
        lastrow = i
  else:
    lastrow = rows
  
        
  rowiterator = rows - 1
  columniterator = columns - 2 
  
  while (columniterator >= 0) and (rowiterator >= 0):

      
    #normalize, divide by coeff
    if matrix[rowiterator][columniterator] != 1 and matrix[rowiterator][columniterator] != 0:
      
      coeff = matrix [rowiterator][columniterator]
      
      for i in range (len(matrix[0])):
        if matrix[rowiterator][i] != 0:
          
          matrix[rowiterator][i] = matrix[rowiterator][i] / coeff
  


    #add multiples of last row
    
    scalarcounter = rowiterator - 1

    while (scalarcounter >= 0):
      
      if matrix[rowiterator][columniterator] != 0 :
      
        scalar = matrix[scalarcounter][columniterator] / matrix[rowiterator][columniterator]
      
      else:
        
        scalar = 0
      
    
      for columncounter in range(0, columns):
        
          matrix[scalarcounter][columncounter] = matrix[scalarcounter][columncounter] - (scalar * matrix[rowiterator][columncounter])       
          
      scalarcounter = scalarcounter - 1
    
    #print "subtract"
    #for i in range (rows):
      #print matrix[i]
        
    rowiterator = rowiterator - 1
    columniterator = columniterator - 1

  return matrix 
