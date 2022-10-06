#include <stdio.h>
#include <stdlib.h>

void bubblesort(int* list, int cur_size){

    int exit_condition = cur_size;
    while (exit_condition > 0){
        for (int i =0; i< cur_size - 1; i++){
        
            if (list[i] > list[i+1]){
                int temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
            }
        }
        exit_condition--;
    }
}

int main(){
    int cap = 2;
    int cur_size = 0;
    int* l = (int*)malloc(sizeof(int)* cap);
    int num;
    while (scanf("%d", &num) == 1){
        if (cur_size == cap){
            cap *= 2;
            l = realloc(l, sizeof(int)* cap);
        }
        l[cur_size] = num;
        cur_size++;
    }
    printf("Before sorting the list: [");
    for (int i = 0; i < cur_size; i++){
        printf("%d ", l[i]);
    }
    printf("]\n");

    printf("After sorting the list: [");
    bubblesort(l, cur_size);
    for (int i = 0; i < cur_size; i++){
        printf("%d ", l[i]);
    }
    printf("]\n");


    free(l);
    return 0;
}
