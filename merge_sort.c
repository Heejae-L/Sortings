#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print_arr(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void merge(int* arr, int size){
    if(size==1){
        return;
    }
    //make two empty arrays and split entered array into two empty arrays
    int* left = (int*)malloc(sizeof(int)*size/2);
    int* right = (int*)malloc(sizeof(int)*size-size/2);
    
    int cur=0;
    for(int k=0; k<size/2; k++){
        left[k] = arr[cur++];
    }
    for(int k=0; k<size-size/2; k++){
        right[k] = arr[cur++];
    }
    //recursive fuction call
    merge(left,size/2);
    merge(right,size-size/2);

    //merge two arrays
    cur=0;
    int cur1=0, cur2=0;

    while(cur<size){
        if(left[cur1]<right[cur2]){
            arr[cur++]=left[cur1++];
        }
        else{
            arr[cur++]=right[cur2++];
        }
        if(cur1==size/2 || cur2 == size-size/2)
            break;
    }
    while(cur1<size/2){
        arr[cur++]=left[cur1++];
    }
    while(cur2<size-size/2){
        arr[cur++]=right[cur2++];
    }
    
    free(left);
    free(right);

}
int main(){
    int array[SIZE] = {3,1,5,2,4,8,10,9,7,6};
    print_arr(array,SIZE);
    merge(array, SIZE);
    print_arr(array,SIZE);

    return 0;
}