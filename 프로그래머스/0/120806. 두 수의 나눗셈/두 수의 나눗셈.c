#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    return (int)((double)num1 / num2 * 1000);
}

int main(void) {
    int num1, num2, result;
    num1 = 3;
    num2 = 2;
    result = solution(num1, num2);
    printf("%d", result);
    
    num1 = 7;
    num2 = 3;
    result = solution(num1, num2);
    printf("%d", result);
    
    num1 = 1;
    num2 = 16;
    result = solution(num1, num2);
    printf("%d", result);

    return 0;
}