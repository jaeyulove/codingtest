#include <stdio.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int result_len) {
    size_t cmp = 1; 
    while (cmp < arr_len) {
        cmp *= 2;
    }

    int* answer = (int*)malloc(sizeof(int) * cmp);

    for (size_t i = 0; i < arr_len; i++) {
        answer[i] = arr[i];
    }

    for (size_t i = arr_len; i < cmp; i++) {
        answer[i] = 0;
    }

    result_len = cmp;
    return answer;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    int result_len = 0;
    int* result = solution(arr, arr_len, &result_len);

    if (result != NULL) {
        for (int i = 0; i < result_len; i++) {
            printf("%d\n", result[i]);
        }
        free(result);
    }
    return 0;
}
