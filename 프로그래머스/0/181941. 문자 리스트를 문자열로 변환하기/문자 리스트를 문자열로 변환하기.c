#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// arr_len은 배열 arr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    //동적할당 
    char* answer = (char*)malloc(sizeof(char)*arr_len+1);
    if(answer == NULL){
        printf("memory allocation failed!");
        return NULL;
    }
    
    //초기화
    answer[0] = '\0';
    
    //arr의 각 문자열을 answer에 붙이기 
    size_t pos = 0;
    for(size_t i=0; i<arr_len; i++){
        strcat(answer+pos,arr[i]);
        pos += strlen(arr[i]); 
    }
    answer[arr_len] = '\0';
    return answer;
}

int main(void){
    const char* arr[] = {"a","b","c"};
    size_t arr_len = sizeof(arr)/sizeof(arr[0]); // 3/1 = 3 
    char* result = solution(arr,arr_len); 
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}