#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int result_len) {
    int start = -1, end = -1;
    int index = 0;

    // 2가 있는지 확인 (첫 번째와 마지막 2의 위치 찾기)
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == 2) {
            if (start == -1) {
                start = i;  
            }
            end = i;  
        }
    }

    // 배열에 2가 없으면 -1을 반환해야 함
    if (start == -1 || end == -1) {
        result_len = 1;
        int* answer = (int*)malloc(sizeof(int));  
        answer[0] = -1; 
        return answer;   
    }

    // 2가 있는 구간만큼 메모리 할당
    int* answer = (int*)malloc(sizeof(int) * (end - start + 1));
    if (answer == NULL) {
        result_len = 0;
        return NULL; 
    }

    // start부터 end까지의 값을 복사
    for (int i = start; i <= end; i++) {
        answer[index++] = arr[i];
    }

    result_len = index; 
    return answer;
}

int main(void) {
    int arr[] = {1, 2, 1, 4, 5, 2, 9};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    int result_len = 0;
    int* result = solution(arr, arr_len, &result_len);

    // 결과 출력
    if (result != NULL) {
        if (result_len == 1 && result[0] == -1) {
            // 배열에 2가 없을 때
            printf("%d\n", -1);
        } else {
            // 배열에 2가 있을 때 결과 출력
            for (int i = 0; i < result_len; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
        free(result);  // 동적 할당된 메모리 해제
    }

    return 0;
}
