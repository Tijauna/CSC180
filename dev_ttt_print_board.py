# coding: utf-8
# %load dev_ttt_print_board.py
def printBoard (T):
    rowcounter = 0
    smallcounter = 0
    limit = 2
    if (len(T) > 9): #for too many positions
         return False
    for i in range (0, 8, 1): #for invalid list values
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
