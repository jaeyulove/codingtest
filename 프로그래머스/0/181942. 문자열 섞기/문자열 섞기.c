#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* str1, const char* str2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t str1_len = strlen(str1);
    char* answer = (char*)malloc(sizeof(char)*(str1_len*2)+1);
    int index = 0;
    
    for(size_t i=0; i<str1_len; i++){
        answer[index++] = str1[i];
        answer[index++] = str2[i];
    }
    answer[index] = '\0';
    return answer;
}

int main(void){
    const char* str1 = "aaaaa";
    const char* str2 = "bbbbb";
    
    char* result = solution(str1, str2); 
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}