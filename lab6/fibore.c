#include <stdio.h>

int fibo(int n);

int main(void) {
   int i;
   for (i=0;i<20;i=i++){
      int f = fibo(i+1);
      printf("fibo(%d)=%d\n",i,f);
   }

   return 0;
}

int fibo(int n){
   if(n < 2){
   	return n;
   }
   return fibo(n-1) + fibo(n-2);
}

