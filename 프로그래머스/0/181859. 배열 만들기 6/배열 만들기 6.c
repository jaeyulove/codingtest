#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int* result_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    //int* answer = (int*)malloc(sizeof(arr_len));
    //int* stk = NULL; 
    int* stk = (int*)malloc(arr_len*sizeof(int)); 
    int index = 0; 
    
    for(int i=0; i<arr_len ; i++){
        if(index == 0) {
            stk[index++] = arr[i]; 
        }
        else if(arr[i] == stk[index-1]) {
            index--; 
        }
        else if(arr[i] != stk[index-1]) {
            stk[index++] = arr[i];
        } 
      }
    
    if(index == 0) {
        stk[index++] = -1;
    }
    
    // 스택이 비어 있을 경우 [-1]을 반환
    /*if (index == 0) {
        stk = (int*)realloc(stk, sizeof(int)); // 메모리 크기 재조정
        stk[0] = -1;
        *result_len = 1;
        return stk;
    }*/
    
    result_len = index; 
    return stk;
}

int main(void){
    int arr[] = {0,1,1,1,0};
    size_t arr_len = sizeof(arr)/sizeof(arr[0]);
    int result_len = 0; 
    
    int* result = solution(arr,arr_len, &result_len);
    if(result != NULL)
    {
        for(int i=0; i<result_len; i++)
        {
            printf("%d", result[i]);
        }
    }
    free(result);
    return 0; 
}