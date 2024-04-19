#include <stdio.h>
#include <stdlib.h>

int solution(int array[], size_t array_len) {
    int maxCount = 0;
    int mode = 0;
    int modeCount = 0; // 최빈값이 몇 번 나왔는지 카운트합니다.

    // 각 요소의 출현 횟수를 세고, 최빈값을 찾습니다.
    for (int i = 0; i < array_len; i++) {
        int count = 0;
        for (int j = 0; j < array_len; j++) {
            if (array[j] == array[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = array[i];
            modeCount = 1; // 새로운 최빈값이 발견되었으므로, 카운트를 1로 리셋합니다.
        } else if (count == maxCount) {
            if (array[i] != mode) {
                modeCount++; // 기존 최빈값과 다른 값이 같은 횟수로 나타난 경우
            }
        }
    }

    // 최빈값이 하나인지 여러 개인지 확인합니다.
    if (modeCount > 1) {
        return -1; // 최빈값이 여러 개인 경우
    } else {
        return mode; // 유일한 최빈값을 반환합니다.
    }
}

int main() {
    int arr[] = {1, 3, 3, 3, 5, 5, 5, 2, 2};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int result = solution(arr, n);
    printf("최빈값: %d\n", result);
    return 0;
}
