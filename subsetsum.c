#include <stdio.h>
#include <stdlib.h>
#include "subsetsum.h"


int main(int argc,char* argv[])   
{

   int n, s;

   scanf("%d %d ", &n, &s);

   int list[n];
   int i =0;
   int temp;
   while(i < n){
       scanf("%d", &temp);
       list[i] = temp;
       i++;
   }

   subSetSum(n, s, list);

   return 0; 
}
