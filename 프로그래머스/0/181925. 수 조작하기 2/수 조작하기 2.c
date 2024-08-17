#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numLog_len은 배열 numLog의 길이입니다.
char* solution(int numLog[], size_t numLog_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*numLog_len);
    int index = 0;
    int n = 0; 
    
    n = numLog[0]; 
    
    for(size_t i=1; i<numLog_len; i++){
        if(numLog[i] == n+1){
            answer[index++] = 'w';
        }
        else if(numLog[i] == n-1){
            answer[index++] = 's';
             
        }
        else if(numLog[i] == n+10){
            answer[index++] = 'd';
        }
        else if(numLog[i] == n-10){
            answer[index++] = 'a';
        }
        n = numLog[i]; 
    }
   answer[index] = '\0';
    return answer;
}

int main(void){
    int numLog[] = {0, 1, 0, 10, 0, 1, 0, 10, 0, -1, -2, -1};
    size_t numLog_len = sizeof(numLog)/sizeof(numLog[0]); 
    char* result = solution(numLog,numLog_len);
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}