#include <stdio.h>
#include <stdlib.h>
#include <math.h> // fabs 함수 사용

int compare(const void *a, const void *b, void *n) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    int pivot = *(int *)n;

    // n과의 차이 계산
    int diff1 = fabs(arg1 - pivot);
    int diff2 = fabs(arg2 - pivot);

    // 차이가 같을 경우 큰 숫자를 먼저 위치
    if (diff1 == diff2) {
        return (arg2 - arg1);
    }

    return (diff1 - diff2);
}

int* solution(int numlist[], size_t numlist_len, int n) {
    int* answer = malloc(sizeof(int) * numlist_len);
    if (answer == NULL) {
        return NULL; // 메모리 할당 실패 시
    }

    // 원본 배열 복사
    for (int i = 0; i < numlist_len; i++) {
        answer[i] = numlist[i];
    }

    // 정렬
    qsort_r(answer, numlist_len, sizeof(int), compare, &n);

    return answer;
}

int main(void) {
    int numlist[] = {1, 2, 3, 4, 5, 6};
    int n = 4;
    size_t numlist_len = sizeof(numlist) / sizeof(numlist[0]);
    int* result = solution(numlist, numlist_len, n);

    for (int i = 0; i < numlist_len; i++) {
        printf("%d ", result[i]);
    }
    free(result); // 할당된 메모리 해제
    return 0;
}
