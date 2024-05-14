#include <stdio.h>

int find_gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(int a, int b) {
    int gcd = find_gcd(a, b); 
    b /= gcd;  // 분모를 gcd로 나누어 기약분수의 분모를 얻음
    
    while (b % 2 == 0) b /= 2;  // 2로 나눌 수 있는 만큼 나눔
    while (b % 5 == 0) b /= 5;  // 5로 나눌 수 있는 만큼 나눔
    
    // 2와 5로 완전히 나누어 떨어지면 유한소수
    if (b == 1) return 1;
    else return 2;  // 그 외의 경우에는 무한소수
}

int main(void) {
    int a = 7, b = 20;
    int result = solution(a, b);
    printf("%d", result);  // 예상 출력: 1
    return 0;
}
