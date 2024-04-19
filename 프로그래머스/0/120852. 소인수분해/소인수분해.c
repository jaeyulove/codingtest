#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)* 10); 
    int index = 0;
    
    if(answer == NULL){
        printf("memory alloc failed");
        return NULL; 
    }
    
    for(int i=2; n>1; i++) {
        while(n % i == 0) {
        answer[index++] = i; 
            while(n%i ==0){ 
            n /= i;
            }
        }
                
        
        if(index >= 10) {
            answer = (int*)realloc(answer, sizeof(int) * (index + 10)); 
            if (answer == NULL) {
                printf("reallocation failed\n");
                free(answer);
                return NULL; 
            }
        }
    }
    
 answer = (int*)realloc(answer, sizeof(int) * index);
    if(answer == NULL) {
        printf("final realloc failed\n");
        free(answer);
        return NULL; 
    }
    return answer;
}
