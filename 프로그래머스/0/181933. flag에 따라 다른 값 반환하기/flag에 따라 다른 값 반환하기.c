#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, bool flag) {
    int answer = 0;
    
    answer = flag == true ? (a + b) : (a - b); 
    
    return answer;
}

int main(void){
    int a = -4;
    int b = 7; 
    char flag = true; 
    
    int result = solution(a,b,flag);
    printf("%d\n", result); 
    
    return 0; 
}