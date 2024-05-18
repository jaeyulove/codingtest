#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* myString) {
    size_t len = strlen(myString); 
    char* answer = (char*)malloc(sizeof(char)*(len+1));
    if(answer == NULL){
        printf("memory alloc failed"); 
        return NULL; 
    }
    strcpy(answer, myString); 
    
    for(int i=0; i<len; i++){
        if(answer[i] >= 97){
            answer[i] -= 32;  
        }
    }
    answer[len] = '\0'; 
    return answer;
}

int main(void){
    const char myString = "aBcDeFg";
    char* result = solution(myString); 
    
    if(result != NULL){
    printf("%s", result);
    }
    
    else{
        printf("memory alloc failed"); 
    }
    return 0; 
}