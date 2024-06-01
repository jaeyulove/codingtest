#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    if(n % 2 == 0){
        for(int i=1; i<=n; i++){
            if(i % 2 == 0){
                answer += i*i; 
            }
        }
    }
    
    else if(n % 2 != 0){
        for(int i=0; i<=n ; i++){
            if(i%2 != 0){
                answer += i; 
            }
        }
    }
    return answer;
}

int main(void){
    int n = 7;
    int result = 16; 
    
    printf("%d\n", result); 
    return 0; 
}