#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
       return num1 + num2; 
}

int main(void){
    int num1, num2, result;
    
    num1=2;
    num2=3;
    result = solution(num1,num2);
    printf("result : %d", result);
    
    num1=100;
    num2=2;
    result = solution(num1, num2);
    printf("result : %d", result);
    
    return 0;
}