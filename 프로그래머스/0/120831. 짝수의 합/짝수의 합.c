#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
int sum = 0; 
int i, temp;
    
    for (i=0; i<num; i++){
        temp = num-i;
        if(temp % 2 == 0) sum += temp;   
    }
    return sum; 
}

int main(void){
    int num, result;
    
    num=10;
    result = solution(num);
    printf("%d", result);
        
    num=4;
    result = solution(num);
    printf("%d", result);
    
    return 0; 
}