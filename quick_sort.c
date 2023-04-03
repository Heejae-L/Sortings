#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 

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

void quick(int *array, int start, int end){
    if(end-start<=0) return;

    int pivot = start;
    int low = start+1, high = end-1;

    while(low<=high){
        if(array[low]>array[pivot]&&array[high]<=array[pivot]){
            swap(array+low,array+high);
            low++;
            high--;
        }
        else if(array[low]>array[pivot]&&array[high]>array[pivot])
            high--;
        else if(array[low]<=array[pivot]&&array[high]<=array[pivot])
            low++;
        else{
            low++;
            high--;
        }
    }
    swap(array+pivot,array+high);

    quick(array,start,high);
    quick(array,low,end);
}

int main(){
    int array[SIZE] = {3,1,5,2,4,8,10,9,7,6};
    print_arr(array,SIZE);
    quick(array, 0, SIZE);
    print_arr(array,SIZE);

    return 0;
}