#include "hamming.h"

/* Q1: read a string of arbitrary length from the standard input. The string is linefeed (\n)
       terminated. Think carefully of where memory is coming from as there is no upper 
       bound on the string length.
       input: none
       ouput: a pointer to a buffer container the string read. It ought to be a valid string
              (\0 terminated)
*/
char* readString()
{
    int cap = 2;
    int cur_size = 0;
   char* string = (char*)malloc(sizeof(char)*cap);
   char c;
   while ( (c = getchar()) != '\n' ){
       if (cur_size == cap){
           cap *= 2;
           string = realloc(string, sizeof(char) * cap);
       }
       string[cur_size] = c;
       cur_size++;
   }
   string[cur_size] = '\0';

   return string; 
}

/* Q2: compute the hamming distance between two strings. The strings are expected to be the 
       same length. The hamming distance is the number of indices where the string differ. 
       input: s1 : pointer to string 1
              s2 : pointer to string 2
       output: integer: the number of indices where the string disagree
       Note: 1. this should work for strings of any length. 
             2. You can assume that s1 and s2 have the same length.
*/

int computeHD(char* s1,char* s2)
{
    int hd = 0;
    //number of indices where the strings differ
    if (strlen(s1) != strlen(s2)){
        hd++;
    }
    if (strlen(s1) > strlen(s2)){
        //size of the first string is greater than the size of the second string
        int i = 0;
        while (s2[i] != '\0'){
            if (s2[i] != s1[i]){
                hd++;
            } 
            i++;           
        }
    }
    else{
        //else you can assume the size of s2 is greater than or equal to
        int i =0;
        while (s1[i] != '\0'){
            if (s1[i] != s2[i]){
                hd++;
            }
            i++;
        }
    }
    

   return hd; 
}
