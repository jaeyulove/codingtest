#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int len = n/k; 
    int* answer = (int*)malloc(sizeof(int)*len);
    
    if(answer == NULL){
        printf("memory alloc failed");
        return NULL;
    }
    
    int index = 0; 

    for(int i=1; i<len+1; i++){
        answer[index++] = i*k;
    }    
    return answer;
}

int main(void){
    int n=10;
    int k=3;
    int len = n/k; 
    int* result = solution(n,k);
    
    if(result != NULL){
        for(int i=0; i<len; i++){
            printf("%d", result[i]);
        }
    } else {
        printf("memory allloc failed\n");
    }
    return 0; 
}