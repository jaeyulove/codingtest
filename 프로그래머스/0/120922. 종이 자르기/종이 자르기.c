#include <stdio.h>
#include <stdbool.h>

int solution(int M, int N) {
    int width = (M-1)*N;
    int length = (N-1); 
    
    return width + length; 
}

int main(void){
    int M = 2;
    int N = 2;
    
    int result = solution(M,N);
    printf("%d", result);
    return 0; 
}