#include <stdio.h>
#include <stdlib.h>

int solution(int num, int k) {
    char str[10]; 
    sprintf(str, "%d", num); // 숫자를 문자열로 변환
    int len = 0;
    while (str[len] != '\0') len++; // 문자열 길이 계산

    for (int i = 0; i < len; i++) {
        if (str[i] - '0' == k) {
            return i + 1; // 위치를 1부터 세기 위해 1을 추가
        }
    }
    return -1; 
}

int main(void) {
    int num = 232443;
    int k = 4;
    int result = solution(num, k);
    printf("Result: %d\n", result);
    return 0;
}
