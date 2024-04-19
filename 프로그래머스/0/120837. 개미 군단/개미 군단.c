#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) {
    int queen = 5;
    int soldier = 3;
    int worker = 1; 
    int answer = 0; 
    
    answer = hp / queen;
    hp %= queen; 
    
    answer += hp / soldier;
    hp %= soldier; 
    
    answer += hp / worker; 

    return answer; 
} 

int main(void){
    int hp = 23;
    int result = solution(hp);
    printf("%d", result); 
    
    return 0;
}