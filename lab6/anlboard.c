int anlboard( int *T, int sizeT ){
  if (sizeT != 9){
      return -1;
  }
  int i = 0;
  for (i = 0; i<9; i++){
      if ((T[i] != 0) && (T[i] != 1) && (T[i] != 2)){
          return -1;
      }
  }
  int checkercounter = 1;
  while (checkercounter <= 2){

      if (T[0] == T[1] && T[0] == T[2] && T[0] == checkercounter){
          return checkercounter;
      }
      if (T[3] == T[4] && T[3] == T[5] && T[3] == checkercounter){
          return checkercounter;
      }
      if (T[6] == T[7] && T[6] == T[8] && T[6] == checkercounter){
          return checkercounter;
      }
      if (T[0] == T[3] && T[0] == T[6] && T[0] == checkercounter){
          return checkercounter;
      }
      if (T[1] == T[4] && T[1] == T[7] && T[1] == checkercounter){
          return checkercounter;
      }
      if (T[2] == T[5] && T[2] == T[8] && T[2] == checkercounter){
          return checkercounter;
      }
      if (T[0] == T[4] && T[0] == T[8] && T[0] == checkercounter){
          return checkercounter;
      }
      if (T[2] == T[4] && T[2] == T[6] && T[2] == checkercounter){
          return checkercounter;
      }
      checkercounter = checkercounter + 1;
  }
  int movespossible = 0;
  int z = 0;
  for (z = 0; z < 9; z++){
      if (T[z] == 0){
          movespossible = 1;
      }
  }
  if(movespossible == 0){
      return 3;
  }
  else{
      return 0;
  }
}
      
