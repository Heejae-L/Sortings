#include <stdio.h>
void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void bubble(int* array, int size){
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j<size; j++){
            if(array[i]>array[j]){
                swap(array+i, array+j);
            }
        }
    }
}

int main(){
    int array[10] = {3,1,5,2,4,8,10,9,7,6};
    print_arr(array,10);
    bubble(array, 10);
    print_arr(array,10);

    return 0;
}