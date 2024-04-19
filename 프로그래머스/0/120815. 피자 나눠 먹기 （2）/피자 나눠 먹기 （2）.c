#include <stdio.h>

// 최대 공약수를 구하는 함수
int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 최소 공배수를 구하는 함수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// 필요한 최소 피자 판 수를 계산하는 함수
int solution(int n) {
    int pizzaSlicesPerPie = 6;
    // n명과 피자 조각(6조각)의 최소 공배수를 구한 뒤, 이를 6으로 나눔
    return lcm(n, pizzaSlicesPerPie) / pizzaSlicesPerPie;
}

int main(void) {
    int n;
    printf("사람의 수를 입력하세요: ");
    scanf("%d", &n);
    printf("필요한 최소 피자 판 수: %d\n", solution(n));
    return 0;
}
