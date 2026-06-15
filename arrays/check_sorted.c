#include <stdio.h>

int check_sorted(int* arr, int arr_len);

int main(){

    int array[] = {1,2,2,2,2,3,4,5};
    
    int arr_len = (sizeof(array) / sizeof(int));
    printf("%d\n",check_sorted(array, arr_len));

    return 0;
}


int check_sorted(int* arr, int arr_len){
    
    for (int i = 0; i < arr_len - 1; i++){

        if (arr[i] > arr[i+1]){
            return 0;
        }
    }

    return 1;
}