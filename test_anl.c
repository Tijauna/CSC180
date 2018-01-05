#include <stdio.h>
#include <stdlib.h>

#include "anlboard.c"
/*#include "anlboardchar.c"*/

void main(int argc,char *argv[]){
   int t1[]= { 0,2,0, 0,0,2, 1,1,0 };
   int t2[]= { 1,1,1, 0,0,0, 0,0,0 };
   int t3[]= { 0,0,0, 1,1,1, 0,0,0 };
   int t4[]= { 0,0,0, 0,0,0, 1,1,1 };
   int t5[]= { 2,2,2, 0,0,0, 0,0,0 };
   int t6[]= { 0,0,0, 2,2,2, 0,0,0 };
   int t7[]= { 0,0,0, 0,0,0, 2,2,2 };
   int t8[]= { 1,2,1, 1,2,1, 2,1,2 };
   int r;
   float score=0, total=0;

   total += 100; 
   r=anlboard(t1,9); if (r==0) score+=100;
   r=anlboard(t2,9); if (r==1) score+=100;
   r=anlboard(t3,9); if (r==1) score+=100;
   r=anlboard(t4,9); if (r==1) score+=100;
   r=anlboard(t5,9); if (r==2) score+=100;
   r=anlboard(t6,9); if (r==2) score+=100;
   r=anlboard(t7,9); if (r==2) score+=100;
   r=anlboard(t8,9); if (r==3) score+=100;

   printf("SCORE:\"%s\",%d\n",argv[1],(int)(score*100/total));
}
