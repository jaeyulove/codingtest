#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h> 

int_pow(int base, int exp){
    int result = 1; 
    for(int i=0; i<base; i++){
        result *= exp; 
    }
    return result; 
}


int solution(int a, int b, int c) {
    int answer = 0;
    
        if(a == b && b == c){
            answer = (a+b+c) * (int_pow(2,a)+int_pow(2,b)+int_pow(2,c)) * (int_pow(3,a)+int_pow(3,b)+int_pow(3,c));
        }
        else if(a != b && b != c && c != a){
            answer = a+b+c;
        }
        else if(a == b || a == c || b == c){
            answer = (a+b+c) * (int_pow(2,a) + int_pow(2,b) + int_pow(2,c));
        }
        return answer;
}

int main(void){
    int a = 2;
    int b = 6;
    int c = 1;
    
    int result = solution(a,b,c); 
    printf("%d\n", result);
    return 0; 
}