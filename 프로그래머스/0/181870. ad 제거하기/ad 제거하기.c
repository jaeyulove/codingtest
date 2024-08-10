#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* strArr[], size_t strArr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*)*strArr_len);
    size_t index = 0; 
    
    for(size_t i=0; i<strArr_len; i++){
        if(strstr(strArr[i], "ad") == NULL){
            answer[index++] = strArr[i];
        }
    }
   // answer[index+1] = '\0'; 
    return answer;        
    }

int main(void){
    const char* strArr[] = {"and","notad","abcd"};
    size_t strArr_len = sizeof(strArr)/sizeof(strArr[0]); 
    size_t strArr_len_result; 
    char* result = solution(strArr,strArr_len);
    
    size_t index =0;
    if(result != NULL){
        for(size_t i=0; i<strArr_len_result; i++){
            printf("%s", result[i]);
            free(result[i]);
        }
        free(result); 
    }
    return 0; 
}