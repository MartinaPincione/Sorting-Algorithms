#include "subsetsum.h"
#include <stdio.h>

/* 
 * This function has 3 inputs and will produce on stdout the list of subsetsum in lexicographic
 * increasing order
 * n : the number of integers in the input set
 * s : the target sum to reach 
 * t : an array of size n with the integers present in the input set.
 * output: none. Only side-effects on the standard output
 */ 

 void aux(int n, int s, int t[n], int comp_index, int arr_index, int arr[n]){
     if ((s == 0) && (comp_index == n)){
         printf("sss:[");
         for (int i =0; i< arr_index; i++){
             printf("%d ", arr[i]);
         }
         printf("]\n");
     }
     else if (comp_index == n){
         return;
     }
     else{
         //including the comp_num in the arr 
         arr[arr_index] = t[comp_index];
         aux(n, s - t[comp_index], t, comp_index + 1, arr_index + 1, arr);
         //excluding the comp_num in the arr 
         aux(n, s, t, comp_index + 1, arr_index, arr);         
     }
 }
void subSetSum(int n,int s,int t[n])
{
    int arr[n];
    int num_arr=0;
    int arr_index=0;
    aux(n, s, t, num_arr, arr_index, arr);
   // TODO(Q4.1): Implement this routine
}
