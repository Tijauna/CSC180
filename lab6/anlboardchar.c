int anlboard( char *T, int sizeT ){
  if (sizeT != 9){
      return -1;
  }
  for(int i = 0; i<9; i++){
      if ((T[i] != 'X') && (T[i] != 'O') && (T[i] != '-')){
          return -1;
      }
  }
  char checkercounter = 'X';

  if (T[0] == T[1] && T[0] == T[2] && T[0] == checkercounter){
      return 1;
  }
  if (T[3] == T[4] && T[3] == T[5] && T[3] == checkercounter){
      return 1;
  }
  if (T[6] == T[7] && T[6] == T[8] && T[6] == checkercounter){
      return 1;
  }
  if (T[0] == T[3] && T[0] == T[6] && T[0] == checkercounter){
      return 1;
  }
  if (T[1] == T[4] && T[1] == T[7] && T[1] == checkercounter){
      return 1;
  }
  if (T[2] == T[5] && T[2] == T[8] && T[2] == checkercounter){
      return 1;
  }
  if (T[0] == T[4] && T[0] == T[8] && T[0] == checkercounter){
      return 1;
  }
  if (T[2] == T[4] && T[2] == T[6] && T[2] == checkercounter){
      return 1;
  }
  
  checkercounter = 'O';

  if (T[0] == T[1] && T[0] == T[2] && T[0] == checkercounter){
      return 2;
  }
  if (T[3] == T[4] && T[3] == T[5] && T[3] == checkercounter){
      return 2;
  }
  if (T[6] == T[7] && T[6] == T[8] && T[6] == checkercounter){
      return 2;
  }
  if (T[0] == T[3] && T[0] == T[6] && T[0] == checkercounter){
      return 2;
  }
  if (T[1] == T[4] && T[1] == T[7] && T[1] == checkercounter){
      return 2;
  }
  if (T[2] == T[5] && T[2] == T[8] && T[2] == checkercounter){
      return 2;
  }
  if (T[0] == T[4] && T[0] == T[8] && T[0] == checkercounter){
      return 2;
  }
  if (T[2] == T[4] && T[2] == T[6] && T[2] == checkercounter){
      return 2;
  }
 

  int movespossible = 0;
  for (int z = 0; z < 9; z++){
      if (T[z] == '-'){
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
      
