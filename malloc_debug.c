/*tegmentation fault or a silent error in your program.
   Specifically, in printArray, we deliberately cause the for loop
   to go far beyond the arg size.

   How would you debug this?

   We'll if you got a segmentation fault, and if that was reproducible,
   (and that's an *if*) then perhaps a bunch of print statements may help
   you get to the point of failure.

   But what if you didn't get segmentation faults: the problem with dealing
   with pointers/addresses --- the computer in its raw state --- is that
   you may go and overwrite variables in your program. This wouldn't gen
   a seg fault, but would rather result in erroneous operation.

   You'd see the erroneous operation only if you STRENUOULSY verified
   your software, testing it for cases that would stimulate the
   error. Again, a big *if*.

   Fortunately, we're programming with C and we have 2017-1972 years of
   engineering effort in creating awesome tools to help debug.

   The classic tool is gdb --- the debugger. We'll skip this for now, and
   introduce another modern tool: valrind.

   DO THE FOLLOWING:
   1. compile this program: gcc -pedantic malloc_debug.c
   2. run it: ./a.out
   3. can you see it failing or generating output that is sketchy?
   4. now run: valgrind ./a.out
   5. READ THE WHOLE TRANSCRIPT of what valgrind reports.
      Can you see an indication of a problem?

   Like with python and C programming, you MUST learn how to read the output
   of tools from a computer. Practice your reading comprehension skills
   (technical reading comprehension) by parsing the output from valgrind.

   Valgrind also indicates that I forgot to do something in the program below.
   What is that?

   Hint: every malloc requires a call to another function when you want to
   release the allocated memory. What is that call? Do I do it here?

   As you can see valgrind is an ESSENTIAL tool for anyone dealing with
   pointers. USE IT.
*/

#include <stdio.h>
#include <stdlib.h>

int printArray(int *array, int size) {
    int i = 0;

    if (array == NULL) {
       /* this means the user didn't send in a properly allocated pointer;
 *           we must return at this point because if we try to get the values
 *                     from an improperly allocated pointer --- we'll either:
 *                               - generate a segmentation fault if our access goes beyond the
 *                                           segment that the program owns
 *                                                     - overwrite other variables of our program --- silently ---
 *                                                                 causing the program to work erroneously without us having
 *                                                                             any warning
 *                                                                                    */
       return -1;
    }

    for (i=0;i<size*2;i=i+1){ /* ERROR injected here ... size*2 should be size*/
       printf("element %d is %d\n",i,array[i]);
    }
    return 0;
}

int main(void) {
   int *x = NULL;
   int size = 0;
   int i = 0;
   int r = 0;

   /* pretend we asked the user for a size and got that size via scanf */
   size=10;
   x = (int *) malloc (sizeof(int) * size);

   for(i=0;i<size;i++){
      x[i]=i*10;
   }

   r=printArray(x,size);
   if (r != 0) {
       printf("ERR: printArray failed\n");
   }

   /* ERROR: another problem with this code is I forgot to call a vital
 *       function here. What is that? How does valgrind tell you this? */
   return 0;
}
