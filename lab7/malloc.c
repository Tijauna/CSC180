/* COMPILE THIS WITH: gcc -pedantic malloc.c */

/* PROTOTYPES */

#include<stdio.h>
#include<stdlib.h>

int computeAverage(int *data,int size,float *average);

/* END PROTOTYPES */

/* FUNCTIONS */
int main(void){
   /* VARIABLES FOR THIS { BODY } OF FUNCTION */
   int n = 0;
   int i = 0;
   int *dynArray = NULL;
   int staticArray[10];
   int status = 0;
   float avg = 0;
   /* END VARIABLES */

   /* THIS IS AN EXAMPLE OF A FAILED CALL TO THE
      FUNCTION WITH A NULL POINTER
      (because at this point dynArray has not
       been malloc'd!) */
 
   status = computeAverage(dynArray,n,&avg);
   if (status == -1) {
     printf("ERR: computeAverage failed\n");
   } else {
     printf("INFO: averae is %f\n",avg);
   }


   printf("How many numbers do you want to process?\n");
   scanf("%d",&n);
   dynArray=(int *)malloc(n*sizeof(int));

   for(i=0;i<n;i=i+1) {
      /* VARIABLES FOR THIS { BODY } OF FOR */
      int tmp = 0;
      /* END VARIABLES */

      printf("Enter a number: ");
      scanf("%d",&tmp);
      dynArray[i] = tmp;
   }

   status = computeAverage(dynArray,n,&avg);
   if (status == -1) {
     printf("ERR: computeAverage failed\n");
   } else {
     printf("INFO: average is %f\n",avg);
   }

   free(dynArray); /* NEED THIS FOR EACH MALLOC */
   return 0;
}

int computeAverage(int *data,int size,float *average) {
   /* VARIABLES FOR THIS { BODY } OF FUNCTION */
   int i = 0;
   float r = 0;
   /* END VARIABLES */

   if ((data == NULL) || (average == NULL)) {
      printf("ERR: computeAverage called with a NULL pointer\n");
      return -1;
   }

   for(i=0;i<size;i++){
      r=r+data[i];
   }
   (*average) = r/((float)size);
   return 0;
}
/* END FUNCTIONS */
