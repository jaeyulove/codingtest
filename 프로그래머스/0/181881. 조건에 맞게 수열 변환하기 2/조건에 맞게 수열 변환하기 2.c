#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 0;
    bool identical = false;
    
    // 배열이 변하지 않을 때까지 반복
    while (!identical) {
        identical = true;  // 매 반복마다 동일성 여부 확인

        // 배열의 각 원소를 규칙에 따라 변경
        for (int i = 0; i < arr_len; i++) {
            int original_value = arr[i];  // 원본 값 저장

            // 규칙에 따른 값 변경
            if (arr[i] >= 50 && arr[i] % 2 == 0) {
                arr[i] /= 2;
            } else if (arr[i] < 50 && arr[i] % 2 != 0) {
                arr[i] = arr[i] * 2 + 1;
            }

            // 값이 변경되었으면 identical = false로 설정
            if (arr[i] != original_value) {
                identical = false;  // 변동이 생겼으므로 반복을 계속
            }
        }
        // identical == false 라면 
        if (!identical) {
            answer++;  // 배열이 변했을 경우 반복 횟수 증가
        }
    }
    
    return answer;
}

int main(void) {
    int arr[] = {1, 2, 3, 100, 99, 98};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    int result = solution(arr, arr_len);
    
    printf("%d\n", result);
    return 0;
}
