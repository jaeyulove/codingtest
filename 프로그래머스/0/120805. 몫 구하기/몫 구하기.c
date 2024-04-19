#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = num1/num2;
    return answer;
}

int main(void)
{
    int num1, num2,answer;
    
    num1 = 10;
    num2 = 5;
    
    solution(num1, num2);
    answer = solution;
    printf("num1 : %d num2 : %d result : %d", num1, num2, answer);
    
    return 0; 
}