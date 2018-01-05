int bubbleSort(int *array, int size){
  //already sorted 
  if (size == 1){
   return 0; 
  }
  
  //null array 
  if (array == NULL){
    return -1;
  }
  
  //check if the array matches its size, all elements assigned
  //for (int z = 0; z < size; z++){
    //if (array[z] == NULL){
      //return -1;
    //}
  //}
  
  for (int i = 0; i < (size-1); i++){
    
    for (int j = 0; j < (size-1-i); j++){
      if (array [j] > array[j+1]){
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  
  int status = 0;
  
  for (int x = 0; x < size - 1; x++){
    if (array[x] <= array[x+1]){
      status = 0;
    }
    else{
      status = -1;
      return status;
    }
  }
  return status;
}


