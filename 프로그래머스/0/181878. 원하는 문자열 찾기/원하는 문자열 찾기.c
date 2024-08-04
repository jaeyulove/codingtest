#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 문자열을 소문자로 변환하는 함수
char* strlwr(char* str) {
    char* orig = str;
    while (*str) {
        if(*str >= 'A' && *str <= 'Z'){
            *str = *str + 32; 
        }
        str++;
    }
    return orig;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    size_t myString_len = strlen(myString);
    size_t pat_len = strlen(pat);
    char myString_cpy[strlen(myString)+1];
    char pat_cpy[strlen(pat)+1];
    char result[pat_len+1]; 
    
    strcpy(myString_cpy, myString);
    strcpy(pat_cpy, pat);

    strlwr(myString_cpy);
    strlwr(pat_cpy); 
    
    int answer = (strstr(myString_cpy, pat_cpy) != NULL) ? 1 : 0;
    
    return answer;
}

int main(void){
    const char* myString = "AbCdEfG"; 
    const char* pat = "aBc"; 
    int* result = solution(myString,pat); 
    
    printf("%d\n", result);
    return 0; 
}