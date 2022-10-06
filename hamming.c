#include "hamming.h"

/* Q3: Write a test program that reads two strings from the standard input (of arbitrary lengths)
       and compute their hamming distance. The user input is not guaranteed to give strings
       of the same length!
       
       Your code cannot have memory leaks or memory corruptions. We will check with valgrind.

   Example:
   input:
   qwerty uiop asdf
   qwerty ui0p a3df
   output:
   hd:2

   Don't forget to handle the case of inputs of different lengths.
*/

int main()
{
    int hd;
    char* s1 = readString();
    char* s2 = readString();

    hd = computeHD(s1, s2);
    printf("hd:%d\n",hd);

    free(s1);
    free(s2);
   return 0;
}
