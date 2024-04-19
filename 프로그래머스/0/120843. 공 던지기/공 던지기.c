#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int numbers[], size_t numbers_len, int k) {
    // 인덱스를 계산
    int index = (k * 2 - 2) % numbers_len;
    
    return numbers[index];
}

int main(void){
    int numbers[] = {1, 2, 3, 4};
    int k = 2; 
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]); 
    int result = solution(numbers, numbers_len, k);
    
    printf("%d", result);
    return 0; 
}
