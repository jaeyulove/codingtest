#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int* solution(int numer1, int denom1, int numer2, int denom2) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    int commonDenom = lcm(denom1, denom2);
    
    numer1 *= commonDenom / denom1;
    numer2 *= commonDenom / denom2;
    
    int sumNumer = numer1 + numer2;
    int gcdResult = gcd(sumNumer, commonDenom); // 합친 분수의 분자와 분모의 최대공약수를 구함
    
    // 결과 분수를 기약분수로 만듦
    answer[0] = sumNumer / gcdResult;
    answer[1] = commonDenom / gcdResult;
    
    return answer;
}

int main() {
    int numer1 = 1, denom1 = 3, numer2 = 2, denom2 = 5;
    int* result = solution(numer1, denom1, numer2, denom2);
    printf("Result: %d/%d\n", result[0], result[1]);
    free(result); // 동적 할당된 메모리 해제
    return 0;
}
