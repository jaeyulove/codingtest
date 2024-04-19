#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


long long solution(int n, int k) {
    
   long long result = 1; 
    for(int i = 1; i<=k; i++){
        result = result * (n-i+1)/i; 
    }
    return result; 
}

int main(void){
    int balls = 3; 
    int share = 2; 
    
    int result = solution(balls, share); 
    printf("%lld", result);
    
    return 0; 
}