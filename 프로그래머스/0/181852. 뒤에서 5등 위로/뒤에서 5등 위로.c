#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 오름차순 비교 함수
// int* 는 메모리 주소를 가리키는 포인터, 역참조해서 정수값을 가져오기 
int asc_compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* solution(int num_list[], size_t num_list_len) {
    // 입력 배열을 정렬
    qsort(num_list, num_list_len, sizeof(int), asc_compare);

    // 결과 배열을 동적 할당
    int* answer = (int*)malloc(sizeof(int)*num_list_len);
    if (answer == NULL) {
        printf(stderr, "Memory allocation failed\n");
    }

    // 가장 작은 5개의 수를 제외한 요소를 결과 배열에 복사
    for (size_t i = 0; i < num_list_len-5; i++) {
        answer[i] = num_list[i + 5];
    }

    return answer;
}

int main(void) {
    int num_list[] = {12, 4, 15, 46, 38, 1, 14, 56, 32, 10};
    size_t num_list_len = sizeof(num_list) / sizeof(num_list[0]);

    int* result = solution(num_list, num_list_len);

    // 결과 배열 출력
    for (size_t i = 0; i < num_list_len-5; i++) {
        printf("%d", result[i]);
    }
    // 결과 배열 해제
    free(result);

    return 0;
}
