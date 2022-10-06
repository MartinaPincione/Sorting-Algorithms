#include "hamming.h"


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


int computeHD(char* s1,char* s2)
{
    int hd = 0;

    if (strlen(s1) != strlen(s2)){
        hd++;
    }
    if (strlen(s1) > strlen(s2)){
        
        int i = 0;
        while (s2[i] != '\0'){
            if (s2[i] != s1[i]){
                hd++;
            } 
            i++;           
        }
    }
    else{
        
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
