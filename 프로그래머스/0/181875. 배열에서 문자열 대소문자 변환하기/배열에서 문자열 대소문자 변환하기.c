#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* strArr[], size_t strArr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*)*strArr_len+1);
    
    if(answer == NULL){
        printf("memory allocation failed.");
        return NULL;
    }
    
    size_t i,j, str_len;
    
    
    for(i=0; i<strArr_len; i++){
        str_len = strlen(strArr[i]); 
        answer[i] = (char*)malloc(sizeof(char)*str_len+1);
        
        for(j=0; j<strlen(strArr[i]); j++){  
            if(i % 2 != 0){
                answer[i][j] = toupper(strArr[i][j]); 
            } else {
                answer[i][j] = tolower(strArr[i][j]);
            }
        }
        answer[i][str_len] = '\0';
    }
    return answer;
}

int main(void){
    const char* strArr[] = {"AAA","BBB","CCC","DDD"};
    size_t strArr_len = sizeof(strArr)/sizeof(strArr[0]);
    char** result = solution(strArr, strArr_len);
    
    if(result != NULL){
        for(int i=0; i<strArr_len; i++){
          printf("%s\n", result[i]);
          free(result[i]);
      }
    }
    return 0; 
}