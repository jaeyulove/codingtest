#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* n_str) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*10);
    
    int n_str_num = atoi(n_str); 
    
    sprintf(answer, "%d", n_str_num);
    
    return answer;
}

int main(void){
    const char* n_str = "0010";
    char* result = solution(n_str);
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    else {
        printf("memory allocation failed");
    }
    return 0; 
}