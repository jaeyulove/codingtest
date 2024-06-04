#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number, int n, int m) {
    int answer = 0;
    
    if(number % n == 0 && number % m == 0){
        return 1;
    }
    
    else {
        return 0; 
    }
}

int main(void) {
    int number = 60;
    int n = 2;
    int m = 3;
    int result = solution(number, n, m);
    
    printf("%d\n", result); 
    return 0; 
}