#include <stdio.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // 동적 할당된 결과 배열을 준비
    int* answer = (int*)malloc(sizeof(int) * queries_rows);

    for (size_t i = 0; i < queries_rows; i++) {
        int start = queries[i][0];
        int end = queries[i][1];
        int refer_p = queries[i][2];
        int min_value = -1; 

        for (int j = start; j <= end; j++) {
            if (arr[j] > refer_p) {
                if (min_value == -1 || arr[j] < min_value) {
                    min_value = arr[j];
                }
            }
        }

        // 결과를 answer 배열에 저장
        answer[i] = min_value;
    }

    return answer;
}

int main(void) {
    int arr[] = {0, 1, 2, 4, 3};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    // 2차원 쿼리 배열 동적 할당 및 초기화
    size_t queries_rows = 3;
    size_t queries_cols = 3;
    int** queries = (int**)malloc(queries_rows * sizeof(int*));
    for (size_t i = 0; i < queries_rows; i++) {
        queries[i] = (int*)malloc(queries_cols * sizeof(int));
    }

    // 쿼리 값 초기화
    queries[0][0] = 0; queries[0][1] = 4; queries[0][2] = 2;
    queries[1][0] = 0; queries[1][1] = 3; queries[1][2] = 2;
    queries[2][0] = 0; queries[2][1] = 2; queries[2][2] = 2;

    // solution 함수 호출
    int* result = solution(arr, arr_len, queries, queries_rows, queries_cols);

    // 결과 출력
    for (size_t i = 0; i < queries_rows; i++) {
        printf("Query %zu result: %d\n", i, result[i]);
    }

    // 동적 할당 메모리 해제
    free(result);
    for (size_t i = 0; i < queries_rows; i++) {
        free(queries[i]);
    }
    free(queries);

    return 0;
}
