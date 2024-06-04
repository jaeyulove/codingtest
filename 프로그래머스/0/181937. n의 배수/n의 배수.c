#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int n) {
  
    if(num % n == 0){
        return 1;
    }
    
    else if(num % n != 0){
        return 0; 
    }
}

int main(void){
    int num = 98;
    int n = 2;
    int result = solution(num,n);
    
    printf("%d\n", num); 
    return 0; 
}