#include <stdio.h>
#include <stdlib.h> // abs 함수 사용을 위해 필요

// n명이 최소 한 조각씩 피자를 먹으려면 필요한 최소 피자 판 수를 계산하는 함수
int solution(int slice, int n) {
    // (n + slice - 1) / slice를 사용하여 올림 효과를 내는 계산
    return (n + slice - 1) / slice;
}

int main(void) {
    int slice, n;
    printf("피자 조각 수와 사람 수를 입력하세요: ");
    scanf("%d %d", &slice, &n);

    int result = solution(slice, n);
    printf("필요한 최소 피자 판 수: %d\n", result);

    return 0;
}
