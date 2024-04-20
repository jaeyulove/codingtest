#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* msg) {    
    size_t msg_len = strlen(msg);
        return (int)msg_len*2;
}

int main(void){
    int result;
    const char* msg;
    
    msg="happy birthday!";
    result = solution(msg);
    printf("%d", result);
    
    msg="I love you";
    result = solution(msg);
    printf("%d", result);
    
    return 0;
}