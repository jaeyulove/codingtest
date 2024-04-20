#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*500);
    int index = 0;
    
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            answer[index++] = i;
        }
    }
    
    int* resized = realloc(answer,sizeof(int)*index);
    if(resized != NULL){
        answer = resized;
    }
    return answer;
}

int main(void){
    int n = 24;
    int* result = solution(n);
    if(result != NULL){
        int* answer = result;
        free(result); 
    }
    else {
        printf("memory alloc failed"); 
    }
    return 0; 
}