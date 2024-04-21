#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numlist_len은 배열 numlist의 길이입니다.
int* solution(int n, int numlist[], size_t numlist_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)* numlist_len / n);
    int index = 0; 
    for(int i=0; i<numlist_len; i++){
        if(numlist[i] % n == 0){
            answer[index++] = numlist[i];
        }
    }
    
    return answer;
}

int main(void){
    int n = 3;
    int numlist[] = {4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t numlist_len = sizeof(numlist)/ sizeof(numlist[0]);
    int* result = solution(n, numlist, numlist_len); 
    
    int index = 0;
    if(result != NULL){
        while(result != NULL){
            printf("%d", result[index++]);
        }
    }
    free(result);
    return 0; 
}