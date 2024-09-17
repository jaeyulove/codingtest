#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(int q, int r, const char* code) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
   
    size_t code_len = strlen(code);     
    char* answer = (char*)malloc(sizeof(char)*(code_len+1));
    int index = 0; 
    
    for(size_t i=0; i<code_len; i++) {
        if(i % q == r) {
            answer[index++] = code[i]; 
        }
    }
    answer[index] = '\0'; 
    return answer;
}

int main(void) {
    int q = 3;
    int r = 1;
    const char* code = 	"qjnwezgrpirldywt"; 
    
    int* result = solution(q,r,code);
    
    if(result != NULL) {
        printf("%s\n", result); 
        free(result);
    }
    return 0; 
}