#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    
    // 2~n까지의 수를 루트n 나머지를 구해서 합성수를 찾음
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break; // 소수가 아니라면 루프 종료
            }
        }
        if (!isPrime && i != 1) {
            answer++; // 합성수일 경우 개수 증가
        }
    }
    return answer;
}

int main(void) {
    int n = 10;
    int result = solution(n); 
    printf("%d\n", result); // 10 이하 합성수의 개수
    
    n = 15;
    result = solution(n);
    printf("%d\n", result); // 15 이하 합성수의 개수
    return 0;
}
