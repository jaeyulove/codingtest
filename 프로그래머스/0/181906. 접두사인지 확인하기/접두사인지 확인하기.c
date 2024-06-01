#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_prefix) {
    size_t is_prefix_len = strlen(is_prefix); 
    int count = 0; 
    int answer = 0;
    
    if(strncmp(my_string,is_prefix,is_prefix_len) == 0){
        answer = 1;
    } 
    
    return answer;
}

int main(void){
    const char* my_string = "banana";
    const char* is_prefix = "ban";
    
    int result = solution(my_string,is_prefix);
    printf("%d", result);
    return 0;
}