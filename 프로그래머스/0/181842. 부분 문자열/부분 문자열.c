#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* str1, const char* str2) {
    char answer;
    
    answer = strstr(str2,str1);
    if(answer == NULL){
        return 0;
    }
    else {
        return 1;
    }
}

int main(void){
    const char* str1="abc";
    const char* str2 = "aabcc";
    
    int result = solution(str1, str2);
    printf("%d\n", result);
    return 0;
}