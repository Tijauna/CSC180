int ge_fw(float *matrix, int rows, int cols, float *matrix_out) {

  int r=0;
  int c=0;
  
  int i = 0;
  int z = 0;
  float scalar = 0;
  
  int rowcounter = 0;
  int columncounter = 0;
  float swaptemp = 0;
  int scalarcounter = 0;
  
  
  if (matrix==NULL) {
    return -1;
  }
  if (matrix_out==NULL) {
    return -1;
  }
  
  /*copy the matrix in to matrix out */
  for(r=0;r<rows;r=r+1) {
    for(c=0;c<cols;c=c+1) {
       matrix_out[r*cols + c] = matrix[r*cols + c];
    }
  }
  
  r = 0;
  c = 0;
  
  while ((c < cols) && (r < rows)){
   
    if (matrix_out[r*cols + c] == 0){
      
      /*iterate the rows for swaps*/
      for (i = 0; i<rows;i++){
      
         
        if (matrix_out[i*cols+c] != 0){
         /*swap*/
         swaptemp = matrix_out[r*cols +c];
         matrix_out[r*cols + c] = matrix_out[i*cols + c];
         matrix_out[i*cols + c] = swaptemp;
       }
       
      }
      
    }
    
    /*get zeroes underneath the first value in the column*/
    for (rowcounter = r + 1; rowcounter < rows; rowcounter++){
      
      scalarcounter = 0;
      
      
      while (scalarcounter < r+1){
        
        if (matrix_out[rowcounter*cols + c] != 0){
          
          /*keep the scalar multiple*/
          scalar = (matrix_out[rowcounter*cols + c] / matrix_out[r*cols + c]);
          
          /*apply the subtraction across all column*/
          for (columncounter=0; columncounter < cols; columncounter++){ 
          
            matrix_out[rowcounter*cols + columncounter] = matrix_out[rowcounter*cols + columncounter] - (scalar * matrix_out[r*cols + columncounter]);
    
          }
          
        }
        
        else{
          
          scalar = 0;
        }
        
        scalarcounter = scalarcounter + 1;
      }
     
    }
    
    r = r + 1;
    c = c + 1;
  } 
  return 0;
}



int ge_bw(float *matrix, int rows, int cols, float *matrix_out){
  int r = 0;
  int c = 0;
  int i = 0;
  int coeff = 0;
  int scalarcounter = 0;
  int columncounter = 0;
  int scalar = 0;
  
  if (matrix==NULL) {
    return -1;
  }
  if (matrix_out==NULL) {
    return -1;
  }
  
  /*copy the matrix in to matrix out*/
  for(r=0;r<rows;r=r+1) {
    for(c=0;c<cols;c=c+1) {
       matrix_out[r*cols + c] = matrix[r*cols + c];
    }
  }
  
  r = rows - 1;
  c = cols - 2;
  
  while (c >= 0 && r >= 0){
    
    /*normalize*/
    if (matrix_out[r*cols + c] != 1 && matrix_out[r*cols + c] != 0){
      coeff = matrix_out [r*cols + c];
      
      for (i = 0; i < cols; i++){
        if (matrix_out[r*cols + i] != 0){
          matrix_out[r*cols + i] = (matrix_out[r*cols + i] / coeff);
        }
      }
      
    }
    
    /*add multiples of last row */
    scalarcounter = r - 1;
    
    while (scalarcounter >=0){
      if (matrix_out[r*cols + c] != 0){
        scalar = matrix_out[scalarcounter*cols + c] / matrix_out[r*cols + c];
      }
      
      else{
        
        scalar = 0;
      }
      
      for (columncounter = 0; columncounter < cols; columncounter++){
        matrix_out[scalarcounter*cols + columncounter] = matrix_out[scalarcounter*cols + columncounter] - (scalar*matrix_out[r*cols + columncounter]);
        
      
      }
      scalarcounter = scalarcounter - 1;
    }
    
    r = r - 1;
    c = c - 1;
  }
  
  return 0;
  
}
