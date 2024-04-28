#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int solution(const char* my_string) {
    size_t len = strlen(my_string);
    char* buffer = strdup(my_string); 
    int num = 0;
    int total = 0;
    bool is_number = false;

    for(int i=0; i<len; i++){
        if(isdigit(buffer[i])) {
             num = num * 10 + (buffer[i] - '0'); 
             is_number = true; 
        } else {
            //연속된 숫자의 시퀀스가 끝났고, 숫자가 아닌 다른 문자를 시작
            if(is_number){ 
                total += num;
                num=0;
                is_number = false; 
            }
        }
    }
    
    if (is_number) total += num; // 마지막으로 누적된 숫자가 있으면 추가
    
    free(buffer);
    return total;
}

int main(void){
    const char* my_string = "aAb1B2cC34oOp";
    int result = solution(my_string);
    
    printf("%d", result); 
    return 0; 
}