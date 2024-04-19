#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* my_string) {
    size_t len = strlen(my_string); 
    int* answer = (int*)malloc(sizeof(int) * len); 
    
    if(answer == NULL){
        printf("Memory allocation failed");
        return -1; 
    }
    
    // 문자를 정수로 변환 
    int count = 0;
    for(size_t i = 0; i < len; i++){
        if(my_string[i] >= '0' && my_string[i] <= '9'){
            answer[count++] = my_string[i] - '0'; 
        }
    }
    
    // 정수 합계 구하기 
    int sum = 0;
    for(int i = 0; i < count; i++){
        sum += answer[i];
    }
    
    free(answer);
    return sum; // 정수 합계 반환 
}

int main(void) {
    const char* my_string = "aAb1B2cC34oOp"; 
    int result = solution(my_string);
    
    printf("Sum of numbers: %d\n", result);
    return 0;
}
