#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {

    for(int i=0; i<numbers_len; i++){
        for(int j=0; j<numbers_len -1 -i; j++){
        if(numbers[j]>numbers[j+1]){
        int temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp; 
        }
    }
}
    
    int answer = numbers[numbers_len-1] * numbers[numbers_len-2]; 

    return answer;
}

int main(void){
    int numbers[]={1,2,3,4,5};
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);
    
    int result = solution(numbers, numbers_len);
    printf("%d", result);
    
    return 0;
}