#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;

    if (a % 2 != 0 && b % 2 != 0) {
        // a와 b가 모두 홀수인 경우
        answer = (a*a)+(b*b);
    } else if (a % 2 == 0 && b % 2 == 0) {
        // a와 b가 모두 짝수인 경우
        answer = abs(a-b); 
    } else  {
        // 그 외의 경우
        answer = 2 * (a + b);
    }
    return answer;
}

int main(void) {
    int a = 3;
    int b = 5;
    int result = solution(a, b); 
    
    printf("%d\n", result);
    return 0; 
}
