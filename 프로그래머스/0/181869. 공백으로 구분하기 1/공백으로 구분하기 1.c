#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t my_string_len = strlen(my_string); 
    char* temp;
    char** answer = (char**)malloc(sizeof(char*)*500);
    
    temp = strtok(my_string," "); 
    
    size_t i=0;
    while(temp != NULL){ 
        answer[i++] = temp;
        temp = strtok(NULL," "); 
    }
    answer[i] = '\0';
    return answer;
}

int main(void){
    const char* my_string = "i love you";
    const char* result = solution(my_string); 
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}