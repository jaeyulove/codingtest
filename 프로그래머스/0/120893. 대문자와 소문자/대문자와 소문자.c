#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char)* (len+1));
    
    if(answer == NULL){
        printf("memory alloc failed");
        return NULL;
    }
    
    for(size_t i=0; i<len; i++){
        if(my_string[i] == tolower(my_string[i])){
            answer[i] = toupper(my_string[i]);
        }
        else if(my_string[i] == toupper(my_string[i])){
            answer[i] = tolower(my_string[i]); 
        }   
         
    }
    answer[len] = '\0'; 
    return answer;
}

int main(void){
    const char* my_string = "cccCCC";
    char* result = solution(my_string);
    
    if(result != NULL){
        printf("%s\n", result);
        free(result); 
    } else {
        printf("memory alloc failed");
    }
    
    return 0; 
}