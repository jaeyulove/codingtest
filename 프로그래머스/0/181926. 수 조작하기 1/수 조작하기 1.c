#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(int n, const char* control) {
    
    size_t len = strlen(control); 
    
    for(int i=0; i<len; i++){
        control[i] == 'w'?n+=1:0;
        control[i] == 's'?n-=1:0; 
        control[i] == 'd'?n+=10:0; 
        control[i] == 'a'?n-=10:0; 
    }
    return n;
}

int main(void){
    int n = 0; 
    const char* control = "wsdawsdassw";
    int result = solution(n, control); 
    printf("%d\n", n); 
}