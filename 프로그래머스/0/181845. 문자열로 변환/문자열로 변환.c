#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * n);
    sprintf(answer, "%d", n);

    return answer;
}

int main(void){
    int n = 123;
    char* result= solution(n);
    
    if(result != NULL){
    printf("%s\n", result);
    free(result); 
    }
    else {
        printf("memory allocation failed!\n");
    }
    return 0; 
}