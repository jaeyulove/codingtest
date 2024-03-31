#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    int i;
    // 정수 배열을 위한 메모리 동적 할당
    int* answer = (int*)malloc(sizeof(int) * num_list_len);
    
    // 배열의 순서를 뒤집어서 answer에 저장
    for(i = 0; i < num_list_len; i++) {
        answer[i] = num_list[num_list_len - 1 - i];
    }
    
    return answer;
}

int main(void) {
    int num_list[] = {1, 2, 3, 4, 5};
    size_t num_list_len = sizeof(num_list) / sizeof(int); // 배열의 길이 계산
    int* reversed_array;
    int i;
    
    reversed_array = solution(num_list, num_list_len); // 뒤집힌 배열 받기
    
    for(i = 0; i < num_list_len; i++) {
        printf("%d ", reversed_array[i]);
    }
    
    free(reversed_array); // 동적 할당된 메모리 해제
    
    return 0;
}
