#include <stdio.h> // this is needed to provide access to the standard IO
                   // (or input/output) library for printf, or scanf

float bsqrt(float x, float accuracy);
float myAbs(float x);

int main(void) {
   int i;
   for(i=0;i<10;i++){
      float sqrt;
      sqrt = bsqrt((float)i,0.001);
      printf("The sqrt of  %d is %f\n",i,sqrt);
   }
   return 0;
}

float myAbs(float x){		
   if (x<0){
      x = (x*(-1));
   }
   return x;
}

float bsqrt(float x, float accuracy){
   float guess;
   guess = x/2;
   while (myAbs((guess*guess)- x) > accuracy){
      guess = 0.5*(guess + x/guess);
   }
   return guess;
}

