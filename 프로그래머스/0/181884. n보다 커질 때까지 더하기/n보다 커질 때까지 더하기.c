#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len, int n) {
    int answer = 0;
    

    for(int i=0; i<numbers_len; i++){
        if(answer <= n){
           answer += numbers[i]; 
        }   
       /* if(answer < n){
            return answer;  
        } */
    }
    return answer;
}

int main(void){
    int numbers[] = {34, 5, 71, 29, 100, 34};
    size_t numbers_len = sizeof(numbers)/ sizeof(numbers[0]); 
    int n = 123;
    
    int result = solution(numbers,numbers_len, n);
    printf("%d", result);
    return 0; 
}