# coding: utf-8
class stack:
    store = []
    
    def push(self,x):
        self.store = self.store + [x]
    
    def pop(self):
        try:      
            rval = self.store[len(self.store)-1]
        except:
            return False
        self.store = self.store[0:len(self.store)-1]
        return rval
    
    def disp(self):
        if (len(self.store) == 0):
            return False
        for i in range(0,len(self.store)):
            print self.store[i],"<--top--" if i==0 else ""
            
