#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// flag_len은 배열 flag의 길이입니다.
int* solution(int arr[], size_t arr_len, bool flag[], size_t flag_len,int result_len){
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*(arr_len*20));
    int index = 0; 
    
    for(size_t i=0; i<arr_len; i++){
        if(flag[i] == true){
            for(size_t j=0; j<arr[i]*2; j++){
                answer[index++] = arr[i];    
            }
        }
        else {
            index -=arr[i]; 
        }
    }
    result_len = index; 
    return answer;
}

int main(void){
int arr[] = {3, 2, 4, 1, 3}; 
size_t arr_len = sizeof(arr)/sizeof(arr[0]); 
bool flag[] = {true, false, true, false, false}; 
size_t flag_len = sizeof(flag)/sizeof(flag[0]); 
int result_len = 0; 

int* result= solution(arr,arr_len,flag,flag_len,result_len); 

if(result != NULL){
    for(size_t i=0; i<result_len; i++){
    printf("%d ", result[i]);
    }
}
  return 0;    
}