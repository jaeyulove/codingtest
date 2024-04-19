#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int money) {
    int* answer = (int*)malloc(sizeof(int) * 2 );
    int coffee = 5500; 
    
    answer[0] = money/coffee;
    answer[1] = money-coffee * answer[0]; 

    return answer;
}

int main(void){
    
    int cup, money; 
    int * result; 
    money = 15000; 
    int i; 
    
    result = solution(money);
    
    for(i=0; i<2; i++){
    printf("%d", result[i]);
    }
    return 0; 
}