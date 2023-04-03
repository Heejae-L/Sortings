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

void selection(int *array, int size){
    int min_idx;
    for(int i=0; i<size-1; i++){
        min_idx = i;
        for(int j=i+1; j<size; j++){
            if(array[min_idx]>array[j])
                min_idx = j;
        }
        if(i!=min_idx) swap(array+i,array+min_idx);

    }
}

int main(){
    int array[10] = {3,1,5,2,4,8,10,9,7,6};
    print_arr(array,10);
    selection(array, 10);
    print_arr(array,10);

    return 0;
}