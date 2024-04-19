#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    if(0<num1 && num1<=100 && 0<num2 && num2<=100)
    return num1%num2; 
}

int main(void)
{
    int num1,num2,answer;
    
    num1=3;
    num2=2;
    answer = solution(num1,num2);
    printf("num1 : %d num2 : %d result : %d", num1, num2, answer);
    
    num1=10;
    num2=5;
    answer = solution(num1,num2);
    printf("num1 : %d num2 : %d result : %d", num1, num2, answer);
    
    return 0; 
}