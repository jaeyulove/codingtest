#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int* result_len) {
    // stk 배열을 동적으로 할당
    int* stk = (int*)malloc(sizeof(int) * arr_len);
    int stk_len = 0;  // stk 배열의 현재 길이를 관리하는 변수
    
    for (int i = 0; i < arr_len; ) {
        if (stk_len == 0) {
            // stk가 비어 있으면 arr[i]를 추가
            stk[stk_len++] = arr[i];
            i++;
        }
        else if (stk[stk_len - 1] < arr[i]) {
            // stk의 마지막 원소가 arr[i]보다 작으면 arr[i]를 추가
            stk[stk_len++] = arr[i];
            i++;
        }
        else {
            // stk의 마지막 원소가 arr[i]보다 크거나 같으면 stk에서 제거
            stk_len--;
        }
    }
    
    // 결과 배열의 길이를 업데이트
    result_len = stk_len;
    
    return stk;
}

int main(void) {
    int arr[] = {1, 4, 2, 5, 3}; 
    size_t arr_len = sizeof(arr) / sizeof(arr[0]); 
    int result_len = 0; 
    
    // solution 함수 호출
    int* result = solution(arr, arr_len, &result_len);
    
    // 결과 출력
    if (result != NULL) {
        for (int i = 0; i < result_len; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);  // 동적 메모리 해제
    }
    
    return 0; 
}
