#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int slice = 7;
    
    if (n%slice==0) return n/slice;
    else if (n%slice!=0) return n/slice+1;
    else return 0; 
}

int main(void){
    int n, result;
    
    n=7;
    result=solution(n);
    printf("%d", result);
    
    n=1;
    result=solution(n);
    printf("%d", result);
    
    n=15;
    result=solution(n);
    printf("%d", result);
    
    return 0;
}

