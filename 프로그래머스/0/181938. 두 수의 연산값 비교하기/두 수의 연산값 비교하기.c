#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int concat(int a, int b) {
    // 두 정수를 문자열로 변환한 후 붙입니다.
    char str1[20];
    char str2[20];
    sprintf(str1, "%d", a);
    sprintf(str2, "%d", b);
    strcat(str1, str2);
    return atoi(str1);
}

int solution(int a, int b) {
    int answer = 0;
    
    int ab_concat = concat(a,b); 
    int ab_product = 2 * a * b; 
    
    if(ab_concat >= ab_product) {
        return ab_concat; 
    }
    
    else {
        return ab_product; 
    }
}

int main(void){
    int a = 2;
    int b = 91;
    int result = solution(a,b); 
    printf("%d\n", result); 
    
    return 0; 
}