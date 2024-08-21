#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int m, int c) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    size_t my_string_len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char)*my_string_len/m+1);
    int index = 0;
    
    for(size_t i=c-1; i<my_string_len; i++){
        answer[index++] = my_string[i]; 
        i += m-1;
    }
    answer[index] = '\0';
    return answer;
}

int main(void){
    const char* my_string = "ihrhbakrfpndopljhygc"; 
    int m = 4;
    int c = 2;
    char* result = solution(my_string,m,c);
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0;
}