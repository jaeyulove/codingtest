#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    if(num1>=0 && num1<=100 && num2>=0 && num2<=100)
        if(num1 == num2)
            return 1;
            else 
                return -1;
}

int main(void)
{
    int num1, num2, result; 
    
    num1 = 2;
    num2 = 3;
    result = solution(num1, num2);
    printf("num1 : %d num2 : %d result : %d", num1, num2, result);
    
    num1 = 11;
    num2 = 11;
    result = solution(num1, num2);
    printf("num1 : %d num2 : %d result : %d", num1, num2, result);
    
    
    num1 = 7;
    num2 = 99;
    result = solution(num1, num2);
    printf("num1 : %d num2 : %d result: %d", num1, num2 , result);
    
    return 0; 
}

