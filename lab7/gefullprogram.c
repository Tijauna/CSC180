#include<stdio.h>
#include<stdlib.h>

int ge_fw(float *matrix, int rows, int cols, float *matrix_out);
int ge_bw(float *matrix, int rows, int cols, float *matrix_out);
int print(float *matrix, int rows, int cols);

int print(float *matrix, int rows, int cols) {
   int r=0;
   int c=0;

   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         printf("%8.3f",matrix[r*cols + c]);
      }
      printf("\n");
   }
   return 0;
}

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
  
  //copy the matrix in to matrix out 
  for(r=0;r<rows;r=r+1) {
    for(c=0;c<cols;c=c+1) {
       matrix_out[r*cols + c] = matrix[r*cols + c];
    }
  }
  
  r = 0;
  c = 0;
  
  while ((c < cols) && (r < rows)){
   
    if (matrix_out[r*cols + c] == 0){
      
      //iterate the rows for swaps
      for (i = 0; i<rows;i++){
      
         
        if (matrix_out[i*cols+c] != 0){
         //swap
         swaptemp = matrix_out[r*cols +c];
         matrix_out[r*cols + c] = matrix_out[i*cols + c];
         matrix_out[i*cols + c] = swaptemp;
       }
       
      }
      
    }
    
    //get zeroes underneath the first value in the column
    for (rowcounter = r + 1; rowcounter < rows; rowcounter++){
      
      scalarcounter = 0;
      
      
      while (scalarcounter < r+1){
        
        if (matrix_out[rowcounter*cols + c] != 0){
          
          //keep the scalar multiple
          scalar = (matrix_out[rowcounter*cols + c] / matrix_out[r*cols + c]);
          
          //apply the subtraction across all columns 
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
  
  //copy the matrix in to matrix out 
  for(r=0;r<rows;r=r+1) {
    for(c=0;c<cols;c=c+1) {
       matrix_out[r*cols + c] = matrix[r*cols + c];
    }
  }
  
  r = rows - 1;
  c = cols - 2;
  
  while (c >= 0 && r >= 0){
    
    //normalize
    if (matrix_out[r*cols + c] != 1 && matrix_out[r*cols + c] != 0){
      coeff = matrix_out [r*cols + c];
      
      for (i = 0; i < cols; i++){
        if (matrix_out[r*cols + i] != 0){
          matrix_out[r*cols + i] = (matrix_out[r*cols + i] / coeff);
        }
      }
      
    }
    
    //add multiples of last row 
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

int main(void) {
   int rows=0, cols=0;
   float *m=NULL, *n=NULL; /* init value for ptrs */
   int r=0,c=0;
   int idx=0;
   int rval=0;

   printf("How many rows? ");
   scanf("%d",&rows);
   printf("How many cols? ");
   scanf("%d",&cols);

   /* dynamically allocate matrices m and n
      Note: malloc returns NULL if it failed; i.e., if the computer
      was unable to allocate memory as requested */
   m = (float *)malloc(sizeof(int)*rows*cols);
   if (m==NULL) {
      printf("ERR: failed to allocate m; malloc failed\n");
      return -1;
   }
   n = (float *)malloc(sizeof(int)*rows*cols);
   if (n==NULL) {
      printf("ERR: failed to allocate n; malloc failed\n");
      return -1;
   }
  

   /* construct the matrix with some dank data */
   m[0] = 1;
   m[1] = 3;
   m[2] = -5;
   m[3] = 2;
   m[4] = 3;
   m[5] = 11;
   m[6] = -9;
   m[7] = 4;
   m[8] = -1;
   m[9] = 1;
   m[10] = 6;
   m[11] = 5;
   
   /* first step in debugging: print
      second step in debugging: roll your own convenient print function */
   printf("INFO: the input matrix is:\n");
   rval = print(m,rows,cols);
   /* if a function produces a return val ALWAYS CHECK THE RETURN VAL
      Do Not Be Lazy ... */
   if (rval != 0) {
      printf("ERR: print returned a non-zero status\n");
      return -1;
   }

   //fowards
   rval = ge_fw(m, rows, cols, n);
   if (rval != 0) {
      printf("ERR: ge_blah returned a non-zero status\n");
      return -1;
   }
   printf("INFO: the forward resultant matrix is:\n");
   rval = print(n,rows,cols);
   if (rval != 0) {
      printf("ERR: print returned a non-zero status\n");
      return -1;
   }
   
   //copy n to m, reinput 
   int y = 0;
   int b = 0;
   for(y=0;y<rows;y=y+1) {
    for(b=0;b<cols;b=b+1) {
       m[y*cols + b] = n[y*cols + b];
    }
  }
   
   //backwards
   rval = ge_bw(m, rows, cols, n);
   if (rval != 0) {
      printf("ERR: ge_blah returned a non-zero status\n");
      return -1;
   }
   printf("INFO: the backward resultant matrix is:\n");
   rval = print(n,rows,cols);
   if (rval != 0) {
      printf("ERR: print returned a non-zero status\n");
      return -1;
   }

   return 0;
}
