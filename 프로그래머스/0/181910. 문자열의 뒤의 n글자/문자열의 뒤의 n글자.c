#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(n*sizeof(char)+1);
    size_t len = strlen(my_string); 
    
    for(int i =0; i<n; i++){
        answer[i] = my_string[len-n+i];
    }
    answer[n] = '\0'; 
    return answer;
}

int main(void){
    const char* my_string = "ProgrammerS123"; 
    int n = 11; 
    char* result = solution(my_string, n); 
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    
    else {
        printf("memory allicaton failed"); 
    }
    return 0; 
}