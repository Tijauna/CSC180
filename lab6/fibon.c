#include <stdio.h>

int fibo(int n);

int main(void){
   int i;
   int z;
   printf("Enter the number of terms: ");
   scanf("%d",&i);
   for (z=0;z<i;z=z+1){
      int f = fibo(z+1);
      printf("fibo(%d)=%d\n",z,f);
   }

   return 0;
}

int fibo(int n){
   if(n < 2){
   	return n;
   }
   return fibo(n-1) + fibo(n-2);
}

