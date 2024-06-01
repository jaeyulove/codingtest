#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_suffix) {
    size_t my_string_len = strlen(my_string); 
    size_t is_suffix_len = strlen(is_suffix); 
    int count = 0; 
    int answer = 0; 
    
    //"banana" + 6 - 3 (시작 주소 + 6 - 3 )
    if(strcmp(my_string + my_string_len - is_suffix_len, is_suffix) == 0){
        return 1; 
     } 
    else {
        return 0; 
    }
    
    return answer;
}

int main(void){
    const char* my_string = "banana"; 
    const char* is_suffix = "ana";
    int result = solution(my_string, is_suffix); 
    
    printf("%d\n", result); 
    return 0; 
}