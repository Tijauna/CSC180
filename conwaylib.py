# coding: utf-8
from random import randint
from rule import rule 

class conway:
  def __init__(self,Y, X, inputType):
      #sizeY is rows
      #sizeX is cols
      self.sizeX = X
      self.sizeY = Y
      if(inputType == 'zeros'):
          self.store = [[0 for i in range(X)] for j in range(Y)]
      if(inputType == 'ones'):
          self.store = [[1 for i in range(X)] for j in range(Y)]
      elif(inputType == 'random'):
          self.store = [[(randint(0,1)) for i in range(X)] for j in range(Y)]

  def evolve(self,rule):
      self.nextState = [[0 for i in range(self.sizeX)] for j in range(self.sizeY)]
      rows = self.sizeY
      cols = self.sizeX
      
      for i in range (0,rows):
        for j in range (0,cols):

          value = self.store[i][j]
          listinput = self.getNeighbours(i, j)
          
          result = rule(value, listinput)
          self.nextState[i][j] = result
      self.store = self.nextState
    
  def getDisp(self):
      self.string = ""
      for i in self.store:
          for j in i:
              if(j == 1):
                  self.string += str("*")
              else:
                  self.string += str(" ")
          self.string += "\n"
      return self.string

  def printDisp(self):
      self.getDisp()
      print(self.string)
      return True

  def setPos(self, row, column, value):
      if(row<0 or column<0 or row>self.sizeY-1 or column>self.sizeX-1):
          return False
      if(value != 1 and value != 0):
          return False
      self.store[row][column] = value
      return True

  def getNeighbours(self, row, col):
      if(row<0 or col<0 or row>self.sizeY-1 or col>self.sizeX-1):
          return False
      counter = 0
      out = [None]*8

      for i in range(row-1, row+2):
          if(i < 0):
              i += self.sizeY
          if(i >= self.sizeY):
              i -=self.sizeY
          for j in range(col-1, col+2):
              if(i==row and j == col):
                  continue
              if(j < 0):
                  j += self.sizeX
              if(j >= self.sizeX):
                  j -=self.sizeX
              out[counter] = self.store[i][j]
              counter+=1
      return out
      
   
