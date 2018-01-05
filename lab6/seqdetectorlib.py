# coding: utf-8
class seqdetector:


  def __init__(self):
      self.state = 0
      
#8 states of progress: "here", "are", "the", "solutions", "to", "the", "next", "exam"
  def evolve(self, word):
    if word == 'here':
      self.state = 1
      return False 
    if word == 'are' and self.state == 1:
      self.state = 2
      return False 
    if word == 'the' and self.state == 2:
      self.state = 3
      return False 
    if word == 'solutions' and self.state == 3:
      self.state = 4
      return False 
    if word == 'to' and self.state == 4:
      self.state = 5
      return False 
    if word == 'the' and self.state == 5:
      self.state = 6
      return False
    if word == 'next' and self.state == 6:
      self.state = 7
      return False
    if word == 'exam' and self.state == 7:
      self.state = 8
      return True
    else:
      self.state = 0
      return False 
  
