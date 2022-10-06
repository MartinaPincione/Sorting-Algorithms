#include <stdio.h>
#include <stdlib.h>

void insertionsort(int* list, int cur_size){
    
    int i, j;  
    for (i=1; i< cur_size; i++ ){
        int cur_num = list[i];
        j = i - 1;
        while (j >= 0 && cur_num < list[j]){
            list[j+1] = list[j]; //
            j--;
        }
        
        list[j+1] = cur_num;
    }
}

int main(int argc, char* argv[]){
    int cap = 2;
    int cur_size = 0;
    int* list = malloc(sizeof(int)* cap);
    FILE* file;
    file = fopen(argv[1], "r");
    
    int digit;
    while (fscanf(file, "%d", &digit) != EOF){
        if (cur_size == cap){
            cap *= 2;
            list = realloc(list, sizeof(int)*cap);
        }
        list[cur_size] = digit;
        cur_size++;
    }

    fclose(file);

    printf("Numbers list before sorting is: [");
    for (int i =0; i < cur_size; i++){
        printf("%d ", list[i]);
    }
    printf("]\n");
    
   
    insertionsort(list, cur_size);

    printf("Numbers list after sorting is: [");
    for (int i =0; i < cur_size; i++){
        printf("%d ", list[i]);
    }
    printf("]\n");

    free(list);
    return 0;
}
