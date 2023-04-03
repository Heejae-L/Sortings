#include <stdio.h>

void print_arr(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int* array, int size){
    for(int i=0; i<size; i++){
        for(int j = i; j>0; j--){
        if(array[j]<array[j-1])
            swap(array+j, array+j-1);
        }
    }
}

int main(){
    int array[10] = {3,1,5,2,4,8,10,9,7,6};
    print_arr(array,10);
    insertion(array, 10);
    print_arr(array,10);

    return 0;
}