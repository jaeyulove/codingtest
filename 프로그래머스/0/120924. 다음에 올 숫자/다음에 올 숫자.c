#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) {
    if (common_len < 2) return -1; // 배열 길이가 2 미만인 경우 처리

    int answer = 0; 
    int d = common[1] - common[0];
    int r = (common[0] != 0) ? common[1] / common[0] : 0; // 0 나누기 예외 처리
    
    bool isArithmetic = true;
    bool isGeometric = (common[0] != 0); // common[0]이 0이면 등비수열이 아님

    // 등차수열 검사
    for (int i = 0; i < common_len - 1; i++) {
        if (common[i] + d != common[i + 1]) {
            isArithmetic = false;
            break;
        }
    }

    // 등비수열 검사
    if (isGeometric) {
        for (int i = 0; i < common_len - 1; i++) {
            if (common[i] * r != common[i + 1]) {
                isGeometric = false;
                break;
            }
        }
    }

    if (isArithmetic) {
        answer = common[common_len - 1] + d;
    } else if (isGeometric) {
        answer = common[common_len - 1] * r;
    } else {
        return -1; // 어느 수열도 아님
    }
    return answer;
}

int main(void) {
    int common[] = {1, 2, 3, 4};
    size_t common_len = sizeof(common) / sizeof(common[0]);
    
    int result = solution(common, common_len);
    printf("%d", result);
    return 0;
}
