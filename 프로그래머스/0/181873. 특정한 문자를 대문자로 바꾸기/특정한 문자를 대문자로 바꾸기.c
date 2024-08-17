#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* alp) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*strlen(my_string)+1);
    size_t my_string_len = strlen(my_string); 
    
    for(size_t i=0; i<my_string_len; i++){
        if(my_string[i] == *alp){
            answer[i] = toupper(my_string[i]); 
        }
        else {
            answer[i] = my_string[i];
        }
        answer[my_string_len] = '\0';
    }
    return answer;
}

int main(void){
    const char* my_string = "programmers";
    const char* alp = 'p'; 
    char result = solution(my_string,alp); 
    
    if(result != NULL){
       printf("%s", result);
       free(result);
    }
    return 0; 
}