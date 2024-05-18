#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    int* answer = (int*)malloc(sizeof(int)*arr_len);
    
    for(int i=0; i<arr_len; i++){
        if(arr[i]>= 50 && arr[i]%2 == 0){
            answer[i] = arr[i] / 2; 
        } else if(arr[i]<50 && arr[i]%2 != 0){
            answer[i] = arr[i] * 2; 
        } else { 
            answer[i] = arr[i];
        }
    }
    return answer;
}

int main(void){
    int arr[] = {1, 2, 3, 100, 99, 98}; 
    size_t arr_len = sizeof(arr)/sizeof(arr[0]); 
    int* result = solution(arr,arr_len); 
    
    if(result != NULL){
        for(int i =0; i<arr_len; i++){
          printf("%d", result[i]);
       }
        free(result);
    }
    
    else {
        printf("memory allocation failed \n"); 
    }
    return 0;
}