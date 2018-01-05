# coding: utf-8
def analyzeBoard(T):
    if (len(T) > 9): #for too many positions
        return -1
    for i in range (0, 8, 1): #for invalid list values
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
    for z in range (0, 8, 1):
        if (T[z] == 0):
            movespossible = 1
    if (movespossible == 0):
        return 3
    else:
        return 0
    
