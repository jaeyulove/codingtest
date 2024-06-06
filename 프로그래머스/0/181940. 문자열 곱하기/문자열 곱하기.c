#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t my_string_len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char) * (my_string_len * k) +1);
    
    strcpy(answer, my_string); 
    
    for(int i=0; i<k-1; i++) {
        strcat(answer, my_string); 
    } 
    return answer;
}

int main(void) {
    char my_string = "string";
    int k = 3;
    char* result = solution(my_string, k);
    
    if (result =! NULL) {
        printf("%s", result); 
        free(result); 
    }
    
    else {
        printf("memory allocation failed"); 
    }
    
    return 0; 
}