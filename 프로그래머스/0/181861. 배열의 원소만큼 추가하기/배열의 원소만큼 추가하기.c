#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int result_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*10000);
    int index = 0; 
    
    for(size_t i=0; i<arr_len; i++){
        for(size_t j=0; j<arr[i]; j++){
            answer[index++] = arr[i]; 
        }
    }
    return answer;
}

int main(void){
    int arr[] = {5,1,4};
    size_t arr_len = sizeof(arr)/sizeof(arr[0]);  
    int result_len=0;
    
    for(size_t i=0; i<arr_len; i++){
        result_len += arr[i]; 
    }
    
    int* result = solution(arr,arr_len,result_len);
    
    if(result != NULL){
        for(size_t i=0; i<result_len; i++){
            printf("%d", result[i]);
        }
        free(result);
    }
    return 0; 
}