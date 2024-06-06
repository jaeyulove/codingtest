#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

int concate(int a, int b) {
    char str_a[12];
    char str_b[12]; 
    char str_ab[24];
    
    sprintf(str_a, "%d", a);
    sprintf(str_b, "%d", b);
    strcpy(str_ab, str_a);
    strcat(str_ab, str_b); 
    
    return atoi(str_ab);
}

int solution(int a, int b) {
    
    int ab = concate(a,b);
    int ba = concate(b,a); 
    
    if (ab > ba) {
        return  ab;
    }
    
    else if (ab < ba) {
        return ba; 
    }
    
    else {
        return ab; 
    }
}

int main(void) {
    int a = 9;
    int b = 91;
    
    int result = solution(a,b);
    printf("%d\n", result); 
    
    return 0; 
}