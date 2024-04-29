#include <stdio.h>
#include <stdlib.h>

int solution(int sides[], size_t sides_len) {
    int a = sides[0];
    int b = sides[1];
    int minThirdSide = abs(a - b) + 1; // 세 번째 변의 최소 길이
    int maxThirdSide = a + b - 1;      // 세 번째 변의 최대 길이
    
    if (minThirdSide > maxThirdSide) {
        return 0; // 가능한 세 번째 변이 없는 경우
    } else {
        return maxThirdSide - minThirdSide + 1; // 가능한 세 번째 변의 개수
    }
}

int main() {
    int sides[2] = {4, 6}; // 예시 측면 길이
    int result = solution(sides, 2);
    printf("Possible third side lengths: %d\n", result);
    return 0;
}
