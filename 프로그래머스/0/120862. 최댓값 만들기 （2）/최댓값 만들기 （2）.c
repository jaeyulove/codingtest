#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int numbers[], size_t numbers_len) {
    int answer = 0; 
    int max = numbers[0]*numbers[1]; 
    for(int i=0; i<numbers_len-1; i++){
        for(int j=i+1; j<numbers_len; j++){
            if(numbers[i]*numbers[j] > max){
                max = numbers[i]*numbers[j]; 
            }
        }
    }
    return max;
}

int main(void){
    int numbers[] = {1,2,-3,4,-5}; 
    size_t numbers_len = sizeof(numbers)/sizeof(numbers[0]);
    int result = solution(numbers, numbers_len); 
    printf("%d", result); 
    
    return 0; 
}
