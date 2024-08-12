#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int** answer = (int**)malloc(sizeof(int*)*n);
    
    //각 행 동적배열 
    for(size_t i=0; i<n; i++){
        answer[i] = (int*)malloc(sizeof(int)*n); 
    }
    
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            if(i == j){
                answer[i][j] = 1; 
            }
            
            else {
                answer[i][j] = 0; 
            }
        }
    }
    return answer;
}

int main(void){
    int n = 3; 
    int** result = solution(n);
    
    if(result != NULL){
        for(size_t i=0; i<n; i++){
            for(size_t j=0; j<n; j++){
                printf("%d", result[i][j]);
                free(result[i][j]);
            }
        }
    }
    free(result); 
    return 0; 
}