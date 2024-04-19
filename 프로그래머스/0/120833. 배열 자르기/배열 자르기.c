#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len, int num1, int num2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)* (num2-num1+1));


    if (answer == NULL) {
        printf("메모리 할당 실패 \n");
        return NULL;
    }

    int i;
    int index = 0; 
    for (i = num1; i <= num2; i++){
        answer[index++] = numbers[i];
    }
    return answer; 
}

int main(void) {
    int numbers[] = { 1,2,3,4,5 };
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);
    int num1 = 1;
    int num2 = 3; 

    int* result = solution(numbers, numbers_len, num1, num2); 

    if (result != NULL) {

        for (int i = 0; i < num2 - num1; i++) {
            printf("%d", result[i]);
        }
        free(result);
    }
  
    return 0; 
}