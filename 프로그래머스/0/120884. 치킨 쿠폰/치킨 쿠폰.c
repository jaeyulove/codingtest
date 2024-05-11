#include <stdio.h>
#include <stdlib.h>

int solution(int chicken) {
    int coupons = 0;
    int totalChickens = chicken;

    while (chicken >= 10) {
        int freeChickens = chicken / 10;  // 무료로 받을 수 있는 치킨 수
        coupons += freeChickens;          // 총 쿠폰 수에 추가
        chicken = (chicken % 10) + freeChickens;  // 남은 치킨 + 무료 치킨
    }

    return coupons;
}

int main(void) {
    int chicken = 100;
    int result = solution(chicken);
    printf("무료로 받을 수 있는 치킨 수: %d\n", result);
    return 0;
}
