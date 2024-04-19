#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(num1, num2)
{
    int result;
    
    result = num1 - num2;
    
    return result;
}

int main(void)
{
    printf("Result:%d\n", solution(2,3));
    printf("Result:%d\n", solution(2,98));

    return 0; 
}