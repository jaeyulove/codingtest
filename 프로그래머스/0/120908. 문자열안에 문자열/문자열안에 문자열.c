#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* str1, const char* str2) {
    
   return strstr(str1, str2)?1:2;
}

int main(void){
    const char* str1 = "ab6CDE443fgh22iJKlmn1o";
    const char* str2 = "6CD"; 
    
    int result = solution(str1, str2);
    printf("%d", result);
    return 0; 
}