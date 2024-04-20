#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int* solution(int array[], size_t array_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)* 2);
    
    if(answer == NULL){
        printf("memory alloc failed");
        return 1; 
    }

    int max_value = array[0];
    int index = 0;
    for(int i=0; i<array_len; i++){
            if(array[i]>max_value){
                max_value = array[i];
                answer[0] = array[i];
                answer[1] = i;
            }
    }
    return answer;
}

int main(void){
    int array[] = {1,8,3};
    size_t array_len = sizeof(array)/sizeof(array[0]);
    int* result = solution(array, array_len);
    
    if(result == NULL){
        printf("memory alloc failed");
        return 1; 
    }
    else {
        for(int i=0; result[i] !=0; i++){
            printf("%d ", result[i]);
            free(result); 
        }
        return 0; 
    }
}