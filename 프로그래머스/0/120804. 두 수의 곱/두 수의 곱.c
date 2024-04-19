#include<stdio.h>

int solution(int num1, int num2){
    return num1 * num2; 
}

int main(void){
    int num1, num2, result;
    
num1=3; 
num2=4;
    
result = solution(num1, num2);
printf("num1:%d num2:%d result=%d", num1, num2, solution); 
    
num1=27;
num2=19;

result=solution(num1, num2);
printf("num1:%d num2:%d result=%d", num1, num2, solution); 
    
    return 0;
}