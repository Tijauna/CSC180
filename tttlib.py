# coding: utf-8
class ttt:
  
  T = [0,0,0,0,0,0,0,0,0,]
  
 
  def __init__(self):
    self.T=[0 for i in range(0,9)]


  def copy(self,source):
    if len(self.T) != len(source.T):
      return False
    else:
      for i in len(self.T):
        self.T[i]=source.T[i]
      return True

 
  def Move(self,x,player):
    T = self.T
    if ((player != 1) and (player != 2)): #not a player
      return False
    elif ((x < 0) or (x > 8)): #not a valid position 
      return False
    elif (T[x] == 0): #check if board is occupied
      T[x] = player 
      return True 
    else:
      return False 
 
  def genRandomMove(self,player):
    T = self.T
    movespossible = 0
    for z in range (0, 9, 1): #check if moves possible
      if (T[z] == 0):
        movespossible = 1
    if (movespossible == 0):
      return -1
    if (len(T) > 9): #for too many positions
      return -1
    for i in range (0, 9, 1): #for invalid list values
      if ((T[i] != 0) and (T[i] != 1) and (T[i] != 2)):
        return -1
    movegenerated = 0
    from random import randint
    while (movegenerated == 0):
      move = randint (0,8)
      if (T[move] == 0):
        return move
        movegenerated = 1
        
  def genWinningMove(self,player):
    T = self.T
    movespossible = 0
    for z in range (0, 9, 1): #check if moves possible
      if (T[z] == 0):
        movespossible = 1
    if (movespossible == 0):
      return -1
    if (len(T) > 9): #for too many positions
      return -1
    for i in range (0, 9, 1): #for invalid list values
      if ((T[i] != 0) and (T[i] != 1) and (T[i] != 2)):
        return -1
    #begin checking for winning cases:
    #horizontal
    if ((T[0] == T[1] == player) and (T[2] == 0)):    
      return 2
    if ((T[3] == T[4] == player) and (T[5] == 0)):    
      return 5
    if ((T[6] == T[7] == player) and (T[8] == 0)):    
      return 8
    if ((T[1] == T[2] == player) and (T[0] == 0)):    
      return 0
    if ((T[4] == T[5] == player) and (T[3] == 0)):    
      return 3
    if ((T[7] == T[8] == player) and (T[6] == 0)):    
      return 6
    if ((T[0] == T[2] == player) and (T[1] == 0)):    
      return 1
    if ((T[3] == T[5] == player) and (T[4] == 0)):    
      return 4  
    if ((T[6] == T[8] == player) and (T[7] == 0)):    
      return 7
    #vertical
    if ((T[0] == T[3] == player) and (T[6] == 0)):    
      return 6
    if ((T[1] == T[4] == player) and (T[7] == 0)):    
      return 7
    if ((T[2] == T[5] == player) and (T[8] == 0)):    
      return 8 
    if ((T[3] == T[6] == player) and (T[0] == 0)):    
      return 0
    if ((T[4] == T[7] == player) and (T[1] == 0)):    
      return 1
    if ((T[5] == T[8] == player) and (T[2] == 0)):    
      return 2    
    if ((T[0] == T[6] == player) and (T[3] == 0)):    
      return 3
    if ((T[1] == T[7] == player) and (T[4] == 0)):    
      return 4
    if ((T[2] == T[8] == player) and (T[5] == 0)):    
      return 5 
    #diagonal
    if ((T[0] == T[8] == player) and (T[4] == 0)):    
      return 4
    if ((T[2] == T[6] == player) and (T[4] == 0)):    
      return 4
    if ((T[0] == T[4] == player) and (T[8] == 0)):    
      return 8  
    if ((T[4] == T[8] == player) and (T[0] == 0)):    
      return 0
    if ((T[2] == T[4] == player) and (T[6] == 0)):    
      return 6
    if ((T[4] == T[6] == player) and (T[2] == 0)):    
      return 2
    #could not find winning case 
    else:
      return -1
      
  def genNonLoser(self,player):
    T = self.T
    movespossible = 0
    for z in range (0, 9, 1): #check if moves possible
      if (T[z] == 0):
        movespossible = 1
    if (movespossible == 0):
      return -1
    if (len(T) > 9): #for too many positions
      return -1
    for i in range (0, 9, 1): #for invalid list values
      if ((T[i] != 0) and (T[i] != 1) and (T[i] != 2)):
        return -1
    if (player == 1):
      enemy = 2
    if (player == 2):
      enemy = 1
    player = enemy
    #begin checking for losing cases:
    #horizontal
    if ((T[0] == T[1] == player) and (T[2] == 0)):    
      return 2
    if ((T[3] == T[4] == player) and (T[5] == 0)):    
      return 5
    if ((T[6] == T[7] == player) and (T[8] == 0)):    
      return 8
    if ((T[1] == T[2] == player) and (T[0] == 0)):    
      return 0
    if ((T[4] == T[5] == player) and (T[3] == 0)):    
      return 3
    if ((T[7] == T[8] == player) and (T[6] == 0)):    
      return 6
    if ((T[0] == T[2] == player) and (T[1] == 0)):    
      return 1
    if ((T[3] == T[5] == player) and (T[4] == 0)):    
      return 4  
    if ((T[6] == T[8] == player) and (T[7] == 0)):    
      return 7
    #vertical
    if ((T[0] == T[3] == player) and (T[6] == 0)):    
      return 6
    if ((T[1] == T[4] == player) and (T[7] == 0)):    
      return 7
    if ((T[2] == T[5] == player) and (T[8] == 0)):    
      return 8 
    if ((T[3] == T[6] == player) and (T[0] == 0)):    
      return 0
    if ((T[4] == T[7] == player) and (T[1] == 0)):    
      return 1
    if ((T[5] == T[8] == player) and (T[2] == 0)):    
      return 2    
    if ((T[0] == T[6] == player) and (T[3] == 0)):    
      return 3
    if ((T[1] == T[7] == player) and (T[4] == 0)):    
      return 4
    if ((T[2] == T[8] == player) and (T[5] == 0)):    
      return 5 
    #diagonal
    if ((T[0] == T[8] == player) and (T[4] == 0)):    
      return 4
    if ((T[2] == T[6] == player) and (T[4] == 0)):    
      return 4
    if ((T[0] == T[4] == player) and (T[8] == 0)):    
      return 8  
    if ((T[4] == T[8] == player) and (T[0] == 0)):    
      return 0
    if ((T[2] == T[4] == player) and (T[6] == 0)):    
      return 6
    if ((T[4] == T[6] == player) and (T[2] == 0)):    
      return 2
    #could not find winning case 
    else:
      return -1
        
  def printBoard (self):
      T = self.T
      rowcounter = 0
      smallcounter = 0
      limit = 2
      if (len(T) > 9): #for too many positions
           return False
      for i in range (0, 9, 1): #for invalid list values
          if ((T[i] != 0) and (T[i] != 1) and (T[i] != 2)):
              return False
      while (rowcounter <= 2):#big loop, 2 rows = 1 iteration
          print '',
          while(smallcounter <= limit):
              if (T[smallcounter] == 0):
                  a = str(smallcounter)
              if (T[smallcounter] == 1):
                  a = 'X'
              if (T[smallcounter] == 2):
                  a = 'O'
              if (smallcounter != limit):
                  print a,
                  print '|',
              else:
                  print a
              smallcounter = smallcounter + 1
          if (rowcounter != 2):
              print "---|---|---"
          rowcounter = rowcounter +1
          limit = limit + 3
      return True
  
  def analyzeBoard(self):
      T = self.T
      if (len(T) > 9): #for too many positions
          return -1
      for i in range (0, 9, 1): #for invalid list values
          if ((T[i] != 0) and (T[i] != 1) and (T[i] != 2)):
              return -1
      checkercounter = 1
      while (checkercounter <= 2): ##check for win
          if (T[0] == T[1] == T[2] == checkercounter):
              return checkercounter
          if (T[3] == T[4] == T[5] == checkercounter):
              return checkercounter
          if (T[6] == T[7] == T[8] == checkercounter):
              return checkercounter
          if (T[0] == T[3] == T[6] == checkercounter):
              return checkercounter
          if (T[1] == T[4] == T[7] == checkercounter):
              return checkercounter
          if (T[2] == T[5] == T[8] == checkercounter):
              return checkercounter
          if (T[0] == T[4] == T[8] == checkercounter):
              return checkercounter
          if (T[2] == T[4] == T[6] == checkercounter):
              return checkercounter
          checkercounter = checkercounter + 1
      movespossible = 0
      for z in range (0, 9, 1):
          if (T[z] == 0):
              movespossible = 1
      if (movespossible == 0):
          return 3
      else:
          return 0
      
