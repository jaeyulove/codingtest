#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** solution(int num_list[], size_t num_list_len, int n) {
    int rows = num_list_len / n;
    int** answer = (int**)malloc(rows * sizeof(int*)); // 각 행을 위한 포인터 할당
    if (answer == NULL) {
        printf("메모리 할당 실패\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        answer[i] = (int*)malloc(n * sizeof(int)); // 각 행의 열을 위한 메모리 할당
        if (answer[i] == NULL) {
            printf("메모리 할당 실패\n");
            return NULL; // 메모리 할당 실패 시 NULL 반환
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            answer[i][j] = num_list[i * n + j]; // 2차원 배열에 값 할당
        }
    }
    return answer;
}

int main(void) {
    int num_list[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t num_list_len = sizeof(num_list) / sizeof(num_list[0]);
    int n = 2;

    int** result = solution(num_list, num_list_len, n);
    if (result != NULL) {
        for (int i = 0; i < num_list_len / n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        // 할당된 메모리 해제
        for (int i = 0; i < num_list_len / n; i++) {
            free(result[i]);
        }
        free(result);
    } else {
        printf("결과 생성 실패\n");
    }

    return 0;
}
