#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) {
    
    int lamb = 12000;
    int drink = 2000;
    int service_drink = n/10; 

    int sum = (k*drink)-(service_drink*drink)+(n*12000);
    return sum;
}

int main(void){
    int lamb = 12000;
    int drink = 2000;
    int n,k, result;
    
    n=10;
    k=3;
    result =solution(n,k);
    printf("%d\n", result);
    
    n=64;
    k=6;
    result =solution(n,k);
    printf("%d\n", result);
    
    return 0;
}